#include <iostream>
#include <string>
#include "MergeSort.h"
#include "FileUtils.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <field_number>" << endl;
        return 1;
    }

    int field = stoi(argv[1]);
    std::vector<Employee> employees = readEmployeesFromFile(
            "/Users/yitian/CLionProjects/assignment-4-we1-1a/docs/employee.csv");
    mergeSort(employees, 0, employees.size() - 1, field);
    outputSortedEmployees(employees);
    writeEmployeesToFile("/Users/yitian/CLionProjects/assignment-4-we1-1a/output/sorted_employees.csv", employees);

    return 0;
}
