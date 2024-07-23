#include <iostream>
#include <cassert>

using namespace std;

/*
    You need to refactor the following function using clean code guidelines
        - Meaningful names
        - Functions
        - Comments
        - Formatting
        - Error Handling
    After finishing, you are requested to write unite tests below in the main code for the function.
*/

int sum (int arr[], int s, int e, int n) {  
    int x = 0;  
    for (int i = s; i < e; i++) {  
        x+=arr[i];
    }
    return x;  
}

int main () {
    //#TODO Write the unit testing assertions here
    return 1;
}
