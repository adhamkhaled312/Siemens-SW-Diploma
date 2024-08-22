//https://www.hackerrank.com/challenges/password-cracker/problem
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'passwordCracker' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING_ARRAY passwords
 *  2. STRING loginAttempt
 */


bool backtrack(const vector<string>& passwords, const string& loginAttempt,vector<string>& result,unordered_map<string,vector<string>>& memo){
    if(loginAttempt.empty()){
        return true;
    }
    if(memo.find(loginAttempt)!=memo.end()){
        return !memo[loginAttempt].empty();
    }
    for(const string& pass: passwords){
        if(loginAttempt.find(pass)==0){
            result.push_back(pass);
            if(backtrack(passwords,loginAttempt.substr(pass.size()),result,memo)){
                memo[loginAttempt]=result;
                return true;
            }
            result.pop_back();
        }
    }
    memo[loginAttempt]={};
    return false;
}
string passwordCracker(vector<string> passwords, string loginAttempt) {
    vector<string>result;
    string ret;
    unordered_map<string,vector<string>>memo;
    if(backtrack(passwords,loginAttempt,result,memo)){
        for(const string & pass :result){
            ret+=pass+" ";
        }
        ret.pop_back();
    }
    else{
        ret="WRONG PASSWORD";
    }
    return ret;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string passwords_temp_temp;
        getline(cin, passwords_temp_temp);

        vector<string> passwords_temp = split(rtrim(passwords_temp_temp));

        vector<string> passwords(n);

        for (int i = 0; i < n; i++) {
            string passwords_item = passwords_temp[i];

            passwords[i] = passwords_item;
        }

        string loginAttempt;
        getline(cin, loginAttempt);

        string result = passwordCracker(passwords, loginAttempt);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
