class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        
        int n = digits.size();
        if(n==0)
        {
            digits[0]=1;
            return digits;
        }
       
        int addone=1;
        
        for(int i=n-1; i>=1;i--)
        {
            if(addone == 0)
                break;
            int olddig = digits[i];
            digits[i] = (digits[i]+addone)%10;
            addone = (olddig+addone)/10;
        }
        
        int oldhead = digits[0];
        digits[0] = (digits[0]+addone)%10;
        if(oldhead+addone >=10 )
            digits.insert(digits.begin(),1);
        
        
        return digits;
    }
};