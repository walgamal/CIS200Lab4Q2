/*

 *Author: Wasim Algamal

 *Creation Date: 10/04/2020

 *Modification Date: 10/06/2020

 *Purpose: Computes a factorial recursively through a function, then calls that function
		   enough times to stress test the function to determine when “stack overflow” occurs.

*/

using namespace std;
#include <iostream>

int factorial(int value, bool& methodStatus) {

	if (value < 0) {
		methodStatus = false;
		return -1;
	}
	else if (value == 0) {
		methodStatus = true;
		return 1;
	}

	int returnVal = value * factorial(value - 1, methodStatus);

	return returnVal;
}
//factorial function

int main() {

	int value;
	bool methodStatus = NULL;
	char sentinel = 'y';

	while (sentinel == 'y' || sentinel == 'Y') {

		cout << "Please enter an integer whose factorial you'd like to compute: \n";
		cin >> value;

		int output = factorial(value, methodStatus);

		if (methodStatus == true) {
			cout << "The factorial of " << value << " is " << output << endl << endl;
		}
		else if (methodStatus == false) {
			cout << "Please retry with a value greater than 0. \n \n";
		}

		cout << "Enter \"y\" or \"Y\" to continue. All other input will quit the program. \n";
		cin >> sentinel;
		cout << endl;

	}
	//sentinel controlled while loop

	return 0;
}
