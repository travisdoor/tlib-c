#include "tests.h"

int
main(void)
{
	TList *list = tlist_new(sizeof(s32));
	ASSERT(list->data_size == sizeof(s32));
	ASSERT(list->begin == &list->end);
	ASSERT(list->size == 0);

	for (s32 i = 0; i < 100; ++i) {
		tlist_push_back(list, i);
	}

	ASSERT(list->size == 100);

	tlist_delete(list);
	return 0;
}
