/*
 * 统计一个数字在排序数组中出现的次数。
 * 二分查找，递归
 */
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int size = data.size();
        if(size <= 0)
            return 0;
        int first = FindFirstK(data, k, 0, size-1);
        int last = FindLastK(data, k, 0, size-1);
        if(first>-1 && last >-1)
            return last-first+1;
        return 0;
    }
    
    int FindFirstK(vector<int>&data, int k, int start, int end){
        if(start >= end && data[start]!=k)
            return -1;
        if(start==end && data[start]==k)
            return start;
        int mid = (end+start)/2;
        if(data[mid]==k){
            //当mid==0时，说明它的左边没有元素可以比较了，这时mid就是k的其实位置
            if((mid>0 && data[mid-1]!=k) || mid==0)
                return mid;
            else
                end = mid-1;
        }else if(data[mid]>k){
            end = mid-1;
        }else
            start = mid+1;
        
        return FindFirstK(data, k, start, end);
    }
    
    int FindLastK(vector<int>&data, int k, int start, int end){
        int size = data.size();
        if(start>=end && data[start]!=k)
            return -1;
        if(start==end && data[start]==k)
            return start;
        int mid = (end+start)/2;
        if(data[mid]==k){
            //当mid为size-1时，说明mid的右边没有别的元素了，所以mid为k的结束位置
            if((mid<size-1 && data[mid+1]!=k) || mid==size-1)
                return mid;
            else
                start = mid+1;
        }else if(data[mid]>k)
            end = mid-1;
        else
            start = mid+1;
        
        return FindLastK(data, k, start, end);
    }
};

/*
 *二分查找，循环
 */
ass Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int size = data.size();
        if(size <= 0)
            return 0;
        int first = FindFirstK(data, k, 0, size-1);
        int last = FindLastK(data, k, 0, size-1);
        if(first>-1 && last >-1)
            return last-first+1;
        return 0;
    }
    
    int FindFirstK(vector<int>&data, int k, int start, int end){
        int result = -1;
        int mid = 0;
        while(start<=end){
            mid = (end+start)/2;
            if(data[mid]==k){
                if((mid>0&&data[mid-1]!=k) || mid==0)
                    return mid;
                else
                    end = mid-1;
            }else if(data[mid]>k)
                end = mid-1;
            else
                start = mid+1;
        }
        return result;
    }
    
    int FindLastK(vector<int>&data, int k, int start, int end){
        int size = data.size();
        int result = -1;
        int mid = 0;
        while(start<=end){
            mid = (start+end)/2;
            if(data[mid]==k){
                if((mid<size-1&&data[mid+1]!=k) || mid==size-1)
                    return mid;
                else
                    start = mid+1;
            }else if(data[mid]>k)
                end = mid-1;
            else
                start = mid+1;
        }
        return result;
    }
};
