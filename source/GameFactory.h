#ifndef GAMEFACTORY_H
#define GAMEFACTORY_H

#include <map>
#include <unordered_map>
#include <list>
#include <typeinfo>
#include <type_traits>

#include "RakNet.h"

#include "Reference.h"
#include "Object.h"
#include "Item.h"
#include "Container.h"
#include "Actor.h"
#include "Player.h"
#include "Window.h"
#include "Button.h"
#include "Text.h"
#include "Edit.h"

#ifdef VAULTSERVER
#include "vaultserver/vaultserver.h"
#include "vaultserver/Database.h"
#include "vaultserver/Record.h"
#include "vaultserver/Reference.h"
#include "vaultserver/Exterior.h"
#include "vaultserver/Weapon.h"
#include "vaultserver/Race.h"
#include "vaultserver/NPC.h"
#include "vaultserver/BaseContainer.h"
#include "vaultserver/Item.h"
#include "vaultserver/Terminal.h"
#include "vaultserver/Interior.h"
#endif

#include "Expected.h"

#ifdef VAULTMP_DEBUG
#include "Debug.h"
#endif

const unsigned int ID_REFERENCE        = 0x01;
const unsigned int ID_OBJECT           = ID_REFERENCE << 1;
const unsigned int ID_ITEM             = ID_OBJECT << 1;
const unsigned int ID_CONTAINER        = ID_ITEM << 1;
const unsigned int ID_ACTOR            = ID_CONTAINER << 1;
const unsigned int ID_PLAYER           = ID_ACTOR << 1;
const unsigned int ID_WINDOW           = ID_PLAYER << 1;
const unsigned int ID_BUTTON           = ID_WINDOW << 1;
const unsigned int ID_TEXT             = ID_BUTTON << 1;
const unsigned int ID_EDIT             = ID_TEXT << 1;

const unsigned int ALL_OBJECTS         = (ID_OBJECT | ID_ITEM | ID_CONTAINER | ID_ACTOR | ID_PLAYER);
const unsigned int ALL_CONTAINERS      = (ID_CONTAINER | ID_ACTOR | ID_PLAYER);
const unsigned int ALL_ACTORS          = (ID_ACTOR | ID_PLAYER);
const unsigned int ALL_WINDOWS         = (ID_WINDOW | ID_BUTTON | ID_TEXT | ID_EDIT);

/**
  * \brief Holds an instance pointer
  */
template<typename T>
class FactoryWrapper;

/**
 * \brief Create, use and destroy game object instances via the GameFactory
 */
class GameFactory
{
	private:
		typedef std::map<std::shared_ptr<Reference>, unsigned int> ReferenceList;
		typedef std::unordered_map<RakNet::NetworkID, ReferenceList::iterator> ReferenceIndex;
		typedef std::unordered_map<unsigned int, unsigned int> ReferenceCount;
		typedef std::unordered_set<RakNet::NetworkID> ReferenceDeleted;

		GameFactory() = delete;

#ifdef VAULTMP_DEBUG
		static DebugInput<GameFactory> debug;
#endif

		static CriticalSection cs;
		static ReferenceList instances;
		static ReferenceIndex index;
		static ReferenceCount typecount;
		static ReferenceDeleted delrefs;
		static bool changed;

#ifdef VAULTSERVER
		static Database<DB::Record> dbRecords;
		static Database<DB::Reference> dbReferences;
		static Database<DB::Exterior> dbExteriors;
		static Database<DB::Weapon> dbWeapons;
		static Database<DB::Race> dbRaces;
		static Database<DB::NPC> dbNpcs;
		static Database<DB::BaseContainer> dbContainers;
		static Database<DB::Item> dbItems;
		static Database<DB::Terminal> dbTerminals;
		static Database<DB::Interior> dbInteriors;
#endif

		inline static ReferenceList::iterator GetShared(const RakNet::NetworkID& id) { return index.count(id) ? index[id] : instances.end(); }

	public:
		enum class LaunchPolicy
		{
			Blocking,
			Async,
			Default = Blocking
		};

		enum class FailPolicy
		{
			None,
			Return,
			Exception,
			Default = Exception
		};

	private:
		template<FailPolicy FP, LaunchPolicy LP, typename R> struct OperateReturn;
		template<typename R> struct OperateReturn<FailPolicy::None, LaunchPolicy::Blocking, R> { typedef R type; };
		template<typename R> struct OperateReturn<FailPolicy::Return, LaunchPolicy::Blocking, R> { typedef bool type; };
		template<typename R> struct OperateReturn<FailPolicy::Exception, LaunchPolicy::Blocking, R> { typedef R type; };
		template<typename P, FailPolicy FP, LaunchPolicy LP, typename R> struct OperateReturnProxy { typedef typename OperateReturn<FP, LP, R>::type type; };

