#include <vector>
#include "Employee.h"

using namespace std;

void merge(std::vector<Employee> &employees, int left, int middle, int right, int field);

void mergeSort(std::vector<Employee> &employees, int left, int right, int field);
