#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool check(string &np, string &op){
    vector<int> next(26,0);
    for (int i=0;i<25;i++){
        next[i]=i+1;
    }
    next[25]=0;
    int nps = np.size(), ops=op.size();
    int i=0,j=0;
    while (i<nps && j<ops){
        if (op[j]==(char)(next[np[i]-'a']+'a') || op[j]==np[i]){
            j++;
        }
        i++;
    }
    return (j==ops);
}

vector<string> checkSimilarPasswords(vector<string> newPasswords, vector<string> oldPasswords) {
    vector<string> res(oldPasswords.size());
    for (int i=0;i<oldPasswords.size();i++){
        if (check(newPasswords[i], oldPasswords[i])) 
            res[i] = "YES";
        else 
            res[i] = "NO";
    }
    return res;
}

int main() {
    vector<string> newPasswords = {"bd", "a9", "zx"};
    vector<string> oldPasswords = {"abcde", "123456789", "xyz"};
    vector<string> results = checkSimilarPasswords(newPasswords, oldPasswords);
    
    for (const string& result : results) {
        cout << result << " ";
    }
    
    return 0;
}
