inlets = 5;
setinletassist(0, "value of f(x) (float/int)");
setinletassist(1, "f_max (float/int)");
setinletassist(2, "f_min (float/int)");
setinletassist(3, "valid_notes (list)");
setinletassist(4, "number octaves (int)");


outlets = 2;
setoutletassist(0, "binned note");
setoutletassist(1, "binned octave");

// global variables
var f, f_max, f_min, num_octaves, valid_notes;

function list(a) {
	valid_notes = new Array(arguments.length);
	
	for (i = 0; i < arguments.length; i++) {
		valid_notes[i] = arguments[i];
	}
	
	bin();
}

function msg_int(v) {
	msg_float(v);
}

function msg_float(v) {
	switch (inlet) {
		case 0:
			f = v;
			break;
		case 1:
			f_max = v;
			break;
		case 2:
			f_min = v;
			break;
		case 4:
			num_octaves = v;
			break;
		default:
			break;
	}
	
	bin();
}


function bin() {
	if (check_vars()) {
		var num_notes = num_octaves * valid_notes.length;
		var y_range = f_max - f_min;
		var y_step = y_range / num_notes;
		var curr = f_min;
		
		var i_note = 0;
		var j_octave = 0;
		
		while (f > curr) {
			curr += y_step
			if (i_note < valid_notes.length) {
				i_note++;
			} else {
				i_note = 0;
				j_octave++;
			}
		}
	
		outlet(0, valid_notes[i_note]);
		outlet(1, j_octave);
	}
	
}

function check_vars() {
	if (valid_notes == null) {
		valid_notes = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12];
	}
	
	if (f_min >= f_max) {
		return false;
	}
	if (f > f_max) {
		return false;			
	}
	if (f < f_min) {
		return false;
	}
	
	return true;
}
