#ifndef OPTIONS_H_
#define OPTIONS_H_

#define QUEUE_SIZE 1024*1024

#include <stdio.h>
#include "types.h"

#include "limits.h"

typedef struct {
	char short_char;
	char long_char[10];
	char long_name[20];
	char description[1000];
} option_t;

typedef struct {
	char *filename_in;
	char *filename_out;

	char *mode_string;
	int mode;

	int channels;
	int order;

	int print_every;

	int use_void;
	int seed;

/* Correlate */
	uint64_t queue_size;
	uint64_t max_time_distance;
	uint64_t min_time_distance;
	uint64_t max_pulse_distance;
	uint64_t min_pulse_distance;
	int positive_only;
	int start_stop;

/* Intensity */
	uint64_t bin_width;
	int count_all;
	int set_start_time;
	int64_t start_time;
	int set_stop_time;
	int64_t stop_time;

/* Histogram */
	char *time_string;
	limits_t time_limits;
	char *pulse_string;
	limits_t pulse_limits;
	
	char *time_scale_string;
	int time_scale;
	char *pulse_scale_string;
	int pulse_scale;

/* Channels */
	int suppress_channels;
	char *suppress_string;
	int *suppressed_channels;

	int offset_time;
	char *time_offsets_string;
	int64_t *time_offsets;

	int offset_pulse;
	char *pulse_offsets_string;
	int64_t *pulse_offsets;

/* correlate_vector */
	int approximate;
	int true_autocorrelation;

/* gn */
	int exact_normalization;

/* t2_to_t3 */
	int64_t repetition_time;
} options_t;

typedef struct {
	char message[10000];
	int options[100];
} program_options_t;

enum { OPT_HELP, OPT_VERSION,
		OPT_VERBOSE, OPT_PRINT_EVERY,
		OPT_FILE_IN, OPT_FILE_OUT,
		OPT_MODE, OPT_CHANNELS, OPT_ORDER,
		OPT_USE_VOID, OPT_SEED,
		OPT_QUEUE_SIZE, 
		OPT_START_TIME, OPT_STOP_TIME,
		OPT_MAX_TIME_DISTANCE, OPT_MIN_TIME_DISTANCE,
		OPT_MAX_PULSE_DISTANCE, OPT_MIN_PULSE_DISTANCE,
		OPT_POSITIVE_ONLY, OPT_START_STOP,
		OPT_BIN_WIDTH, OPT_COUNT_ALL,
		OPT_TIME, OPT_PULSE, OPT_TIME_SCALE, OPT_PULSE_SCALE,
		OPT_TIME_OFFSETS, OPT_PULSE_OFFSETS, 
		OPT_SUPPRESS,
		OPT_APPROXIMATE, OPT_TRUE_CORRELATION,
		OPT_EXACT_NORMALIZATION, 
		OPT_REPETITION_TIME,
		OPT_EOF };

void default_options(options_t *options);
int validate_options(program_options_t *program_options, options_t *options);

int parse_options(int argc, char *argv[], options_t *options, 
		program_options_t *program_options);
void usage(int argc, char *argv[], 
		program_options_t *program_options);
void version(int argc, char *argv[]);
int is_option(int option, program_options_t *program_options);
char *make_option_string(program_options_t *program_options);
void free_options(options_t *options);
char *get_options_string(program_options_t *program_options);

int read_offsets(options_t *options);
int parse_offsets(char *offsets_string, int64_t **offsets,
		options_t *options);
int parse_suppress(options_t *options);

#endif
