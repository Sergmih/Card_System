#ifndef CCard_H
#define CCard_H

#include <iostream>
#include <string>
#include "Base_Card.h"

class CCard:public Base_Card
{
public:
	CCard(unsigned int _card_number, Date _card_validate, Human _owner) :
		card_number(_card_number), card_validate(_card_validate), card_owner(_owner){}
	virtual ~CCard() = default;

	virtual void Get_info();
	unsigned int Get_card_number() const;
	Date Get_card_validate() const;
	Human Get_card_owner() const;

private:
	unsigned int card_number;
	Date card_validate;
	Human card_owner;
};

unsigned int CCard::Get_card_number() const
{
	return card_number;
}
Date CCard::Get_card_validate() const
{
	return card_validate;
}
Human CCard::Get_card_owner() const
{
	return card_owner;
}
void CCard::Get_info()
{
	std::cout << "Card number: " << Get_card_number() << std::endl;
	std::cout << "Card holder name: " << Get_card_owner().Second_Name << " " << Get_card_owner().Name << std::endl;
	std::cout << "Card holder birthday: " << Get_card_owner().Birth.year << "." << Get_card_owner().Birth.month << "." << Get_card_owner().Birth.day << std::endl;
	std::cout << "Card available before: " << Get_card_validate().year << "." << Get_card_validate().month << "." << Get_card_validate().day << std::endl;
}
#endif
