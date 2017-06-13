#include "size.h"

void bitwise(void) {
	long long int a, b, c;

	for (unsigned int i = 0; i < BITWISE_SIZE; ++i) {
		a ^= b;
		a <<= 3;
		b |= a & c;
		b >>= 3;
		c ^= a | b;
		c <<= 2;
		b &= c;
		b <<= 2;
	}
}
