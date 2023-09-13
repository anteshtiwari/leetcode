class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        multimap<int,int> m;
        int ans = 0;
        for(int i=0;i<reward1.size();i++){
            m.insert({reward2[i]-reward1[i],i});
        }
        int bt = 0;
        multimap<int, int>::iterator itr;
        for (itr = m.begin(); itr != m.end() ; ++itr) {
            if(bt<k){
                ans+=reward1[itr->second];
                bt++;
            }else{
                ans+=reward2[itr->second];
            }
    }
        return ans;
        
    }
};