		template<typename T, FailPolicy FP, LaunchPolicy LP, typename I, typename F>
		struct OperateFunctions {
			static typename OperateReturn<FP, LP, decltype(F())>::type Operate(I id, F function);
		};

	public:
		static void Initialize();

		/**
		 * \brief Obtains a lock on a Reference
		 *
		 * The Reference is identified by a NetworkID
		 */
		template<typename T = Object>
		static Expected<FactoryWrapper<T>> GetObject(RakNet::NetworkID id);
		/**
		 * \brief Obtains a lock on a Reference
		 *
		 * The Reference is identified by a reference ID
		 */
		template<typename T = Object>
		static Expected<FactoryWrapper<T>> GetObject(unsigned int refID);
		/**
		 * \brief Executes a function on a Reference
		 *
		 * The Reference is identified by an arbitrary type. This can be a NetworkID or a reference ID only.
		 */
		template<typename I, typename F> static typename OperateReturnProxy<typename std::enable_if<!std::is_base_of<Reference, F>::value>::type, FailPolicy::Default, LaunchPolicy::Default, typename std::result_of<F(FactoryWrapper<Object>&)>::type>::type Operate(I id, F function) { return OperateFunctions<Object, FailPolicy::Default, LaunchPolicy::Default, I, F>::Operate(id, function); }
		template<typename T, typename I, typename F> static typename OperateReturn<FailPolicy::Default, LaunchPolicy::Default, typename std::result_of<F(FactoryWrapper<T>&)>::type>::type Operate(I id, F function) { return OperateFunctions<T, FailPolicy::Default, LaunchPolicy::Default, I, F>::Operate(id, function); }
		template<typename T, FailPolicy FP, typename I, typename F> static typename OperateReturnProxy<typename std::enable_if<FP == FailPolicy::None>::type, FP, LaunchPolicy::Default, typename std::result_of<F(Expected<FactoryWrapper<T>>&)>::type>::type Operate(I id, F function) { return OperateFunctions<T, FP, LaunchPolicy::Default, I, F>::Operate(id, function); }
		template<typename T, FailPolicy FP, typename I, typename F> static typename OperateReturnProxy<typename std::enable_if<FP != FailPolicy::None>::type, FP, LaunchPolicy::Default, typename std::result_of<F(FactoryWrapper<T>&)>::type>::type Operate(I id, F function) { return OperateFunctions<T, FP, LaunchPolicy::Default, I, F>::Operate(id, function); }
		template<typename T, FailPolicy FP, LaunchPolicy LP, typename I, typename F> static typename OperateReturnProxy<typename std::enable_if<FP == FailPolicy::None>::type, FP, LP, typename std::result_of<F(Expected<FactoryWrapper<T>>&)>::type>::type Operate(I id, F function) { return OperateFunctions<T, FP, LP, I, F>::Operate(id, function); }
		template<typename T, FailPolicy FP, LaunchPolicy LP, typename I, typename F> static typename OperateReturn<FP, LP, typename std::result_of<F(FactoryWrapper<T>&)>::type>::type Operate(I id, F function) { return OperateFunctions<T, FP, LP, I, F>::Operate(id, function); }
		/**
		 * \brief Obtains a lock on multiple References
		 *
		 * The References are identified by a STL vector of reference IDs. You must use this function if you want to obtain multiple locks.
		 * Returns a STL vector which contains the locked References in the same ordering as the input vector.
		 */
		template<typename T = Object>
		static std::vector<Expected<FactoryWrapper<T>>> GetMultiple(const std::vector<unsigned int>& objects);
		/**
		 * \brief Obtains a lock on multiple References
		 *
		 * The References are identified by a STL vector of NetworkID. You must use this function if you want to obtain multiple locks.
		 * Returns a STL vector which contains the locked References in the same ordering as the input vector.
		 */
		template<typename T = Object>
		static std::vector<Expected<FactoryWrapper<T>>> GetMultiple(const std::vector<RakNet::NetworkID>& objects);
		/**
		 * \brief Lookup a NetworkID
		 */
		static RakNet::NetworkID LookupNetworkID(unsigned int refID);
		/**
		 * \brief Lookup a reference IDFactoryWrapper
		 */
		static unsigned int LookupRefID(RakNet::NetworkID id);
		/**
		 * \brief Checks if an ID has been deleted
		 */
		static bool IsDeleted(RakNet::NetworkID id);
		/**
		 * \brief Returns the type of the given NetworkID
		 */
		static unsigned int GetType(RakNet::NetworkID id) noexcept;
		/**
		 * \brief Returns the type of the given reference
		 */
		static unsigned int GetType(const Reference* reference) noexcept;
		/**
		 * \brief Returns the type of the given reference ID
		 */
		static unsigned int GetType(unsigned int refID) noexcept;
		/**
		 * \brief Obtains a lock on all References of a given type
		 */
		template<typename T = Object>
		static std::vector<FactoryWrapper<T>> GetObjectTypes(unsigned int type) noexcept;
		/**
		 * \brief Returns the NetworkID's of all References of a given type
		 */
		static std::vector<RakNet::NetworkID> GetIDObjectTypes(unsigned int type) noexcept;
		/**
		 * \brief Counts the amount of References of a given type
		 */
		static unsigned int GetObjectCount(unsigned int type) noexcept;
		/**
		 * \brief Invalidates a Reference held by a FactoryWrapper
		 */
		template<typename T>
		static void LeaveReference(FactoryWrapper<T>& reference);
		/**
		 * \brief Creates a new instance of a given type
		 */
		static RakNet::NetworkID CreateInstance(unsigned int type, unsigned int refID, unsigned int baseID);
		/**
		 * \brief Creates a new instance of a given type
		 */
		static RakNet::NetworkID CreateInstance(unsigned int type, unsigned int baseID);
		/**
		 * \brief Creates a known instance from a network packet
		 */
		static RakNet::NetworkID CreateKnownInstance(unsigned int type, const pDefault* packet);

