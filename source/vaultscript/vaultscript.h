#ifndef VAULTSCRIPT_H
#define VAULTSCRIPT_H

/*
 *  vaultscript.h
 *  Don't change anything here
 */

#ifdef __cplusplus
	#include <string>
	#include <vector>
	#include <unordered_set>
	#include <unordered_map>
	#include <cstdint>
	#include <climits>
	#define VAULTFUNCTION inline static
	#define VAULTAPI(name) c##name
	#define VAULTAPI_PREFIX 'c'
	#define VAULTSPACE vaultmp::
	#define VAULTCPP(expr) expr
	#define VAULTC(expr)
#else
	#include <stdint.h>
	#include <limits.h>
	#define VAULTAPI(name) name
	#define VAULTAPI_PREFIX '\0'
	#define VAULTSPACE
	#define VAULTCPP(expr)
	#define VAULTC(expr) expr
#endif

#ifndef __WIN32__
	#ifndef __cdecl
		#define __cdecl __attribute__((__cdecl__))
	#endif
	#define VAULTVAR __attribute__ ((__visibility__("default")))
	#define VAULTSCRIPT VAULTVAR __cdecl
#else
	#define VAULTVAR __declspec(dllexport)
	#define VAULTSCRIPT VAULTVAR __cdecl
#endif

VAULTCPP(
namespace vaultmp {
)
	typedef void Void;
	typedef char* RawString;
	typedef char RawChar;
	typedef const char* cRawString;
	typedef const char cRawChar;
	typedef int32_t Count;
	typedef uint32_t UCount;
	typedef double Value;

	enum VAULTCPP(class) Index VAULTCPP(: uint8_t)
	{
		MAX_PLAYER_NAME = 16,
		MAX_PASSWORD_SIZE = 16,
		MAX_MESSAGE_LENGTH = 64,
		MAX_CHAT_LENGTH	= 128,
	};

	enum VAULTCPP(class) Type VAULTCPP(: uint32_t)
	{
		ID_REFERENCE = 0x01,
		ID_OBJECT = ID_REFERENCE << 1,
		ID_ITEM = ID_OBJECT << 1,
		ID_CONTAINER = ID_ITEM << 1,
		ID_ACTOR = ID_CONTAINER << 1,
		ID_PLAYER = ID_ACTOR << 1,
		ID_WINDOW = ID_PLAYER << 1,
		ID_BUTTON = ID_WINDOW << 1,
		ID_TEXT = ID_BUTTON << 1,
		ID_EDIT = ID_TEXT << 1,

		ALL_OBJECTS = (ID_OBJECT | ID_ITEM | ID_CONTAINER | ID_ACTOR | ID_PLAYER),
		ALL_CONTAINERS = (ID_CONTAINER | ID_ACTOR | ID_PLAYER),
		ALL_ACTORS = (ID_ACTOR | ID_PLAYER),
		ALL_WINDOWS = (ID_WINDOW | ID_BUTTON | ID_TEXT | ID_EDIT),
	};

	enum VAULTCPP(class) ActorValue VAULTCPP(: uint8_t)
	{
		Aggression = 0x00,
		Confidence = 0x01,
		Energy = 0x02,
		Responsibility = 0x03,
		Mood = 0x04,
		Strength = 0x05,
		Perception = 0x06,
		Endurance = 0x07,
		Charisma = 0x08,
		Intelligence = 0x09,
		Agility = 0x0A,
		Luck = 0x0B,
		ActionPoints = 0x0C,
		CarryWeight = 0x0D,
		CritChance = 0x0E,
		HealRate = 0x0F,
		Health = 0x10,
		MeleeDamage = 0x11,
		DamageResistance = 0x12,
		PoisonResistance = 0x13,
		RadResistance = 0x14,
		SpeedMultiplier = 0x15,
		Fatigue = 0x16,
		Karma = 0x17,
		XP = 0x18,
		Head = 0x19,
		Torso = 0x1A,
		LeftArm = 0x1B,
		RightArm = 0x1C,
		LeftLeg = 0x1D,
		RightLeg = 0x1E,
		Brain = 0x1F,
		Barter = 0x20,
		BigGuns = 0x21,
		EnergyWeapons = 0x22,
		Explosives = 0x23,
		Lockpick = 0x24,
		Medicine = 0x25,
		MeleeWeapons = 0x26,
		Repair = 0x27,
		Science = 0x28,
		SmallGuns = 0x29,
		Sneak = 0x2A,
		Speech = 0x2B,
		Throwing = 0x2C,
		Unarmed = 0x2D,
		InventoryWeight = 0x2E,
		Paralysis = 0x2F,
		Invisibility = 0x30,
		Chameleon = 0x31,
		NightEye = 0x32,
		DetectLifeRange = 0x33,
		FireResistance = 0x34,
		WaterBreathing = 0x35,
		RadLevel = 0x36,
		BloodyMess = 0x37,
		UnarmedDamage = 0x38,
		Assistance = 0x39,

		EnergyResistance = 0x3C,
		EMPResistance = 0x3D,
		Var1Medical = 0x3E,
		Variable02 = 0x3F,
		Variable03 = 0x40,
		Variable04 = 0x41,
		Variable05 = 0x42,
		Variable06 = 0x43,
		Variable07 = 0x44,
		Variable08 = 0x45,
		Variable09 = 0x46,
		Variable10 = 0x47,
		IgnoreCrippledLimbs = 0x48,
	};

	enum VAULTCPP(class) Limb VAULTCPP(: uint16_t)
	{
		VAULTCPP(None)VAULTC(None_) = 0x0000,
		VAULTCPP(Torso)VAULTC(Torso_) = 0x0001,
		Head1 = VAULTCPP(Torso)VAULTC(Torso_) << 1,
		Head2 = Head1 << 1,
		LeftArm1 = Head2 << 1,
		LeftArm2 = LeftArm1 << 1,
		RightArm1 = LeftArm2 << 1,
		RightArm2 = RightArm1 << 1,
		LeftLeg1 = RightArm2 << 1,
		LeftLeg2 = LeftLeg1 << 1,
		LeftLeg3 = LeftLeg2 << 1,
		RightLeg1 = LeftLeg3 << 1,
		RightLeg2 = RightLeg1 << 1,
		RightLeg3 = RightLeg2 << 1,
		VAULTCPP(Brain)VAULTC(Brain_) = RightLeg3 << 1,
		Weapon = VAULTCPP(Brain)VAULTC(Brain_) << 1,

		TORSO = (VAULTCPP(Torso)VAULTC(Torso_)),
		HEAD = (Head1 | Head2),
		LEFT_ARM = (LeftArm1 | LeftArm2),
		RIGHT_ARM = (RightArm1 | RightArm2),
		LEFT_LEG = (LeftLeg1 | LeftLeg2 | LeftLeg3),
		RIGHT_LEG = (RightLeg1 | RightLeg2 | RightLeg3),
		BRAIN = (VAULTCPP(Brain)VAULTC(Brain_)),
		WEAPON = (Weapon),

		ALL_LIMBS = (TORSO | HEAD | LEFT_ARM | RIGHT_ARM | LEFT_LEG | RIGHT_LEG | BRAIN | WEAPON),
	};

	enum VAULTCPP(class) Death VAULTCPP(: int8_t)
	{
		None = -1,
		Explosion = 0,
		Gun = 2,
		BluntWeapon = 3,
		HandToHand = 4,
		ObjectImpact = 5,
		Poison = 6,
		Radiation = 7,
	};

	enum VAULTCPP(class) Lock VAULTCPP(: uint32_t)
	{
		Unlocked = UINT_MAX,
		Broken = UINT_MAX - 1,
		VeryEasy = 0,
		Easy = 25,
		Average = 50,
		Hard = 75,
		VeryHard = 100,
		Impossible = 255,
	};

	enum VAULTCPP(class) Emoticon VAULTCPP(: uint8_t)
	{
		Happy = 0,
		Sad = 1,
		Neutral = 2,
		Pain = 3,
	};

	enum VAULTCPP(class) Interval VAULTCPP(: uint32_t)
	{
		DEFAULT_PLAYER_RESPAWN = 8000,
	};
#ifndef __cplusplus
	typedef int8_t Death;
	typedef uint8_t Reason;
	typedef uint8_t Index;
	typedef uint8_t Type;
	typedef uint8_t State;
	typedef uint8_t Emoticon;
	typedef uint8_t ActorValue;
	typedef uint16_t Limb;
	typedef uint32_t Ref;
	typedef uint32_t Base;
	typedef uint32_t Interval;
	typedef uint32_t Lock;
	typedef uint64_t ID;
	typedef uint64_t Timer;
	typedef uint64_t Result;
	typedef int64_t Time;

	#define RawFunction(types) Result (__cdecl*)(types)
	#define RawArray(type) type*
#else
	enum Reason : uint8_t;

	enum State : bool
	{
		True = true,
		False = false
	};

	State operator!(State state) { return state ? False : True; }

	enum Ref : uint32_t;
	enum Base : uint32_t;
	enum ID : uint64_t;
	enum Timer : uint64_t;
	enum Result : uint64_t;
	enum Time : int64_t;

	struct _hash_Base { inline size_t operator() (const Base& base) const { return std::hash<std::underlying_type<Base>::type>()(static_cast<std::underlying_type<Base>::type>(base)); }};
	struct _hash_ID { inline size_t operator() (const ID& id) const { return std::hash<std::underlying_type<ID>::type>()(static_cast<std::underlying_type<ID>::type>(id)); }};

	typedef std::string String;
	typedef std::vector<Base> BaseVector;
	typedef std::vector<ID> IDVector;
	typedef std::unordered_set<ID, _hash_Base> BaseSet;
	typedef std::unordered_set<ID, _hash_ID> IDSet;

	template <typename V>
	using BaseHash = std::unordered_map<Base, V, _hash_Base>;

	template <typename V>
	using IDHash = std::unordered_map<ID, V, _hash_ID>;

	template <typename T>
	using RawArray = T*;

	#define RawArray(type)		RawArray<type>

	template <typename... Types>
	using Function = Result (__cdecl*)(Types...) noexcept;

	#define RawFunction(types) 	Function<types>
#endif

#include "records.h"

VAULTCPP(})

