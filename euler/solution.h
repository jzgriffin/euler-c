/*
 * Project Euler in C
 * Copyright (c) Jeremiah Griffin 2016
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef EULER_SOLUTION_H
#define EULER_SOLUTION_H

#include <inttypes.h>
#include <stddef.h>

#define EU_RESULT_MIN INT64_MIN
#define EU_RESULT_MAX INT64_MAX
#define EU_RESULT_PRI PRId64

typedef int64_t eu_result_t;
typedef eu_result_t (*eu_solver_t)();

typedef struct {
    size_t number;
    eu_solver_t solver;
} eu_solution_t;

extern const size_t eu_solution_count;
extern const eu_solution_t *const eu_solutions[];

#endif /* EULER_SOLUTION_H */
