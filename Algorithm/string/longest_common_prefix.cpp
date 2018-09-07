/*
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:
输入: ["flower","flow","flight"]
输出: "fl"

示例 2:
输入: ["dog","racecar","car"]
输出: ""

解释: 输入不存在公共前缀。
*/

// 就是逐个遍历比较同一个位置的字母，直到遇到不同，然后返回子串
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int vec_len=strs.size();
        if(vec_len==0)
            return "";
        int str_len=strs[0].size();
        for(int i=0;i<str_len;i++)
          for(int j=1;j<vec_len;j++)
            if(strs[j][i]!=strs[0][i])
                return strs[0].substr(0,i);
        return strs[0];
                      
        
    }
};