VAULTCPP(extern "C" {)
	VAULTVAR VAULTSPACE RawChar vaultprefix = VAULTAPI_PREFIX;

	VAULTSCRIPT VAULTSPACE Void OnSpawn(VAULTSPACE ID) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Void OnActivate(VAULTSPACE ID, VAULTSPACE ID) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Void OnCellChange(VAULTSPACE ID, VAULTSPACE CELL) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Void OnLockChange(VAULTSPACE ID, VAULTSPACE ID, VAULTSPACE Lock) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Void OnContainerItemChange(VAULTSPACE ID, VAULTSPACE Base, VAULTSPACE Count, VAULTSPACE Value) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Void OnActorValueChange(VAULTSPACE ID, VAULTSPACE ActorValue, VAULTSPACE Value) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Void OnActorBaseValueChange(VAULTSPACE ID, VAULTSPACE ActorValue, VAULTSPACE Value) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Void OnActorAlert(VAULTSPACE ID, VAULTSPACE State) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Void OnActorSneak(VAULTSPACE ID, VAULTSPACE State) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Void OnActorDeath(VAULTSPACE ID, VAULTSPACE ID, VAULTSPACE Limb, VAULTSPACE Death) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Void OnActorEquipItem(VAULTSPACE ID, VAULTSPACE Base, VAULTSPACE Value) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Void OnActorUnequipItem(VAULTSPACE ID, VAULTSPACE Base, VAULTSPACE Value) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Void OnActorPunch(VAULTSPACE ID, VAULTSPACE State) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Void OnActorFireWeapon(VAULTSPACE ID, VAULTSPACE WEAP) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Void OnPlayerDisconnect(VAULTSPACE ID, VAULTSPACE Reason) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE NPC_ OnPlayerRequestGame(VAULTSPACE ID) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State OnPlayerChat(VAULTSPACE ID, VAULTSPACE RawString) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Void OnWindowMode(VAULTSPACE ID, VAULTSPACE State) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Void OnWindowClick(VAULTSPACE ID, VAULTSPACE ID) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Void OnWindowTextChange(VAULTSPACE ID, VAULTSPACE ID, VAULTSPACE cRawString) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State OnClientAuthenticate(VAULTSPACE cRawString, VAULTSPACE cRawString) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Void OnGameYearChange(VAULTSPACE UCount) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Void OnGameMonthChange(VAULTSPACE UCount) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Void OnGameDayChange(VAULTSPACE UCount) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Void OnGameHourChange(VAULTSPACE UCount) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Void OnServerInit() VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Void OnServerExit() VAULTCPP(noexcept);

	VAULTSCRIPT VAULTSPACE Void (*VAULTAPI(timestamp))() VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Timer (*VAULTAPI(CreateTimer))(VAULTSPACE RawFunction(), VAULTSPACE Interval) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Timer (*VAULTAPI(CreateTimerEx))(VAULTSPACE RawFunction(), VAULTSPACE Interval, VAULTSPACE cRawString, ...) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Void (*VAULTAPI(KillTimer))(VAULTSPACE Timer) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Void (*VAULTAPI(MakePublic))(VAULTSPACE RawFunction(), VAULTSPACE cRawString, VAULTSPACE cRawString) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Result (*VAULTAPI(CallPublic))(VAULTSPACE cRawString, ...) VAULTCPP(noexcept);

	VAULTSCRIPT VAULTSPACE Void (*VAULTAPI(SetServerName))(VAULTSPACE cRawString) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Void (*VAULTAPI(SetServerMap))(VAULTSPACE cRawString) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Void (*VAULTAPI(SetServerRule))(VAULTSPACE cRawString, VAULTSPACE cRawString) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE UCount (*VAULTAPI(GetMaximumPlayers))() VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE UCount (*VAULTAPI(GetCurrentPlayers))() VAULTCPP(noexcept);

	VAULTSCRIPT VAULTSPACE cRawString (*VAULTAPI(ValueToString))(VAULTSPACE Index) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE cRawString (*VAULTAPI(AxisToString))(VAULTSPACE Index) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE cRawString (*VAULTAPI(AnimToString))(VAULTSPACE Index) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE cRawString (*VAULTAPI(BaseToString))(VAULTSPACE Base) VAULTCPP(noexcept);

	VAULTSCRIPT VAULTSPACE State (*VAULTAPI(Kick))(VAULTSPACE ID) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State (*VAULTAPI(UIMessage))(VAULTSPACE ID, VAULTSPACE cRawString, VAULTSPACE Emoticon) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State (*VAULTAPI(ChatMessage))(VAULTSPACE ID, VAULTSPACE cRawString) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Void (*VAULTAPI(SetRespawnTime))(VAULTSPACE Interval) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Void (*VAULTAPI(SetSpawnCell))(VAULTSPACE CELL) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Void (*VAULTAPI(SetConsoleEnabled))(VAULTSPACE State) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Void (*VAULTAPI(SetGameWeather))(VAULTSPACE WTHR) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Void (*VAULTAPI(SetGameTime))(VAULTSPACE Time) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Void (*VAULTAPI(SetGameYear))(VAULTSPACE UCount) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Void (*VAULTAPI(SetGameMonth))(VAULTSPACE UCount) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Void (*VAULTAPI(SetGameDay))(VAULTSPACE UCount) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Void (*VAULTAPI(SetGameHour))(VAULTSPACE UCount) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Void (*VAULTAPI(SetTimeScale))(VAULTSPACE Value) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State (*VAULTAPI(IsValid))(VAULTSPACE ID) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State (*VAULTAPI(IsObject))(VAULTSPACE ID) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State (*VAULTAPI(IsItem))(VAULTSPACE ID) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State (*VAULTAPI(IsContainer))(VAULTSPACE ID) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State (*VAULTAPI(IsActor))(VAULTSPACE ID) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State (*VAULTAPI(IsPlayer))(VAULTSPACE ID) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State (*VAULTAPI(IsCell))(VAULTSPACE CELL) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State (*VAULTAPI(IsInterior))(VAULTSPACE CELL) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State (*VAULTAPI(IsItemList))(VAULTSPACE ID) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State (*VAULTAPI(IsWindow))(VAULTSPACE ID) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State (*VAULTAPI(IsButton))(VAULTSPACE ID) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State (*VAULTAPI(IsText))(VAULTSPACE ID) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State (*VAULTAPI(IsEdit))(VAULTSPACE ID) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State (*VAULTAPI(IsChatbox))(VAULTSPACE ID) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Type (*VAULTAPI(GetType))(VAULTSPACE ID) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE UCount (*VAULTAPI(GetConnection))(VAULTSPACE ID) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE UCount (*VAULTAPI(GetCount))(VAULTSPACE Type) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE UCount (*VAULTAPI(GetList))(VAULTSPACE Type, VAULTSPACE RawArray(VAULTSPACE ID)*) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Interval (*VAULTAPI(GetRespawnTime))() VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE CELL (*VAULTAPI(GetSpawnCell))() VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State (*VAULTAPI(GetConsoleEnabled))() VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE WTHR (*VAULTAPI(GetGameWeather))() VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Time (*VAULTAPI(GetGameTime))() VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE UCount (*VAULTAPI(GetGameYear))() VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE UCount (*VAULTAPI(GetGameMonth))() VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE UCount (*VAULTAPI(GetGameDay))() VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE UCount (*VAULTAPI(GetGameHour))() VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Value (*VAULTAPI(GetTimeScale))() VAULTCPP(noexcept);

	VAULTSCRIPT VAULTSPACE ID (*VAULTAPI(GetID))(VAULTSPACE Ref) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Ref (*VAULTAPI(GetReference))(VAULTSPACE ID) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Base (*VAULTAPI(GetBase))(VAULTSPACE ID) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Void (*VAULTAPI(GetPos))(VAULTSPACE ID, VAULTSPACE Value*, VAULTSPACE Value*, VAULTSPACE Value*) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Void (*VAULTAPI(GetAngle))(VAULTSPACE ID, VAULTSPACE Value*, VAULTSPACE Value*, VAULTSPACE Value*) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE CELL (*VAULTAPI(GetCell))(VAULTSPACE ID) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Lock (*VAULTAPI(GetLock))(VAULTSPACE ID) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE NPC_ (*VAULTAPI(GetOwner))(VAULTSPACE ID) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE cRawString (*VAULTAPI(GetBaseName))(VAULTSPACE ID) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State (*VAULTAPI(IsNearPoint))(VAULTSPACE ID, VAULTSPACE Value, VAULTSPACE Value, VAULTSPACE Value, VAULTSPACE Value) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE ID (*VAULTAPI(GetItemContainer))(VAULTSPACE ID) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE UCount (*VAULTAPI(GetItemCount))(VAULTSPACE ID) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Value (*VAULTAPI(GetItemCondition))(VAULTSPACE ID) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State (*VAULTAPI(GetItemEquipped))(VAULTSPACE ID) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State (*VAULTAPI(GetItemSilent))(VAULTSPACE ID) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State (*VAULTAPI(GetItemStick))(VAULTSPACE ID) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE UCount (*VAULTAPI(GetContainerItemCount))(VAULTSPACE ID, VAULTSPACE Base) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE UCount (*VAULTAPI(GetContainerItemList))(VAULTSPACE ID, VAULTSPACE RawArray(VAULTSPACE ID)*) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Value (*VAULTAPI(GetActorValue))(VAULTSPACE ID, VAULTSPACE ActorValue) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Value (*VAULTAPI(GetActorBaseValue))(VAULTSPACE ID, VAULTSPACE ActorValue) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE IDLE (*VAULTAPI(GetActorIdleAnimation))(VAULTSPACE ID) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Index (*VAULTAPI(GetActorMovingAnimation))(VAULTSPACE ID) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Index (*VAULTAPI(GetActorWeaponAnimation))(VAULTSPACE ID) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State (*VAULTAPI(GetActorAlerted))(VAULTSPACE ID) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State (*VAULTAPI(GetActorSneaking))(VAULTSPACE ID) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State (*VAULTAPI(GetActorDead))(VAULTSPACE ID) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE RACE (*VAULTAPI(GetActorBaseRace))(VAULTSPACE ID) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State (*VAULTAPI(GetActorBaseSex))(VAULTSPACE ID) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State (*VAULTAPI(IsActorJumping))(VAULTSPACE ID) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Interval (*VAULTAPI(GetPlayerRespawnTime))(VAULTSPACE ID) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE CELL (*VAULTAPI(GetPlayerSpawnCell))(VAULTSPACE ID) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State (*VAULTAPI(GetPlayerConsoleEnabled))(VAULTSPACE ID) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE UCount (*VAULTAPI(GetPlayerWindowCount))(VAULTSPACE ID) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE UCount (*VAULTAPI(GetPlayerWindowList))(VAULTSPACE ID, VAULTSPACE RawArray(VAULTSPACE ID)*) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE ID (*VAULTAPI(GetPlayerChatboxWindow))(VAULTSPACE ID) VAULTCPP(noexcept);

	VAULTSCRIPT VAULTSPACE ID (*VAULTAPI(CreateObject))(VAULTSPACE Base, VAULTSPACE ID, VAULTSPACE CELL, VAULTSPACE Value, VAULTSPACE Value, VAULTSPACE Value) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State (*VAULTAPI(DestroyObject))(VAULTSPACE ID) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State (*VAULTAPI(SetPos))(VAULTSPACE ID, VAULTSPACE Value, VAULTSPACE Value, VAULTSPACE Value) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State (*VAULTAPI(SetAngle))(VAULTSPACE ID, VAULTSPACE Value, VAULTSPACE Value, VAULTSPACE Value) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State (*VAULTAPI(SetCell))(VAULTSPACE ID, VAULTSPACE CELL, VAULTSPACE Value, VAULTSPACE Value, VAULTSPACE Value) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State (*VAULTAPI(SetLock))(VAULTSPACE ID, VAULTSPACE Lock) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State (*VAULTAPI(SetOwner))(VAULTSPACE ID, VAULTSPACE NPC_) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State (*VAULTAPI(SetBaseName))(VAULTSPACE ID, VAULTSPACE cRawString) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE ID (*VAULTAPI(CreateItem))(VAULTSPACE Base, VAULTSPACE ID, VAULTSPACE CELL, VAULTSPACE Value, VAULTSPACE Value, VAULTSPACE Value) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE ID (*VAULTAPI(SetItemContainer))(VAULTSPACE ID, VAULTSPACE ID) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State (*VAULTAPI(SetItemCount))(VAULTSPACE ID, VAULTSPACE UCount) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State (*VAULTAPI(SetItemCondition))(VAULTSPACE ID, VAULTSPACE Value) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State (*VAULTAPI(SetItemEquipped))(VAULTSPACE ID, VAULTSPACE State, VAULTSPACE State, VAULTSPACE State) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE ID (*VAULTAPI(CreateContainer))(VAULTSPACE CONT, VAULTSPACE ID, VAULTSPACE CELL, VAULTSPACE Value, VAULTSPACE Value, VAULTSPACE Value) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE ID (*VAULTAPI(CreateItemList))(VAULTSPACE ID, VAULTSPACE Base) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE ID (*VAULTAPI(AddItem))(VAULTSPACE ID, VAULTSPACE Base, VAULTSPACE UCount, VAULTSPACE Value, VAULTSPACE State) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Void (*VAULTAPI(AddItemList))(VAULTSPACE ID, VAULTSPACE ID, VAULTSPACE Base) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE UCount (*VAULTAPI(RemoveItem))(VAULTSPACE ID, VAULTSPACE Base, VAULTSPACE UCount, VAULTSPACE State) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Void (*VAULTAPI(RemoveAllItems))(VAULTSPACE ID) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE ID (*VAULTAPI(CreateActor))(VAULTSPACE Base, VAULTSPACE ID, VAULTSPACE CELL, VAULTSPACE Value, VAULTSPACE Value, VAULTSPACE Value) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Void (*VAULTAPI(SetActorValue))(VAULTSPACE ID, VAULTSPACE ActorValue, VAULTSPACE Value) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Void (*VAULTAPI(SetActorBaseValue))(VAULTSPACE ID, VAULTSPACE ActorValue, VAULTSPACE Value) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State (*VAULTAPI(EquipItem))(VAULTSPACE ID, VAULTSPACE Base, VAULTSPACE State, VAULTSPACE State) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State (*VAULTAPI(UnequipItem))(VAULTSPACE ID, VAULTSPACE Base, VAULTSPACE State, VAULTSPACE State) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State (*VAULTAPI(PlayIdle))(VAULTSPACE ID, VAULTSPACE IDLE) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State (*VAULTAPI(SetActorMovingAnimation))(VAULTSPACE ID, VAULTSPACE Index) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State (*VAULTAPI(SetActorWeaponAnimation))(VAULTSPACE ID, VAULTSPACE Index) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State (*VAULTAPI(SetActorAlerted))(VAULTSPACE ID, VAULTSPACE State) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State (*VAULTAPI(SetActorSneaking))(VAULTSPACE ID, VAULTSPACE State) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State (*VAULTAPI(FireWeapon))(VAULTSPACE ID) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Void (*VAULTAPI(KillActor))(VAULTSPACE ID, VAULTSPACE Limb, VAULTSPACE Death) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State (*VAULTAPI(SetActorBaseRace))(VAULTSPACE ID, VAULTSPACE RACE) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State (*VAULTAPI(AgeActorBaseRace))(VAULTSPACE ID, VAULTSPACE Count) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State (*VAULTAPI(SetActorBaseSex))(VAULTSPACE ID, VAULTSPACE State) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Void (*VAULTAPI(SetPlayerRespawnTime))(VAULTSPACE ID, VAULTSPACE Interval) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Void (*VAULTAPI(SetPlayerSpawnCell))(VAULTSPACE ID, VAULTSPACE CELL) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Void (*VAULTAPI(SetPlayerConsoleEnabled))(VAULTSPACE ID, VAULTSPACE State) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State (*VAULTAPI(AttachWindow))(VAULTSPACE ID, VAULTSPACE ID) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State (*VAULTAPI(DetachWindow))(VAULTSPACE ID, VAULTSPACE ID) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Void (*VAULTAPI(ForceWindowMode))(VAULTSPACE ID, VAULTSPACE State) VAULTCPP(noexcept);

	VAULTSCRIPT VAULTSPACE ID (*VAULTAPI(GetParentWindow))(VAULTSPACE ID) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE ID (*VAULTAPI(GetWindowRoot))(VAULTSPACE ID) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE UCount (*VAULTAPI(GetWindowChildCount))(VAULTSPACE ID) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE UCount (*VAULTAPI(GetWindowChildList))(VAULTSPACE ID, VAULTSPACE RawArray(VAULTSPACE ID)*) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Void (*VAULTAPI(GetWindowPos))(VAULTSPACE ID, VAULTSPACE Value*, VAULTSPACE Value*, VAULTSPACE Value*, VAULTSPACE Value*) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE Void (*VAULTAPI(GetWindowSize))(VAULTSPACE ID, VAULTSPACE Value*, VAULTSPACE Value*, VAULTSPACE Value*, VAULTSPACE Value*) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State (*VAULTAPI(GetWindowVisible))(VAULTSPACE ID) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State (*VAULTAPI(GetWindowLocked))(VAULTSPACE ID) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE cRawString (*VAULTAPI(GetWindowText))(VAULTSPACE ID) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE UCount (*VAULTAPI(GetEditMaxLength))(VAULTSPACE ID) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE cRawString (*VAULTAPI(GetEditValidation))(VAULTSPACE ID) VAULTCPP(noexcept);

	VAULTSCRIPT VAULTSPACE ID (*VAULTAPI(CreateWindow))(VAULTSPACE Value, VAULTSPACE Value, VAULTSPACE Value, VAULTSPACE Value, VAULTSPACE Value, VAULTSPACE Value, VAULTSPACE Value, VAULTSPACE Value, VAULTSPACE State, VAULTSPACE State, VAULTSPACE cRawString) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State (*VAULTAPI(DestroyWindow))(VAULTSPACE ID) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State (*VAULTAPI(AddChildWindow))(VAULTSPACE ID, VAULTSPACE ID) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State (*VAULTAPI(RemoveChildWindow))(VAULTSPACE ID, VAULTSPACE ID) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State (*VAULTAPI(SetWindowPos))(VAULTSPACE ID, VAULTSPACE Value, VAULTSPACE Value, VAULTSPACE Value, VAULTSPACE Value) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State (*VAULTAPI(SetWindowSize))(VAULTSPACE ID, VAULTSPACE Value, VAULTSPACE Value, VAULTSPACE Value, VAULTSPACE Value) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State (*VAULTAPI(SetWindowVisible))(VAULTSPACE ID, VAULTSPACE State) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State (*VAULTAPI(SetWindowLocked))(VAULTSPACE ID, VAULTSPACE State) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State (*VAULTAPI(SetWindowText))(VAULTSPACE ID, VAULTSPACE cRawString) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE ID (*VAULTAPI(CreateButton))(VAULTSPACE Value, VAULTSPACE Value, VAULTSPACE Value, VAULTSPACE Value, VAULTSPACE Value, VAULTSPACE Value, VAULTSPACE Value, VAULTSPACE Value, VAULTSPACE State, VAULTSPACE State, VAULTSPACE cRawString) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE ID (*VAULTAPI(CreateText))(VAULTSPACE Value, VAULTSPACE Value, VAULTSPACE Value, VAULTSPACE Value, VAULTSPACE Value, VAULTSPACE Value, VAULTSPACE Value, VAULTSPACE Value, VAULTSPACE State, VAULTSPACE State, VAULTSPACE cRawString) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE ID (*VAULTAPI(CreateEdit))(VAULTSPACE Value, VAULTSPACE Value, VAULTSPACE Value, VAULTSPACE Value, VAULTSPACE Value, VAULTSPACE Value, VAULTSPACE Value, VAULTSPACE Value, VAULTSPACE State, VAULTSPACE State, VAULTSPACE cRawString) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State (*VAULTAPI(SetEditMaxLength))(VAULTSPACE ID, VAULTSPACE UCount) VAULTCPP(noexcept);
	VAULTSCRIPT VAULTSPACE State (*VAULTAPI(SetEditValidation))(VAULTSPACE ID, VAULTSPACE cRawString) VAULTCPP(noexcept);
VAULTCPP(})

