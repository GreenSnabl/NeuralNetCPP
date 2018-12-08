
#include "TrainingData.h"
#include "NeuralNet.h"
#include <iostream>
#include <cassert>

using namespace std;

// class to read training data from a file


void showVectorVals(string label, vector<double> &v)
{
	cout << label << " ";
	for (unsigned i = 0; i < v.size(); ++i) {
		cout << v[i] << " ";
	}

	cout << endl;
}


int main() {
	TrainingData trainData("tmp/ampel.txt");

	// e.g., {3, 2, 1}
	vector<unsigned> topology;
	trainData.getTopology(topology);	
	NeuralNet myNet(topology);

	vector<double> inputVals, targetVals, resultVals;
	int trainingPass = 0;

		while (!trainData.isEof()) {
			++ trainingPass;
			cout << endl << "Pass " << trainingPass;
			
			// Get new input data and feed it forward
			if (trainData.getNextInputs(inputVals) != topology[0]) {
				break;		
			}

			showVectorVals(": Inputs:", inputVals);
			myNet.feedForward(inputVals);

			// Collect the net's actual results:
			myNet.getResults(resultVals);
			showVectorVals("Outputs:", resultVals);

			// Train the net what the outputs should have been
			trainData.getTargetOutputs(targetVals);
			showVectorVals("Targets:", targetVals);
			assert(targetVals.size() == topology.back());
			
			myNet.backProp(targetVals);

			// Report how well the training is working, average over recent samples
			cout << "Net recent average error: "
				<< myNet.getRecentAverageError() << endl;
		}

		cout << endl << "Done" << endl;

		}
