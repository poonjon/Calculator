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
	NumberToken number1 = {.type = NUMBER_TOKEN, .value = 3};
	NumberToken number2 = {.type = NUMBER_TOKEN, .value = 2};
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
	NumberToken number1 = {.type = NUMBER_TOKEN, .value = 3};
	NumberToken number2 = {.type = NUMBER_TOKEN, .value = 2};
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
	NumberToken number1 = {.type = NUMBER_TOKEN, .value = 3};
	NumberToken number2 = {.type = NUMBER_TOKEN, .value = 2};
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
	NumberToken number1 = {.type = NUMBER_TOKEN, .value = 3};
	NumberToken number2 = {.type = NUMBER_TOKEN, .value = 2};
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
	pop_ExpectAndReturn(&operatorStack, NULL);
	push_Expect(&operatorStack, &operator2);
	
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
	pop_ExpectAndReturn(&operatorStack, &operator1);
	pop_ExpectAndReturn(&dataStack, &number1);
	pop_ExpectAndReturn(&dataStack, &number2);
	createNumberToken_ExpectAndReturn(7, &result1);
	push_Expect(&dataStack, &result1);
	pop_ExpectAndReturn(&operatorStack, NULL);
	push_Expect(&operatorStack, &operator2);
	
	nextToken_ExpectAndReturn(&tokenizer, (Token *)&number3);
	push_Expect(&dataStack, &number3);
	
	nextToken_ExpectAndReturn(&tokenizer, (Token *)&operator3);
	pop_ExpectAndReturn(&operatorStack, &operator2);
	pop_ExpectAndReturn(&dataStack, &number3);
	pop_ExpectAndReturn(&dataStack, &result1);
	createNumberToken_ExpectAndReturn(12, &result2);
	push_Expect(&dataStack, &result2);
	pop_ExpectAndReturn(&operatorStack, NULL);
	push_Expect(&operatorStack, &operator3);

	nextToken_ExpectAndReturn(&tokenizer, (Token *)&number4);
	push_Expect(&dataStack, &number4);
	
	nextToken_ExpectAndReturn(&tokenizer, NULL);
	
	pop_ExpectAndReturn(&operatorStack, &operator3);
	pop_ExpectAndReturn(&dataStack, &number4);
	pop_ExpectAndReturn(&dataStack, &result2);
	createNumberToken_ExpectAndReturn(6, &result3);
	push_Expect(&dataStack, &result3);
	
	pop_ExpectAndReturn(&operatorStack, NULL);
	Try{
	evaluate("3+4+5-6", &operatorStack, &dataStack);	
	}Catch(error){
	
	}
}

