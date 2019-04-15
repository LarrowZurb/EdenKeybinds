
#include "\Lars\EdenKeybinds\ui\Eden_KeyBinds_IDC.hpp"

#define EKB_Display					( findDisplay Eden_KeyBinds_IDD )
#define EKB_PAK						( findDisplay Eden_KeyBinds_PAK )

//Dropdown
#define EKB_Section					( EKB_Display displayCtrl Eden_KeyBinds_BindSection )
//Binds group
#define EKB_KeyBindGroup			( EKB_Display displayCtrl Eden_KeyBinds_KeySettings )

#define EKB_KeyBind( CTRL )			( EKB_KeyBindGroup controlsGroupCtrl ( if ( CTRL isEqualType 0 ) then { CTRL }else{ ctrlIDC CTRL }))
#define EKB_GetBind( CTRL )			( ctrlParentControlsGroup CTRL )
#define EKB_GetBindIDC( CTRL )		( ctrlIDC EKB_GetBind( CTRL ))

//Bind controls
#define EKB_BindDescrip( CTRL )		( EKB_KeyBind( CTRL ) controlsGroupCtrl Eden_KeyBinds_BindDescrip )
#define EKB_BindKey( CTRL )			( EKB_KeyBind( CTRL ) controlsGroupCtrl Eden_KeyBinds_BindKey )
#define EKB_BindAction( CTRL )		( EKB_KeyBind( CTRL ) controlsGroupCtrl Eden_KeyBinds_BindAction )
#define EKB_BindCheckShft( CTRL )	( EKB_KeyBind( CTRL ) controlsGroupCtrl Eden_KeyBinds_CheckShft )
#define EKB_BindCheckCtrl( CTRL )	( EKB_KeyBind( CTRL ) controlsGroupCtrl Eden_KeyBinds_CheckCtrl )
#define EKB_BindCheckAlt( CTRL )	( EKB_KeyBind( CTRL ) controlsGroupCtrl Eden_KeyBinds_CheckAlt )

//Buttons
#define EKB_ButtonClear				( EKB_Display displayCtrl Eden_KeyBinds_Clear )
#define EKB_ButtonReset				( EKB_Display displayCtrl Eden_KeyBinds_Reset )

#define EKB_ProtectedKeys			[ DIK_ESCAPE, DIK_LSHIFT, DIK_RSHIFT, DIK_RCONTROL, DIK_LCONTROL, DIK_LALT, DIK_RALT, DIK_DELETE ]

//Data
#define EKB_DataVarName				0
#define EKB_DataValue				1
#define EKB_DataDefault				2
#define EKB_DataSection				3
#define EKB_DataBind				4
#define EKB_DataDescrip				5
#define EKB_DataHasConflict			6
#define EKB_DataConflictSection		7
#define EKB_DataConflictIndex		8
//Only for Mission Keys
#define EKB_DataKeyEvent			9
#define EKB_DataKeyScript			10
#define EKB_DataKeyScriptNamespace	11

#define EKB_GetData( SECTION, BIND, DATA )			( LARs_keyBinds_data select SECTION select BIND select DATA )
#define EKB_SetData( SECTION, BIND, DATA, INFO )	( LARs_keyBinds_data select SECTION select BIND set [ DATA, INFO ] )

#define EKB_GetDataOld( SECTION, BIND )				( LARs_keyBinds_dataOld select SECTION select BIND )