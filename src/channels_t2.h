#ifndef CHANNELS_T2_H_
#define CHANNELS_T2_H_

#include <stdio.h>

#include "options.h"
#include "t2.h"

int channels_t2(FILE *in_stream, FILE *out_stream, options_t *options);
void offset_t2(t2_t *record, options_t *options);

void yield_sorted_t2(FILE *out_stream, t2_queue_t *queue, 
		int64_t max_offset_difference, options_t *options);

#endif