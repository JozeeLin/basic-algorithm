class Solution {
public:
    bool g_InvalidInput = false;
    
    int FindGreatestSumOfSubArray(vector<int> array) {
        int GreatestSubArray[3] = {INT_MIN,0,0};
        int length = array.size();
        if(length<=0){
            g_InvalidInput = true;
            return 0;
        }
        
        g_InvalidInput = false;
        int nCurSum = 0;
        int nCurStart = 0;
        int nCurEnd = 0;
        for(int i=0; i<length; ++i){
            if(nCurSum<=0){
                nCurSum = array[i];
                nCurStart = nCurEnd = i;
            }
            else{
                nCurSum += array[i];
                nCurEnd = i;
            }
            if(nCurSum>GreatestSubArray[0]){
                GreatestSubArray[0] = nCurSum;
                GreatestSubArray[1] = nCurStart;
                GreatestSubArray[2] = nCurEnd;
            }
        }
        return GreatestSubArray[0];
    }
};
