/**
 *  @file    main.cpp
 *  @author  Jing Liang
 *  @copyright 3-clause BSD
 *  @date    09/26/2019
 *  @version 1.0
 *
 *  @brief This is main file for test
 *
 */


#include <gtest/gtest.h>


int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
