/**
 *  @file    pidController.h
 *  @author  Jing Liang
 *  @copyright 3-clause BSD
 *  @date    09/26/2019
 *  @version 1.0
 *
 *  @brief This file is a header file to define a simple PID controller
 *
 */

#ifndef PID_CONTROLLER_H
#define PID_CONTROLLER_H


/**
 * @brief    pidController
 */
class pidController {
private:
	double pidGain = 0;
	double pidIntegral = 0;
	double pidDerivative = 0;

	double timeStep = 0;
	double inputValue = 0;

	double maxIntegeral = 0;
	double minIntegeral = 0;

	double pidError = 0;
	double previousError = 0;

	double totalIntegration = 0;

public:
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
	 * @brief    get error of one step
	 * @param    inputValue const double&, it is the input signal for one step
	 * @return   pidError double
	 */
	double getError(const double& inputValue);

	/**
	 * @brief    use getError function to generate error each step and tune the controller to stable position
	 * @param    inputValue const double&, it is the input signal for each step
	 * @return   output double
	 */
	double tunningPID(const double& inputValue);
};

#endif