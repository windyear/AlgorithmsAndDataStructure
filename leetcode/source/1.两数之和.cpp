class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if(nums.size() < 2){
           vector<int> result;
           return result;
        }
        vector<int> result = {0, 0};
        for(vector<int>::size_type i = 0; i < nums.size()-1; i++){
            for(vector<int>::size_type j = i+1; j < nums.size(); j++){
               if(nums[i] + nums[j] == target){
                   result[0] = i;
                   result[1] = j;
                   break;
               } 
            }
        }
        return result;
    }
};
