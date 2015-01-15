class Solution {
public:
    int findMin(vector<int> &num) {
        
        int len = num.size();
        int low=0, high=len-1, mid = 0;
        
        while(low<=high)
        {
            mid = low + (high-low)/2;// search binary bug
            
            if(num[mid]<num[high])
                high = mid;
            else if(num[mid]>num[high])
                low = mid+1;
            else high--;
        }
        
        return num[low];
    }
};