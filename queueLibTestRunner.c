#include <stdio.h>

int testCount=-1;
int passCount=0;
void setup();
void tearDown();

void fixtureSetup();
void fixtureTearDown();
void incrementTestCount();
void incrementPassCount();
int currentTestFailed=0;

void testStarted(char* name){
	incrementTestCount();
	currentTestFailed=0;
	printf("\t%s\n",name);
}

void testEnded(){
	if(!currentTestFailed)
		incrementPassCount();
}

void resetTestCount(){
	testCount=0;
	passCount=0;
	printf("********* Starting tests\n\n");
}

void summarizeTestCount(){
	printf("\n********* Ran %d tests passed %d failed %d\n",testCount,passCount,testCount-passCount);
}

void incrementTestCount(){
	testCount++;
}

void incrementPassCount(){
	passCount++;
}

void testFailed(const char* fileName, int lineNumber, char* expression){
	currentTestFailed = 1;
	printf("\t\t %s : failed at %s:%d\n",expression, fileName,lineNumber);
}

int main(){
	fixtureSetup();
	resetTestCount();

	testStarted("test_to_create_int_Queue");
	setup();
		test_to_create_int_Queue();
	tearDown();
	testEnded();
	testStarted("test_to_create_float_Queue");
	setup();
		test_to_create_float_Queue();
	tearDown();
	testEnded();
	testStarted("test_to_create_char_Queue");
	setup();
		test_to_create_char_Queue();
	tearDown();
	testEnded();
	testStarted("test_to_create_double_Queue");
	setup();
		test_to_create_double_Queue();
	tearDown();
	testEnded();
	testStarted("test_to_create_string_Queue");
	setup();
		test_to_create_string_Queue();
	tearDown();
	testEnded();
	testStarted("test_to_enqueue_an_int_element");
	setup();
		test_to_enqueue_an_int_element();
	tearDown();
	testEnded();
	testStarted("test_to_dequeue_an_int_element");
	setup();
		test_to_dequeue_an_int_element();
	tearDown();
	testEnded();
	testStarted("test_to_check_the_behaviour_on_full_capacity");
	setup();
		test_to_check_the_behaviour_on_full_capacity();
	tearDown();
	testEnded();
	testStarted("test_to_check_the_behaviour_on_full_capacity_after_dequeing");
	setup();
		test_to_check_the_behaviour_on_full_capacity_after_dequeing();
	tearDown();
	testEnded();
	testStarted("test_to_deque_from_empty_queue");
	setup();
		test_to_deque_from_empty_queue();
	tearDown();
	testEnded();
	testStarted("test_enqueue_char_element_at_rear_of_queue");
	setup();
		test_enqueue_char_element_at_rear_of_queue();
	tearDown();
	testEnded();
	testStarted("test_enqueue_char_element_at_rear_of_queue_rear_is_at_middle");
	setup();
		test_enqueue_char_element_at_rear_of_queue_rear_is_at_middle();
	tearDown();
	testEnded();
	testStarted("test_enqueue_char_element_at_rear_of_queue_rear_is_at_middle1");
	setup();
		test_enqueue_char_element_at_rear_of_queue_rear_is_at_middle1();
	tearDown();
	testEnded();
	testStarted("test_enqueue_char_element_return_false_when_queue_is_full");
	setup();
		test_enqueue_char_element_return_false_when_queue_is_full();
	tearDown();
	testEnded();
	testStarted("test_enqueue_int_element_at_rear_of_queue");
	setup();
		test_enqueue_int_element_at_rear_of_queue();
	tearDown();
	testEnded();
	testStarted("test_enqueue_float_element_at_rear_of_queue");
	setup();
		test_enqueue_float_element_at_rear_of_queue();
	tearDown();
	testEnded();
	testStarted("test_enqueue_string_element_at_rear_of_queue");
	setup();
		test_enqueue_string_element_at_rear_of_queue();
	tearDown();
	testEnded();
	testStarted("test_enqueue_int_element_at_rear_of_queue_rear_is_at_middle");
	setup();
		test_enqueue_int_element_at_rear_of_queue_rear_is_at_middle();
	tearDown();
	testEnded();
	testStarted("test_enqueue_int_element_at_rear_of_queue_rear_is_at_middle1");
	setup();
		test_enqueue_int_element_at_rear_of_queue_rear_is_at_middle1();
	tearDown();
	testEnded();
	testStarted("test_enqueue_int_element_return_false_when_queue_is_full");
	setup();
		test_enqueue_int_element_return_false_when_queue_is_full();
	tearDown();
	testEnded();
	testStarted("test_enqueue_int_element_return_false_when_queue_is_full1");
	setup();
		test_enqueue_int_element_return_false_when_queue_is_full1();
	tearDown();
	testEnded();
	testStarted("test_enqueue_float_element_at_rear_of_queue_rear_is_at_middle");
	setup();
		test_enqueue_float_element_at_rear_of_queue_rear_is_at_middle();
	tearDown();
	testEnded();
	testStarted("test_enqueue_float_element_at_rear_of_queue_rear_is_at_middle1");
	setup();
		test_enqueue_float_element_at_rear_of_queue_rear_is_at_middle1();
	tearDown();
	testEnded();
	testStarted("test_enqueue_float_element_return_false_when_queue_is_full");
	setup();
		test_enqueue_float_element_return_false_when_queue_is_full();
	tearDown();
	testEnded();
	testStarted("test_enqueue_float_element_return_false_when_queue_is_full1");
	setup();
		test_enqueue_float_element_return_false_when_queue_is_full1();
	tearDown();
	testEnded();
	testStarted("test_enqueue_string_element_at_rear_of_queue_rear_is_at_middle");
	setup();
		test_enqueue_string_element_at_rear_of_queue_rear_is_at_middle();
	tearDown();
	testEnded();
	testStarted("test_enqueue_string_element_at_rear_of_queue_rear_is_at_middle1");
	setup();
		test_enqueue_string_element_at_rear_of_queue_rear_is_at_middle1();
	tearDown();
	testEnded();
	testStarted("test_enqueue_string_element_return_false_when_queue_is_full");
	setup();
		test_enqueue_string_element_return_false_when_queue_is_full();
	tearDown();
	testEnded();
	testStarted("test_enqueue_string_element_return_false_when_queue_is_full1");
	setup();
		test_enqueue_string_element_return_false_when_queue_is_full1();
	tearDown();
	testEnded();
	testStarted("test_dequeue_int_element_at_front_of_queue");
	setup();
		test_dequeue_int_element_at_front_of_queue();
	tearDown();
	testEnded();
	testStarted("test_dequeue_float_element_at_front_of_queue");
	setup();
		test_dequeue_float_element_at_front_of_queue();
	tearDown();
	testEnded();
	testStarted("test_dequeue_string_element_at_front_of_queue");
	setup();
		test_dequeue_string_element_at_front_of_queue();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void fixtureSetup(){}

void fixtureTearDown(){}
