#ifndef QUEUE_H
#define QUEUE_H

/*Queue template using a dubbly linked list as a Circular Buffer*/

template<typename T>
class Queue {
private:
	struct Element{
		T * head;
		T* tail;
		T data;
	};
	int nrOfElements;
	Element* start;
	void deleteElements();
public:
	Queue();
	virtual~Queue();
	bool empty()const;
	int size()const;
	T front()const throw(...);
	T back()const throw(...);
	void push(T element);
	bool insertAt(Element element, int pos)throw(...);
	bool mergeList(Queue *otherQueue);
	void getAllElements(T* elementArray);


};


template<typename T>
 Queue<T>::Queue() {
	nrOfElements = 0;
	start = nullptr;
}
template<typename T>
 Queue<T>::~Queue() {
	deleteElements();
}
template<typename T>
 bool Queue<T>::empty() const {
	return nrOfElements == 0;
}
template<typename T>
 int Queue<T>::size() const {
	return nrOfElements;
}
template<typename T>
 T Queue<T>::front() const throw(...) {
	if (nrOfElements !> 0) {
		char msg[] = "No Elements In Queue.";
		throw &msg[0];
	}
	return *start;
}
template<typename T>
 T Queue<T>::back() const throw(...) {
	if (nrOfElements !> 0) {
		char msg[] = "No Elements In Queue.";
		throw &msg[0];
	}
	Element *ptr = start;
	if (ptr->head != nullptr)
		ptr = ptr->head;
	return ptr;
}
template<typename T>
 void Queue<T>::push(T element) {
	Element *newElement = new Element;
	newElement = element;
	//Connect new element to last elements tail and first element head.
	if (nrOfElements != 0) {
	
		newElement->head = start->head;
		newElement->tail = start;

		start->head->tail = newElement;
		start->head = newElement;
	}
	else {
		start = newElement;
		newElement->tail = start;
		start->head = start;
	}
	nrOfElements++;
}
template<typename T>
 bool Queue<T>::insertAt(Element element, int pos) throw(...) {
	if (nrOfElements !> 0) {
		char msg[] = "No Elements In Queue.";
		throw &msg[0];
	}
	else if (pos > nrOfelements) {
		push(element);
		char msg[] = "Position outside bounds, element added at back of queue.";
		throw &msg[0];
	}
	Element * ptr = new Element;
	Element * current = start;
	ptr = element;
	for (int i = 0; i < nrOfElements; i++)
		current = current->tail;
	ptr->head = current->head;
	ptr->tail = current;
	current->head = ptr;
	return true;
}
template<typename T>
 bool Queue<T>::mergeList(Queue *otherQueue) {
	bool succes = false;
	if (nrOfElements == 0 || otherQueue.nrOfElements == 0) {

	}
	else {
	otherQueue->start->head = start->head;
	otherQuese->start->head->tail = start;
	start = otherQueue->start;
	nrOfElements += otherQueue->nrOfElements;

	otherQueue->nrOfElements = 0;
	otherQuene->start = nullptr;
	succes = true;
	}

	return succes;
}
#endif // !QUEUE_H
