class Solution {
public:
    string maximumBinaryString(string s) {
        
        //Step 1 -> Count number of zeroes
        int zeros=0;
        for(auto i:s)
            if(i=='0')
                zeros++;
        
 //Step 2 Only one '0' will be left as baaki sb '0's club krke "00"--> "10" bnayege
/* Dry run --> "110010101"

           -->  111010101 (00 -> 10)
           -->  111001101 (10 -> 01)
           -->  111101101 (00 -> 10)  00 -> 10 bna rha aur '10' jo bnra vo 01 bnjara
           -->  111101011 (10 -> 01)
           -->  111100111 (10 -> 01)
           -->  111110111 (00 -> 10)
now see 1st zero i=2 index pe tha vo shift hogya apne se aage (no of zeroes -1) times = (2+4-1)= 5th index  aur dekho 5th index pe hi 0 hai "111110111"     */
        
        string ans(s.size(),'1');
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='0')    
            {
                ans[i+zeros-1]='0';
                return ans;
            }
        }
        return ans;
    }
};