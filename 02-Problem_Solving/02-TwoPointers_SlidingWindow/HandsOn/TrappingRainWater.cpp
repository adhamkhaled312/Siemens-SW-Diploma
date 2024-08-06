// https://leetcode.com/problems/trapping-rain-water/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int res=0;
        int maxLeft=height[0];
        int maxRight=height[height.size()-1];
        int left=1;
        int right=height.size()-2;
        while(right>left){
            if(maxLeft<maxRight){
                res+=max(maxLeft-height[left],0);
                maxLeft=max(maxLeft,height[left]);
                left++;
            }
            else{
                res+=max(maxRight-height[right],0);
                maxRight=max(maxRight,height[right]);
                right--;
            }
        }   
    return res;
    }
};