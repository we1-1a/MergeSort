#include "MergeSort.h"

//https://www.programiz.com/dsa/merge-sort
void merge(std::vector<Employee> &employees, int left, int middle, int right, int field) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Create temporary vectors
    std::vector<Employee> leftEmployees;
    std::vector<Employee> rightEmployees;

    // Copy employees to temporary vectors
    for (int i = 0; i < n1; ++i) {
        leftEmployees.push_back(employees[left + i]);
    }
    for (int i = 0; i < n2; ++i) {
        rightEmployees.push_back(employees[middle + 1 + i]);
    }

    int i = 0;
    int j = 0;
    int k = left;

    // Merge the temporary vectors back into the main vector
    while (i < n1 && j < n2) {
        if (leftEmployees[i].getField(field) <= rightEmployees[j].getField(field)) {
            employees[k] = leftEmployees[i];
            i++;
        } else {
            employees[k] = rightEmployees[j];
            j++;
        }
        k++;
    }

    // Copy remaining employees from leftEmployees, if any
    while (i < n1) {
        employees[k] = leftEmployees[i];
        i++;
        k++;
    }

    // Copy remaining employees from rightEmployees, if any
    while (j < n2) {
        employees[k] = rightEmployees[j];
        j++;
        k++;
    }
}


void mergeSort(std::vector<Employee> &employees, int left, int right, int field) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(employees, left, middle, field);
        mergeSort(employees, middle + 1, right, field);

        merge(employees, left, middle, right, field);
    }
}