void test_evaluate_111_divide_12_plus_13_and_14_expect_6_should_pass(){
	Stack dataStack;
	Stack operatorStack;
	Tokenizer tokenizer;
	int error;
	
	OperatorToken operator1 = {.type = OPERATOR_TOKEN, .name = "/", .precedence = 100};
	OperatorToken operator2 = {.type = OPERATOR_TOKEN, .name = "+", .precedence = 70};
	OperatorToken operator3 = {.type = OPERATOR_TOKEN, .name = "&", .precedence = 20};
	NumberToken number1 = {.type = NUMBER_TOKEN, .value = 111};
	NumberToken number2 = {.type = NUMBER_TOKEN, .value = 12};	
	NumberToken number3 = {.type = NUMBER_TOKEN, .value = 13};
	NumberToken number4 = {.type = NUMBER_TOKEN, .value = 14};
	NumberToken result1 = {.type = NUMBER_TOKEN, .value = 9};
	NumberToken result2 = {.type = NUMBER_TOKEN, .value = 22};
	NumberToken result3 = {.type = NUMBER_TOKEN, .value = 6};

	tokenizerNew_ExpectAndReturn("111/12+13&14", &tokenizer);
	nextToken_ExpectAndReturn(&tokenizer, (Token *)&number1);
	push_Expect(&dataStack, &number1);
	
	nextToken_ExpectAndReturn(&tokenizer, (Token *)&operator1);
	push_Expect(&operatorStack, &operator1);
	
	nextToken_ExpectAndReturn(&tokenizer, (Token *)&number2);
	push_Expect(&dataStack, &number2);

	nextToken_ExpectAndReturn(&tokenizer, (Token *)&operator2);
	pop_ExpectAndReturn(&operatorStack, &operator1);
	pop_ExpectAndReturn(&dataStack, &number2);
	pop_ExpectAndReturn(&dataStack, &number1);
	createNumberToken_ExpectAndReturn(9, &result1);
	push_Expect(&dataStack, &result1);
	pop_ExpectAndReturn(&operatorStack, NULL);
	push_Expect(&operatorStack, &operator2);
	
	nextToken_ExpectAndReturn(&tokenizer, (Token *)&number3);
	push_Expect(&dataStack, &number3);
	
	nextToken_ExpectAndReturn(&tokenizer, (Token *)&operator3);
	pop_ExpectAndReturn(&operatorStack, &operator2);
	pop_ExpectAndReturn(&dataStack, &number3);
	pop_ExpectAndReturn(&dataStack, &result1);
	createNumberToken_ExpectAndReturn(22, &result2);
	push_Expect(&dataStack, &result2);
	pop_ExpectAndReturn(&operatorStack, NULL);
	push_Expect(&operatorStack, &operator3);

	nextToken_ExpectAndReturn(&tokenizer, (Token *)&number4);
	push_Expect(&dataStack, &number4);
	
	nextToken_ExpectAndReturn(&tokenizer, NULL);
	
	pop_ExpectAndReturn(&operatorStack, &operator3);
	pop_ExpectAndReturn(&dataStack, &number4);
	pop_ExpectAndReturn(&dataStack, &result2);
	createNumberToken_ExpectAndReturn(6, &result3);
	push_Expect(&dataStack, &result3);
	
	pop_ExpectAndReturn(&operatorStack, NULL);
	Try{
	evaluate("111/12+13&14", &operatorStack, &dataStack);	
	}Catch(error){
	
	}
}

void test_evaluate_211_and_22_xor_23_plus_24_expect_17_should_pass(){
	Stack dataStack;
	Stack operatorStack;
	Tokenizer tokenizer;
	int error;
	
	OperatorToken operator1 = {.type = OPERATOR_TOKEN, .name = "&", .precedence = 20};
	OperatorToken operator2 = {.type = OPERATOR_TOKEN, .name = "^", .precedence = 50};
	OperatorToken operator3 = {.type = OPERATOR_TOKEN, .name = "+", .precedence = 70};
	NumberToken number1 = {.type = NUMBER_TOKEN, .value = 211};
	NumberToken number2 = {.type = NUMBER_TOKEN, .value = 22};	
	NumberToken number3 = {.type = NUMBER_TOKEN, .value = 23};
	NumberToken number4 = {.type = NUMBER_TOKEN, .value = 24};
	NumberToken result1 = {.type = NUMBER_TOKEN, .value = 47};
	NumberToken result2 = {.type = NUMBER_TOKEN, .value = 57};
	NumberToken result3 = {.type = NUMBER_TOKEN, .value = 17};

	tokenizerNew_ExpectAndReturn("211&22^23+14", &tokenizer);
	nextToken_ExpectAndReturn(&tokenizer, (Token *)&number1);
	push_Expect(&dataStack, &number1);
	
	nextToken_ExpectAndReturn(&tokenizer, (Token *)&operator1);
	push_Expect(&operatorStack, &operator1);
	
	nextToken_ExpectAndReturn(&tokenizer, (Token *)&number2);
	push_Expect(&dataStack, &number2);

	nextToken_ExpectAndReturn(&tokenizer, (Token *)&operator2);
	pop_ExpectAndReturn(&operatorStack, &operator1);
	push_Expect(&dataStack, &operator1);
	push_Expect(&dataStack, &operator2);
	
	nextToken_ExpectAndReturn(&tokenizer, (Token *)&number3);
	push_Expect(&dataStack, &number3);
	
	nextToken_ExpectAndReturn(&tokenizer, (Token *)&operator3);
	pop_ExpectAndReturn(&operatorStack, &operator2);
	push_Expect(&dataStack, &operator2);
	push_Expect(&dataStack, &operator3);
	
	nextToken_ExpectAndReturn(&tokenizer, (Token *)&number4);
	push_Expect(&dataStack, &number4);
	
	nextToken_ExpectAndReturn(&tokenizer, NULL);
	
	pop_ExpectAndReturn(&operatorStack, &operator3);
	pop_ExpectAndReturn(&dataStack, &number4);
	pop_ExpectAndReturn(&dataStack, &number3);
	createNumberToken_ExpectAndReturn(47, &result1);
	push_Expect(&dataStack, &result1);

	pop_ExpectAndReturn(&operatorStack, &operator2);
	pop_ExpectAndReturn(&dataStack, &result1);
	pop_ExpectAndReturn(&dataStack, &number2);
	createNumberToken_ExpectAndReturn(57, &result2);
	push_Expect(&dataStack, &result2);	
	
	pop_ExpectAndReturn(&operatorStack, &operator1);
	pop_ExpectAndReturn(&dataStack, &result2);
	pop_ExpectAndReturn(&dataStack, &number1);
	createNumberToken_ExpectAndReturn(17, &result3);
	push_Expect(&dataStack, &result3);
	
	pop_ExpectAndReturn(&operatorStack, NULL);
	Try{
	evaluate("211&22^23+14", &operatorStack, &dataStack);	
	}Catch(error){
	
	}
}

