class Display3DEN
{
	idd=313;
	enableSimulation=1;
	enableDisplay=1;
	scriptName="Display3DEN";
	scriptPath="3DENDisplays";
	onLoad="[""onLoad"",_this,""Display3DEN"",'3DENDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	onUnload="[""onUnload"",_this,""Display3DEN"",'3DENDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	class ContextMenu: ctrlMenu
	{
		idc=1100;
		colorBackground[]={0.1,0.1,0.1,1};
		class Items
		{
			items[]=
			{
				"ConnectParent",
				"SeparatorSelected",
				"MoveCamera",
				"PlayFromHere",
				"PlayAsEntity",
				"Separator",
				"Select",
				"Edit",
				"Transform",
				"Grid",
				"Log",
				"ChangeSeatParent",
				"SeparatorEntity",
				"CustomComposition",
				"FindCreate",
				"FindConfig",
				"SeparatorSelected",
				"SeparatorNotSelected",
				"CreateComment",
				"Arsenal",
				"ArsenalReset",
				"Garage",
				"GarageReset",
				"SeparatorArsenal",
				"Attributes"
			};
			class Separator
			{
				value=0;
			};
			class SeparatorObject
			{
				value=0;
				conditionShow="hoverObject";
			};
			class SeparatorNotSelected
			{
				value=0;
				conditionShow="(1 - (selected))";
			};
			class SeparatorSelected
			{
				value=0;
				conditionShow="selected";
			};
			class SeparatorArsenal
			{
				value=0;
				conditionShow="(hoverObjectBrain 	* (1 - (hoverObjectVehicle))) 	+ (hoverObjectVehicle 	* IsInternal)";
			};
			class SeparatorEntity
			{
				value=0;
				conditionShow="hoverObject 	+ hoverGroup 	+ hoverTrigger 	+ hoverWaypoint 	+ hoverLogic 	+ hoverMarker";
			};
			class ConnectParent
			{
				items[]=
				{
					"Connect",
					"ConnectOther"
				};
				text="$STR_3DEN_Display3DEN_EntityMenu_ConnectParent_text";
				value=0;
			};
			class Connect
			{
				data="Connect";
			};
			class ConnectOther
			{
				data="ConnectOther";
			};
			class AttachTo
			{
				text="$STR_3DEN_Display3DEN_EntityMenu_AttachTo_text";
				data="AttachTo";
				value=0;
				conditionShow="hoverObject 	* (1 - (hoverObjectAttached))";
				enable=0;
			};
			class Detach
			{
				text="$STR_3DEN_Display3DEN_EntityMenu_Detach_text";
				data="Detach";
				value=0;
				conditionShow="hoverObject 	* hoverObjectAttached";
				enable=0;
			};
			class MoveCamera
			{
				text="$STR_3DEN_Display3DEN_EntityMenu_MoveCamera_text";
				value=0;
				action="['movecamera'] call bis_fnc_3DENEntityMenu;";
				picture="\a3\3DEN\Data\Displays\Display3DEN\EntityMenu\moveCamera_ca.paa";
			};
			class PlayFromHere
			{
				text="$STR_3DEN_Display3DEN_EntityMenu_PlayFromHere_text";
				data="PlayFromHere";
				value=0;
				conditionShow="(1 - (hoverObjectBrain)) 	* (1 - (isMultiplayer))";
				action="['PlayFromHere'] call bis_fnc_3DENEntityMenu;";
				picture="\a3\3DEN\Data\Displays\Display3DEN\EntityMenu\playFromHere_ca.paa";
			};
			class PlayAsEntity
			{
				text="$STR_3DEN_Display3DEN_EntityMenu_PlayAsEntity_text";
				data="PlayAsEntity";
				value=0;
				conditionShow="hoverObjectBrain 	* (1 - (isMultiplayer)) 	* (1 - (HoverObjectUav))";
				action="['PlayAsEntity'] call bis_fnc_3DENEntityMenu;";
				picture="\a3\3DEN\Data\Displays\Display3DEN\EntityMenu\playFromHere_ca.paa";
			};
			class Select
			{
				text="$STR_3DEN_Display3DEN_EntityMenu_Select_text";
				value=0;
				items[]=
				{
					"SelectView",
					"SelectLayerChildren",
					"SelectLayerAllDescendants",
					"SeparatorSelected",
					"SelectMatchingClassSelected",
					"SelectMatchingClassView",
					"SeparatorSelected",
					"SelectMatchingTypeSelected",
					"SelectMatchingTypeView"
				};
			};
			class SelectView
			{
				text="$STR_3DEN_Display3DEN_EntityMenu_SelectView_text";
				data="SelectAllOnScreen";
				value=0;
				conditionShow="(1 - (isEditList))";
				shortcuts[]=
				{
					"512 + 0x1E"
				};
			};
			class SelectLayerChildren
			{
				text="$STR_3DEN_Display3DEN_EntityMenu_SelectLayerChildren_text";
				data="SelectLayerChildren";
				value=0;
				conditionShow="hoverLayer";
			};
			class SelectLayerAllDescendants
			{
				text="$STR_3DEN_Display3DEN_EntityMenu_SelectLayerAllDescendants_text";
				data="SelectLayerAllDescendants";
				value=0;
				conditionShow="hoverLayer";
			};
			class SelectMatchingClassSelected
			{
				text="$STR_3DEN_Display3DEN_EntityMenu_SelectMatchingClassSelected_text";
				data="SelectMatchingClassSelected";
				value=0;
				conditionShow="selected";
			};
			class SelectMatchingClassView
			{
				text="$STR_3DEN_Display3DEN_EntityMenu_SelectMatchingClassView_text";
				data="SelectMatchingClassView";
				value=0;
				conditionShow="selected";
			};
			class SelectMatchingTypeSelected
			{
				text="$STR_3DEN_Display3DEN_EntityMenu_SelectMatchingTypeSelected_text";
				data="SelectMatchingTypeSelected";
				value=0;
				conditionShow="selected";
			};
			class SelectMatchingTypeView
			{
				text="$STR_3DEN_Display3DEN_EntityMenu_SelectMatchingTypeView_text";
				data="SelectMatchingTypeView";
				value=0;
				conditionShow="selected";
			};
			class Edit
			{
				text="$STR_3DEN_Display3DEN_MenUBar_Edit_text";
				value=0;
				items[]=
				{
					"Cut",
					"Copy",
					"Paste",
					"PasteOrig",
					"Delete"
				};
			};
			class Cut
			{
				text="$STR_3DEN_Display3DEN_MenuBar_EntityCut_text";
				data="CutUnit";
				value=0;
				conditionEnable="selected";
				shortcuts[]=
				{
					"512 + 0x2D"
				};
			};
			class Copy
			{
				text="$STR_3DEN_Display3DEN_MenuBar_EntityCopy_text";
				data="CopyUnit";
				value=0;
				conditionEnable="selected";
				shortcuts[]=
				{
					"512 + 0x2E"
				};
			};
			class Paste
			{
				text="$STR_3DEN_Display3DEN_MenuBar_EntityPaste_text";
				data="PasteItems";
				value=0;
				shortcuts[]=
				{
					"512 + 0x2F"
				};
			};
			class PasteOrig
			{
				text="$STR_3DEN_Display3DEN_MenuBar_EntityPasteOrig_text";
				data="PasteUnitOrig";
				value=0;
				shortcuts[]=
				{
					"512 + 	1024 + 0x2F"
				};
			};
			class Delete
			{
				text="$STR_3DEN_Delete";
				data="DeleteItems";
				value=0;
				conditionEnable="selected";
				shortcuts[]={211};
			};
			class CopyAttributes
			{
				text="$STR_3DEN_Display3DEN_EntityMenu_CopyAttributes_text";
				data="CopyAttributes";
				value=0;
				conditionEnable="selected";
				enable=0;
			};
			class PasteAttributes
			{
				text="$STR_3DEN_Display3DEN_EntityMenu_PasteAttributes_text";
				data="PasteAttributes";
				value=0;
				conditionEnable="selected";
				enable=0;
			};
			class Transform
			{
				text="$STR_3DEN_Display3DEN_EntityMenu_Transform_text";
				value=0;
				conditionShow="hoverObject 	+ hoverGroup";
				items[]=
				{
					"SelectLeader",
					"MoveToFormation",
					"MoveFlying",
					"MoveSurface",
					"SetATL",
					"SetASL"
				};
			};
			class SelectLeader
			{
				text="$STR_3DEN_Display3DEN_EntityMenu_SelectLeader_text";
				data="SelectLeader";
				value=0;
				conditionShow="hoverObjectBrain";
				picture="\a3\3DEN\Data\Displays\Display3DEN\EntityMenu\selectLeader_ca.paa";
			};
			class MoveToFormation
			{
				text="$STR_3DEN_Display3DEN_EntityMenu_MoveToFormation_text";
				data="ForceToFormation";
				value=0;
				conditionShow="hoverObjectBrain 	+ hoverGroup";
				picture="\a3\3DEN\Data\Displays\Display3DEN\EntityMenu\moveToFormation_ca.paa";
			};
			class MoveFlying
			{
				text="$STR_3DEN_Display3DEN_EntityMenu_MoveFlying_text";
				data="SetFlyingHeight";
				value=0;
				conditionShow="hoverObjectCanFly 	* (1 - (hoverObjectFlying))";
				picture="\a3\3DEN\Data\Displays\Display3DEN\EntityMenu\moveFlying_ca.paa";
			};
			class MoveSurface
			{
				text="$STR_3DEN_Display3DEN_EntityMenu_MoveSurface_text";
				data="SnapToSurface";
				value=0;
				conditionShow="hoverObject 	+ hoverTrigger 	+ hoverWaypoint 	+ hoverLogic";
				picture="\a3\3DEN\Data\Displays\Display3DEN\EntityMenu\moveSurface_ca.paa";
			};
			class SetATL
			{
				text="$STR_3DEN_Display3DEN_EntityMenu_SetATL_text";
				data="LevelWithSurface";
				value=0;
				conditionShow="hoverObject";
				picture="\a3\3DEN\Data\Displays\Display3DEN\EntityMenu\setATL_ca.paa";
			};
			class SetASL
			{
				text="$STR_3DEN_Display3DEN_EntityMenu_SetASL_text";
				data="LevelOutObjects";
				value=0;
				conditionShow="hoverObject";
				picture="\a3\3DEN\Data\Displays\Display3DEN\EntityMenu\setASL_ca.paa";
			};
			class Grid
			{
				text="$STR_3DEN_Display3DEN_MenuBar_Grid_text";
				value=0;
				conditionShow="hoverObject";
				items[]=
				{
					"GridTranslationX",
					"GridTranslationY",
					"GridTranslationZ"
				};
			};
			class GridCenter
			{
				text="$STR_3DEN_Display3DEN_EntityMenu_GridCenter_text";
				data="GridCenter";
				value=0;
				enable=0;
			};
			class GridTranslationX
			{
				text="$STR_3DEN_Display3DEN_EntityMenu_GridTranslationX_text";
				data="GridTranslationX";
				value=0;
				conditionShow="hoverObject";
				action="['Grid','translation',0] spawn bis_fnc_3DENEntityMenu;";
				picture="\a3\3DEN\Data\Displays\Display3DEN\EntityMenu\gridTranslationX_ca.paa";
			};
			class GridTranslationY
			{
				text="$STR_3DEN_Display3DEN_EntityMenu_GridTranslationY_text";
				data="GridTranslationY";
				value=0;
				conditionShow="hoverObject";
				action="['Grid','translation',1] spawn bis_fnc_3DENEntityMenu;";
				picture="\a3\3DEN\Data\Displays\Display3DEN\EntityMenu\gridTranslationY_ca.paa";
			};
			class GridTranslationZ
			{
				text="$STR_3DEN_Display3DEN_EntityMenu_GridTranslationZ_text";
				data="GridTranslationZ";
				value=0;
				conditionShow="hoverObject";
				action="['Grid','translation',2] spawn bis_fnc_3DENEntityMenu;";
				picture="\a3\3DEN\Data\Displays\Display3DEN\EntityMenu\gridTranslationZ_ca.paa";
			};
			class ChangeSeatParent
			{
				items[]=
				{
					"ChangeSeat"
				};
				text="$STR_3DEN_Display3DEN_EntityMenu_ChangeSeat_text";
				value=0;
			};
			class ChangeSeat
			{
				data="ChangeSeat";
			};
			class Log
			{
				text="$STR_3DEN_Display3DEN_EntityMenu_Log_text";
				value=0;
				items[]=
				{
					"LogPosition",
					"LogClasses"
				};
			};
			class LogPosition
			{
				text="$STR_3DEN_Display3DEN_EntityMenu_LogPosition_text";
				data="LogPosition";
				value=0;
				action="['logPosition'] call bis_fnc_3DENEntityMenu;";
			};
			class LogClasses
			{
				text="$STR_3DEN_Display3DEN_EntityMenu_LogClasses_text";
				data="LogClasses";
				value=0;
				conditionShow="selectedObject 	+ selectedWaypoint 	+ selectedLogic 	+ selectedMarker";
				action="['logClasses'] call bis_fnc_3DENEntityMenu;";
			};
			class CustomComposition
			{
				text="$STR_3den_display3den_entitymenu_customcomposition_text";
				data="CustomComposition";
				value=0;
				action="do3denaction 'createcustomcomposition';";
				conditionShow="hoverObject 	+ hoverGroup 	+ 	+ hoverTrigger 	+ hoverWaypoint 	+ hoverLogic 	+ hoverMarker 	+ hoverLayer";
				picture="\a3\3DEN\Data\Displays\Display3DEN\PanelRight\customcomposition_add_ca.paa";
				opensNewWindow=1;
			};
			class FindCreate
			{
				text="$STR_3DEN_Display3DEN_EntityMenu_FindCreate_text";
				data="FindCreate";
				value=0;
				conditionShow="hoverObject 	+ hoverWaypoint 	+ hoverLogic 	+ hoverMarker";
				action="['findcreate'] spawn bis_fnc_3DENEntityMenu;";
				picture="\a3\3DEN\Data\Displays\Display3DEN\EntityMenu\findCreate_ca.paa";
				opensNewWindow=1;
			};
			class FindConfig
			{
				text="$STR_3DEN_Display3DEN_EntityMenu_FindConfig_text";
				data="FindConfig";
				value=0;
				conditionShow="hoverObject 	+ hoverWaypoint 	+ hoverLogic 	+ hoverMarker";
				action="['findconfig'] call bis_fnc_3DENEntityMenu;";
				picture="\a3\3DEN\Data\Displays\Display3DEN\EntityMenu\findConfig_ca.paa";
				opensNewWindow=1;
			};
			class CreateComment
			{
				text="$STR_3den_display3den_entitymenu_createcomment_text";
				data="CreateAndChangeComment";
				value=0;
				conditionShow="(1 - (selected))";
				picture="\a3\3DEN\Data\Cfg3DEN\Comment\texture_ca.paa";
			};
			class Arsenal
			{
				text="$STR_3den_display3den_entitymenu_arsenal_text";
				data="Arsenal";
				value=0;
				action="['arsenal'] call bis_fnc_3DENEntityMenu;";
				conditionShow="hoverObjectBrain 	* (1 - (hoverObjectVehicle))";
				picture="\a3\3DEN\Data\Displays\Display3DEN\EntityMenu\arsenal_ca.paa";
				opensNewWindow=1;
			};
			class ArsenalReset
			{
				text="$STR_3den_display3den_entitymenu_arsenalreset_text";
				data="ArsenalReset";
				value=0;
				action="['arsenalReset'] call bis_fnc_3DENEntityMenu;";
				conditionShow="hoverObjectBrain 	* (1 - (hoverObjectVehicle))";
			};
			class Garage
			{
				text="$STR_3den_display3den_entitymenu_garage_text";
				data="Garage";
				value=0;
				action="['garage'] call bis_fnc_3DENEntityMenu;";
				conditionShow="hoverObjectVehicle";
				picture="\a3\3DEN\Data\Displays\Display3DEN\EntityMenu\garage_ca.paa";
				opensNewWindow=1;
			};
			class GarageReset
			{
				text="$STR_3den_display3den_entitymenu_garagereset_text";
				data="GarageReset";
				value=0;
				action="['garageReset'] call bis_fnc_3DENEntityMenu;";
				conditionShow="hoverObjectVehicle";
			};
			class Attributes
			{
				text="$STR_3DEN_Display3DEN_MenuBar_Attributes_text";
				data="OpenAttributes";
				value=0;
				conditionShow="selected";
				opensNewWindow=1;
			};
			class Default
			{
				text="$STR_3DEN_Display3DEN_MenuBar_Default_text";
				data="Empty";
				enable=0;
			};
		};
	};
	class ControlsBackground
	{
		class Map: ctrlMap
		{
			idc=51;
			x="safezoneXAbs";
			y="safezoneY";
			w="safezoneWAbs";
			h="safezoneH";
			class CustomMark
			{
				icon="#(argb,8,8,3)color(0,0,0,0)";
				color[]={0,0,0,0};
				size=0;
				importance=0;
				coefMin=0;
				coefMax=0;
			};
		};
		class MouseArea: ctrlStatic
		{
			idc=52;
			style=16;
			x="safezoneXAbs";
			y="safezoneY";
			w="safezoneWAbs";
			h="safezoneH";
		};
		class ScrollBlockTop: ctrlStatic
		{
			idc=46;
			x="safezoneX";
			y="safezoneY";
			w="safezoneW";
			h="(		5 + 	(	5 + 2)) * (pixelH * pixelGrid * 	0.50)";
		};
		class ScrollBlockLeft: ScrollBlockTop
		{
			idc=47;
			x="safezoneX";
			y="safezoneY + (		5 + 	(	5 + 2)) * (pixelH * pixelGrid * 	0.50)";
			w="60 * (pixelW * pixelGrid * 	0.50)";
			h="safezoneH - (		5 + 	(	5 + 2) + 		4) * (pixelH * pixelGrid * 	0.50)";
		};
		class ScrollBlockRight: ScrollBlockTop
		{
			idc=48;
			x="safezoneX + safezoneW - 	60 * (pixelW * pixelGrid * 	0.50)";
			y="safezoneY + (	5 + 	(	5 + 2)) * (pixelH * pixelGrid * 	0.50)";
			w="60 * (pixelW * pixelGrid * 	0.50)";
			h="safezoneH - (		5 + 	(	5 + 2)) * (pixelH * pixelGrid * 	0.50)";
		};
		class ScrollBlockBottom: ScrollBlockTop
		{
			idc=49;
			x="safezoneX";
			y="safezoneY + safezoneH - 		4 * (pixelH * pixelGrid * 	0.50)";
			w="(safezoneW - 	60 * (pixelW * pixelGrid * 	0.50))";
			h="(		4 + 1) * (pixelH * pixelGrid * 	0.50)";
		};
		class NavigationWidget: ctrlStatic
		{
			idc=87;
			x="safezoneX + (	60 + 		15 * 0.2) * (pixelW * pixelGrid * 	0.50)";
			y="safezoneY + safezoneH - (		4 + 		15 * 1.2) * (pixelH * pixelGrid * 	0.50)";
			w="15 * (pixelW * pixelGrid * 	0.50)";
			h="15 * (pixelH * pixelGrid * 	0.50)";
			widgetLineWidth=10;
			sizeEx="20 * pixelW";
		};
		class Black: ctrlStatic
		{
			idc=998;
			x="safezoneXAbs";
			y="safezoneY";
			w="safezoneWAbs";
			h="safezoneH";
			colorBackground[]={0,0,0,1};
		};
	};
	class Controls
	{
		class ButtonExit: ctrlButtonPicture
		{
			idc=2;
			x="safezoneX + safezoneW - (	5 * (pixelW * pixelGrid * 	0.50))";
			y="safezoneY";
			w="5 * (pixelW * pixelGrid * 	0.50)";
			h="5 * (pixelH * pixelGrid * 	0.50)";
			colorBackground[]={0.1,0.1,0.1,1};
			text="\a3\3DEN\Data\Displays\Display3DEN\search_end_ca.paa";
			onButtonClick="do3DENAction '3DENExit';";
			offsetPressedX=0;
			offsetPressedY=0;
		};
		class MissionName: ctrlStatic
		{
			idc=76;
			style=1;
			x="safezoneX";
			y="safezoneY";
			w="safezoneW - (	5 * (pixelW * pixelGrid * 	0.50))";
			h="5 * (pixelH * pixelGrid * 	0.50)";
			colorBackground[]={0.1,0.1,0.1,1};
			onLoad="(_this select 0) ctrlenable false;";
		};
		class MenuStrip: ctrlMenuStrip
		{
			idc=120;
			x="safezoneX";
			y="safezoneY";
			w="safezoneW - 	5 * (pixelW * pixelGrid * 	0.50)";
			h="5 * (pixelH * pixelGrid * 	0.50)";
			colorStripBackground[]={0,0,0,0};
			colorBackground[]={0.1,0.1,0.1,1};
			class Items
			{
				items[]=
				{
					"File",
					"Edit",
					"View",
					"Attributes",
					"Tools",
					"Options",
					"Preview",
					"Help"
				};
				class File
				{
					text="$STR_3DEN_Scenario";
					items[]=
					{
						"MissionNew",
						"MissionOpen",
						"MissionSave",
						"MissionSaveAs",
						"Separator",
						"MissionPublishSteam",
						"MissionExport",
						"MissionMerge",
						"Separator",
						"MissionAddons",
						"MissionFolder",
						"LogFolder",
						"Separator",
						"Exit"
					};
					data="test1";
					value=1;
				};
				class MissionNew
				{
					text="$STR_3DEN_Display3DEN_MenuBar_MissionNew_text";
					data="MissionNew";
					shortcuts[]=
					{
						"512 + 0x31"
					};
					picture="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\new_ca.paa";
					opensNewWindow=1;
				};
				class MissionOpen
				{
					text="$STR_3DEN_Display3DEN_MenuBar_MissionOpen_text";
					data="MissionLoad";
					shortcuts[]=
					{
						"512 + 0x18"
					};
					picture="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\open_ca.paa";
					opensNewWindow=1;
				};
				class MissionSave
				{
					text="$STR_3DEN_Display3DEN_MenuBar_MissionSave_text";
					data="MissionSave";
					shortcuts[]=
					{
						"512 + 0x1F"
					};
					picture="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\save_ca.paa";
				};
				class MissionSaveAs
				{
					text="$STR_3DEN_Display3DEN_MenuBar_MissionSaveAs_text";
					data="MissionSaveAs";
					shortcuts[]=
					{
						"512 + 	1024 + 0x1F"
					};
					picture="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\saveas_ca.paa";
					opensNewWindow=1;
				};
				class MissionPublishSteam
				{
					text="$STR_3DEN_Display3DEN_MenuBar_MissionPublishSteam_text";
					data="MissionPublishSteam";
					enable=1;
					action="do3DENAction 'OpenSteamPublishDialog';";
					picture="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\steam_ca.paa";
				};
				class MissionExport
				{
					text="$STR_3DEN_Display3DEN_MenuBar_MissionExport_text";
					items[]=
					{
						"MissionExportSP",
						"MissionExportMP",
						"MissionTerrainBuilder"
					};
				};
				class MissionExportSP
				{
					text="$STR_3DEN_Display3DEN_MenuBar_MissionExportSP_text";
					data="MissionExportSP";
				};
				class MissionExportMP
				{
					text="$STR_3DEN_Display3DEN_MenuBar_MissionExportMP_text";
					data="MissionExportMP";
				};
				class MissionTerrainBuilder
				{
					text="$STR_3DEN_Display3DEN_MenuBar_MissionTerrainBuilder_text";
					data="MissionExportTerrainBuilder";
					action="[] spawn bis_fnc_3DENExportTerrainBuilder;";
				};
				class MissionMerge
				{
					text="$STR_3DEN_Display3DEN_MenuBar_MissionMerge_text";
					data="MissionMerge";
					shortcuts[]=
					{
						"512 + 0x32"
					};
				};
				class MissionFolder
				{
					text="$STR_3DEN_Display3DEN_MenuBar_MissionFolder_text";
					data="FolderMission";
				};
				class MissionAddons
				{
					text="$STR_3DEN_Display3DEN_MenuBar_MissingAddons_text";
					data="OpenRequiredAddons";
				};
				class LogFolder
				{
					text="$STR_3DEN_Display3DEN_MenuBar_LogFolder_text";
					data="FolderLog";
				};
				class Exit
				{
					text="$STR_3DEN_Display3DEN_MenuBar_Exit_text";
					data="Exit3DEN";
				};
				class Edit
				{
					text="$STR_3DEN_Display3DEN_MenuBar_Edit_text";
					items[]=
					{
						"Undo",
						"Redo",
						"Separator",
						"EntitySelectScreen",
						"Separator",
						"Widget",
						"Grid",
						"Vertical",
						"SurfaceSnapToggle",
						"WaypointSnapToggle",
						"Separator",
						"Space",
						"Mode"
					};
				};
				class Undo
				{
					text="$STR_3DEN_Display3DEN_MenuBar_Undo_text";
					data="Undo";
					shortcuts[]=
					{
						"512 + 0x2C"
					};
					picture="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\undo_ca.paa";
				};
				class Redo
				{
					text="$STR_3DEN_Display3DEN_MenuBar_Redo_text";
					data="Redo";
					shortcuts[]=
					{
						"512 + 0x15",
						"512 + 	1024 + 0x2C"
					};
					picture="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\redo_ca.paa";
				};
				class EntitySelectScreen
				{
					text="$STR_3DEN_Display3DEN_MenuBar_EntitySelectScreen_text";
					data="SelectAllOnScreen";
					shortcuts[]=
					{
						"512 + 0x1E"
					};
				};
				class EntityCut
				{
					text="$STR_3DEN_Display3DEN_MenuBar_EntityCut_text";
					data="CutUnit";
					shortcuts[]=
					{
						"512 + 0x2D"
					};
				};
				class EntityCopy
				{
					text="$STR_3DEN_Display3DEN_MenuBar_EntityCopy_text";
					data="CopyUnit";
					shortcuts[]=
					{
						"512 + 0x2E"
					};
				};
				class EntityPaste
				{
					text="$STR_3DEN_Display3DEN_MenuBar_EntityPaste_text";
					data="PasteUnit";
					shortcuts[]=
					{
						"512 + 0x2F"
					};
				};
				class EntityPasteOrig
				{
					text="$STR_3DEN_Display3DEN_MenuBar_EntityPasteOrig_text";
					data="PasteUnitOrig";
					shortcuts[]=
					{
						"512 + 	1024 + 0x2F"
					};
				};
				class EntitySimulation
				{
					xtext="$STR_3DEN_Display3DEN_MenuBar_EntitySimulation_text";
					data="SimulateUnit";
					shortcuts[]=
					{
						"512 + 0x19"
					};
					enable=0;
				};
				class Widget
				{
					text="$STR_3DEN_Display3DEN_MenuBar_Widget_text";
					items[]=
					{
						"WidgetToggle",
						"WidgetNone",
						"WidgetTranslation",
						"WidgetRotation",
						"WidgetScaling",
						"WidgetArea"
					};
				};
				class WidgetToggle
				{
					text="$STR_3DEN_Display3DEN_MenuBar_WidgetToggle_text";
					data="WidgetToggle";
					shortcuts[]={57};
				};
				class WidgetNone
				{
					text="$STR_3DEN_Display3DEN_MenuBar_WidgetNone_text";
					data="WidgetNone";
					picture="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_none_off_ca.paa";
					shortcuts[]={2};
				};
				class WidgetTranslation
				{
					text="$STR_3DEN_Display3DEN_MenuBar_WidgetTranslation_text";
					data="WidgetTranslation";
					picture="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_translation_off_ca.paa";
					shortcuts[]={3};
				};
				class WidgetRotation
				{
					text="$STR_3DEN_Display3DEN_MenuBar_WidgetRotation_text";
					data="WidgetRotation";
					picture="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_rotation_off_ca.paa";
					shortcuts[]={4};
				};
				class WidgetScaling
				{
					text="$STR_3DEN_Display3DEN_MenuBar_WidgetScaling_text";
					data="WidgetScale";
					picture="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_scaling_off_ca.paa";
					shortcuts[]={5};
				};
				class WidgetArea
				{
					text="$STR_3DEN_Display3DEN_MenuBar_WidgetArea_text";
					data="WidgetArea";
					picture="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_area_off_ca.paa";
					shortcuts[]={6};
				};
				class WidgetSpace
				{
					text="$STR_3DEN_Display3DEN_MenuBar_WidgetSpace_text";
					data="WidgetSpace";
					shortcuts[]={34};
					enable=0;
				};
				class WidgetSpaceWorld
				{
					text="$STR_3DEN_Display3DEN_MenuBar_WidgetSpaceWorld_text";
					data="WidgetSpaceWorld";
					enable=0;
				};
				class WidgetSpaceLocal
				{
					text="$STR_3DEN_Display3DEN_MenuBar_WidgetSelectedEntity_text";
					data="WidgetSpaceLocal";
					enable=0;
				};
				class WidgetPosition
				{
					xtext="$STR_3DEN_Display3DEN_MenuBar_WidgetPosition_text";
					data="WidgetPosition";
					shortcuts[]={34};
					enable=0;
				};
				class WidgetPositionEntity
				{
					xtext="$STR_3DEN_Display3DEN_MenuBar_WidgetSelectedEntity_text";
					data="WidgetPositionEntity";
					enable=0;
				};
				class WidgetPositionMean
				{
					xtext="$STR_3DEN_Display3DEN_MenuBar_WidgetPositionMean_text";
					data="WidgetPositionMean";
					enable=0;
				};
				class Grid
				{
					text="$STR_3DEN_Display3DEN_MenuBar_Grid_text";
					items[]=
					{
						"GridTranslationToggle",
						"GridRotationToggle",
						"GridScalingToggle",
						"GridDecrease",
						"GridIncrease"
					};
				};
				class GridTranslationToggle
				{
					text="$STR_3DEN_Display3DEN_MenuBar_GridTranslationToggle_text";
					data="MoveGridToggle";
					shortcuts[]={39};
					type="CheckBox";
					default="false";
				};
				class GridRotationToggle
				{
					text="$STR_3DEN_Display3DEN_MenuBar_GridRotationToggle_text";
					data="RotateGridToggle";
					type="CheckBox";
					default="false";
				};
				class GridScalingToggle
				{
					text="$STR_3DEN_Display3DEN_MenuBar_GridScalingToggle_text";
					data="ScaleGridToggle";
					type="CheckBox";
					default="false";
				};
				class GridDecrease
				{
					text="$STR_3DEN_Display3DEN_MenuBar_GridDecrease_text";
					data="GridDecrease";
					shortcuts[]={26};
					action="['decrease'] call bis_fnc_3DENGrid;";
				};
				class GridIncrease
				{
					text="$STR_3DEN_Display3DEN_MenuBar_GridIncrease_text";
					data="GridIncrease";
					shortcuts[]={27};
					action="['increase'] call bis_fnc_3DENGrid;";
				};
				class Vertical
				{
					text="$STR_3DEN_Display3DEN_MenuBar_Vertical_text";
					items[]=
					{
						"VerticalToggle",
						"VerticalATL",
						"VerticalASL"
					};
				};
				class VerticalToggle
				{
					text="$STR_3DEN_Display3DEN_MenuBar_VerticalToggle_text";
					data="VerticalToggle";
					shortcuts[]={40};
				};
				class VerticalATL
				{
					text="$STR_3DEN_Display3DEN_MenuBar_VerticalATL_text";
					data="VerticalATL";
				};
				class VerticalASL
				{
					text="$STR_3DEN_Display3DEN_MenuBar_VerticalASL_text";
					data="VerticalASL";
				};
				class SurfaceSnapToggle
				{
					text="$STR_3DEN_Display3DEN_MenuBar_SurfaceSnapToggle_text";
					data="SurfaceSnapToggle";
					type="CheckBox";
					default="true";
					shortcuts[]={43};
				};
				class WaypointSnapToggle
				{
					text="$STR_3DEN_Display3DEN_MenuBar_WaypointSnapToggle_text";
					data="WaypointSnapToggle";
					type="CheckBox";
					default="true";
					shortcuts[]={53};
				};
				class Space
				{
					text="$STR_3DEN_Display3DEN_MenuBar_Space_text";
					items[]=
					{
						"SpaceMission",
						"SpaceIntro",
						"SpaceOutroWin",
						"SpaceOutroLose"
					};
				};
				class SpaceMission
				{
					text="$STR_3DEN_Scenario";
					data="MissionPartMission";
				};
				class SpaceIntro
				{
					text="$STR_3DEN_Display3DEN_MenuBar_SpaceIntro_text";
					data="MissionPartIntro";
				};
				class SpaceOutroWin
				{
					text="$STR_3DEN_Display3DEN_MenuBar_SpaceOutroWin_text";
					data="MissionPartOutroWin";
				};
				class SpaceOutroLose
				{
					text="$STR_3DEN_Display3DEN_MenuBar_SpaceOutroLose_text";
					data="MissionPartOutroLoose";
				};
				class Mode
				{
					text="$STR_3DEN_Display3DEN_MenuBar_Mode_text";
					items[]=
					{
						"ModeObject",
						"ModeGroup",
						"ModeTrigger",
						"ModeWaypoint",
						"ModeLogic",
						"ModeMarker",
						"ModeFavorite",
						"SubmodeToggle"
					};
				};
				class ModeObject
				{
					text="$STR_3DEN_Object_textPlural";
					data="SelectObjectMode";
					shortcuts[]={59};
				};
				class ModeGroup
				{
					text="$STR_3DEN_Group_textPlural";
					data="SelectGroupMode";
					shortcuts[]={60};
				};
				class ModeTrigger
				{
					text="$STR_3DEN_Trigger_textPlural";
					data="SelectTriggerMode";
					shortcuts[]={61};
				};
				class ModeWaypoint
				{
					text="$STR_3DEN_Waypoint_textPlural";
					data="SelectWaypointMode";
					shortcuts[]={62};
				};
				class ModeLogic
				{
					text="$STR_3DEN_Logic_textPlural";
					data="SelectModuleMode";
					shortcuts[]={63};
				};
				class ModeMarker
				{
					text="$STR_3DEN_Marker_textPlural";
					data="SelectMarkerMode";
					shortcuts[]={64};
				};
				class ModeFavorite
				{
					text="$STR_3DEN_Favorite_textPlural";
					data="SelectFavoritesMode";
					shortcuts[]={65};
					enable=0;
				};
				class SubmodeToggle
				{
					text="$STR_3DEN_Display3DEN_MenuBar_SubmodeToggle_text";
					data="SubmodeToggle";
					shortcuts[]={15};
				};
				class View
				{
					text="$STR_3DEN_Display3DEN_MenuBar_View_text";
					items[]=
					{
						"ViewRandom",
						"ViewSelected",
						"ViewPlayer",
						"Separator",
						"Map",
						"MapTextures",
						"Separator",
						"VisionMode",
						"ToggleFlashlight",
						"ToggleLocations",
						"ToggleVegetation",
						"Separator",
						"Search",
						"Interface"
					};
				};
				class ViewRandom
				{
					text="$STR_3DEN_Display3DEN_MenuBar_ViewRandom_text";
					data="CenterCameraOnRandom";
					shortcuts[]=
					{
						"512 + 0x13"
					};
					action="'random' call bis_fnc_3DENCamera;";
				};
				class ViewSelected
				{
					text="$STR_3DEN_Display3DEN_MenuBar_ViewSelected_text";
					data="CenterCameraOnSelected";
					action="'selected' call bis_fnc_3DENCamera;";
					shortcuts[]={33};
				};
				class ViewPlayer
				{
					text="$STR_3DEN_Display3DEN_MenuBar_ViewPlayer_text";
					data="CenterCameraOnPlayer";
					shortcuts[]={199};
				};
				class Map
				{
					text="$STR_3DEN_Display3DEN_MenuBar_Map_text";
					data="ToggleMap";
					type="CheckBox";
					default="false";
					shortcuts[]={50};
				};
				class MapTextures
				{
					text="$STR_3DEN_Display3DEN_MenuBar_MapTextures_text";
					data="ToggleMapTextures";
					shortcuts[]=
					{
						"512 + 0x14"
					};
					type="CheckBox";
					default="false";
				};
				class MapIDs
				{
					text="$STR_3DEN_Display3DEN_MenuBar_MapIDs_text";
					data="MapIDs";
					enable=0;
				};
				class ToggleLocations
				{
					text="$STR_3DEN_Display3DEN_MenuBar_ToggleLocations_text";
					data="ToggleLocations";
					action="[] call bis_fnc_3DENDrawLocations;";
				};
				class ToggleFlashlight
				{
					text="$STR_3DEN_Display3DEN_MenuBar_ToggleFlashlight_text";
					data="ToggleFlashlight";
					action="[] call bis_fnc_3DENFlashlight;";
					shortcuts[]={38};
					picture="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\flashlight_off_ca.paa";
				};
				class ToggleVegetation
				{
					text="$STR_3DEN_Display3DEN_MenuBar_ToggleVegetation_text";
					data="ToggleVegetation";
					type="CheckBox";
					default="false";
					shortcuts[]=
					{
						"512 + 0x22"
					};
				};
				class VisionMode
				{
					text="$STR_3DEN_Display3DEN_MenuBar_VisionMode_text";
					data="ViewVisionMode";
					items[]=
					{
						"VisionModeToggle",
						"VisionModeNormal",
						"VisionModeNVG",
						"VisionModeTI"
					};
				};
				class VisionModeToggle
				{
					text="$STR_3DEN_Display3DEN_MenuBar_VisionModeToggle_text";
					data="VisionModeToggle";
					shortcuts[]={49};
					action="-1 call BIS_fnc_3DENVisionMode;";
					picture="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\vision_normal_ca.paa";
				};
				class VisionModeNormal
				{
					text="$STR_3DEN_Display3DEN_MenuBar_VisionModeNormal_text";
					data="VisionModeNormal";
					action="0 call BIS_fnc_3DENVisionMode;";
				};
				class VisionModeNVG
				{
					text="$STR_3DEN_Display3DEN_MenuBar_VisionModeNVG_text";
					data="VisionModeNVG";
					action="1 call BIS_fnc_3DENVisionMode;";
				};
				class VisionModeTI
				{
					text="$STR_3DEN_Display3DEN_MenuBar_VisionModeTI_text";
					data="VisionModeTI";
					action="2 call BIS_fnc_3DENVisionMode;";
				};
				class Search
				{
					text="$STR_3DEN_Display3DEN_MenuBar_Search_text";
					data="Search";
					items[]=
					{
						"SearchCreate",
						"SearchEdit"
					};
				};
				class SearchCreate
				{
					text="$STR_3DEN_Display3DEN_MenuBar_SearchCreate_text";
					data="SearchCreate";
					shortcuts[]=
					{
						"512 + 0x21"
					};
				};
				class SearchEdit
				{
					text="$STR_3DEN_Display3DEN_MenuBar_SearchEdit_text";
					data="SearchEdit";
					shortcuts[]=
					{
						"512 + 	1024 + 0x21"
					};
				};
				class Interface
				{
					text="$STR_3DEN_Display3DEN_MenuBar_Interface_text";
					data="Interface";
					items[]=
					{
						"InterfaceToggle",
						"InterfacePanelLeft",
						"InterfacePanelRight",
						"InterfaceControlsHint",
						"InterfaceNavigationWidget"
					};
				};
				class InterfaceToggle
				{
					text="$STR_3DEN_Display3DEN_MenuBar_InterfaceToggle_text";
					data="InterfaceToggle";
					shortcuts[]={14};
					action="with uinamespace do {'showInterface' call BIS_fnc_3DENInterface;};";
				};
				class InterfacePanelLeft
				{
					text="$STR_3DEN_Display3DEN_MenuBar_InterfacePanelLeft_text";
					data="InterfacePanelLeft";
					shortcuts[]={18};
					action="with uinamespace do {'showPanelLeft' call BIS_fnc_3DENInterface;};";
				};
				class InterfacePanelRight
				{
					text="$STR_3DEN_Display3DEN_MenuBar_InterfacePanelRight_text";
					data="InterfacePanelRight";
					shortcuts[]={19};
					action="with uinamespace do {'showPanelRight' call BIS_fnc_3DENInterface;};";
				};
				class InterfaceControlsHint
				{
					text="$STR_3DEN_Display3DEN_MenuBar_InterfaceControlsHint_text";
					data="InterfaceControlsHint";
					action="'toggle' call BIS_fnc_3DENControlsHint;";
				};
				class InterfaceNavigationWidget
				{
					text="$STR_3DEN_Display3DEN_MenuBar_InterfaceNavigationWidget_text";
					data="InterfaceNavigationWidget";
					action="with uinamespace do {'navigationWidget' call BIS_fnc_3DENInterface;};";
				};
				class Attributes
				{
					text="$STR_3DEN_Display3DEN_MenuBar_Attributes_text";
					items[]=
					{
						"AttributesScenario",
						"AttributesEnvironment",
						"AttributesMultiplayer",
						"AttributesGarbageCollection",
						"Separator"
					};
				};
				class AttributesScenario
				{
					text="$STR_3DEN_Scenario_textSingular";
					data="AttributesScenario";
					action="edit3DENMissionAttributes 'Scenario';";
					opensNewWindow=1;
				};
				class AttributesMultiplayer
				{
					text="$STR_3DEN_Multiplayer_textSingular";
					data="AttributesMultiplayer";
					action="edit3DENMissionAttributes 'Multiplayer';";
					opensNewWindow=1;
				};
				class AttributesEnvironment
				{
					text="$STR_3DEN_Environment_textSingular";
					data="AttributesEnvironment";
					shortcuts[]=
					{
						"512 + 0x17"
					};
					action="edit3DENMissionAttributes 'Intel';";
					picture="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\intel_ca.paa";
					opensNewWindow=1;
				};
				class AttributesGarbageCollection
				{
					text="$STR_3DEN_Performance_textSingular";
					data="AttributesGarbageCollection";
					action="edit3DENMissionAttributes 'GarbageCollection';";
					opensNewWindow=1;
				};
				class Tools
				{
					text="$STR_3DEN_Display3DEN_MenuBar_Tools_text";
					items[]=
					{
						"DebugConsole",
						"FunctionsViewer",
						"ConfigViewer",
						"FieldManual",
						"Separator"
					};
				};
				class DebugConsole
				{
					text="$STR_3DEN_Display3DEN_MenuBar_DebugConsole_text";
					data="DebugConsole";
					shortcuts[]={41};
					action="(ctrlparent (_this select 0)) createdisplay 'RscDisplayDebugPublic';";
					enable=1;
					opensNewWindow=1;
				};
				class FunctionsViewer
				{
					text="$STR_3DEN_Display3DEN_MenuBar_FunctionsViewer_text";
					data="FunctionsViewer";
					action="[ctrlparent (_this select 0)] call (uinamespace getvariable 'bis_fnc_help');";
					picture="\a3\3DEN\Data\Displays\Display3DEN\EntityMenu\functions_ca.paa";
					opensNewWindow=1;
				};
				class ConfigViewer
				{
					text="$STR_3DEN_Display3DEN_MenuBar_ConfigViewer_text";
					data="ConfigViewer";
					action="[ctrlparent (_this select 0)] call (uinamespace getvariable 'bis_fnc_configviewer');";
					picture="\a3\3DEN\Data\Displays\Display3DEN\EntityMenu\findConfig_ca.paa";
					opensNewWindow=1;
				};
				class AnimationViewer
				{
					xtext="$STR_3DEN_Display3DEN_MenuBar_AnimationViewer_text";
					data="AnimationViewer";
					action="[ctrlparent (_this select 0)] call (uinamespace getvariable 'bis_fnc_animviewer');";
					opensNewWindow=1;
				};
				class FieldManual
				{
					text="$STR_A3_RscDisplayFieldManual_Title";
					data="FieldManual";
					action="(ctrlparent (_this select 0)) createdisplay 'RscDisplayFieldManual';";
					opensNewWindow=1;
				};
				class CommunityTools
				{
					text="$STR_3DEN_Display3DEN_MenuBar_CommunityTools_text";
					data="CommunityTools";
					enable=1;
					items[]={};
				};
				class Preview
				{
					text="$STR_3DEN_Display3DEN_MenuBar_Preview_text";
					items[]=
					{
						"MissionPreviewSP",
						"MissionPreviewSPBriefing",
						"MissionPreviewCamera",
						"MissionPreviewSpectator",
						"Separator",
						"MissionPreviewMP"
					};
				};
				class MissionPreviewSP
				{
					text="$STR_3DEN_Display3DEN_MenuBar_MissionPreviewSP_text";
					data="MissionPreview";
					shortcuts[]={28,156};
				};
				class MissionPreviewSPBriefing
				{
					text="$STR_3DEN_Display3DEN_MenuBar_MissionPreviewSPBriefing_text";
					data="MissionPreviewBriefing";
					shortcuts[]=
					{
						"1024 + 0x1C",
						"1024 + 0x9C"
					};
				};
				class MissionPreviewCamera
				{
					text="$STR_3DEN_Display3DEN_MenuBar_MissionPreviewCamera_text";
					data="MissionPreviewCamera";
					shortcuts[]=
					{
						"512 + 	1024 + 0x1C",
						"512 + 	1024 + 0x9C"
					};
					action="{'MissionPreviewCustom' call bis_fnc_3DENMissionPreview;} call bis_fnc_3DENMissionPreview;";
				};
				class MissionPreviewSpectator
				{
					text="$STR_3DEN_Display3DEN_MenuBar_MissionPreviewSpectator_text";
					data="MissionPreviewSpectator";
					action="{'MissionPreviewSpectator' call bis_fnc_3DENMissionPreview;} call bis_fnc_3DENMissionPreview;";
				};
				class MissionPreviewMP
				{
					text="$STR_3DEN_Display3DEN_MenuBar_MissionPreviewMP_text";
					data="MissionPreviewMP";
				};
				class Options
				{
					text="$STR_3DEN_Display3DEN_MenuBar_Options_text";
					items[]=
					{
						"OptionsEditor",
						"Separator",
						"OptionsVideo",
						"OptionsAudio",
						"OptionsGame",
						"OptionsControls"
					};
				};
				class OptionsVideo
				{
					text="$STR_3DEN_Display3DEN_MenuBar_OptionsVideo_text";
					data="OptionsVideo";
					opensNewWindow=1;
				};
				class OptionsAudio
				{
					text="$STR_3DEN_Display3DEN_MenuBar_OptionsAudio_text";
					data="OptionsAudio";
					opensNewWindow=1;
				};
				class OptionsGame
				{
					text="$STR_3DEN_Display3DEN_MenuBar_OptionsGame_text";
					data="OptionsGame";
					opensNewWindow=1;
				};
				class OptionsControls
				{
					text="$STR_3DEN_Display3DEN_MenuBar_OptionsControls_text";
					data="OptionsControls";
					opensNewWindow=1;
				};
				class OptionsEditor
				{
					text="$STR_3DEN_Preferences_textSingular";
					data="Preferences";
					action="edit3DENMissionAttributes 'Preferences';";
					shortcuts[]=
					{
						"512 + 0x25"
					};
					opensNewWindow=1;
				};
				class Help
				{
					text="$STR_3DEN_Display3DEN_MenuBar_Help_text";
					items[]=
					{
						"HelpDoc",
						"HelpScripting",
						"Separator",
						"HelpBiki",
						"HelpForums",
						"HelpFeedback",
						"HelpDevHub",
						"Separator",
						"HelpTutorials"
					};
				};
				class HelpDoc
				{
					text="$STR_3DEN_Display3DEN_MenuBar_HelpDoc_text";
					data="HelpDoc";
					picture="\a3\3DEN\Data\Controls\ctrlMenu\link_ca.paa";
					weblink="https://community.bistudio.com/wiki/Eden_Editor";
					opensNewWindow=1;
				};
				class HelpScripting
				{
					text="$STR_3DEN_Display3DEN_MenuBar_HelpScripting_text";
					data="HelpScripting";
					picture="\a3\3DEN\Data\Controls\ctrlMenu\link_ca.paa";
					weblink="https://community.bistudio.com/wiki/Category:Scripting_Commands_Arma_3";
					opensNewWindow=1;
				};
				class HelpBiki
				{
					text="$STR_3DEN_Display3DEN_MenuBar_HelpBiki_text";
					data="HelpBiki";
					picture="\a3\3DEN\Data\Controls\ctrlMenu\link_ca.paa";
					weblink="https://community.bistudio.com/";
					opensNewWindow=1;
				};
				class HelpForums
				{
					text="$STR_3DEN_Display3DEN_MenuBar_HelpForums_text";
					data="HelpForums";
					picture="\a3\3DEN\Data\Controls\ctrlMenu\link_ca.paa";
					weblink="https://forums.bistudio.com/forum/161-arma-3-editing/";
					opensNewWindow=1;
				};
				class HelpFeedback
				{
					text="$STR_3DEN_Display3DEN_MenuBar_HelpFeedback_text";
					data="HelpFeedback";
					picture="\a3\3DEN\Data\Controls\ctrlMenu\link_ca.paa";
					weblink="https://feedback.arma3.com";
					opensNewWindow=1;
				};
				class HelpDevHub
				{
					text="$STR_3DEN_Display3DEN_MenuBar_HelpDevHub_text";
					data="HelpDevHub";
					picture="\a3\3DEN\Data\Controls\ctrlMenu\link_ca.paa";
					weblink="https://dev.arma3.com/";
					opensNewWindow=1;
				};
				class HelpTutorials
				{
					text="$STR_3DEN_Display3DENTutorial_Title_text";
					data="HelpTutorials";
					picture="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\help_tutorial_ca.paa";
					action="(ctrlparent (_this select 0)) createdisplay 'Display3DENTutorial';";
					opensNewWindow=1;
				};
				class HelpUpdates
				{
					text="$STR_3DEN_Display3DENUpdates_Title_text";
					data="HelpUpdates";
					picture="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\help_updates_ca.paa";
					action="(ctrlparent (_this select 0)) createdisplay 'Display3DENUpdates';";
					opensNewWindow=1;
				};
				class Separator
				{
				};
				class Default
				{
					text="$STR_3DEN_Display3DEN_MenuBar_Default_text";
					enable=0;
				};
			};
		};
		class Toolbar: ctrlControlsGroupNoScrollbars
		{
			idc=1000;
			x="safezoneX";
			y="safezoneY + 		5 * (pixelH * pixelGrid * 	0.50)";
			w="safezoneW";
			h="(	5 + 2) * (pixelH * pixelGrid * 	0.50)";
			class Controls
			{
				class ToolbarBackground: ctrlStatic
				{
					idc=1001;
					colorBackground[]={0.2,0.2,0.2,1};
					x=0;
					y=0;
					w="safezoneW";
					h="7 * (pixelH * pixelGrid * 	0.50)";
				};
				class File: ctrlControlsGroupNoScrollbars
				{
					idc=1002;
					x=0;
					y="1 * (pixelH * pixelGrid * 	0.50)";
					w="4 * 	(	5 * (pixelW * pixelGrid * 	0.50))";
					h="(	5 * (pixelH * pixelGrid * 	0.50))";
					class Controls
					{
						class New: ctrlButtonToolbar
						{
							idc=1006;
							action="do3DENAction 'MissionNew';";
							text="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\new_ca.paa";
							tooltip="$STR_3DEN_Display3DEN_MenuBar_MissionNew_text";
							onLoad="['showShortcut','MissionNew',_this] call bis_fnc_3DENInterface;";
							x="0 * 	(	5 * (pixelW * pixelGrid * 	0.50))";
							y=0;
							h="(	5 * (pixelH * pixelGrid * 	0.50))";
							w="(	5 * (pixelW * pixelGrid * 	0.50))";
						};
						class Open: ctrlButtonToolbar
						{
							idc=1007;
							action="do3DENAction 'MissionLoad';";
							text="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\open_ca.paa";
							tooltip="$STR_3DEN_Display3DEN_MenuBar_MissionOpen_text";
							onLoad="['showShortcut','MissionLoad',_this] call bis_fnc_3DENInterface;";
							x="1 * 	(	5 * (pixelW * pixelGrid * 	0.50))";
							y=0;
							h="(	5 * (pixelH * pixelGrid * 	0.50))";
							w="(	5 * (pixelW * pixelGrid * 	0.50))";
						};
						class Save: ctrlButtonToolbar
						{
							idc=1008;
							action="do3DENAction 'MissionSave';";
							text="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\save_ca.paa";
							tooltip="$STR_3DEN_Display3DEN_MenuBar_MissionSave_text";
							onLoad="['showShortcut','MissionSave',_this] call bis_fnc_3DENInterface;";
							x="2 * 	(	5 * (pixelW * pixelGrid * 	0.50))";
							y=0;
							h="(	5 * (pixelH * pixelGrid * 	0.50))";
							w="(	5 * (pixelW * pixelGrid * 	0.50))";
						};
						class Publish: ctrlButtonToolbar
						{
							idc=10091;
							action="do3DENAction 'OpenSteamPublishDialog';";
							text="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\steam_ca.paa";
							tooltip="$STR_3DEN_Display3DEN_MenuBar_MissionPublishSteam_text";
							onLoad="['showShortcut','MissionPublishSteam',_this] call bis_fnc_3DENInterface;";
							x="3 * 	(	5 * (pixelW * pixelGrid * 	0.50))";
							y=0;
							h="(	5 * (pixelH * pixelGrid * 	0.50))";
							w="(	5 * (pixelW * pixelGrid * 	0.50))";
						};
					};
				};
				class Separator1: ctrlStatic
				{
					colorBackground[]={0,0,0,0.5};
					x="4.5 * 	(	5 * (pixelW * pixelGrid * 	0.50))";
					y="1 * (pixelH * pixelGrid * 	0.50)";
					w="pixelW";
					h="(	5 * (pixelH * pixelGrid * 	0.50))";
				};
				class History: ctrlControlsGroupNoScrollbars
				{
					idc=1003;
					x="5 * 	(	5 * (pixelW * pixelGrid * 	0.50))";
					y="1 * (pixelH * pixelGrid * 	0.50)";
					w="2 * 	(	5 * (pixelW * pixelGrid * 	0.50))";
					h="(	5 * (pixelH * pixelGrid * 	0.50))";
					class Controls
					{
						class Undo: ctrlButtonToolbar
						{
							idc=1010;
							action="do3DENAction 'Undo';";
							text="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\undo_ca.paa";
							tooltip="$STR_3DEN_Display3DEN_MenuBar_Undo_text";
							onLoad="['showShortcut','Undo',_this] call bis_fnc_3DENInterface;";
							x="0 * 	(	5 * (pixelW * pixelGrid * 	0.50))";
							y=0;
							h="(	5 * (pixelH * pixelGrid * 	0.50))";
							w="(	5 * (pixelW * pixelGrid * 	0.50))";
						};
						class Redo: ctrlButtonToolbar
						{
							idc=1011;
							action="do3DENAction 'Redo';";
							text="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\redo_ca.paa";
							tooltip="$STR_3DEN_Display3DEN_MenuBar_Redo_text";
							onLoad="['showShortcut','Redo',_this] call bis_fnc_3DENInterface;";
							x="1 * 	(	5 * (pixelW * pixelGrid * 	0.50))";
							y=0;
							h="(	5 * (pixelH * pixelGrid * 	0.50))";
							w="(	5 * (pixelW * pixelGrid * 	0.50))";
						};
					};
				};
				class Separator2: Separator1
				{
					x="7.5 * 	(	5 * (pixelW * pixelGrid * 	0.50))";
				};
				class Widget: ctrlControlsGroupNoScrollbars
				{
					idc=1004;
					x="8 * 	(	5 * (pixelW * pixelGrid * 	0.50))";
					y="1 * (pixelH * pixelGrid * 	0.50)";
					w="5 * 	(	5 * (pixelW * pixelGrid * 	0.50))";
					h="(	5 * (pixelH * pixelGrid * 	0.50))";
					class Controls
					{
						class WidgetNone: ctrlCheckboxToolbar
						{
							idc=10041;
							onCheckedChanged="do3DENAction 'WidgetNone'";
							onLoad="['showShortcut','WidgetNone',_this] call bis_fnc_3DENInterface;";
							tooltip="$STR_3DEN_Display3DEN_MenuBar_WidgetNone_text";
							textureChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_none_on_ca.paa";
							textureUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_none_off_ca.paa";
							textureFocusedChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_none_on_ca.paa";
							textureFocusedUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_none_off_ca.paa";
							textureHoverChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_none_on_ca.paa";
							textureHoverUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_none_off_ca.paa";
							texturePressedChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_none_on_ca.paa";
							texturePressedUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_none_off_ca.paa";
							textureDisabledChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_none_on_ca.paa";
							textureDisabledUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_none_off_ca.paa";
							x="0 * 	(	5 * (pixelW * pixelGrid * 	0.50))";
							y=0;
							h="(	5 * (pixelH * pixelGrid * 	0.50))";
							w="(	5 * (pixelW * pixelGrid * 	0.50))";
						};
						class WidgetTranslation: ctrlCheckboxToolbar
						{
							idc=10042;
							onCheckedChanged="do3DENAction 'WidgetTranslation'";
							onLoad="['showShortcut','WidgetTranslation',_this] call bis_fnc_3DENInterface;";
							tooltip="$STR_3DEN_Display3DEN_MenuBar_WidgetTranslation_text";
							textureChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_translation_on_ca.paa";
							textureUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_translation_off_ca.paa";
							textureFocusedChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_translation_on_ca.paa";
							textureFocusedUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_translation_off_ca.paa";
							textureHoverChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_translation_on_ca.paa";
							textureHoverUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_translation_off_ca.paa";
							texturePressedChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_translation_on_ca.paa";
							texturePressedUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_translation_off_ca.paa";
							textureDisabledChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_translation_on_ca.paa";
							textureDisabledUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_translation_off_ca.paa";
							x="1 * 	(	5 * (pixelW * pixelGrid * 	0.50))";
							y=0;
							h="(	5 * (pixelH * pixelGrid * 	0.50))";
							w="(	5 * (pixelW * pixelGrid * 	0.50))";
						};
						class WidgetRotation: ctrlCheckboxToolbar
						{
							idc=10043;
							onCheckedChanged="do3DENAction 'WidgetRotation'";
							onLoad="['showShortcut','WidgetRotation',_this] call bis_fnc_3DENInterface;";
							tooltip="$STR_3DEN_Display3DEN_MenuBar_WidgetRotation_text";
							textureChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_rotation_on_ca.paa";
							textureUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_rotation_off_ca.paa";
							textureFocusedChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_rotation_on_ca.paa";
							textureFocusedUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_rotation_off_ca.paa";
							textureHoverChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_rotation_on_ca.paa";
							textureHoverUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_rotation_off_ca.paa";
							texturePressedChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_rotation_on_ca.paa";
							texturePressedUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_rotation_off_ca.paa";
							textureDisabledChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_rotation_on_ca.paa";
							textureDisabledUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_rotation_off_ca.paa";
							x="2 * 	(	5 * (pixelW * pixelGrid * 	0.50))";
							y=0;
							h="(	5 * (pixelH * pixelGrid * 	0.50))";
							w="(	5 * (pixelW * pixelGrid * 	0.50))";
						};
						class WidgetScaling: ctrlCheckboxToolbar
						{
							idc=10044;
							onCheckedChanged="do3DENAction 'WidgetScale'";
							onLoad="['showShortcut','WidgetScale',_this] call bis_fnc_3DENInterface;";
							tooltip="$STR_3DEN_Display3DEN_MenuBar_WidgetScaling_text";
							textureChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_scaling_on_ca.paa";
							textureUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_scaling_off_ca.paa";
							textureFocusedChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_scaling_on_ca.paa";
							textureFocusedUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_scaling_off_ca.paa";
							textureHoverChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_scaling_on_ca.paa";
							textureHoverUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_scaling_off_ca.paa";
							texturePressedChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_scaling_on_ca.paa";
							texturePressedUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_scaling_off_ca.paa";
							textureDisabledChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_scaling_on_ca.paa";
							textureDisabledUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_scaling_off_ca.paa";
							x="3 * 	(	5 * (pixelW * pixelGrid * 	0.50))";
							y=0;
							h="(	5 * (pixelH * pixelGrid * 	0.50))";
							w="(	5 * (pixelW * pixelGrid * 	0.50))";
						};
						class WidgetArea: ctrlCheckboxToolbar
						{
							idc=10045;
							onCheckedChanged="do3DENAction 'WidgetArea'";
							onLoad="['showShortcut','WidgetArea',_this] call bis_fnc_3DENInterface;";
							tooltip="$STR_3DEN_Display3DEN_MenuBar_WidgetArea_text";
							textureChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_area_on_ca.paa";
							textureUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_area_off_ca.paa";
							textureFocusedChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_area_on_ca.paa";
							textureFocusedUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_area_off_ca.paa";
							textureHoverChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_area_on_ca.paa";
							textureHoverUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_area_off_ca.paa";
							texturePressedChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_area_on_ca.paa";
							texturePressedUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_area_off_ca.paa";
							textureDisabledChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_area_on_ca.paa";
							textureDisabledUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_area_off_ca.paa";
							x="4 * 	(	5 * (pixelW * pixelGrid * 	0.50))";
							y=0;
							h="(	5 * (pixelH * pixelGrid * 	0.50))";
							w="(	5 * (pixelW * pixelGrid * 	0.50))";
						};
					};
				};
				class Separator3: Separator1
				{
					x="13.5 * 	(	5 * (pixelW * pixelGrid * 	0.50))";
				};
				class Interaction: ctrlControlsGroupNoScrollbars
				{
					idc=1005;
					x="14 * 	(	5 * (pixelW * pixelGrid * 	0.50))";
					y="1 * (pixelH * pixelGrid * 	0.50)";
					w="3 * 	(	5 * (pixelW * pixelGrid * 	0.50))";
					h="(	5 * (pixelH * pixelGrid * 	0.50))";
					class Controls
					{
						class WidgetCoord: ctrlCheckboxToolbar
						{
							idc=1016;
							onCheckedChanged="do3DENAction 'WidgetCoord';";
							onLoad="['showShortcut','WidgetCoord',_this] call bis_fnc_3DENInterface;";
							tooltip="$STR_3den_display3den_menubar_widgetspace_text";
							textureChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_local_ca.paa";
							textureUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_global_ca.paa";
							textureFocusedChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_local_ca.paa";
							textureFocusedUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_global_ca.paa";
							textureHoverChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_local_ca.paa";
							textureHoverUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_global_ca.paa";
							texturePressedChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_local_ca.paa";
							texturePressedUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_global_ca.paa";
							textureDisabledChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_local_ca.paa";
							textureDisabledUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_global_ca.paa";
							x="0 * 	(	5 * (pixelW * pixelGrid * 	0.50))";
							y=0;
							h="(	5 * (pixelH * pixelGrid * 	0.50))";
							w="(	5 * (pixelW * pixelGrid * 	0.50))";
						};
						class VerticalToggle: ctrlCheckboxToolbar
						{
							idc=1017;
							onCheckedChanged="do3DENAction 'VerticalToggle';";
							onLoad="['showShortcut','VerticalToggle',_this] call bis_fnc_3DENInterface;";
							tooltip="$STR_3DEN_Display3DEN_MenuBar_VerticalToggle_text";
							textureChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\vert_ATL_ca.paa";
							textureUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\vert_ASL_ca.paa";
							textureFocusedChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\vert_ATL_ca.paa";
							textureFocusedUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\vert_ASL_ca.paa";
							textureHoverChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\vert_ATL_ca.paa";
							textureHoverUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\vert_ASL_ca.paa";
							texturePressedChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\vert_ATL_ca.paa";
							texturePressedUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\vert_ASL_ca.paa";
							textureDisabledChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\vert_ATL_ca.paa";
							textureDisabledUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\vert_ASL_ca.paa";
							x="1 * 	(	5 * (pixelW * pixelGrid * 	0.50))";
							y=0;
							h="(	5 * (pixelH * pixelGrid * 	0.50))";
							w="(	5 * (pixelW * pixelGrid * 	0.50))";
						};
						class SurfaceSnapToggle: ctrlCheckboxToolbar
						{
							idc=1018;
							onCheckedChanged="do3DENAction 'SurfaceSnapToggle';";
							onLoad="['showShortcut','SurfaceSnapToggle',_this] call bis_fnc_3DENInterface;";
							tooltip="$STR_3DEN_Display3DEN_MenuBar_SurfaceSnapToggle_text";
							textureChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\snap_on_ca.paa";
							textureUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\snap_off_ca.paa";
							textureFocusedChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\snap_on_ca.paa";
							textureFocusedUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\snap_off_ca.paa";
							textureHoverChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\snap_on_ca.paa";
							textureHoverUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\snap_off_ca.paa";
							texturePressedChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\snap_on_ca.paa";
							texturePressedUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\snap_off_ca.paa";
							textureDisabledChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\snap_on_ca.paa";
							textureDisabledUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\snap_off_ca.paa";
							x="2 * 	(	5 * (pixelW * pixelGrid * 	0.50))";
							y=0;
							h="(	5 * (pixelH * pixelGrid * 	0.50))";
							w="(	5 * (pixelW * pixelGrid * 	0.50))";
						};
					};
				};
				class Separator4: Separator1
				{
					x="17.5 * 	(	5 * (pixelW * pixelGrid * 	0.50))";
				};
				class Grid: ctrlControlsGroupNoScrollbars
				{
					idc=1024;
					x="18 * 	(	5 * (pixelW * pixelGrid * 	0.50))";
					y="1 * (pixelH * pixelGrid * 	0.50)";
					w="4.5 * 	(	5 * (pixelW * pixelGrid * 	0.50))";
					h="(	5 * (pixelH * pixelGrid * 	0.50))";
					class Controls
					{
						class Translation: ctrlCheckboxToolbar
						{
							idc=1025;
							onCheckedChanged="do3DENAction 'MoveGridToggle';";
							onLoad="['showShortcut','MoveGridToggle',_this] call bis_fnc_3DENInterface;";
							tooltip="$STR_3DEN_Display3DEN_MenuBar_GridTranslationToggle_text";
							textureChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\grid_translation_on_ca.paa";
							textureUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\grid_translation_off_ca.paa";
							textureFocusedChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\grid_translation_on_ca.paa";
							textureFocusedUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\grid_translation_off_ca.paa";
							textureHoverChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\grid_translation_on_ca.paa";
							textureHoverUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\grid_translation_off_ca.paa";
							texturePressedChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\grid_translation_on_ca.paa";
							texturePressedUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\grid_translation_off_ca.paa";
							textureDisabledChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\grid_translation_on_ca.paa";
							textureDisabledUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\grid_translation_off_ca.paa";
							x="0 * 	(	5 * (pixelW * pixelGrid * 	0.50))";
							y=0;
							h="(	5 * (pixelH * pixelGrid * 	0.50))";
							w="(	5 * (pixelW * pixelGrid * 	0.50))";
						};
						class TranslationValue: ctrlComboToolbar
						{
							idc=1026;
							tooltip="$STR_3DEN_Display3DEN_MenuBar_GridTranslationToggle_text";
							x="1 * 	(	5 * (pixelW * pixelGrid * 	0.50))";
							y=0;
							h="(	5 * (pixelH * pixelGrid * 	0.50))";
							w="(	5 * (pixelW * pixelGrid * 	0.50)) * 0.5";
							gridType="translation";
							onLoad="with uinamespace do {['init',_this] call bis_fnc_3DENGrid;};";
						};
						class Rotation: Translation
						{
							idc=1027;
							onCheckedChanged="do3DENAction 'RotateGridToggle';";
							onLoad="['showShortcut','RotateGridToggle',_this] call bis_fnc_3DENInterface;";
							tooltip="$STR_3DEN_Display3DEN_MenuBar_GridRotationToggle_text";
							textureChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\grid_rotation_on_ca.paa";
							textureUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\grid_rotation_off_ca.paa";
							textureFocusedChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\grid_rotation_on_ca.paa";
							textureFocusedUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\grid_rotation_off_ca.paa";
							textureHoverChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\grid_rotation_on_ca.paa";
							textureHoverUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\grid_rotation_off_ca.paa";
							texturePressedChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\grid_rotation_on_ca.paa";
							texturePressedUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\grid_rotation_off_ca.paa";
							textureDisabledChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\grid_rotation_on_ca.paa";
							textureDisabledUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\grid_rotation_off_ca.paa";
							x="1.5 * 	(	5 * (pixelW * pixelGrid * 	0.50))";
							y=0;
							h="(	5 * (pixelH * pixelGrid * 	0.50))";
							w="(	5 * (pixelW * pixelGrid * 	0.50))";
						};
						class RotationValue: TranslationValue
						{
							idc=1028;
							tooltip="$STR_3DEN_Display3DEN_MenuBar_GridRotationToggle_text";
							gridType="rotation";
							x="2.5 * 	(	5 * (pixelW * pixelGrid * 	0.50))";
							y=0;
							h="(	5 * (pixelH * pixelGrid * 	0.50))";
							w="(	5 * (pixelW * pixelGrid * 	0.50)) * 0.5";
						};
						class Scaling: Translation
						{
							idc=1029;
							onCheckedChanged="do3DENAction 'ScaleGridToggle';";
							onLoad="['showShortcut','ScaleGridToggle',_this] call bis_fnc_3DENInterface;";
							tooltip="$STR_3DEN_Display3DEN_MenuBar_GridScalingToggle_text";
							textureChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\grid_scaling_on_ca.paa";
							textureUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\grid_scaling_off_ca.paa";
							textureFocusedChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\grid_scaling_on_ca.paa";
							textureFocusedUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\grid_scaling_off_ca.paa";
							textureHoverChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\grid_scaling_on_ca.paa";
							textureHoverUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\grid_scaling_off_ca.paa";
							texturePressedChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\grid_scaling_on_ca.paa";
							texturePressedUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\grid_scaling_off_ca.paa";
							textureDisabledChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\grid_scaling_on_ca.paa";
							textureDisabledUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\grid_scaling_off_ca.paa";
							x="3 * 	(	5 * (pixelW * pixelGrid * 	0.50))";
							y=0;
							h="(	5 * (pixelH * pixelGrid * 	0.50))";
							w="(	5 * (pixelW * pixelGrid * 	0.50))";
						};
						class ScalingValue: TranslationValue
						{
							idc=1030;
							tooltip="$STR_3DEN_Display3DEN_MenuBar_GridScalingToggle_text";
							gridType="scaling";
							x="4 * 	(	5 * (pixelW * pixelGrid * 	0.50))";
							y=0;
							h="(	5 * (pixelH * pixelGrid * 	0.50))";
							w="(	5 * (pixelW * pixelGrid * 	0.50)) * 0.5";
						};
					};
				};
				class Separator5: Separator1
				{
					x="23 * 	(	5 * (pixelW * pixelGrid * 	0.50))";
				};
				class Mission: ctrlControlsGroupNoScrollbars
				{
					idc=10301;
					x="23.5 * 	(	5 * (pixelW * pixelGrid * 	0.50))";
					y="1 * (pixelH * pixelGrid * 	0.50)";
					w="10 * 	(	5 * (pixelW * pixelGrid * 	0.50))";
					h="(	5 * (pixelH * pixelGrid * 	0.50))";
					class Controls
					{
						class Intel: ctrlButtonToolbar
						{
							idc=10302;
							action="edit3DENMissionAttributes 'Intel';";
							onLoad="['showShortcut','OpenIntelDisplay',_this] call bis_fnc_3DENInterface;";
							text="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\intel_ca.paa";
							tooltip="$STR_3DEN_Display3DEN_MenuBar_MissionIntel_text";
							x="0 * 	(	5 * (pixelW * pixelGrid * 	0.50))";
							y=0;
							h="(	5 * (pixelH * pixelGrid * 	0.50))";
							w="(	5 * (pixelW * pixelGrid * 	0.50))";
						};
						class Map: ctrlCheckboxToolbar
						{
							idc=10303;
							onCheckedChanged="do3DENAction 'ToggleMap';";
							onLoad="['showShortcut','ToggleMap',_this] call bis_fnc_3DENInterface;";
							tooltip="$STR_3DEN_Display3DEN_MenuBar_Map_text";
							textureChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\map_on_ca.paa";
							textureUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\map_off_ca.paa";
							textureFocusedChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\map_on_ca.paa";
							textureFocusedUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\map_off_ca.paa";
							textureHoverChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\map_on_ca.paa";
							textureHoverUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\map_off_ca.paa";
							texturePressedChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\map_on_ca.paa";
							texturePressedUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\map_off_ca.paa";
							textureDisabledChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\map_on_ca.paa";
							textureDisabledUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\map_off_ca.paa";
							x="1 * 	(	5 * (pixelW * pixelGrid * 	0.50))";
							y=0;
							h="(	5 * (pixelH * pixelGrid * 	0.50))";
							w="(	5 * (pixelW * pixelGrid * 	0.50))";
						};
						class Flashlight: ctrlCheckboxToolbar
						{
							idc=10305;
							onCheckedChanged="[] call bis_fnc_3DENFlashlight;";
							onLoad="['showShortcut','ToggleFlashlight',_this] call bis_fnc_3DENInterface;";
							tooltip="$STR_3DEN_Display3DEN_MenuBar_ToggleFlashlight_text";
							textureChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\flashlight_on_ca.paa";
							textureUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\flashlight_off_ca.paa";
							textureFocusedChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\flashlight_on_ca.paa";
							textureFocusedUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\flashlight_off_ca.paa";
							textureHoverChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\flashlight_on_ca.paa";
							textureHoverUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\flashlight_off_ca.paa";
							texturePressedChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\flashlight_on_ca.paa";
							texturePressedUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\flashlight_off_ca.paa";
							textureDisabledChecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\flashlight_on_ca.paa";
							textureDisabledUnchecked="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\flashlight_off_ca.paa";
							x="2 * 	(	5 * (pixelW * pixelGrid * 	0.50))";
							y=0;
							h="(	5 * (pixelH * pixelGrid * 	0.50))";
							w="(	5 * (pixelW * pixelGrid * 	0.50))";
						};
						class Vision: ctrlButtonToolbar
						{
							idc=10304;
							action="[] call bis_fnc_3DENVisionMode;";
							onLoad="['showShortcut','VisionModeToggle',_this] call bis_fnc_3DENInterface;";
							tooltip="$STR_3DEN_Display3DEN_MenuBar_VisionModeToggle_text";
							text="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\vision_normal_ca.paa";
							x="3 * 	(	5 * (pixelW * pixelGrid * 	0.50))";
							y=0;
							h="(	5 * (pixelH * pixelGrid * 	0.50))";
							w="(	5 * (pixelW * pixelGrid * 	0.50))";
						};
						class Workspace: ctrlCombo
						{
							idc=10306;
							tooltip="$STR_3DEN_Display3DEN_MenuBar_Space_text";
							x="4.5 * 	(	5 * (pixelW * pixelGrid * 	0.50))";
							y=0;
							h="(	5 * (pixelH * pixelGrid * 	0.50))";
							w="5.5 * 	(	5 * (pixelW * pixelGrid * 	0.50))";
							onLbSelChanged="do3DENAction ((_this select 0) lbdata (_this select 1));";
							class Items
							{
								class Mission
								{
									text="$STR_3den_scenario";
									data="MissionPartMission";
									default=1;
								};
								class Intro
								{
									text="$STR_3den_display3den_menubar_spaceintro_text";
									data="MissionPartIntro";
								};
								class OutroWin
								{
									text="$STR_3den_display3den_menubar_spaceoutrowin_text";
									data="MissionPartOutroWin";
								};
								class OutroLose
								{
									text="$STR_3den_display3den_menubar_spaceoutrolose_text";
									data="MissionPartOutroLoose";
								};
							};
						};
					};
				};
				class Help: ctrlControlsGroupNoScrollbars
				{
					idc=10251;
					x="safezoneW - 1 * 	(	5 * (pixelW * pixelGrid * 	0.50)) - (pixelW * pixelGrid * 	0.50)";
					y="1 * (pixelH * pixelGrid * 	0.50)";
					w="1 * 	(	5 * (pixelW * pixelGrid * 	0.50))";
					h="(	5 * (pixelH * pixelGrid * 	0.50))";
					class Controls
					{
						class Tutorial: ctrlButtonToolbar
						{
							idc=10310;
							text="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\help_tutorial_ca.paa";
							tooltip="$STR_3DEN_Display3DENTutorial_Title_text";
							onLoad="				_count = 0;				{					_count = _count + count configproperties [_x >> 'Sections','isclass _x'];				} foreach configproperties [configfile >> 'Cfg3DEN' >> 'Tutorials'];				if (_count > count (profilenamespace getvariable ['display3DENTutorial_completed',[]])) then {					(_this select 0) ctrlsettext '\a3\3DEN\Data\Displays\Display3DEN\ToolBar\help_tutorial_new_ca.paa';				};			";
							onButtonClick="(ctrlparent (_this select 0)) createdisplay 'Display3DENTutorial';";
							x="0 * 	(	5 * (pixelW * pixelGrid * 	0.50))";
							y=0;
							h="(	5 * (pixelH * pixelGrid * 	0.50))";
							w="(	5 * (pixelW * pixelGrid * 	0.50))";
						};
					};
				};
			};
		};
		class Notification: ctrlStructuredText
		{
			idc=10312;
			x="safezoneX + 	60 * (pixelW * pixelGrid * 	0.50)";
			y="safezoneY + (		5 + 	(	5 + 2)) * (pixelH * pixelGrid * 	0.50)";
			w="safezoneW - 2 * 	60 * (pixelW * pixelGrid * 	0.50)";
			h=0;
			colorBackground[]={1,0,1,1};
			shadow=0;
			class Attributes: Attributes
			{
				align="center";
			};
		};
		class TabLeftToggle: ctrlButton
		{
			idc=1031;
			style=2;
			x="safezoneX + 0";
			y="safezoneY + (		5 + 	(	5 + 2)) * (pixelH * pixelGrid * 	0.50)";
			w="(	5 + 1) * (pixelW * pixelGrid * 	0.50)";
			h="(	5 + 1) * (pixelH * pixelGrid * 	0.50)";
			text="»";
			sizeEx="5.58 * (1 / (getResolution select 3)) * pixelGrid * 0.5";
			colorBackground[]={0.1,0.1,0.1,1};
			onbuttonclick="'ShowPanelLeft' call bis_fnc_3DENInterface;";
		};
		class PanelLeft: ctrlControlsGroupNoScrollbars
		{
			idc=1019;
			x="safezoneX";
			y="safezoneY + (		5 + 	(	5 + 2)) * (pixelH * pixelGrid * 	0.50)";
			w="60 * (pixelW * pixelGrid * 	0.50)";
			h="safezoneH - (		5 + 	(	5 + 2) + 		4) * (pixelH * pixelGrid * 	0.50)";
			class Controls
			{
				class TabLeftBackground: ctrlStatic
				{
					x=0;
					y=0;
					w="60 * (pixelW * pixelGrid * 	0.50)";
					h="(	5 + 1) * (pixelH * pixelGrid * 	0.50)";
					colorBackground[]={0.1,0.1,0.1,1};
				};
				class TabLeftToggle: ctrlButton
				{
					idc=1032;
					style=2;
					x=0;
					y=0;
					w="(	5 + 1) * (pixelW * pixelGrid * 	0.50)";
					h="(	5 + 1) * (pixelH * pixelGrid * 	0.50)";
					text="«";
					sizeEx="5.58 * (1 / (getResolution select 3)) * pixelGrid * 0.5";
					colorBackground[]={0.1,0.1,0.1,1};
					onbuttonclick="'ShowPanelLeft' call bis_fnc_3DENInterface";
				};
				class TabLeftSections: ctrlToolbox
				{
					idc=1033;
					x="(	5 + 1) * (pixelW * pixelGrid * 	0.50)";
					y="(pixelH * pixelGrid * 	0.50)";
					w="(	60 - 	(	5 + 1) - 1) * (pixelW * pixelGrid * 	0.50)";
					h="5 * (pixelH * pixelGrid * 	0.50)";
					font="RobotoCondensedLight";
					columns=2;
					strings[]=
					{
						"$STR_3DEN_Display3DEN_Entities",
						"$STR_3DEN_Display3DEN_Locations"
					};
					colorBackground[]={0,0,0,0};
					colorSelectedBg[]={0.2,0.2,0.2,1};
					onToolBoxSelChanged="['tabLeft',_this select 1] call bis_fnc_3DENInterface;";
				};
				class PanelLeftBackground: ctrlStatic
				{
					idc=1020;
					x=0;
					y="(	5 + 1) * (pixelH * pixelGrid * 	0.50)";
					w="60 * (pixelW * pixelGrid * 	0.50)";
					h="safezoneH - (		5 + 	(	5 + 2) + 	(	5 + 1) + 		4) * (pixelH * pixelGrid * 	0.50)";
					colorBackground[]={0.2,0.2,0.2,0.87};
				};
				class PanelLeftEdit: ctrlControlsGroupNoScrollbars
				{
					idc=1037;
					x=0;
					y="(	5 + 1) * (pixelH * pixelGrid * 	0.50)";
					w="60 * (pixelW * pixelGrid * 	0.50)";
					h="safezoneH - (		5 + 	(	5 + 2) + 	(	5 + 1) + 		4) * (pixelH * pixelGrid * 	0.50)";
					class Controls
					{
						class PanelLeftEditBackground: ctrlStatic
						{
							w="60 * (pixelW * pixelGrid * 	0.50)";
							h="(	5 + 2) * (pixelH * pixelGrid * 	0.50)";
							colorBackground[]={0.2,0.2,0.2,1};
						};
						class SearchEdit: ctrlEdit
						{
							idc=80;
							x="1 * (pixelW * pixelGrid * 	0.50)";
							y="(pixelH * pixelGrid * 	0.50)";
							w="(	60 - 3 * 	5 - 1) * (pixelW * pixelGrid * 	0.50)";
							h="5 * (pixelH * pixelGrid * 	0.50)";
						};
						class SearchEditButton: ctrlButtonSearch
						{
							idc=81;
							x="(	60 - 3 * 	5) * (pixelW * pixelGrid * 	0.50)";
							y="(pixelH * pixelGrid * 	0.50)";
							w="5 * (pixelW * pixelGrid * 	0.50)";
							h="5 * (pixelH * pixelGrid * 	0.50)";
							onLoad="['showShortcut','SearchEdit',_this] call bis_fnc_3DENInterface;";
							tooltip="$STR_3DEN_Display3DEN_SearchEditButton_tooltip";
						};
						class CollapseAllButton: ctrlButtonCollapseAll
						{
							idc=-1;
							x="(	60 - 2 * 	5) * (pixelW * pixelGrid * 	0.50)";
							y="(pixelH * pixelGrid * 	0.50)";
							w="5 * (pixelW * pixelGrid * 	0.50)";
							h="5 * (pixelH * pixelGrid * 	0.50)";
							onButtonClick="['collapseEntityList'] call bis_fnc_3DENInterface;";
						};
						class ExpandAllButton: ctrlButtonExpandAll
						{
							idc=-1;
							x="(	60 - 1 * 	5) * (pixelW * pixelGrid * 	0.50)";
							y="(pixelH * pixelGrid * 	0.50)";
							w="5 * (pixelW * pixelGrid * 	0.50)";
							h="5 * (pixelH * pixelGrid * 	0.50)";
							onButtonClick="['expandEntityList'] call bis_fnc_3DENInterface;";
						};
						class Edit: ctrlTree
						{
							idc=55;
							x=0;
							y="(	5 + 2) * (pixelH * pixelGrid * 	0.50)";
							w="60 * (pixelW * pixelGrid * 	0.50)";
							h="safezoneH - (		5 + 	(	5 + 2) + 	(	5 + 1) + 		4 + 	5 + 2 + 1 + 	5) * (pixelH * pixelGrid * 	0.50)";
							sizeEx="3.96 * (1 / (getResolution select 3)) * pixelGrid * 0.5";
							font="RobotoCondensedLight";
							colorBorder[]={0,0,0,0};
							multiselectEnabled=1;
							expandOnDoubleclick=0;
							disableKeyboardSearch=1;
							colorDisabled[]={1,1,1,0.25};
						};
						class EditPanel: ctrlControlsGroupNoScrollbars
						{
							y="safezoneH - (		5 + 	(	5 + 2) + 	(	5 + 1) + 		4 + 	5 + 2) * (pixelH * pixelGrid * 	0.50)";
							w="60 * (pixelW * pixelGrid * 	0.50)";
							h="(	5 + 2) * (pixelH * pixelGrid * 	0.50)";
							class Controls
							{
								class EditPanelBackground: ctrlStatic
								{
									w="60 * (pixelW * pixelGrid * 	0.50)";
									h="(	5 + 2) * (pixelH * pixelGrid * 	0.50)";
									colorBackground[]={0.2,0.2,0.2,1};
								};
								class Delete: ctrlButtonToolbar
								{
									idc=85;
									text="\a3\3DEN\Data\Displays\Display3DEN\PanelLeft\entityList_delete_ca.paa";
									x="1 * (pixelW * pixelGrid * 	0.50)";
									y="(pixelH * pixelGrid * 	0.50)";
									w="5 * (pixelW * pixelGrid * 	0.50)";
									h="5 * (pixelH * pixelGrid * 	0.50)";
									tooltip="$STR_3DEN_Delete";
								};
								class EditLayer: Delete
								{
									idc=84;
									text="\a3\3DEN\Data\Displays\Display3DEN\PanelLeft\entityList_layer_ca.paa";
									x="(	60 - 4 * 	5 - 5) * (pixelW * pixelGrid * 	0.50)";
									tooltip="$STR_3DEN_Display3DEN_EditLayer_tooltip";
								};
								class RemoveLayer: Delete
								{
									idc=86;
									text="\a3\3DEN\Data\Displays\Display3DEN\PanelLeft\entityList_layerRemove_ca.paa";
									x="(	60 - 3 * 	5 - 4) * (pixelW * pixelGrid * 	0.50)";
									tooltip="$STR_3DEN_Display3DEN_RemoveLayer_tooltip";
								};
								class EnableLayer: Delete
								{
									idc=1065;
									text="\a3\3DEN\Data\Displays\Display3DEN\PanelLeft\entityList_layerEnable_ca.paa";
									x="(	60 - 2 * 	5 - 2) * (pixelW * pixelGrid * 	0.50)";
									tooltip="$STR_3DEN_Display3DEN_EnableLayer_tooltip";
									onButtonClick="'EnableLayer' call bis_fnc_3DENInterface;";
								};
								class ShowLayer: Delete
								{
									idc=1064;
									text="\a3\3DEN\Data\Displays\Display3DEN\PanelLeft\entityList_layerShow_ca.paa";
									x="(	60 - 1 * 	5 - 1) * (pixelW * pixelGrid * 	0.50)";
									tooltip="$STR_3DEN_Display3DEN_ShowLayer_tooltip";
									onButtonClick="'ShowLayer' call bis_fnc_3DENInterface;";
								};
							};
						};
					};
				};
				class PanelLeftLocations: ctrlControlsGroupNoScrollbars
				{
					idc=1038;
					x=0;
					y="(	5 + 1) * (pixelH * pixelGrid * 	0.50)";
					w="60 * (pixelW * pixelGrid * 	0.50)";
					h="safezoneH - (		5 + 	(	5 + 2) + 	(	5 + 1) + 		4) * (pixelH * pixelGrid * 	0.50)";
					show=0;
					class Controls
					{
						class PanelLeftLocationsBackground: ctrlStatic
						{
							w="60 * (pixelW * pixelGrid * 	0.50)";
							h="(	5 + 2) * (pixelH * pixelGrid * 	0.50)";
							colorBackground[]={0.2,0.2,0.2,1};
						};
						class SearchLocations: ctrlEdit
						{
							idc=1042;
							x="1 * (pixelW * pixelGrid * 	0.50)";
							y="(pixelH * pixelGrid * 	0.50)";
							w="(	60 - 	5 - 2) * (pixelW * pixelGrid * 	0.50)";
							h="5 * (pixelH * pixelGrid * 	0.50)";
							text="";
						};
						class SearchLocationsButton: ctrlButton
						{
							idc=1043;
							style="0x02 + 0x30 + 0x800";
							text="\a3\3DEN\Data\Displays\Display3DEN\search_start_ca.paa";
							textSearch="\a3\3DEN\Data\Displays\Display3DEN\search_end_ca.paa";
							x="(	60 - 	5 - 1) * (pixelW * pixelGrid * 	0.50)";
							y="(pixelH * pixelGrid * 	0.50)";
							w="5 * (pixelW * pixelGrid * 	0.50)";
							h="5 * (pixelH * pixelGrid * 	0.50)";
						};
						class Locations: ctrlTree
						{
							idc=75;
							x=0;
							y="(	5 + 2) * (pixelH * pixelGrid * 	0.50)";
							w="60 * (pixelW * pixelGrid * 	0.50)";
							h="safezoneH - (		5 + 	(	5 + 2) + 	(	5 + 1) + 		4 + 	5 + 2 + 1 + 	5) * (pixelH * pixelGrid * 	0.50)";
							sizeEx="3.96 * (1 / (getResolution select 3)) * pixelGrid * 0.5";
							font="RobotoCondensedLight";
							colorBorder[]={0,0,0,0};
							onTreeDblClick="['select',_this] call bis_fnc_3DENListLocations;";
							disableKeyboardSearch=1;
							expandOnDoubleclick=0;
							idcSearch=1042;
						};
					};
				};
			};
		};
		class TabRightToggle: TabLeftToggle
		{
			idc=1034;
			x="safezoneX + safezoneW - 	(	5 + 1) * (pixelW * pixelGrid * 	0.50)";
			text="«";
			onbuttonclick="'ShowPanelRight' call bis_fnc_3DENInterface";
		};
		class PanelRight: ctrlControlsGroupNoScrollbars
		{
			idc=1021;
			x="safezoneX + safezoneW - 	60 * (pixelW * pixelGrid * 	0.50)";
			y="safezoneY + (	5 + 	(	5 + 2)) * (pixelH * pixelGrid * 	0.50)";
			w="60 * (pixelW * pixelGrid * 	0.50)";
			h="safezoneH - (		5 + 	(	5 + 2) + 	10) * (pixelH * pixelGrid * 	0.50)";
			class Controls
			{
				class TabRightBackground: ctrlStatic
				{
					x=0;
					y=0;
					w="60 * (pixelW * pixelGrid * 	0.50)";
					h="(	5 + 1) * (pixelH * pixelGrid * 	0.50)";
					colorBackground[]={0.1,0.1,0.1,1};
				};
				class TabRightToggle: ctrlButton
				{
					idc=1034;
					style=2;
					x="(	60 - 	(	5 + 1)) * (pixelW * pixelGrid * 	0.50)";
					y=0;
					w="(	5 + 1) * (pixelW * pixelGrid * 	0.50)";
					h="(	5 + 1) * (pixelH * pixelGrid * 	0.50)";
					text="»";
					sizeEx="5.58 * (1 / (getResolution select 3)) * pixelGrid * 0.5";
					colorBackground[]={0,0,0,0};
					onbuttonclick="'ShowPanelRight' call bis_fnc_3DENInterface";
				};
				class TabRightSections: ctrlToolbox
				{
					idc=1036;
					x="(pixelW * pixelGrid * 	0.50)";
					y="(pixelH * pixelGrid * 	0.50)";
					w="(	60 - 	(	5 + 1) - 1) * (pixelW * pixelGrid * 	0.50)";
					h="5 * (pixelH * pixelGrid * 	0.50)";
					font="RobotoCondensedLight";
					columns=2;
					strings[]=
					{
						"$STR_3DEN_Display3DEN_Assets",
						"$STR_3DEN_Display3DEN_History"
					};
					colorBackground[]={0,0,0,0};
					colorSelectedBg[]={0.2,0.2,0.2,1};
					onToolBoxSelChanged="['tabRight',_this select 1] call bis_fnc_3DENInterface;";
				};
				class PanelRightBackground: ctrlStatic
				{
					idc=1022;
					x=0;
					y="(	5 + 1) * (pixelH * pixelGrid * 	0.50)";
					w="60 * (pixelW * pixelGrid * 	0.50)";
					h="safezoneH - (		5 + 	(	5 + 2) + 	10 + 	(	5 + 1)) * (pixelH * pixelGrid * 	0.50)";
					colorBackground[]={0.2,0.2,0.2,0.87};
				};
				class PanelRightCreate: ctrlControlsGroupNoScrollbars
				{
					idc=1039;
					x=0;
					y="(	5 + 1) * (pixelH * pixelGrid * 	0.50)";
					w="60 * (pixelW * pixelGrid * 	0.50)";
					h="safezoneH - (		5 + 	(	5 + 2) + 	10 + 	(	5 + 1)) * (pixelH * pixelGrid * 	0.50)";
					class Controls
					{
						class PanelRightCreateBackground: ctrlStatic
						{
							w="60 * (pixelW * pixelGrid * 	0.50)";
							h="26 * (pixelH * pixelGrid * 	0.50)";
							colorBackground[]={0.2,0.2,0.2,1};
						};
						class ModeLabels: ctrlToolbox
						{
							idc=1060;
							x=0;
							y="2 * pixelH";
							w="60 * (pixelW * pixelGrid * 	0.50)";
							h="3 * (pixelH * pixelGrid * 	0.50)";
							rows=1;
							columns=6;
							strings[]=
							{
								"F1",
								"F2",
								"F3",
								"F4",
								"F5",
								"F6"
							};
							sizeEx="3.96 * (1 / (getResolution select 3)) * pixelGrid * 0.5";
							colorBackground[]={0,0,0,0};
							colorText[]={1,1,1,0.25};
							colorTextSelect[]={1,1,1,1};
							colorSelectedBg[]={0,0,0,0};
							onLoad="(_this select 0) ctrlenable false;";
						};
						class Modes: ctrlToolboxPictureKeepAspect
						{
							idc=53;
							x=0;
							y="3 * (pixelH * pixelGrid * 	0.50)";
							w="60 * (pixelW * pixelGrid * 	0.50)";
							h="7 * (pixelH * pixelGrid * 	0.50)";
							rows=1;
							columns=6;
							strings[]=
							{
								"\a3\3DEN\Data\Displays\Display3DEN\PanelRight\modeObjects_ca.paa",
								"\a3\3DEN\Data\Displays\Display3DEN\PanelRight\modeGroups_ca.paa",
								"\a3\3DEN\Data\Displays\Display3DEN\PanelRight\modeTriggers_ca.paa",
								"\a3\3DEN\Data\Displays\Display3DEN\PanelRight\modeWaypoints_ca.paa",
								"\a3\3DEN\Data\Displays\Display3DEN\PanelRight\modeModules_ca.paa",
								"\a3\3DEN\Data\Displays\Display3DEN\PanelRight\modeMarkers_ca.paa"
							};
							tooltips[]=
							{
								"$STR_3DEN_Object_textPlural",
								"$STR_3DEN_Group_textPlural",
								"$STR_3DEN_Trigger_textPlural",
								"$STR_3DEN_Waypoint_textPlural",
								"$STR_3DEN_Logic_textPlural",
								"$STR_3DEN_Marker_textPlural"
							};
							values[]={0,1,2,3,4,5,6};
							colorBackground[]={0,0,0,0};
							colorText[]={1,1,1,0.25};
							colorTextSelect[]={1,1,1,1};
							colorSelectedBg[]={0,0,0,0};
						};
						class Sides: Modes
						{
							idc=54;
							y="10 * (pixelH * pixelGrid * 	0.50)";
							w="60 * (pixelW * pixelGrid * 	0.50)";
							h="10 * (pixelH * pixelGrid * 	0.50)";
							columns=5;
							strings[]={};
							values[]={};
						};
						class Create: ctrlControlsGroupNoScrollbars
						{
							idc=1049;
							x=0;
							y="19 * (pixelH * pixelGrid * 	0.50)";
							w="60 * (pixelW * pixelGrid * 	0.50)";
							h="safezoneH - (	(		5 + 	(	5 + 2) + 	(	5 + 1) + 	10) + 14 + 	5) * (pixelH * pixelGrid * 	0.50)";
							class Controls
							{
								class ModsButton: ctrlCombo
								{
									idc=4242;
									tooltip="$STR_3DEN_Display3DEN_ModsButton";
									x="(pixelW * pixelGrid * 	0.50)";
									y="(pixelH * pixelGrid * 	0.50)";
									w="5 * (pixelW * pixelGrid * 	0.50)";
									h="5 * (pixelH * pixelGrid * 	0.50)";
									onLoad="				_ctrlMods = _this select 0;				_mods = [];				{_mods pushBackUnique (configsourcemod _x)} foreach configProperties [configfile >> 'CfgPatches'];				{					_params = if (_x == '') then {[]} else {modParams [_x,['name','logoSmall']]};					if (count _params > 0) then {						_lbAdd = _ctrlMods lbadd (_params select 0);						_ctrlMods lbsetdata [_lbAdd,_x];						_ctrlMods lbsetpictureright [_lbAdd,(_params select 1)];						_ctrlMods lbsettooltip [_lbAdd,(_params select 0) + '\n' + _x];					};				} foreach _mods;				lbsort _ctrlMods;			";
									onLBSelChanged="				_ctrlMods = _this select 0;				(ctrlparent _ctrlMods displayctrl 82) ctrlsettext format ['mod %1',_ctrlMods lbdata (_this select 1)];			";
								};
								class SearchCreate: ctrlEdit
								{
									idc=82;
									x="(1 + 	5) * (pixelW * pixelGrid * 	0.50)";
									y="1 * (pixelH * pixelGrid * 	0.50)";
									w="(	60 - 4 * 	5 - 1) * (pixelW * pixelGrid * 	0.50)";
									h="5 * (pixelH * pixelGrid * 	0.50)";
								};
								class SearchCreateButton: ctrlButtonSearch
								{
									idc=83;
									x="(	60 - 3 * 	5) * (pixelW * pixelGrid * 	0.50)";
									y="1 * (pixelH * pixelGrid * 	0.50)";
									w="5 * (pixelW * pixelGrid * 	0.50)";
									h="5 * (pixelH * pixelGrid * 	0.50)";
									onLoad="['showShortcut','SearchCreate',_this] call bis_fnc_3DENInterface;";
									tooltip="$STR_3DEN_Display3DEN_SearchCreateButton_tooltip";
								};
								class CollapseAllButton: ctrlButtonCollapseAll
								{
									idc=-1;
									x="(	60 - 2 * 	5) * (pixelW * pixelGrid * 	0.50)";
									y="1 * (pixelH * pixelGrid * 	0.50)";
									w="5 * (pixelW * pixelGrid * 	0.50)";
									h="5 * (pixelH * pixelGrid * 	0.50)";
									onButtonClick="['collapseAssetBrowser'] call bis_fnc_3DENInterface;";
								};
								class ExpandAllButton: ctrlButtonExpandAll
								{
									idc=-1;
									x="(	60 - 1 * 	5) * (pixelW * pixelGrid * 	0.50)";
									y="1 * (pixelH * pixelGrid * 	0.50)";
									w="5 * (pixelW * pixelGrid * 	0.50)";
									h="5 * (pixelH * pixelGrid * 	0.50)";
									onButtonClick="['expandAssetBrowser'] call bis_fnc_3DENInterface;";
								};
								class CreateObjectWEST: ctrlTree
								{
									idc=56;
									y="(	5 + 2) * (pixelH * pixelGrid * 	0.50)";
									w="60 * (pixelW * pixelGrid * 	0.50)";
									h="safezoneH - (	(		5 + 	(	5 + 2) + 	(	5 + 1) + 	10) + 21 + 	5 + (	5 + 2)) * (pixelH * pixelGrid * 	0.50)";
									defaultItem[]=
									{
										"BLU_F",
										"EdSubcat_Personnel"
									};
									sizeEx="3.96 * (1 / (getResolution select 3)) * pixelGrid * 0.5";
									font="RobotoCondensedLight";
									multiselectEnabled=0;
									colorBackground[]={0,0,0,0};
									colorBorder[]={0,0,0,0};
									ontreeSelChanged="['place',_this] call bis_fnc_3DENControlsHint;";
									onMouseButtonDown="['mousebuttondown',_this] call bis_fnc_3DENControlsHint;";
									onMouseButtonUp="['mousebuttonup',_this] call bis_fnc_3DENControlsHint;";
									disableKeyboardSearch=1;
								};
								class CreateObjectEAST: CreateObjectWEST
								{
									idc=57;
									defaultItem[]=
									{
										"OPF_F",
										"EdSubcat_Personnel"
									};
								};
								class CreateObjectGUER: CreateObjectWEST
								{
									idc=58;
									defaultItem[]=
									{
										"IND_F",
										"EdSubcat_Personnel"
									};
								};
								class CreateObjectCIV: CreateObjectWEST
								{
									idc=59;
									defaultItem[]=
									{
										"CIV_F",
										"EdSubcat_Personnel"
									};
								};
								class CreateObjectEMPTY: CreateObjectWEST
								{
									idc=60;
									defaultItem[]=
									{
										"Default"
									};
									h="safezoneH - (	(		5 + 	(	5 + 2) + 	(	5 + 1) + 	10) + 21 + 	5) * (pixelH * pixelGrid * 	0.50)";
								};
								class CreateGroupWEST: CreateObjectEMPTY
								{
									idc=61;
									defaultItem[]=
									{
										"BLU_F",
										"Infantry"
									};
								};
								class CreateGroupEAST: CreateObjectEMPTY
								{
									idc=62;
									defaultItem[]=
									{
										"OPF_F",
										"Infantry"
									};
								};
								class CreateGroupGUER: CreateObjectEMPTY
								{
									idc=63;
									defaultItem[]=
									{
										"IND_F",
										"Infantry"
									};
								};
								class CreateGroupCIV: CreateObjectEMPTY
								{
									idc=64;
									defaultItem[]={};
								};
								class CreateGroupEMPTY: CreateObjectEMPTY
								{
									idc=65;
									defaultItem[]={};
								};
								class CreateGroupCUSTOM: CreateObjectWEST
								{
									idc=71;
									defaultItem[]={};
								};
								class CreateTrigger: CreateObjectEMPTY
								{
									idc=68;
									defaultItem[]={};
									show=0;
								};
								class CreateWaypoint: CreateObjectEMPTY
								{
									idc=6900000;
									defaultItem[]={};
								};
								class CreateObjectLogic: CreateObjectEMPTY
								{
									idc=66;
									defaultItem[]=
									{
										"Objects"
									};
								};
								class CreateObjectModule: CreateObjectEMPTY
								{
									idc=67;
									defaultItem[]={};
								};
								class CreateMarkerIcon: CreateObjectEMPTY
								{
									idc=69;
									defaultItem[]=
									{
										"Military"
									};
								};
								class CreateMarkerArea: CreateObjectEMPTY
								{
									idc=70;
									defaultItem[]={};
								};
								class VehiclePanel: ctrlControlsGroupNoScrollbars
								{
									idc=1062;
									show=0;
									y="safezoneH - (	(		5 + 	(	5 + 2) + 	(	5 + 1) + 	10) + 14 + 	5 + (	5 + 2)) * (pixelH * pixelGrid * 	0.50)";
									w="60 * (pixelW * pixelGrid * 	0.50)";
									h="(	5 + 2) * (pixelH * pixelGrid * 	0.50)";
									class Controls
									{
										class Background: ctrlStatic
										{
											w="60 * (pixelW * pixelGrid * 	0.50)";
											h="(	5 + 2) * (pixelH * pixelGrid * 	0.50)";
											colorBackground[]={0.2,0.2,0.2,1};
										};
										class ToggleEmpty: ctrlCheckbox
										{
											idc=1063;
											x="1 * (pixelW * pixelGrid * 	0.50)";
											y="(pixelH * pixelGrid * 	0.50)";
											w="5 * (pixelW * pixelGrid * 	0.50)";
											h="5 * (pixelH * pixelGrid * 	0.50)";
											onCheckedChanged="do3DENAction 'TogglePlaceEmptyVehicle';";
										};
										class TextEmpty: ctrlStatic
										{
											text="$STR_3DEN_Display3DEN_VehiclePanel_TextEmpty_text";
											shadow=0;
											x="(	5 + 1) * (pixelW * pixelGrid * 	0.50)";
											y="(pixelH * pixelGrid * 	0.50)";
											w="(	60 - (	5 + 1)) * (pixelW * pixelGrid * 	0.50)";
											h="5 * (pixelH * pixelGrid * 	0.50)";
										};
									};
								};
								class CustomCompositionPanel: ctrlControlsGroupNoScrollbars
								{
									idc=1061;
									show=0;
									y="safezoneH - (	(		5 + 	(	5 + 2) + 	(	5 + 1) + 	10) + 14 + 	5 + (	5 + 2)) * (pixelH * pixelGrid * 	0.50)";
									w="60 * (pixelW * pixelGrid * 	0.50)";
									h="(	5 + 2) * (pixelH * pixelGrid * 	0.50)";
									class Controls
									{
										class Background: ctrlStatic
										{
											w="60 * (pixelW * pixelGrid * 	0.50)";
											h="(	5 + 2) * (pixelH * pixelGrid * 	0.50)";
											colorBackground[]={0.2,0.2,0.2,1};
										};
										class Add: ctrlButtonToolbar
										{
											idc=90;
											text="\a3\3DEN\Data\Displays\Display3DEN\PanelRight\customcomposition_add_ca.paa";
											x="1 * (pixelW * pixelGrid * 	0.50)";
											y="(pixelH * pixelGrid * 	0.50)";
											w="5 * (pixelW * pixelGrid * 	0.50)";
											h="5 * (pixelH * pixelGrid * 	0.50)";
											tooltip="$STR_3DEN_Display3DEN_CustomCompositionPanel_Add_tooltip";
											onButtonClick="do3denaction 'createcustomcomposition';";
										};
										class Edit: Add
										{
											idc=91;
											text="\a3\3DEN\Data\Displays\Display3DEN\PanelRight\customcomposition_edit_ca.paa";
											x="(1 * 	5 + 2) * (pixelW * pixelGrid * 	0.50)";
											tooltip="$STR_3DEN_Display3DEN_CustomCompositionPanel_Edit_tooltip";
											onButtonClick="do3denaction 'editcustomcomposition';";
										};
										class Publish: Add
										{
											idc=93;
											text="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\steam_ca.paa";
											x="(2 * 	5 + 3) * (pixelW * pixelGrid * 	0.50)";
											tooltip="$STR_3DEN_Display3DEN_CustomCompositionPanel_Publish_tooltip";
											onLoad="(_this select 0) ctrlenable false;";
										};
										class Delete: Add
										{
											idc=92;
											text="\a3\3DEN\Data\Displays\Display3DEN\PanelLeft\entityList_delete_ca.paa";
											x="(	60 - 	5 - 1) * (pixelW * pixelGrid * 	0.50)";
											tooltip="$STR_3DEN_Display3DEN_CustomCompositionPanel_Delete_tooltip";
											onButtonClick="do3denaction 'deletecustomcomposition';";
										};
									};
								};
							};
						};
					};
				};
				class PanelRightHistory: ctrlControlsGroupNoScrollbars
				{
					idc=1040;
					x=0;
					y="(	5 + 1) * (pixelH * pixelGrid * 	0.50)";
					w="60 * (pixelW * pixelGrid * 	0.50)";
					h="safezoneH - (		5 + 	(	5 + 2) + 	10 + 	(	5 + 1)) * (pixelH * pixelGrid * 	0.50)";
					show=0;
					class Controls
					{
						class PanelRightHistoryBackground: ctrlStatic
						{
							w="60 * (pixelW * pixelGrid * 	0.50)";
							h="1 * (pixelH * pixelGrid * 	0.50)";
							colorBackground[]={0.2,0.2,0.2,1};
						};
						class History: ctrlListbox
						{
							idc=74;
							x=0;
							y="1 * (pixelH * pixelGrid * 	0.50)";
							w="60 * (pixelW * pixelGrid * 	0.50)";
							h="safezoneH - (		5 + 	(	5 + 2) + 	10 + 	(	5 + 1) + 1) * (pixelH * pixelGrid * 	0.50)";
							sizeEx="3.96 * (1 / (getResolution select 3)) * pixelGrid * 0.5";
							rowHeight="3.96 * (1 / (getResolution select 3)) * pixelGrid * 0.5";
							colorBackground[]={0,0,0,0};
						};
					};
				};
			};
		};
		class EditorPreviewGroup: ctrlControlsGroupNoScrollbars
		{
			idc=98;
			x="safezoneX + safezoneW - (	60 + 	27 * 16/9 + 1) * (pixelW * pixelGrid * 	0.50)";
			y="safezoneY + (	5 + 	(	5 + 2)) * (pixelH * pixelGrid * 	0.50)";
			w="27 * 16/9 * (pixelW * pixelGrid * 	0.50)";
			h="27 * (pixelH * pixelGrid * 	0.50)";
			class Controls
			{
				class Background: ctrlStatic
				{
					x=0;
					y=0;
					w=1;
					h=1;
					colorBackground[]={0.2,0.2,0.2,0.87};
				};
				class EditorPreview: ctrlStaticPictureKeepAspect
				{
					idc=99;
					text="#(argb,8,8,3)color(1,0,1,1)";
					x="(pixelW * pixelGrid * 	0.50)";
					y="(pixelH * pixelGrid * 	0.50)";
					w="(	27 - 2) * (pixelW * pixelGrid * 	0.50)";
					h="(	27 - 2) * (pixelH * pixelGrid * 	0.50)";
				};
			};
		};
		class ButtonPlay: ctrlShortcutButton
		{
			idc=1023;
			x="safezoneX + safezoneW - 	60 * (pixelW * pixelGrid * 	0.50)";
			y="safezoneY + safezoneH - 	10 * (pixelH * pixelGrid * 	0.50)";
			w="60 * (pixelW * pixelGrid * 	0.50)";
			h="10 * (pixelH * pixelGrid * 	0.50) + pixelH";
			size="2.88 * (1 / (getResolution select 3)) * pixelGrid * 0.5";
			onButtonClick="if !(is3DENMultiplayer) then {do3DENAction 'MissionPreview';} else {do3DENAction 'MissionPreviewMP';};";
			shadow=0;
			color2[]={0,0,0,1};
			colorFocused[]={0,0,0,1};
			colorBackground[]={1,1,1,1};
			animTextureNormal="\a3\3DEN\Data\Displays\Display3DEN\PanelRight\playNormal_ca.paa";
			animTexturePressed="\a3\3DEN\Data\Displays\Display3DEN\PanelRight\playNormal_ca.paa";
			animTextureOver="\a3\3DEN\Data\Displays\Display3DEN\PanelRight\playOver_ca.paa";
			animTextureFocused="\a3\3DEN\Data\Displays\Display3DEN\PanelRight\playOver_ca.paa";
			animTextureDisabled="\a3\3DEN\Data\Displays\Display3DEN\PanelRight\playDisabled_ca.paa";
			class Attributes: Attributes
			{
				align="right";
			};
			class TextPos: TextPos
			{
				top=0;
				right="60 * (pixelW * pixelGrid * 	0.50) * 0.2";
			};
			onLoad="['ButtonPlay',_this select 0] call (uinamespace getvariable 'bis_fnc_3DENInterface');";
		};
		class ControlsHint: ctrlListbox
		{
			idc=1044;
			x="safezoneX + safezoneW - (	60 + 	50) * (pixelW * pixelGrid * 	0.50)";
			y="safezoneY + safezoneH - 		4 * (pixelH * pixelGrid * 	0.50)";
			w="50 * (pixelW * pixelGrid * 	0.50)";
			h="5 * (pixelH * pixelGrid * 	0.50) * 10";
			colorBackground[]={0.2,0.2,0.2,0.5};
			colorDisabled[]={1,1,1,1};
			colorTextRight[]={1,1,1,0.5};
			colorPictureDisabled[]={1,1,1,1};
			colorPictureRightDisabled[]={1,1,1,1};
			font="RobotoCondensedLight";
			sizeEx="3.96 * (1 / (getResolution select 3)) * pixelGrid * 0.5";
			rowHeight="5 * (pixelH * pixelGrid * 	0.50)";
			shadow=1;
		};
		class StatusBar: ctrlControlsGroupNoScrollbars
		{
			idc=1050;
			x="safezoneX";
			y="safezoneY + safezoneH - 		4 * (pixelH * pixelGrid * 	0.50)";
			w="(safezoneW - 	60 * (pixelW * pixelGrid * 	0.50))";
			h="(		4 + 1) * (pixelH * pixelGrid * 	0.50)";
			class Controls
			{
				class StatusBarBackground: ctrlStatic
				{
					idc=1051;
					x=0;
					y=0;
					w="(safezoneW - 	60 * (pixelW * pixelGrid * 	0.50))";
					h="(		4 + 1) * (pixelH * pixelGrid * 	0.50)";
					colorBackground[]={0.2,0.2,0.2,1};
				};
				class TextX: ctrlStaticPicture
				{
					y="(2 * pixelH)";
					w="3 * (pixelW * pixelGrid * 	0.50)";
					h="3 * (pixelH * pixelGrid * 	0.50)";
					sizeEx="2.88 * (1 / (getResolution select 3)) * pixelGrid * 0.5";
					text="\a3\3DEN\Data\Displays\Display3DEN\StatusBar\x_ca.paa";
					colorBackground[]={0,0,0,0};
					shadow=0;
				};
				class ValueX: ctrlEdit
				{
					idc=1052;
					style="0x01 + 0x200";
					x="3 * (pixelW * pixelGrid * 	0.50)";
					y="(2 * pixelH)";
					w="16 * (pixelW * pixelGrid * 	0.50)";
					h="4 * (pixelH * pixelGrid * 	0.50) - 2 * (2 * pixelH)";
					font="EtelkaMonospacePro";
					sizeEx="2.945 * (1 / (getResolution select 3)) * pixelGrid * 0.5";
					shadow=0;
					colorDisabled[]={1,1,1,0.5};
					onLoad="(_this select 0) ctrlenable false;";
				};
				class TextY: TextX
				{
					x="(	3 + 	16 + 	4) * (pixelW * pixelGrid * 	0.50)";
					text="\a3\3DEN\Data\Displays\Display3DEN\StatusBar\y_ca.paa";
					colorBackground[]={0,0,0,0};
				};
				class ValueY: ValueX
				{
					idc=1053;
					x="((	3 + 	16 + 	4) + 	3) * (pixelW * pixelGrid * 	0.50)";
				};
				class TextZ: TextX
				{
					x="2 * (	3 + 	16 + 	4) * (pixelW * pixelGrid * 	0.50)";
					text="\a3\3DEN\Data\Displays\Display3DEN\StatusBar\z_ca.paa";
					colorBackground[]={0,0,0,0};
				};
				class ValueZ: ValueX
				{
					idc=1054;
					x="(2 * (	3 + 	16 + 	4) + 	3) * (pixelW * pixelGrid * 	0.50)";
				};
				class TextDis: TextX
				{
					x="3 * (	3 + 	16 + 	4) * (pixelW * pixelGrid * 	0.50)";
					text="\a3\3DEN\Data\Displays\Display3DEN\StatusBar\dis_ca.paa";
					colorBackground[]={0,0,0,0};
				};
				class ValueDis: ValueX
				{
					idc=1055;
					x="(3 * (	3 + 	16 + 	4) + 	3) * (pixelW * pixelGrid * 	0.50)";
					w="30 * (pixelW * pixelGrid * 	0.50)";
				};
				class Version: ValueX
				{
					idc=1057;
					x="(safezoneW - 	60 * (pixelW * pixelGrid * 	0.50)) - (2 * 		4 + 21) * (pixelW * pixelGrid * 	0.50)";
					w="20 * (pixelW * pixelGrid * 	0.50)";
					onLoad="";
					canModify=0;
				};
				class Mod: ctrlStaticPicture
				{
					idc=1058;
					x="(safezoneW - 	60 * (pixelW * pixelGrid * 	0.50)) - 2 * 		4 * (pixelW * pixelGrid * 	0.50)";
					w="4 * (pixelW * pixelGrid * 	0.50)";
					h="4 * (pixelH * pixelGrid * 	0.50)";
					text="\a3\3DEN\Data\Displays\Display3DEN\StatusBar\mod_ca.paa";
				};
				class Server: ctrlStaticPicture
				{
					idc=1059;
					x="(safezoneW - 	60 * (pixelW * pixelGrid * 	0.50)) - 		4 * (pixelW * pixelGrid * 	0.50)";
					w="4 * (pixelW * pixelGrid * 	0.50)";
					h="4 * (pixelH * pixelGrid * 	0.50)";
					text="\a3\3DEN\Data\Displays\Display3DEN\StatusBar\server_ca.paa";
				};
			};
		};
	};
};