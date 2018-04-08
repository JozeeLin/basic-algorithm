class Solution {
public:
    //适合大数据的解决方式是使用最大堆
    typedef multiset<int, greater<int>> intSet;
    typedef multiset<int, greater<int>>::iterator setIterator;
    
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        int length = input.size();
        vector<int>result;
        if(k <=0 || length < k)
            return result;

        intSet leastNumbers;
        for(int i=0;i<length;i++){
            if(leastNumbers.size()<k)
                leastNumbers.insert(input[i]);
            else{
                setIterator largest = leastNumbers.begin();
                if(*(leastNumbers.begin())>input[i]){
                    leastNumbers.erase(largest);
                    leastNumbers.insert(input[i]);
                }
            }
        }
        for(setIterator it=leastNumbers.begin(); it != leastNumbers.end(); it++){
            result.push_back(*it);
        }
        return result;
    }
};

class Solution {
public:
    ////使用快排的partition函数，对数组进行修改来实现

    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        int size = input.size();
        vector<int> result;
        if(k<=0 || size<k)
            return result;
        int index = Partition(input, size, 0, size-1);
        while(index!=k-1){
            if(index==-1)
                return result;
            if(index<k-1)
                index = Partition(input, size, index+1, size-1);
            else if(index > k-1)
                index = Partition(input, size, 0, index-1);
            else
                break;
        }
        for(int i=0;i<k;i++){
            result.push_back(input[i]);
        }
        return result;
    }
    
    int Partition(vector<int>&input, int length, int start, int end){
        int size = input.size();
        if(size<=0||length<=0||start<0||end>=length||end<start)
            return -1;
        
        int small = start-1;
        for(int i=start;i<end;i++){
            if(input[i] < input[end])
            {
                ++small;
                if(small!=i)
                {
                    int tmp = input[small];
                    input[small] = input[i];
                    input[i] = tmp;
                }
            }
        }
        ++small;
        int tmp = input[small];
        input[small] = input[end];
        input[end] = tmp;
        return small;
    }
};
