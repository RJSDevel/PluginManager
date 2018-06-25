#pragma once
#include "IPluginManager.h"
#include "IPlugin.h"

#include <map>

class PluginManagerImpl : public IPluginManager
{
public:
	PluginManagerImpl();
	~PluginManagerImpl();

	void RegisterPlugin(int id, IPlugin* plugin, HMODULE* module);

	bool Activated(int id);

private:
	std::map<int, IPlugin*> plugins;
	std::map<int, HMODULE*> pluginModules;
};