#ifndef T3_H_
#define T3_H_

#include <stdio.h>
#include "options.h"
#include "types.h"

typedef struct {
	int32_t channel;
	int64_t pulse;
	int64_t time;
} t3_t;

typedef struct {
	int32_t length;
	int64_t left_index;
	int64_t right_index;
	t3_t *queue;
} t3_queue_t;

int next_t3(FILE *stream_in, t3_t *record, options_t *options);
void print_t3(FILE *stream_out, t3_t *record, 
		int print_newline, options_t *options);
int t3_comparator(const void *a, const void *b);

t3_queue_t *allocate_t3_queue(int queue_length);
void free_t3_queue(t3_queue_t **queue);
int t3_queue_full(t3_queue_t *queue);
int t3_queue_pop(t3_queue_t *queue, t3_t *record);
int t3_queue_push(t3_queue_t *queue, t3_t *record);
int t3_queue_front(t3_queue_t *queue, t3_t *record);
int t3_queue_back(t3_queue_t *queue, t3_t *record);
int t3_queue_index(t3_queue_t *queue, t3_t *record, int index);
int64_t t3_queue_size(t3_queue_t *queue);
void t3_queue_sort(t3_queue_t *queue);
void yield_t3_queue(FILE *stream_out, t3_queue_t *queue, options_t *options);

/* The windowed stream represents a series of streams which are composed of
 * photons in some time window. For example, an intensity stream can be 
 * generated by counting all photons in 50ms bins, so we want to be able
 * to produce all photons in consecutive 50ms windows.
 */
typedef struct {
	window_t limits;
	int64_t width;
	int set_pulse_limit;
	int64_t pulse_limit;
} t3_window_t;

typedef struct {
	t3_t current_photon;
	int yielded_photon;
	t3_window_t window;
	FILE *stream_in;
} t3_windowed_stream_t;

void init_t3_window(t3_window_t *window, 
		int64_t start_pulse, options_t *options);
void next_t3_window(t3_window_t *window);
int init_t3_windowed_stream(t3_windowed_stream_t *stream,
		FILE *stream_in, options_t *options);
int next_t3_windowed(t3_windowed_stream_t *stream, t3_t *record,
		options_t *options);

#endif
