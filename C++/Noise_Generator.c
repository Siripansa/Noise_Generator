
#include "array_io.h"

#include <stdint.h>
#include <math.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void array_io (dout_t d_o[N], din_t d_i[N]) {
	int i;
	
	// Store accumulated data
	float bpsk[N] ;

	unsigned long s0 =1000;
	unsigned long s1 =2000;
	unsigned long s2 =3000;
	unsigned long b1;
	unsigned long b2;
	unsigned long random1;
	unsigned long random2;
	float random[N];

// Accumulate each channel
	For_Loop: for (i=0;i<N;i++)
	{

b1 = (((s0 << 13) ^ s0 ) >> 19);
s0 = (((s0 & 0xFFFFFFFF) << 12)^b1);

b1 = (((s1 << 2) ^ s1 ) >> 25);
s1 = (((s1 & 0xFFFFFFF8) << 4)^b1);


b1 = (((s2 << 3) ^ s2 ) >> 11);
s2 = (((s2 & 0xFFFFFFF0) << 17)^b1);

random1 = s0^s1^s2 ;

b2 = (((s0 << 13) ^ s0 ) >> 19);
s0 = (((s0 & 0xFFFFFFFF) << 12)^b2);

b2 = (((s1 << 2) ^ s1 ) >> 25);
s1 = (((s1 & 0xFFFFFFF8) << 4)^b2);

b2 = (((s2 << 3) ^ s2 ) >> 11);
s2 = (((s2 & 0xFFFFFFF0) << 17)^b2);

random2 = s0^s1^s2 ;

float random1_d = (float)random1;
float random2_d = (float)random2;

//fprintf(stdout,"random1 = %f\n", random2_d); //

float RandMax = 4294967295;

float drand1;
float drand2;


drand1 = (random1_d + 1)/(RandMax+ 1) ;
drand2 = (random2_d + 1)/(RandMax+ 1) ;



random[i] = (sqrt(-2*log(drand1)))*(cos(2*3.1415926538979323846*drand2));



		bpsk[i] = (2*d_i[i])-1;
		d_o[i] = (random[i]*var) + bpsk[i];

	}
}











