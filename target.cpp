#include <iostream>
#include <vector>
using namespace std;

class Solution{
  public:
    vector<int> twoSum(vector<int>& nums, int target){
        vector<int> res;
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                if(nums[i] + nums[j] == target){
                    res.push_back(i);
                    res.push_back(j);
                }else{
                    continue;
                }
            }
        }
        return res;
    }
};

int main(void){
    Solution sol;
    vector<int> nums = {13, 25, 83, 77};
    int target = 38;
    vector<int> result = sol.twoSum(nums, target);
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << (i == result.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl;
    return 0;
}
