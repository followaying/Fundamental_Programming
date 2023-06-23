#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
class DateTime {
private:
	int hour, minute, second, day, month, year;
	friend class customer;
};

enum card{gold, sliver, daily};

class customer {
public:
	string customerCode, fullname, nickname, address, DoB;
	int ServiceCode;
	int time;
	DateTime* DateTimes;
	float* cost;
	card card;
	class Enterpise {
	protected:
		string taxCode, enterpiseName, fax, email, web;
	public:
		Enterpise():taxCode(""), enterpiseName(""), fax(""), email(""), web("") {}
		~Enterpise(){}
	};
	Enterpise Enterpise;
	customer* next;
	customer(enum card Card, string name, string DoB) : card(Card), fullname(name), DoB(DoB), next(nullptr) {}
	~customer(){}
	void ChangeCard(enum card Card) { card = Card; }

};
class CRM {
protected:
	customer* head;
	int size;
};