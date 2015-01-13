class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        
        vector<vector<vector<int>>>targetArray(target+1,vector<vector<int>>());
        
        targetArray[0].push_back(vector<int>());
       /* 
        for(auto it=candidates.begin(); it!= candidates.end()&& (*it)<=target;it++){
            vector<int> tp(1,*it);
            targetArray[*it].push_back(std::move(tp));
        }
         */   
        
        for(int i=1; i<=target; i++)
        {
            for(auto it = candidates.begin();it != candidates.end() && (*it)<=i;it++)
            {
                if(targetArray[i-(*it)].size()>0)
                {
                   auto tp = targetArray[i-(*it)];
                    for(auto itt = tp.begin();itt!=tp.end();itt++)
                        (*itt).push_back((*it));
                    targetArray[i].insert(targetArray[i].end(),tp.begin(),tp.end());
                }
            }
        }
        
        return targetArray[target];
        
    }
};