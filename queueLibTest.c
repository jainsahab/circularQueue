#include "testUtils.h"
#include "queueLib.h"
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

Queue* queue;

void tearDown(){
	dispose(queue);
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


void test_enqueue_char_element_at_rear_of_queue(){
    char c='A';
    queue = create(sizeof(char),5);
    ASSERT(enQueue(queue,&c));
    ASSERT(*(char*)(queue->base)=='A');
    ASSERT(queue->queueInfo.rear==0);
}

void test_enqueue_char_element_at_rear_of_queue_rear_is_at_middle(){
    char c='K';
    queue = create(sizeof(char),6);
    queue->queueInfo.rear = 3;
    ASSERT(enQueue(queue,&c));
    ASSERT(*(char*)(queue->base+queue->queueInfo.rear*queue->queueInfo.elementSize) == 'K');
    ASSERT(queue->queueInfo.rear == 4);
}

void test_enqueue_char_element_at_rear_of_queue_rear_is_at_middle1(){
    char c='J';
    queue = create(sizeof(char),6);
    queue->queueInfo.rear = 3;
    queue->queueInfo.front = 5;
    ASSERT(enQueue(queue,&c));
    ASSERT(*(char*)(queue->base+queue->queueInfo.rear*queue->queueInfo.elementSize) == 'J');
    ASSERT(queue->queueInfo.rear == 4);
}

void test_enqueue_char_element_return_false_when_queue_is_full(){
    char c='Q';
    queue = create(sizeof(char),6);
    queue->queueInfo.rear = 5;
    queue->queueInfo.front = -1;
    ASSERT(!enQueue(queue,&c));
    ASSERT(queue->queueInfo.rear == 5);
}

void test_enqueue_int_element_at_rear_of_queue(){
    int c=5;
    queue = create(sizeof(int),5);
    ASSERT(enQueue(queue,&c));
    ASSERT(*(int*)(queue->base)==5);
    ASSERT(queue->queueInfo.rear==0);
}

void test_enqueue_float_element_at_rear_of_queue(){
    float c=1.5;
    queue = create(sizeof(float),5);
    queue->queueInfo.rear = 1;
    ASSERT(enQueue(queue,&c));
    ASSERT(queue->queueInfo.rear == 2);
    ASSERT(*(float*)(queue->base+queue->queueInfo.rear*queue->queueInfo.elementSize)==1.5);
}


//-----------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------

void test_enqueue_string_element_at_rear_of_queue(){
    String c = "hi";
    queue = create(sizeof(String),5);
    ASSERT(enQueue(queue,&c));
    ASSERT(!strcmp("hi", *(String*)queue->base));
    ASSERT(queue->queueInfo.rear == 0);
}
void test_enqueue_int_element_at_rear_of_queue_rear_is_at_middle(){
    int c=5;
    queue = create(sizeof(int),6);
    queue->queueInfo.rear = 3;
    ASSERT(enQueue(queue,&c));
    ASSERT(*(int*)(queue->base+queue->queueInfo.rear*queue->queueInfo.elementSize) == 5);
    ASSERT(queue->queueInfo.rear == 4);
}
void test_enqueue_int_element_at_rear_of_queue_rear_is_at_middle1(){
    int c=10;
    queue = create(sizeof(int),6);
    queue->queueInfo.rear = 3;
    queue->queueInfo.front = 5;
    ASSERT(enQueue(queue,&c));
    ASSERT(*(int*)(queue->base+queue->queueInfo.rear*queue->queueInfo.elementSize) == 10);
    ASSERT(queue->queueInfo.rear == 4);
}
void test_enqueue_int_element_return_false_when_queue_is_full(){
    int c=10;
    queue = create(sizeof(int),6);
    queue->queueInfo.rear = 5;
    queue->queueInfo.front = -1;
    ASSERT(!enQueue(queue,&c));
    ASSERT(queue->queueInfo.rear == 5);
}
void test_enqueue_int_element_return_false_when_queue_is_full1(){
    int c=10;
    queue = create(sizeof(int),6);
    queue->queueInfo.rear = 4;
    queue->queueInfo.front = 5;
    ASSERT(!enQueue(queue,&c));
    ASSERT(queue->queueInfo.rear == 4);
}
void test_enqueue_float_element_at_rear_of_queue_rear_is_at_middle(){
    float c=5.90f;
    queue = create(sizeof(float),6);
    queue->queueInfo.rear = 3;
    ASSERT(enQueue(queue,&c));
    ASSERT(*(float*)(queue->base+queue->queueInfo.rear*queue->queueInfo.elementSize) == 5.90f);
    ASSERT(queue->queueInfo.rear == 4);
}
void test_enqueue_float_element_at_rear_of_queue_rear_is_at_middle1(){
    float c=20.20f;
    queue = create(sizeof(float),6);
    queue->queueInfo.rear = 3;
    queue->queueInfo.front = 5;
    ASSERT(enQueue(queue,&c));
    ASSERT(*(float*)(queue->base+queue->queueInfo.rear*queue->queueInfo.elementSize) == 20.20f);
    ASSERT(queue->queueInfo.rear == 4);
}
void test_enqueue_float_element_return_false_when_queue_is_full(){
    float c=10.50;
    queue = create(sizeof(float),6);
    queue->queueInfo.rear = 5;
    queue->queueInfo.front = -1;
    ASSERT(!enQueue(queue,&c));
    ASSERT(queue->queueInfo.rear == 5);
}
void test_enqueue_float_element_return_false_when_queue_is_full1(){
    float c=10.10;
    queue = create(sizeof(float),6);
    queue->queueInfo.rear = 4;
    queue->queueInfo.front = 5;
    ASSERT(!enQueue(queue,&c));
    ASSERT(queue->queueInfo.rear == 4);
}
void test_enqueue_string_element_at_rear_of_queue_rear_is_at_middle(){
    String c="vidya";
    queue = create(sizeof(String),6);
    queue->queueInfo.rear = 3;
    ASSERT(enQueue(queue,&c));
    ASSERT(!strcmp(*(String*)(queue->base+queue->queueInfo.rear*queue->queueInfo.elementSize) , "vidya"));
    ASSERT(queue->queueInfo.rear == 4);
}
void test_enqueue_string_element_at_rear_of_queue_rear_is_at_middle1(){
    String c="poonam";
    queue = create(sizeof(String),6);
    queue->queueInfo.rear = 3;
    queue->queueInfo.front = 5;
    ASSERT(enQueue(queue,&c));
    ASSERT(strcpy(*(String*)(queue->base+queue->queueInfo.rear*queue->queueInfo.elementSize) , "poonam"));
    ASSERT(queue->queueInfo.rear == 4);
}
void test_enqueue_string_element_return_false_when_queue_is_full(){
    String c="hi";
    queue = create(sizeof(float),6);
    queue->queueInfo.rear = 5;
    queue->queueInfo.front = -1;
    ASSERT(!enQueue(queue,&c));
    ASSERT(queue->queueInfo.rear == 5);
}
void test_enqueue_string_element_return_false_when_queue_is_full1(){
    String c="hi";
    queue = create(sizeof(String),6);
    queue->queueInfo.rear = 4;
    queue->queueInfo.front = 5;
    ASSERT(!enQueue(queue,&c));
    ASSERT(queue->queueInfo.rear == 4);
}
void test_dequeue_int_element_at_front_of_queue(){
    void* element;
    int data[]={2,3,4};
    queue = create(sizeof(int),5);
    enQueue(queue,&data[0]);
    enQueue(queue,&data[1]);
    enQueue(queue,&data[2]);
    ASSERT(queue->queueInfo.rear == 2);
    ASSERT(queue->queueInfo.front == -1);
    element = deQueue(queue);
    ASSERT(*(int*)element == 2.0f);
    ASSERT(queue->queueInfo.rear == 2);
    ASSERT(queue->queueInfo.front == 0);
}
void test_dequeue_float_element_at_front_of_queue(){
    void* element;
    float data[]={2.0f,3.0f,4.0f};
    queue = create(sizeof(float),5);
    enQueue(queue,&data[0]);
    enQueue(queue,&data[1]);
    enQueue(queue,&data[2]);
    ASSERT(queue->queueInfo.rear == 2);
    ASSERT(queue->queueInfo.front == -1);
    element = deQueue(queue);
    ASSERT(*(float*)element == 2.0f);
    ASSERT(queue->queueInfo.rear == 2);
    ASSERT(queue->queueInfo.front == 0);
}
void test_dequeue_string_element_at_front_of_queue(){
    void* element;
    String data[]={"sayali","shital","Samiksha"};
    queue = create(sizeof(String),5);
    enQueue(queue,&data[0]);
    enQueue(queue,&data[1]);
    enQueue(queue,&data[2]);
    ASSERT(queue->queueInfo.rear == 2);
    ASSERT(queue->queueInfo.front == -1);
    element = deQueue(queue);
    ASSERT(!strcmp(*(String*)element , "sayali"));
    ASSERT(queue->queueInfo.rear == 2);
    ASSERT(queue->queueInfo.front == 0);
}