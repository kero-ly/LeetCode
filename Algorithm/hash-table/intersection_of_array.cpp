/*
给定两个数组，编写一个函数来计算它们的交集。

示例 1:

输入: nums1 = [1,2,2,1], nums2 = [2,2]
输出: [2,2]
示例 2:

输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出: [4,9]
*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> sb;
        vector<int> qy;
        for (int i = 0; i < nums1.size(); i++) {
            if (sb.count(nums1[i]) == 0) {
                sb[nums1[i]] = 1;
            }
            else {
                sb[nums1[i]] ++;
            }
        }
        
        for (int i = 0; i < nums2.size(); i++) {
            if (sb[nums2[i]] > 0) {
                qy.push_back(nums2[i]);
                sb[nums2[i]]--;
            }
        }
        
        return qy;
    }
};
