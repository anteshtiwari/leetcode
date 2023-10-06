class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size();
        
        int cnt = 0;
        string ans = "";
        for(auto x: s){
            
            if(x == '1'){
                
                cnt = cnt + 1;
                
            }
        }
        
        for(auto x: s){
            
            ans = ans + '0';
        }
        
        ans[n-1] = '1';
        cnt= cnt - 1;
        for(int i=0; i<n-1; i++){
            
            if(cnt != 0 ){
                
                ans[i] = '1';
                cnt--;
                
            }else{
                
                ans[i] = '0';
                
            }
            
            
        }
        
        
        return ans;
    }
};

