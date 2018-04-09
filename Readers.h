#ifndef Readers_H
#define Readers_H

#include <iostream>
#include <string>
#include "Base_Card_Reader.h"
#include "Decorators.h"

class Card_Pasport_Reader : public Base_Card_Reader
{
  /**
  * \brief Для работы с терминалами по идентификации
  */
public:
	Card_Pasport_Reader(Card_Pasport_decorator* _Current_card) :
		Current_card(_Current_card) {}
	virtual ~Card_Pasport_Reader() = default;

	virtual void Read();



private:
	Card_Pasport_decorator* Current_card;

};
void Card_Pasport_Reader::Read()
{
  /**
  * \brief выводит в терминал информацию
  */
	Current_card->Get_info();
}


//__________________________________________________________________________

class Card_Bank_Reader : public Base_Card_Reader
{
  /**
  * \brief Для работы с терминалами в магазинах или банкоматах
  */
public:
	Card_Bank_Reader(Card_Bank_decorator* _Current_card) :
		Current_card(_Current_card)
	{}
	virtual ~Card_Bank_Reader() = default;

	virtual void Read();
	void Buy(int Price);



private:
	Card_Bank_decorator* Current_card;

};
void Card_Bank_Reader::Read()
{
  /**
  * \brief выводит в терминал информацию
  */
	Current_card->Get_info();
}
void Card_Bank_Reader::Buy(int Price)
{
  /**
  * \brief Совершение покупки
  * \details Проверяет достаточно ли средств на карте, если так то совершает покупку, списывае средства
  */
	if(Current_card->Get_Card_Balance() >= Price)
	{
		Current_card->Make_Purchase(Price);
		std::cout << "Successfully" << std::endl;
		std::cout << "New Balance: " << Current_card->Get_Card_Balance() << std::endl;
	}
}


//___________________________________________________________________________________________________

class Card_Medpolis_Reader : public Base_Card_Reader
{
  /**
  * \brief Для работы с терминалами в медицинских учереждениях
  */
public:
	Card_Medpolis_Reader(Card_Medpolis_decorator* _Current_card) :
		Current_card(_Current_card)
	{}
	virtual ~Card_Medpolis_Reader() = default;

	virtual void Read();
	bool Check_For_Validity();


private:
	Card_Medpolis_decorator* Current_card;

};
bool Card_Medpolis_Reader::Check_For_Validity()
{
	unsigned int number = Current_card->Get_Medpolis_number();
	//if(base[number])
  /**
  * \brief проверка, есть ли такой клиент в базе
  */
		return true;

}
void Card_Medpolis_Reader::Read()
{
  /**
  * \brief выводит в терминал информацию
  */
	Current_card->Get_info();
}
#endif
