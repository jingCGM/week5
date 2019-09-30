/**
 *  @file       pidController.cpp
 *  @author     Kevin Dong
 *  @copyright  3-clause BSD
 *  @date       09/28/2019
 *  @version    1.0
 *
 *  @brief      Definitions for pidController.h
 *
 */


#include <pidController.h>


pidController::pidController(const std::vector<double>& parameters) {
	pidGain = *parameters.begin();
	pidIntegral = *(parameters.begin()+1);          // std::next(parameters.begin(),1);
	pidDerivative = *(parameters.begin()+2);
	timeStep = *(parameters.begin()+3);
	totalIntegration = *(parameters.begin()+4);
	minIntegeral = *(parameters.begin()+5);
	maxIntegeral = *(parameters.begin()+6);
}


double pidController::getGain() {return pidGain;}


double pidController::getIntegral() {return pidIntegral;}


double pidController::getDerivative() {return pidDerivative;}


double pidController::getError(double& setPoint, double& systemOutput) {
	double pidError = setPoint - systemOutput;
    return pidError;
}


double pidController::computePIDOutput(double& currentError) {
    totalIntegration = std::max(minIntegeral, std::min(currentError*timeStep+totalIntegration, maxIntegeral));

	double output = pidGain*currentError + pidIntegral*totalIntegration + pidDerivative*(currentError - previousError)/timeStep;
	previousError = currentError;
	return output;
}
