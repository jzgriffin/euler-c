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

/*
 * Problem 015: Lattice paths
 * Starting in the top left corner of a 2×2 grid, and only being able to move
 * to the right and down, there are exactly 6 routes to the bottom right
 * corner.
 *
 * How many such routes are there through a 20×20 grid?
 */

#include "solution.h"

#define LIMIT 20

static eu_result_t solve() {
    eu_result_t sum[LIMIT + 1] = {1};
    for (eu_result_t i = 1; i <= LIMIT; ++i) {
        for (eu_result_t j = 1; j < i; ++j) {
            sum[j] += sum[j - 1];
        }
        sum[i] = 2 * sum[i - 1];
    }
    return sum[LIMIT];
}

const eu_solution_t eu_solution015 = {15, solve};
