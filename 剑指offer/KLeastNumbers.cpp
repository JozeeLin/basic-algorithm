class Solution {
public:
    //适合大数据的解决方式是使用最大堆
    typedef multiset<int, greater<int>> intSet;
    typedef multiset<int, greater<int>>::iterator setIterator;
    
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        intSet leastNumbers;
        leastNumbers.clear();
        vector<int>result;
        if(k<1 || input.size() < (unsigned int)k)
            return result;

        int len = input.size();
        for(int i=0;i<len;i++){
            if((leastNumbers.size()) < (unsigned int)k)
                leastNumbers.insert(input[i]);
            else{
                setIterator iterGreatest = leastNumbers.begin();
                if(input[i] < *(leastNumbers.begin()))
                {
                    leastNumbers.erase(iterGreatest);
                    leastNumbers.insert(input[i]);
                }
            }
        }
        for(setIterator it=leastNumbers.begin();it!=leastNumbers.end();it++)
            result.push_back(*it);
        return result;
    }
    
};
