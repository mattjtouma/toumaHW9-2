// This function takes no command line arguments

#include "AnalogIn.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(int argc, char* argv[]){
	
	// Create an AnalogIn object (AIN0, p9.39)
	AnalogIn Apin(0);

	// Get the ADC value
	int reading = Apin.readADCsample();
	cout << "ADC value: " << reading << endl;

	// ADC value needs to be converted to a voltage
	float voltage = reading*(1.8/4096.0);
	cout << "Voltage: " << voltage << endl;
	
	// Compute the Resistance from that voltage
	float R = (voltage*10000.0/1.8)/(1.0 - (voltage/1.8));

	// Display the resistance to the nearest ohm in kilo-ohms if 
	// R >= 1000. Otherwise, print ohms
	if(R < 1000)
		cout << "Resistance: " << round(R) << " ohms" << endl;
	else
		cout << "Resistance: " << round(R)/1000.0 << " kohms" << endl;
}