		/**
		 * \brief Destroys all instances and cleans up type classes
		 */
		static void DestroyAllInstances();
		/**
		 * \brief Destroys an instance
		 */
		static bool DestroyInstance(RakNet::NetworkID id);
		/**
		 * \brief Destroys an instance which has previously been locked
		 *
		 * You must make sure the lock count of the given Reference equals to one
		 */
		template<typename T>
		static RakNet::NetworkID DestroyInstance(FactoryWrapper<T>& reference);

		/**
		 * \brief Used to set the changed flag for the next network reference going to be created
		 */
		static void SetChangeFlag(bool changed);
};

template<typename T, typename I, typename F>
struct GameFactory::OperateFunctions<T, GameFactory::FailPolicy::Return, GameFactory::LaunchPolicy::Blocking, I, F> {
	static typename OperateReturn<FailPolicy::Return, LaunchPolicy::Blocking, typename std::result_of<F(FactoryWrapper<T>&)>::type>::type Operate(I id, F function)
	{
		auto reference = GameFactory::GetObject<T>(id);

		if (!reference)
			return false;

		function(reference.get());

		return true;
	}
};

template<typename T, typename I, typename F>
struct GameFactory::OperateFunctions<T, GameFactory::FailPolicy::Exception, GameFactory::LaunchPolicy::Blocking, I, F> {
	static typename OperateReturn<FailPolicy::Exception, LaunchPolicy::Blocking, typename std::result_of<F(FactoryWrapper<T>&)>::type>::type Operate(I id, F function)
	{
		auto reference = GameFactory::GetObject<T>(id);
		return function(reference.get());
	}
};

template<typename T, typename I, typename F>
struct GameFactory::OperateFunctions<T, GameFactory::FailPolicy::None, GameFactory::LaunchPolicy::Blocking, I, F> {
	static typename OperateReturn<FailPolicy::None, LaunchPolicy::Blocking, typename std::result_of<F(Expected<FactoryWrapper<T>>&)>::type>::type Operate(I id, F function)
	{
		auto reference = GameFactory::GetObject<T>(id);
		return function(reference);
	}
};

template<>
class FactoryWrapper<Reference>
{
		friend class GameFactory;

		template<typename T, typename U>
		friend Expected<FactoryWrapper<T>> vaultcast(const FactoryWrapper<U>& object) noexcept;

	private:
		Reference* reference;
		unsigned int type;

	protected:
		FactoryWrapper(Reference* reference, unsigned int type) : reference(reinterpret_cast<Reference*>(reference->StartSession())), type(type) {}

		FactoryWrapper(const FactoryWrapper& p) : reference(p.reference), type(p.type)
		{
			if (reference)
				reference->StartSession();
		}
		FactoryWrapper& operator=(const FactoryWrapper& p)
		{
			if (this != &p)
			{
				if (reference)
					reference->EndSession();

				reference = p.reference;
				type = p.type;

				if (reference)
					reference->StartSession();
			}

			return *this;
		}

		FactoryWrapper(FactoryWrapper&& p) : reference(p.reference), type(p.type)
		{
			p.reference = nullptr;
			p.type = 0x00000000;
		}
		FactoryWrapper& operator=(FactoryWrapper&& p)
		{
			if (this != &p)
			{
				if (reference)
					reference->EndSession();

				reference = p.reference;
				type = p.type;

				p.reference = nullptr;
				p.type = 0x00000000;
			}

			return *this;
		}

