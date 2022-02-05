#include <stdio.h>

long a = 10000, b, c = 2800, d, e, f[2801], g;

int main(){

	printf("Terse Version\n");
	
	for(;b-c;) f[++b]=a/5;
	for(;d=0,g=c*2;c-=14,printf("%.4ld",e+d/a),e=d%a)
		for(b=c;d+=f[b]*a,f[b]=d%--g,d/=g--,--b;d*=b); 
	


	printf("\n\nVerbose Version\n");

	a = 10000; 
	c = 2800; 
	e = 0; //re-initialize
	f[0] = 0;

	for(b = 1; b - c; b = b + 1){
		f[b] = a/5; //initialize every element in f
	}

	for(g = 0; g = c *2; c = c - 14){
		
		d = 0;	
		
 		for(b=c; b; b = b - 1){

			if(b != c){
				d = d * b;
			}
			
			d = d + f[b]*a;
			g = g -1;
			f[b] = d%g;
			d = d/g;
			g = g - 1;	

		}
		
		printf("%.4ld", e + d/a);
		e = d%a;

	}
	printf("\n");
	
	
	return 0;
}
