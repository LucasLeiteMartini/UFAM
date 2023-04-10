#include <stdio.h>


int main(){
	
	int a = 0, b = 0, c = 0, mediana = 0;
	
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&c);
	
	
	if(a >= b && a <= c || a <= b && a >= c){
		mediana = a;
	}else if(b >= a && b <= c || b <= a && b >= c){
		mediana = b;
	}else{
		mediana = c;
	}
	
	
	printf("%d",mediana);
	
	return 0;
}