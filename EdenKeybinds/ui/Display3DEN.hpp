
class Display3DEN
{
	class ContextMenu: ctrlMenu
	{
		idc=1100;
		colorBackground[]={0.1,0.1,0.1,1};
		class Items
		{

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
//			class ConnectParent
//			{
//
//				text="$STR_3DEN_Display3DEN_EntityMenu_ConnectParent_text";
//				value=0;
//			};
			class Connect
			{
				data="Connect";
				shortcuts[]={"profilenamespace getvariable [ 'Eden_key_EntitySync', nil ]"};
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
//			class Select
//			{
//				text="$STR_3DEN_Display3DEN_EntityMenu_Select_text";
//				value=0;
//
//			};
			class SelectView
			{
				text="$STR_3DEN_Display3DEN_EntityMenu_SelectView_text";
				data="SelectAllOnScreen";
				value=0;
				conditionShow="(1 - (isEditList))";
				shortcuts[]={"profilenamespace getvariable [ 'Eden_key_EntitySelectScreen', ( 512 + 0x1E ) ]"};
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
//			class Edit
//			{
//				text="$STR_3DEN_Display3DEN_MenUBar_Edit_text";
//				value=0;
//
//			};
			class Cut
			{
				text="$STR_3DEN_Display3DEN_MenuBar_EntityCut_text";
				data="CutUnit";
				value=0;
				conditionEnable="selected";
				shortcuts[]={"profilenamespace getvariable [ 'Eden_key_EntityCut', ( 512 + 0x2D ) ]"};
			};
			class Copy
			{
				text="$STR_3DEN_Display3DEN_MenuBar_EntityCopy_text";
				data="CopyUnit";
				value=0;
				conditionEnable="selected";
				shortcuts[]={"profilenamespace getvariable [ 'Eden_key_EntityCopy', ( 512 + 0x2E ) ]"};
			};
			class Paste
			{
				text="$STR_3DEN_Display3DEN_MenuBar_EntityPaste_text";
				data="PasteItems";
				value=0;
				shortcuts[]={"profilenamespace getvariable [ 'Eden_key_EntityPaste', ( 512 + 0x2F ) ]"};
			};
			class PasteOrig
			{
				text="$STR_3DEN_Display3DEN_MenuBar_EntityPasteOrig_text";
				data="PasteUnitOrig";
				value=0;
				shortcuts[]={"profilenamespace getvariable [ 'Eden_key_EntityPasteOrig', ( 512 + 1024 + 0x2F ) ]"};
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
//			class Transform
//			{
//				text="$STR_3DEN_Display3DEN_EntityMenu_Transform_text";
//				value=0;
//				conditionShow="hoverObject 	+ hoverGroup";
//
//			};
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
				action="[] call LARs_fnc_snapToGround";
				shortcuts[]={"profilenamespace getvariable [ 'Eden_key_EntitySnapToSurface', nil ]"};
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
//			class Grid
//			{
//				text="$STR_3DEN_Display3DEN_MenuBar_Grid_text";
//				value=0;
//				conditionShow="hoverObject";
//
//			};
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
//			class ChangeSeatParent
//			{
//
//				text="$STR_3DEN_Display3DEN_EntityMenu_ChangeSeat_text";
//				value=0;
//			};
			class ChangeSeat
			{
				data="ChangeSeat";
			};
//			class Log
//			{
//				text="$STR_3DEN_Display3DEN_EntityMenu_Log_text";
//				value=0;
//
//			};
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

