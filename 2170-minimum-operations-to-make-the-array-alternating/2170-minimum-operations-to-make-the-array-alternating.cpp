class Solution {
    static bool cmp(pair<int, int>& a, pair<int, int>& b)
    {
        return a.second > b.second;
    }
    
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int, int> even, odd;
        int n = nums.size(), ans = 0;
        
        //Base cases
        if(n==1)
            return 0;
        if(n==2)
        {
            if(nums[0] == nums[1])
                return 1;
            else
                return 0;
        }
        
        //iterating over nums to get frequency of elements
        for(int i=0; i<n; i++)
        {
            if(i%2==0)
                even[nums[i]]++;
            else
                odd[nums[i]]++;
        }
      
        vector<pair<int, int>> A, B;
        for (auto& it : even)
            A.push_back(it);
        for (auto& it : odd)
            B.push_back(it);
        
        //sorting in descending order to get elements with higher frequency first
        sort(A.begin(), A.end(), cmp);
        sort(B.begin(), B.end(), cmp);
        
        if(B.empty()) 
            return 0;
        
        if(A[0].first != B[0].first) 
            return n - A[0].second - B[0].second;
        else {
            int odd1 = B[0].second;
            int odd2 = B.size() == 1 ? 0 : B[1].second;
            int even1 = A[0].second;
            int even2 = A.size() == 1 ? 0 : A[1].second;
            
            return n - max(odd1 + even2, odd2 + even1);
        }
    }
};