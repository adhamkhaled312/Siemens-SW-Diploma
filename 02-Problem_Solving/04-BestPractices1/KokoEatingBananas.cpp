//https://leetcode.com/problems/koko-eating-bananas/
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int right=*max_element(piles.begin(),piles.end());
        int left=1;
        int mid;
        long long int temp;
        int ret;
        while(left<=right){
            temp=0;
            mid=left+(right-left)/2;

            for(int i=0;i<piles.size();i++){
                temp+=ceil(double(piles[i])/mid);
            }
            if(temp>h){
                left=mid+1;
            }
            else{
                ret=mid;
                right=mid-1;
            }
        }
        return ret;
    }
};