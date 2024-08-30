//https://leetcode.com/problems/next-greater-element-i/description/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        if(nums2.size()==1){
            ans.push_back(-1);
            return ans;
        }
        stack<int>st;
        map<int,int>mp;
        st.push(nums2[0]);
        for(int i=1;i<nums2.size();i++){
            if( !st.empty() && nums2[i] > st.top()){
            while( !st.empty() && nums2[i] > st.top()){
                    mp[st.top()]=nums2[i];
                    st.pop();
                }     
            }
            st.push(nums2[i]);
  
        } 
        while(!st.empty()){
            mp[st.top()]=-1;
            st.pop();
        }
        for(auto x : nums1){
            ans.push_back(mp[x]);
        }  
        return ans;
    }
};