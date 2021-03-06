/*
 * Copyright (c) 2011-2015, Thomas Bischof
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice, 
 *    this list of conditions and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the above copyright notice, 
 *    this list of conditions and the following disclaimer in the documentation 
 *    and/or other materials provided with the distribution.
 * 
 * 3. Neither the name of the Massachusetts Institute of Technology nor the 
 *    names of its contributors may be used to endorse or promote products 
 *    derived from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE 
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef RANGE_H_
#define RANGE_H_

#include <stdio.h>

typedef struct {
	int yielded;
	unsigned int start;
	unsigned int stop;
	unsigned int value;
} range_t;

typedef struct {
	unsigned int dimensions;
	range_t **ranges;
} ranges_t;

range_t *range_alloc(void);
void range_init(range_t *range);
void range_set_stop(range_t *range, unsigned int const stop);
void range_set_start(range_t *range, unsigned int const start);
int range_next(range_t *range);
void range_free(range_t **range);

ranges_t *ranges_alloc(unsigned int const dimensions);
void ranges_init(ranges_t *ranges);
void ranges_free(ranges_t **ranges);
int ranges_set_start(ranges_t *ranges, unsigned int const dimension, 
		unsigned int const start);
void ranges_set_starts(ranges_t *ranges, unsigned int const start);
int ranges_set_stop(ranges_t *ranges, unsigned int const dimension, 
		unsigned int const stop);
void ranges_set_stops(ranges_t *ranges, unsigned int const stop);
int ranges_next(ranges_t *ranges);

int ranges_fprintf(FILE *stream_out, ranges_t const *ranges);

#endif
