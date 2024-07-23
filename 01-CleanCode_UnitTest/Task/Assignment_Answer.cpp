#include <iostream>
#include <cassert>
#include <string>

// This string is used for testing only
std::string lastError;

// Function to calculate the sum of numbers in array from startIndex to endIndex
int calculateSum(int array[], int startIndex, int endIndex, int arraySize)
{
    int sum = 0;
    // This line is for testing only, remove it when finishing
    lastError.clear();
    try
    {
        if (endIndex >= arraySize)
        {
            throw std::runtime_error("The end index is greater than size of the array!");
        }
        if (startIndex >= arraySize)
        {
            throw std::runtime_error("The start index is greater than size of the array!");
        }
        if (startIndex > endIndex)
        {
            throw std::runtime_error("The start index is greater than end index!");
        }

        for (int index = startIndex; index <= endIndex; index++)
        {
            sum += array[index];
        }
    }
    catch (const std::exception &error)
    {
        // This line is for testing only, remove it when finishing
        lastError = error.what();

        // uncomment the next 2 lines when finish testing
        // std::cerr << error.what() << std::endl;
        // exit(0);
    }

    return sum;
}

void testCalculateSum()
{
    int array[] = {16, 31, 87, 53, 39, 37, 72, 23, 80, 54};
    int arraySize = sizeof(array) / sizeof(int);
    int result;

    // sum of all elements
    result = calculateSum(array, 0, arraySize-1, arraySize);
    assert(result == 492);

    // sum of elements from 3 to 7
    result = calculateSum(array, 3, 7, arraySize);
    assert(result == 224);

    // sum of elements from 1 to 8
    result = calculateSum(array, 1, 8, arraySize);
    assert(result == 422);

    // sum of single element
    result = calculateSum(array, 4, 4, arraySize);
    assert(result == 39);

    // sum of first element
    result = calculateSum(array, 0, 0, arraySize);
    assert(result == 16);

    // sum of last elements
    result = calculateSum(array, 9, 9, arraySize);
    assert(result == 54);

    // test exception handling
    // test startIndex greater than endIndex
    calculateSum(array, 7, 3, arraySize);
    assert(lastError == "The start index is greater than end index!");

    // test startIndex greater than size of array
    calculateSum(array, arraySize + 2, 3, arraySize);
    assert(lastError == "The start index is greater than size of the array!");

    // test endIndex greater than size of array
    calculateSum(array, 2, arraySize + 5, arraySize);
    assert(lastError == "The end index is greater than size of the array!");
}

int main()
{
    testCalculateSum();
    std::cout << "Succefully passed all tests!\n";

    return 1;
}
