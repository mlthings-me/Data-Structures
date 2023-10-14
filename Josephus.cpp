//{ Driver Code Starts
#include <iostream>
using namespace std;

// } Driver Code Ends
class Solution {
  public:

   void solve(vector<int>& arr, int k, int ind) {
        if (arr.size() == 1) {
            return;
        }
        
        ind = (ind + k - 1) % arr.size(); 
        arr.erase(arr.begin() + ind);
        solve(arr, k, ind);
    }

    int safePos(int n, int k) {
        vector<int> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back(i + 1);
        }
        solve(arr, k, 0);
        return arr[0];
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        
        cin>>n>>k;

        Solution ob;
        cout << ob.safePos(n,k) << endl;
    }
    return 0;
}
// } Driver Code Ends