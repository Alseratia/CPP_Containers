#include <gtest/gtest.h>
#include <list>
#include "../src/Stack + Queue + list/list.h"
using namespace Study;
TEST(ListConstruct, test1) {
  s21::List<int> mylist;
  std::list<int> list;
  ASSERT_TRUE(mylist.Empty() == list.empty());
  ASSERT_TRUE(mylist.Size() == list.size());
}

TEST(ListConstruct, test2) {
  s21::List<int> mylist(4);
  std::list<int> list(4);
  ASSERT_TRUE(mylist.Size() == list.size());
  ASSERT_TRUE(mylist.Back() == list.back());
  ASSERT_TRUE(mylist.Front() == list.front());
}

TEST(ListConstruct, test3) {
  s21::List<int> mylist({15, 8});
  std::list<int> list({15, 8});
  ASSERT_TRUE(mylist.Size() == list.size());
  ASSERT_TRUE(mylist.Back() == list.back());
  ASSERT_TRUE(mylist.Front() == list.front());
}

TEST(ListSplice, test1) {
  s21::List<int> mylist{85, 356, 3, 165};
  std::list<int> list = {85, 356, 3, 165};
  s21::List<int> mylist2{1, 3, 25};
  std::list<int> list2 = {1, 3, 25};
  s21::List<int>::const_iterator itm = mylist.begin();
  std::list<int>::const_iterator itl = list.begin();
  mylist.Splice(itm, mylist2);
  list.splice(itl, list2);
  s21::List<int>::iterator it_m = mylist.begin();
  std::list<int>::iterator it_l = list.begin();
  while (it_m != mylist.end()) {
    ASSERT_TRUE(*it_m == *it_l);
    ++it_l;
    ++it_m;
  }
  ASSERT_TRUE(mylist.Size() == list.size());
}

TEST(ListConstruct, test4) {
  s21::List<int> mylist({2, 456, 8});
  std::list<int> list = {2, 456, 8};
  ASSERT_TRUE(mylist.Size() == list.size());
  ASSERT_TRUE(mylist.Back() == list.back());
  ASSERT_TRUE(mylist.Front() == list.front());
}

TEST(ListConstruct, test5) {
  s21::List<double> mylist({7.8, 4.56, 0.7, 10.12});
  std::list<double> list = {7.8, 4.56, 0.7, 10.12};
  ASSERT_TRUE(mylist.Size() == list.size());
  ASSERT_TRUE(mylist.Back() == list.back());
  ASSERT_TRUE(mylist.Front() == list.front());
}

TEST(ListConstruct, test6) {
  s21::List<char> mylist({'a', 'b', 'c', 'd', 'e'});
  std::list<char> list = {'a', 'b', 'c', 'd', 'e'};
  ASSERT_TRUE(mylist.Size() == list.size());
  ASSERT_TRUE(mylist.Back() == list.back());
  ASSERT_TRUE(mylist.Front() == list.front());
}

TEST(ListConstruct, test7) {
  s21::List<std::string> mylist({"good", "game", "well", "played"});
  std::list<std::string> list = {"good", "game", "well", "played"};
  ASSERT_TRUE(mylist.Size() == list.size());
  ASSERT_TRUE(mylist.Back() == list.back());
  ASSERT_TRUE(mylist.Front() == list.front());
}

TEST(ListConstruct, test8) {
  s21::List<std::string> mylist2({"good", "game", "well", "played"});
  s21::List<std::string> mylist(mylist2);
  std::list<std::string> list2 = {"good", "game", "well", "played"};
  std::list<std::string> list(list2);
  ASSERT_TRUE(mylist.Size() == list.size());
  ASSERT_TRUE(mylist.Back() == list.back());
  ASSERT_TRUE(mylist.Front() == list.front());
}

TEST(ListConstruct, tes9) {
  s21::List<std::string> mylist2({"good", "game", "well", "played"});
  s21::List<std::string> mylist = mylist2;
  std::list<std::string> list2 = {"good", "game", "well", "played"};
  std::list<std::string> list = list2;
  ASSERT_TRUE(mylist.Size() == list.size());
  ASSERT_TRUE(mylist.Back() == list.back());
  ASSERT_TRUE(mylist.Front() == list.front());
}

