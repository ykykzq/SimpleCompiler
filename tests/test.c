//test local var define
int main(){
	int a = 3, b0 = 2, _c = 3;

	if(a > 0) {
		int _c = 011;
		b0 = b0 + _c;
	}

	// b0 = 11

	while(a > 0) {
		int _b0 = 0x11;
		_c = _c + _b0;
		a = a - 1;
	}

	/*
	 * b0 = 11
	 * _c = 54
	 // b0 + _c = 65
	 */

    return b0 + _c;
}