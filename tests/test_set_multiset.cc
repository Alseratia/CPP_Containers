#include <gtest/gtest.h>

#include <iostream>
#include <set>
#include "../src/Map + Set + Multiset/set.h"
#include "../src/Map + Set + Multiset/multiset.h"


TEST(Check_Set, IterBegin) {
  std::initializer_list<int> list{11, 4, 2, 3,  9,  10, 5,
                                  7,  6, 8, 13, 12, 15, 14};
  s21::Set<int> mySet(list);
  std::set<int> origSet(list);
  s21::Set<int>::Iterator myIter;
  std::set<int>::iterator origIter;
  myIter = mySet.begin();
  origIter = origSet.begin();
  ASSERT_EQ(*myIter, *origIter);
}

TEST(Check_Set, FromBeginToEnd) {
  std::initializer_list<int> list{11, 4, 2, 3,  9,  10, 5,
                                  7,  6, 8, 13, 12, 14, 15};
  s21::Set<int> mySet(list);
  std::set<int> origSet(list);
  auto iter1 = mySet.begin();
  auto iter2 = origSet.begin();
  while (iter1 != mySet.end() && iter2 != origSet.end()) {
    ASSERT_EQ(*iter1, *iter2);
    ++iter1;
    ++iter2;
  }
}

TEST(Check_Set, string) {
  std::initializer_list<std::string> list{"2321",   "fgdgf",          "a",
                                          "dfdsf4", "d2ueu3eg32e3d2", "......"};
  s21::Set<std::string> mySet(list);
  std::set<std::string> origSet(list);
  auto iter1 = mySet.begin();
  auto iter2 = origSet.begin();
  while (iter1 != mySet.end() && iter2 != origSet.end()) {
    EXPECT_TRUE(*iter1 == *iter2);
    ++iter1;
    ++iter2;
  }
}

TEST(Check_Set, insert) {
  std::initializer_list<double> list{11.3, -4.1, 3231.2, 2.33, 0.9,
                                     1.10, 2.5,  7.25,   6.3,  8.0,
                                     -132, 12.3, 13.4,   -5.15};
  s21::Set<double> mySet(list);
  std::set<double> origSet(list);
  auto iter1 = mySet.begin();
  auto iter2 = origSet.begin();
  mySet.Insert(666.777);
  origSet.insert(666.777);
  while (iter1 != mySet.end() && iter2 != origSet.end()) {
    ASSERT_DOUBLE_EQ(*iter1, *iter2);
    ++iter1;
    ++iter2;
  }
}

TEST(Check_Set, erase) {
  std::initializer_list<int> list{11, 4, 2, 3,  9,  10, 5,
                                  7,  6, 8, 13, 12, 14, 15};
  s21::Set<int> mySet(list);
  std::set<int> origSet(list);
  auto iter1 = mySet.begin();
  auto iter2 = origSet.begin();
  auto rmIter1 = mySet.begin();
  auto rmIter2 = origSet.begin();
  ++rmIter1;
  ++rmIter2;
  mySet.Erase(rmIter1);
  origSet.erase(rmIter2);
  while (iter1 != mySet.end() && iter2 != origSet.end()) {
    ASSERT_EQ(*iter1, *iter2);
    ++iter1;
    ++iter2;
  }
}

TEST(Check_Set, erase2) {
  std::initializer_list<int> list{11, 4, 2, 3,  9,  10, 5,
                                  7,  6, 8, 13, 12, 14, 15};
  s21::Set<int> mySet(list);
  std::set<int> origSet(list);
  auto iter1 = mySet.begin();
  auto rmIter1 = mySet.begin();
  auto rmIter2 = origSet.begin();
  ++rmIter1;
  ++rmIter2;
  mySet.Erase(rmIter1);
  origSet.erase(rmIter2);
  auto rmIter11 = mySet.begin();
  auto rmIter22 = origSet.begin();
  mySet.Erase(rmIter11);
  origSet.erase(rmIter22);
  iter1 = mySet.begin();
  auto iter22 = origSet.begin();
  while (iter1 != mySet.end() && iter22 != origSet.end()) {
    ASSERT_EQ(*iter1, *iter22);
    ++iter1;
    ++iter22;
  }
}

