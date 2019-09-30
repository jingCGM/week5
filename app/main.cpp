/**
 *  @file       main.cpp
 *  @author     Jing Liang
 *  @copyright  3-clause BSD
 *  @date       09/26/2019
 *  @version    1.0
 *
 *  @brief      This file is main file of using a simple PID controller
 *
 */

#include <iostream>
#include <iterator>
#include <cmath>
#include <pidController.h>

/**
 * @brief    main function
 * @param    argc int
 * @param    argv char array
 * @return   0
 */
int main() {
    std::vector<double> parametersPID = {0.01, 4, 0, 0.0001, 0, -100, 100};
    pidController controller(parametersPID);
    std::cout << "pid coefficient values are: ";
    // std::cout << controller.getGain() << "/" << controller.getIntegral() << "/";
    // std::cout << controller.getDerivative() << std::endl;
    double groundTruth = 1;
    double systemOutput = 0.5;
    double error = 0;
    error = controller.getError(groundTruth, systemOutput);
	std::cout << "error: "<< error << std::endl;
	// do {
	// 	errorPID = controller.getError(groundTruth);
	// 	std::cout << "error: " << errorPID << std::endl;
	// } while (std::abs(errorPID-groundTruth) > thresholdPID);

	return 0;
}
