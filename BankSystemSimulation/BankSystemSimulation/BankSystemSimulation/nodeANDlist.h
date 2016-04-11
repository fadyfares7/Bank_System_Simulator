#include <string>
using namespace std;


template<class T> class node
{
	T data;
	node<T> * next;
public:
	node() :data(0), next(nullptr) {}
	node(T d) :data(d), next(nullptr) {}
	T getData() { return data; }
	void setData(T d){ data = d; }
	node<T> * getNext() { return next; }
	void setNext(node<T> * n) { next = n; }
	template<class T> friend class linkedlist;
};


template<class T> class linkedlist
{
private:
	node<T> * chain;
	node<T> * tail;
	int size;
public:
	linkedlist();
	void addAtend(T item);    //add at end
	T removeAtfront();
	int getSize(){ return size; }
};


template<class T> linkedlist<T>::linkedlist()
{
	chain = nullptr;
	tail = nullptr;
	size = 0;
}



template<class T> void linkedlist<T>::addAtend(T item) // add at end
{
	node<T> * temp=new node<T>(item);
	temp->next=nullptr;

	if (chain == nullptr)
	{
		chain = temp;
		tail = temp;
		size++;
	}
	else
	{
		tail->next=temp;
		tail=temp;
		size++;
	}
}




template<class T> T linkedlist<T> ::removeAtfront()
{
	if (chain == nullptr) return T();
	node<T> * p = chain;
	chain = chain->next;
	size--;
	return  p->data ;
}



