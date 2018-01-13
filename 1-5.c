#include<stdio.h>

int main()
{
	float fahr;

	for (fahr = 300; fahr >= 0; fahr = fahr - 20){
		printf("%3.1f \t %6.1f\n", fahr, (fahr - 32)/1.8);
	}
}