#include "tlib/tlib.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define ASSERT(e)                                                                                  \
	if (!(e)) {                                                                                \
		fprintf(stderr, "Assertion failed on line %d: '" #e "'\n", __LINE__);              \
		abort();                                                                           \
	}
