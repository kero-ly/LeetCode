/*
给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。

案例:
s = "leetcode"
返回 0.

s = "loveleetcode",
返回 2.
*/

static int xx = []() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int firstUniqChar(string s) {
        if (s.size() <= 1)
            if (s.size() == 1)
                return 0;
            else
                return -1;
        
        int a[26] = {0};
        
        // 遍历建表
        for (int i = 0; i < s.size(); i++) {
            a[s[i]-'a']++;
        }
        
        // 主要是按照s的顺序再遍历一遍而已
        for (int i = 0; i < s.size(); i++) {
            if (a[s[i]-'a'] == 1)
                return i;
        }
        return -1;
    }
};
