#include "calculate.c"
#include <stdio.h>
#include <string.h>
#define MAX 500
#define PROMPT ">>> "

int main() {
	
	char expression[MAX];
	printf("Enter expression else press q to exit\n");

	while(1) {
		printf(PROMPT);
		scanf("%[^\n]%*c",expression);
		
		if (strcmp(expression,"q") == 0)
			break;
		printf("Ans-> %f\n", calculate(expression));
	}

	return 0;
}