#ifdef __cplusplus
namespace vaultmp
{
	template<typename T, size_t t> struct TypeChar { static_assert(!t, "Unsupported type in variadic type list"); };
	template<typename T> struct TypeChar<T*, sizeof(void*)> { enum { value = 'p' }; };
	template<typename T> struct TypeChar<T, sizeof(uint8_t)> { enum { value = std::is_signed<T>::value ? 'q' : 'i' }; };
	template<typename T> struct TypeChar<T, sizeof(uint16_t)> { enum { value = std::is_signed<T>::value ? 'q' : 'i' }; };
	template<typename T> struct TypeChar<T, sizeof(uint32_t)> { enum { value = std::is_signed<T>::value ? 'q' : 'i' }; };
	template<typename T> struct TypeChar<T, sizeof(uint64_t)> { enum { value = std::is_signed<T>::value ? 'w' : 'l' }; };
	template<> struct TypeChar<Value, sizeof(Value)> { enum { value = 'f' }; };
	template<> struct TypeChar<cRawString, sizeof(cRawString)> { enum { value = 's' }; };
	template<> struct TypeChar<RawString, sizeof(RawString)> { enum { value = 's' }; };

	template<typename... Types>
	struct TypeString {
		static constexpr RawChar value[sizeof...(Types) + 1] = {
			TypeChar<typeof(Types), sizeof(Types)>::value...
		};
	};

	template<typename... Types>
	constexpr char TypeString<Types...>::value[];

	VAULTFUNCTION Void timestamp() noexcept { return VAULTAPI(timestamp)(); }
	VAULTFUNCTION Timer CreateTimer(Function<> function, Interval interval) noexcept { return VAULTAPI(CreateTimer)(function, interval); }

	template<typename... Types>
	VAULTFUNCTION Timer CreateTimerEx(Function<Types...> function, Interval interval, Types... values) noexcept {
		cRawString types = TypeString<Types...>::value;
		return VAULTAPI(CreateTimerEx)(reinterpret_cast<Function<>>(function), interval, types, values...);
	}

	VAULTFUNCTION Void KillTimer(Timer timer = static_cast<Timer>(0)) noexcept { return VAULTAPI(KillTimer)(timer); }

	template<typename... Types>
	VAULTFUNCTION Void MakePublic(Function<Types...> function, const String& name) noexcept {
		cRawString types = TypeString<Types...>::value;
		return VAULTAPI(MakePublic)(reinterpret_cast<Function<>>(function), name.c_str(), types);
	}

	template<typename... Types>
	VAULTFUNCTION Void MakePublic(Function<Types...> function, cRawString name) noexcept {
		cRawString types = TypeString<Types...>::value;
		return VAULTAPI(MakePublic)(reinterpret_cast<Function<>>(function), name, types);
	}

	template<typename... Types>
	VAULTFUNCTION Result CallPublic(const String& name, Types... values) noexcept {
		static_assert(TypeString<Types...>::value != nullptr, "Unsupported type in variadic type list");
		return VAULTAPI(CallPublic)(name.c_str(), values...);
	}

	template<typename... Types>
	VAULTFUNCTION Result CallPublic(cRawString name, Types... values) noexcept {
		static_assert(TypeString<Types...>::value != nullptr, "Unsupported type in variadic type list");
		return VAULTAPI(CallPublic)(name, values...);
	}

	VAULTFUNCTION Void SetServerName(const String& name) noexcept { return VAULTAPI(SetServerName)(name.c_str()); }
	VAULTFUNCTION Void SetServerName(cRawString name) noexcept { return VAULTAPI(SetServerName)(name); }
	VAULTFUNCTION Void SetServerMap(const String& map) noexcept { return VAULTAPI(SetServerMap)(map.c_str()); }
	VAULTFUNCTION Void SetServerMap(cRawString map) noexcept { return VAULTAPI(SetServerMap)(map); }
	VAULTFUNCTION Void SetServerRule(const String& key, const String& value) noexcept { return VAULTAPI(SetServerRule)(key.c_str(), value.c_str()); }
	VAULTFUNCTION Void SetServerRule(const String& key, cRawString value) noexcept { return VAULTAPI(SetServerRule)(key.c_str(), value); }
	VAULTFUNCTION Void SetServerRule(cRawString key, const String& value) noexcept { return VAULTAPI(SetServerRule)(key, value.c_str()); }
	VAULTFUNCTION Void SetServerRule(cRawString key, cRawString value) noexcept { return VAULTAPI(SetServerRule)(key, value); }
	VAULTFUNCTION UCount GetMaximumPlayers() noexcept { return VAULTAPI(GetMaximumPlayers)(); }
	VAULTFUNCTION UCount GetCurrentPlayers() noexcept { return VAULTAPI(GetCurrentPlayers)(); }

	VAULTFUNCTION String ValueToString(Index index) noexcept { return String(VAULTAPI(ValueToString)(index)); }
	VAULTFUNCTION String AxisToString(Index index) noexcept { return String(VAULTAPI(AxisToString)(index)); }
	VAULTFUNCTION String AnimToString(Index index) noexcept { return String(VAULTAPI(AnimToString)(index)); }
	VAULTFUNCTION String BaseToString(Base base) noexcept { return String(VAULTAPI(BaseToString)(base)); }

