/*
 *在字符串中找出第一个只出现一次的字符
 */
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        int length = str.size();
        if(length<=0)
            return -1;
        vector<int>ascii(256,0);
        for(int i=0;i<length;i++)
            ascii[str[i]]++;
        
        for(int i=0;i<length;i++){
            if(ascii[str[i]] == 1)
                return i;
        }
        return -1;
    }
};
