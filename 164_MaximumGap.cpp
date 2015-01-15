class Solution {
public:
    int maximumGap(vector<int> &num) {
        
       int len = num.size();
       if(len<=1)
           return 0;
       if(len == 2)
           return num[0]>num[1]?num[0]-num[1]:num[1]-num[0];
       
       int min=numeric_limits<int>::max();
       int max=numeric_limits<int>::min();
       
       for(auto it : num)
       {
           if(it < min) min = it;
           if(it > max) max = it;
       }
       
       int delt = (max - min)/(len-1);
       
       vector<vector<int>>bulks(len,vector<int>());
       
       for(auto it : num)
       {
           int bid = (it - min)/(delt+1);// must use del+1, consider delt = 0
           bulks[bid].push_back(it);
       }
       
       int upbond = min,premax = min;
       int lowbond = max;
       int maxgap = delt;
       
       for(auto it : bulks)
       {
           upbond = min;
           lowbond = max;
           
           if(it.empty())
               continue;
               
           for(auto elem : it)
           {
               if(elem >= upbond)
                   upbond = elem;
               if(elem <= lowbond)
                   lowbond = elem;
           }
           int gap = lowbond - premax;
           if(gap > maxgap)
               maxgap = gap;
           premax = upbond;
       }
        
        return maxgap;
    }
};