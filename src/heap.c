#include "heap.h"
#include "_include.h"

void* heapalloc(size_t typesize, size_t n, bool clear)
{
	if(clear)
		return calloc(n, typesize);
	else
		return malloc(typesize * n);
}
void* heaprealloc(void* buf, size_t typesize, size_t n)
{
	return realloc(buf, typesize * n);
}
void  heapfree (void* buf)
{
	free(buf);
}
