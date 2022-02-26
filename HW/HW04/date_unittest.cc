#include "gtest/gtest.h"

#include <iostream>
#include <math.h>

#include <ctime>     // Used to get current date
#include "date.h"


class DateTest : public ::testing::Test {
 public:
  void SetUp( ) { 
    // code here will execute just before the test ensues 
	first_day = Date(2018, 9, 4);
	last_day = Date(2018, 12, 11);
  }
 protected:
  Date first_day;          // first day of classes
  Date last_day;           // last day of classes
};



TEST_F(DateTest, PrintDateTests) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween
  
  std::string expected_out_1 = "1999-12-31\n";
  std::string expected_out_2 = "1776-07-04\n";
  std::string expected_out_3 = "2018-10-31\n";
  
  testing::internal::CaptureStdout();
  y2k.PrintDate(true);
  std::string output1 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout(); // You must do this EVERY TIME, or else it will segfault
  ind_day.PrintDate(true);
  std::string output2 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout();
  best_holiday.PrintDate(true);
  std::string output3 = testing::internal::GetCapturedStdout();
  
  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}

TEST_F(DateTest, PrintDateTestsWithoutNewline) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween
  
  std::string expected_out_1 = "1999-12-31";
  std::string expected_out_2 = "1776-07-04";
  std::string expected_out_3 = "2018-10-31";
  
  testing::internal::CaptureStdout();
  y2k.PrintDate(false);
  std::string output1 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout();
  ind_day.PrintDate(false);
  std::string output2 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout();
  best_holiday.PrintDate(false);
  std::string output3 = testing::internal::GetCapturedStdout();
  
  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}

/**
  *
  * Note, this is the only provided test case which actually uses our test fixture
  * 
  * However, it is illegal to mix TEST() and TEST_F() in the same test case (file).
  *
  */

TEST_F(DateTest, PrintUsDateTests) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween

  std::string expected_out_1 = "12-31-1999\n";
  std::string expected_out_2 = "07-04-1776\n";
  std::string expected_out_3 = "10-31-2018\n";

  testing::internal::CaptureStdout();
  y2k.PrintUsDate(true);
  std::string output1 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  ind_day.PrintUsDate(true);
  std::string output2 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  best_holiday.PrintUsDate(true);
  std::string output3 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}

TEST_F(DateTest, PrintUsDateTestsWithoutNewline) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween

  std::string expected_out_1 = "12-31-1999";
  std::string expected_out_2 = "07-04-1776";
  std::string expected_out_3 = "10-31-2018";

  testing::internal::CaptureStdout();
  y2k.PrintUsDate(false);
  std::string output1 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  ind_day.PrintUsDate(false);
  std::string output2 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  best_holiday.PrintUsDate(false);
  std::string output3 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}

TEST_F(DateTest, DaysBetweenTests) {
  EXPECT_EQ(first_day.GetUsDate(), "09-04-2018") << "First day of class not setup properly";
  EXPECT_EQ(last_day.GetUsDate(), "12-11-2018") << "Last day of class not setup properly";
  EXPECT_EQ(first_day.DaysBetween(last_day), 98) << "Days between is not calculated properly";
  
  Date leapfd(2012, 01, 28);
  Date leapld(2012, 03, 03);
  EXPECT_EQ(leapfd.GetDate(), "2012-01-28") << "Random day in leap year not setup properly";
  EXPECT_EQ(leapld.GetDate(), "2012-03-03") << "Another day in leap year not setup properly";
  EXPECT_EQ(leapfd.DaysBetween(leapld), 35) << "Days between Feb 29 not calculated properly";
}

TEST_F(DateTest, OperatorsTest) {
  Date y2k(1999, 12, 31);          // y2k
  Date nyd(2008, 01, 01);          // new year2008
  Date ly1(2020, 02, 18);	   // leap year2020+
  Date ly2(2016, 03, 10);	   // leap year2016-

  EXPECT_EQ((y2k - 10).GetDate(), "1999-12-21") << "operator- doesn't work correctly";
  EXPECT_EQ((y2k + 4).GetDate(), "2000-01-04") << "operator+ doesn't work correctly";
  EXPECT_EQ((nyd + 20).GetUsDate(), "01-21-2008") << "operator+ doesn't work correctly";
  EXPECT_EQ((nyd - 8).GetUsDate(), "12-24-2007") << "operator- doesn't work correctly";
  EXPECT_EQ((ly1 + 15).GetDate(), "2020-03-04") << "operator+ doesn't work correctly";
  EXPECT_EQ((ly2 - 15).GetUsDate(), "02-24-2016") << "operator- doesn't work correctly";
}

TEST_F(DateTest, ConstructorsTest) {  
  Date curr;
  time_t t = time(0);
  tm* now = localtime(&t);
  int yyyy = now->tm_year + 1900;
  int mm = now->tm_mon + 1;
  int dd = now->tm_mday;
  curr = Date(yyyy, mm, dd);
  Date today = Date();
  
  EXPECT_EQ(curr.GetUsDate(), today.GetUsDate()) << "Date(void) not setup properly";
  EXPECT_EQ(curr.GetDate(), today.GetDate()) << "Date(void) not setup properly";
  
  Date xmas(2018, 12, 24);
  Date nye(2018, 12, 31);
  EXPECT_EQ(xmas.GetUsDate(), "12-24-2018") << "Date(---) not setup properly";
  EXPECT_EQ(nye.GetDate(), "2018-12-31") << "Date(---) not setup properly";

  Date epo1(842294400);
  Date epo2(-444444444);
  EXPECT_EQ(epo1.GetDate(), "1996-09-09") << "Date(epoch) not setup properly";
  EXPECT_EQ(epo1.GetUsDate(), "09-09-1996") << "Date(epoch) not setup properly";
  EXPECT_EQ(epo2.GetDate(), "1955-12-01") << "Date(epoch) not setup properly";
  EXPECT_EQ(epo2.GetUsDate(), "12-01-1955") << "Date(epoch) not setup properly";
}

/**
  *
  * NOPE!  Can't test PRIVATE methods
  *
  */
/*
TEST(DateTest, ConvertFromDays) {
	Date convert_first_day = ConvertToDays(2458365);
	EXPECT_STREQ(convert_first_day.GetUsDate(), "09-04-2018");
}
*/
