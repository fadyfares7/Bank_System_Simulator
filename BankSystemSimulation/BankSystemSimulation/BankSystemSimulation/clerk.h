#include"queue.h"
#include <string.h>
class clerk
{
private: string service;
		 int time;
		 int ID;
		 int totalWaiting;
		 queue<customer> Q;
public:
	clerk(){service=" ",time=0; ID=1;totalWaiting=0;}
	clerk(string s, int t,int id)
	{
		service=s;
		time=t;
		ID=id;
	}
	void setService(string s)
	{service=s;}
	string getService()
	{return service;}
	void setTime(int t)
	{time=t;}
	int getTime()
	{return time;}
	void setID(int t)
	{ID=t;}
	int getID()
	{return ID;}
	void setTotalWaiting(int t)
	{totalWaiting=t;}
	int getTotalWaiting()
	{return totalWaiting;}
	int getQueueSize()
	{return Q.size();}
	
	void AddCustomer(customer c)
	{
		Q.enqueue(c);
	}
	customer removeCustomer()
	{
		return Q.dequeue();
	}


};