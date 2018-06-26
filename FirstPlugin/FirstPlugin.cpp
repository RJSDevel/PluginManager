// FirstPlugin.cpp: определяет экспортированные функции для приложения DLL.
//
#include <windows.h>
#include <IPlugin.h>

class FirstPlugin: public IPlugin
{
public:
	virtual void OnRegister(IPluginManager* manager);

	virtual char* GetPluginName();

	virtual void OnActivate(IPluginManager* manager);

	virtual void OnDestroy(IPluginManager* manager);
};

void FirstPlugin::OnRegister(IPluginManager* manager) {
	MessageBoxA(0, "OnRegister", "", 0);
}

char* FirstPlugin::GetPluginName() {
	return "First plugin";
}

void FirstPlugin::OnActivate(IPluginManager* manager) {
	MessageBoxA(0, "OnActivate", "", 0);
}

void FirstPlugin::OnDestroy(IPluginManager* manager) {
	MessageBoxA(0, "OnDestroy", "", 0);
}

PLUGIN_API IPlugin* getInterface() {
	return new FirstPlugin();
}