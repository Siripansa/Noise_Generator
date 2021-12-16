
#ifndef ARRAY_IO_H_
#define ARRAY_IO_H_
 
#include <stdio.h>
#include <stdbool.h>

typedef bool din_t;
typedef float dout_t;


#define N 640
#define var 0.79

void array_io (dout_t d_o[N], din_t d_i[N]);

#endif
