#include "../includes/Thermistor.h"
#include <math.h> // To use log and exp

// Constructor
Thermistor::Thermistor(double Rref, double R0, double Beta, unsigned samplingBitsNumber, double Vcc, double T0)
    : Rref(Rref), R0(R0), Beta(Beta), samplingBitsNumber(samplingBitsNumber), Vcc(Vcc), T0(T0) {}

// Method to get the temperature
double Thermistor::getTemperature(double adc, char unit) {
    // Convert ADC value to voltage
    double Vout = (adc / (pow(2, samplingBitsNumber) - 1)) * Vcc;

    // Calculate the measured resistance (voltage divider)
    double Rt = R0 * (Vcc / Vout - 1);

    // Calculate the temperature in Kelvin
    double temperatureKelvin = 1 / (1 / T0 + (1 / Beta) * log(Rt / Rref));

    // Convert to the requested unit
    switch (unit) {
        case 'C': // Celsius
            return temperatureKelvin - ZERO_CELSIUS;
        case 'F': // Fahrenheit
            return (temperatureKelvin - ZERO_CELSIUS) * 9 / 5 + 32;
        case 'K': // Kelvin
        default:
            return temperatureKelvin;
    }
}
