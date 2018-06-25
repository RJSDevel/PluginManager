#pragma once

#include "IPluginManager.h"      

#if defined(PLUGIN_EXPORT) 
#   define PLUGIN_API   __declspec(dllexport)
#else 
#   define PLUGIN_API   __declspec(dllimport)
#endif

class IPlugin {
public:
	virtual bool OnRegister(IPluginManager* manager) = 0;

	virtual char* GetPluginName() = 0;

	virtual void OnActivate(IPluginManager* manager) = 0;

	virtual void OnDestroy(IPluginManager* manager) = 0;
};


extern "C" PLUGIN_API IPlugin* getInterface();

typedef IPlugin* (getPluginInterface)();