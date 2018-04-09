#ifndef Base_Card_Reader_H
#define Base_Card_Reader_H

class Base_Card_Reader
{
public:
	virtual ~Base_Card_Reader() = default;
	virtual void Read() = 0;
};
#endif
