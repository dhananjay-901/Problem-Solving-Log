#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
    public:
        string longestCommonPrefix(vector<string>& v){
            string result = "";
            sort(v.begin(), v.end());
            int n = v.size();
            string first = v[0];
            string last = v[n-1];
            for(int i=0;i<min(first.size(), last.size());i++){
                if(first[i]!=last[i]){
                    return result;
                }
                result += first[i];
            }
            return result;
        }
};

int main(void){
    vector<string> strs = {"flower", "flow","flight"};
    Solution s;
    string result = s.longestCommonPrefix(strs);
    cout << result << endl;
    return 0;
}
