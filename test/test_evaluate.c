#include "unity.h"
#include "mock_Stack.h"
#include "mock_Token.h"
#include "evaluate.h"
#include "Error.h"

void setUp(void){}
void tearDown(void){}

void test_evaluate_operator_3_plus_2_expect_5_should_pass(){
	Stack dataStack;
	int error;
	
	OperatorToken operator = {.type = OPERATOR_TOKEN, .name = "+", .precedence = 70};
	NumberToken number1 = {.type = NUMBER_TOKEN, .value = 2};
	NumberToken number2 = {.type = NUMBER_TOKEN, .value = 3};
	NumberToken result = {.type = NUMBER_TOKEN, .value = 5};

	pop_ExpectAndReturn(&dataStack, &number2);
	pop_ExpectAndReturn(&dataStack, &number1);
	createNumberToken_ExpectAndReturn(5, &result);
	push_Expect(&dataStack, &result);
	
	Try{
	evaluateOperator(&dataStack, &operator);
	}Catch(error){
	TEST_ASSERT_EQUAL(2, ERR_NOT_OPERATOR);
	}
	
	TEST_ASSERT_EQUAL(5, result.value);
}

void test_evaluate_operator_3_minus_2_expect_1_should_pass(){
	Stack dataStack;
	int error;
	
	OperatorToken operator = {.type = OPERATOR_TOKEN, .name = "-", .precedence = 70};
	NumberToken number1 = {.type = NUMBER_TOKEN, .value = 2};
	NumberToken number2 = {.type = NUMBER_TOKEN, .value = 3};
	NumberToken result = {.type = NUMBER_TOKEN, .value = 1};

	pop_ExpectAndReturn(&dataStack, &number2);
	pop_ExpectAndReturn(&dataStack, &number1);
	createNumberToken_ExpectAndReturn(1, &result);
	push_Expect(&dataStack, &result);
	
	Try{
	evaluateOperator(&dataStack, &operator);
	}Catch(error){
	TEST_ASSERT_EQUAL(2, ERR_NOT_OPERATOR);
	}
	
	TEST_ASSERT_EQUAL(1, result.value);
}

void test_evaluate_operator_3_divide_2_expect_1_should_pass(){
	Stack dataStack;
	int error;
	
	OperatorToken operator = {.type = OPERATOR_TOKEN, .name = "/", .precedence = 100};
	NumberToken number1 = {.type = NUMBER_TOKEN, .value = 2};
	NumberToken number2 = {.type = NUMBER_TOKEN, .value = 3};
	NumberToken result = {.type = NUMBER_TOKEN, .value = 1};

	pop_ExpectAndReturn(&dataStack, &number2);
	pop_ExpectAndReturn(&dataStack, &number1);
	createNumberToken_ExpectAndReturn(1, &result);
	push_Expect(&dataStack, &result);
	
	Try{
	evaluateOperator(&dataStack, &operator);
	}Catch(error){
	TEST_ASSERT_EQUAL(2, ERR_NOT_OPERATOR);
	}
	
	TEST_ASSERT_EQUAL(1, result.value);
}

void test_evaluate_operator_3_modulo_2_expect_1_should_pass(){
	Stack dataStack;
	int error;
	
	OperatorToken operator = {.type = OPERATOR_TOKEN, .name = "%", .precedence = 100};
	NumberToken number1 = {.type = NUMBER_TOKEN, .value = 2};
	NumberToken number2 = {.type = NUMBER_TOKEN, .value = 3};
	NumberToken result = {.type = NUMBER_TOKEN, .value = 1};

	pop_ExpectAndReturn(&dataStack, &number2);
	pop_ExpectAndReturn(&dataStack, &number1);
	createNumberToken_ExpectAndReturn(1, &result);
	push_Expect(&dataStack, &result);
	
	Try{
	evaluateOperator(&dataStack, &operator);
	}Catch(error){
	TEST_ASSERT_EQUAL(2, ERR_NOT_OPERATOR);
	}
	
	TEST_ASSERT_EQUAL(1, result.value);
}

void test_evaluate_operator_3_multiply_2_expect_6_should_pass(){
	Stack dataStack;
	int error; 
	
	OperatorToken operator = {.type = OPERATOR_TOKEN, .name = "*", .precedence = 100};
	NumberToken number1 = {.type = NUMBER_TOKEN, .value = 3};
	NumberToken number2 = {.type = NUMBER_TOKEN, .value = 2};
	NumberToken result = {.type = NUMBER_TOKEN, .value = 6};

	pop_ExpectAndReturn(&dataStack, &number2);
	pop_ExpectAndReturn(&dataStack, &number1);
	createNumberToken_ExpectAndReturn(6, &result);
	push_Expect(&dataStack, &result);
	
	Try{
	evaluateOperator(&dataStack, &operator);
	}Catch(error){
	TEST_ASSERT_EQUAL(2, ERR_NOT_OPERATOR);
	}
	
	TEST_ASSERT_EQUAL(6, result.value);
}

