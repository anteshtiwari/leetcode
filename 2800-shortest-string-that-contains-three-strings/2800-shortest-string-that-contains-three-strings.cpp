class Solution {
    string f(string &a, string &b)
    {
        if(a.find(b) != string::npos) return a;
        for(int i=min(a.size(), b.size()); i>=0; i--)
        {
            if(a.substr(a.size()-i)==b.substr(0, i)) return a+b.substr(i);
        }
        return a+b;
    }
    string solve(vector<string> &v)
    {
        int n=v.size();
        string ans="";
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                for(int k=0; k<n; k++)
                {
                    if(i!=j && j!=k && k!=i)
                    {
                        string s1=f(v[i], v[j]); // merging string
                        string s2=f(s1, v[k]); // meriging string
                        if(ans.empty() || s2.size()<ans.size() || (s2.size()==ans.size() && s2<ans))
                        {
                            ans=s2;
                        }
                    }
                }
            }
        }
        return ans;
    }
public:
    string minimumString(string a, string b, string c) 
    {
        vector<string> temp={a, b, c};  // making vector of given string
        return solve(temp);  // returning answer
    }
};