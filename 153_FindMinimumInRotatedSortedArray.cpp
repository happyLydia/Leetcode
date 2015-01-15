class Solution {
public:
    int findMin(vector<int> &num) {
        
        int len = num.size();
        int low=1,high = len-1,mid=0;
        int pv = num[0];
        while(low<=high)
        {
            mid = (low+high)/2;
            if(num[mid]<num[mid-1])
                return num[mid];
            if(num[mid]<pv)
                high = mid-1;
            else low = mid+1;
        }
        
        return num[0];
    }
};