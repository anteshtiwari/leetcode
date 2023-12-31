
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<nums.size();i++)
            mp[nums[i]].push_back(i);
        
        
        unordered_map<int,vector<long long>>dp;//for storing prefix sum
        
        for(auto it:mp)
        {
            auto arr=it.second;
            dp[it.first].push_back(arr[0]);
            for(int i=1;i<arr.size();i++)
            {
                dp[it.first].push_back(0ll+dp[it.first].back()+arr[i]);
            }
        }
        
        vector<long long>ans(nums.size(),0);
        
        
        for(auto it:mp)
        {
            auto arr1=it.second;
            auto arr2=dp[it.first];
            
            for(int i=arr1.size()-1;i>=0;i--)
            {
                int left=i;
                int right=arr1.size()-i-1;
                
                long long sum1=i-1>=0?arr2[i-1]:0;
                long long sum2=arr2[arr1.size()-1]-arr2[i];
                
                long long val=(1ll*left*arr1[i]-sum1)+(sum2-1ll*right*arr1[i]);
                ans[arr1[i]]=val;
            }
        }
        return ans;
    }
};