	VAULTFUNCTION State Kick(ID id) noexcept { return VAULTAPI(Kick)(id); }
	VAULTFUNCTION State UIMessage(ID id, const String& message, Emoticon emoticon = Emoticon::Happy) noexcept { return VAULTAPI(UIMessage)(id, message.c_str(), emoticon); }
	VAULTFUNCTION State UIMessage(ID id, cRawString message, Emoticon emoticon = Emoticon::Happy) noexcept { return VAULTAPI(UIMessage)(id, message, emoticon); }
	VAULTFUNCTION State UIMessage(const String& message, Emoticon emoticon = Emoticon::Happy) noexcept { return VAULTAPI(UIMessage)(static_cast<ID>(0), message.c_str(), emoticon); }
	VAULTFUNCTION State UIMessage(cRawString message, Emoticon emoticon = Emoticon::Happy) noexcept { return VAULTAPI(UIMessage)(static_cast<ID>(0), message, emoticon); }
	VAULTFUNCTION State ChatMessage(ID id, const String& message) noexcept { return VAULTAPI(ChatMessage)(id, message.c_str()); }
	VAULTFUNCTION State ChatMessage(ID id, cRawString message) noexcept { return VAULTAPI(ChatMessage)(id, message); }
	VAULTFUNCTION State ChatMessage(const String& message) noexcept { return VAULTAPI(ChatMessage)(static_cast<ID>(0), message.c_str()); }
	VAULTFUNCTION State ChatMessage(cRawString message) noexcept { return VAULTAPI(ChatMessage)(static_cast<ID>(0), message); }
	VAULTFUNCTION Void SetRespawnTime(Interval interval) noexcept { return VAULTAPI(SetRespawnTime)(interval); }
	VAULTFUNCTION Void SetSpawnCell(CELL cell) noexcept { return VAULTAPI(SetSpawnCell)(cell); }
	VAULTFUNCTION Void SetConsoleEnabled(State enabled) noexcept { return VAULTAPI(SetConsoleEnabled)(enabled); }
	VAULTFUNCTION Void SetGameWeather(WTHR weather) noexcept { return VAULTAPI(SetGameWeather)(weather); }
	VAULTFUNCTION Void SetGameTime(Time time) noexcept { return VAULTAPI(SetGameTime)(time); }
	VAULTFUNCTION Void SetGameYear(UCount year) noexcept { return VAULTAPI(SetGameYear)(year); }
	VAULTFUNCTION Void SetGameMonth(UCount month) noexcept { return VAULTAPI(SetGameMonth)(month); }
	VAULTFUNCTION Void SetGameDay(UCount day) noexcept { return VAULTAPI(SetGameDay)(day); }
	VAULTFUNCTION Void SetGameHour(UCount hour) noexcept { return VAULTAPI(SetGameHour)(hour); }
	VAULTFUNCTION Void SetTimeScale(Value scale) noexcept { return VAULTAPI(SetTimeScale)(scale); }
	VAULTFUNCTION State IsValid(ID id) noexcept { return VAULTAPI(IsValid)(id); }
	VAULTFUNCTION State IsObject(ID id) noexcept { return VAULTAPI(IsObject)(id); }
	VAULTFUNCTION State IsItem(ID id) noexcept { return VAULTAPI(IsItem)(id); }
	VAULTFUNCTION State IsContainer(ID id) noexcept { return VAULTAPI(IsContainer)(id); }
	VAULTFUNCTION State IsActor(ID id) noexcept { return VAULTAPI(IsActor)(id); }
	VAULTFUNCTION State IsPlayer(ID id) noexcept { return VAULTAPI(IsPlayer)(id); }
	VAULTFUNCTION State IsCell(CELL cell) noexcept { return VAULTAPI(IsCell)(cell); }
	VAULTFUNCTION State IsInterior(CELL cell) noexcept { return VAULTAPI(IsInterior)(cell); }
	VAULTFUNCTION State IsItemList(ID id) noexcept { return VAULTAPI(IsItemList)(id); }
	VAULTFUNCTION State IsWindow(ID id) noexcept { return VAULTAPI(IsWindow)(id); }
	VAULTFUNCTION State IsButton(ID id) noexcept { return VAULTAPI(IsButton)(id); }
	VAULTFUNCTION State IsText(ID id) noexcept { return VAULTAPI(IsText)(id); }
	VAULTFUNCTION State IsEdit(ID id) noexcept { return VAULTAPI(IsEdit)(id); }
	VAULTFUNCTION State IsChatbox(ID id) noexcept { return VAULTAPI(IsChatbox)(id); }
	VAULTFUNCTION Type GetType(ID id) noexcept { return VAULTAPI(GetType)(id); }
	VAULTFUNCTION UCount GetConnection(ID id) noexcept { return VAULTAPI(GetConnection)(id); }
	VAULTFUNCTION UCount GetCount(Type type) noexcept { return VAULTAPI(GetCount)(type); }
	VAULTFUNCTION IDVector GetList(Type type) noexcept {
		RawArray<ID> data;
		UCount size = VAULTAPI(GetList)(type, &data);
		return size ? IDVector(data, data + size) : IDVector();
	}
	VAULTFUNCTION Interval GetRespawnTime() noexcept { return VAULTAPI(GetRespawnTime)(); }
	VAULTFUNCTION CELL GetSpawnCell() noexcept { return VAULTAPI(GetSpawnCell)(); }
	VAULTFUNCTION State GetConsoleEnabled() noexcept { return VAULTAPI(GetConsoleEnabled)(); }
	VAULTFUNCTION WTHR GetGameWeather() noexcept { return VAULTAPI(GetGameWeather)(); }
	VAULTFUNCTION Time GetGameTime() noexcept { return VAULTAPI(GetGameTime)(); }
	VAULTFUNCTION UCount GetGameYear() noexcept { return VAULTAPI(GetGameYear)(); }
	VAULTFUNCTION UCount GetGameMonth() noexcept { return VAULTAPI(GetGameMonth)(); }
	VAULTFUNCTION UCount GetGameDay() noexcept { return VAULTAPI(GetGameDay)(); }
	VAULTFUNCTION UCount GetGameHour() noexcept { return VAULTAPI(GetGameHour)(); }
	VAULTFUNCTION Value GetTimeScale() noexcept { return VAULTAPI(GetTimeScale)(); }

	VAULTFUNCTION ID GetID(Ref ref) noexcept { return VAULTAPI(GetID)(ref); }
	VAULTFUNCTION Ref GetReference(ID id) noexcept { return VAULTAPI(GetReference)(id); }
	VAULTFUNCTION Base GetBase(ID id) noexcept { return VAULTAPI(GetBase)(id); }
	VAULTFUNCTION Void GetPos(ID id, Value& X, Value& Y, Value& Z) noexcept { return VAULTAPI(GetPos)(id, &X, &Y, &Z); }
	VAULTFUNCTION Void GetAngle(ID id, Value& X, Value& Y, Value& Z) noexcept { return VAULTAPI(GetAngle)(id, &X, &Y, &Z); }
	VAULTFUNCTION CELL GetCell(ID id) noexcept { return VAULTAPI(GetCell)(id); }
	VAULTFUNCTION Lock GetLock(ID id) noexcept { return VAULTAPI(GetLock)(id); }
	VAULTFUNCTION NPC_ GetOwner(ID id) noexcept { return VAULTAPI(GetOwner)(id); }
	VAULTFUNCTION String GetBaseName(ID id) noexcept { return String(VAULTAPI(GetBaseName)(id)); }
	VAULTFUNCTION State IsNearPoint(ID id, Value X, Value Y, Value Z, Value R) noexcept { return VAULTAPI(IsNearPoint)(id, X, Y, Z, R); }
	VAULTFUNCTION ID GetItemContainer(ID id) noexcept { return VAULTAPI(GetItemContainer)(id); }
	VAULTFUNCTION UCount GetItemCount(ID id) noexcept { return VAULTAPI(GetItemCount)(id); }
	VAULTFUNCTION Value GetItemCondition(ID id) noexcept { return VAULTAPI(GetItemCondition)(id); }
	VAULTFUNCTION State GetItemEquipped(ID id) noexcept { return VAULTAPI(GetItemEquipped)(id); }
	VAULTFUNCTION State GetItemSilent(ID id) noexcept { return VAULTAPI(GetItemSilent)(id); }
	VAULTFUNCTION State GetItemStick(ID id) noexcept { return VAULTAPI(GetItemStick)(id); }

	#define GetContainerItemCount_Template(type) \
		VAULTFUNCTION UCount GetContainerItemCount(ID id, type item) noexcept { return VAULTAPI(GetContainerItemCount)(id, static_cast<Base>(item)); }
	GetContainerItemCount_Template(Base);
	GetContainerItemCount_Template(ALCH);
	GetContainerItemCount_Template(AMMO);
	GetContainerItemCount_Template(ARMA);
	GetContainerItemCount_Template(ARMO);
	GetContainerItemCount_Template(ENCH);
	GetContainerItemCount_Template(KEYM);
	GetContainerItemCount_Template(MISC);
	GetContainerItemCount_Template(NOTE);
	GetContainerItemCount_Template(WEAP);
	#undef GetContainerItemCount_Template

	VAULTFUNCTION UCount GetContainerItemCount(ID id) noexcept { return VAULTAPI(GetContainerItemCount)(id, static_cast<Base>(0)); }
	VAULTFUNCTION IDVector GetContainerItemList(ID id) noexcept {
		RawArray<ID> data;
		UCount size = VAULTAPI(GetContainerItemList)(id, &data);
		return size ? IDVector(data, data + size) : IDVector();
	}
	VAULTFUNCTION Value GetActorValue(ID id, ActorValue index) noexcept { return VAULTAPI(GetActorValue)(id, index); }
	VAULTFUNCTION Value GetActorBaseValue(ID id, ActorValue index) noexcept { return VAULTAPI(GetActorBaseValue)(id, index); }
	VAULTFUNCTION IDLE GetActorIdleAnimation(ID id) noexcept { return VAULTAPI(GetActorIdleAnimation)(id); }
	VAULTFUNCTION Index GetActorMovingAnimation(ID id) noexcept { return VAULTAPI(GetActorMovingAnimation)(id); }
	VAULTFUNCTION Index GetActorWeaponAnimation(ID id) noexcept { return VAULTAPI(GetActorWeaponAnimation)(id); }
	VAULTFUNCTION State GetActorAlerted(ID id) noexcept { return VAULTAPI(GetActorAlerted)(id); }
	VAULTFUNCTION State GetActorSneaking(ID id) noexcept { return VAULTAPI(GetActorSneaking)(id); }
	VAULTFUNCTION State GetActorDead(ID id) noexcept { return VAULTAPI(GetActorDead)(id); }
	VAULTFUNCTION RACE GetActorBaseRace(ID id) noexcept { return VAULTAPI(GetActorBaseRace)(id); }
	VAULTFUNCTION State GetActorBaseSex(ID id) noexcept { return VAULTAPI(GetActorBaseSex)(id); }
	VAULTFUNCTION State IsActorJumping(ID id) noexcept { return VAULTAPI(IsActorJumping)(id); }
	VAULTFUNCTION Interval GetPlayerRespawnTime(ID id) noexcept { return VAULTAPI(GetPlayerRespawnTime)(id); }
	VAULTFUNCTION CELL GetPlayerSpawnCell(ID id) noexcept { return VAULTAPI(GetPlayerSpawnCell)(id); }
	VAULTFUNCTION State GetPlayerConsoleEnabled(ID id) noexcept { return VAULTAPI(GetPlayerConsoleEnabled)(id); }
	VAULTFUNCTION UCount GetPlayerWindowCount(ID id) noexcept { return VAULTAPI(GetPlayerWindowCount)(id); }
	VAULTFUNCTION IDVector GetPlayerWindowList(ID id) noexcept {
		RawArray<ID> data;
		UCount size = VAULTAPI(GetPlayerWindowList)(id, &data);
		return size ? IDVector(data, data + size) : IDVector();
	}
	VAULTFUNCTION ID GetPlayerChatboxWindow(ID id) noexcept { return VAULTAPI(GetPlayerChatboxWindow)(id); }