TEST(Check_Set, emptyTrue) {
  std::set<char> oSet;
  s21::Set<char> mSet;
  EXPECT_TRUE(oSet.empty());
  EXPECT_TRUE(mSet.Empty());
}

TEST(Check_Set, emptyFlase) {
  std::initializer_list<int> list{11, 4, 2, 3,  9,  10, 5,
                                  7,  6, 8, 13, 12, 14, 15};
  std::set<int> oSet(list);
  s21::Set<int> mSet(list);
  EXPECT_FALSE(oSet.empty());
  EXPECT_FALSE(mSet.Empty());
}

TEST(Check_Set, clear) {
  std::initializer_list<int> list{11, 4, 2, 3,  9,  10, 5,
                                  7,  6, 8, 13, 12, 14, 15};
  std::set<int> oSet(list);
  s21::Set<int> mSet(list);
  oSet.clear();
  mSet.Clear();
  EXPECT_TRUE(oSet.empty());
  EXPECT_TRUE(mSet.Empty());
  oSet.clear();
  mSet.Clear();
  EXPECT_TRUE(oSet.empty());
  EXPECT_TRUE(mSet.Empty());
}

TEST(Check_Set, swap) {
  std::initializer_list<long double> list{11.3, -4.1, 3231.2, 2.33, 0.9,
                                          1.10, 2.5,  7.25,   6.3,  8.0,
                                          -132, 12.3, 13.4,   -5.15};
  std::set<long double> oSet1(list);
  std::set<long double> oSet2;
  s21::Set<long double> mSet1(list);
  s21::Set<long double> mSet2;
  oSet1.swap(oSet2);
  mSet1.Swap(mSet2);
  EXPECT_TRUE(oSet1.empty());
  EXPECT_FALSE(oSet2.empty());
  EXPECT_TRUE(mSet1.Empty());
  EXPECT_FALSE(mSet2.Empty());
}

TEST(Check_Set, merge1) {
  std::initializer_list<int> list3{11, 4, 2, 3,  9,  10, 5,
                                   7,  6, 8, 13, 12, 14, 15, -4, -5, 28, 39};
  std::initializer_list<int> list1{11, 4, 2, 3,  9,  10, 5,
                                   7,  6, 8, 13, 12, 14, 15};
  std::initializer_list<int> list2{-4, -5, 28, 39};
  std::set<int> oSet1(list3);

  s21::Set<int> mSet1(list1);
  s21::Set<int> mSet2(list2);
  mSet1.Merge(mSet2);
  std::set<int>::iterator oIt = oSet1.begin();
  s21::Set<int>::Iterator mIt = mSet1.begin();
  while (oIt != oSet1.end() && mIt != mSet1.end()) {
    ASSERT_EQ(*oIt, *mIt);
    ++oIt;
    ++mIt;
  }
}

TEST(Check_Set, merge2) {
  std::set<int> oSet;
  s21::Set<int> mSet;
  mSet.Merge(mSet);
  EXPECT_TRUE(oSet.empty() && mSet.Empty());
}

TEST(Check_Set, find1) {
  std::initializer_list<int> list{11, 4, 2, 3,  9,  10, 5,
                                  7,  6, 8, 13, 12, 14, 15};
  std::set<int> oSet(list);
  s21::Set<int> mSet(list);
  std::set<int>::iterator oIter = oSet.find(13);
  s21::Set<int>::Iterator mIter = mSet.Find(13);
  ASSERT_EQ(*oIter, *mIter);
  ++oIter;
  ++mIter;
  ASSERT_EQ(*oIter, *mIter);
}

TEST(Check_Set, find2) {
  s21::Set<char> Set;
  s21::Set<char>::Iterator it;
  it = Set.Find('f');
  EXPECT_TRUE(it == Set.end());
}

TEST(Check_Set, contains1) {
  s21::Set<char> Set;
  EXPECT_FALSE(Set.Contains('f'));
}

TEST(Check_Set, contains2) {
  std::initializer_list<int> list{11, 4, 2, 3,  9,  10, 5,
                                  7,  6, 8, 13, 12, 14, 15};
  s21::Set<int> Set(list);
  EXPECT_TRUE(Set.Contains(10));
  EXPECT_TRUE(Set.Contains(13));
  EXPECT_TRUE(Set.Contains(12));
  EXPECT_FALSE(Set.Contains(-7));
}

