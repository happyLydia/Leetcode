class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        
        vector<vector<vector<int>>> cal(target+1, vector<vector<int>>());
		cal[0].push_back(vector<int>());

		for(auto elem:candidates)
		{
			for(auto j=elem; j<=target;j++)
				if(cal[j-elem].size()>0)
				{
					auto tp = cal[j-elem];
					for(auto& t : tp)
						t.push_back(elem);
					cal[j].insert(cal[j].end(),tp.begin(),tp.end());
				}
		}
		auto& ret = cal[target];
		for(int i=0;i<ret.size();i++)
		    sort(ret[i].begin(),ret[i].end());
		return ret;
    }
};