	VAULTFUNCTION ID CreateObject(Base object, ID id) noexcept { return VAULTAPI(CreateObject)(object, id, static_cast<CELL>(0), 0.00, 0.00, 0.00); }
	VAULTFUNCTION ID CreateObject(Base object, CELL cell, Value X, Value Y, Value Z) noexcept { return VAULTAPI(CreateObject)(object, static_cast<ID>(0), cell, X, Y, Z); }
	VAULTFUNCTION State DestroyObject(ID id) noexcept { return VAULTAPI(DestroyObject)(id); }
	VAULTFUNCTION State SetPos(ID id, Value X, Value Y, Value Z) noexcept { return VAULTAPI(SetPos)(id, X, Y, Z); }
	VAULTFUNCTION State SetAngle(ID id, Value X, Value Y, Value Z) noexcept { return VAULTAPI(SetAngle)(id, X, Y, Z); }
	VAULTFUNCTION State SetCell(ID id, CELL cell, Value X = 0.00, Value Y = 0.00, Value Z = 0.00) noexcept { return VAULTAPI(SetCell)(id, cell, X, Y, Z); }
	VAULTFUNCTION State SetLock(ID id, Lock lock) noexcept { return VAULTAPI(SetLock)(id, lock); }
	VAULTFUNCTION State SetOwner(ID id, NPC_ owner) noexcept { return VAULTAPI(SetOwner)(id, owner); }
	VAULTFUNCTION State SetBaseName(ID id, const String& name) noexcept { return VAULTAPI(SetBaseName)(id, name.c_str()); }
	VAULTFUNCTION State SetBaseName(ID id, cRawString name) noexcept { return VAULTAPI(SetBaseName)(id, name); }

	#define CreateItem_Template(type) \
		VAULTFUNCTION ID CreateItem(type item, ID id) noexcept { return VAULTAPI(CreateItem)(static_cast<Base>(item), id, static_cast<CELL>(0), 0.00, 0.00, 0.00); } \
		VAULTFUNCTION ID CreateItem(type item, CELL cell, Value X, Value Y, Value Z) noexcept { return VAULTAPI(CreateItem)(static_cast<Base>(item), static_cast<ID>(0), cell, X, Y, Z); }
	CreateItem_Template(Base);
	CreateItem_Template(ALCH);
	CreateItem_Template(AMMO);
	CreateItem_Template(ARMA);
	CreateItem_Template(ARMO);
	CreateItem_Template(ENCH);
	CreateItem_Template(KEYM);
	CreateItem_Template(MISC);
	CreateItem_Template(NOTE);
	CreateItem_Template(WEAP);
	#undef CreateItem_Template

	VAULTFUNCTION ID SetItemContainer(ID id, ID container) noexcept { return VAULTAPI(SetItemContainer)(id, container); }
	VAULTFUNCTION State SetItemCount(ID id, UCount count) noexcept { return VAULTAPI(SetItemCount)(id, count); }
	VAULTFUNCTION State SetItemCondition(ID id, Value condition) noexcept { return VAULTAPI(SetItemCondition)(id, condition); }
	VAULTFUNCTION State SetItemEquipped(ID id, State equipped, State silent = True, State stick = False) noexcept { return VAULTAPI(SetItemEquipped)(id, equipped, silent, stick); }
	VAULTFUNCTION ID CreateContainer(CONT container, ID id) noexcept { return VAULTAPI(CreateContainer)(container, id, static_cast<CELL>(0), 0.00, 0.00, 0.00); }
	VAULTFUNCTION ID CreateContainer(CONT container, CELL cell, Value X, Value Y, Value Z) noexcept { return VAULTAPI(CreateContainer)(container, static_cast<ID>(0), cell, X, Y, Z); }

	struct AddItem_Initializer {
		Base item;
		UCount count;
		Value condition;
		State silent;
		State equipped;
		State stick;

		#define AddItem_Initializer_ctor(type) \
			AddItem_Initializer(type item, UCount count = 1, Value condition = 100.0, State silent = True, State equipped = False, State stick = False) : item(static_cast<Base>(item)), count(count), condition(condition), silent(silent), equipped(equipped), stick(stick) {}
		AddItem_Initializer_ctor(Base);
		AddItem_Initializer_ctor(ALCH);
		AddItem_Initializer_ctor(AMMO);
		AddItem_Initializer_ctor(ARMA);
		AddItem_Initializer_ctor(ARMO);
		AddItem_Initializer_ctor(ENCH);
		AddItem_Initializer_ctor(KEYM);
		AddItem_Initializer_ctor(MISC);
		AddItem_Initializer_ctor(NOTE);
		AddItem_Initializer_ctor(WEAP);
		#undef AddItem_Initializer_ctor
	};

	VAULTFUNCTION ID CreateItemList(ID source = static_cast<ID>(0)) noexcept { return VAULTAPI(CreateItemList)(source, static_cast<Base>(0)); }
	VAULTFUNCTION ID CreateItemList(Base source) noexcept { return VAULTAPI(CreateItemList)(static_cast<ID>(0), source); }

	VAULTFUNCTION ID CreateItemList(std::initializer_list<ID> source) noexcept {
		ID result = VAULTAPI(CreateItemList)(static_cast<ID>(0), static_cast<Base>(0));

		for (const auto& id : source)
			VAULTAPI(AddItemList)(result, id, static_cast<Base>(0));

		return result;
	}

	VAULTFUNCTION ID CreateItemList(std::initializer_list<Base> source) noexcept {
		ID result = VAULTAPI(CreateItemList)(static_cast<ID>(0), static_cast<Base>(0));

		for (const auto& base : source)
			VAULTAPI(AddItemList)(result, static_cast<ID>(0), base);

		return result;
	}

	VAULTFUNCTION ID CreateItemList(std::initializer_list<AddItem_Initializer> source) noexcept {
		ID result = VAULTAPI(CreateItemList)(static_cast<ID>(0), static_cast<Base>(0));

		for (const auto& item : source)
		{
			VAULTAPI(AddItem)(result, item.item, item.count, item.condition, item.silent);

			if (item.equipped)
				VAULTAPI(EquipItem)(result, item.item, item.silent, item.stick);
		}

		return result;
	}

	#define AddItem_Template(type) \
		VAULTFUNCTION ID AddItem(ID id, type item, UCount count = 1, Value condition = 100.0, State silent = True) noexcept { return VAULTAPI(AddItem)(id, static_cast<Base>(item), count, condition, silent); }
	AddItem_Template(Base);
	AddItem_Template(ALCH);
	AddItem_Template(AMMO);
	AddItem_Template(ARMA);
	AddItem_Template(ARMO);
	AddItem_Template(ENCH);
	AddItem_Template(KEYM);
	AddItem_Template(MISC);
	AddItem_Template(NOTE);
	AddItem_Template(WEAP);
	#undef AddItem_Template

	VAULTFUNCTION Void AddItem(ID id, std::initializer_list<AddItem_Initializer> source) noexcept {
		for (const auto& item : source)
		{
			VAULTAPI(AddItem)(id, item.item, item.count, item.condition, item.silent);

			if (item.equipped)
				VAULTAPI(EquipItem)(id, item.item, item.silent, item.stick);
		}
	}

	VAULTFUNCTION Void AddItemList(ID id, ID source) noexcept { return VAULTAPI(AddItemList)(id, source, static_cast<Base>(0)); }

	#define AddItemList_Template(type) \
		VAULTFUNCTION Void AddItemList(ID id, type source) noexcept { return VAULTAPI(AddItemList)(id, static_cast<ID>(0), static_cast<Base>(source)); }
	AddItemList_Template(Base);
	AddItemList_Template(NPC_);
	AddItemList_Template(CREA);
	#undef AddItemList_Template

	#define RemoveItem_Template(type) \
		VAULTFUNCTION UCount RemoveItem(ID id, type item, UCount count = 1, State silent = True) noexcept { return VAULTAPI(RemoveItem)(id, static_cast<Base>(item), count, silent); }
	RemoveItem_Template(Base);
	RemoveItem_Template(ALCH);
	RemoveItem_Template(AMMO);
	RemoveItem_Template(ARMA);
	RemoveItem_Template(ARMO);
	RemoveItem_Template(ENCH);
	RemoveItem_Template(KEYM);
	RemoveItem_Template(MISC);
	RemoveItem_Template(NOTE);
	RemoveItem_Template(WEAP);
	#undef RemoveItem_Template

	VAULTFUNCTION Void RemoveAllItems(ID id) noexcept { return VAULTAPI(RemoveAllItems)(id); }

	#define CreateActor_Template(type) \
		VAULTFUNCTION ID CreateActor(type actor, ID id) noexcept { return VAULTAPI(CreateActor)(static_cast<Base>(actor), id, static_cast<CELL>(0), 0.00, 0.00, 0.00); } \
		VAULTFUNCTION ID CreateActor(type actor, CELL cell, Value X, Value Y, Value Z) noexcept { return VAULTAPI(CreateActor)(static_cast<Base>(actor), static_cast<ID>(0), cell, X, Y, Z); }
	CreateActor_Template(Base);
	CreateActor_Template(NPC_);
	CreateActor_Template(CREA);
	#undef CreateActor_Template

	VAULTFUNCTION Void SetActorValue(ID id, ActorValue index, Value value) noexcept { return VAULTAPI(SetActorValue)(id, index, value); }
	VAULTFUNCTION Void SetActorBaseValue(ID id, ActorValue index, Value value) noexcept { return VAULTAPI(SetActorBaseValue)(id, index, value); }

	#define EquipItem_Template(type) \
		VAULTFUNCTION State EquipItem(ID id, type item, State silent = True, State stick = False) noexcept { return VAULTAPI(EquipItem)(id, static_cast<Base>(item), silent, stick); }
	EquipItem_Template(Base);
	EquipItem_Template(ARMA);
	EquipItem_Template(ARMO);
	EquipItem_Template(WEAP);
	#undef EquipItem_Template

	#define UnequipItem_Template(type) \
		VAULTFUNCTION State UnequipItem(ID id, type item, State silent = True, State stick = False) noexcept { return VAULTAPI(UnequipItem)(id, static_cast<Base>(item), silent, stick); }
	UnequipItem_Template(Base);
	UnequipItem_Template(ARMA);
	UnequipItem_Template(ARMO);
	UnequipItem_Template(WEAP);
	#undef UnequipItem_Template

	VAULTFUNCTION State PlayIdle(ID id, IDLE idle) noexcept { return VAULTAPI(PlayIdle)(id, idle); }
	VAULTFUNCTION State SetActorMovingAnimation(ID id, Index anim) noexcept { return VAULTAPI(SetActorMovingAnimation)(id, anim); }
	VAULTFUNCTION State SetActorWeaponAnimation(ID id, Index anim) noexcept { return VAULTAPI(SetActorWeaponAnimation)(id, anim); }
	VAULTFUNCTION State SetActorAlerted(ID id, State alerted) noexcept { return VAULTAPI(SetActorAlerted)(id, alerted); }
	VAULTFUNCTION State SetActorSneaking(ID id, State sneaking) noexcept { return VAULTAPI(SetActorSneaking)(id, sneaking); }
	VAULTFUNCTION State FireWeapon(ID id) noexcept { return VAULTAPI(FireWeapon)(id); }
	VAULTFUNCTION Void KillActor(ID id, Limb limbs = Limb::None, Death cause = Death::None) noexcept { return VAULTAPI(KillActor)(id, limbs, cause); }
	VAULTFUNCTION State SetActorBaseRace(ID id, RACE race) noexcept { return VAULTAPI(SetActorBaseRace)(id, race); }
	VAULTFUNCTION State AgeActorBaseRace(ID id, Count age) noexcept { return VAULTAPI(AgeActorBaseRace)(id, age); }
	VAULTFUNCTION State SetActorBaseSex(ID id, State female) noexcept { return VAULTAPI(SetActorBaseSex)(id, female); }
	VAULTFUNCTION Void SetPlayerRespawnTime(ID id, Interval interval) noexcept { return VAULTAPI(SetPlayerRespawnTime)(id, interval); }
	VAULTFUNCTION Void SetPlayerSpawnCell(ID id, CELL cell) noexcept { return VAULTAPI(SetPlayerSpawnCell)(id, cell); }
	VAULTFUNCTION Void SetPlayerConsoleEnabled(ID id, State enabled) noexcept { return VAULTAPI(SetPlayerConsoleEnabled)(id, enabled); }
	VAULTFUNCTION State AttachWindow(ID id, ID window) noexcept { return VAULTAPI(AttachWindow)(id, window); }
	VAULTFUNCTION State DetachWindow(ID id, ID window) noexcept { return VAULTAPI(DetachWindow)(id, window); }
	VAULTFUNCTION Void ForceWindowMode(ID id, State enabled) noexcept { return VAULTAPI(ForceWindowMode)(id, enabled); }

