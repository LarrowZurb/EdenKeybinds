
#include "\a3\ui_f\hpp\definedikcodes.inc"
#include "\Lars\EdenKeybinds\ui\Eden_KeyBinds_IDC.hpp"
#include "\Lars\EdenKeybinds\functions\EdenKeybinds_macros.hpp"

disableSerialization;

params[ "_fnc", "_this" ];

//diag_log format[ "%1 - %2", _fnc, _this ];

switch ( toUpper _fnc ) do {

	//INIT
	case "INIT" : {
		if !( canSuspend ) exitWith {
			[ "INIT", _this ] spawn LARs_fnc_EKB_EdenKeybinds
		};
		private[ "_section", "_sectionName", "_nul", "_index", "_bindName", "_varName", "_description", "_default", "_currentValue", "_largestSection" ];
		params[ "_display", [ "_menu", ( [ "LARs_EKB_customKeys", configFile >> "LARs_EdenKeybinds" ] select is3DEN ), [ configNull, "", [] ] ] ];

		waitUntil{ !isNull _display };

		//TODO: need to check if LARs_keybinds_data is not already filled via registered keys
		//Need to add registered key to data and perform initialisation of key event handler for those keys that have a function
		LARs_keybinds_data = [];
		LARs_keybinds_currentSelected = [];

		if ( _menu isEqualType configNull ) then {

			//Fill Section dropdown
			//And get config key data
			_largestSection = 0;
			_section = EKB_Section;
			{
				_sectionName = configName _x;
				_nul = _section lbAdd configName _x;

				_index = LARs_keybinds_data pushBack [];
				_count = 0;
				{
					_bindName = configName _x;
					_varName = getText( _x >> "varName" );
					_description = getText( _x >> "description" );
					_default = getArray( _x >> "default" );
					_default = if ( count _default > 0 ) then {
						if ( _default select 0 isEqualType "" ) then {
							call compile ( _default select 0 )
						}else{
							_default select 0
						};
					}else{
						-1
					};
					_currentValue = profileNamespace getVariable[ _varName, _default ];

					_keyEvent = getText( _x >> "keyEvent" );
					_keyFunction = getText( _x >> "keyFunction" );
					_keyFunctionNamespace = getText( _x >> "keyFunctionNamespace" );

					_keyEvent = [ "up", toLower _keyEvent ] select ( toLower _keyEvent in [ "up", "down" ] );

					_keyFunctionNamespace = [ missionNamespace, _keyFunctionNamespace ] select ( !( _keyFunctionNamespace isEqualTo "" ) && { call compile _keyFunctionNamespace isEqualType missionNamespace } );
					_keyFunction = if ( !( _keyFunction isEqualTo "" ) ) then {
						private _keyFunctionCode = call compile format[ "%1 getVariable %2", _keyFunctionNamespace, str _keyFunction ];
						if ( !( isNil "_keyFunctionCode" ) && { _keyFunctionCode isEqualType {} } ) then {
							_keyFunction
						}else{
							""
						};
					}else{
						""
					};

					_nul = LARs_keybinds_data select _index pushBack [ _varName, _currentValue, _default, _sectionName, _bindName, _description, false, nil, nil, _keyEvent, _keyFunction, _keyFunctionNamespace ];
					_count = _count + 1;
				}forEach ( "true" configClasses( _x ));
				_largestSection = _largestSection max _count;
			}forEach ( "true" configClasses _menu );

		}else{

			if ( _menu isEqualType "" ) then {
				_menu = missionNamespace getVariable _menu;
			};

			if !( _menu isEqualType [] ) exitWith {
				"EKB: Bad menu format" call BIS_fnc_error;
			};

			//#Region "Example data"
			//TODO: need to add code OR function data index to call when key is used
				//			[
				//				_menuName
				//				[
				//					_sectionName,
				//					[
				//						[ "title", "description", "varName", "_dikCode", [ "alt", "shft", "ctr" ], _keyEvent, _keyFunction, _keyFunctionNamespace ],
				//						[ "title", "description", "varName", "_dikCode", [ "alt", "shft", "ctr" ], _keyEvent, _keyFunction, _keyFunctionNamespace ],
				//					]
				//				],
				//				[
				//					_sectionName,
				//					[
				//						[ "title", "description", "varName", "_dikCode", [ "alt", "shft", "ctr" ], _keyEvent, _keyFunction, _keyFunctionNamespace ],
				//						[ "title", "description", "varName", "_dikCode", [ "alt", "shft", "ctr" ], _keyEvent, _keyFunction, _keyFunctionNamespace ],
				//					]
				//				]
				//			]
			//#End Region

			//If data provides _menuName
			if ( _menu select 0 isEqualType "" ) then {
				//Set it
				_display displayCtrl Eden_KeyBinds_WindowTitle ctrlSetText ( _menu select 0 );
				//Remove _menuName from data array
				_menu = _menu select[ 1, count _menu ];
			}else{
				//Else use a default title
				_display displayCtrl Eden_KeyBinds_WindowTitle ctrlSetText "Custom Keys";
			};


			//Fill Section dropdown
			//And get config key data
			_largestSection = 0;
			_section = EKB_Section;
			{
				_x params[ "_sectionName", "_binds" ];

				_nul = _section lbAdd _sectionName;

				_index = LARs_keybinds_data pushBack [];
				_count = 0;
				{
					_x params[
						[ "_bindName", "NO TITLE", [ "" ] ],
						[ "_description", "NO DESCRIPTION", [ "" ] ],
						[ "_varName", "", [ "" ] ],
						[ "_dikCode", -1, [ 0 ] ],
						[ "_modifiers", [ false, false, false ], [ [] ] ],
						[ "_keyEvent", "up", [ "" ] ],
						[ "_keyFunction", "", [ "" ] ],
						[ "_keyFunctionNamespace", missionNamespace, [ missionNamespace ] ]
					];

					_keyEvent = [ "up", toLower _keyEvent ] select ( toLower _keyEvent in [ "up", "down" ] );

					_keyFunctionNamespace = [ missionNamespace, _keyFunctionNamespace ] select ( _keyFunctionNamespace isEqualType missionNamespace );
					_keyFunction = _keyFunctionNamespace getVariable [ _keyFunction, {} ];

					{
						_type = [
							INPUT_ALT_OFFSET,		//2048
							INPUT_SHIFT_OFFSET,		//1024
							INPUT_CTRL_OFFSET		//512
						] select _forEachIndex;

						if ( _x isEqualType 0 ) then {
							_modifiers set[ _forEachIndex, [ 0, _type ] select ( _x > 0 ) ];
						}else{
							if ( _x isEqualType false ) then {
								_modifiers set[ _forEachIndex, [ 0, _type ] select _x ];
							}else{
								//fallback for bad data
								_modifiers set[ _forEachIndex, 0 ];
							};
						};
					}forEach _modifiers;

					_modifiers params[ "_alt", "_shft", "_ctr" ];

					_default = _dikCode + _alt + _shft + _ctr;
					_currentValue = profileNamespace getVariable[ _varName, _default ];
					_nul = LARs_keybinds_data select _index pushBack [ _varName, _currentValue, _default, _sectionName, _bindName, _description, false, nil, nil, _keyEvent, _keyFunction, _keyFunctionNamespace ];
					_count = _count + 1;
				}forEach _binds;
				_largestSection = _largestSection max _count;
			}forEach _menu;

			missionNamespace setVariable[ "LARs_EKB_customKeys", +LARs_keybinds_data ];

			//TODO: Need somewhere to start a Key event for each keybind ( possibly allow specify of KeyUp OR KeyDown )
			//Add each sepreately and store EH ID so they can be added removed whenever a keyBind changes
			//Or one EH that loops through data looking at each keyBinds key and modifiers

			//TODO: REGISTER_KEY ????

		};


		LARs_keybinds_dataOld = +LARs_keybinds_data;

		_bindControls = [];
		for "_i" from 0 to _largestSection - 1 do {
			_bind = EKB_Display ctrlCreate [ "LARs_EdenKeyBinds_bind", 100 + _i, EKB_KeyBindGroup ];
			_bind ctrlSetPosition[ 0, Eden_KeyBinds_BindGrp_height * _i ];
			_bind ctrlCommit 0;

			_nul = _bindControls pushBack _bind;
		};
		EKB_KeyBindGroup setVariable[ "bindControls", _bindControls ];

		//Disable CLEAR
		EKB_ButtonClear ctrlEnable false;
		//Disbale RESET
		EKB_ButtonReset ctrlEnable false;

		_section ctrlAddEventHandler [ "LBSelChanged", {
			[ "SECTION", [ "LB_CHANGED", _this + [ true ] ] ] call LARs_fnc_EKB_EdenKeybinds;
		}];
		_section lbSetCurSel 0;

	};

	//SECTION
	case "SECTION" : {
		params[ "_fnc", "_this" ];

		switch ( toUpper _fnc ) do {

			//CHANGED
			case "LB_CHANGED" : {
				private[ "_ctrl", "_numBinds", "_bindControls", "_bindIndex", "_bind", "_nul", "_sectionIndex", "_sIndex", "_bIndex", "_conflict", "_sName", "_AltShftCtrl" ];
				params[ "_section", "_index", [ "_isNewSection", false ] ];

				if ( _isNewSection ) then {
					LARs_keybinds_currentSelected = [];
				};

				_data = LARs_keybinds_data select _index;
				{

					_bindIndex = _forEachIndex;
					_bind = _x;

					if ( _bindIndex < count _data ) then {

						{
							_x params[ "_ctrl", [ "_enable", true ] ];
							_ctrl ctrlSetFade 0;
							_ctrl ctrlEnable _enable;
							_ctrl ctrlCommit 0;
						}forEach[
							[ EKB_BindDescrip( _bind ), false ],	//This is never enabled else it takes focus away from BindAction
							[ EKB_BindKey( _bind ), false ],		//This is never enabled else it takes focus away from BindAction
							[ EKB_BindAction( _bind ) ],
							[ EKB_BindCheckShft( _bind ) ],
							[ EKB_BindCheckCtrl( _bind ) ],
							[ EKB_BindCheckAlt( _bind ) ]
						];

						//Clear conflict
						EKB_SetData( _index, _bindIndex, EKB_DataHasConflict, false );
						EKB_SetData( _index, _bindIndex, EKB_DataConflictSection, nil );
						EKB_SetData( _index, _bindIndex, EKB_DataConflictIndex, nil );

						_data select _bindIndex params[ "_varName", "_value", "_default", "_sectionName", "_bindName", "_description", [ "_hasConflict", false ] ];

						//Description
						EKB_BindDescrip( _bind ) ctrlSetText _description;

						if !( _value isEqualTo -1 ) then {
							{
								_sectionIndex = _forEachIndex;
								{
									if ( !( _x select EKB_DataVarName isEqualTo _varName ) && { _x select EKB_DataValue isEqualTo _value } ) then {
										EKB_SetData( _sectionIndex, _forEachIndex, EKB_DataHasConflict, true );
										EKB_SetData( _sectionIndex, _forEachIndex, EKB_DataConflictSection, _index );
										EKB_SetData( _sectionIndex, _forEachIndex, EKB_DataConflictIndex, _bindIndex );
										EKB_SetData( _index, _bindIndex, EKB_DataHasConflict, true );
										EKB_SetData( _index, _bindIndex, EKB_DataConflictSection, _sectionIndex );
										EKB_SetData( _index, _bindIndex, EKB_DataConflictIndex, _forEachIndex );
									};
								}forEach _x;
							}forEach LARs_keybinds_data;
							if !( EKB_GetData( _index, _bindIndex, EKB_DataHasConflict ) ) then {
								EKB_BindDescrip( _bind ) ctrlSetTextColor [1,1,1,1];
								EKB_BindAction( _bind ) ctrlSetTooltip "";
							}else{
								EKB_BindDescrip( _bind ) ctrlSetTextColor [1,0,0,1];
								_sIndex = EKB_GetData( _index, _bindIndex, EKB_DataConflictSection );
								_bIndex = EKB_GetData( _index, _bindIndex, EKB_DataConflictIndex );
								_conflict = EKB_GetData( _sIndex, _bIndex, EKB_DataDescrip );
								_sName = EKB_Section lbText _sIndex;
								//diag_log format[ "Conlict: %1 - %2 %3 = %4 %5", _description, _sIndex, _bIndex, _sName, _conflict ];
								_conflict = format[ "Conflicts with %1 - %2", str _sName, str _conflict ];
								EKB_BindAction( _bind ) ctrlSetTooltip _conflict;
							};
						}else{
							EKB_BindDescrip( _bind ) ctrlSetTextColor [1,1,1,1];
							EKB_BindAction( _bind ) ctrlSetTooltip "";
						};

						_AltShftCtrl = [ false, false, false ];
						if !( _value isEqualTo -1 ) then {
							{
								if ( _value >= _x ) then {
									_AltShftCtrl set[ _forEachIndex, true ];
									_value = _value - _x;
								};
							}forEach [
								INPUT_ALT_OFFSET,		//2048
								INPUT_SHIFT_OFFSET,		//1024
								INPUT_CTRL_OFFSET		//512
							];
							if ( _value > 0 ) then {
								EKB_BindKey( _bind ) ctrlSetText ( keyName _value );
							};
						}else{
							EKB_BindKey( _bind ) ctrlSetText "";
						};

						{
							if ( _value > 0 ) then {
								_x cbSetChecked ( _AltShftCtrl select _forEachIndex );
								_x ctrlEnable true;
							}else{
								_x cbSetChecked false;
								_x ctrlEnable false;
							};
						}forEach[
							EKB_BindCheckAlt( _bind ),
							EKB_BindCheckShft( _bind ),
							EKB_BindCheckCtrl( _bind )
						];

					}else{

						{
							_x ctrlSetFade 1;
							_x ctrlEnable false;
							_x ctrlCommit 0;
						}forEach[
							EKB_BindDescrip( _bind ),
							EKB_BindKey( _bind ),
							EKB_BindAction( _bind ),
							EKB_BindCheckShft( _bind ),
							EKB_BindCheckCtrl( _bind ),
							EKB_BindCheckAlt( _bind )
						];

					};

				}forEach ( EKB_KeyBindGroup getVariable[ "bindControls", [] ] );

				if ( count LARs_keybinds_currentSelected > 0 ) then {
					[ "BIND", [ "HIGHLIGHT", EKB_KeyBindGroup ] ] call LARs_fnc_EKB_EdenKeybinds;
				};

			};

			//RESET
			case "RESET" : {
				private[ "_sectionindex", "_data" ];
				params[ "_ctrl" ];

				_sectionIndex = lbCurSel EKB_Section;

				_data = LARs_keybinds_data select _sectionIndex;
				{
					_x params[ "_varName", "_currentValue", "_default" ];

					if !( _currentValue isEqualTo _default ) then {
						EKB_SetData( _sectionIndex, _forEachIndex, EKB_DataValue, _default );
					};
				}forEach +_data;

				[ "SECTION", [ "LB_CHANGED", [ EKB_Section, _sectionIndex ] ] ] call LARs_fnc_EKB_EdenKeybinds;
			};
		};
	};

	//BIND
	case "BIND" : {
		params[ "_fnc", "_this" ];

		switch ( toUpper _fnc ) do {

			case "SELECT" : {
				private[ "_nul", "_sectionIndex", "_bindIndex", "_conflict" ];
				params[ "_ctrl", "_button", "", "", "_shft", "_ctr" ];

				if !( isNil "LARs_EdenKeybinds_selecting" ) exitWith {};
				LARs_EdenKeybinds_selecting = true;

				if ( _button isEqualTo 0 ) then {
					if ( _shft || _ctr ) then {
						if ( _shft ) then {
							_nul = LARs_keybinds_currentSelected pushBack EKB_GetBind( _ctrl );
						}else{
							LARs_keybinds_currentSelected = LARs_keybinds_currentSelected - [ EKB_GetBind( _ctrl ) ];
						};
					}else{
						LARs_keybinds_currentSelected = [ EKB_GetBind( _ctrl ) ];
					};

					[ "BIND", [ "HIGHLIGHT", EKB_KeyBindGroup ] ] call LARs_fnc_EKB_EdenKeybinds;
				}else{
					if ( _button isEqualTo 1 ) then {
						_sectionIndex = lbCurSel EKB_Section;
						_bindIndex = EKB_GetBindIDC( _ctrl ) - 100;
						_conflict = EKB_GetData( _sectionIndex, _bindIndex, EKB_DataHasConflict );
						if ( !isNil"_conflict" && { _conflict } ) then {
							//diag_log format[ "MR: si:%1, bi:%2, c:%3, CS:%4", _sectionIndex, _bindIndex, _conflict, EKB_GetData( _sectionIndex, _bindIndex, EKB_DataConflictSection ) ];
							_conflictSection = EKB_GetData( _sectionIndex, _bindIndex, EKB_DataConflictSection );
							if !( isNil"_conflictSection" ) then {
								EKB_Section lbSetCurSel _conflictSection;
							};
						};
					};
				};
				LARs_EdenKeybinds_selecting = nil;
			};

			case "HIGHLIGHT" : {
				private[ "_sectionIndex", "_hasConflict" ];

				_sectionIndex = lbCurSel EKB_Section;
				{
					if ( ctrlEnabled _x ) then {
						if ( _x in LARs_keybinds_currentSelected ) then {
							EKB_BindDescrip( _x ) ctrlSetTextColor [ 0, 1, 0, 1 ];
						}else{
							_hasConflict = EKB_GetData( _sectionIndex, _forEachIndex, EKB_DataHasConflict );
							if ( !isNil "_hasConflict" && { _hasConflict } ) then {
								EKB_BindDescrip( _x ) ctrlSetTextColor [ 1, 0, 0, 1 ];
							}else{
								EKB_BindDescrip( _x ) ctrlSetTextColor [ 1, 1, 1, 1 ];
							};
						};
						ctrlSetFocus EKB_BindAction( _x );
					};
				}forEach +( EKB_KeyBindGroup getVariable[ "bindControls", [] ] );

				if ( count LARs_keybinds_currentSelected > 0 ) then {
					//Enable CLEAR
					EKB_ButtonClear ctrlEnable true;
					//Enbale RESET
					EKB_ButtonReset ctrlEnable true;
				}else{
					//Disable CLEAR
					EKB_ButtonClear ctrlEnable false;
					//Disbale RESET
					EKB_ButtonReset ctrlEnable false;
				};
			};

			case "GET" : {
				private[ "_sectionIndex", "_bindIndex" ];
				params[ "_ctrl", "_button" ];

				if !( _button isEqualTo 0 ) exitWith {};

				EKB_Display createDisplay "LARs_EdenKeyBinds_PAK";

				_sectionIndex = lbCurSel EKB_Section;
				_bindIndex = ( EKB_KeyBindGroup getVariable[ "bindControls", [] ] ) find EKB_GetBind( _ctrl );

				LARs_keybinds_dataPath = [ _sectionIndex, _bindIndex ];

				EKB_PAK setVariable[ "PAK_EH", EKB_PAK displayAddEventHandler [ "KeyDown", {
					params[ "_display", "_keyCode", "_shft", "_ctr", "_alt" ];

					if !( _keyCode in EKB_ProtectedKeys ) then {
						[ "BIND", [ "SET", [ _keyCode, [ _shft, _ctr, _alt ] ] ] ] call LARs_fnc_EKB_EdenKeybinds;
					};
				}]];
			};

			case "SET" : {
				private[ "_value" ];
				params[ "_keyCode", "_modifiers" ];
				_modifiers params[ "_shft", "_ctr", "_alt" ];

				_value = _keyCode +
					( [ 0, INPUT_SHIFT_OFFSET ] select _shft ) +
					( [ 0, INPUT_CTRL_OFFSET ] select _ctr ) +
					( [ 0, INPUT_ALT_OFFSET ] select _alt );

				LARs_keybinds_dataPath params[ "_sectionIndex", "_bindIndex" ];
				EKB_SetData( _sectionIndex, _bindIndex, EKB_DataValue, _value );

				LARs_keybinds_dataPath = nil;

				EKB_PAK displayRemoveEventHandler[ "KeyDown", EKB_PAK getVariable "PAK_EH" ];

				EKB_PAK closeDisplay 1;

				[ "SECTION", [ "LB_CHANGED", [ EKB_Section, lbCurSel EKB_Section, true ] ] ] call LARs_fnc_EKB_EdenKeybinds;
			};

			case "CHECK" : {
				private[ "_value", "_sectionIndex", "_bindIndex", "_currentValue" ];
				params[ "_ctrl", "_checked" ];

				if !( isNil"LARs_EdenKeybinds_checked" ) exitWith{};
				LARs_EdenKeybinds_checked = true;

				_checked = _checked > 0;

				//shft ctr alt
				_value = [ INPUT_SHIFT_OFFSET, INPUT_CTRL_OFFSET, INPUT_ALT_OFFSET ] select ( [ Eden_KeyBinds_CheckShft, Eden_KeyBinds_CheckCtrl, Eden_KeyBinds_CheckAlt ] find ctrlIDC _ctrl );
				if !( _checked ) then {
					_value = 0 -_value;
				};

				_sectionIndex = lbCurSel EKB_Section;
				_bindIndex = ( EKB_KeyBindGroup getVariable[ "bindControls", [] ] ) find EKB_GetBind( _ctrl );

				_currentValue = EKB_GetData( _sectionIndex, _bindIndex, EKB_DataValue );
				EKB_SetData( _sectionIndex, _bindIndex, EKB_DataValue, ( _currentValue + _value ) max -1 );

				[ "SECTION", [ "LB_CHANGED", [ EKB_Section, _sectionIndex ] ] ] call LARs_fnc_EKB_EdenKeybinds;

				LARs_EdenKeybinds_checked = nil;
			};

			case "CREATE" : {
				//TODO: Move creation of bind ctrl in here
				params[ "_sectionSize" ];

				private _currentCtrls = EKB_KeyBindGroup getVariable[ "bindControls", [] ];

				//Delete unneed bind ctrls
				if ( count _currentCtrls > _sectionSize ) then {
					{
						ctrlDelete _x;
					}forEach ( _currentCtrls select[ _sectionSize, count _currentCtrls ] );
					_currentCtrls = _currentCtrls select[ 0, _sectionSize ];
				};

				if ( count _currentCtrls < _sectionSize ) then {
					private _newCtrls = [];
					for "_i" from count _currentCtrls to _sectionSize do { //TODO: check these values
						private _bind = EKB_Display ctrlCreate [ "LARs_EdenKeyBinds_bind", 100 + _i, EKB_KeyBindGroup ];
						_bind ctrlSetPosition[ 0, Eden_KeyBinds_BindGrp_height * _i ];
						_bind ctrlCommit 0;
						private _nul = _newCtrls pushBack _bind;
					};
					EKB_KeyBindGroup setVariable[ "bindControls", _currentCtrls append _newCtrls ];
				};
			};

		};
	};

	//SAVE
	case "SAVE" : {
		private[ "_sectionIndex", "_changed" ];

		for "_i" from 0 to ( count LARs_keybinds_data ) -1 do {
			EKB_Section lbSetCurSel _i;
		};

		if ( { { !isNil{ _x select EKB_DataHasConflict } && { _x select EKB_DataHasConflict } }count _x > 0 }count LARs_keybinds_data > 0 ) then {
			if ( is3DEN ) then {
				[ "You must resolve any bind conflicts", 1, 5 ] call BIS_fnc_3DENNotification;
			};
			{
				_sectionIndex = _forEachIndex;
				_shown = {
					if ( !isNil{ _x select EKB_DataHasConflict } && { _x select EKB_DataHasConflict } ) exitWith {
						EKB_Section lbSetCurSel _sectionIndex;
						true
					};
				}forEach _x;
				if ( !isNil"_shown" && { _shown } ) exitWith{};
			}forEach LARs_keybinds_data;

		}else{

			_changed = false;
			{
				_sectionIndex = _forEachIndex;
				{
					if !( _x isEqualTo EKB_GetDataOld( _sectionIndex, _forEachIndex ) ) then {
						_x params[ "_varName", "_value" ];

						_changed = true;
						profileNamespace setVariable[ _varName, _value ];
						diag_log format[ "Saving %1 %2", _varName, _value ];
					};
				}forEach _x;
			}forEach LARs_keybinds_data;

			if ( _changed ) then {
				saveProfileNamespace;
				EKB_Display closeDisplay 1;
				if ( is3DEN ) then {
					[ "You must restart the editor for changes to take effect", 1, 5 ] call BIS_fnc_3DENNotification;
				};
			};
		};
	};

	//SELECTION
	case "SELECTION" : {
		params[ "_fnc", "_this" ];

		switch ( toUpper _fnc ) do {

			//RESET
			case "RESET" : {
				private[ "_sectionIndex", "_data" ];
				params[ "_ctrl" ];

				_sectionIndex = lbCurSel EKB_Section;

				_data = LARs_keybinds_data select _sectionIndex;
				{
					_x params[ "_varName", "_currentValue", "_default" ];

					if ( EKB_KeyBind( 100 + _forEachIndex ) in LARs_keybinds_currentSelected ) then {
						if !( _currentValue isEqualTo _default ) then {
							EKB_SetData( _sectionIndex, _forEachIndex, EKB_DataValue, _default );
						};
					};
				}forEach +_data;

				[ "SECTION", [ "LB_CHANGED", [ EKB_Section, _sectionIndex ] ] ] call LARs_fnc_EKB_EdenKeybinds;
			};

			//CLEAR
			case "CLEAR" : {
				private[ "_sectionIndex", "_data", "_sIndex", "_bIndex" ];
				params[ "_ctrl" ];

				_sectionIndex = lbCurSel EKB_Section;

				_data = LARs_keybinds_data select _sectionIndex;
				{
					_x params[ "_varName", "_currentValue", "_default" ];

					if ( EKB_KeyBind( 100 + _forEachIndex ) in LARs_keybinds_currentSelected ) then {
						EKB_SetData( _sectionIndex, _forEachIndex, EKB_DataValue, -1 );
						if ( EKB_GetData( _sectionIndex, _forEachIndex, EKB_DataHasConflict ) ) then {
							_sIndex = EKB_GetData( _sectionIndex, _forEachIndex, EKB_DataConflictSection );
							_bIndex = EKB_GetData( _sectionIndex, _forEachIndex, EKB_DataConflictIndex );
							EKB_SetData( _sIndex, _bIndex, EKB_DataHasConflict, false );
							EKB_SetData( _sIndex, _bIndex, EKB_DataConflictSection, nil );
							EKB_SetData( _sIndex, _bIndex, EKB_DataConflictIndex, nil );
						};
						EKB_SetData( _sectionIndex, _forEachIndex, EKB_DataHasConflict, false );
						EKB_SetData( _sectionIndex, _forEachIndex, EKB_DataConflictSection, nil );
						EKB_SetData( _sectionIndex, _forEachIndex, EKB_DataConflictIndex, nil );
					};
				}forEach +_data;

				[ "SECTION", [ "LB_CHANGED", [ EKB_Section, _sectionIndex ] ] ] call LARs_fnc_EKB_EdenKeybinds;
			};

		};
	};


	case "KEY" : {
		params[ "_fnc", "_this" ];

		switch ( _fnc ) do {

			//GET
			case "GET" : {
				params[ "_varName", [ "_default", 0 ] ];

				_value = profileNamespace getVariable[ _varName, _default ];

				_AltShftCtrl = [ false, false, false ];
				{
					if ( _value >= _x ) then {
						_value = _value - _x;
						_AltShftCtrl set[ _forEachIndex, true ];
					};
				}forEach[
					INPUT_ALT_OFFSET,		//2048
					INPUT_SHIFT_OFFSET,		//1024
					INPUT_CTRL_OFFSET		//512
				];

				( [ _value ] + _AltShftCtrl )
			};

			//REGISTER
			case "REGISTER" : {
				params[
					[ "_sectionName", "", [ "" ] ],
					[ "_keyData", [], [ [] ] ]
				];

				if ( _sectionName isEqualTo "" || _keyData isEqualTo [] ) exitWith{ false };

				_keyData params[
					[ "_bindName", "NO TITLE", [ "" ] ],
					[ "_description", "NO DESCRIPTION", [ "" ] ],
					[ "_varName", "", [ "" ] ],
					[ "_dikCode", -1, [ 0 ] ],
					[ "_modifiers", [ false, false, false ], [ [] ] ],
					[ "_keyEvent", "up", [ "" ] ],
					[ "_keyFunction", "", [ "" ] ],
					[ "_keyFunctionNamespace", missionNamespace, [ missionNamespace ] ]
				];

				private _customKeys = missionNamespace getVariable[ "LARs_EKB_customKeys", [] ];

				private _index = _customKeys findIf{ ( _x select 0 ) == _sectionName };

				if ( _index isEqualTo -1 ) then {
					_index = _customKeys pushBack [ _sectionName, [] ];
				};

				_keyEvent = [ "up", toLower _keyEvent ] select ( toLower _keyEvent in [ "up", "down" ] );

				_keyFunctionNamespace = [ missionNamespace, _keyFunctionNamespace ] select ( _keyFunctionNamespace isEqualType missionNamespace );
				_keyFunctionNamespace getVariable [ _keyFunction, {} ];

				//TODO: need to add registered key to LARs_keybinds_data and perform initialisation of key event handler for those keys that have a function

				private _nul = ( _customKeys select _index select 1 ) pushBack [ _bindName, _description, _varName, _dikCode, _modifiers, _keyEvent, _keyFunction, _keyFunctionNamespace ];
				missionNamespace setVariable[ "LARs_EKB_customKeys", _customKeys ];

				true
			};

		};
	};

};