#include <stdio.h> 
#include <math.h>
#include <unistd.h>
int main() 
{ 
	double x; 
	x = sqrt(8.0); 
	printf("Square root of 8.0 is %f\n", x); 
	write(STDOUT_FILENO, "Hello World", 11); 
} 

