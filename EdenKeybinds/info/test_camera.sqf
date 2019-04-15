
findDisplay 313 displayAddEventHandler [ "KeyDown", {
	params[
		"_ctrl", //"_display"
		"_keyCode",
		"_shft",
		"_ctr",
		"_alt"
	];
	
	switch ( _keyCode ) do {
		
		case 18 : {
			get3DENCamera setPos (getPos get3DENCamera vectorAdd ( vectorDir get3DENCamera vectorMultiply 0.5));
			get3DENCamera camCommit 0;
		};
		
		case 32 : {
			get3DENCamera setPos (getPos get3DENCamera vectorAdd ( vectorDir get3DENCamera vectorMultiply -0.5));
			get3DENCamera camCommit 0;
		};
	};
	
}];