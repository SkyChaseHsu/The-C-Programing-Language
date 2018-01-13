#include<stdio.h>

// switch th celsius into fahr

int main()
{
	int upper, lower, step;
	float celsius, fahr;

	upper = 300;
	lower = 0;
	celsius = lower;
	step = 20;

	printf("Temperature Switch\n");
	printf("\n");

	while(fahr <= upper){
		fahr = celsius * 1.8 + 32.0;
		printf("%3.1f \t %3.1f\n", celsius, fahr);
		celsius = celsius + 20;
	}
}