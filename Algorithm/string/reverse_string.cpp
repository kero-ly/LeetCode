/*
编写一个函数，其作用是将输入的字符串反转过来。

示例 1:
输入: "hello"
输出: "olleh"

示例 2:
输入: "A man, a plan, a canal: Panama"
输出: "amanaP :lanac a ,nalp a ,nam A"
*/

// O(n)解法
class Solution {
public:
    string reverseString(string s) {
        string a;
        for (int i = s.size() - 1; i >= 0; i--)
            a += s[i];
        return a;
    }
};

// O(n/2)解法
class Solution {
public:
    string reverseString(string s) {
        for (int i = 0; i < s.size()/2; i++)
            swap(s[i], s[s.size()-1-i]);
        return s;
    }
};