	class Controls
	{
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

//				class File
//				{
//					text="$STR_3DEN_Scenario";
//
//					data="test1";
//					value=1;
//				};
				class MissionNew
				{
					text="$STR_3DEN_Display3DEN_MenuBar_MissionNew_text";
					data="MissionNew";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_MissionNew', ( 512 + 0x31 ) ]"};
					picture="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\new_ca.paa";
					opensNewWindow=1;
				};
				class MissionOpen
				{
					text="$STR_3DEN_Display3DEN_MenuBar_MissionOpen_text";
					data="MissionLoad";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_MissionOpen', ( 512 + 0x18 ) ]"};
					picture="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\open_ca.paa";
					opensNewWindow=1;
				};
				class MissionSave
				{
					text="$STR_3DEN_Display3DEN_MenuBar_MissionSave_text";
					data="MissionSave";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_MissionSave', ( 512 + 0x1F ) ]"};
					picture="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\save_ca.paa";
				};
				class MissionSaveAs
				{
					text="$STR_3DEN_Display3DEN_MenuBar_MissionSaveAs_text";
					data="MissionSaveAs";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_MissionSaveAs', ( 512 + 	1024 + 0x1F ) ]"};
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
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_MissionPublishSteam', nil ]"};
				};
//				class MissionExport
//				{
//					text="$STR_3DEN_Display3DEN_MenuBar_MissionExport_text";
//
//				};
				class MissionExportSP
				{
					text="$STR_3DEN_Display3DEN_MenuBar_MissionExportSP_text";
					data="MissionExportSP";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_MissionExportSP', nil ]"};

				};
				class MissionExportMP
				{
					text="$STR_3DEN_Display3DEN_MenuBar_MissionExportMP_text";
					data="MissionExportMP";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_MissionSave', nil ]"};
				};
				class MissionTerrainBuilder
				{
					text="$STR_3DEN_Display3DEN_MenuBar_MissionTerrainBuilder_text";
					data="MissionExportTerrainBuilder";
					action="[] spawn bis_fnc_3DENExportTerrainBuilder;";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_MissionSave', nil ]"};
				};
				class MissionMerge
				{
					text="$STR_3DEN_Display3DEN_MenuBar_MissionMerge_text";
					data="MissionMerge";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_MissionMerge', ( 512 + 0x32 ) ]"};
				};
				class MissionFolder
				{
					text="$STR_3DEN_Display3DEN_MenuBar_MissionFolder_text";
					data="FolderMission";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_MissionFolder', nil ]"};
				};
				class MissionAddons
				{
					text="$STR_3DEN_Display3DEN_MenuBar_MissingAddons_text";
					data="OpenRequiredAddons";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_MissionAddons', nil ]"};
				};
				class LogFolder
				{
					text="$STR_3DEN_Display3DEN_MenuBar_LogFolder_text";
					data="FolderLog";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_LogFolder', nil ]"};
				};
				class Exit
				{
					text="$STR_3DEN_Display3DEN_MenuBar_Exit_text";
					data="Exit3DEN";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_Exit', nil ]"};
				};
//				class Edit
//				{
//					text="$STR_3DEN_Display3DEN_MenuBar_Edit_text";
//
//				};
				class Undo
				{
					text="$STR_3DEN_Display3DEN_MenuBar_Undo_text";
					data="Undo";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_Undo', ( 512 + 0x2C ) ]"};
					picture="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\undo_ca.paa";
				};
				class Redo
				{
					text="$STR_3DEN_Display3DEN_MenuBar_Redo_text";
					data="Redo";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_Redo', ( 512 + 0x15 ) ]"};
					picture="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\redo_ca.paa";
				};
				class EntitySelectScreen
				{
					text="$STR_3DEN_Display3DEN_MenuBar_EntitySelectScreen_text";
					data="SelectAllOnScreen";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_EntitySelectScreen', ( 512 + 0x1E ) ]"};
				};
				class EntityCut
				{
					text="$STR_3DEN_Display3DEN_MenuBar_EntityCut_text";
					data="CutUnit";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_EntityCut', ( 512 + 0x2D ) ]"};
				};
				class EntityCopy
				{
					text="$STR_3DEN_Display3DEN_MenuBar_EntityCopy_text";
					data="CopyUnit";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_EntityCopy', ( 512 + 0x2E ) ]"};
				};
				class EntityPaste
				{
					text="$STR_3DEN_Display3DEN_MenuBar_EntityPaste_text";
					data="PasteUnit";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_EntityPaste', ( 512 + 0x2F ) ]"};
				};
				class EntityPasteOrig
				{
					text="$STR_3DEN_Display3DEN_MenuBar_EntityPasteOrig_text";
					data="PasteUnitOrig";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_EntityPasteOrig', ( 512 + 	1024 + 0x2F ) ]"};
				};
				class EntitySimulation
				{
					xtext="$STR_3DEN_Display3DEN_MenuBar_EntitySimulation_text";
					data="SimulateUnit";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_EntitySimulation', ( 512 + 0x19 ) ]"};
					enable=0;
				};
//				class Widget
//				{
//					text="$STR_3DEN_Display3DEN_MenuBar_Widget_text";
//
//				};
				class WidgetToggle
				{
					text="$STR_3DEN_Display3DEN_MenuBar_WidgetToggle_text";
					data="WidgetToggle";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_WidgetToggle', ( 57 ) ]"};
				};
				class WidgetNone
				{
					text="$STR_3DEN_Display3DEN_MenuBar_WidgetNone_text";
					data="WidgetNone";
					picture="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_none_off_ca.paa";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_WidgetNone', ( 2 ) ]"};
				};
				class WidgetTranslation
				{
					text="$STR_3DEN_Display3DEN_MenuBar_WidgetTranslation_text";
					data="WidgetTranslation";
					picture="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_translation_off_ca.paa";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_WidgetTranslation', ( 3 ) ]"};
				};
				class WidgetRotation
				{
					text="$STR_3DEN_Display3DEN_MenuBar_WidgetRotation_text";
					data="WidgetRotation";
					picture="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_rotation_off_ca.paa";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_WidgetRotation', ( 4 ) ]"};
				};
				class WidgetScaling
				{
					text="$STR_3DEN_Display3DEN_MenuBar_WidgetScaling_text";
					data="WidgetScale";
					picture="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_scaling_off_ca.paa";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_WidgetScaling', ( 5 ) ]"};
				};
				class WidgetArea
				{
					text="$STR_3DEN_Display3DEN_MenuBar_WidgetArea_text";
					data="WidgetArea";
					picture="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_area_off_ca.paa";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_WidgetArea', ( 6 ) ]"};
				};
				class WidgetSpace
				{
					text="$STR_3DEN_Display3DEN_MenuBar_WidgetSpace_text";
					data="WidgetSpace";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_WidgetSpace', ( 34 ) ]"};
					enable=0;
				};
				class WidgetSpaceWorld
				{
					text="$STR_3DEN_Display3DEN_MenuBar_WidgetSpaceWorld_text";
					data="WidgetSpaceWorld";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_WidgetSpaceWorld', nil ]"};
					enable=0;
				};
				class WidgetSpaceLocal
				{
					text="$STR_3DEN_Display3DEN_MenuBar_WidgetSelectedEntity_text";
					data="WidgetSpaceLocal";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_WidgetSpaceLocal', nil ]"};
					enable=0;
				};
				class WidgetPosition
				{
					xtext="$STR_3DEN_Display3DEN_MenuBar_WidgetPosition_text";
					data="WidgetPosition";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_WidgetPosition', ( 34 ) ]"};
					enable=0;
				};
				class WidgetPositionEntity
				{
					xtext="$STR_3DEN_Display3DEN_MenuBar_WidgetSelectedEntity_text";
					data="WidgetPositionEntity";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_WidgetPositionEntity', nil ]"};
					enable=0;
				};
				class WidgetPositionMean
				{
					xtext="$STR_3DEN_Display3DEN_MenuBar_WidgetPositionMean_text";
					data="WidgetPositionMean";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_WidgetPositionMean', nil ]"};
					enable=0;
				};
//				class Grid
//				{
//					text="$STR_3DEN_Display3DEN_MenuBar_Grid_text";
//
//				};
				class GridTranslationToggle
				{
					text="$STR_3DEN_Display3DEN_MenuBar_GridTranslationToggle_text";
					data="MoveGridToggle";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_GridTranslationToggle', ( 39 ) ]"};
					type="CheckBox";
					default="false";
				};
				class GridRotationToggle
				{
					text="$STR_3DEN_Display3DEN_MenuBar_GridRotationToggle_text";
					data="RotateGridToggle";
					type="CheckBox";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_GridRotationToggle', nil ]"};
					default="false";
				};
				class GridScalingToggle
				{
					text="$STR_3DEN_Display3DEN_MenuBar_GridScalingToggle_text";
					data="ScaleGridToggle";
					type="CheckBox";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_GridScalingToggle', nil ]"};
					default="false";
				};
				class GridDecrease
				{
					text="$STR_3DEN_Display3DEN_MenuBar_GridDecrease_text";
					data="GridDecrease";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_GridDecrease', ( 26 ) ]"};
					action="['decrease'] call bis_fnc_3DENGrid;";
				};
				class GridIncrease
				{
					text="$STR_3DEN_Display3DEN_MenuBar_GridIncrease_text";
					data="GridIncrease";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_GridIncrease', ( 27 ) ]"};
					action="['increase'] call bis_fnc_3DENGrid;";
				};
//				class Vertical
//				{
//					text="$STR_3DEN_Display3DEN_MenuBar_Vertical_text";
//
//				};
				class VerticalToggle
				{
					text="$STR_3DEN_Display3DEN_MenuBar_VerticalToggle_text";
					data="VerticalToggle";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_VerticalToggle', ( 40 ) ]"};
				};
				class VerticalATL
				{
					text="$STR_3DEN_Display3DEN_MenuBar_VerticalATL_text";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_VerticalATL', nil ]"};
					data="VerticalATL";
				};
				class VerticalASL
				{
					text="$STR_3DEN_Display3DEN_MenuBar_VerticalASL_text";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_VerticalASL', nil ]"};
					data="VerticalASL";
				};
				class SurfaceSnapToggle
				{
					text="$STR_3DEN_Display3DEN_MenuBar_SurfaceSnapToggle_text";
					data="SurfaceSnapToggle";
					type="CheckBox";
					default="true";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_SurfaceSnapToggle', ( 43 ) ]"};
				};
				class WaypointSnapToggle
				{
					text="$STR_3DEN_Display3DEN_MenuBar_WaypointSnapToggle_text";
					data="WaypointSnapToggle";
					type="CheckBox";
					default="true";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_WaypointSnapToggle', ( 53 ) ]"};
				};
//				class Space
//				{
//					text="$STR_3DEN_Display3DEN_MenuBar_Space_text";
//
//				};
				class SpaceMission
				{
					text="$STR_3DEN_Scenario";
					data="MissionPartMission";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_SpaceMission', nil ]"};
				};
				class SpaceIntro
				{
					text="$STR_3DEN_Display3DEN_MenuBar_SpaceIntro_text";
					data="MissionPartIntro";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_SpaceIntro', nil ]"};
				};
				class SpaceOutroWin
				{
					text="$STR_3DEN_Display3DEN_MenuBar_SpaceOutroWin_text";
					data="MissionPartOutroWin";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_SpaceOutroWin', nil ]"};
				};
				class SpaceOutroLose
				{
					text="$STR_3DEN_Display3DEN_MenuBar_SpaceOutroLose_text";
					data="MissionPartOutroLoose";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_SpaceOutroLose', nil ]"};
				};
//				class Mode
//				{
//					text="$STR_3DEN_Display3DEN_MenuBar_Mode_text";
//
//				};
				class ModeObject
				{
					text="$STR_3DEN_Object_textPlural";
					data="SelectObjectMode";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_ModeObject', ( 59 ) ]"};
				};
				class ModeGroup
				{
					text="$STR_3DEN_Group_textPlural";
					data="SelectGroupMode";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_ModeGroup', ( 60 ) ]"};
				};
				class ModeTrigger
				{
					text="$STR_3DEN_Trigger_textPlural";
					data="SelectTriggerMode";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_ModeTrigger', ( 61 ) ]"};
				};
				class ModeWaypoint
				{
					text="$STR_3DEN_Waypoint_textPlural";
					data="SelectWaypointMode";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_ModeWaypoint', ( 62 ) ]"};
				};
				class ModeLogic
				{
					text="$STR_3DEN_Logic_textPlural";
					data="SelectModuleMode";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_ModeLogic', ( 63 ) ]"};
				};
				class ModeMarker
				{
					text="$STR_3DEN_Marker_textPlural";
					data="SelectMarkerMode";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_ModeMarker', ( 64 ) ]"};
				};
				class ModeFavorite
				{
					text="$STR_3DEN_Favorite_textPlural";
					data="SelectFavoritesMode";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_ModeFavorite', ( 65 ) ]"};
					enable=0;
				};
				class SubmodeToggle
				{
					text="$STR_3DEN_Display3DEN_MenuBar_SubmodeToggle_text";
					data="SubmodeToggle";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_SubmodeToggle', ( 15 ) ]"};
				};
//				class View
//				{
//					text="$STR_3DEN_Display3DEN_MenuBar_View_text";
//
//				};
				class ViewRandom
				{
					text="$STR_3DEN_Display3DEN_MenuBar_ViewRandom_text";
					data="CenterCameraOnRandom";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_ViewRandom', ( 512 + 0x13 ) ]"};
					action="'random' call bis_fnc_3DENCamera;";
				};
				class ViewSelected
				{
					text="$STR_3DEN_Display3DEN_MenuBar_ViewSelected_text";
					data="CenterCameraOnSelected";
					action="_this call bis_fnc_log; 'selected' call bis_fnc_3DENCamera;";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_ViewSelected', ( 0x21 ) ]"};
				};
				class ViewPlayer
				{
					text="$STR_3DEN_Display3DEN_MenuBar_ViewPlayer_text";
					data="CenterCameraOnPlayer";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_ViewPlayer', ( 199 ) ]"};
				};
				class Map
				{
					text="$STR_3DEN_Display3DEN_MenuBar_Map_text";
					data="ToggleMap";
					type="CheckBox";
					default="false";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_Map', ( 50 ) ]"};
				};
				class MapTextures
				{
					text="$STR_3DEN_Display3DEN_MenuBar_MapTextures_text";
					data="ToggleMapTextures";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_MapTextures', ( 512 + 0x14 ) ]"};
					type="CheckBox";
					default="false";
				};
				class MapIDs
				{
					text="$STR_3DEN_Display3DEN_MenuBar_MapIDs_text";
					data="MapIDs";
					enable=0;
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_MapIDs', nil ]"};
				};
				class ToggleLocations
				{
					text="$STR_3DEN_Display3DEN_MenuBar_ToggleLocations_text";
					data="ToggleLocations";
					action="[] call bis_fnc_3DENDrawLocations;";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_ToggleLocations', nil ]"};
				};
				class ToggleFlashlight
				{
					text="$STR_3DEN_Display3DEN_MenuBar_ToggleFlashlight_text";
					data="ToggleFlashlight";
					action="[] call bis_fnc_3DENFlashlight;";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_ToggleFlashlight', ( 38 ) ]"};
					picture="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\flashlight_off_ca.paa";
				};
				class ToggleVegetation
				{
					text="$STR_3DEN_Display3DEN_MenuBar_ToggleVegetation_text";
					data="ToggleVegetation";
					type="CheckBox";
					default="false";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_ToggleVegetation', ( 512 + 0x22 ) ]"};
				};
//				class VisionMode
//				{
//					text="$STR_3DEN_Display3DEN_MenuBar_VisionMode_text";
//					data="ViewVisionMode";
//
//				};
				class VisionModeToggle
				{
					text="$STR_3DEN_Display3DEN_MenuBar_VisionModeToggle_text";
					data="VisionModeToggle";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_VisionModeToggle', ( 49 ) ]"};
					action="-1 call BIS_fnc_3DENVisionMode;";
					picture="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\vision_normal_ca.paa";
				};
				class VisionModeNormal
				{
					text="$STR_3DEN_Display3DEN_MenuBar_VisionModeNormal_text";
					data="VisionModeNormal";
					action="0 call BIS_fnc_3DENVisionMode;";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_VisionModeNormal', nil ]"};
				};
				class VisionModeNVG
				{
					text="$STR_3DEN_Display3DEN_MenuBar_VisionModeNVG_text";
					data="VisionModeNVG";
					action="1 call BIS_fnc_3DENVisionMode;";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_VisionModeNVG', nil ]"};
				};
				class VisionModeTI
				{
					text="$STR_3DEN_Display3DEN_MenuBar_VisionModeTI_text";
					data="VisionModeTI";
					action="2 call BIS_fnc_3DENVisionMode;";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_VisionModeTI', nil ]"};
				};
//				class Search
//				{
//					text="$STR_3DEN_Display3DEN_MenuBar_Search_text";
//					data="Search";
//
//				};
				class SearchCreate
				{
					text="$STR_3DEN_Display3DEN_MenuBar_SearchCreate_text";
					data="SearchCreate";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_SearchCreate', ( 512 + 0x21 ) ]"};
				};
				class SearchEdit
				{
					text="$STR_3DEN_Display3DEN_MenuBar_SearchEdit_text";
					data="SearchEdit";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_SearchEdit', ( 512 + 1024 + 0x21 ) ]"};
				};
//				class Interface
//				{
//					text="$STR_3DEN_Display3DEN_MenuBar_Interface_text";
//					data="Interface";
//
//				};
				class InterfaceToggle
				{
					text="$STR_3DEN_Display3DEN_MenuBar_InterfaceToggle_text";
					data="InterfaceToggle";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_InterfaceToggle', ( 14 ) ]"};
					action="with uinamespace do {'showInterface' call BIS_fnc_3DENInterface;};";
				};
				class InterfacePanelLeft
				{
					text="$STR_3DEN_Display3DEN_MenuBar_InterfacePanelLeft_text";
					data="InterfacePanelLeft";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_InterfacePanelLeft', ( 18 ) ]"};
					action="with uinamespace do {'showPanelLeft' call BIS_fnc_3DENInterface;};";
				};
				class InterfacePanelRight
				{
					text="$STR_3DEN_Display3DEN_MenuBar_InterfacePanelRight_text";
					data="InterfacePanelRight";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_InterfacePanelRight', ( 19 ) ]"};
					action="with uinamespace do {'showPanelRight' call BIS_fnc_3DENInterface;};";
				};
				class InterfaceControlsHint
				{
					text="$STR_3DEN_Display3DEN_MenuBar_InterfaceControlsHint_text";
					data="InterfaceControlsHint";
					action="'toggle' call BIS_fnc_3DENControlsHint;";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_InterfaceControlsHint', nil ]"};
				};
				class InterfaceNavigationWidget
				{
					text="$STR_3DEN_Display3DEN_MenuBar_InterfaceNavigationWidget_text";
					data="InterfaceNavigationWidget";
					action="with uinamespace do {'navigationWidget' call BIS_fnc_3DENInterface;};";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_InterfaceNavigationWidget', nil ]"};
				};
//				class Attributes
//				{
//					text="$STR_3DEN_Display3DEN_MenuBar_Attributes_text";
//
//				};
				class AttributesScenario
				{
					text="$STR_3DEN_Scenario_textSingular";
					data="AttributesScenario";
					action="edit3DENMissionAttributes 'Scenario';";
					opensNewWindow=1;
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_AttributesScenario', nil ]"};
				};
				class AttributesMultiplayer
				{
					text="$STR_3DEN_Multiplayer_textSingular";
					data="AttributesMultiplayer";
					action="edit3DENMissionAttributes 'Multiplayer';";
					opensNewWindow=1;
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_AttributesMultiplayer', nil ]"};
				};
				class AttributesEnvironment
				{
					text="$STR_3DEN_Environment_textSingular";
					data="AttributesEnvironment";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_AttributesEnvironment', ( 512 + 0x17 ) ]"};
					action="edit3DENMissionAttributes 'Intel';";
					picture="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\intel_ca.paa";
					opensNewWindow=1;
				};
				class AttributesGarbageCollection
				{
					text="Performance";
					data="AttributesGarbageCollection";
					action="edit3DENMissionAttributes 'GarbageCollection';";
					opensNewWindow=1;
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_AttributesGarbageCollection', nil ]"};
				};
//				class Tools
//				{
//					text="$STR_3DEN_Display3DEN_MenuBar_Tools_text";
//
//				};
				class DebugConsole
				{
					text="$STR_3DEN_Display3DEN_MenuBar_DebugConsole_text";
					data="DebugConsole";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_DebugConsole', ( 41 ) ]"};
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
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_FunctionsViewer', nil ]"};
				};
				class ConfigViewer
				{
					text="$STR_3DEN_Display3DEN_MenuBar_ConfigViewer_text";
					data="ConfigViewer";
					action="[ctrlparent (_this select 0)] call (uinamespace getvariable 'bis_fnc_configviewer');";
					picture="\a3\3DEN\Data\Displays\Display3DEN\EntityMenu\findConfig_ca.paa";
					opensNewWindow=1;
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_ConfigViewer', nil ]"};
				};
				class AnimationViewer
				{
					xtext="$STR_3DEN_Display3DEN_MenuBar_AnimationViewer_text";
					data="AnimationViewer";
					action="[ctrlparent (_this select 0)] call (uinamespace getvariable 'bis_fnc_animviewer');";
					opensNewWindow=1;
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_AnimationViewer', nil ]"};
				};
//				class CommunityTools
//				{
//					text="$STR_3DEN_Display3DEN_MenuBar_CommunityTools_text";
//					data="CommunityTools";
//					enable=1;
//
//				};
//				class Preview
//				{
//					text="$STR_3DEN_Display3DEN_MenuBar_Preview_text";
//
//				};
				class MissionPreviewSP
				{
					text="$STR_3DEN_Display3DEN_MenuBar_MissionPreviewSP_text";
					data="MissionPreview";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_MissionPreviewSP', ( 1024 + 0x1C ) ]"};
				};
				class MissionPreviewSPBriefing
				{
					text="$STR_3DEN_Display3DEN_MenuBar_MissionPreviewSPBriefing_text";
					data="MissionPreviewBriefing";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_MissionPreviewSPBriefing', ( 512 + 1024 + 0x1C ) ]"};
				};
				class MissionPreviewCamera
				{
					text="$STR_3DEN_Display3DEN_MenuBar_MissionPreviewCamera_text";
					data="MissionPreviewCamera";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_MissionPreviewCamera', ( 512 + 1024 + 2048 + 0x1C ) ]"};
					action="{'MissionPreviewCustom' call bis_fnc_3DENMissionPreview;} call bis_fnc_3DENMissionPreview;";
				};
				class MissionPreviewSpectator
				{
					text="$STR_3DEN_Display3DEN_MenuBar_MissionPreviewSpectator_text";
					data="MissionPreviewSpectator";
					action="{'MissionPreviewSpectator' call bis_fnc_3DENMissionPreview;} call bis_fnc_3DENMissionPreview;";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_MissionPreviewSpectator', nil ]"};
				};
				class MissionPreviewMP
				{
					text="$STR_3DEN_Display3DEN_MenuBar_MissionPreviewMP_text";
					data="MissionPreviewMP";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_MissionPreviewMP', nil ]"};
				};
				class Options
				{
					text="$STR_3DEN_Display3DEN_MenuBar_Options_text";
					//Entry for EdenKeyBinds UI
					items[] +=
					{
						"OptionsEditorKeybinds"
					};
				};
				class OptionsVideo
				{
					text="$STR_3DEN_Display3DEN_MenuBar_OptionsVideo_text";
					data="OptionsVideo";
					opensNewWindow=1;
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_OptionsVideo', nil ]"};
				};
				class OptionsAudio
				{
					text="$STR_3DEN_Display3DEN_MenuBar_OptionsAudio_text";
					data="OptionsAudio";
					opensNewWindow=1;
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_OptionsAudio', nil ]"};
				};
				class OptionsGame
				{
					text="$STR_3DEN_Display3DEN_MenuBar_OptionsGame_text";
					data="OptionsGame";
					opensNewWindow=1;
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_OptionsGame', nil ]"};
				};
				class OptionsControls
				{
					text="$STR_3DEN_Display3DEN_MenuBar_OptionsControls_text";
					data="OptionsControls";
					opensNewWindow=1;
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_OptionsControls', nil ]"};
				};
				class OptionsEditor
				{
					text="$STR_3DEN_Preferences_textSingular";
					data="Preferences";
					action="edit3DENMissionAttributes 'Preferences';";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_OptionsEditor', ( 512 + 0x25 ) ]"};
					opensNewWindow=1;
				};
				class OptionsEditorKeybinds
				{
					text="Eden Key Binds";
					data="Preferences";
					action="(ctrlparent (_this select 0)) createdisplay 'LARs_EdenKeyBinds_UI';";
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_OptionsEditorKeybinds', nil ]"};
					opensNewWindow=1;
				};
//				class Help
//				{
//					text="$STR_3DEN_Display3DEN_MenuBar_Help_text";
//
//				};
				class HelpDoc
				{
					text="$STR_3DEN_Display3DEN_MenuBar_HelpDoc_text";
					data="HelpDoc";
					picture="\a3\3DEN\Data\Controls\ctrlMenu\link_ca.paa";
					weblink="https://community.bistudio.com/wiki/Eden_Editor";
					opensNewWindow=1;
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_HelpDoc', nil ]"};
				};
				class HelpScripting
				{
					text="$STR_3DEN_Display3DEN_MenuBar_HelpScripting_text";
					data="HelpScripting";
					picture="\a3\3DEN\Data\Controls\ctrlMenu\link_ca.paa";
					weblink="https://community.bistudio.com/wiki/Category:Scripting_Commands_Arma_3";
					opensNewWindow=1;
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_HelpScripting', nil ]"};
				};
				class HelpBiki
				{
					text="$STR_3DEN_Display3DEN_MenuBar_HelpBiki_text";
					data="HelpBiki";
					picture="\a3\3DEN\Data\Controls\ctrlMenu\link_ca.paa";
					weblink="https://community.bistudio.com/";
					opensNewWindow=1;
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_HelpBiki', nil ]"};
				};
				class HelpForums
				{
					text="$STR_3DEN_Display3DEN_MenuBar_HelpForums_text";
					data="HelpForums";
					picture="\a3\3DEN\Data\Controls\ctrlMenu\link_ca.paa";
					weblink="https://forums.bistudio.com/forum/161-arma-3-editing/";
					opensNewWindow=1;
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_HelpForums', nil ]"};
				};
				class HelpFeedback
				{
					text="$STR_3DEN_Display3DEN_MenuBar_HelpFeedback_text";
					data="HelpFeedback";
					picture="\a3\3DEN\Data\Controls\ctrlMenu\link_ca.paa";
					weblink="https://feedback.arma3.com";
					opensNewWindow=1;
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_HelpFeedback', nil ]"};
				};
				class HelpDevHub
				{
					text="$STR_3DEN_Display3DEN_MenuBar_HelpDevHub_text";
					data="HelpDevHub";
					picture="\a3\3DEN\Data\Controls\ctrlMenu\link_ca.paa";
					weblink="https://dev.arma3.com/";
					opensNewWindow=1;
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_HelpDevHub', nil ]"};
				};
				class HelpTutorials
				{
					text="$STR_3DEN_Display3DENTutorial_Title_text";
					data="HelpTutorials";
					picture="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\help_tutorial_ca.paa";
					action="(ctrlparent (_this select 0)) createdisplay 'Display3DENTutorial';";
					opensNewWindow=1;
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_HelpTutorials', nil ]"};
				};
				class HelpUpdates
				{
					text="$STR_3DEN_Display3DENUpdates_Title_text";
					data="HelpUpdates";
					picture="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\help_updates_ca.paa";
					action="(ctrlparent (_this select 0)) createdisplay 'Display3DENUpdates';";
					opensNewWindow=1;
					shortcuts[]={"profilenamespace getvariable [ 'Eden_key_HelpUpdates', nil ]"};
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
			shortcuts[]={"profilenamespace getvariable [ 'Eden_key_MissionPreviewButton', { 28 } ]"};
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
	};
};