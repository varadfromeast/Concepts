class Solution {
public:
    void find(int ind, vector<int> &nums, vector<int> &curr, vector<vector<int>> &res) {
        res.push_back(curr);
        
        for(int i = ind; i < nums.size(); ++i) {  
            if(i!=ind && nums[i] == nums[i-1]) // i != ind is imp. it allows for subsets starting from 1,1 or 1,1,1.
                continue;
            
            curr.push_back(nums[i]);
            find(i+1,nums,curr,res);
            curr.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>curr;
        
        sort(nums.begin(), nums.end()); // since sorted, only make subsets starting from one distinct element.
        find(0,nums,curr,res);          // 1 1 2 2 3 , only make subsets starting from 1;  1,1;  2;  2,2;  3.
        
        return res;
    }
};
