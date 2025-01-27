#include <stdio.h>
#include <stdint.h>
#include <x86intrin.h>

void test(int a) {
	int sum = 0;
	for (int i = 1; i < a; ++i) {
		sum += i * i;
	}
}

void print_timing(int mon_arg, void(*test)(int), int num_amorcage, int num_moyennage) {

	uint64_t tic, toc;
	unsigned int _pid;
	uint64_t list[num_moyennage];

	for (int i = 0; i < num_amorcage; ++i) {
		test(mon_arg);
	}

	for (int i = 0; i < num_moyennage; ++i) {
		tic = __rdtscp(&_pid);
		test(mon_arg);
		toc = __rdtscp(&_pid);
		uint64_t timing = toc - tic;
		list[i] = timing;
	}
	uint64_t sum = 0;
	for (int i = 0; i < num_moyennage; ++i) {
		sum += list[i];
	}
	uint64_t mean = (sum / num_moyennage);

	printf("timing = %lu\n", mean);
}

uint64_t return_timing(int mon_arg, void(*test)(int), int num_amorcage, int num_moyennage) {

	uint64_t tic, toc;
	unsigned int _pid;
	uint64_t list[num_moyennage];

	for (int i = 0; i < num_amorcage; ++i) {
		test(mon_arg);
	}

	for (int i = 0; i < num_moyennage; ++i) {
		tic = __rdtscp(&_pid);
		test(mon_arg);
		toc = __rdtscp(&_pid);
		uint64_t timing = toc - tic;
		list[i] = timing;
	}
	uint64_t sum = 0;
	for (int i = 0; i < num_moyennage; ++i) {
		sum += list[i];
	}
	uint64_t mean = (sum / num_moyennage);

	return mean;
}
