#include <gtest/gtest.h>
#include "../src/Map + Set + Multiset/map.h"
#include <map>

using namespace Study;

#define PAIR_INT                                                                                  \
{                                                                                             \
    std::pair<int, int>(50, 3), std::pair<int, int>(25, 23), std::pair<int, int>(12, 63),     \
        std::pair<int, int>(37, 37), std::pair<int, int>(18, 53), std::pair<int, int>(6, 93), \
        std::pair<int, int>(31, 13), std::pair<int, int>(45, 31), std::pair<int, int>(1, 33), \
        std::pair<int, int>(8, 35), std::pair<int, int>(10, 35), std::pair<int, int>(14, 34), \
        std::pair<int, int>(20, 33), std::pair<int, int>(27, 76), std::pair<int, int>(33, 1), \
        std::pair<int, int>(35, 33), std::pair<int, int>(39, 76), std::pair<int, int>(42, 1), \
        std::pair<int, int>(47, 33)                                                           \
}

TEST(check_map, empty1) {
  Map<int, int> m1;
  Map<int, int> m2(PAIR_INT);
  EXPECT_TRUE(m1.Empty());
  EXPECT_FALSE(m2.Empty());
}

TEST(check_map, empty2) {
  Map<int, int> map;
  std::map<int, int> origin;
  ASSERT_EQ(map.Size(), origin.size());
  ASSERT_EQ(map.Size(), 0);
}

TEST(check_map, size) {
  std::map<int, int> m1(PAIR_INT);
  Map<int, int> m2(PAIR_INT);
  ASSERT_EQ(m1.size(), m2.Size());
}

TEST(check_map, clear) {
  Map<int, int> m1(PAIR_INT);
  m1.Clear();
  EXPECT_TRUE(m1.Empty());
}
TEST(check_map, at) {
  std::map<int, int> m1(PAIR_INT);
  Map<int, int> m2(PAIR_INT);

  ASSERT_EQ(m1.at(50), m2.At(50));
}

TEST(check_map, constructor_1) {
  Map<int, int> m1;
  EXPECT_TRUE(m1.Empty());
}

TEST(check_map, constructor_2) {
  Map<int, int> m1(PAIR_INT);
  ASSERT_EQ(m1.Size(), 19);
}

TEST(check_map, constructor_3) {
  Map<int, int> m1(PAIR_INT);
  Map<int, int> m2(m1);
  ASSERT_EQ(m1.Size(), 19);
  ASSERT_EQ(m2.Size(), 19);
}

TEST(check_map, constructor_4) {
  Map<int, int> m1(PAIR_INT);
  Map<int, int> m2(std::move(m1));
  ASSERT_EQ(m2.Size(), 19);
  ASSERT_EQ(m1.Size(), 0);
}

TEST(check_map, insert1) {
  Map<int, int> m1;
  std::map<int, int> m2;

  Map<int, int>::iterator it;
  std::map<int, int>::iterator std_it;

  m1.Insert(1, 1);
  m2.insert(std::pair<int, int>(1, 1));
  it = m1.begin();
  std_it = m2.begin();
  EXPECT_EQ((*it).first, (*std_it).first);
}
TEST(check_map, insert2) {
  Map<int, int> m1;
  m1[55] = 88;
  m1[2] = 7;
  m1[233] = 252;
  m1.InsertOrAssign(3, 18);

  EXPECT_EQ(m1[3], 18);
}

TEST(check_map, erase1) {
  Map<int, int> m1;
  m1[1] = 2;
  m1[2] = 2;
  m1[3] = 2;
  m1[4] = 2;
  m1[5] = 2;
  Map<int, int>::iterator it;
  it = m1.end();
  --it;
  m1.Erase(it);
  EXPECT_FALSE(m1.Empty());
}

TEST(check_map, erase2) {
  Map<int, int> m1;
  m1[1] = 5;
  m1[2] = 1;

  Map<int, int>::iterator it;
  it = m1.end();
  m1.Erase(it);
  EXPECT_FALSE(m1.Empty());
}

