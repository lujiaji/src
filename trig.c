#include "trig.h"
#include <stdio.h>
#define TABLE_SIZE 4096
float cosine_table[TABLE_SIZE];
float sine_table[TABLE_SIZE];

int factorial(int a) {
	if(a==0) return 1;
	return a*factorial(a-1);
}

float cosine(float x){
	float c,s;
	if(x > (PI/2) || x < (-PI/2)) {
		c=cosine(x/2);
		s=sine(x/2);
		return c*c-s*s;
	}
	int i,j;
	float cosine=0;
	float power;
	for(i=0;i<10;i++) {
		if(i==0) power=1;
		else power=x;
		if(i!=0) {
			for(j=0;j<i*2-1;j++)
				power*=x;
		}
		if(i%2==1)
			power*=-1;
		cosine+=power/factorial(2*i);
	}
	return cosine;
}

void Initialize() {
	    for (int i = 0; i < TABLE_SIZE; i++) {
	        float angle = -PI * i / (TABLE_SIZE / 2);
	        cosine_table[i] = cos(angle);
	        sine_table[i] = sin(angle);
	    }
}
void init_and_lookup(int k, int b, float* cosine_value, float* sine_value) {

	int index = (int)(((double)k / b) * (TABLE_SIZE / 2));
	    index = index % TABLE_SIZE;  // 防止越界
    *cosine_value = cosine_table[index];
    *sine_value = sine_table[index];
}
