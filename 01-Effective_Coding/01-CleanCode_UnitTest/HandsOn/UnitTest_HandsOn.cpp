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
    // #TODO Write unit testing code here
    return 1;
}

