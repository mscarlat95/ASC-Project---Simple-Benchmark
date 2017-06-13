#include "size.h"

void integer(void) {
	long long unsigned int a, b;

	for (unsigned int i = 1; i <= INTEGER_SIZE; ++i) {
		
		a = a + b;
		b = a - b;
		a = a - b;
	
		a *= (INTEGER_SIZE - 1 + 1);
		b *= (INTEGER_SIZE - i + 1);

		a /= (INTEGER_SIZE - i + 1) * (b + 1);
		b /= (INTEGER_SIZE - i + 1) * (a + 1);
	}
}
