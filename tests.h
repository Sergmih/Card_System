#ifndef tests_H
#define tests_H

#include <gtest/gtest.h>
#include "Base_Card.h"
#include "Base_Card_Reader.h"
#include "Readers.h"
#include "Decorators.h"
#include "CCard.h"
/**
* \brief Тестирование
* \details Запуск различных тестов, провекра корректности работы программы
*/
TEST(CCard, test1){
  CCard c(007, Date(2020, 04, 20), Human("Ivan", "Ivanov", Date(1999, 04, 20)));
  EXPECT_EQ(c.Get_card_number(), 7);
}
TEST(Pasporttest, test1){
    CCard c(007, Date(2020, 04, 20), Human("Ivan", "Ivanov", Date(1999, 04, 20)));
    Card_Pasport_decorator p(&c, 8010, 555555, Date(2014, 04, 20));
    EXPECT_EQ(p.Get_Pasport_number(), 555555);
}
TEST(Pasporttest, test2){
    CCard c(007, Date(2020, 04, 20), Human("Ivan", "Ivanov", Date(1999, 04, 20)));
    Card_Pasport_decorator p(&c, 8010, 555555, Date(2014, 04, 20));
    EXPECT_EQ(p.Get_Pasport_series(), 8010);
}
TEST(Medpolistest, test1){
    CCard c(007, Date(2020, 04, 20), Human("Ivan", "Ivanov", Date(1999, 04, 20)));
    Card_Medpolis_decorator m(&c, 123456, "company_name");
    EXPECT_EQ(m.Get_Medpolis_number(), 123456);
}
TEST(Medpolistest, test2){
    CCard c(007, Date(2020, 04, 20), Human("Ivan", "Ivanov", Date(1999, 04, 20)));
    Card_Medpolis_decorator m(&c, 123456, "company_name");
    EXPECT_EQ(m.Get_Insurance_company(), "company_name");
}
TEST(Banktest, test1){
    CCard c(007, Date(2020, 04, 20), Human("Ivan", "Ivanov", Date(1999, 04, 20)));
    Card_Bank_decorator b(&c, 100000);
    EXPECT_EQ(b.Get_Card_Balance(), 100000);
}
TEST(Combine, test1){
  CCard c(007, Date(2020, 04, 20), Human("Ivan", "Ivanov", Date(1999, 04, 20)));
  Card_Medpolis_decorator m(&c, 123456, "company_name");
  Card_Pasport_decorator p(&m, 8010, 555555, Date(2014, 04, 20));
  EXPECT_EQ(p.Get_Pasport_number(), 555555);
}
TEST(Combine, test2){
  CCard c(007, Date(2020, 04, 20), Human("Ivan", "Ivanov", Date(1999, 04, 20)));
  Card_Medpolis_decorator m(&c, 123456, "company_name");
  Card_Pasport_decorator p(&m, 8010, 555555, Date(2014, 04, 20));
    EXPECT_EQ(m.Get_Medpolis_number(), 123456);
}
#endif
