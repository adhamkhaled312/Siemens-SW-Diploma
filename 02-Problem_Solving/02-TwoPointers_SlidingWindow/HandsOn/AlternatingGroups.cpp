//https://leetcode.com/problems/alternating-groups-i/description/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int left=0;
        int right=2;
        int count=0;
        int size=colors.size(); 
        while(left<size){
            if(colors[(left+1)%size]!=colors[left] && colors[(left+1)%size]!=colors[right] ){
                count++;
            }
            left++;
            right=(right+1)%size;
        }
    return count;
    }
    
};
int main(){}