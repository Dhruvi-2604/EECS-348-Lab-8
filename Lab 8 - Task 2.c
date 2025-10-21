/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

// Function prototypes
double convertTemperature(double temp, char from, char to);
void categorizeTemperature(double tempCelsius);

int main() {
    double temp, converted;
    char fromScale, toScale;

    while (1) {
        printf("Enter the temperature value (or -999 to quit): ");
        scanf("%lf", &temp);
        if (temp == -999)
            break;

        printf("Enter the original scale (C, F, or K): ");
        scanf(" %c", &fromScale);

        printf("Enter the scale to convert to (C, F, or K): ");
        scanf(" %c", &toScale);

        // Perform conversion
        converted = convertTemperature(temp, fromScale, toScale);
        if (converted == -1) {
            printf("Invalid temperature scale entered.\n");
            continue;
        }

        printf("Converted temperature: %.2f %c\n", converted, toScale);

        // Categorize temperature based on converted value in Celsius
        double tempInC = convertTemperature(converted, toScale, 'C');
        categorizeTemperature(tempInC);
        printf("\n");
    }

    printf("Program terminated.\n");
    return 0;
}

// Function to convert temperature between scales
double convertTemperature(double temp, char from, char to) {
    double result;

    // Convert input scale to Celsius first
    if (from == 'C' || from == 'c') {
        result = temp;
    } else if (from == 'F' || from == 'f') {
        result = (temp - 32) * 5 / 9;
    } else if (from == 'K' || from == 'k') {
        result = temp - 273.15;
    } else {
        return -1;  // invalid input
    }

    // Convert from Celsius to target scale
    if (to == 'C' || to == 'c') {
        return result;
    } else if (to == 'F' || to == 'f') {
        return (result * 9 / 5) + 32;
    } else if (to == 'K' || to == 'k') {
        return result + 273.15;
    } else {
        return -1;  // invalid target
    }
}

// Function to categorize and advise based on Celsius temperature
void categorizeTemperature(double tempCelsius) {
    if (tempCelsius < 0) {
        printf("Temperature category: Freezing\n");
        printf("Weather advisory: Stay warm and avoid prolonged outdoor exposure.\n");
    } else if (tempCelsius < 10) {
        printf("Temperature category: Cold\n");
        printf("Weather advisory: Wear a jacket.\n");
    } else if (tempCelsius < 25) {
        printf("Temperature category: Comfortable\n");
        printf("Weather advisory: Enjoy your day!\n");
    } else if (tempCelsius < 35) {
        printf("Temperature category: Hot\n");
        printf("Weather advisory: Drink lots of water!\n");
    } else {
        printf("Temperature category: Extreme Heat\n");
        printf("Weather advisory: Stay indoors and stay hydrated.\n");
    }
}
