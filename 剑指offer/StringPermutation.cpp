#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> result;
        if(str.length()==0)
            return result;
        int length = str.length();
        Permutation(str, result, 0, length);
        sort(result.begin(),result.end());
        return result;
    }
    
    void Permutation(string &str, vector<string> &result, int begin, int length){
        if(begin >= length)
        {
            result.push_back(str);
            return;
        }

        for(int i=begin;i<length;i++){
            //去重条件
            if(str[i] == str[begin] && i!=begin)
                continue;
            char tmp = str[begin];
            str[begin] = str[i];
            str[i] = tmp;
            Permutation(str, result, begin+1, length);
            tmp = str[begin];
            str[begin] = str[i];
            str[i] = tmp;
        }
    }
};

int main()
{
    Solution mysol = Solution();
    string str = "abc";
    vector<string> result = mysol.Permutation(str);
    int length = result.size();
    for(int i=0;i<length;i++){
        cout<<result[i]<<"  ";
    }    
    return 0;
}