		FactoryWrapper() : reference(nullptr), type(0x00000000) {};
		~FactoryWrapper()
		{
			if (reference)
				reference->EndSession();
		}

	public:
		unsigned int GetType() const { return type; }
		Reference& operator*() const { return *reference; }
		Reference* operator->() const { return reference; }
		explicit operator bool() const { return reference; }
		bool operator==(const FactoryWrapper& p) const { return reference && reference == p.reference; }
		bool operator!=(const FactoryWrapper& p) const { return !operator==(p); }

		template<typename T>
		inline bool validate(unsigned int type = 0x00000000) const;
};

#define GF_TYPE_WRAPPER(derived, base, token)                                                                                                               \
	template<> inline bool FactoryWrapper<Reference>::validate<derived>(unsigned int type) const { return type ? (type & token) : (this->type & token); }   \
	template<> class FactoryWrapper<derived> : public FactoryWrapper<base>                                                                                  \
	{                                                                                                                                                       \
		friend class GameFactory;                                                                                                                           \
                                                                                                                                                            \
		template<typename T, typename U>                                                                                                                    \
		friend Expected<FactoryWrapper<T>> vaultcast(const FactoryWrapper<U>& object) noexcept;                                                             \
                                                                                                                                                            \
	protected:                                                                                                                                              \
		FactoryWrapper(Reference* reference, unsigned int type) : FactoryWrapper<base>(reference, type)                                                     \
		{                                                                                                                                                   \
			if (!validate<derived>())                                                                                                                       \
				reference = nullptr;                                                                                                                        \
		}                                                                                                                                                   \
		template<typename T> FactoryWrapper(const FactoryWrapper<T>& p) : FactoryWrapper<base>(p) {}                                                        \
		template<typename T> FactoryWrapper& operator=(const FactoryWrapper<T>& p) { return FactoryWrapper<base>::operator=(p); }                           \
                                                                                                                                                            \
	public:                                                                                                                                                 \
		FactoryWrapper() : FactoryWrapper<base>() {}                                                                                                        \
		FactoryWrapper(const FactoryWrapper& p) : FactoryWrapper<base>(p) {}                                                                                \
		FactoryWrapper& operator=(const FactoryWrapper&) = default;                                                                                         \
		FactoryWrapper(FactoryWrapper&& p) : FactoryWrapper<base>(std::move(p)) {}                                                                          \
		FactoryWrapper& operator=(FactoryWrapper&&) = default;                                                                                              \
		~FactoryWrapper() = default;                                                                                                                        \
																																							\
		derived* operator->() const { return static_cast<derived*>(FactoryWrapper<Reference>::operator->()); }                                              \
		derived& operator*() const { return static_cast<derived&>(FactoryWrapper<Reference>::operator*()); }                                                \
};                                                                                                                                                          \
typedef FactoryWrapper<derived> Factory##derived;                                                                                                           \
typedef Expected<FactoryWrapper<derived>> Expected##derived;

GF_TYPE_WRAPPER(Object, Reference, ALL_OBJECTS)
GF_TYPE_WRAPPER(Item, Object, ID_ITEM)
GF_TYPE_WRAPPER(Container, Object, ID_CONTAINER)
GF_TYPE_WRAPPER(Actor, Container, ALL_ACTORS)
GF_TYPE_WRAPPER(Player, Actor, ID_PLAYER)
GF_TYPE_WRAPPER(Window, Reference, ALL_WINDOWS)
GF_TYPE_WRAPPER(Button, Window, ID_BUTTON)
GF_TYPE_WRAPPER(Text, Window, ID_TEXT)
GF_TYPE_WRAPPER(Edit, Window, ID_EDIT)

#undef GF_TYPE_WRAPPER

/**
  * \brief Tries to cast the instance pointer of a FactoryWrapper
  */
template<typename T, typename U>
inline Expected<FactoryWrapper<T>> vaultcast(const FactoryWrapper<U>& object) noexcept
{
	auto result = FactoryWrapper<T>(object);

	if (result.template validate<T>())
		return result;

	return VaultException("vaultcast failed");
}
template<typename T, typename U>
inline Expected<FactoryWrapper<T>> vaultcast(const Expected<FactoryWrapper<U>>& object) noexcept { return vaultcast<T>(const_cast<Expected<FactoryWrapper<U>>&>(object).get()); }
#endif

using FailPolicy = GameFactory::FailPolicy;
using LaunchPolicy = GameFactory::LaunchPolicy;
