class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int len = numbers.size();
        if(len<=0)
            return 0;
        int result = numbers[0];
        int subCount = 0;
        for(int i=0;i<len;i++){
            if(result == numbers[i])
                subCount++;
            else{
                if(subCount!=0)
                    subCount--;
                else{
                    result = numbers[i];
                    subCount++;
                }
            }
        }
        return CheckMoreThanHalf(numbers,len,result);
    }
    int CheckMoreThanHalf(vector<int>&numbers, int len, int result){
        int times=0;
        for(int i=0;i<len;i++){
            if(numbers[i]==result)
                times++;
        }
        if(times > len/2)
            return result;
        return 0;
    }
};
