//输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        int length = sequence.size();
        if(length<=0)
            return false;
        return verifySequenceOfBST(sequence,0,length);
    }
    bool verifySequenceOfBST(vector<int> sequence, int start, int length){
        if(length<=0)
            return true;
        int rootValue = sequence[length-1];
        int leftLen = start;
        while(sequence[leftLen]<rootValue)
            leftLen++;
        for(int i=leftLen;i<length-1;i++)
            if(sequence[i]<rootValue)
                return false;
        bool result = false;
        if(leftLen>start)
            result = verifySequenceOfBST(sequence,start, leftLen-start);
        if(!result && leftLen-start<length)
            result = verifySequenceOfBST(sequence,leftLen,length-leftLen-1);
        return result;
    }
};

