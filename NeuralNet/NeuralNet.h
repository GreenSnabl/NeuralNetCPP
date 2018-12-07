/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NeuralNet.h
 * Author: den
 *
 * Created on December 7, 2018, 8:01 PM
 */

#ifndef NEURALNET_H
#define NEURALNET_H


#include "Neuron.h"

class NeuralNet {
	public:
		NeuralNet(const vector<unsigned> &topology);
		void feedForward(const vector<double> &inputVals);
		void backProp(const vector<double> &targetVals);
		void getResults(vector<double> &resultVals) const;
		double getRecentAverageError(void) const { return m_recentAverageError; }
	private:
		vector<Layer> m_layers;
		double m_error;
		double m_recentAverageError;
		double m_recentAverageSmoothingFactor;
};

#endif /* NEURALNET_H */

