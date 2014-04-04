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
	push_Expect(&dataStack, result);
	
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
	push_Expect(&dataStack, result);
	
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
	push_Expect(&dataStack, result);
	
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
	push_Expect(&dataStack, result);
	
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
	push_Expect(&dataStack, result);
	
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
	push_Expect(&dataStack, result);
	
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
	push_Expect(&dataStack, result);
	
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
	push_Expect(&dataStack, result);
	
	Try{
	evaluateOperator(&dataStack, &operator);
	}Catch(error){
	TEST_ASSERT_EQUAL(2, ERR_NOT_OPERATOR);
	}
	
	TEST_ASSERT_EQUAL(0xf, result.value);
}

void test_evaluate_operator_invalid_operator_should_throw_exception(){
	Stack dataStack;
	int error;
	
	OperatorToken operator = {.type = OPERATOR_TOKEN, .name = "?", .precedence = 70};
	NumberToken number1 = {.type = NUMBER_TOKEN, .value = 0x0};
	NumberToken number2 = {.type = NUMBER_TOKEN, .value = 0xf};
	NumberToken result = {.type = NUMBER_TOKEN, .value = 0xf};
	
	Try{
	evaluateOperator(&dataStack, &operator);
	}Catch(error){
	TEST_ASSERT_EQUAL(2, ERR_NOT_OPERATOR);
	}
	
}

void test_evaluate_operator_3_multiply_4_plus_2_expect_f_should_pass(){
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
	
	Try{
	evaluateAllOperatorOnStack(&operatorStack, &dataStack);
	}Catch(error){
	TEST_ASSERT_EQUAL(2, ERR_NOT_OPERATOR);
	}
	
	TEST_ASSERT_EQUAL(14, result2.value);
}
