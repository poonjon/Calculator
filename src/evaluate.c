#include <stdio.h>
#include <string.h>
#include "Stack.h"
#include "Token.h"
#include "evaluate.h"
#include "Error.h"


int evaluate(char *expression, Stack *operatorStack, Stack *dataStack){
	Tokenizer *tokenizer;
	OperatorToken *operator;
	NumberToken *number;
	int i;
	
	tokenizer = tokenizerNew(expression);
	number = (NumberToken *)nextToken(tokenizer);
	if(number->type != NUMBER_TOKEN)
		Throw(ERR_NOT_OPERATOR);
		
	else{
		for(i=0; (operator != NULL || number != NULL) ; i++ ){
			
			if(number == NULL){
				Throw(ERR_NOT_OPERATOR);
			}
			
			else{
				push(dataStack, number);
				operator = (OperatorToken *)nextToken(tokenizer);
				operator_check(operator);	
					
				if(operator != NULL){
					push(operatorStack, operator);
				}
				else if(operator == NULL){
					evaluateAllOperatorsOnStack(operatorStack, dataStack);
					return 1;
				}
				else{
					Throw(ERR_NOT_OPERATOR);
				}
				
				number = (NumberToken *)nextToken(tokenizer);
				if(number->type != NUMBER_TOKEN || number == NULL)
					Throw(ERR_NOT_OPERATOR);
				else{
					push(dataStack, number);
					operator = (OperatorToken *)nextToken(tokenizer);
					
					if(operator == NULL){
						evaluateAllOperatorsOnStack(operatorStack, dataStack);
						return 1;
					}
					else if(operator != NULL){
						push(operatorStack, operator);
						number = (NumberToken *)nextToken(tokenizer);
					}
					else
						Throw(ERR_NOT_OPERATOR);
				}
			}
		}
	}
	
	evaluateAllOperatorsOnStack(operatorStack, dataStack);
	
}

void tryEvaluateOperatorsOnStackThenPush(Stack *operatorStack, Stack *dataStack, OperatorToken *operator){
	int i;
	int precedence_old, precedence_new;
	OperatorToken *token;
	
	token = pop(operatorStack);
	precedence_old = token->precedence;
	precedence_new = operator->precedence;
	
	if(precedence_old < precedence_new){
		push(operatorStack, token);
		push(operatorStack, operator);
	}
	
	else if(precedence_old > precedence_new){
		evaluateOperator(dataStack, token);
	}
	
	else
		Throw(ERR_INVALID_TOKEN);
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