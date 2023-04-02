#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <vector>

class Employee {
public:
    std::string employeeID;
    std::string lastName;
    std::string firstName;
    std::string streetAddress;
    std::string city;
    std::string province;
    std::string postalCode;
    std::string phoneNumber;
    std::string gender;
    int age;
    int numDependents;
    std::string departmentCategory;
    std::string unionMember;
    double hourlyRate;

    std::string toString() const;

    Employee(std::vector<std::string> &data, int rowNumber);

    std::string getField(int field) const;
};

#endif // EMPLOYEE_H
