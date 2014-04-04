#ifndef Token_H
#define Token_H

typedef enum{UNKNOWN_TOKEN, NUMBER_TOKEN, OPERATOR_TOKEN} TokenType;

typedef struct{
	TokenType type;
}Token;

typedef struct{
	TokenType type;
	int value;
}NumberToken;

typedef struct{
	TokenType type;
	char *name;
	int precedence;
}OperatorToken;

typedef struct{
	char *expression;
	int startIndex;
}Tokenizer;

NumberToken *createNumberToken(int value);
Tokenizer *tokenizerNew(char *text);
Token *nextToken(Tokenizer *tokenizer);

#endif // Token_H