TEST(Check_Set, size1) {
  std::initializer_list<int> list{6,        9,      -2,     43,
                                  21432432, 234324, 412342, 12321};
  s21::Set<int> mSet(list);
  std::set<int> oSet(list);
  ASSERT_EQ(mSet.Size(), oSet.size());
}

TEST(Check_Set, size2) {
  std::set<int> oSet;
  s21::Set<int> mSet;
  ASSERT_EQ(oSet.size(), mSet.Size());
}

TEST(Check_Set, move_constructor) {
  std::initializer_list<int> list{11, 4, 2, 3,  9,  10, 5,
                                  7,  6, 8, 13, 12, 14, 15};
  std::set<int> oSet1(list);
  std::set<int> oSet2(std::move(oSet1));
  s21::Set<int> mSet1(list);
  s21::Set<int> mSet2(std::move(mSet1));
  EXPECT_TRUE(oSet1.empty() == mSet1.Empty());
  EXPECT_TRUE(oSet2.empty() == mSet2.Empty());
}

TEST(Check_Set, copy_constructor) {
  std::initializer_list<int> list{11, 4, 2, 3,  9,  10, 5,
                                  7,  6, 8, 13, 12, 14, 15};
  s21::Set<int> mSet1(list);
  s21::Set<int> mSet2(mSet1);
  s21::Set<int>::iterator it1 = mSet1.begin();
  s21::Set<int>::iterator it2 = mSet2.begin();
  while (it1 != mSet1.end() || it2 != mSet2.end()) {
    ASSERT_EQ(*it1, *it2);
    ++it1;
    ++it2;
  }
}

TEST(Check_Set, move_operator) {
  std::initializer_list<int> list{11, 4, 2, 3,  9,  10, 5,
                                  7,  6, 8, 13, 12, 14, 15};
  s21::Set<int> mSet1(list);
  s21::Set<int> mSet2 = std::move(mSet1);
  ASSERT_TRUE(mSet1.Empty());
  ASSERT_FALSE(mSet2.Empty());
}

TEST(Check_Set, max_size) {
  s21::Set<int> mSet;
  ASSERT_EQ(2305843009213693951, mSet.MaxSize()); //
}

TEST(Check_Multiset, multi_fromStartToEnd) {
  s21::Multiset<int> mMulti;
  std::multiset<int> oMulti;
  mMulti.Insert(1);
  oMulti.insert(1);
  mMulti.Insert(1);
  oMulti.insert(1);
  mMulti.Insert(2);
  oMulti.insert(2);
  mMulti.Insert(3);
  oMulti.insert(3);
  mMulti.Insert(3);
  oMulti.insert(3);
  auto it1 = mMulti.begin();
  auto it2 = oMulti.begin();
  while (it1 != mMulti.end() && it2 != oMulti.end()) {
    ASSERT_EQ(*it1, *it2);
    ++it1;
    ++it2;
  }
}

TEST(Check_Multiset, multi_initlist) {
  std::initializer_list<int> list = {1, 1,  1,  2, 2, 2, 3,  3, 5,
                                     6, -1, -1, 6, 7, 9, 22, 0, -3};
  s21::Multiset<int> mMulti(list);
  std::multiset<int> oMulti(list);
  auto it1 = mMulti.begin();
  auto it2 = oMulti.begin();
  while (it1 != mMulti.end() && it2 != oMulti.end()) {
    ASSERT_EQ(*it1, *it2);
    ++it1;
    ++it2;
  }
}

TEST(Check_Multiset, multi_copy) {
  std::initializer_list<int> list = {1, 1,  1,  2, 2, 2, 3,  3, 5,
                                     6, -1, -1, 6, 7, 9, 22, 0, -3};
  s21::Multiset<int> mMulti1(list);
  s21::Multiset<int> mMulti2(mMulti1);
  auto it1 = mMulti1.begin();
  auto it2 = mMulti2.begin();
  while (it1 != mMulti1.end() && it2 != mMulti2.end()) {
    ASSERT_EQ(*it1, *it2);
    ++it1;
    ++it2;
  }
}

