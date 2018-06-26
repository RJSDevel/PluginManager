#include "stdafx.h"
#include "PluginManagerImpl.h"

PluginManagerImpl::PluginManagerImpl()
{
}

void PluginManagerImpl::RegisterPlugin(int id, IPlugin* plugin, HMODULE* module)
{
	try {
		plugin->OnRegister(this);
		plugins.insert(plugins.cend(), std::pair<int, IPlugin*>(id, plugin));
		pluginModules.insert(pluginModules.cend(), std::pair<int, HMODULE*>(id, module));
	}
	catch (...) {

	}
}

bool PluginManagerImpl::Activated(int id)
{
	try {
		for (std::map<int, IPlugin*>::iterator it = plugins.begin(); it != plugins.end(); ++it)
		{
			if (it->first == id)
			{
				it->second->OnActivate(this);
				return true;
			}
		}
	}
	catch (...) {

	}

	return false;
}

PluginManagerImpl::~PluginManagerImpl()
{
	try {
		for (std::map<int, HMODULE*>::iterator it = pluginModules.begin(); it != pluginModules.end(); ++it)
		{
			for (std::map<int, IPlugin*>::iterator itp = plugins.begin(); itp != plugins.end(); ++itp)
			{
				if (itp->first == it->first)
				{
					itp->second->OnDestroy(this);
					break;
				}
			}

			FreeLibrary(*it->second);
		}

		pluginModules.clear();
		plugins.clear();
	}
	catch (...) {

	}
}




