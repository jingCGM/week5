/**
 *  @file    pidController.cpp
 *  @author  Kevin Dong
 *  @copyright 3-clause BSD
 *  @date    09/28/2019
 *  @version 1.0
 *
 *  @brief Definitions for pidController.h
 *
 */


#include "pidController.h"


pidController::pidController(const std::vector<double>& parameters) 
{
	pidGain = *parameters.begin();
	pidIntegral = *(parameters.begin()+1);          //std::next(parameters.begin(),1);
	pidDerivative = *(parameters.begin()+2);
	timeStep = *(parameters.begin()+3);
	totalIntegration = *(parameters.begin()+4);
	minIntegeral = *(parameters.begin()+5);
	maxIntegeral = *(parameters.begin()+6);
}


double pidController::getGain(){return pidGain;}


double pidController::getIntegral(){return pidIntegral;}


double pidController::getDerivative(){return pidDerivative;}


double pidController::getError(const double& inputValue) 
{
	pidError = inputValue - previousError;
	totalIntegration = std::max(minIntegeral, std::min(pidError*timeStep+totalIntegration, maxIntegeral));

	pidError = pidGain*pidError + pidIntegral*totalIntegration + pidDerivative*(pidError - previousError)/timeStep;
	previousError = pidError;
	return pidError;
}


double pidController::tunningPID(const double& inputValue)
{
    double error = getError(inputValue);

    return error;
}
