/*  '''
【题目】
给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。
你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。

示例:

给定 nums = [2, 7, 11, 15], target = 9
因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
'''  */

/*
解法1
双重循环遍历，
时间复杂度O(n^2)
空间复杂度O(1)
最暴力的方法，简单，但耗费资源
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ret_counter = 0;
        int counter = 0;
        for (unsigned int i = 0; i < s.length(); i++) {
            map<char, int> hash;
            for (unsigned int j = i; j < s.length(); j++) {
                if (hash.count(s[j]) == 0) {
                    counter++;
                    hash[s[j]] = j;
                }
                else
                    break;
            }
            if (counter >= ret_counter)
                ret_counter = counter;
            if (ret_counter >= s.length() - 1)
                break;
            counter = 0;
        }
        return ret_counter;
    }
};