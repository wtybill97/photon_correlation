#ifndef T3_VOID_H_
#define T3_VOID_H_

#include "t3.h"

typedef int (*t3v_next_t)(FILE *, void *);
typedef int (*t3v_print_t)(FILE *, void const *);

int t3v_fread(FILE *stream_in, void *photon);
int t3v_fscanf(FILE *stream_in, void *photon);
int t3v_fprintf(FILE *stream_out, void const *photon);
int t3v_fwrite(FILE *stream_out, void const *photon);

int64_t t3v_window_dimension(void const *photon);
int64_t t3v_channel_dimension(void const *photon);

#define T3V_NEXT(x) (x ? t3v_fread : t3v_fscanf);
#define T3V_PRINT(x) (x ? t3v_fwrite : t3v_fprintf);

#endif