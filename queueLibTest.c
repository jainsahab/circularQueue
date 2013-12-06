#include "testUtils.h"
#include "queueLib.h"
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

Queue* queue;

void tearDown(){
	free(queue->base);
	free(queue);
}
int areEqual(Queue* src, Queue* expected){
	int res = (src->queueInfo.elementSize == expected->queueInfo.elementSize) 
				&& (src->queueInfo.front == expected->queueInfo.front)
				&& (src->queueInfo.rear == expected->queueInfo.rear)
				&& (src->queueInfo.length == expected->queueInfo.length);
	if(!res)
		return res;
	res = memcmp(src->base,expected->base,src->queueInfo.length*src->queueInfo.elementSize);
	return 0==res;
}

void DebugArray(Queue* st){
	printf("Address = %p",st->base);
	printf("Element Size=%d",st->queueInfo.elementSize);
	printf("Front = %d\n", st->queueInfo.front);
	printf("Rear = %d\n", st->queueInfo.rear);
	printf("Length = %d\n", st->queueInfo.length);
}

void test_to_create_int_Queue(){
	int expArr[2]={0,0};
	Queue expected = {expArr,{2,sizeof(int),-1,-1}};
	queue=create(sizeof(int), 2);
	ASSERT(areEqual(queue, &expected));
}

void test_to_create_float_Queue(){
	float expArr[2]={0,0};
	Queue expected = {expArr,{2,sizeof(float),-1,-1}};
	queue=create(sizeof(float), 2);
	ASSERT(areEqual(queue, &expected));
}

void test_to_create_char_Queue(){
	char expArr[2]={'\0','\0'};
	Queue expected = {expArr,{2,sizeof(char),-1,-1}};
	queue=create(sizeof(char), 2);
	ASSERT(areEqual(queue, &expected));
}

void test_to_create_double_Queue(){
	double expArr[2]={0,0};
	Queue expected = {expArr,{2,sizeof(double),-1,-1}};
	queue=create(sizeof(double), 2);
	ASSERT(areEqual(queue, &expected));
}

void test_to_create_string_Queue(){
	String expArr[2]={"Prateek","Kajal"};
	Queue expected = {expArr,{2,sizeof(String),-1,-1}};
	queue=create(sizeof(String), 2);
	memcpy(queue->base, expected.base, sizeof(String)*2);
	ASSERT(areEqual(queue, &expected));
}

void test_to_enqueue_an_int_element(){
	int element = 4;
	queue = create(sizeof(int), 3);
	ASSERT(enQueue(queue, &element));
	ASSERT(enQueue(queue, &element));
}

void test_to_dequeue_an_int_element(){
	int element = 4;
	queue = create(sizeof(int), 3);
	ASSERT(enQueue(queue, &element));
	ASSERT(enQueue(queue, &element));
	deQueue(queue);
	deQueue(queue);
	ASSERT(1==queue->queueInfo.front);
}

void test_to_check_the_behaviour_on_full_capacity(){
	int element = 4;
	queue = create(sizeof(int), 4);
	ASSERT(enQueue(queue, &element));
	ASSERT(enQueue(queue, &element));
	ASSERT(enQueue(queue, &element));
	ASSERT(enQueue(queue, &element));
	ASSERT(false==enQueue(queue, &element));
}

void test_to_check_the_behaviour_on_full_capacity_after_dequeing(){
	int element[] = {4,5,6,7,8,9};
	queue = create(sizeof(int), 4);
	ASSERT(enQueue(queue, element));
	ASSERT(enQueue(queue, &element[1]));
	ASSERT(enQueue(queue, &element[2]));
	ASSERT(4==*(int*)(deQueue(queue)));
	ASSERT(0==queue->queueInfo.front);
	ASSERT(enQueue(queue, &element[3]));
	ASSERT(3==queue->queueInfo.rear);
	ASSERT(false==enQueue(queue, &element[4]));
	ASSERT(5==*(int*)(deQueue(queue)));
	ASSERT(enQueue(queue, &element[4]));
	ASSERT(1==queue->queueInfo.front);
	ASSERT(0==queue->queueInfo.rear);
}

void test_to_deque_from_empty_queue(){
	queue = create(sizeof(int), 4);
	ASSERT(NULL==deQueue(queue));
}