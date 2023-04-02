#include <vector>
#include <string>
#include "Employee.h"

using namespace std;

std::vector<std::string> split(const std::string &s, char delimiter);

std::vector<Employee> readEmployeesFromFile(const std::string &filename);

void outputSortedEmployees(const std::vector<Employee> &employees);

void writeEmployeesToFile(const std::string &filename, const std::vector<Employee> &employees);
