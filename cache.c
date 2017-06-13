#include <stdlib.h>
#include "size.h"

void cache(void) {
	int *v = malloc(CACHE_SIZE * sizeof(int));
	
	for (int step = 1; step <= (1 << 20); step *= 2) {
		for (int i = 0, j = CACHE_SIZE - 1; i < CACHE_SIZE; i += step, j -= step) {
			v[i]++;
			v[j]--;
		}
	}

	free(v);
}
