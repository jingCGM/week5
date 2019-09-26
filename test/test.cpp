/**
 *  @file    test.cpp
 *  @author  Jing Liang
 *  @copyright 3-clause BSD
 *  @date    09/26/2019
 *  @version 1.0
 *
 *  @brief This file is to test PID controller
 *
 */

#include <iostream>
#include <vector>
#include <gtest/gtest.h>
#include "pidController.h"

/**
 * @brief    main function
 * @param    argc int
 * @param    argv char array
 * @return   0
 */
int main() {
	std::vector<double> parametersPID = {0.01,4,0, 0.0001,0, -100,100};
	pidController controller(parametersPID);

	std::cout<<"pid coefficient values are: "<<controller.getGain()<<"/"<<controller.getIntegral()<<"/"<<controller.getDerivative()<<std::endl;

	double groundTruth = 1;
	double thresholdPID = 0.01;
	double errorPID = 0;

	errorPID = controller.getError(groundTruth);
	std::cout<<"error: "<<errorPID<<std::endl;
	
	TEST(dummy, should_pass) {
		EXPECT_EQ(errorPID, groundTruth);
	}

	return 0;
}
