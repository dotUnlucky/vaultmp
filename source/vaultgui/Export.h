#include <iostream>

using namespace std;

bool GUI_MouseClickCallback(const CEGUI::EventArgs& e);
bool GUI_TextChanged(const CEGUI::EventArgs& e);

extern "C"
{
	__declspec(dllexport) void Chatbox_AddToChat(char* c);

	__declspec(dllexport) char* Chatbox_GetQueue();

	__declspec(dllexport) void Chatbox_AddPlayerName(string name,int* x,int* y,int* z);

	__declspec(dllexport) void Chatbox_DeletePlayerName(string name);

	__declspec(dllexport) void SetPlayersDataPointer(void* p);

	/*__declspec(dllexport) void HideChatbox(bool hide);

	__declspec(dllexport) void LockChatbox(bool lock);

	__declspec(dllexport) void SetChatboxPos(float x,float y);

	__declspec(dllexport) void SetChatboxSize(float x,float y);*/




	__declspec(dllexport) void GUI_CreateFrameWindow(char *name);

	__declspec(dllexport) void GUI_AddStaticText(char* parent,char* name);


	__declspec(dllexport) void GUI_AddTextbox(char* parent,char* name);
	__declspec(dllexport) void GUI_Textbox_SetMaxLength(char* name,int maxLength);
	__declspec(dllexport) void GUI_Textbox_SetValidationString(char* name,char* val);

	__declspec(dllexport) void GUI_AddButton(char* parent,char* name);

	__declspec(dllexport) void GUI_SetPosition(char* name,float x,float y,float xOffset,float yOffset);

	__declspec(dllexport) void GUI_SetSize(char* name,float x,float y,float xOffset,float yOffset);

	__declspec(dllexport) void GUI_SetText(char* name,char* txt);

	__declspec(dllexport) void GUI_RemoveWindow(char* name);

	__declspec(dllexport) void GUI_SetClickCallback(void (*pt)(char* name));
	__declspec(dllexport) void GUI_SetTextChangedCallback(void (*pt)(char* name,char* t));
	__declspec(dllexport) void GUI_SetListboxSelectionChangedCallback(void (*pt)(char* name,char** text));

	__declspec(dllexport) void GUI_ForceGUI(bool inGui);
	__declspec(dllexport) void GUI_SetVisible(char* name,bool visible);
	__declspec(dllexport) void GUI_AllowDrag(char* name,bool allow);

	__declspec(dllexport) void GUI_AddListbox(char* parent,char* name);
	__declspec(dllexport) void GUI_Listbox_AddItem(char* name,char* t);
	__declspec(dllexport) void GUI_Listbox_RemoveItem(char* name,char* t);
	__declspec(dllexport) void GUI_Listbox_EnableMultiSelect(char* name,bool e);
	__declspec(dllexport) vector<string>* GUI_Listbox_GetSelectedItems(char* name);
}