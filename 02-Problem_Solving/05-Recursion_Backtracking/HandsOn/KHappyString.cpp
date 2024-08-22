//https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/
class Solution {
public:
    bool getKHappyString(string& happy, const int& n, const int& k, int& idx) {
        static vector<char> happyChars {'a', 'b', 'c'};
        if (happy.size() == n) {
            if (idx == k) {
                return true;
            }
            idx++;
            return false;
        }
        for (char& ch : happyChars) {
            if (happy.empty() || happy.back() != ch) {
                happy += ch;
                if (getKHappyString(happy, n, k, idx)) {
                    return true;
                }
                happy.pop_back();
            }
        }
        return false;
    }

    string getHappyString(int n, int k) {
        string happy = "";
        int idx = 1;
        if (!getKHappyString(happy, n, k, idx)) {
            return "";
        }
        return happy;
    }
};
