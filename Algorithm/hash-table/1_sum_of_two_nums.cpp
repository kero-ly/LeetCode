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
    vector<int> twoSum(vector<int>& nums, int target) {
        for (unsigned int i = 0; i < nums.size(); i++) {
            for (unsigned int j = i+1; j < nums.size(); j++) {
                if ((target - nums[i]) == nums[j]) {
                    vector<int> ret = {i, j};
                    return ret;
                }
            }
        }
        return {};
    }
};

/*
解法2
哈希表（散列表）Hash table
是根据关键码值(Key value)而直接进行访问的数据结构。
也就是说，它通过把关键码值映射到表中一个位置来访问记录，以加快查找的速度。
这个映射函数叫做散列函数，存放记录的数组叫做散列表。

时间复杂度O(n)
空间复杂度O(n)
通过以空间换取速度的方式，我们可以将查找时间从O(n)降低到O(1)。
哈希表正是为此目的而构建的，它支持以 "近似" 恒定的时间进行快速查找
为什么说近似恒定？如果出现数据冲突，则查找时间会从O(1)升低到O(n)，例如（K1!=K2，但f(K1)=f(K2)）

如何解决哈希冲突？
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> hashmap;
        for (unsigned int i = 0; i < nums.size(); i++) {
            
            int temp = target - nums[i];
            
            if (hashmap.count(temp) != 0) {
                vector<int> ret = {hashmap[temp], i};
                return ret;
            }  
            hashmap[nums[i]] = i;
        }
        return {};
    } 
};
