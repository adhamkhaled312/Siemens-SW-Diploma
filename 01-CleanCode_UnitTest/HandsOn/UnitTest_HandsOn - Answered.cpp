#include<iostream>
#include<vector>
#include <cassert>
using namespace std;

int get_closest_to_zero(vector<int>& nums) 
{
    int answer;
    if (nums.empty())
        return 0;
    
    
    answer = nums[0];
    for(size_t index=1; index< nums.size(); index++)
    {
        // checking if each value of nums is less than the max value
        if((abs(nums[index])) < (abs(answer)))
        {
            answer = nums[index];
        }
        else if(abs(nums[index]) == abs(answer))
        {
            answer = max (answer, nums[index]) ; // return the maximum in cases there are multiple answers
        }
    }
    return answer;
}

int main() {
    int answer;

    //single integer
    vector<int> identical {42};
    answer = closest_to_zero(identical);
    assert (answer == 42);
    
    //identical integers
    vector<int> identical2 {42, 42, 42, 42};
    answer = closest_to_zero(identical2);
    assert (answer == 42);
    
    //occurrence of zero
    vector<int> identical3 {42, -273 , 0, 23};
    answer = closest_to_zero(identical3);
    assert (answer == 0);

    //tie between positive and negative
    vector<int> identical5 {-20000, 20000};
    answer = closest_to_zero(identical5);
    assert (answer == 20000);

    //min positive number is closest to zero
    vector<int> identical6 {42, 1, 23, 97, 7};
    answer = closest_to_zero(identical6);
    assert (answer == 1);
    
    //empty vector
    vector<int> identical7 {};
    answer = closest_to_zero(identical7);
    assert (answer == 0);
    
}
