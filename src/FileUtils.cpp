#include <iostream>
#include <fstream>
#include <sstream>
#include "FileUtils.h"

// Splits a string into tokens based on a delimiter character
std::vector<string> split(const string &s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

// Reads employee data from a CSV file and returns a vector of Employee objects
std::vector<Employee> readEmployeesFromFile(const std::string &filename) {
    std::vector<Employee> employees;
    std::ifstream file(filename);

    if (!file.is_open()) {
        throw std::runtime_error("Cannot open file: " + filename);
    }

    std::string line;
    int rowNumber = 1;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::vector<std::string> data;
        std::string field;

        while (std::getline(iss, field, ',')) {
            data.push_back(field);
        }

        employees.emplace_back(data, rowNumber);
        rowNumber++;
    }

    file.close();
    return employees;
}

// Outputs the sorted employee data to the console
void outputSortedEmployees(const vector<Employee> &employees) {
    for (const auto &employee: employees) {
        cout << employee.employeeID << ","
             << employee.lastName << ","
             << employee.firstName << ","
             << employee.streetAddress << ","
             << employee.city << ","
             << employee.province << ","
             << employee.postalCode << ","
             << employee.phoneNumber << ","
             << employee.gender << ","
             << employee.age << ","
             << employee.numDependents << ","
             << employee.departmentCategory << ","
             << employee.unionMember << ","
             << employee.hourlyRate << endl;
    }
}

// Writes the sorted employee data to a CSV file
void writeEmployeesToFile(const std::string &filename, const std::vector<Employee> &employees) {
    std::ofstream file(filename);

    if (!file.is_open()) {
        throw std::runtime_error("Cannot open file for writing: " + filename);
    }

    for (const auto &employee: employees) {
        file << employee.toString() << std::endl;
    }

    file.close();
}