	VAULTFUNCTION ID GetParentWindow(ID id) noexcept { return VAULTAPI(GetParentWindow)(id); }
	VAULTFUNCTION ID GetWindowRoot(ID id) noexcept { return VAULTAPI(GetWindowRoot)(id); }
	VAULTFUNCTION UCount GetWindowChildCount(ID id) noexcept { return VAULTAPI(GetWindowChildCount)(id); }
	VAULTFUNCTION IDVector GetWindowChildList(ID id) noexcept {
		RawArray<ID> data;
		UCount size = VAULTAPI(GetWindowChildList)(id, &data);
		return size ? IDVector(data, data + size) : IDVector();
	}
	VAULTFUNCTION Void GetWindowPos(ID id, Value& X, Value& Y, Value& offset_X, Value& offset_Y) noexcept { return VAULTAPI(GetWindowPos)(id, &X, &Y, &offset_X, &offset_Y); }
	VAULTFUNCTION Void GetWindowSize(ID id, Value& X, Value& Y, Value& offset_X, Value& offset_Y) noexcept { return VAULTAPI(GetWindowSize)(id, &X, &Y, &offset_X, &offset_Y); }
	VAULTFUNCTION State GetWindowVisible(ID id) noexcept { return VAULTAPI(GetWindowVisible)(id); }
	VAULTFUNCTION State GetWindowLocked(ID id) noexcept { return VAULTAPI(GetWindowLocked)(id); }
	VAULTFUNCTION String GetWindowText(ID id) noexcept { return String(VAULTAPI(GetWindowText)(id)); }
	VAULTFUNCTION UCount GetEditMaxLength(ID id) noexcept { return VAULTAPI(GetEditMaxLength)(id); }
	VAULTFUNCTION String GetEditValidation(ID id) noexcept { return String(VAULTAPI(GetEditValidation)(id)); }

	VAULTFUNCTION ID CreateWindow(Value posX, Value posY, Value offset_posX, Value offset_posY, Value sizeX, Value sizeY, Value offset_sizeX, Value offset_sizeY, State visible = True, State locked = False, const String& text = "") noexcept { return VAULTAPI(CreateWindow)(posX, posY, offset_posX, offset_posY, sizeX, sizeY, offset_sizeX, offset_sizeY, visible, locked, text.c_str()); }
	VAULTFUNCTION ID CreateWindow(Value posX, Value posY, Value offset_posX, Value offset_posY, Value sizeX, Value sizeY, Value offset_sizeX, Value offset_sizeY, State visible = True, State locked = False, cRawString text = "") noexcept { return VAULTAPI(CreateWindow)(posX, posY, offset_posX, offset_posY, sizeX, sizeY, offset_sizeX, offset_sizeY, visible, locked, text); }
	VAULTFUNCTION State DestroyWindow(ID id) noexcept { return VAULTAPI(DestroyWindow)(id); }
	VAULTFUNCTION State AddChildWindow(ID id, ID child) noexcept { return VAULTAPI(AddChildWindow)(id, child); }
	VAULTFUNCTION State RemoveChildWindow(ID id, ID child) noexcept { return VAULTAPI(RemoveChildWindow)(id, child); }
	VAULTFUNCTION State SetWindowPos(ID id, Value X, Value Y, Value offset_X, Value offset_Y) noexcept { return VAULTAPI(SetWindowPos)(id, X, Y, offset_X, offset_Y); }
	VAULTFUNCTION State SetWindowSize(ID id, Value X, Value Y, Value offset_X, Value offset_Y) noexcept { return VAULTAPI(SetWindowSize)(id, X, Y, offset_X, offset_Y); }
	VAULTFUNCTION State SetWindowVisible(ID id, State visible) noexcept { return VAULTAPI(SetWindowVisible)(id, visible); }
	VAULTFUNCTION State SetWindowLocked(ID id, State locked) noexcept { return VAULTAPI(SetWindowLocked)(id, locked); }
	VAULTFUNCTION State SetWindowText(ID id, const String& text) noexcept { return VAULTAPI(SetWindowText)(id, text.c_str()); }
	VAULTFUNCTION State SetWindowText(ID id, cRawString text) noexcept { return VAULTAPI(SetWindowText)(id, text); }
	VAULTFUNCTION ID CreateButton(Value posX, Value posY, Value offset_posX, Value offset_posY, Value sizeX, Value sizeY, Value offset_sizeX, Value offset_sizeY, State visible = True, State locked = False, const String& text = "") noexcept { return VAULTAPI(CreateButton)(posX, posY, offset_posX, offset_posY, sizeX, sizeY, offset_sizeX, offset_sizeY, visible, locked, text.c_str()); }
	VAULTFUNCTION ID CreateButton(Value posX, Value posY, Value offset_posX, Value offset_posY, Value sizeX, Value sizeY, Value offset_sizeX, Value offset_sizeY, State visible = True, State locked = False, cRawString text = "") noexcept { return VAULTAPI(CreateButton)(posX, posY, offset_posX, offset_posY, sizeX, sizeY, offset_sizeX, offset_sizeY, visible, locked, text); }
	VAULTFUNCTION ID CreateText(Value posX, Value posY, Value offset_posX, Value offset_posY, Value sizeX, Value sizeY, Value offset_sizeX, Value offset_sizeY, State visible = True, State locked = False, const String& text = "") noexcept { return VAULTAPI(CreateText)(posX, posY, offset_posX, offset_posY, sizeX, sizeY, offset_sizeX, offset_sizeY, visible, locked, text.c_str()); }
	VAULTFUNCTION ID CreateText(Value posX, Value posY, Value offset_posX, Value offset_posY, Value sizeX, Value sizeY, Value offset_sizeX, Value offset_sizeY, State visible = True, State locked = False, cRawString text = "") noexcept { return VAULTAPI(CreateText)(posX, posY, offset_posX, offset_posY, sizeX, sizeY, offset_sizeX, offset_sizeY, visible, locked, text); }
	VAULTFUNCTION ID CreateEdit(Value posX, Value posY, Value offset_posX, Value offset_posY, Value sizeX, Value sizeY, Value offset_sizeX, Value offset_sizeY, State visible = True, State locked = False, const String& text = "") noexcept { return VAULTAPI(CreateEdit)(posX, posY, offset_posX, offset_posY, sizeX, sizeY, offset_sizeX, offset_sizeY, visible, locked, text.c_str()); }
	VAULTFUNCTION ID CreateEdit(Value posX, Value posY, Value offset_posX, Value offset_posY, Value sizeX, Value sizeY, Value offset_sizeX, Value offset_sizeY, State visible = True, State locked = False, cRawString text = "") noexcept { return VAULTAPI(CreateEdit)(posX, posY, offset_posX, offset_posY, sizeX, sizeY, offset_sizeX, offset_sizeY, visible, locked, text); }
	VAULTFUNCTION State SetEditMaxLength(ID id, UCount length) noexcept { return VAULTAPI(SetEditMaxLength)(id, length); }
	VAULTFUNCTION State SetEditValidation(ID id, const String& validation) noexcept { return VAULTAPI(SetEditValidation)(id, validation.c_str()); }
	VAULTFUNCTION State SetEditValidation(ID id, cRawString validation) noexcept { return VAULTAPI(SetEditValidation)(id, validation); }

	class Reference {
		protected:
			ID id;
			Ref refID;
			Base baseID;
			Type type;

			Reference(ID id, Type type) noexcept : id(id), refID(id ? vaultmp::GetReference(id) : static_cast<Ref>(0)), baseID(id ? vaultmp::GetBase(id) : static_cast<Base>(0)), type(type) {}
			virtual ~Reference() noexcept {}

		public:
			State IsValid() const noexcept { return id ? True : False; }
			explicit operator bool() const noexcept { return IsValid(); }
			explicit operator State() const noexcept { return IsValid(); }
			bool operator==(const Reference& R) const noexcept { return this->id == R.id; }
			bool operator!=(const Reference& R) const noexcept { return !operator==(R); }

			ID GetID() const noexcept { return id; }
			Ref GetReference() const noexcept { return refID; }
			Base GetBase() const noexcept { return baseID; }
			Type GetType() const noexcept { return type; }

			static UCount GetCount() noexcept { return vaultmp::GetCount(Type::ID_REFERENCE); }
			static IDVector GetList() noexcept { return vaultmp::GetList(Type::ID_REFERENCE); }
	};

	class Object : public Reference {
		protected:
			Object(ID id, Type type) noexcept : Reference(id, type) {}

		public:
			Object(ID id) noexcept : Reference(vaultmp::IsObject(id) ? id : static_cast<ID>(0), Type::ID_OBJECT) {}
			virtual ~Object() noexcept {}

			Void GetPos(Value& X, Value& Y, Value& Z) const noexcept { return vaultmp::GetPos(id, X, Y, Z); }
			Void GetAngle(Value& X, Value& Y, Value& Z) const noexcept { return vaultmp::GetAngle(id, X, Y, Z); }
			CELL GetCell() const noexcept { return vaultmp::GetCell(id); }
			Lock GetLock() const noexcept { return vaultmp::GetLock(id); }
			NPC_ GetOwner() const noexcept { return vaultmp::GetOwner(id); }
			String GetBaseName() const noexcept { return vaultmp::GetBaseName(id); }
			State IsNearPoint(Value X, Value Y, Value Z, Value R) const noexcept { return vaultmp::IsNearPoint(id, X, Y, Z, R); }

			State DestroyObject() noexcept { State state = vaultmp::DestroyObject(id); id = static_cast<ID>(0); return state; }
			State SetPos(Value X, Value Y, Value Z) noexcept { return vaultmp::SetPos(id, X, Y, Z); }
			State SetAngle(Value X, Value Y, Value Z) noexcept { return vaultmp::SetAngle(id, X, Y, Z); }
			State SetCell(CELL cell, Value X = 0.00, Value Y = 0.00, Value Z = 0.00) noexcept { return vaultmp::SetCell(id, cell, X, Y, Z); }
			State SetLock(Lock lock) noexcept { return vaultmp::SetLock(id, lock); }
			State SetOwner(NPC_ owner) noexcept { return vaultmp::SetOwner(id, owner); }
			State SetBaseName(const String& name) noexcept { return vaultmp::SetBaseName(id, name); }
			State SetBaseName(cRawString name) noexcept { return vaultmp::SetBaseName(id, name); }

			static ID Create(Base object, ID id) noexcept { return vaultmp::CreateObject(object, id); }
			static ID Create(Base object, CELL cell, Value X, Value Y, Value Z) noexcept { return vaultmp::CreateObject(object, cell, X, Y, Z); }
			static UCount GetCount() noexcept { return vaultmp::GetCount(Type::ID_OBJECT); }
			static IDVector GetList() noexcept { return vaultmp::GetList(Type::ID_OBJECT); }
	};

	class Item : public Object {
		protected:
			Item(ID id, Type type) noexcept : Object(id, type) {}

		public:
			Item(ID id) noexcept : Object(vaultmp::IsItem(id) ? id : static_cast<ID>(0), Type::ID_ITEM) {}
			virtual ~Item() noexcept {}

			ID GetItemContainer() const noexcept { return vaultmp::GetItemContainer(id); }
			UCount GetItemCount() const noexcept { return vaultmp::GetItemCount(id); }
			Value GetItemCondition() const noexcept { return vaultmp::GetItemCondition(id); }
			State GetItemEquipped() const noexcept { return vaultmp::GetItemEquipped(id); }
			State GetItemStick() const noexcept { return vaultmp::GetItemStick(id); }
			State GetItemSilent() const noexcept { return vaultmp::GetItemSilent(id); }

			ID SetItemContainer(ID container) noexcept { return vaultmp::SetItemContainer(id, container); }
			State SetItemCount(UCount count) noexcept { return vaultmp::SetItemCount(id, count); }
			State SetItemCondition(Value condition) noexcept { return vaultmp::SetItemCondition(id, condition); }
			State SetItemEquipped(State equipped, State silent = True, State stick = False) noexcept { return vaultmp::SetItemEquipped(id, equipped, silent, stick); }

