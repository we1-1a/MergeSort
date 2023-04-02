#include "Employee.h"
#include <stdexcept>
#include <sstream>

std::string Employee::toString() const {
    std::stringstream ss;

    ss << employeeID << ',' << lastName << ',' << firstName << ','
       << streetAddress << ',' << city << ',' << province << ','
       << postalCode << ',' << phoneNumber << ',' << gender << ','
       << age << ',' << numDependents << ',' << departmentCategory << ','
       << unionMember << ',' << hourlyRate;

    return ss.str();
}


Employee::Employee(std::vector<std::string> &data, int rowNumber) {
    if (data.size() != 14) {
        throw std::runtime_error("Invalid data format for Employee at row " + std::to_string(rowNumber));
    }

    employeeID = data[0];
    lastName = data[1];
    firstName = data[2];
    streetAddress = data[3];
    city = data[4];
    province = data[5];
    postalCode = data[6];
    phoneNumber = data[7];
    gender = data[8];
    age = std::stoi(data[9]);
    numDependents = std::stoi(data[10]);
    departmentCategory = data[11];
    unionMember = data[12];
    hourlyRate = std::stod(data[13]);
}

std::string Employee::getField(int field) const {
    switch (field) {
        case 0:
            return employeeID;
        case 1:
            return lastName;
        case 2:
            return firstName;
        case 3:
            return streetAddress;
        case 4:
            return city;
        case 5:
            return province;
        case 6:
            return postalCode;
        case 7:
            return phoneNumber;
        case 8:
            return gender;
        case 9:
            return std::to_string(age);
        case 10:
            return std::to_string(numDependents);
        case 11:
            return departmentCategory;
        case 12:
            return unionMember;
        case 13:
            return std::to_string(hourlyRate);
        default:
            throw std::runtime_error("Invalid field number for Employee");
    }
}
