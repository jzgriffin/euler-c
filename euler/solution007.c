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
 * Problem 007: 10001st prime
 * By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see
 * that the 6th prime is 13.
 *
 * What is the 10001st prime number?
 */

#include "solution.h"
#include <math.h>
#include <stdbool.h>

#define INDEX 10001

static eu_result_t solve() {
    eu_result_t table[INDEX] = {2, 3}; /* After these, gap >= 2 */
    size_t count = sizeof table / sizeof *table;
    size_t index = 2; /* 2 primes are pre-calculated above */
    for (eu_result_t number = 5; index < count; number += 2) {
        eu_result_t root = (eu_result_t)(0.5 + sqrt(number));
        bool prime = true;
        for (size_t i = 0; i < index && table[i] <= root; ++i) {
            if (number % table[i] == 0) {
                prime = false;
                break;
            }
        }
        if (prime) {
            table[index++] = number;
        }
    }
    return table[index - 1];
}

const eu_solution_t eu_solution007 = {7, solve};
