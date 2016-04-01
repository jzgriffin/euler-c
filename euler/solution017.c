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
 * Problem 017: Number letter counts
 * If the numbers 1 to 5 are written out in words: one, two, three, four,
 * five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
 *
 * If all the numbers from 1 to 1000 (one thousand) inclusive were written out
 * in words, how many letters would be used?
 *
 * NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and
 * forty-two) contains 23 letters and 115 (one hundred and fifteen) contains
 * 20 letters. The use of "and" when writing out numbers is in compliance with
 * British usage.
 */

#include "solution.h"

#define LIMIT 1000

/* 1    one             3
 * 2    two             3
 * 3    three           5
 * 4    four            4
 * 5    five            4
 * 6    six             3
 * 7    seven           5
 * 8    eight           5
 * 9    nine            4
 * 10   ten             3
 * 11   eleven          6
 * 12   twelve          6
 * 13   thirteen        8
 * 14   fourteen        8
 * 15   fifteen         7
 * 16   sixteen         7
 * 17   seventeen       9
 * 18   eighteen        8
 * 19   nineteen        8 */
static const eu_result_t ones[19] =
    {3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 6, 6, 8, 8, 7, 7, 9, 8, 8};

/* 20   twenty  6
 * 30   thirty  6
 * 40   forty   5
 * 50   fifty   5
 * 60   sixty   5
 * 70   seventy 7
 * 80   eighty  6
 * 90   ninety  6 */
static const eu_result_t tens[8] =
    {6, 6, 5, 5, 5, 7, 6, 6};

static const eu_result_t hundred = 7;
static const eu_result_t thousand = 8;
static const eu_result_t and = 3;

static eu_result_t count(eu_result_t i) {
    if (i >= 1 && i <= 19) {
        return ones[i - 1];
    } else if (i >= 20 && i <= 99) {
        return tens[(i / 10) - 2] + count(i % 10);
    } else if (i >= 100 && i <= 999) {
        return count(i / 100) + hundred +
            ((i % 100 == 0) ? 0 : (and + count(i % 100)));
    } else if (i >= 1000) {
        return count(i / 1000) + thousand + count(i % 1000);
    } else {
        return 0;
    }
}

static eu_result_t solve() {
    eu_result_t sum = 0;
    for (eu_result_t i = 1; i <= LIMIT; ++i) {
        sum += count(i);
    }
    return sum;
}

const eu_solution_t eu_solution017 = {17, solve};
