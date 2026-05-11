#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> seperateDigits(vector<int>& nums){
        vector<int> res;
        for(auto x : nums){
            vector<int> temp;
            while(x>0){
                temp.push_back(x%10);
                x /= 10;
            }
            for(int i=temp.size()-1; i>=0; i--){
                res.push_back(temp[i]);
            }
        }
        return res;
    }
};

int main(void){
    Solution sol;
    vector<int> nums = {13, 25, 83, 77};
    vector<int> result = sol.seperateDigits(nums);
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << (i == result.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl;
    return 0;
}
