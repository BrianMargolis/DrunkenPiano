/*
// global variables
var f, f_max, f_min, num_octaves, valid_notes;

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
*/

int bin(double freq, double freq_max, double freq_min, double num_octaves, double[] valid_notes)
{
	if (!validate(freq, freq_max, freq_min, num_octaves, valid_notes)) {
		return;
	}
		
	int valid_notes_length = sizeof(valid_notes) / sizeof(valid_notes[0];)

	double num_notes = num_octaves * valid_notes_length;
	double y_range = freq_max - freq_min;
	double y_step = y_range / num_notes;
	double curr = f_min;
	
	int i_note = 0;
	int j_octave = 0;

	while (freq > curr) {
		curr += y_step
		if (i_note < valid_notes_length) {
			i_note++;
		} else {
			i_note = 0;
			j_octave++;
		}
	}
	
}