// Copyright (c) 2021 Felipe Affonso All rights reserved
//
// Created by: Felipe Affonso
// Created on: May 2021
// This program formats an adress in the standart form

#include <iostream>
#include <cmath>
#include <iomanip>
#include <random>
#include <string>
#include <cstring>
#include <locale>

std::string adressConverter(std::string name, std::string streetNumber,
    std::string streetName, std::string city, std::string province,
    std::string postalCode, std::string apartmentNumber = "") {
    // this function formats an adress in the standart form
    std::string adress;
    std::string adressUpper;
    std::locale loc;

    if (apartmentNumber != "") {
        adress = name + "\n" + apartmentNumber + "-" + streetNumber + " " +
            streetName + "\n" + city + " " + province + "  " + postalCode;
    } else {
        adress = name + "\n" + streetNumber + " " + streetName + "\n" + city +
            " " + province + "  " + postalCode;
    }

    int adressLength = adress.length();

    char char_array[adressLength + 1];
    strcpy(char_array, adress.c_str());

    for (int counter = 0; counter < adressLength; counter++) {
        adressUpper += std::toupper(char_array[counter], loc);
    }

    return adressUpper;
}


int main() {
    // This is the main function
    std::string name;
    char nameChar[25];
    std::string apartment;
    std::string apartmentUpper;
    std::string apartmentNumber;
    std::string streetNumber;
    std::string streetName;
    char streetChar[30];
    std::string city;
    std::string province;
    std::string postalCode;
    char postalCodeChar[7];
    std::string adress;
    try {
        std::cout <<
        "This program formats your address as a mailing address.\n"
        << std::endl;

        std::cout << "Insert your full name: ";
        std::cin.getline(nameChar, 25);
        name = nameChar;

        std::cout << "Do you live in an apartment?(Y/n): ";
        std::cin >> apartment;

        apartmentUpper += std::toupper(apartment[0]);

        if (apartmentUpper == "Y") {
            std::cout << "Insert your apartment number: ";
            std::cin >> apartmentNumber;
        }

        std::cout << "Insert your street number: ";
        std::cin >> streetNumber;

        std::cout << "Insert your street name: ";
        std::cin.getline(streetChar, 30);
        streetName = streetChar;

        std::cout << "Insert your city: ";
        std::cin >> city;

        std::cout << "Insert your province(as an abbreviation): ";
        std::cin >> province;

        std::cout << "Insert your postal code(123 456): ";
        std::cin.getline(postalCodeChar, 7);
        postalCode = postalCodeChar;

        if (apartmentUpper == "Y") {
            adress = adressConverter(name, streetNumber, streetName, city,
                province, postalCode, apartmentNumber);
        } else {
            adress = adressConverter(name, streetNumber, streetName, city,
                province, postalCode);
        }

        std::cout << "\n" << adress << std::endl;
    } catch (std::invalid_argument) {
        std::cout <<
        "\nThis input is invalid, try again."
        << std::endl;
    }

    std::cout << "\nDone." << std::endl;
}
