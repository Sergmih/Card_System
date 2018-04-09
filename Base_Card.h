#ifndef Base_Card_H
#define Base_Card_H

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
#endif
