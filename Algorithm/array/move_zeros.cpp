/*
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

示例:

输入: [0,1,0,3,12]
输出: [1,3,12,0,0]
说明:

必须在原数组上操作，不能拷贝额外的数组。
尽量减少操作次数。

*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.size() <= 1)
            return;
        
        vector<int>::iterator p = nums.begin();
        vector<int>::iterator q = nums.begin();
        
        for (int i = 0; i < nums.size(); i++) {
            if (*q == 0) {
                if (q == nums.end()) break;
                q++;
            }
            else {
                *p = *q;
                if (q == nums.end()) break;
                p++;
                q++;
            }
        }

        while (p != nums.end()) {
            *p=0;
            p++;
        }
    }
};

// 记录不用iterator的方法
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int pos=0,count=0;int i=0;
            while(i<nums.size()&&nums[i]!=0){
                pos++;
                i++;
                count++;
            }
        for(;i<nums.size();i++){

            if(nums[i]!=0){
                if(pos<i){
                    nums[pos]=nums[i];
                    count++;
                    pos++;
                }
            }
        }
        for(int i=count;i<nums.size();i++){
            nums[i]=0;
        }
        
    }
};

// 钱仪方法
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.size() <= 1)
            return;
        
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i+1+count >= nums.size()) break;
            
            if (nums[i] != 0) continue;
            
            while (nums[i+1+count] == 0 && i+1+count < nums.size() -1 ) {
                count++;
            }
            swap(nums[i], nums[i+count+1]);
        }
    }
};