void test_evaluate_operator_6_xor_5_expect_3_should_pass(){
	Stack dataStack;
	int error;
	
	OperatorToken operator = {.type = OPERATOR_TOKEN, .name = "^", .precedence = 50};
	NumberToken number1 = {.type = NUMBER_TOKEN, .value = 5};
	NumberToken number2 = {.type = NUMBER_TOKEN, .value = 6};
	NumberToken result = {.type = NUMBER_TOKEN, .value = 3};

	pop_ExpectAndReturn(&dataStack, &number2);
	pop_ExpectAndReturn(&dataStack, &number1);
	createNumberToken_ExpectAndReturn(3, &result);
	push_Expect(&dataStack, &result);
	
	Try{
	evaluateOperator(&dataStack, &operator);
	}Catch(error){
	TEST_ASSERT_EQUAL(2, ERR_NOT_OPERATOR);
	}
	
	TEST_ASSERT_EQUAL(3, result.value);
}

void test_evaluate_operator_f_and_0_expect_0_should_pass(){
	Stack dataStack;
	int error;
	
	OperatorToken operator = {.type = OPERATOR_TOKEN, .name = "&", .precedence = 20};
	NumberToken number1 = {.type = NUMBER_TOKEN, .value = 0x0};
	NumberToken number2 = {.type = NUMBER_TOKEN, .value = 0xf};
	NumberToken result = {.type = NUMBER_TOKEN, .value = 0x0};

	pop_ExpectAndReturn(&dataStack, &number2);
	pop_ExpectAndReturn(&dataStack, &number1);
	createNumberToken_ExpectAndReturn(0, &result);
	push_Expect(&dataStack, &result);
	
	Try{
	evaluateOperator(&dataStack, &operator);
	}Catch(error){
	TEST_ASSERT_EQUAL(2, ERR_NOT_OPERATOR);
	}
	
	TEST_ASSERT_EQUAL(0, result.value);
}

void test_evaluate_operator_f_or_0_expect_f_should_pass(){
	Stack dataStack;
	int error;
	
	OperatorToken operator = {.type = OPERATOR_TOKEN, .name = "|", .precedence = 10};
	NumberToken number1 = {.type = NUMBER_TOKEN, .value = 0x0};
	NumberToken number2 = {.type = NUMBER_TOKEN, .value = 0xf};
	NumberToken result = {.type = NUMBER_TOKEN, .value = 0xf};

	pop_ExpectAndReturn(&dataStack, &number2);
	pop_ExpectAndReturn(&dataStack, &number1);
	createNumberToken_ExpectAndReturn(0xf, &result);
	push_Expect(&dataStack, &result);
	
	Try{
	evaluateOperator(&dataStack, &operator);
	}Catch(error){
	TEST_ASSERT_EQUAL(2, ERR_NOT_OPERATOR);
	}
	
	TEST_ASSERT_EQUAL(0xf, result.value);
}

void test_evaluateAllOperatorsOnStack_operator_3_multiply_4_plus_2_expect_14_should_pass(){
	Stack dataStack;
	Stack operatorStack;
	int error;
	
	OperatorToken operator1 = {.type = OPERATOR_TOKEN, .name = "+", .precedence = 70};
	OperatorToken operator2 = {.type = OPERATOR_TOKEN, .name = "*", .precedence = 100};
	NumberToken number1 = {.type = NUMBER_TOKEN, .value = 2};
	NumberToken number2 = {.type = NUMBER_TOKEN, .value = 4};
	NumberToken number3 = {.type = NUMBER_TOKEN, .value = 3};
	NumberToken result1 = {.type = NUMBER_TOKEN, .value = 12};
	NumberToken result2 = {.type = NUMBER_TOKEN, .value = 14};

	pop_ExpectAndReturn(&operatorStack, &operator2);
	pop_ExpectAndReturn(&dataStack, &number3);
	pop_ExpectAndReturn(&dataStack, &number2);
	createNumberToken_ExpectAndReturn(12, &result1);
	push_Expect(&dataStack, &result1);
	
	pop_ExpectAndReturn(&operatorStack, &operator1);
	pop_ExpectAndReturn(&dataStack, &result1);
	pop_ExpectAndReturn(&dataStack, &number1);
	createNumberToken_ExpectAndReturn(14, &result2);
	push_Expect(&dataStack, &result2);
	
	pop_ExpectAndReturn(&operatorStack, NULL);
	
	evaluateAllOperatorsOnStack(&operatorStack, &dataStack);
	
	TEST_ASSERT_EQUAL(14, result2.value);
}

