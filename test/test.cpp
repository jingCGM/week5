/**
 *  @file       test.cpp
 *  @author     Jing Liang
 *  @copyright  3-clause BSD
 *  @date       09/26/2019
 *  @version    1.0
 *
 *  @brief      This file is to test PID controller
 *
 */

#include <gtest/gtest.h>
#include <vector>
#include <pidController.h>

/**
 * @brief    the function tests if the integerator buffer behaves right
 * @param    PIDTest is test name
 * @param    getError_test shows what function this test does
 * @return   none
 */
TEST(PIDTest, getError_test)  {
    std::vector<double> parametersPID = {1, 1, 1, 0.0001, 0, -100, 100};
	pidController controller(parametersPID);

	double groundTruth = 1;
    double systemOutput = 0.5;
	double error = 0;

	error = controller.getError(groundTruth, systemOutput);

	EXPECT_EQ(error, 0.5);
}


/**
 * @brief    the function tests if the integerator buffer behaves right
 * @param    PIDTest is test name
 * @param    computePIDOutput_test shows what function this test does
 * @return   none
 */
TEST(PIDTest, computePIDOutput_test)  {
	std::vector<double> parametersPID = {1, 1, 1, 0.0001, 0, -100, 100};
	pidController controller(parametersPID);

	double groundTruth = 1;
    double systemOutput = 0;
	double pidOutput = 0;

    double error = controller.getError(groundTruth, systemOutput);
	pidOutput = controller.computePIDOutput(error);

	EXPECT_EQ(pidOutput, 10001.0001);
    EXPECT_EQ(controller.previousError, 1);
    EXPECT_EQ(controller.totalIntegration, 0.0001);
}
