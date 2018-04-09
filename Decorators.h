#ifndef Decorators_H
#define Decorators_H

#include <iostream>
#include <string>
#include "Base_Card.h"


class Card_Pasport_decorator : public Base_Card
{
public:
	Card_Pasport_decorator(Base_Card* _Current_card, unsigned short int _Pasport_series, unsigned int _Pasport_number, Date _Pasport_date_of_issue) :
		Current_card(_Current_card), Pasport_series(_Pasport_series), Pasport_number(_Pasport_number), Pasport_date_of_issue(_Pasport_date_of_issue){}
	virtual ~Card_Pasport_decorator() = default;

	virtual void Get_info();
	unsigned short int Get_Pasport_series();
	unsigned int Get_Pasport_number();
	Date Get_Pasport_date_of_issue();

private:
	Base_Card *Current_card;
	unsigned short int Pasport_series;
	unsigned int Pasport_number;
	Date Pasport_date_of_issue;
};
unsigned short int Card_Pasport_decorator::Get_Pasport_series()
{
	return Pasport_series;
}
unsigned int Card_Pasport_decorator::Get_Pasport_number()
{
	return Pasport_number;
}
Date Card_Pasport_decorator::Get_Pasport_date_of_issue()
{
	return Pasport_date_of_issue;
}
void Card_Pasport_decorator::Get_info()
{
	Current_card->Get_info();
	std::cout << "PASPORT INFO:" << std::endl;
	std::cout << "Passport series and number: " << Pasport_series << " " << Pasport_number << std::endl;
	std::cout << "date of issue: " << Get_Pasport_date_of_issue().year << "." << Get_Pasport_date_of_issue().month << "." << Get_Pasport_date_of_issue().day << std::endl;
}


//____________________________________________________________________________________
class Card_Medpolis_decorator : public Base_Card
{
public:
	Card_Medpolis_decorator(Base_Card* _Current_card, unsigned int _Medpolis_number, std::string _Insurance_company) :
		Current_card(_Current_card), Medpolis_number(_Medpolis_number), Insurance_company(_Insurance_company){}
	virtual ~Card_Medpolis_decorator() = default;
	virtual void Get_info();
	unsigned int Get_Medpolis_number();
	std::string Get_Insurance_company();

private:
	Base_Card *Current_card;
	unsigned int Medpolis_number;
	std::string Insurance_company;
};
unsigned int Card_Medpolis_decorator::Get_Medpolis_number()
{
	return Medpolis_number;
}
std::string Card_Medpolis_decorator::Get_Insurance_company()
{
	return Insurance_company;
}
void Card_Medpolis_decorator::Get_info()
{
	Current_card->Get_info();
	std::cout << "MEDPOLIS INFO:" << std::endl;
	std::cout << "Medpolis number: " << Get_Medpolis_number() << std::endl;
	std::cout << "Medpolis Insurance Company: " << Get_Insurance_company() <<std::endl;
}


//_________________________________________________________________________________

class Card_Bank_decorator : public Base_Card
{
public:
	Card_Bank_decorator(Base_Card *_Current_card, int _Card_Balance) :
		Current_card(_Current_card), Card_Balance(_Card_Balance){}
	virtual ~Card_Bank_decorator() = default;

	virtual void Get_info();
	int Get_Card_Balance();
	void Make_Purchase(int Price);

private:
	Base_Card *Current_card;
	int Card_Balance;

};
int Card_Bank_decorator::Get_Card_Balance()
{
	return Card_Balance;
}
void Card_Bank_decorator::Make_Purchase(int Price)
{
	Card_Balance -= Price;
}
void Card_Bank_decorator::Get_info()
{
	Current_card->Get_info();
	std::cout << "BANK INFO:" << std::endl;
	std::cout << "Bank card balance: " << Get_Card_Balance() << std::endl;
}
#endif