			#define Create_Template(type) \
				static ID Create(type item, ID id) noexcept { return vaultmp::CreateItem(item, id); } \
				static ID Create(type item, CELL cell, Value X, Value Y, Value Z) noexcept { return vaultmp::CreateItem(item, cell, X, Y, Z); }
			Create_Template(Base);
			Create_Template(ALCH);
			Create_Template(AMMO);
			Create_Template(ARMA);
			Create_Template(ARMO);
			Create_Template(ENCH);
			Create_Template(KEYM);
			Create_Template(MISC);
			Create_Template(NOTE);
			Create_Template(WEAP);
			#undef Create_Template

			static UCount GetCount() noexcept { return vaultmp::GetCount(Type::ID_ITEM); }
			static IDVector GetList() noexcept { return vaultmp::GetList(Type::ID_ITEM); }
	};

	class Container : public Object {
		protected:
			Container(ID id, Type type) noexcept : Object(id, type) {}

		public:
			Container(ID id) noexcept : Object(vaultmp::IsContainer(id) ? id : static_cast<ID>(0), Type::ID_CONTAINER) {}
			virtual ~Container() noexcept {}

			#define GetContainerItemCount_Template(type) \
				UCount GetContainerItemCount(type item = static_cast<type>(0)) const noexcept { return vaultmp::GetContainerItemCount(id, item); }
			GetContainerItemCount_Template(Base);
			GetContainerItemCount_Template(ALCH);
			GetContainerItemCount_Template(AMMO);
			GetContainerItemCount_Template(ARMA);
			GetContainerItemCount_Template(ARMO);
			GetContainerItemCount_Template(ENCH);
			GetContainerItemCount_Template(KEYM);
			GetContainerItemCount_Template(MISC);
			GetContainerItemCount_Template(NOTE);
			GetContainerItemCount_Template(WEAP);
			#undef GetContainerItemCount_Template

			UCount GetContainerItemCount() const noexcept { return vaultmp::GetContainerItemCount(id, static_cast<Base>(0)); }
			IDVector GetContainerItemList() const noexcept { return vaultmp::GetContainerItemList(id); }

			#define AddItem_Template(type) \
				ID AddItem(type item, UCount count = 1, Value condition = 100.0, State silent = True) noexcept { return vaultmp::AddItem(id, item, count, condition, silent); }
			AddItem_Template(Base);
			AddItem_Template(ALCH);
			AddItem_Template(AMMO);
			AddItem_Template(ARMA);
			AddItem_Template(ARMO);
			AddItem_Template(ENCH);
			AddItem_Template(KEYM);
			AddItem_Template(MISC);
			AddItem_Template(NOTE);
			AddItem_Template(WEAP);
			#undef AddItem_Template

			Void AddItem(std::initializer_list<AddItem_Initializer> source) noexcept { return vaultmp::AddItem(id, source); }
			Void AddItemList(ID source) noexcept { return vaultmp::AddItemList(id, source); }

			#define AddItemList_Template(type) \
				Void AddItemList(type source) noexcept { return vaultmp::AddItemList(id, source); }
			AddItemList_Template(Base);
			AddItemList_Template(NPC_);
			AddItemList_Template(CREA);
			#undef AddItemList_Template

			#define RemoveItem_Template(type) \
				UCount RemoveItem(type item, UCount count = 1, State silent = True) noexcept { return vaultmp::RemoveItem(id, item, count, silent); }
			RemoveItem_Template(Base);
			RemoveItem_Template(ALCH);
			RemoveItem_Template(AMMO);
			RemoveItem_Template(ARMA);
			RemoveItem_Template(ARMO);
			RemoveItem_Template(ENCH);
			RemoveItem_Template(KEYM);
			RemoveItem_Template(MISC);
			RemoveItem_Template(NOTE);
			RemoveItem_Template(WEAP);
			#undef RemoveItem_Template

			Void RemoveAllItems() noexcept { return vaultmp::RemoveAllItems(id); }

			static ID Create(CONT container, ID id) noexcept{ return vaultmp::CreateContainer(container, id); }
			static ID Create(CONT container, CELL cell, Value X, Value Y, Value Z) noexcept { return vaultmp::CreateContainer(container, cell, X, Y, Z); }
			static UCount GetCount() noexcept { return vaultmp::GetCount(Type::ID_CONTAINER); }
			static IDVector GetList() noexcept { return vaultmp::GetList(Type::ID_CONTAINER); }
	};

	class ItemList {
		protected:
			ID id;

		public:
			ItemList(ID id) noexcept : id(vaultmp::IsItemList(id) ? id : static_cast<ID>(0)) {}
			virtual ~ItemList() noexcept {}

			State IsValid() const noexcept { return id ? True : False; }
			explicit operator bool() const noexcept { return IsValid(); }
			explicit operator State() const noexcept { return IsValid(); }
			bool operator==(const ItemList& R) const noexcept { return this->id == R.id; }
			bool operator!=(const ItemList& R) const noexcept { return !operator==(R); }

			ID GetID() const noexcept { return id; }

			#define GetContainerItemCount_Template(type) \
				UCount GetContainerItemCount(type item = static_cast<type>(0)) const noexcept { return vaultmp::GetContainerItemCount(id, item); }
			GetContainerItemCount_Template(Base);
			GetContainerItemCount_Template(ALCH);
			GetContainerItemCount_Template(AMMO);
			GetContainerItemCount_Template(ARMA);
			GetContainerItemCount_Template(ARMO);
			GetContainerItemCount_Template(ENCH);
			GetContainerItemCount_Template(KEYM);
			GetContainerItemCount_Template(MISC);
			GetContainerItemCount_Template(NOTE);
			GetContainerItemCount_Template(WEAP);
			#undef GetContainerItemCount_Template

			UCount GetContainerItemCount() const noexcept { return vaultmp::GetContainerItemCount(id, static_cast<Base>(0)); }
			IDVector GetContainerItemList() const noexcept { return vaultmp::GetContainerItemList(id); }

			#define AddItem_Template(type) \
				ID AddItem(type item, UCount count = 1, Value condition = 100.0, State silent = True) noexcept { return vaultmp::AddItem(id, item, count, condition, silent); }
			AddItem_Template(Base);
			AddItem_Template(ALCH);
			AddItem_Template(AMMO);
			AddItem_Template(ARMA);
			AddItem_Template(ARMO);
			AddItem_Template(ENCH);
			AddItem_Template(KEYM);
			AddItem_Template(MISC);
			AddItem_Template(NOTE);
			AddItem_Template(WEAP);
			#undef AddItem_Template

			Void AddItem(std::initializer_list<AddItem_Initializer> source) noexcept { return vaultmp::AddItem(id, source); }
			Void AddItemList(ID source) noexcept { return vaultmp::AddItemList(id, source); }

			#define AddItemList_Template(type) \
				Void AddItemList(type source) noexcept { return vaultmp::AddItemList(id, source); }
			AddItemList_Template(Base);
			AddItemList_Template(NPC_);
			AddItemList_Template(CREA);
			#undef AddItemList_Template

			#define RemoveItem_Template(type) \
				UCount RemoveItem(type item, UCount count = 1, State silent = True) noexcept { return vaultmp::RemoveItem(id, item, count, silent); }
			RemoveItem_Template(Base);
			RemoveItem_Template(ALCH);
			RemoveItem_Template(AMMO);
			RemoveItem_Template(ARMA);
			RemoveItem_Template(ARMO);
			RemoveItem_Template(ENCH);
			RemoveItem_Template(KEYM);
			RemoveItem_Template(MISC);
			RemoveItem_Template(NOTE);
			RemoveItem_Template(WEAP);
			#undef RemoveItem_Template

			#define EquipItem_Template(type) \
				State EquipItem(type item, State silent = True, State stick = False) noexcept { return vaultmp::EquipItem(id, item, silent, stick); }
			EquipItem_Template(Base);
			EquipItem_Template(ARMA);
			EquipItem_Template(ARMO);
			EquipItem_Template(WEAP);
			#undef EquipItem_Template

			#define UnequipItem_Template(type) \
				State UnequipItem(type item, State silent = True, State stick = False) noexcept { return vaultmp::UnequipItem(id, item, silent, stick); }
			UnequipItem_Template(Base);
			UnequipItem_Template(ARMA);
			UnequipItem_Template(ARMO);
			UnequipItem_Template(WEAP);
			#undef UnequipItem_Template

			Void RemoveAllItems() noexcept { return vaultmp::RemoveAllItems(id); }

			static ID Create(ID source = static_cast<ID>(0)) noexcept { return vaultmp::CreateItemList(source); }
			static ID Create(Base source) noexcept { return vaultmp::CreateItemList(source); }
			static ID Create(std::initializer_list<ID> source) noexcept { return vaultmp::CreateItemList(source); }
			static ID Create(std::initializer_list<Base> source) noexcept { return vaultmp::CreateItemList(source); }
			static ID Create(std::initializer_list<AddItem_Initializer> source) noexcept { return vaultmp::CreateItemList(source); }
	};

	class Actor : public Container {
		protected:
			Actor(ID id, Type type) noexcept : Container(id, type) {}

		public:
			Actor(ID id) noexcept : Container(vaultmp::IsActor(id) ? id : static_cast<ID>(0), Type::ID_ACTOR) {}
			virtual ~Actor() noexcept {}

			Value GetActorValue(ActorValue index) const noexcept { return vaultmp::GetActorValue(id, index); }
			Value GetActorBaseValue(ActorValue index) const noexcept { return vaultmp::GetActorBaseValue(id, index); }
			IDLE GetActorIdleAnimation() const noexcept { return vaultmp::GetActorIdleAnimation(id); }
			Index GetActorMovingAnimation() const noexcept { return vaultmp::GetActorMovingAnimation(id); }
			Index GetActorWeaponAnimation() const noexcept { return vaultmp::GetActorWeaponAnimation(id); }
			State GetActorAlerted() const noexcept { return vaultmp::GetActorAlerted(id); }
			State GetActorSneaking() const noexcept { return vaultmp::GetActorSneaking(id); }
			State GetActorDead() const noexcept { return vaultmp::GetActorDead(id); }
			RACE GetActorBaseRace() const noexcept { return vaultmp::GetActorBaseRace(id); }
			State GetActorBaseSex() const noexcept { return vaultmp::GetActorBaseSex(id); }
			State IsActorJumping() const noexcept { return vaultmp::IsActorJumping(id); }

			Void SetActorValue(ActorValue index, Value value) noexcept { return vaultmp::SetActorValue(id, index, value); }
			Void SetActorBaseValue(ActorValue index, Value value) noexcept { return vaultmp::SetActorBaseValue(id, index, value); }

			#define EquipItem_Template(type) \
				State EquipItem(type item, State silent = True, State stick = False) noexcept { return vaultmp::EquipItem(id, item, silent, stick); }
			EquipItem_Template(Base);
			EquipItem_Template(ARMA);
			EquipItem_Template(ARMO);
			EquipItem_Template(WEAP);
			#undef EquipItem_Template

			#define UnequipItem_Template(type) \
				State UnequipItem(type item, State silent = True, State stick = False) noexcept { return vaultmp::UnequipItem(id, item, silent, stick); }
			UnequipItem_Template(Base);
			UnequipItem_Template(ARMA);
			UnequipItem_Template(ARMO);
			UnequipItem_Template(WEAP);
			#undef UnequipItem_Template

			State PlayIdle(IDLE idle) noexcept { return vaultmp::PlayIdle(id, idle); }
			State SetActorMovingAnimation(Index anim) noexcept { return vaultmp::SetActorMovingAnimation(id, anim); }
			State SetActorWeaponAnimation(Index anim) noexcept { return vaultmp::SetActorWeaponAnimation(id, anim); }
			State SetActorAlerted(State alerted) noexcept { return vaultmp::SetActorAlerted(id, alerted); }
			State SetActorSneaking(State sneaking) noexcept { return vaultmp::SetActorSneaking(id, sneaking); }
			State FireWeapon() noexcept { return vaultmp::FireWeapon(id); }
			Void KillActor(Limb limbs = Limb::None, Death cause = Death::None) noexcept { return vaultmp::KillActor(id, limbs, cause); }
			State SetActorBaseRace(RACE race) noexcept { return vaultmp::SetActorBaseRace(id, race); }
			State AgeActorBaseRace(Count age) noexcept { return vaultmp::AgeActorBaseRace(id, age); }
			State SetActorBaseSex(State female) noexcept { return vaultmp::SetActorBaseSex(id, female); }

