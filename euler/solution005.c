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
 * Problem 005: Smallest multiple
 * 2520 is the smallest number that can be divided by each of the numbers from
 * 1 to 10 without any remainder.
 *
 * What is the smallest positive number that is evenly divisible by all of the
 * numbers from 1 to 20?
 */

#include "solution.h"

#define MINIMUM 2520

static eu_result_t solve() {
    const eu_result_t lcm = MINIMUM;
    eu_result_t number = 0;
    for (eu_result_t i = lcm; i < EU_RESULT_MAX; i += lcm) {
        /* This reduced set is the smallest set of factors that span [1,20]
         *     20: 20, 10, 5, 4, 2
         *     19: 19
         *     18: 18, 9, 6, 3, 2
         *     17: 17
         *     16: 16, 8, 4, 2
         *     14: 14, 7, 2
         *     13: 13
         *     11: 11 */
        if (i % 20 == 0 && i % 19 == 0 && i % 18 == 0 && i % 17 == 0 &&
                i % 16 == 0 && i % 14 == 0 && i % 13 == 0 && i % 11 == 0) {
            number = i;
            break;
        }
    }
    return number;
}

const eu_solution_t eu_solution005 = {5, solve};
