/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Neuron.h
 * Author: den
 *
 * Created on December 7, 2018, 7:54 PM
 */

#ifndef NEURON_H
#define NEURON_H

#include <cstdlib>
#include <vector>
using std::vector;



struct Connection
{
	double weight;
	double deltaWeight;
};


class Neuron;
typedef vector<Neuron> Layer;


class Neuron
{
	public:
		Neuron(unsigned numOutputs, unsigned m_myIndex);
		void setOutputVal(double val) { m_outputVal = val; }
	       	double getOutputVal() const { return m_outputVal; }		
		void feedForward(const Layer &prevLayer);
		void calcOutputGradients(double targetVal);
		void calcHiddenGradients(const Layer &nextLayer);
		void updateInputWeights(Layer &prevLayer);
	private:
		static double eta;
		static double alpha;
		static double transferFunction(double x);
		static double transferFunctionDerivate(double x);
		static double randomWeight(void) { return rand() / double(RAND_MAX); }
		double sumDOW(const Layer &nextLayer) const;
		double m_outputVal;
		vector<Connection> m_outputWeights;
		unsigned m_myIndex;
		double m_gradient;
};



#endif /* NEURON_H */