TEST(Check_Multiset, multi_move) {
  std::initializer_list<int> list = {1, 1,  1,  2, 2, 2, 3,  3, 5,
                                     6, -1, -1, 6, 7, 9, 22, 0, -3};
  s21::Multiset<int> mMulti1(list);
  std::multiset<int> oMulti1(list);
  s21::Multiset<int> mMulti2(std::move(mMulti1));
  std::multiset<int> oMulti2(std::move(oMulti1));
  EXPECT_TRUE(mMulti1.Empty());
  EXPECT_TRUE(oMulti1.empty());
  auto it1 = mMulti2.begin();
  auto it2 = oMulti2.begin();
  while (it1 != mMulti2.end() && it2 != oMulti2.end()) {
    ASSERT_EQ(*it1, *it2);
    ++it1;
    ++it2;
  }
}

TEST(Check_Multiset, multi_eq) {
  std::initializer_list<int> list = {1, 1,  1,  2, 2, 2, 3,  3, 5,
                                     6, -1, -1, 6, 7, 9, 22, 0, -3};
  s21::Multiset<int> mMulti1(list);
  std::multiset<int> oMulti1(list);
  s21::Multiset<int> mMulti2 = std::move(mMulti1);
  std::multiset<int> oMulti2 = std::move(oMulti1);
  EXPECT_TRUE(mMulti1.Empty());
  EXPECT_TRUE(oMulti1.empty());
  auto it1 = mMulti2.begin();
  auto it2 = oMulti2.begin();
  while (it1 != mMulti2.end() && it2 != oMulti2.end()) {
    ASSERT_EQ(*it1, *it2);
    ++it1;
    ++it2;
  }
}

TEST(Check_Multiset, size) {
  std::initializer_list<int> list = {1, 1,  1,  2, 2, 2, 3,  3, 5,
                                     6, -1, -1, 6, 7, 9, 22, 0, -3};
  s21::Multiset<int> mMulti2(list);
  std::multiset<int> oMulti2(list);
  auto it1 = mMulti2.begin();
  auto it2 = oMulti2.begin();
  while (it1 != mMulti2.end() && it2 != oMulti2.end()) {
    ASSERT_EQ(*it1, *it2);
    ++it1;
    ++it2;
  }
  ASSERT_EQ(mMulti2.Size(), oMulti2.size());
}

TEST(Check_Multiset, max_size_int) {
  s21::Multiset<int> mMulti;
  ASSERT_EQ(2305843009213693951, mMulti.MaxSize());
}

TEST(Check_Multiset, multi_clear) {
  std::initializer_list<int> list = {1, 1,  1,  2, 2, 2, 3,  3, 5,
                                     6, -1, -1, 6, 7, 9, 22, 0, -3};
  s21::Multiset<int> mMulti(list);
  mMulti.Clear();
  ASSERT_TRUE(mMulti.Empty());
}

TEST(Check_Multiset, multi_erase) {
  std::initializer_list<int> list = {1, 1,  1,  2, 2, 2, 3,  3, 5,
                                     6, -1, -1, 6, 7, 9, 22, 0, -3};
  s21::Multiset<int> mMulti2(list);
  std::multiset<int> oMulti2(list);
  auto rit1 = mMulti2.begin();
  auto rit2 = oMulti2.begin();
  ++rit2;
  ++rit1;
  mMulti2.Erase(rit1);
  oMulti2.erase(rit2);
  auto it1 = mMulti2.begin();
  auto it2 = oMulti2.begin();
  while (it1 != mMulti2.end() && it2 != oMulti2.end()) {
    ASSERT_EQ(*it1, *it2);
    ++it1;
    ++it2;
  }
  ASSERT_EQ(mMulti2.Size(), oMulti2.size());
}

TEST(Check_Multiset, multi_erase2) {
  std::initializer_list<int> list = {1, 1,  1,  2, 2, 2, 3,  3, 5,
                                     6, -1, -1, 6, 7, 9, 22, 0, -3};
  s21::Multiset<int> mMulti2(list);
  std::multiset<int> oMulti2(list);
  auto rit1 = mMulti2.begin();
  auto rit2 = oMulti2.begin();
  mMulti2.Erase(rit1);
  oMulti2.erase(rit2);
  auto it1 = mMulti2.begin();
  auto it2 = oMulti2.begin();
  while (it1 != mMulti2.end() && it2 != oMulti2.end()) {
    ASSERT_EQ(*it1, *it2);
    ++it1;
    ++it2;
  }
  ASSERT_EQ(mMulti2.Size(), oMulti2.size());
}