TEST(ListConstruct, test10) {
  s21::List<int> mylist2({85, 356, 3, 165});
  s21::List<int> mylist = mylist2;
  std::list<int> list2 = {85, 356, 3, 165};
  std::list<int> list = list2;
  ASSERT_TRUE(mylist.Size() == list.size());
  ASSERT_TRUE(mylist.Back() == list.back());
  ASSERT_TRUE(mylist.Front() == list.front());
}

TEST(ListConstruct, test11) {
  s21::List<int> mylist2({85, 356, 3, 165});
  s21::List<int> mylist;
  mylist = std::move(mylist2);
  std::list<int> list2 = {85, 356, 3, 165};
  std::list<int> list;
  list = std::move(list2);
  ASSERT_TRUE(mylist.Size() == list.size());
  ASSERT_TRUE(mylist.Back() == list.back());
  ASSERT_TRUE(mylist.Front() == list.front());
}

TEST(ListPush, test1) {
  s21::List<int> mylist(4);
  mylist.PushBack(12);
  std::list<int> list(4);
  list.push_back(12);
  ASSERT_TRUE(mylist.Back() == list.back());
}

TEST(ListPush, test2) {
  s21::List<int> mylist;
  mylist.PushBack(9);
  std::list<int> list;
  list.push_back(9);
  ASSERT_TRUE(mylist.Back() == list.back());
  ASSERT_TRUE(mylist.Front() == list.front());
}
TEST(ListPush, test3) {
  s21::List<int> mylist({17, 83, 932, 9, 124});
  mylist.PushBack(-8);
  std::list<int> list = {17, 83, 932, 9, 124};
  list.push_back(-8);
  ASSERT_TRUE(mylist.Back() == list.back());
  ASSERT_TRUE(mylist.Front() == list.front());
}
TEST(ListPush, test4) {
  s21::List<int> mylist({17, 83, 932, 9, 124});
  mylist.PushFront(-152);
  std::list<int> list = {17, 83, 932, 9, 124};
  list.push_front(-152);
  ASSERT_TRUE(mylist.Back() == list.back());
  ASSERT_TRUE(mylist.Front() == list.front());
}
TEST(ListPush, test5) {
  s21::List<int> mylist;
  mylist.PushFront(-1);
  std::list<int> list;
  list.push_front(-1);
  ASSERT_TRUE(mylist.Back() == list.back());
  ASSERT_TRUE(mylist.Front() == list.front());
}

TEST(ListPush, test6) {
  s21::List<int> mylist({2, 83});
  mylist.PushFront(92);
  std::list<int> list({2, 83});
  list.push_front(92);
  ASSERT_TRUE(mylist.Back() == list.back());
  ASSERT_TRUE(mylist.Front() == list.front());
}

TEST(ListPop, test1) {
  s21::List<int> mylist({2, 83});
  mylist.PopFront();
  std::list<int> list({2, 83});
  list.pop_front();
  ASSERT_TRUE(mylist.Size() == list.size());
  ASSERT_TRUE(mylist.Back() == list.back());
  ASSERT_TRUE(mylist.Front() == list.front());
}
TEST(ListPop, test2) {
  s21::List<int> mylist({17, 83, 932, 9, 124});
  mylist.PopFront();
  std::list<int> list = {17, 83, 932, 9, 124};
  list.pop_front();
  ASSERT_TRUE(mylist.Size() == list.size());
  ASSERT_TRUE(mylist.Back() == list.back());
  ASSERT_TRUE(mylist.Front() == list.front());
}
TEST(ListPop, test3) {
  s21::List<std::string> mylist{"i", "am", "tired"};
  std::list<std::string> list = {"i", "am", "tired"};
  mylist.PopBack();
  list.pop_back();
  ASSERT_TRUE(mylist.Size() == list.size());
  ASSERT_TRUE(mylist.Back() == list.back());
  ASSERT_TRUE(mylist.Front() == list.front());
}
TEST(ListSwap, test1) {
  s21::List<int> mylist2({85, 356, 3, 165});
  s21::List<int> mylist;
  std::list<int> list2 = {85, 356, 3, 165};
  std::list<int> list;
  mylist.Swap(mylist2);
  list.swap(list2);
  ASSERT_TRUE(mylist.Size() == list.size());
  ASSERT_TRUE(mylist.Back() == list.back());
  ASSERT_TRUE(mylist.Front() == list.front());
}
TEST(ListSwap, test2) {
  s21::List<std::string> mylist{"one", "two", "three"};
  std::list<std::string> list{"one", "two", "three"};
  s21::List<std::string> mylist2;
  std::list<std::string> list2;
  mylist.Swap(mylist2);
  list.swap(list2);
  ASSERT_TRUE(mylist.Size() == list.size());
  ASSERT_TRUE(mylist.Empty() == list.empty());
}

