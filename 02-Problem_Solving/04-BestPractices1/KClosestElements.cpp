//https://leetcode.com/problems/find-k-closest-elements/description/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int left = 0;
    int right = arr.size() - 1;

    while (right - left >= k) {
        if (abs(arr[left] - x) > abs(arr[right] - x)) {
            left++;
        } else {
            right--;
        }
    }
    return vector<int>(arr.begin() + left, arr.begin() + right + 1);
    }
};