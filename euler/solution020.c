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
 * Problem 020: Factorial digit sum
 * n! means n × (n − 1) × ... × 3 × 2 × 1
 *
 * For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
 * and the sum of the digits in the number 10! is
 * 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
 *
 * Find the sum of the digits in the number 100!
 */

#include "solution.h"
#include <ctype.h>
#include <stdlib.h>
#include <gmp.h>

static eu_result_t solve() {
    mpz_t factorial;
    mpz_init(factorial);
    mpz_fac_ui(factorial, 100);
    char *str = mpz_get_str(NULL, 10, factorial);
    eu_result_t sum = 0;
    for (const char *ptr = str; *ptr != '\0'; ++ptr) {
        if (isdigit(*ptr)) {
            sum += *ptr - '0';
        }
    }
    free(str);
    mpz_clear(factorial);
    return sum;
}

const eu_solution_t eu_solution020 = {20, solve};
