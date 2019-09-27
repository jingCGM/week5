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

#include <vector>
#include <gtest/gtest.h>
#include "pidController.h"



TEST(dummy, one_step_test) {
	std::vector<double> parametersPID = {0.01,4,0, 0.0001,0, -100,100};
	pidController controller(parametersPID);

	double groundTruth = 1;
	double errorPID = 0;

	errorPID = controller.getError(groundTruth);

	EXPECT_EQ(errorPID, groundTruth);
}

TEST(dummy2, threshold_test) {
	std::vector<double> parametersPID = {0.01,4,0, 0.0001,0, -100,100};
	pidController controller(parametersPID);

	double groundTruth = 1;
	double thresholdPID = 0.01;
	double errorPID = 0;

	do {
		errorPID = controller.getError(groundTruth);
	} while(std::abs(errorPID-groundTruth)>thresholdPID);

	EXPECT_EQ(errorPID, groundTruth);
}