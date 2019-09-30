/**
 *  @file       pidController.h
 *  @author     Jing Liang
 *  @copyright  3-clause BSD
 *  @date       09/26/2019
 *  @version    1.0
 *
 *  @brief      This file is a header file to define a simple PID controller
 *
 */

#ifndef INCLUDE_PIDCONTROLLER_H_
#define INCLUDE_PIDCONTROLLER_H_

#include <vector>

/**
 * @brief    pidController
 */
class pidController {
private:
	double pidGain = 0;
	double pidIntegral = 0;
	double pidDerivative = 0;

	double timeStep = 0;
	// double inputValue = 0;

	double maxIntegeral = 0;
	double minIntegeral = 0;

public:

    double previousError = 0;
	double totalIntegration = 0;

	/**
	 * @brief    pidController's constructor
	 * @param    parameters const std::vector<double> , with {gain coefficient, integral coefficient, derivative coefficient, timestep, initial integral value}
	 * @return   none
	 */
	explicit pidController(const std::vector<double>& parameters);

	/**
	 * @brief    get coefficent of propotional gain
	 * @param    none
	 * @return   pidGain double
	 */
	double getGain();

	/**
	 * @brief    get coefficent of integral
	 * @param    none
	 * @return   pidIntegral double
	 */
	double getIntegral();

	/**
	 * @brief    get coefficent of derivative
	 * @param    none
	 * @return   pidDerivative double
	 */
	double getDerivative();

	/**
	 * @brief    Get error of one step by taking the difference of the system velocity output and setpoint
	 * @param    setPoint double&, systemOutput double&
	 * @return   pidError double
	 */
	double getError(double& setPoint, double& systemOutput);

	/**
	 * @brief    Use getError output to generate error each step and compute controller output
	 * @param    currentError double&
	 * @return   output double
	 */
	double computePIDOutput(double& currentError);
};

#endif      // INCLUDE_PIDCONTROLLER_H_
