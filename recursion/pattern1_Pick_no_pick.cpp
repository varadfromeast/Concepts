class Solution {
public:
    void find(int ind, vector<int> &nums, vector<int> &curr, vector<vector<int>>&res) {
        if(ind == nums.size()) {
            res.push_back(curr);
            return;
        }
        
        curr.push_back(nums[ind]);
        find(ind+1,nums,curr,res);
        curr.pop_back();
        
        find(ind+1,nums,curr,res);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>curr;
        
        find(0,nums,curr,res);
        return res;
    }
};
