class Solution {
public:
    int minimumOperations(string num) {

        int n = num.size();
        vector<int> dp(num.size(),n);

        for(int i = 0; i < n; i++)
        {
            dp[i] = (num[i] == '0')?n-1:n;
        }
        
        for(int i = 0; i < num.size(); i++)
        { 
            for(int j = 0; j < i && (num[i] == '0' || num[i] == '5'); j++)
            {
                if(((num[j]-'0')*10+(num[i]-'0'))%25 == 0)
                {
                    dp[i] = min(dp[i],n-j-2);
                }
            }
        }
    
        return *min_element(dp.begin(), dp.end());
    }
};