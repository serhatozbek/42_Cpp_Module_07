#include <iostream>
#include <string>
#include <exception>
#include "Array.hpp"

int main(void)
{
    std::cout << "=== TEST 1: Default Constructor ===" << std::endl;
    Array<int> emptyArray;
    std::cout << "Empty array size: " << emptyArray.size() << std::endl;

    std::cout << "\n=== TEST 2: Parameterized Constructor & Default Initialization ===" << std::endl;
    Array<int> intArray(5);
    std::cout << "intArray size: " << intArray.size() << std::endl;
    std::cout << "Values (should be initialized to 0): ";
    for (unsigned int i = 0; i < intArray.size(); i++)
    {
        std::cout << intArray[i] << " ";
        intArray[i] = (i + 1) * 10;
    }
    std::cout << "\nValues after modification: ";
    for (unsigned int i = 0; i < intArray.size(); i++)
    {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "\n=== TEST 3: Deep Copy (Copy Constructor) ===" << std::endl;
    Array<int> copyArray(intArray);
    copyArray[0] = 999;
    std::cout << "intArray[0] (Original) : " << intArray[0] << " (Should be 10)" << std::endl;
    std::cout << "copyArray[0] (Copy)    : " << copyArray[0] << " (Should be 999)" << std::endl;

    std::cout << "\n=== TEST 4: Deep Copy (Assignment Operator) ===" << std::endl;
    Array<int> assignedArray;
    assignedArray = intArray;
    assignedArray[1] = 888;
    std::cout << "intArray[1] (Original) : " << intArray[1] << " (Should be 20)" << std::endl;
    std::cout << "assignedArray[1] (Copy): " << assignedArray[1] << " (Should be 888)" << std::endl;

    std::cout << "\n=== TEST 5: Out of Bounds Exception ===" << std::endl;
    try
    {
        std::cout << "Trying to access index 5 (size is 5, max index is 4)..." << std::endl;
        std::cout << intArray[5] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << "Trying to access index -1..." << std::endl;
        std::cout << intArray[-1] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "\n=== TEST 6: Template with Complex Types (std::string) ===" << std::endl;
    Array<std::string> strArray(3);
    strArray[0] = "Hello";
    strArray[1] = "42";
    strArray[2] = "School";
    for (unsigned int i = 0; i < strArray.size(); i++)
    {
        std::cout << strArray[i] << " ";
    }
    std::cout << "\n\nAll tests completed successfully!" << std::endl;

    return 0;
}