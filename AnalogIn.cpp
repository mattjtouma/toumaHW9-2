#include "AnalogIn.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

#define ADC_PATH "/sys/bus/iio/devices/iio:device0/in_voltage"


AnalogIn::AnalogIn(){

}

// Constructor
AnalogIn::AnalogIn(unsigned int n){
	// define the 'number' variable which will be used
	// by other functions in this implementation file.
	number = n;
}

// getNumber was already implemented in the header file.
// It simply returns number.
//unsigned int AnalogIn::getNumber()

void AnalogIn::setNumber(unsigned int n){
	// Change the value of 'number' to the new ADC number
	number = n;
}

int AnalogIn::readADCsample(){
	// Create a variable to store the ADC value that will be read.
	unsigned int ADC_val;

	// Create the ADC filepath based on the ADC number.
	string ADC_filepath = ADC_PATH + to_string(number) + "_raw";
	//cout << ADC_filepath << endl;

	// Create an fstream object
	fstream ADC_in_file;
	// Open the file with read mode.
	ADC_in_file.open(ADC_filepath.c_str(), fstream::in);
	// Store the contents of the file into the 'ADC_val' variable.
	ADC_in_file >> ADC_val;
	//cout << "ADC value: " << ADC_val << endl;
	// Close the file.
	ADC_in_file.close();

	// Return the int ADC value.
	return ADC_val;
}

// Destructor
AnalogIn::~AnalogIn(){

}