TEST(ListErase, test1) {
  s21::List<int> mylist({85, 356, 3, 165});
  std::list<int> list = {85, 356, 3, 165};
  s21::List<int>::Listiterator it_m = ++mylist.begin();
  std::list<int>::iterator it_l = ++list.begin();
  mylist.Erase(it_m);
  list.erase(it_l);
  ASSERT_TRUE(mylist.Size() == list.size());
  ASSERT_TRUE(mylist.Back() == list.back());
  ASSERT_TRUE(mylist.Front() == list.front());
}
TEST(ListErase, test2) {
  s21::List<std::string> mylist{"hi", "bye"};
  std::list<std::string> list{"hi", "bye"};
  s21::List<std::string>::Listiterator it_m = mylist.begin();
  std::list<std::string>::iterator it_l = list.begin();
  mylist.Erase(it_m);
  list.erase(it_l);
  ASSERT_TRUE(mylist.Size() == list.size());
  ASSERT_TRUE(mylist.Back() == list.back());
  ASSERT_TRUE(mylist.Front() == list.front());
}
TEST(ListErase, test3) {
  s21::List<double> mylist({8.5, 35.6, 3, 1.65});
  std::list<double> list = {8.5, 35.6, 3, 1.65};
  s21::List<double>::Listiterator it_m = --mylist.end();
  std::list<double>::iterator it_l = --list.end();
  mylist.Erase(it_m);
  list.erase(it_l);
  ASSERT_TRUE(mylist.Size() == list.size());
  ASSERT_TRUE(mylist.Back() == list.back());
  ASSERT_TRUE(mylist.Front() == list.front());
}

TEST(ListInsert, test1) {
  s21::List<int> mylist({85, 3, -165});
  std::list<int> list = {85, 3, -165};
  s21::List<int>::Listiterator it_m = mylist.begin();
  std::list<int>::iterator it_l = list.begin();
  mylist.Insert(it_m, -842);
  list.insert(it_l, -842);
  ASSERT_TRUE(mylist.Size() == list.size());
  ASSERT_TRUE(mylist.Back() == list.back());
  ASSERT_TRUE(mylist.Front() == list.front());
}

TEST(ListInsert, test2) {
  s21::List<int> mylist({85, 3, -165});
  std::list<int> list = {85, 3, -165};
  s21::List<int>::Listiterator it_m = ++mylist.begin();
  std::list<int>::iterator it_l = ++list.begin();
  mylist.Insert(it_m, -842);
  list.insert(it_l, -842);
  ASSERT_TRUE(mylist.Size() == list.size());
  ASSERT_TRUE(mylist.Back() == list.back());
  ASSERT_TRUE(mylist.Front() == list.front());
}
TEST(ListInsert, test3) {
  s21::List<int> mylist({85, 3, -165});
  std::list<int> list = {85, 3, -165};
  s21::List<int>::Listiterator it_m = mylist.end();
  std::list<int>::iterator it_l = list.end();
  mylist.Insert(it_m, -842);
  list.insert(it_l, -842);
  ASSERT_TRUE(mylist.Size() == list.size());
  ASSERT_TRUE(mylist.Back() == list.back());
  ASSERT_TRUE(mylist.Front() == list.front());
}
TEST(ListInsert, test4) {
  s21::List<int> mylist({85, 3, -165});
  std::list<int> list = {85, 3, -165};
  s21::List<int>::Listiterator it_m = --mylist.end();
  std::list<int>::iterator it_l = --list.end();
  mylist.Insert(it_m, -82);
  list.insert(it_l, -82);
  ASSERT_TRUE(mylist.Size() == list.size());
  ASSERT_TRUE(mylist.Back() == list.back());
  ASSERT_TRUE(mylist.Front() == list.front());
}
TEST(ListInsert, test5) {
  s21::List<std::string> mylist{"lol", "kek"};
  std::list<std::string> list{"lol", "kek"};
  s21::List<std::string>::Listiterator it_m = mylist.begin();
  std::list<std::string>::iterator it_l = list.begin();
  mylist.Insert(it_m, "cheburek");
  list.insert(it_l, "cheburek");
  ASSERT_TRUE(mylist.Size() == list.size());
  ASSERT_TRUE(mylist.Back() == list.back());
  ASSERT_TRUE(mylist.Front() == list.front());
}

