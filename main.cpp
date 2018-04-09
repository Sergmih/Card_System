#include <iostream>
#include "Base_Card.h"
#include "Base_Card_Reader.h"
#include "Readers.h"
#include "Decorators.h"
#include "CCard.h"

int main()
{
  std::cout << "Это система многофункциональной карты\nХотите завести карту?" << std::endl;
  std::cout << "y\\n" << std::endl;
  char otv;
  std::cin >> otv;
  if(otv == 'n' || otv == 'N')
    std::cout << "Очень зря, хорошая штука!\n" << std::endl;
  else{
    std::cout << "Отлично!\nВведите вашу Фамилию и Имя:" << std::endl;
    std::string s1, s2;
    std::cin>>s1>>s2;
    std::cout << "А теперь введите дату рождения в формате гггг мм дд:" << std::endl;
    unsigned short int y, m, d;
    std::cin >> y >> m >> d;
    unsigned int getid = 1; // Функция возвращающее незанятый номер карты
    CCard card(getid, Date(y+10, m, d), Human(s2, s1, Date(y, m, d)));
    std::cout << "Карта готова, вот информация о ней:\n" << std::endl;
    card.Get_info();
    std::cout << "Хотите Использовать ее как паспорт?\n" << std::endl;
    // И так далее
  }

  return 0;
}
