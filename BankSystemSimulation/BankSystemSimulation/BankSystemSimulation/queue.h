#include "nodeANDlist.h"
#include "customer.h"


template<class T> class queue
{
	private:
		linkedlist<T> q;

	public:
		queue() { }
		void enqueue(T object) { q.addAtend(object); }
		T dequeue() {return q.removeAtfront(); }
		int size() { return q.getSize(); }

		//bool isEmpty() { return q.isEmpty(); };

};