

_selected = get3DENSelected "";
_objects = _selected select 0;
_triggers = _selected select 2;
_logics = _selected select 3;
_waypoints = _selected select 4;
_markers = _selected select 5;

collect3DENHistory{
	
	{
		_pos = _x get3DENAttribute "position" select 0;
		_pos set[ 2, 0 ];
		_x set3DENAttribute [ "position", _pos ];
	}forEach _objects;
	
	
};