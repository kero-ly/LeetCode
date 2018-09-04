/*
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的一个字母异位词。

示例 1:
输入: s = "anagram", t = "nagaram"
输出: true

示例 2:
输入: s = "rat", t = "car"
输出: false
*/

static int xx = []() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

// 还是建表比较快，但是考虑unicode呢？
class Solution {
public:
    bool isAnagram(string s, string t) {
        int s_[26] = {0};
        int t_[26] = {0};
        for (int i = 0; i < s.size(); i++)
            s_[s[i]-'a']++;
        for (int i = 0; i < t.size(); i++)
            t_[t[i]-'a']++;
        for (int i = 0; i < 26; i++) {
            if (s_[i] != t_[i])
                return false;
        }
        return true;
    }
};

// 排序就有点慢了，虽然也挺直观
bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != t[i])
                return false;
        }
        return true;
    }
