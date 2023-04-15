#include <gtest/gtest.h>

#include "test_array.cc"
#include "test_set_multiset.cc"
#include "test_map.cc"
#include "test_vector.cc"
#include "test_queue.cc"
#include "test_stack.cc"
#include "test_list.cc"

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}