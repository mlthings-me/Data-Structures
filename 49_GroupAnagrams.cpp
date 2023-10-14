#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
 vector<vector<string>> groupAnagrams(vector<string>& strs) {       
        vector<vector<string>> result;
        unordered_map<string, vector<string>> map1;
        for(auto i: strs){
            string sortedStr(i.begin(), i.end());
            sort(sortedStr.begin(), sortedStr.end());
            map1[sortedStr].push_back(i);
        }
        for(auto i: map1){
            result.push_back(i.second);
        }
        return result;
    }
int main(){
vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = groupAnagrams(strs);

    // Print the result
    for (const auto& group : result) {
        for (const string& word : group) {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;}