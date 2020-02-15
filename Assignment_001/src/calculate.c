#include <stdio.h>
#include <string.h>
#include <ctype.h>


int precedence(char op){ 
	if(op == '+'||op == '-') 
	return 1; 
	if(op == '*'||op == '/') 
	return 2; 
	return 0; 
} 


int applyOp(int a, int b, char op){ 
	switch(op){ 
		case '+': return a + b; 
		case '-': return a - b; 
		case '*': return a * b; 
		case '/': return a / b; 
	} 
}

float calculate(char* expression) {
	int stackSize = 500;

	float values[stackSize];
	int valuesTop = -1;

	char ops[stackSize];
	int opsTop = -1;

	for (int i=0; i<strlen(expression); i++){
		
		if (expression[i] == ' ')
			continue;

		else if (expression[i] == '('){
			ops[++opsTop] = expression[i];
		}

		else if (isdigit(expression[i])) {
			float val = 0;

			while((i < strlen(expression)) && (isdigit(expression[i])) ) {
				val = (val*10) + (expression[i] - '0');
				i++;
			}
			
			//-------------
			i--;
			values[++valuesTop] = val;
		}

		else if (expression[i] == ')') {

			while ((opsTop != -1) && (ops[opsTop] != '(')) {
				float arg2 = values[valuesTop];
				valuesTop--;

				float arg1 = values[valuesTop];
				valuesTop--;

				char operator = ops[opsTop];
				opsTop--;

				values[++valuesTop] = applyOp(arg1, arg2, operator);
			}

			if(opsTop != -1) {
				opsTop--;
			}
		}

		else {
			while((opsTop != -1) && precedence(ops[opsTop]) >= precedence(expression[i])){

				float arg2 = values[valuesTop];
				valuesTop--;

				float arg1 = values[valuesTop];
				valuesTop--;

				char operator = ops[opsTop];
				opsTop--;

				values[++valuesTop] = applyOp(arg1, arg2, operator);
			}

			ops[++opsTop] = expression[i]; 
		}
	}

	while (opsTop != -1) {
		float arg2 = values[valuesTop];
		valuesTop--;

		float arg1 = values[valuesTop];
		valuesTop--;

		char operator = ops[opsTop];
		opsTop--;

		values[++valuesTop] = applyOp(arg1, arg2, operator);
	}

	return values[valuesTop];
}
