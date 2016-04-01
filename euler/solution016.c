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
 * Problem 016: Power digit sum
 * 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
 *
 * What is the sum of the digits of the number 2^1000?
 */

#include "solution.h"
#include <ctype.h>
#include <stdlib.h>
#include <gmp.h>

#define LIMIT 1000

static eu_result_t solve() {
    mpz_t number;
    mpz_init_set_ui(number, 2);
    mpz_pow_ui(number, number, LIMIT);
    eu_result_t sum = 0;
    char *str = mpz_get_str(NULL, 10, number);
    for (const char *ptr = str; *ptr != '\0'; ++ptr) {
        if (isdigit(*ptr)) {
            sum += (eu_result_t)(*ptr - '0');
        }
    }
    free(str);
    mpz_clear(number);
    return sum;
}

const eu_solution_t eu_solution016 = {16, solve};
