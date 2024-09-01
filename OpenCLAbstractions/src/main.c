#include "parallel_computing.h"

#include <stdio.h>

int main() {

	char* src = "__kernel void vectoradd(__global int* a, __global int* b, __global int* c) { \n\n int x = get_global_id(0);c[x] = a[x] + b[x]; }";

	void* kernel = create_kernel(src);

	#define array_size 10

	int a[array_size];
	int b[array_size];
	int c[array_size];

	for (int i = 0; i < array_size; i++) { a[i] = i; b[i] = i; }

	run_kernel(kernel, 1, array_size, 1, 1, &a[0], array_size * sizeof(int), BUFFER_COPY, &b[0], array_size * sizeof(int), BUFFER_COPY, &c[0], array_size * sizeof(int), BUFFER_READ);

	for (int i = 0; i < array_size; i++) printf("%d ", c[i]);

	destroy_kernel(kernel);

	return 0;
}