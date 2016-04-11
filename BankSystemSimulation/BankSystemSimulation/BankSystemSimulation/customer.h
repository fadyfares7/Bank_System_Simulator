#include <string.h>

class customer
{
protected:
	int ID;
	string state;
	int waitTime;
	int finishingTime;
	int ticket;
	int turn;
public:
	
	customer() { state = "waiting"; waitTime = 0; finishingTime = 0; ticket = 0; turn = 0; }
	customer(int x){ID=x;}
	customer(int x, string s, int wt, int ft, int tkt, int t){ ID = x;  state = s; waitTime = wt; finishingTime = ft; ticket = tkt; turn = t; }
	customer &customer:: operator=(customer &c)
	{
		ID=c.ID;
		state=c.state;
		waitTime=c.waitTime;
		finishingTime=c.finishingTime;
		ticket=c.ticket;
		turn=c.turn;
		return *this;
	}

	void setID(int id) { ID = id; }
	int getID() { return ID; }

	void setState(string s) { state = s; }
	string getState() { return state; }

	void setWaitTime(int wt) { waitTime = wt; }
	int getWaitTime() { return waitTime; }

	void setFinishingTime(int ft) { finishingTime = ft; }
	int getFinishingTime() { return finishingTime; }

	void setTicket(int tkt) { ticket = tkt; }
	int getTicket() { return ticket; }

	void setTurn(int t) { turn = t; }
	int getTurn() { return turn; }


};