void test_tryEvaluateOperatorsOnStackThenPush_push_operator_should_pass(){
	Stack dataStack;
	Stack operatorStack;
	int error;
	
	OperatorToken operator1 = {.type = OPERATOR_TOKEN, .name = "+", .precedence = 70};
	OperatorToken operator2 = {.type = OPERATOR_TOKEN, .name = "*", .precedence = 100};
	NumberToken number1 = {.type = NUMBER_TOKEN, .value = 2};
	NumberToken number2 = {.type = NUMBER_TOKEN, .value = 5};
	NumberToken number3 = {.type = NUMBER_TOKEN, .value = 3};
	NumberToken result1 = {.type = NUMBER_TOKEN, .value = 15};
	NumberToken result2 = {.type = NUMBER_TOKEN, .value = 17};

	pop_ExpectAndReturn(&operatorStack, &operator1);
	push_Expect(&operatorStack, &operator1);
	push_Expect(&operatorStack, &operator2);

	tryEvaluateOperatorsOnStackThenPush(&operatorStack, &dataStack, &operator2);
	
}

void test_tryEvaluateOperatorsOnStackThenPush_should_execute_2_multiply_5_expect_10_should_pass(){
	Stack dataStack;
	Stack operatorStack;
	int error;
	
	OperatorToken operator1 = {.type = OPERATOR_TOKEN, .name = "*", .precedence = 100};
	OperatorToken operator2 = {.type = OPERATOR_TOKEN, .name = "+", .precedence = 70};
	NumberToken number1 = {.type = NUMBER_TOKEN, .value = 2};
	NumberToken number2 = {.type = NUMBER_TOKEN, .value = 5};
	NumberToken result1 = {.type = NUMBER_TOKEN, .value = 10};

	pop_ExpectAndReturn(&operatorStack, &operator1);
	pop_ExpectAndReturn(&dataStack, &number2);
	pop_ExpectAndReturn(&dataStack, &number1);
	createNumberToken_ExpectAndReturn(10, &result1);
	push_Expect(&dataStack, &result1);
	
	tryEvaluateOperatorsOnStackThenPush(&operatorStack, &dataStack, &operator2);
}

void test_evaluate_1_plus_2_expect_3_should_pass(){
	Stack dataStack;
	Stack operatorStack;
	Tokenizer tokenizer;
	int error;
	
	OperatorToken operator1 = {.type = OPERATOR_TOKEN, .name = "+", .precedence = 70};
	NumberToken number1 = {.type = NUMBER_TOKEN, .value = 1};
	NumberToken number2 = {.type = NUMBER_TOKEN, .value = 2};
	NumberToken result1 = {.type = NUMBER_TOKEN, .value = 3};

	tokenizerNew_ExpectAndReturn("1 + 2", &tokenizer);
	nextToken_ExpectAndReturn(&tokenizer, (Token *)&number1);
	push_Expect(&dataStack, &number1);
	
	nextToken_ExpectAndReturn(&tokenizer, (Token *)&operator1);
	push_Expect(&operatorStack, &operator1);
	
	nextToken_ExpectAndReturn(&tokenizer, (Token *)&number2);
	push_Expect(&dataStack, &number2);
	
	nextToken_ExpectAndReturn(&tokenizer, NULL);
	
	pop_ExpectAndReturn(&operatorStack, &operator1);
	pop_ExpectAndReturn(&dataStack, &number2);
	pop_ExpectAndReturn(&dataStack, &number1);
	createNumberToken_ExpectAndReturn(3, &result1);
	push_Expect(&dataStack, &result1);
	
	pop_ExpectAndReturn(&operatorStack, NULL);
	
	evaluate("1 + 2", &operatorStack, &dataStack);
}

