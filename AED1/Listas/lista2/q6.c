#include <stdio.h>

int main() {
 unsigned int dimensao, l, c;
	
 scanf("%u%*c",&dimensao);
	
	
 for( l=0; l < dimensao; l++) {
	for( c=0; c < dimensao; c++) {
		if((l==0) || (l == dimensao-1) || (c == 0) || (c == dimensao - 1)) {
		 printf("1");
		}
		else if(l == c || l + c == dimensao - 1){
			printf("1");
		}
		else {
		 printf("o");
		}
	}
	printf("\n");
 }
}