void test_evaluate_266_or_27_xor_28_plus_29_and_30_expect_17_should_pass(){
	Stack dataStack;
	Stack operatorStack;
	Tokenizer tokenizer;
	int error;
	
	OperatorToken operator1 = {.type = OPERATOR_TOKEN, .name = "|", .precedence = 10};
	OperatorToken operator2 = {.type = OPERATOR_TOKEN, .name = "^", .precedence = 50};
	OperatorToken operator3 = {.type = OPERATOR_TOKEN, .name = "+", .precedence = 70};
	OperatorToken operator4 = {.type = OPERATOR_TOKEN, .name = "&", .precedence = 20};
	NumberToken number1 = {.type = NUMBER_TOKEN, .value = 266};
	NumberToken number2 = {.type = NUMBER_TOKEN, .value = 27};	
	NumberToken number3 = {.type = NUMBER_TOKEN, .value = 28};
	NumberToken number4 = {.type = NUMBER_TOKEN, .value = 29};
	NumberToken number5 = {.type = NUMBER_TOKEN, .value = 30};
	NumberToken result1 = {.type = NUMBER_TOKEN, .value = 57};
	NumberToken result2 = {.type = NUMBER_TOKEN, .value = 34};
	NumberToken result3 = {.type = NUMBER_TOKEN, .value = 2};
	NumberToken result4 = {.type = NUMBER_TOKEN, .value = 266};

	tokenizerNew_ExpectAndReturn("266|27^28+19&30", &tokenizer);
	nextToken_ExpectAndReturn(&tokenizer, (Token *)&number1);
	push_Expect(&dataStack, &number1);
	
	nextToken_ExpectAndReturn(&tokenizer, (Token *)&operator1);
	push_Expect(&operatorStack, &operator1);
	
	nextToken_ExpectAndReturn(&tokenizer, (Token *)&number2);
	push_Expect(&dataStack, &number2);

	nextToken_ExpectAndReturn(&tokenizer, (Token *)&operator2);
	pop_ExpectAndReturn(&operatorStack, &operator1);
	push_Expect(&dataStack, &operator1);
	push_Expect(&dataStack, &operator2);
	
	nextToken_ExpectAndReturn(&tokenizer, (Token *)&number3);
	push_Expect(&dataStack, &number3);
	
	nextToken_ExpectAndReturn(&tokenizer, (Token *)&operator3);
	pop_ExpectAndReturn(&operatorStack, &operator2);
	push_Expect(&dataStack, &operator2);
	push_Expect(&dataStack, &operator3);
	
	nextToken_ExpectAndReturn(&tokenizer, (Token *)&number4);
	push_Expect(&dataStack, &number4);
	
	nextToken_ExpectAndReturn(&tokenizer, (Token *)&operator4);
	pop_ExpectAndReturn(&operatorStack, &operator3);
	pop_ExpectAndReturn(&dataStack, &number4);
	pop_ExpectAndReturn(&dataStack, &number3);
	createNumberToken_ExpectAndReturn(57, &result1);
	push_Expect(&dataStack, &result1);
	pop_ExpectAndReturn(&operatorStack, &operator2);
	pop_ExpectAndReturn(&dataStack, &result1);
	pop_ExpectAndReturn(&dataStack, &number2);
	createNumberToken_ExpectAndReturn(34, &result2);
	push_Expect(&dataStack, &result2);	
	pop_ExpectAndReturn(&operatorStack, &operator1);
	push_Expect(&operatorStack, &operator1);	
	push_Expect(&operatorStack, &operator4);	
	
	nextToken_ExpectAndReturn(&tokenizer, (Token *)&number5);
	push_Expect(&dataStack, &number5);
	
	nextToken_ExpectAndReturn(&tokenizer, NULL);

	pop_ExpectAndReturn(&operatorStack, &operator4);
	pop_ExpectAndReturn(&dataStack, &number5);
	pop_ExpectAndReturn(&dataStack, &result2);
	createNumberToken_ExpectAndReturn(2, &result3);
	push_Expect(&dataStack, &result3);
	pop_ExpectAndReturn(&operatorStack, &operator1);
	pop_ExpectAndReturn(&dataStack, &result3);
	pop_ExpectAndReturn(&dataStack, &number1);
	createNumberToken_ExpectAndReturn(266, &result4);
	push_Expect(&dataStack, &result4);	
	pop_ExpectAndReturn(&operatorStack, NULL);
	
	Try{
	evaluate("266|27^28+19&30", &operatorStack, &dataStack);	
	}Catch(error){
	
	}
}

