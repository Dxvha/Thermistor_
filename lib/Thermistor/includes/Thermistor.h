#ifndef THERMISTOR_H
#define THERMISTOR_H

// Constant for Celsius <-> Kelvin conversion
const double ZERO_CELSIUS = 273.15;

class Thermistor {
private:
    // Model parameters
    double Rref;               // Resistance at the reference temperature
    double R0;                 // Fixed resistance in the voltage divider
    double Beta;               // Beta coefficient of the thermistor
    double T0;                 // Reference temperature in Kelvin
    double Vcc;                // Supply voltage
    unsigned samplingBitsNumber; // Number of bits of the ADC converter

public:
    // Constructor
    Thermistor(double Rref, double R0, double Beta, unsigned samplingBitsNumber = 10, 
               double Vcc = 5, double T0 = 298.15);

    // Method to get the temperature
    // Parameters: adc (ADC numeric value), unit ('K', 'C', 'F' for Kelvin, Celsius, Fahrenheit)
    double getTemperature(double adc, char unit = 'K');
};

#endif // THERMISTOR_H
