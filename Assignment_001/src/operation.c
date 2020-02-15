float operation(float arg1, float arg2, char operator) {
	switch(operator) {
		case('+'): return add(arg1, arg2);
		case('-'): return sub(arg1, arg2);
		case('*'): return mult(arg1, arg2);
		case('/'): return div(arg1, arg2);
	}
}


