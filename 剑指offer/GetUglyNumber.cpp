/*
 * 求按从小到大的顺序的第1500个丑数 
 */
class Solution {
public:
    int Min(int x,int y, int z)
    {
        int min = x;
        if(x>y)
            min = y;
        if(min>z)
            min = z;
        return min;
    }
    int GetUglyNumber_Solution(int index) {
        if(index <= 0)
            return 0;
        vector<int> numbers(index,0);
        numbers[0] = 1;
        int ugly2=0;
        int ugly3=0;
        int ugly5=0;
        for(int i=1;i<index;i++){
            int min = Min(numbers[ugly2]*2,numbers[ugly3]*3,numbers[ugly5]*5);
            numbers[i] = min;
            while(numbers[ugly2]*2<=numbers[i]) ugly2++;
            while(numbers[ugly3]*3<=numbers[i]) ugly3++;
            while(numbers[ugly5]*5<=numbers[i]) ugly5++;
        }
        return numbers[index-1];
    }
};
