class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        
        vector<vector<int>>res;
        int n = num.size();
        if(n<=2)
            return res;
        sort(num.begin(),num.end());
        
        for(int first=0; first<=n-3; first++ )
        {
            if(num[first] + num[n-2]+num[n-1] <0)
                continue;
            if(first != 0 && num[first-1] == num[first])
                continue;
            if(num[first] >0)
                break;
            for(int second = first+1; second<=n-2;second++)
            {
                if(second!= first+1 && num[second-1] == num[second])
                    continue;
                if(num[first] + num[second] + num[n-1] <0)
                    continue;
                if(num[first]+num[second]>0)
                    break;
                
                for(int third = second+1; third <= n-1; third++)
                {
                    if(third != second+1 && num[third-1] == num[third])
                        continue;
                    if(num[first] + num[second] + num[third] == 0)
                    {
                        vector<int> curres;
                        curres.push_back(num[first]);
                        curres.push_back(num[second]);
                        curres.push_back(num[third]);
                        res.push_back(curres);
                        break;
                    }else if(num[first] + num[second] + num[third] > 0)
                        break;
                }    
            }
        }
        
        return res;
    }
};