TEST(Check_Multiset, multi_swap) {
  std::initializer_list<int> list = {1, 1,  1,  2, 2, 2, 3,  3, 5,
                                     6, -1, -1, 6, 7, 9, 22, 0, -3};
  s21::Multiset<int> mMulti1(list);
  s21::Multiset<int> mMulti2;
  mMulti1.Swap(mMulti2);
  EXPECT_TRUE(mMulti1.Empty());
  EXPECT_FALSE(mMulti2.Empty());
}

TEST(Check_Multiset, multi_merge) {
  std::initializer_list<int> list = {1, 2, 3, 3, 4, 5, 5, 6};
  std::initializer_list<int> list2 = {1, 2, 3, 3, 4, 5, 5, 6, 1, 2, 3, 3, 4, 5, 5, 6};
  s21::Multiset<int> mMulti1(list);
  s21::Multiset<int> mMulti2(list);
  std::multiset<int> oMulti1(list2);
  mMulti1.Merge(mMulti2);
  EXPECT_TRUE(mMulti2.Empty());
  auto it1 = mMulti1.begin();
  auto it2 = oMulti1.begin();
  while (it1 != mMulti1.end() || it2 != oMulti1.end()) {
    ASSERT_EQ(*it1, *it2);
    ++it1;
    ++it2;
  }
}

TEST(Check_Multiset, find) {
  std::initializer_list<int> list = {1, 1,  1,  2, 2, 2, 3,  3, 5,
                                     6, -1, -1, 6, 7, 9, 22, 0, -3};
  s21::Multiset<int> mMulti(list);
  std::multiset<int> oMulti(list);
  auto it1 = mMulti.Find(3);
  auto it2 = oMulti.find(3);
  ASSERT_EQ(*it1, *it2);
  ++it1;
  ++it2;
  ASSERT_EQ(*it1, *it2);
  while (it1 != mMulti.end() || it2 != oMulti.end()) {
    ASSERT_EQ(*it1, *it2);
    ++it1;
    ++it2;
  }
}

TEST(Check_Multiset, contains) {
  std::initializer_list<int> list = {1, 1,  1,  2, 2, 2, 3,  3, 5,
                                     6, -1, -1, 6, 7, 9, 22, 0, -3};
  s21::Multiset<int> mMulti(list);
  EXPECT_TRUE(mMulti.Contains(-3));
  EXPECT_FALSE(mMulti.Contains(-10));
}

TEST(Check_Multiset, count) {
  std::initializer_list<int> list = {1, 1,  1,  2, 2, 2, 3,  3, 5,
                                     6, -1, -1, 6, 7, 9, 22, 0, -3};
  std::multiset<int> oMulti(list);
  s21::Multiset<int> mMulti(list);
  ASSERT_EQ(oMulti.count(1), mMulti.Count(1));
  ASSERT_EQ(oMulti.count(2), mMulti.Count(2));
  ASSERT_EQ(oMulti.count(0), mMulti.Count(0));
  ASSERT_EQ(oMulti.count(73), mMulti.Count(73));
}

TEST(Check_Multiset, lower1) {
  std::initializer_list<int> list = {1, 1,  1,  2, 2, 2,  3, 3, 5,
                                     6, -1, -1, 6, 7, 22, 9, 0, -3};
  std::multiset<int> oMulti(list);
  s21::Multiset<int> mMulti(list);
  ASSERT_TRUE(mMulti.LowerBound(77) == mMulti.end());
  auto it1 = mMulti.LowerBound(1);
  auto it2 = oMulti.lower_bound(1);
  while (it1 != mMulti.end() || it2 != oMulti.end()) {
    ASSERT_EQ(*it1, *it2);
    ++it1;
    ++it2;
  }
}

TEST(Check_Multiset, upper) {
  std::initializer_list<int> list = {1, 1,  1,  2, 2, 2,  3, 3, 5,
                                     6, -1, -1, 6, 7, 22, 9, 0, -3};
  std::multiset<int> oMulti(list);
  s21::Multiset<int> mMulti(list);
  ASSERT_TRUE(mMulti.UpperBound(23) == mMulti.end());
  ASSERT_EQ(*mMulti.UpperBound(6), *oMulti.upper_bound(6));
  auto it1 = mMulti.UpperBound(1);
  auto it2 = oMulti.upper_bound(1);
  while (it1 != mMulti.end() || it2 != oMulti.end()) {
    ASSERT_EQ(*it1, *it2);
    ++it1;
    ++it2;
  }
}

