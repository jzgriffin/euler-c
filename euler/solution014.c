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
 * Problem 014: Longest Collatz sequence
 * The following iterative sequence is defined for the set of positive
 * integers:
 *
 * n → n/2 (n is even)
 * n → 3n + 1 (n is odd)
 *
 * Using the rule above and starting with 13, we generate the following
 * sequence:
 *
 * 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
 * It can be seen that this sequence (starting at 13 and finishing at 1)
 * contains 10 terms. Although it has not been proved yet (Collatz Problem),
 * it is thought that all starting numbers finish at 1.
 *
 * Which starting number, under one million, produces the longest chain?
 *
 * NOTE: Once the chain starts the terms are allowed to go above one million.
 */

#include "solution.h"

#define LIMIT 1000000

static eu_result_t chain(eu_result_t number) {
    static eu_result_t known[LIMIT + 1] = {0,};
    eu_result_t steps = 1;
    eu_result_t n = number;
    for (; n > 1 && steps < EU_RESULT_MAX; ++steps) {
        if (n <= LIMIT && known[n] != 0) {
            steps += known[n];
            known[number] = steps;
            return steps;
        }
        if ((n & 1) != 0) {
            n = 3 * n + 1;
        }
        else {
            n /= 2;
        }
    }
    known[number] = steps;
    return steps;
}

static eu_result_t solve() {
    eu_result_t length = 0;
    eu_result_t number = 0;
    for (eu_result_t i = 1; i <= LIMIT; ++i) {
        eu_result_t steps = chain(i);
        if (steps > length) {
            length = steps;
            number = i;
        }
    }
    return number;
}

const eu_solution_t eu_solution014 = {14, solve};
