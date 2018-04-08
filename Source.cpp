#include <iostream>
#include <string>

struct Date
{
	Date(unsigned short int _year, unsigned short int _month, unsigned short int _day) : year(_year), month(_month), day(_day){}
	Date() = default;
	unsigned short int year;
	unsigned short int month;
	unsigned short int day;
};

struct Human
{
	Human(std::string _Name, std::string _Second_Name, Date _Birth) : Name(_Name), Second_Name(_Second_Name), Birth(_Birth){}
	std::string Name;
	std::string Second_Name;
	Date Birth;
};

class Base_Card
{
public:
	virtual void Get_info() = 0;
	virtual ~Base_Card() = default;
};

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


//_____________________________________________________________________________________________________

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


//_____________________________________________________________________________
//Readers

class Base_Card_Reader
{
public:
	virtual ~Base_Card_Reader() = default;
	virtual void Read() = 0;
};

//_____________________________________________________________________________
class Card_Pasport_Reader : public Base_Card_Reader
{
public:
	Card_Pasport_Reader(Card_Pasport_decorator* _Current_card) :
		Current_card(_Current_card) {}
	virtual ~Card_Pasport_Reader() = default;
	
	virtual void Read();

	//functions connected with person identification

private:
	Card_Pasport_decorator* Current_card;

};
void Card_Pasport_Reader::Read()
{
	Current_card->Get_info();
}


//__________________________________________________________________________

class Card_Bank_Reader : public Base_Card_Reader
{
public:
	Card_Bank_Reader(Card_Bank_decorator* _Current_card) :
		Current_card(_Current_card)
	{}
	virtual ~Card_Bank_Reader() = default;
	
	virtual void Read();
	void Buy(int Price);


	//

private:
	Card_Bank_decorator* Current_card;

};
void Card_Bank_Reader::Read()
{
	Current_card->Get_info();
}
void Card_Bank_Reader::Buy(int Price)
{
	//Pricladivanie karti k terminalu v magazine
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
	//if(base[number]) Esli v baze est' etot polis, to mozno lechit'
		return true;

}
void Card_Medpolis_Reader::Read()
{
	Current_card->Get_info();
}

//________________________________________________________________________________________________

int main()
{
	CCard c(007, Date(2020, 04, 20), Human("Ivan", "Ivanov", Date(1999, 04, 20)));
	c.Get_info();
	std::cout << std::endl;
	Card_Medpolis_decorator f(&c, 123456, "company_name");
	f.Get_info();
	std::cout << std::endl;
	Card_Pasport_decorator d(&f, 8010, 555555, Date(2014, 04, 20));
	d.Get_info();
	std::cout << std::endl;
	Card_Bank_decorator s(&d, 100000);
	s.Get_info();

	system(" pause ");

	return 0;
 }