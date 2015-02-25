// http://www.appliedsoftwaredesign.com/archives/cosine-similarity-calculator
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
	float a[5] = { 1, 2, 3, 4, 5 };
	float b[5] = { 1, 2, 3, 4, 5 };
	
	float ad, bd;
	float a_sq_sum = 0, b_sq_sum = 0;
	float dot_ab = 0;
	
	int i;
	
	printf("hell world!\n");
	
	for (i = 0; i < 5; i++) {
	
		a_sq_sum += a[i] * a[i];
		b_sq_sum += b[i] * b[i];
		
		dot_ab += a[i] * b[i];
		
	}
	
	ad = sqrt(a_sq_sum);
	bd = sqrt(b_sq_sum);
	
	
	
	printf("simi = %f\n", dot_ab / (ad * bd));
	
	
	
}
