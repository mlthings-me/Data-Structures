#include<iostream>
#include<vector>
using namespace std;
int main()
{
}
    vector<vector<int>> f(int ind, vector<int> arr, vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        
        // Base case: if ind exceeds or equals the size of nums
        if (ind >= n) {
            ans.push_back(arr);
            return ans;
        }
        
        arr.push_back(nums[ind]);
        // Recursively generate subsets including nums[ind]
        vector<vector<int>> subsetsWithNum = f(ind + 1, arr, nums);
        ans.insert(ans.end(), subsetsWithNum.begin(), subsetsWithNum.end());
        
        arr.pop_back();
        // Recursively generate subsets excluding nums[ind]
        vector<vector<int>> subsetsWithoutNum = f(ind + 1, arr, nums);
        ans.insert(ans.end(), subsetsWithoutNum.begin(), subsetsWithoutNum.end());
        
        return ans;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> a;
        return f(0, a, nums);
    }


