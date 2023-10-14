#include<iostream>
#include<vector> 
using namespace std; 
class Solution
{
public:
    void solve(vector<int> op, vector<int> ip, vector<vector<int>>& ans)
    {
        if (ip.size() == 0)
        {
            ans.push_back(op);
            return;
        }
        vector<int> op1 = op;
        vector<int> op2 = op;
        op1.push_back(ip[0]);
        ip.erase(ip.begin());
        solve(op1, ip, ans);
        solve(op2, ip, ans);
        return;
    }

    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<vector<int>> ans;
        vector<int> op;
        solve(op, arr, ans);
        
        vector<int> res;
        for (int i = 0; i < ans.size(); i++)
        {
            int sum = 0;
            for (int j = 0; j < ans[i].size(); j++) // Fix the loop variable j instead of i
            {
                sum += ans[i][j];
            }
            res.push_back(sum);
        }
        return res;
    }
};

int main()
{
    int arr[] = {2, 3, 5};
    int N = sizeof(arr) / sizeof(arr[0]);
    vector<int> arrVec(arr, arr + N);

    Solution obj;
    vector<int> ans = obj.subsetSums(arrVec, N);

    sort(ans.begin(),ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
