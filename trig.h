/*
These functions return the sine and cosine of a floating point input.
This is done through by implementing the taylor series.
Because the taylor series is unstable after PI/2, the double angle formula is used for values larger than PI/2
Input - 
	x - a floating point value that can range from -PI to PI. 
Returns
	floating point value of the sine or cosine of x respectively
	sine and cosine are undefined for x out of bounds.
*/

#ifndef TRIG_H
#define TRIG_H

#define PI 3.14159265

int factorial(int a); 
float sine(float x);
float cosine(float x);
void init_and_lookup(int k, int b, float* cosine_value, float* sine_value);
float mult_real_fft(float q, float w, float cosine_value, float sine_value);
float mult_im_fft(float q, float w, float cosine_value, float sine_value);
#endif
