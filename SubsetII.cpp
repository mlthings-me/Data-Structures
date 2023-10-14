#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    void solve(vector<int> ip, vector<int> op, set<vector<int>>& ans) {
        if (ip.size() == 0) {
            sort(op.begin(), op.end());
            ans.insert(op);
            return;
        }

        vector<int> op1 = op;
        vector<int> op2 = op;
        op1.push_back(ip[0]);
        ip.erase(ip.begin());
        solve(ip, op1, ans);
        solve(ip, op2, ans);
        return;
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> op;
        set<vector<int>> s;
        vector<vector<int>> ans;
        solve(nums, op, s);
        for (auto i : s) {
            ans.push_back(i);
        }
        return ans;
    }
};
int main()
{
    int arr[] = {2, 3, 5, 3};
    int N = sizeof(arr) / sizeof(arr[0]);
    vector<int> arrVec(arr, arr + N);

    Solution obj;
    vector<vector<int>> ans = obj.subsetsWithDup(arrVec);

    sort(ans.begin(),ans.end());
    for (int i = 0; i < ans.size(); i++)
    {   
        // cout<<"[";
        for(int j = 0; j < ans[i].size(); j++){
        cout <<ans[i][j] << " ";}
        cout<<endl;
    }
    
}