TEST(check_map, erase3) {
  Map<int, int> m1;
  m1[5] = 2;
  m1[8] = 2;
  m1[7] = 2;
  m1[9] = 2;

  Map<int, int>::iterator it;
  it = m1.end();
  --it;
  m1.Erase(it);
  EXPECT_FALSE(m1.Empty());
}

TEST(check_map, erase4) {
  Map<int, int> m1;
  m1[9] = 2;
  m1[6] = 2;
  m1[5] = 2;

  Map<int, int>::iterator it;
  it = m1.end();
  --it;
  m1.Erase(it);
  EXPECT_FALSE(m1.Empty());
}

TEST(check_map, erase5) {
  Map<int, int> m1;
  m1[5] = 2;
  m1[7] = 2;
  m1[6] = 2;

  Map<int, int>::iterator it;
  it = m1.end();
  m1.Erase(it);
  EXPECT_FALSE(m1.Empty());
}

TEST(check_map, erase6) {
  Map<int, int> m1({std::pair<int, int>(4, 23)});
  Map<int, int>::iterator it;
  it = m1.begin();
  m1.Erase(it);
  EXPECT_TRUE(m1.Empty());
}

TEST(check_map, swap1) {
  Map<int, int> m1({std::pair<int, int>(4, 23)});
  Map<int, int> m2({std::pair<int, int>(33, 2)});
  m1.Swap(m2);
}

TEST(check_map, merge) {
  Map<int, int> m1;
  Map<int, int> m2;

  Map<int, int> m3;

  m1[15] = 2;
  m1[13] = 2;
  m1[17] = 2;

  m2[18] = 2;
  m2[13] = 2;
  m2[17] = 2;

  m3[15] = 2;
  m3[13] = 2;
  m3[17] = 2;
  m3[18] = 2;

  m1.Merge(m2);

  Map<int, int>::iterator it;
  Map<int, int>::iterator std_it;
  it = m1.begin();
  std_it = m3.begin();
  while (it != m1.end()) {
      EXPECT_EQ((*it).first, (*std_it).first);
      EXPECT_EQ((*it).second, (*std_it).second);
      ++it;
      ++std_it;
  }
}

TEST(check_map, contains) {
  Map<int, int> m1(PAIR_INT);
  EXPECT_TRUE(m1.Contains(18));
  EXPECT_FALSE(m1.Contains(13));
}

TEST(check_map, emplace) {
  Map<int, int> my_map;
  std::map<int, int> original_map;

  std::pair<int, int> pair = {1, 1};
  my_map.Emplace(pair);
  original_map.emplace(pair);

  Map<int, int>::iterator my_it = my_map.begin();
  std::map<int, int>::iterator originalIt = original_map.begin();

  for (size_t i = 0; i < my_map.Size(); ++i) {
      EXPECT_EQ((*my_it).first, (*originalIt).first);
      EXPECT_EQ((*my_it).second, (*originalIt).second);
      ++my_it;
      ++originalIt;
  }
}

TEST(check_map, operator_add1) {
    Map<int, int> m1(PAIR_INT);
    std::map<int, int> m2(PAIR_INT);

    Map<int, int>::iterator it;
    std::map<int, int>::iterator std_it;
    it = m1.begin();
    std_it = m2.begin();
    while (it != m1.end()) {
        EXPECT_EQ((*it).first, (*std_it).first);
        EXPECT_EQ((*it).second, (*std_it).second);
        ++it;
        ++std_it;
    }
}

TEST(check_map, operator_sub) {
    Map<int, int> m1(PAIR_INT);
    std::map<int, int> m2(PAIR_INT);

    Map<int, int>::iterator it;
    std::map<int, int>::iterator std_it;
    it = m1.end();
    --it;
    std_it = m2.end();
    --std_it;
    while (it != m1.begin()) {
        EXPECT_EQ((*it).first, (*std_it).first);
        EXPECT_EQ((*it).second, (*std_it).second);
        --it;
        --std_it;
    }
}