// File: JsonParser.cpp
#include "JsonParser.h"
#include <nlohmann/json.hpp>
#include <iostream>

using json = nlohmann::json;

void displayWeatherData(const std::string& jsonData) {
    try {
        auto data = json::parse(jsonData);

        // Extract the necessary fields from the JSON data
        std::string location = data["location"]["name"];
        std::string country = data["location"]["country"];
        std::string temperature = data["current"]["temperature"].dump();
        std::string weatherDescription = data["current"]["weather_descriptions"][0];

        // Display the weather information
        std::cout << "Location: " << location << ", " << country << std::endl;
        std::cout << "Temperature: " << temperature << "°C" << std::endl;
        std::cout << "Weather: " << weatherDescription << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error parsing JSON data: " << e.what() << std::endl;
    }
}
