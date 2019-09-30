//*****************************************************************************
// tlib-c
//
// File:   array.h
// Author: Martin Dorazil
// Date:   29/9/2019
//
// Copyright 2019 Martin Dorazil
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//*****************************************************************************

#ifndef T_ARRAY_H
#define T_ARRAY_H

#include "tlib/common.h"

#define TARRAY_FOREACH(T, _arr, _it)                                                               \
	if ((_arr) && (_arr)->size)                                                                \
		for (usize i = 0; i < (_arr)->size && ((_it) = tarray_at(T, (_arr), i)); ++i)

typedef struct TArray {
	void *data;
	usize size;
	usize allocated;
	usize elem_size;
} TArray;

/* clang-format off */
/* Create new array on heap. */
T_API TArray *
tarray_new(usize elem_size);

/* Delete array on heap. */
T_API void
tarray_delete(TArray *arr);

/* Initialize array. */
T_API void 
tarray_init(TArray *arr, usize elem_size);

/* Terminate array. */
T_API void
tarray_terminate(TArray *arr);

T_API void
tarray_reserve(TArray *arr, usize size);

T_API void
tarray_clear(TArray *arr);

T_API void
_tarray_push(TArray *arr, void *v_ptr);

#define tarray_at(T, _arr, _i) (*(T *)_tarray_at((_arr), (_i)))

T_API void *
_tarray_at(TArray *arr, usize i);

#define tarray_push(_arr, _v) _tarray_push((_arr), &(_v))

T_API void
tarray_pop(TArray *arr);

T_API void
tarray_erase(TArray *arr, usize i);

/* clang-format on */

#endif
