// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
#include <algorithm>
#include <vector>
class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int retResult=0;
        int buy=prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i]<buy){
                buy=prices[i];
            }else{
                retResult=std::max(retResult,prices[i]-buy);
            }
        }
    return retResult;
    }
};