TEST(Check_Multiset, xtreme_upANDlow) {
  std::initializer_list<double> list = {22.3, 17.9, 323.2};
  std::multiset<double> oSet(list);
  s21::Multiset<double> mSet(list);
  ASSERT_DOUBLE_EQ(*oSet.upper_bound(1.3), *mSet.UpperBound(1.3));
  ASSERT_DOUBLE_EQ(*oSet.lower_bound(1.3), *mSet.LowerBound(1.3));
}

TEST(Check_Multiset, range) {
  std::initializer_list<int> list = {1, 1,  1,  2, 2, 2,  3, 3, 5,
                                     6, -1, -1, 6, 7, 22, 9, 0, -3};
  std::multiset<int> oSet(list);
  s21::Multiset<int> mSet(list);
  std::pair<std::multiset<int>::iterator, std::multiset<int>::iterator> p1;
  std::pair<s21::Multiset<int>::Iterator, s21::Multiset<int>::Iterator> p2;
  p1 = oSet.equal_range(2);
  p2 = mSet.EqualRange(2);
  ASSERT_EQ(*p1.first, *p2.first);
  ASSERT_EQ(*p1.second, *p2.second);
}

TEST(Tets, set_emplace) {
  std::initializer_list<double> list = {1.2, 3.7, 3.14, 8.9};
  std::set<double> set1(list);
  s21::Set<double> set2(list);
  set1.emplace(1.2);
  set1.emplace(3.7);
  set1.emplace(9.9);
  auto v2 = set2.Emplace(1.2, 3.7, 9.9);
  auto it2 = v2.begin();
  for (int i = 0; i < 3; ++i, ++it2) {
    if (i == 2) {
      ASSERT_TRUE((*it2).second);
    } else {
      ASSERT_FALSE((*it2).second);
    }
  }
  auto iter1 = set1.begin();
  auto iter2 = set2.begin();
  while (iter1 != set1.end() || iter2 != set2.end()) {
    ASSERT_DOUBLE_EQ(*iter1, *iter2);
    ++iter1;
    ++iter2;
  }
}

TEST(Check_Multiset, set_emplace_empty) {
  std::initializer_list<int> list = {1, 3, 3, 8, 17};
  s21::Set<int> set1(list);
  std::set<int> set2(list);
  auto v1 = set1.Emplace();
  auto it1 = v1.begin();
  ASSERT_FALSE((*it1).second);
  auto iter1 = set1.begin();
  auto iter2 = set2.begin();
  while (iter1 != set1.end() || iter2 != set2.end()) {
    ASSERT_EQ(*iter1, *iter2);
    ++iter1;
    ++iter2;
  }
}

TEST(Check_Multiset, multi_emplace) {
  std::initializer_list<double> list = {1.2, 3.7, 3.14, 8.9};
  std::multiset<double> set1(list);
  s21::Multiset<double> set2(list);
  set1.emplace(1.2);
  set1.emplace(3.7);
  set1.emplace(9.9);
  auto v2 = set2.Emplace(1.2, 3.7, 9.9);
  auto it2 = v2.begin();
  for (int i = 0; i < 3; ++i, ++it2) {
    ASSERT_TRUE((*it2).second);
  }
  auto iter1 = set1.begin();
  auto iter2 = set2.begin();
  while (iter1 != set1.end() || iter2 != set2.end()) {
    ASSERT_DOUBLE_EQ(*iter1, *iter2);
    ++iter1;
    ++iter2;
  }
}

TEST(Check_Multiset, multi_emplce_empty) {
  std::initializer_list<int> list = {1, 3, 3, 8, 17};
  s21::Multiset<int> set1(list);
  std::multiset<int> set2(list);
  auto v1 = set1.Emplace();
  auto it1 = v1.begin();
  ASSERT_FALSE((*it1).second);
  auto iter1 = set1.begin();
  auto iter2 = set2.begin();
  while (iter1 != set1.end() || iter2 != set2.end()) {
    ASSERT_EQ(*iter1, *iter2);
    ++iter1;
    ++iter2;
  }
}
