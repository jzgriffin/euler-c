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
 * Problem 019: Counting Sundays
 * You are given the following information, but you may prefer to do some
 * research for yourself.
 *
 * - 1 Jan 1900 was a Monday.
 * - Thirty days has September,
 *   April, June and November.
 *   All the rest have thirty-one,
 *   Saving February alone,
 *   Which has twenty-eight, rain or shine.
 *   And on leap years, twenty-nine.
 * - A leap year occurs on any year evenly divisible by 4, but not on a
 *   century unless it is divisible by 400.
 *
 * How many Sundays fell on the first of the month during the twentieth
 * century (1 Jan 1901 to 31 Dec 2000)?
 */

#include "solution.h"
#include <stdbool.h>

static eu_result_t days_in_month(eu_result_t year, eu_result_t month) {
    const static eu_result_t days[] =
        {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 1) { /* February has variable length */
        bool is_leap = year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
        return days[month] + (is_leap ? 1 : 0);
    }
    return days[month];
}

static eu_result_t solve() {
    eu_result_t year = 1900;
    eu_result_t month = 0;
    eu_result_t day = 0;
    eu_result_t weekday = 0;
    eu_result_t length = days_in_month(year, month);
    eu_result_t sum = 0;
    while (year != 2001 || month != 0 || day != 0) {
        if (year >= 1901 && day == 0 && weekday == 6) {
            ++sum;
        }
        ++day;
        if (day == length) {
            day = 0;
            ++month;
            if (month == 12) {
                month = 0;
                ++year;
            }
        }
        ++weekday;
        if (weekday == 7) {
            weekday = 0;
        }
    }
    return sum;
}

const eu_solution_t eu_solution019 = {19, solve};
