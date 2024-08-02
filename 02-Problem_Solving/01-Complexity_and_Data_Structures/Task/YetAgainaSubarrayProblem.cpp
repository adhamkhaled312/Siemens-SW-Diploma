// Problem link: https://www.codechef.com/LRNDSA03/problems/SUBPRNJL?tab=statement
// Submission link: https://www.codechef.com/viewsolution/1076822112
#include <bits/stdc++.h> 

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            map<int, int> ms;
            for (int j = i, s = 1; j < n; ++j, ++s) {
                ms[v[j]]++;
                int m = ceil(k / float(s));
                int offset = (m * s - k) / m;

                int F;
                if (offset < s - offset) {
                    auto it = ms.rbegin();
                    while (offset >= it->second) {
                        offset -= it->second;
                        ++it;
                    }
                    F = it->second;
                } else {
                    offset = s - offset - 1;
                    auto it = ms.begin();
                    while (offset >= it->second) {
                        offset -= it->second;
                        ++it;
                    }
                    F = it->second;
                }

                if (ms.count(F)) {
                    ans++;
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}