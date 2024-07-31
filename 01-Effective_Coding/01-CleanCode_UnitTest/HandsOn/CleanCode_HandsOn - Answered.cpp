#include <iostream>  
using namespace std; 
// Use meaningful function names  
int divideFirstBySecond(int firstNumber, int secondNumber) {
    int result;
    try {  
        if (secondNumber == 0) {  
            throw std::runtime_error("Division by zero is not allowed!");  
        }  
        result = firstNumber / secondNumber;  
    } 
    catch (const std::exception& error) {  
        std::cerr << "Error: " << error.what() << std::endl;  
        exit(0);
    } 
  return result;   
}  
  
// Use descriptive function names and comments to explain functionality  
void printResult(int firstNumber, int secondNumber, int result) {  
    cout << "The division of " << firstNumber << " over " << secondNumber << " is " << result << endl;  
}  
  
int main() {  
    int firstNumber = 10;  
    int secondNumber = 0;  
  
    // Use meaningful variable names  
    int result = divideFirstBySecond(firstNumber, secondNumber);  
  
    printResult(firstNumber, secondNumber, result);  
  
    return 0;  
} 