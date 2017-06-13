#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "size.h"

extern void bitwise();
extern void integer();
extern void floating();
extern void cache();

int main(int argc, char const *argv[]) 
{
	if (argc != 3) {
		printf("Usage: %s test_num_type cores_num\n", argv[0]);
		return 0;
	}

	pthread_t t[MAX_CORES];
	int test = atoi(argv[1]);
	int cores = atoi(argv[2]);
	void *f;

	if (cores > MAX_CORES) {
		cores = MAX_CORES;
	}

	switch (test) {
		case 1:
			f = bitwise;
			break;
		case 2:
			f = integer;
			break;
		case 3:
			f = floating;
			break;
		case 4:
			f = cache;
			break;
		default:
			printf ("Error: Invalid test number\n");
			return 0;
	}

	for (int i = 0; i < cores; ++i) {
		pthread_create(&t[i], NULL, f, NULL);
	}

	for (int i = 0; i < cores; ++i) {
		pthread_join(t[i], NULL);
	}

	return 0;
}
