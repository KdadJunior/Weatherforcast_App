// File: main.cpp
#include <iostream>
#include <string>
#include <algorithm>
#include "WeatherApi.h"  // Include the header for your Weather API logic
#include "JsonParser.h"  // Include the header for your JSON parsing logic

int main() {
    std::string city;
    std::cout << "Enter the city name: ";
    std::getline(std::cin, city);

    // Replace spaces with %20 for URL encoding
    size_t pos = city.find(" ");
    while (pos != std::string::npos) {
        city.replace(pos, 1, "%20");
        pos = city.find(" ", pos + 3);
    }

    // Get weather data in JSON format
    std::string jsonData = getWeatherData(city);

    if (!jsonData.empty()) {
        // Parse JSON and display the relevant data
        displayWeatherData(jsonData);
    }
    else {
        std::cerr << "Failed to retrieve weather data." << std::endl;
    }

    return 0;
}
