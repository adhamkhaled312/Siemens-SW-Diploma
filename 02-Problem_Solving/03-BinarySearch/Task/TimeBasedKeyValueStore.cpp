//https://leetcode.com/problems/time-based-key-value-store/
class TimeMap {
public:
    unordered_map<string,vector<pair<string,int>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key)==mp.end()){
            return "";
        }
        
        int left=0;
        int right=mp[key].size()-1;
        int bestTimestamp=INT_MIN;
        while(left <=right){
            int mid=left+(right-left)/2;
            if(mp[key][mid].second==timestamp){
                return mp[key][mid].first;
            }
            else if(mp[key][mid].second > timestamp){
                right=mid-1;
            }
            else{
                bestTimestamp=max(bestTimestamp,mid);
                left=mid+1;
            }
        }
        return bestTimestamp==INT_MIN ? "" : mp[key][bestTimestamp].first;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */