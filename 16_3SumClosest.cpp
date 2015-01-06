class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        
        int closetarget = 65535;
        int n=num.size();
        if(n==3)
            return (num[0]+num[1]+num[2]);
        
        sort(num.begin(),num.end());
        
        for(int first=0; first<n-2;first++)
        {
            int fsmallest = num[first]+num[first+1]+num[first+2];
            int fbiggest = num[first]+num[n-1]+num[n-2];
            if(fsmallest-target>=0 && fbiggest-target>=0 )
            {
                if(abs(fsmallest - target) < abs(closetarget-target))
                    closetarget = fsmallest;
                continue;
            }else if(fsmallest-target<=0 && fbiggest-target<=0)
            {
                if(abs(fbiggest-target) < abs(closetarget-target))
                    closetarget = fbiggest;
                continue;
            }
                
            for(int second=first+1; second<n-1; second++)
            {
                int ssmallest = num[first]+num[second]+num[second+1];
                int sbiggest = num[first]+num[second]+num[n-1];
                
                if(ssmallest - target >=0 && sbiggest -target >=0)
                {
                    if(abs(ssmallest - target) < abs(closetarget - target))
                        closetarget = ssmallest;
                    continue;
                }else if(ssmallest - target <=0 && sbiggest -target <=0)
                {
                     if(abs(sbiggest - target) < abs(closetarget - target))
                        closetarget = sbiggest;
                    continue;
                }
             
                for(int third=second+1; third<n;third++)
                {
                    int cursum = num[first]+num[second]+num[third];
                    if(abs(cursum - target) < abs(closetarget - target))
                        closetarget = cursum;
                  //  else break;
                }
            }
        }
        
        return closetarget;
    }
};