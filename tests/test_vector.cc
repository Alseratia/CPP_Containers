#include <gtest/gtest.h>

#include <iostream>
#include <vector>

#include "../src/Vector + Array/vector.h"

using namespace Study;

template <typename T>
bool CompareVector(std::vector<T> ar1, Vector<T> ar2) {
  bool result = (ar1.size() == ar2.Size());
  for (std::size_t i = 0; i < ar2.Size() && result; ++i) {
    result *= (ar1[i] == ar2[i]);
    result *= (ar1.at(i) == ar2.At(i));
  }
  result *= (ar1.empty() == ar2.Empty());
  if (!ar1.empty() && !ar2.Empty()) {
    result *= (ar1.back() == ar2.Back());
    result *= (ar1.front() == ar2.Front());
  }
  return result;
}
TEST(Vector_check, constructors) {
  std::vector<int> vect1(4);
  Vector<int> vect2(4);
  ASSERT_TRUE(CompareVector<int>(vect1, vect2));

  std::vector<char> ar1({'a', 'b', 'c', 'd'});
  Vector<char> ar2({'a', 'b', 'c', 'd'});
  ASSERT_TRUE(CompareVector(ar1, ar2));

  std::vector<char> ar1copy(ar1);
  Vector<char> ar2copy(ar2);
  ASSERT_TRUE(CompareVector(ar1copy, ar2copy));

  std::vector<char> ar1operator;
  ar1operator = ar1;
  Vector<char> ar2operator;
  ar2operator = ar2;
  ASSERT_TRUE(CompareVector(ar1operator, ar2operator));

  std::vector<char> arr1({'a', 'b', 'c', 'd'});
  Vector<char> arr2({'a', 'b', 'c', 'd'});
  std::vector<char> ar1move(std::move(arr1));
  Vector<char> ar2move(std::move(arr2));
  arr1 = std::move(ar1move);
  arr2 = std::move(ar2move);
}
TEST(Vector_check, emplace) {
  std::vector<int> ar1({2,6,5,3});
  Vector<int> ar2({2,6,5,3});
  ar1.emplace(ar1.begin(),3);
  ar2.Emplace(ar2.begin(),3);
  ASSERT_TRUE(CompareVector(ar1, ar2));

  ar1.emplace_back(22);
  ar2.EmplaceBack(22);
  ASSERT_TRUE(CompareVector(ar1, ar2));

  std::vector<int> arr1;
  Vector<int> arr2;
  ASSERT_TRUE(CompareVector(arr1, arr2));
}
TEST(Vector_check, at) {
  Vector<int> ar1({2,6,5,3,5,4,6});
  ASSERT_ANY_THROW(ar1.At(20));
  ASSERT_ANY_THROW(ar1[20]);
  ASSERT_EQ(ar1.At(3), 3);
  ASSERT_EQ(ar1[3], 3);

  ASSERT_EQ(ar1.Front(), 2);
  ASSERT_EQ(ar1.Back(), 6);
}
TEST(Vector_check, other) {
  Vector<int> ar2;
  std::vector<int> ar3;
  int a = 3;
  ASSERT_TRUE(CompareVector(ar3, ar2));
  ar2.PushBack(a);
  ar3.push_back(a);
  ASSERT_TRUE(CompareVector(ar3, ar2));
  ar2.PushBack(a);
  ar3.push_back(a);
  ar2.PushBack(a);
  ar3.push_back(a);
  ASSERT_TRUE(CompareVector(ar3, ar2));
  ar2.ShrinkToFit();
  ar3.shrink_to_fit();
  ASSERT_TRUE(CompareVector(ar3, ar2));

  ar2.Reserve(10);
  ar3.reserve(10);
  ASSERT_TRUE(CompareVector(ar3, ar2));

  int b = 1;
  ar2.Insert(ar2.begin(), b);
  ar3.insert(ar3.begin(), b);
  ASSERT_TRUE(CompareVector(ar3, ar2));

  ar2.PopBack();
  ar3.pop_back();
  ASSERT_TRUE(CompareVector(ar3, ar2));

  ar2.Erase(ar2.begin());
  ar3.erase(ar3.begin());
  ASSERT_TRUE(CompareVector(ar3, ar2));

  ar2.Clear();
  ar3.clear();
  ASSERT_TRUE(CompareVector(ar3, ar2));
}