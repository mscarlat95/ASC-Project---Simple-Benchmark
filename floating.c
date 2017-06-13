#include "size.h"

void floating(void) {
	long double a, b;

	for (unsigned int i = 1; i <= FLOATING_SIZE; ++i) {
		a *= b / 4.14534;
		b += (a + b + 31.9736);
		b /= (a + 1.98512);
		b *= (a * b - a * 2.530);
		a += b * a * 0.3312;
		a *= b;
	}
}
