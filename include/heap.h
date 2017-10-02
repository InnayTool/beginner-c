#include "types.h"

void* heapalloc(size_t typesize, size_t n, bool clear);
void* heaprealloc(void* buf, size_t typesize, size_t n);
void  heapfree (void* buf);