void test_evaluate_4_plus_3_expect_12_should_pass(){
	Stack dataStack;
	Stack operatorStack;
	Tokenizer tokenizer;
	int error;
	
	OperatorToken operator1 = {.type = OPERATOR_TOKEN, .name = "*", .precedence = 100};
	NumberToken number1 = {.type = NUMBER_TOKEN, .value = 4};
	NumberToken number2 = {.type = NUMBER_TOKEN, .value = 3};
	NumberToken result1 = {.type = NUMBER_TOKEN, .value = 12};

	tokenizerNew_ExpectAndReturn("4 * 3", &tokenizer);
	nextToken_ExpectAndReturn(&tokenizer, (Token *)&number1);
	push_Expect(&dataStack, &number1);
	
	nextToken_ExpectAndReturn(&tokenizer, (Token *)&operator1);
	push_Expect(&operatorStack, &operator1);
	
	nextToken_ExpectAndReturn(&tokenizer, (Token *)&number2);
	push_Expect(&dataStack, &number2);
	
	nextToken_ExpectAndReturn(&tokenizer, NULL);
	
	pop_ExpectAndReturn(&operatorStack, &operator1);
	pop_ExpectAndReturn(&dataStack, &number2);
	pop_ExpectAndReturn(&dataStack, &number1);
	createNumberToken_ExpectAndReturn(12, &result1);
	push_Expect(&dataStack, &result1);
	
	pop_ExpectAndReturn(&operatorStack, NULL);
	
	evaluate("4 * 3", &operatorStack, &dataStack);
}

void test_evaluate_3_plus_4_plus_five_minus_6_expect_6_should_pass(){
	Stack dataStack;
	Stack operatorStack;
	Tokenizer tokenizer;
	int error;
	
	OperatorToken operator1 = {.type = OPERATOR_TOKEN, .name = "+", .precedence = 100};
	OperatorToken operator2 = {.type = OPERATOR_TOKEN, .name = "+", .precedence = 100};
	OperatorToken operator3 = {.type = OPERATOR_TOKEN, .name = "-", .precedence = 100};
	NumberToken number1 = {.type = NUMBER_TOKEN, .value = 3};
	NumberToken number2 = {.type = NUMBER_TOKEN, .value = 4};	
	NumberToken number3 = {.type = NUMBER_TOKEN, .value = 5};
	NumberToken number4 = {.type = NUMBER_TOKEN, .value = 6};
	NumberToken result1 = {.type = NUMBER_TOKEN, .value = 7};
	NumberToken result2 = {.type = NUMBER_TOKEN, .value = 12};
	NumberToken result3 = {.type = NUMBER_TOKEN, .value = 6};

	tokenizerNew_ExpectAndReturn("3+4+5-6", &tokenizer);
	nextToken_ExpectAndReturn(&tokenizer, (Token *)&number1);
	push_Expect(&dataStack, &number1);
	
	nextToken_ExpectAndReturn(&tokenizer, (Token *)&operator1);
	push_Expect(&operatorStack, &operator1);
	
	nextToken_ExpectAndReturn(&tokenizer, (Token *)&number2);
	push_Expect(&dataStack, &number2);

	nextToken_ExpectAndReturn(&tokenizer, (Token *)&operator2);
	push_Expect(&operatorStack, &operator2);
	
	nextToken_ExpectAndReturn(&tokenizer, (Token *)&number3);
	push_Expect(&dataStack, &number3);
	
	nextToken_ExpectAndReturn(&tokenizer, (Token *)&operator3);
	push_Expect(&operatorStack, &operator3);
	
	nextToken_ExpectAndReturn(&tokenizer, (Token *)&number4);
	push_Expect(&dataStack, &number4);
	
	nextToken_ExpectAndReturn(&tokenizer, NULL);
	
	pop_ExpectAndReturn(&operatorStack, &operator1);
	pop_ExpectAndReturn(&dataStack, &number1);
	pop_ExpectAndReturn(&dataStack, &number2);
	createNumberToken_ExpectAndReturn(7, &result1);
	push_Expect(&dataStack, &result1);
	
	pop_ExpectAndReturn(&operatorStack, &operator2);
	pop_ExpectAndReturn(&dataStack, &result1);
	pop_ExpectAndReturn(&dataStack, &number3);
	createNumberToken_ExpectAndReturn(12, &result2);
	push_Expect(&dataStack, &result2);

	pop_ExpectAndReturn(&operatorStack, &operator3);
	pop_ExpectAndReturn(&dataStack, &result2);
	pop_ExpectAndReturn(&dataStack, &number4);
	createNumberToken_ExpectAndReturn(6, &result3);
	push_Expect(&dataStack, &result3);
	
	pop_ExpectAndReturn(&operatorStack, NULL);
	
	evaluate("3+4+5-6", &operatorStack, &dataStack);
}

