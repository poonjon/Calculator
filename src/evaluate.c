#include <stdio.h>
#include <string.h>
#include "Stack.h"
#include "Token.h"
#include "evaluate.h"
#include "Error.h"


int evaluate(char *expression, Stack *operatorStack, Stack *dataStack){
	int i;
	Tokenizer *tokenizer;
	OperatorToken *operator;
	NumberToken *number;
	NumberToken *result;
	
	tokenizer = tokenizerNew(expression);
	number = (NumberToken *)nextToken(tokenizer);
	check_number(number);
		
	for(i=0; (operator != NULL || number != NULL) ; i++ ){
	
		
		if(i == 0){
			push(dataStack, number);
			
			operator = (OperatorToken *)nextToken(tokenizer);
			check_operator(operator);	
			push(operatorStack, operator);
			
			number = (NumberToken *)nextToken(tokenizer);
			check_number(number);
		}
		
		else if(i != 0){
			push(dataStack, number);
			
			operator = (OperatorToken *)nextToken(tokenizer);
			if(operator == NULL)
				break;
			check_operator(operator);	
			tryEvaluateOperatorsOnStackThenPush(operatorStack, dataStack, operator);
			
			number = (NumberToken *)nextToken(tokenizer);
			check_number(number);
		}		
	}
	
	evaluateAllOperatorsOnStack(operatorStack, dataStack);

}
	
void tryEvaluateOperatorsOnStackThenPush(Stack *operatorStack, Stack *dataStack, OperatorToken *operator){
	int i;
	int precedence_old, precedence_new;
	OperatorToken *token;
	
	precedence_new = operator->precedence;
	
	token = pop(operatorStack);
	for(i =0 ; token != NULL ; i++){ 
	
		precedence_old = token->precedence;
		
		if(token == NULL){
			push(operatorStack, operator);
			break;
		}
		
		else if(precedence_old < precedence_new){
			push(operatorStack, token);
			push(operatorStack, operator);
			break;
		}
		
		else if(precedence_old > precedence_new || precedence_old == precedence_new){
			evaluateOperator(dataStack, token);
						
		}
		
		else
			Throw(ERR_INVALID_TOKEN);
	}
}

void evaluateAllOperatorsOnStack(Stack *operatorStack, Stack *dataStack){
	int i;
	OperatorToken *token;
		
		token = pop(operatorStack);
		for(i =0 ; token != NULL ; i++){
			evaluateOperator(dataStack, token);
			token = pop(operatorStack);
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
			result = createNumberToken(left->value + right->value);
			push(dataStack, result);
			break;
			
		case 1:
			right = pop(dataStack);
			left = pop(dataStack);
			result = createNumberToken(left->value - right->value);
			push(dataStack, result);
			break;
		
		case 2:
			right = pop(dataStack);
			left = pop(dataStack);
			result = createNumberToken(left->value ^ right->value);
			push(dataStack, result);
			break;
			
		case 3:
			right = pop(dataStack);
			left = pop(dataStack);
			result = createNumberToken(left->value * right->value);
			push(dataStack, result);
			break;
		
		case 4:
			right = pop(dataStack);
			left = pop(dataStack);
			result = createNumberToken(left->value / right->value);
			push(dataStack, result);
			break;
			
		case 5:
			right = pop(dataStack);
			left = pop(dataStack);
			result = createNumberToken(left->value % right->value);
			push(dataStack, result);
			break;
			
		case 6:
			right = pop(dataStack);
			left = pop(dataStack);
			result = createNumberToken(left->value & right->value);
			push(dataStack, result);
			break;
			
		case 7:
			right = pop(dataStack);
			left = pop(dataStack);
			result = createNumberToken(left->value | right->value);
			push(dataStack, result);
			break;
		
		default: 
			Throw(ERR_NOT_OPERATOR);
	}
}

void check_number(NumberToken *number){
		
		if(number->type != NUMBER_TOKEN)
			Throw(ERR_NOT_DATA);
}

void check_operator(OperatorToken *operator){
		
		if(operator->type != OPERATOR_TOKEN)
			Throw(ERR_NOT_OPERATOR);
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