#include "String.h"
#include "Stack.h"
#include "Token.h"
#include "evaluate.h"
#include "Error.h"


int evaluate(char *expression){

}

void tryEvaluateOperatorsOnStackThenPush(Stack *operatorStack, Stack *dataStack, OperatorToken *operator){

}

void evaluateAllOperatorsOnStack(Stack *operatorStack, Stack *dataStack){
	int i;
	
	for(i = 0; operatorStack != NULL ; i++){
		OperatorToken *token = pop(operatorStack);
		evaluateOperator(dataStack, token);
	}
}

void evaluateOperator(Stack *dataStack, OperatorToken *operator){
	NumberToken *result; 
	NumberToken *right;
	NumberToken *left;
	
	switch(operator_check(operator)){
		case 0:
			right = pop(dataStack);
			left = pop(dataStack);
			result = createNumberToken(right->value + left->value);
			push(dataStack, result);
			break;
			
		case 1:
			right = pop(dataStack);
			left = pop(dataStack);
			result = createNumberToken(right->value - left->value);
			push(dataStack, result);
			break;
		
		case 2:
			right = pop(dataStack);
			left = pop(dataStack);
			result = createNumberToken(right->value ^ left->value);
			push(dataStack, result);
			break;
			
		case 3:
			right = pop(dataStack);
			left = pop(dataStack);
			result = createNumberToken(right->value * left->value);
			push(dataStack, result);
			break;
		
		case 4:
			right = pop(dataStack);
			left = pop(dataStack);
			result = createNumberToken(right->value / left->value);
			push(dataStack, result);
			break;
			
		case 5:
			right = pop(dataStack);
			left = pop(dataStack);
			result = createNumberToken(right->value % left->value);
			push(dataStack, result);
			break;
			
		case 6:
			right = pop(dataStack);
			left = pop(dataStack);
			result = createNumberToken(right->value & left->value);
			push(dataStack, result);
			break;
			
		case 7:
			right = pop(dataStack);
			left = pop(dataStack);
			result = createNumberToken(right->value | left->value);
			push(dataStack, result);
			break;
		
		default: 
			Throw(ERR_NOT_OPERATOR);
	}
}

int operator_check(OperatorToken *operator){
	if(strcmp("+", operator->name) == 0)
		return 0;
		
	else if(strcmp("-", operator->name) == 0)
		return 1;
		
	else if(strcmp("^", operator->name) == 0)
		return 2;
		
	else if(strcmp("*", operator->name) == 0)
		return 3;
		
	else if(strcmp("/", operator->name) == 0)
		return 4;
		
	else if(strcmp("%", operator->name) == 0)
		return 5;
		
	else if(strcmp("&", operator->name) == 0)
		return 6;
		
	else if(strcmp("|", operator->name) == 0)
		return 7;
	
	else 
		Throw(ERR_NOT_OPERATOR);
		
}