			#define Create_Template(type) \
				static ID Create(type actor, ID id) noexcept { return vaultmp::CreateActor(actor, id); } \
				static ID Create(type actor, CELL cell, Value X, Value Y, Value Z) noexcept { return vaultmp::CreateActor(actor, cell, X, Y, Z); }
			Create_Template(Base);
			Create_Template(NPC_);
			Create_Template(CREA);
			#undef Create_Template

			static UCount GetCount() noexcept { return vaultmp::GetCount(Type::ID_ACTOR); }
			static IDVector GetList() noexcept { return vaultmp::GetList(Type::ID_ACTOR); }
	};

	class Player : public Actor {
		public:
			Player(ID id) noexcept : Actor(vaultmp::IsPlayer(id) ? id : static_cast<ID>(0), Type::ID_PLAYER) {}
			virtual ~Player() noexcept {}

			Interval GetPlayerRespawnTime() const noexcept { return vaultmp::GetPlayerRespawnTime(id); }
			CELL GetPlayerSpawnCell() const noexcept { return vaultmp::GetPlayerSpawnCell(id); }
			State GetPlayerConsoleEnabled() const noexcept { return vaultmp::GetPlayerConsoleEnabled(id); }
			UCount GetPlayerWindowCount() const noexcept { return vaultmp::GetPlayerWindowCount(id); }
			IDVector GetPlayerWindowList() const noexcept { return vaultmp::GetPlayerWindowList(id); }
			ID GetPlayerChatboxWindow() const noexcept { return vaultmp::GetPlayerChatboxWindow(id); }

			Void SetPlayerRespawnTime(Interval interval) noexcept { return vaultmp::SetPlayerRespawnTime(id, interval); }
			Void SetPlayerSpawnCell(CELL cell) noexcept { return vaultmp::SetPlayerSpawnCell(id, cell); }
			Void SetPlayerConsoleEnabled(State enabled) noexcept { return vaultmp::SetPlayerConsoleEnabled(id, enabled); }
			State AttachWindow(ID window) noexcept { return vaultmp::AttachWindow(id, window); }
			State DetachWindow(ID window) noexcept { return vaultmp::DetachWindow(id, window); }
			Void ForceWindowMode(State enabled) noexcept { return vaultmp::ForceWindowMode(id, enabled); }

			State Kick() noexcept { return vaultmp::Kick(id); }
			State UIMessage(const String& message, Emoticon emoticon = Emoticon::Happy) noexcept { return vaultmp::UIMessage(id, message, emoticon); }
			State UIMessage(cRawString message, Emoticon emoticon = Emoticon::Happy) noexcept { return vaultmp::UIMessage(id, message, emoticon); }
			State ChatMessage(const String& message) noexcept { return vaultmp::ChatMessage(id, message); }
			State ChatMessage(cRawString message) noexcept { return vaultmp::ChatMessage(id, message); }

			Player& operator<<(const String& message) noexcept
			{
				ChatMessage(message);
				return *this;
			}

			Player& operator<<(cRawString message) noexcept
			{
				ChatMessage(message);
				return *this;
			}

			static UCount GetCount() noexcept { return vaultmp::GetCount(Type::ID_PLAYER); }
			static IDVector GetList() noexcept { return vaultmp::GetList(Type::ID_PLAYER); }
	};

	class Window {
		protected:
			ID id;
			Type type;

			Window(ID id, Type type) noexcept : id(id), type(type) {}

		public:
			Window(ID id) noexcept : id(vaultmp::IsWindow(id) ? id : static_cast<ID>(0)), type(Type::ID_WINDOW) {}
			virtual ~Window() noexcept {}

			State IsValid() const noexcept { return id ? True : False; }
			explicit operator bool() const noexcept { return IsValid(); }
			explicit operator State() const noexcept { return IsValid(); }
			bool operator==(const Window& R) const noexcept { return this->id == R.id; }
			bool operator!=(const Window& R) const noexcept { return !operator==(R); }

			ID GetID() const noexcept { return id; }
			Type GetType() const noexcept { return type; }

			ID GetParentWindow() const noexcept { return vaultmp::GetParentWindow(id); }
			ID GetWindowRoot() const noexcept { return vaultmp::GetParentWindow(id); }
			UCount GetWindowChildCount() const noexcept { return vaultmp::GetParentWindow(id); }
			IDVector GetWindowChildList() const noexcept { return vaultmp::GetWindowChildList(id); }
			Void GetWindowPos(Value& X, Value& Y, Value& offset_X, Value& offset_Y) const noexcept { return vaultmp::GetWindowPos(id, X, Y, offset_X, offset_Y); }
			Void GetWindowSize(Value& X, Value& Y, Value& offset_X, Value& offset_Y) const noexcept { return vaultmp::GetWindowSize(id, X, Y, offset_X, offset_Y); }
			State GetWindowVisible() const noexcept { return vaultmp::GetWindowVisible(id); }
			State GetWindowLocked() const noexcept { return vaultmp::GetWindowLocked(id); }
			String GetWindowText() const noexcept { return vaultmp::GetWindowText(id); }

			State DestroyWindow() noexcept { State state = vaultmp::DestroyWindow(id); id = static_cast<ID>(0); return state; }
			State AddChildWindow(ID child) noexcept { return vaultmp::AddChildWindow(id, child); }
			State RemoveChildWindow(ID child) noexcept { return vaultmp::RemoveChildWindow(id, child); }
			State SetWindowPos(Value X, Value Y, Value offset_X, Value offset_Y) noexcept { return vaultmp::SetWindowPos(id, X, Y, offset_X, offset_Y); }
			State SetWindowSize(Value X, Value Y, Value offset_X, Value offset_Y) noexcept { return vaultmp::SetWindowSize(id, X, Y, offset_X, offset_Y); }
			State SetWindowVisible(State visible) noexcept { return vaultmp::SetWindowVisible(id, visible); }
			State SetWindowLocked(State locked) noexcept { return vaultmp::SetWindowLocked(id, locked); }
			State SetWindowText(const String& text) noexcept { return vaultmp::SetWindowText(id, text); }
			State SetWindowText(cRawString text) noexcept { return vaultmp::SetWindowText(id, text); }

			static ID Create(Value posX, Value posY, Value offset_posX, Value offset_posY, Value sizeX, Value sizeY, Value offset_sizeX, Value offset_sizeY, State visible = True, State locked = False, const String& text = "") noexcept { return vaultmp::CreateWindow(posX, posY, offset_posX, offset_posY, sizeX, sizeY, offset_sizeX, offset_sizeY, visible, locked, text.c_str()); }
			static ID Create(Value posX, Value posY, Value offset_posX, Value offset_posY, Value sizeX, Value sizeY, Value offset_sizeX, Value offset_sizeY, State visible = True, State locked = False, cRawString text = "") noexcept { return vaultmp::CreateWindow(posX, posY, offset_posX, offset_posY, sizeX, sizeY, offset_sizeX, offset_sizeY, visible, locked, text); }
			static UCount GetCount() noexcept { return vaultmp::GetCount(Type::ID_WINDOW); }
			static IDVector GetList() noexcept { return vaultmp::GetList(Type::ID_WINDOW); }
	};

	class Button : public Window {
		protected:
			Button(ID id, Type type) noexcept : Window(id, type) {}

		public:
			Button(ID id) noexcept : Window(vaultmp::IsButton(id) ? id : static_cast<ID>(0), Type::ID_BUTTON) {}
			virtual ~Button() noexcept {}

			static ID Create(Value posX, Value posY, Value offset_posX, Value offset_posY, Value sizeX, Value sizeY, Value offset_sizeX, Value offset_sizeY, State visible = True, State locked = False, const String& text = "") noexcept { return vaultmp::CreateButton(posX, posY, offset_posX, offset_posY, sizeX, sizeY, offset_sizeX, offset_sizeY, visible, locked, text.c_str()); }
			static ID Create(Value posX, Value posY, Value offset_posX, Value offset_posY, Value sizeX, Value sizeY, Value offset_sizeX, Value offset_sizeY, State visible = True, State locked = False, cRawString text = "") noexcept { return vaultmp::CreateButton(posX, posY, offset_posX, offset_posY, sizeX, sizeY, offset_sizeX, offset_sizeY, visible, locked, text); }
			static UCount GetCount() noexcept { return vaultmp::GetCount(Type::ID_BUTTON); }
			static IDVector GetList() noexcept { return vaultmp::GetList(Type::ID_BUTTON); }
	};

	class Text : public Window {
		protected:
			Text(ID id, Type type) noexcept : Window(id, type) {}

		public:
			Text(ID id) noexcept : Window(vaultmp::IsText(id) ? id : static_cast<ID>(0), Type::ID_TEXT) {}
			virtual ~Text() noexcept {}

			static ID Create(Value posX, Value posY, Value offset_posX, Value offset_posY, Value sizeX, Value sizeY, Value offset_sizeX, Value offset_sizeY, State visible = True, State locked = False, const String& text = "") noexcept { return vaultmp::CreateText(posX, posY, offset_posX, offset_posY, sizeX, sizeY, offset_sizeX, offset_sizeY, visible, locked, text.c_str()); }
			static ID Create(Value posX, Value posY, Value offset_posX, Value offset_posY, Value sizeX, Value sizeY, Value offset_sizeX, Value offset_sizeY, State visible = True, State locked = False, cRawString text = "") noexcept { return vaultmp::CreateText(posX, posY, offset_posX, offset_posY, sizeX, sizeY, offset_sizeX, offset_sizeY, visible, locked, text); }
			static UCount GetCount() noexcept { return vaultmp::GetCount(Type::ID_TEXT); }
			static IDVector GetList() noexcept { return vaultmp::GetList(Type::ID_TEXT); }
	};

	class Edit : public Window {
		protected:
			Edit(ID id, Type type) noexcept : Window(id, type) {}

		public:
			Edit(ID id) noexcept : Window(vaultmp::IsEdit(id) ? id : static_cast<ID>(0), Type::ID_EDIT) {}
			virtual ~Edit() noexcept {}

			UCount GetEditMaxLength() const noexcept { return vaultmp::GetEditMaxLength(id); }
			String GetEditValidation() const noexcept { return vaultmp::GetEditValidation(id); }

			State SetEditMaxLength(UCount length) noexcept { return vaultmp::SetEditMaxLength(id, length); }
			State SetEditValidation(const String& validation) noexcept { return vaultmp::SetEditValidation(id, validation); }
			State SetEditValidation(cRawString validation) noexcept { return vaultmp::SetEditValidation(id, validation); }

			static ID Create(Value posX, Value posY, Value offset_posX, Value offset_posY, Value sizeX, Value sizeY, Value offset_sizeX, Value offset_sizeY, State visible = True, State locked = False, const String& text = "") noexcept { return vaultmp::CreateEdit(posX, posY, offset_posX, offset_posY, sizeX, sizeY, offset_sizeX, offset_sizeY, visible, locked, text.c_str()); }
			static ID Create(Value posX, Value posY, Value offset_posX, Value offset_posY, Value sizeX, Value sizeY, Value offset_sizeX, Value offset_sizeY, State visible = True, State locked = False, cRawString text = "") noexcept { return vaultmp::CreateEdit(posX, posY, offset_posX, offset_posY, sizeX, sizeY, offset_sizeX, offset_sizeY, visible, locked, text); }
			static UCount GetCount() noexcept { return vaultmp::GetCount(Type::ID_EDIT); }
			static IDVector GetList() noexcept { return vaultmp::GetList(Type::ID_EDIT); }
	};

	class GlobalChat {
		public:
			GlobalChat& operator<<(const String& message) noexcept
			{
				ChatMessage(message);
				return *this;
			}

			GlobalChat& operator<<(cRawString message) noexcept
			{
				ChatMessage(message);
				return *this;
			}
	} Chat;
}
#endif

#endif
