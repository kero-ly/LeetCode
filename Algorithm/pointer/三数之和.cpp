/*
例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]

思路：
使用双指针，前后夹击！

*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> >re;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); ++i){
            
            // j指针去重
            if(i!=0 && nums[i]==nums[i-1]) continue;
            
            // 双指针定义
            int j=i+1, k=nums.size()-1;
            
            // 结束条件为相撞
            while(j<k){
                int sum=nums[j]+nums[k]+nums[i];
                if(sum==0){
                    re.push_back({nums[i], nums[j], nums[k]});
                    ++j;
                    --k; 
                    while(j<k && nums[j]==nums[j-1]) ++j;
                    while(j<k && nums[k]==nums[k+1]) --k; 
                }
                else{
                    sum<0 ? ++j: --k;
                }
            }
        }
        return re;
    }
};
