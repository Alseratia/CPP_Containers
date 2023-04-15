#include <gtest/gtest.h>

#include <array>
#include <iostream>

#include "../src/Vector + Array/array.h"

using namespace Study;

template <typename T, std::size_t N>
bool CompareArray(std::array<T, N> ar1, Array<T, N> ar2) {
  bool result = (ar1.size() == ar2.Size());
  for (std::size_t i = 0; i < ar2.Size() && result; ++i) {
    result *= (ar1[i] == ar2[i]);
    result *= (ar1.at(i) == ar2.At(i));
  }
  result *= (ar1.max_size() == ar2.MaxSize());
  result *= (ar1.empty() == ar2.Empty());
  if (!ar1.empty() && !ar2.Empty()) {
    result *= (ar1.back() == ar2.Back());
    result *= (ar1.front() == ar2.Front());
  }
  return result;
}

TEST(array_check, constructors) {
  std::array<char, 4> ar1({'a', 'b', 'c', 'd'});
  Array<char, 4> ar2({'a', 'b', 'c', 'd'});
  ASSERT_TRUE(CompareArray(ar1, ar2));

  std::array<char, 4> ar1copy(ar1);
  Array<char, 4> ar2copy(ar2);
  ASSERT_TRUE(CompareArray(ar1copy, ar2copy));

  std::array<char, 4> ar1operator;
  ar1operator = ar1;
  Array<char, 4> ar2operator;
  ar2operator = ar2;
  ASSERT_TRUE(CompareArray(ar1operator, ar2operator));

  std::array<char, 4> ar1move(std::move(ar1));
  Array<char, 4> ar2move(std::move(ar2));
  ASSERT_TRUE(CompareArray(ar1move, ar2move));

  ar1 = std::move(ar1move);
  ar2 = std::move(ar2move);
  ASSERT_TRUE(CompareArray(ar1, ar2));
}

TEST(array_check, base_functions) {
  std::array<int, 4> ar1({2, 6, 5, 3});
  Array<int, 4> ar2({2, 6, 5, 3});
  ASSERT_TRUE(CompareArray(ar1, ar2));

  std::array<int, 0> arr1;
  Array<int, 0> arr2;
  ASSERT_TRUE(CompareArray(arr1, arr2));
}

TEST(array_check, array_functions) {
  std::array<char, 4> ar1({'a', 'b', 'c', 'd'});
  Array<char, 4> ar2({'a', 'b', 'c', 'd'});
  char f = 'f';
  ar1.fill(f);
  ar2.Fill(f);
  ASSERT_TRUE(CompareArray(ar1, ar2));

  std::array<char, 4> arr1;
  Array<char, 4> arr2;
  ar1.swap(arr1);
  ar2.Swap(arr2);
  ASSERT_TRUE(CompareArray(arr1, arr2));
}