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

#include "solution.h"
#include "timer.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    eu_timer_init();

    printf("###            Time (ns)             Solution\n");
    for (size_t i = 0; i < eu_solution_count; i++) {
        const eu_solution_t *const solution = eu_solutions[i];

        eu_nsec_t ti = eu_timer_nsec();
        eu_result_t result = solution->solver();
        eu_nsec_t tf = eu_timer_nsec();

        eu_nsec_t dt = tf - ti;
        printf("%03zu % 20" EU_NSEC_PRI " % 20" EU_RESULT_PRI "\n",
                solution->number, dt, result);
    }

    eu_timer_fini();
    return EXIT_SUCCESS;
}