TEST(ListUnique, test1) {
  s21::List<int> mylist{85, 85, 356, 3, 3, 165};
  std::list<int> list = {85, 85, 356, 3, 3, 165};
  mylist.Unique();
  list.unique();
  ASSERT_TRUE(mylist.Size() == list.size());
  ASSERT_TRUE(mylist.Back() == list.back());
  ASSERT_TRUE(mylist.Front() == list.front());
}

TEST(ListUnique, test2) {
  s21::List<int> mylist{85, 85, 356, 3, 3, 165};
  std::list<int> list = {85, 85, 356, 3, 3, 165};
  mylist.Unique();
  list.unique();
  s21::List<int>::Listiterator it_m = mylist.begin();
  std::list<int>::iterator it_l = list.begin();
  while (it_m != mylist.end()) {
    ASSERT_TRUE(*it_m == *it_l);
    ++it_l;
    ++it_m;
  }
  ASSERT_TRUE(mylist.Size() == list.size());
}

TEST(ListUnique, test3) {
  s21::List<int> mylist{17, 17, 17, 17, 83, 932, 9, 9, 9, 124};
  std::list<int> list{17, 17, 17, 17, 83, 932, 9, 9, 9, 124};
  mylist.Unique();
  list.unique();
  s21::List<int>::Listiterator it_m = mylist.begin();
  std::list<int>::iterator it_l = list.begin();
  while (it_m != mylist.end()) {
    ASSERT_TRUE(*it_m == *it_l);
    ++it_l;
    ++it_m;
  }
  ASSERT_TRUE(mylist.Size() == list.size());
}

TEST(ListUnique, test4) {
  s21::List<char> mylist{'n', 'o', 'o', 'o', 'o', 'o', 'o', 'y', 'e', 's'};
  std::list<char> list = {'n', 'o', 'o', 'o', 'o', 'o', 'o', 'y', 'e', 's'};
  mylist.Unique();
  list.unique();
  s21::List<char>::Listiterator it_m = mylist.begin();
  std::list<char>::iterator it_l = list.begin();
  while (it_m != mylist.end()) {
    ASSERT_TRUE(*it_m == *it_l);
    ++it_l;
    ++it_m;
  }
  ASSERT_TRUE(mylist.Size() == list.size());
}

TEST(ListReverse, test1) {
  s21::List<int> mylist{85, 356, 3, 165};
  std::list<int> list = {85, 356, 3, 165};
  mylist.Reverse();
  list.reverse();
  s21::List<int>::Listiterator it_m = mylist.begin();
  std::list<int>::iterator it_l = list.begin();
  while (it_m != mylist.end()) {
    ASSERT_TRUE(*it_m == *it_l);
    ++it_l;
    ++it_m;
  }
}

TEST(ListReverse, test2) {
  s21::List<int> mylist{17, 83, 932, 9, 124};
  std::list<int> list = {17, 83, 932, 9, 124};
  mylist.Reverse();
  list.reverse();
  s21::List<int>::Listiterator it_m = mylist.begin();
  std::list<int>::iterator it_l = list.begin();
  while (it_m != mylist.end()) {
    ASSERT_TRUE(*it_m == *it_l);
    ++it_l;
    ++it_m;
  }
}
TEST(ListReverse, test3) {
  s21::List<std::string> mylist{"i", "am", "tired"};
  std::list<std::string> list = {"i", "am", "tired"};
  mylist.Reverse();
  list.reverse();
  s21::List<std::string>::Listiterator it_m = mylist.begin();
  std::list<std::string>::iterator it_l = list.begin();
  while (it_m != mylist.end()) {
    ASSERT_TRUE(*it_m == *it_l);
    ++it_l;
    ++it_m;
  }
}

TEST(ListEmplase, test1) {
  s21::List<int> mylist{2, 3, 32, 165};
  mylist.EmplaceBack(5, 18);
  s21::List<int> mylist2{2, 3, 32, 165, 5, 18};
  s21::List<int>::Listiterator it_m = mylist.begin();
  s21::List<int>::Listiterator it_2 = mylist2.begin();
  ASSERT_TRUE(*it_m = *it_2);
  while (it_m != mylist.end()) {
    ASSERT_TRUE(*it_m == *it_2);
    ++it_2;
    ++it_m;
  }
}