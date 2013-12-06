#include <stdbool.h>
typedef char String[256];
typedef struct{
	void *base;
	struct queueInfo{
		int length;
		int elementSize;
		int front;
		int rear;
	}queueInfo;
} Queue;

Queue* create(int elementSize,int length);
bool enQueue(Queue* queue,void* element);
void* deQueue(Queue* queue);