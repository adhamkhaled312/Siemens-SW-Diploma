//https://leetcode.com/problems/sqrtx/
class Solution {
public:
    int mySqrt(int x) {
        int left=1;
        int right=x/2;
        int res;
        if(x==1 || x==0){
            return x;
        }
        while(left <= right){
            int mid=left+(right-left)/2;
            if(mid==x/mid){
                res=mid;
                break;
            }
            else if(mid > x/mid){
                right=mid-1;
            }
            else{
                left=mid+1;
                res=mid;
            }
        }
        return res;
    }
};