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
 * Problem 010: Summation of primes
 * The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 *
 * Find the sum of all the primes below two million.
 */

#include "solution.h"
#include <stdbool.h>
#include <math.h>

#define LIMIT 2000000

static eu_result_t solve() {
    /* 206773 is an overestimation of the number of primes below 2000000, as
     * calculated using the approximation n/ln(n), multipled with 3/2 for good
     * measure, as the aforementioned approximation is less than the true
     * number of primes */
    eu_result_t table[206773] = {2, 3}; /* After these, gap >= 2 */
    size_t count = sizeof table / sizeof *table;
    size_t index = 2; /* 2 primes are pre-calculated above */
    eu_result_t sum = 2 + 3; /* The sum of the pre-calculated primes */
    for (eu_result_t number = 5; index < count && number < LIMIT; number += 2) {
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
            sum += number;
        }
    }
    return sum;
}

const eu_solution_t eu_solution010 = {10, solve};
