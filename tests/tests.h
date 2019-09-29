#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tlib/tlib.h"

#define ASSERT(e)                                                                                  \
	if (!(e)) {                                                                                \
		printf("##e\n");                                                                   \
		abort();                                                                           \
	}
