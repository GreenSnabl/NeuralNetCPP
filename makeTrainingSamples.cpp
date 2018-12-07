#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

void makeXOR() {
	// Random training sets for XOR -- tow inputs and one output
	
	cout << "topology: 2 4 1" << endl;
	for (int i = 2000; i >= 0; --i) {
		int n1 = static_cast<int>(2.0 * rand() / double(RAND_MAX));
		int n2 = static_cast<int>(2.0 * rand() / double(RAND_MAX));
		int t = n1 ^ n2; // should be 0 or 1
		cout << "in: " << n1 << ".0 " << n2 << ".0 " << endl;
		cout << "out: " << t << ".0" << endl;
	}
}

void makeAMPEL() {
	// Random training sets for XOR -- tow inputs and one output
	
	cout << "topology: 3 4 4 1" << endl;
	for (int i = 2000; i >= 0; --i) {
		int n1 = static_cast<int>(2.0 * rand() / double(RAND_MAX));
		int n2 = static_cast<int>(2.0 * rand() / double(RAND_MAX));
		int n3 = static_cast<int>(2.0 * rand() / double(RAND_MAX));
		int t = (n1 & ~n2 & ~n3) | (~n1 & n2 & ~n3); // should be 0 or 1
		cout << "in: " << n1 << ".0 " << n2 << ".0 " << n3 << ".0" << endl;
		cout << "out: " << t << ".0" << endl;
	}
}



int main() 
{
	makeAMPEL();
}
