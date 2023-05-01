#include "Customer.h"
#include <iostream>
#ifndef _QUEUEMY_H_
#define _QUEUEMY_H_

template <class ElementofQueue>
class Queue 
{
private:
	struct QNode {
		ElementofQueue Data;
		struct QNode* Next;
	};
	typedef struct QNode* PtrToQNode;
	PtrToQNode front;
	PtrToQNode rear;
	int qnum;
	const int qsize;
public:
	Queue(int qs = 10);
	~Queue();
	bool IsEmptyQ() const;
	bool IsFullQ() const;
	bool InQueue(const ElementofQueue & item);
	bool DeQueue(ElementofQueue &item);
	int count();
};

template <class ElementofQueue>
Queue<ElementofQueue>::Queue(int qs):qsize(qs)
{
	front = NULL;
	rear = NULL;
	qnum = 0;
}
template <class ElementofQueue>
Queue<ElementofQueue>::~Queue()
{
	PtrToQNode tmp;
	while (front) {
		tmp = front;
		front = front->Next;
		delete tmp;
	}
}
template <class ElementofQueue>
bool Queue<ElementofQueue>::IsEmptyQ() const
{
	return (qnum == 0);
}
template <class ElementofQueue>
bool Queue<ElementofQueue>::IsFullQ() const
{
	return (qnum == qsize);
}
template <class ElementofQueue>
bool Queue<ElementofQueue>::InQueue(const ElementofQueue& item)
{
	if (this->IsFullQ()) return false;

	PtrToQNode NewNode = new QNode;
	NewNode->Data = item;
	NewNode->Next = NULL;
	qnum++;

	if (front)
		rear->Next = NewNode;
	else
		front = NewNode;
	rear = NewNode;
	return true;
}
template <class ElementofQueue>
bool Queue<ElementofQueue>::DeQueue(ElementofQueue& item)
{
	if (IsEmptyQ()) return false;

	item = front->Data;
	PtrToQNode tmp = front;
	front = front->Next;
	delete tmp;
	qnum--;
	if (!front)
		rear = NULL;
	return true;
}
template <class ElementofQueue>
int Queue<ElementofQueue>::count()
{
	return qnum;
}
#endif // !_QUEUEMY_H_
