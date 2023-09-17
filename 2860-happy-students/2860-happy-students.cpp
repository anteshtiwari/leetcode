class Solution {
public:
    int countWays(vector<int>& v) {
        int n=v.size();
        sort(v.begin(),v.end());
        int ans=0;
        int c=0;
        if(c<v[0])
            ans++;
        for(int i=0;i<n;i++)
        {  c++;
           if(i==n-1 && c>v[i])
                ans++;
            else if(c>v[i] && c<v[i+1])
                ans++;
         
            for(int j=0; j<n; j++){
           
            
            
            }
        }
        return ans;
    }
};

