class Solution1 {
public:
    int majorityElement(vector<int> &num) {
        int nTimes = 0;
        int candidate = 0;
        for(int i = 0; i < num.size(); i ++)
        {
            if(nTimes == 0)
            {
                candidate = num[i];
                nTimes = 1;
            }
            else
            {
                if(candidate == num[i])
                    nTimes ++;
                else
                    nTimes --;
            }
        }
        return candidate;
    }
};

class Solution2 {
public:
    int majorityElement(vector<int> &num) {
        
        int len = num.size();
        
        if(len ==1)
            return num[0];
        
        sort(num.begin(),num.end());
        
        return num[len/2];
    }
};