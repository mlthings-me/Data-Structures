// You are given a sorted unique integer array nums.

// A range [a,b] is the set of all integers from a to b (inclusive).

// Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.

// Each range [a,b] in the list should be output as:

// "a->b" if a != b
// "a" if a == b
#include <iostream>
#include <vector>
//#include<bits/stdc++.h>
#include <string>
using namespace std;

vector<string> summaryRanges(vector<int>& nums) {
    vector<string> res;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        int start = nums[i];
        while (i < n - 1 && nums[i + 1] - nums[i] == 1) {
            i++;
        }
        int end = nums[i];
        if (start == end) {
            res.push_back(to_string(start));
        } else {
            res.push_back(to_string(start) + "->" + to_string(end));
        }
    }
    return res;
}

int main() {
    vector<int> nums;
    nums = {0, 1, 2, 4, 5, 7};
    vector<string> res = summaryRanges(nums);
    for (string s : res) {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}