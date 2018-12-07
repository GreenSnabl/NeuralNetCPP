/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TrainingData.h
 * Author: den
 *
 * Created on December 7, 2018, 7:44 PM
 */
#include <vector>
#include <fstream>
#include <string>

#ifndef TRAININGDATA_H
#define TRAININGDATA_H

class TrainingData {
	public:
		TrainingData(const std::string filename);
		bool isEof(void) { return m_trainingDataFile.eof(); }
		void getTopology(std::vector<unsigned> &topology);

		// Returns the number of input values read from the file
		unsigned getNextInputs(std::vector<double> &inputVals);
		unsigned getTargetOutputs(std::vector<double> &targetOutputVals);
	
	private:
		std::ifstream m_trainingDataFile;
};


#endif /* TRAININGDATA_H */

