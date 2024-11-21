#include <Arduino.h>
#include "../../includes/Thermistor.h"

// Initialization of thermistor parameters
double Rref = 1000;        // Reference resistance at T0 (in ohms)
double R0 = 1500;          // Fixed resistance in the voltage divider (in ohms)
double Beta = 3275;        // Beta coefficient
unsigned samplingBits = 10; // ADC resolution in bits
double Vcc = 5.0;          // Supply voltage (in volts)
double T0 = 298.15;        // Reference temperature in Kelvin (25°C)

// Create the Thermistor object
Thermistor thermistor(Rref, R0, Beta, samplingBits, Vcc, T0);

void setup() {
    // Initialize the serial port
    Serial.begin(9600);
    Serial.println("Thermistor Temperature Measurement");
}

void loop() {
    // Read the ADC value from pin A0
    int adcValue = analogRead(A0);

    // Convert the ADC value to temperature
    double temperatureCelsius = thermistor.getTemperature(static_cast<double>(adcValue), 'C');

    // Display the temperature in °C
    Serial.print("Measured temperature: ");
    Serial.print(temperatureCelsius);
    Serial.println(" °C");

    // Wait for 5 seconds before taking another measurement
    delay(5000);
}
