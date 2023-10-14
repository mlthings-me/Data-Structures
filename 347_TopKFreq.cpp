#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    vector<int> result;
    int count= 0;
    for(int i= 0 ; i< 10; i++){
        m[i]=0;
    }
    for(auto i: nums){
        m[i]+=1;
    }
    vector<pair<int, int>> hello;
    for (const auto& i : m) {
        hello.push_back({i.first, i.second});
    }
    sort(hello.begin(), hello.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });
    for(int i = hello.size()-1; i>hello.size()-k-1; i--){
    result.push_back(hello[i].first);
    }
    return result;
}
};
int main(){
vector<int>& nums={1,1,1,2,2,3};
}