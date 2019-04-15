class CfgPatches
{
	class EdenKeybinds
	{
		units[] = {}; // No objects must belong to the addon. CfgVehicles should ideally not be present at all.
		weapons[] = {};
		requiredVersion = 1.0;
		requiredAddons[] = {"3DEN"}; // 3DEN must be among required addons!
	};
};

#include "includes.hpp"
#include "ui\Display3DEN.hpp"
#include "ui\Eden_keyBinds.gui"
#include "data\keybinds.data"

class CfgFunctions
{
	#include "functions\EdenKeybinds.fncs"
};