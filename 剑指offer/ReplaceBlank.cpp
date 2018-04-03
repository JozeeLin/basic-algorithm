/*
 * 题目：请实现一个函数，把字符串中的每个空格替换成"%20".
 * 思路：
 * 方案1：对字符串进行遍历，统计空格数，算出替换空格之后的字符串长度，然后申请一段长度等于新字符串长度的空间。然后再一次遍历原始字符串，把非空格符直接复制到新空间中，把空格符替换为"%20"存储到新空间中。时间复杂度为O(N),空间复杂度为O(N)
 * 方案2：原字符串有足够的空间存放替换空格后的新字符串。先对字符串进行遍历获取新字符串的长度，创建两个索引变量，p1变量指向新字符串的尾部，p2变量指向旧字符串的尾部。当p2变量指向的元素为非空格字符，直接复制到p1所指向的空间，然后同时移动p1，p2。当p2变量指向的元素为空格符，p1变量指向的空间一次写入”02%“，这三个字符之后，p2自己向前移动一次。时间复杂度为O(N),空间复杂度为O(1).
 */

#include <iostream>
using namespace std;

void ReplaceBlank(char str[], int length)
{
    cout<<"befor: "<<str<<endl;
    int BlankNum = 0;
    int NewLength = 0;
    int RealLength = 0;
    int i = 0;
    
    if(str==NULL){
        cout<<"Invalid Input: str is NULL!"<<endl;
        return;
    }

    while(str[i] != '\0'){
        RealLength++;
        if(str[i] == ' ')
            BlankNum++;
        ++i;
    }
    NewLength = RealLength+2*BlankNum;
    if(NewLength >= length)
    {
        cout<<"Invalid Input: length is too small!"<<endl;
        return;
    }
    //注意边界条件'\0',需要把结束符也复制过去
    int p1 = NewLength;
    int p2 = RealLength;

    while(p2>=0 && p1>=p2){
        if(str[p2]==' '){
            str[p1--]='0';
            str[p1--]='2';
            str[p1--]='%';
        }
        else{
            str[p1--] = str[p2];
        }
        --p2;
    }
    cout<<"after: "<<str<<endl;
}

int main(void){
    /*
     * 测试用例：
     * 1.输入字符串中包含空格，空格在字符串的最前面，最后面，中间
     * 2.输入字符串不包含空格
     * 3.字符串为NULL
     * 4.字符串空间小于新字符串所需要的空间
     * 5.字符串为空串
     * 6.字符串只包含一个空格，或者多个连续空格，没有其他的字符
     */
    char str[19] = "We are family!";
    ReplaceBlank(str, 19);
    char str2[19] = "  wearefamily!";
    ReplaceBlank(str2,19);
    char str3[19] = "wearefamily!  ";
    ReplaceBlank(str3,19);
    char str4[17] = "wearefamily!";
    ReplaceBlank(str4,17);
    char str5[2] = "";
    ReplaceBlank(str5,2);
    char str6[4] = " ";
    ReplaceBlank(str6,4);
    char str7[7] = "  ";
    ReplaceBlank(str7, 7);
    return 0;
}