void test_evaluate_plus_should_throw_exception(){

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
		TEST_ASSERT_EQUAL(1, ERR_NOT_DATA);
	}
}

void test_evaluate_38_39_should_throw_exception(){
	Stack dataStack;
	Stack operatorStack;
	Tokenizer tokenizer;
	int error;
	
	NumberToken number1 = {.type = NUMBER_TOKEN, .value = 38};
	NumberToken number2 = {.type = NUMBER_TOKEN, .value = 39};

	tokenizerNew_ExpectAndReturn("38 39", &tokenizer);
	nextToken_ExpectAndReturn(&tokenizer, (Token *)&number1);
	push_Expect(&dataStack, &number1);
	
	nextToken_ExpectAndReturn(&tokenizer, (Token *)&number2);
	
	Try{
	evaluate("38 39", &operatorStack, &dataStack);
	}Catch(error){
		TEST_ASSERT_EQUAL(2, ERR_NOT_OPERATOR);
	}
}

void test_evaluate_43_plus_multiply_should_throw_exception(){
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
		TEST_ASSERT_EQUAL(1, ERR_NOT_DATA);
	}
}

void test_evaluate_43_xor_2_minus_should_throw_exception(){
	Stack dataStack;
	Stack operatorStack;
	Tokenizer tokenizer;
	int error;
	
	OperatorToken operator1 = {.type = OPERATOR_TOKEN, .name = "^", .precedence = 50};
	OperatorToken operator2 = {.type = OPERATOR_TOKEN, .name = "-", .precedence = 70};
	NumberToken number1 = {.type = NUMBER_TOKEN, .value = 42};
	NumberToken number2 = {.type = NUMBER_TOKEN, .value = 2};

	tokenizerNew_ExpectAndReturn("43 ^ 2 - ", &tokenizer);
	nextToken_ExpectAndReturn(&tokenizer, (Token *)&number1);
	push_Expect(&dataStack, &number1);
	
	nextToken_ExpectAndReturn(&tokenizer, (Token *)&operator1);
	push_Expect(&operatorStack, &operator1);
	
	nextToken_ExpectAndReturn(&tokenizer, (Token *)&number2);
	push_Expect(&dataStack, &number2);
	
	nextToken_ExpectAndReturn(&tokenizer, (Token *)&operator2);
	pop_ExpectAndReturn(&operatorStack, &operator1);
	push_Expect(&dataStack, &operator1);
	push_Expect(&dataStack, &operator2);
	
	nextToken_ExpectAndReturn(&tokenizer, NULL);
	
	Try{
	evaluate("43 ^ 2 - ", &operatorStack, &dataStack);
	}Catch(error){
		TEST_ASSERT_EQUAL(4, ERR_NO_EXPRESSION);
	}
}

void test_evaluate_43_hash_should_throw_exception(){
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
		TEST_ASSERT_EQUAL(3, ERR_INVALID_TOKEN);
	}
}



