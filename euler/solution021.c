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
 * Problem 021: Amicable numbers
 * Let d(n) be defined as the sum of proper divisors of n (numbers less
 * than n which divide evenly into n).
 * If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable
 * pair and each of a and b are called amicable numbers.
 *
 * For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20,
 * 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of
 * 284 are 1, 2, 4, 71 and 142; so d(284) = 220.
 *
 * Evaluate the sum of all the amicable numbers under 10000.
 */

#include "solution.h"

#define LIMIT 10000

static eu_result_t solve() {
    eu_result_t sum = 0;
    eu_result_t sums[LIMIT] = {0};
    for (eu_result_t i = 0; i < LIMIT; ++i) {
        sums[i] = 1; /* 1 is always a proper divisor */
        for (eu_result_t j = 2; j * j <= i; ++j) {
            if (i % j == 0) {
                sums[i] += j + i / j;
            }
        }
    }
    for (eu_result_t i = 0; i < LIMIT; ++i) {
        for (eu_result_t j = 0; j < LIMIT; ++j) {
            if (i != j && sums[i] == j && sums[j] == i) {
                sum += i;
            }
        }
    }
    return sum;
}

const eu_solution_t eu_solution021 = {21, solve};
