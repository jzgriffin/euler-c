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
 * Problem 004: Largest palindrome product
 * A palindromic number reads the same both ways. The largest palindrome made
 * from the product of two 2-digit numbers is 9009 = 91 × 99.
 *
 * Find the largest palindrome made from the product of two 3-digit numbers.
 */

#include "solution.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

static bool is_palindrome(eu_result_t num) {
    char str[20];
    int len = sprintf(str, "%" EU_RESULT_PRI, num);
    for (char *i = str + len - 1, *j = str; *j != '\0'; --i, ++j) {
        if (*i != *j) {
            return false;
        }
    }
    return true;
}

static eu_result_t solve() {
    eu_result_t number = 0;
    for (eu_result_t a = 999; a >= 100; --a) {
        for (eu_result_t b = 999; b >= 100; --b) {
            eu_result_t product = a * b;
            if (product > number && is_palindrome(product)) {
                number = product;
            }
        }
    }
    return number;
}

const eu_solution_t eu_solution004 = {4, solve};
