class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long int s1 = 0, s2 = 0;
        int c1 = 0, c2 = 0;
        
        for(auto i: nums1){
            
            s1 = s1 + i;
            c1 += (i == 0);
            
        }
        
        for(auto i: nums2){
            
            s2 = s2 + i;
            c2 = c2 + (i == 0);
            
        }
        
        if(c1 == 0 && s1 < s2+c2) return -1;
        if(c2 == 0 && s2 < s1+c1) return -1;
        
        return max(s1+c1, s2+c2);
        
    }
};