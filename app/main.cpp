/**
 *  @file    main.cpp
 *  @author  Jing Liang
 *  @copyright 3-clause BSD
 *  @date    09/26/2019
 *  @version 1.0
 *
 *  @brief This file is a simple PID controller
 *
 */

#include <iostream>
#include <vector>
#include <iterator>
#include <cmath>

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
	double getGain(){return pidGain;}

	/**
	 * @brief    get coefficent of integral
	 * @param    none
	 * @return   pidIntegral double
	 */
	double getIntegral(){return pidIntegral;}

	/**
	 * @brief    get coefficent of derivative
	 * @param    none
	 * @return   pidDerivative double
	 */
	double getDerivative(){return pidDerivative;}

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

pidController::pidController(const std::vector<double>& parameters) {
	pidGain = *parameters.begin();
	pidIntegral = * (parameters.begin()+1); //std::next(parameters.begin(),1);
	pidDerivative = * (parameters.begin()+2);
	timeStep = * (parameters.begin()+3);
	totalIntegration = * (parameters.begin()+4);
	minIntegeral = * (parameters.begin()+5);
	maxIntegeral = * (parameters.begin()+6);
}

double pidController::getError(const double& inputValue) {
	pidError = inputValue - previousError;
	totalIntegration =std::max(minIntegeral, std::min(pidError*timeStep+totalIntegration, maxIntegeral));

	pidError = pidGain*pidError + pidIntegral*totalIntegration + pidDerivative*(pidError - previousError)/timeStep;
	previousError = pidError;
	return pidError;
}

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

	do {
		errorPID = controller.getError(groundTruth);
		std::cout<<"error: "<<errorPID<<std::endl;
	} while(std::abs(errorPID-groundTruth)>thresholdPID);

	return 0;
}
