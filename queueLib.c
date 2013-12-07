#include "queueLib.h"
#include <stdlib.h>
#include <string.h>
Queue* create(int elementSize,int length){
	Queue* queue = calloc(1,sizeof(Queue));
	queue -> base = calloc(length, elementSize);
	queue->queueInfo.front = -1;
	queue->queueInfo.rear = -1;
	queue->queueInfo.elementSize = elementSize;
	queue->queueInfo.length = length;
	return queue;
}

int isFull(Queue* queue){
	int front = queue->queueInfo.front;
	int rear = queue->queueInfo.rear;
	int length = queue->queueInfo.length;
	return(front - rear == 1 ||
		(front==-1 && rear==length-1));
}

bool enQueue(Queue* queue,void* element){
	void* address;
	if(isFull(queue))
		return false;
	queue->queueInfo.rear++;
	if(queue->queueInfo.rear >= queue->queueInfo.length && queue->queueInfo.front == 0)
		return false;
	if(queue->queueInfo.rear >= queue->queueInfo.length && queue->queueInfo.front > 0)
		queue->queueInfo.rear=0;
	address = queue->base+((queue->queueInfo.rear)*queue->queueInfo.elementSize);
	memcpy(address,element,queue->queueInfo.elementSize);
	return true; 
}

int isEmpty(Queue* queue){
	return(queue->queueInfo.rear == -1 
		&& queue->queueInfo.front == -1);
}

void* deQueue(Queue *queue){
	void* dequeuedElement;
	if(isEmpty(queue))
		return NULL;
	queue->queueInfo.front++;
	dequeuedElement=malloc(queue->queueInfo.elementSize);
	memcpy(dequeuedElement,	
	 queue->base+(queue->queueInfo.front*queue->queueInfo.elementSize),
	  queue->queueInfo.elementSize);
	return dequeuedElement;
}

void dispose(Queue* queue){
	free(queue->base);
	free(queue);
}