void test_evaluate_should_throw_exception(){
	Stack dataStack;
	Stack operatorStack;
	Tokenizer tokenizer;
	int error;
	
	OperatorToken operator1 = {.type = OPERATOR_TOKEN, .name = "#", .precedence = 100};
	NumberToken number1 = {.type = NUMBER_TOKEN, .value = 4};
	NumberToken number2 = {.type = NUMBER_TOKEN, .value = 3};
	NumberToken result1 = {.type = NUMBER_TOKEN, .value = 12};

	tokenizerNew_ExpectAndReturn("4 # 3", &tokenizer);
	nextToken_ExpectAndReturn(&tokenizer, (Token *)&number1);
	push_Expect(&dataStack, &number1);
	
	nextToken_ExpectAndReturn(&tokenizer, (Token *)&operator1);
	
	Try{
	evaluate("4 # 3", &operatorStack, &dataStack);
	}Catch(error){
		TEST_ASSERT_EQUAL(2, ERR_NOT_OPERATOR);
	}
}

void test_evaluate_should_throw_exception2(){
	Stack dataStack;
	Stack operatorStack;
	Tokenizer tokenizer;
	int error;
	
	OperatorToken operator1 = {.type = OPERATOR_TOKEN, .name = "+", .precedence = 100};

	tokenizerNew_ExpectAndReturn("+", &tokenizer);
	nextToken_ExpectAndReturn(&tokenizer, (Token *)&operator1);

	
	Try{
	evaluate("+", &operatorStack, &dataStack);
	}Catch(error){
		TEST_ASSERT_EQUAL(2, ERR_NOT_OPERATOR);
	}
}

void test_evaluate_should_throw_exception3(){
	Stack dataStack;
	Stack operatorStack;
	Tokenizer tokenizer;
	int error;
	
	OperatorToken operator1 = {.type = OPERATOR_TOKEN, .name = "#", .precedence = 100};
	NumberToken number1 = {.type = NUMBER_TOKEN, .value = 43};
	

	tokenizerNew_ExpectAndReturn("43 #", &tokenizer);
	nextToken_ExpectAndReturn(&tokenizer, (Token *)&number1);
	push_Expect(&dataStack, &number1);
	
	nextToken_ExpectAndReturn(&tokenizer, (Token *)&operator1);
	
	Try{
	evaluate("43 #", &operatorStack, &dataStack);
	}Catch(error){
		TEST_ASSERT_EQUAL(2, ERR_NOT_OPERATOR);
	}
}

void test_evaluate_should_throw_exception4(){
	Stack dataStack;
	Stack operatorStack;
	Tokenizer tokenizer;
	int error;
	
	OperatorToken operator1 = {.type = OPERATOR_TOKEN, .name = "+", .precedence = 100};
	OperatorToken operator2 = {.type = OPERATOR_TOKEN, .name = "*", .precedence = 100};
	NumberToken number1 = {.type = NUMBER_TOKEN, .value = 42};
	

	tokenizerNew_ExpectAndReturn("43 + *", &tokenizer);
	nextToken_ExpectAndReturn(&tokenizer, (Token *)&number1);
	push_Expect(&dataStack, &number1);
	nextToken_ExpectAndReturn(&tokenizer, (Token *)&operator1);
	push_Expect(&operatorStack, &operator1);
	nextToken_ExpectAndReturn(&tokenizer, (Token *)&operator2);
	
	Try{
	evaluate("43 + *", &operatorStack, &dataStack);
	}Catch(error){
		TEST_ASSERT_EQUAL(2, ERR_NOT_OPERATOR);
	}
}

void test_evaluate_should_throw_exception5(){
	Stack dataStack;
	Stack operatorStack;
	Tokenizer tokenizer;
	int error;
	
	OperatorToken operator1 = {.type = OPERATOR_TOKEN, .name = "^", .precedence = 100};
	OperatorToken operator2 = {.type = OPERATOR_TOKEN, .name = "-", .precedence = 100};
	NumberToken number1 = {.type = NUMBER_TOKEN, .value = 42};
	NumberToken number2 = {.type = NUMBER_TOKEN, .value = 2};
	

	tokenizerNew_ExpectAndReturn("43 ^ 2 -", &tokenizer);
	nextToken_ExpectAndReturn(&tokenizer, (Token *)&number1);
	push_Expect(&dataStack, &number1);
	
	nextToken_ExpectAndReturn(&tokenizer, (Token *)&operator1);
	push_Expect(&operatorStack, &operator1);
	
	nextToken_ExpectAndReturn(&tokenizer, (Token *)&number2);
	push_Expect(&dataStack, &number2);
	
	nextToken_ExpectAndReturn(&tokenizer, (Token *)&operator2);
	push_Expect(&operatorStack, &operator2);
	
	nextToken_ExpectAndReturn(&tokenizer, NULL);
	Try{
	evaluate("43 ^ 2 -", &operatorStack, &dataStack);
	}Catch(error){
		TEST_ASSERT_EQUAL(2, ERR_NOT_OPERATOR);
	}
}


