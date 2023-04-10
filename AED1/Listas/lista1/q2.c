#include <stdio.h>

int main() {

	float a, b, c, media = 0.0;
	
	scanf("%f",&a);
	scanf("%f",&b);
	scanf("%f",&c);
	
	
	media = (a+b+c) / 3;
	
	printf("%.2f", media);
	
	return 0;
}