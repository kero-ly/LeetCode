/*
给定一个链表（链表结点包含一个整型值）的头结点 head。

同时给定列表 G，该列表是上述链表中整型值的一个子集。

返回列表 G 中组件的个数，这里对组件的定义为：链表中一段最长连续结点的值（该值必须在列表 G 中）构成的集合。

示例 1：

输入: 
head: 0->1->2->3
G = [0, 1, 3]
输出: 2
解释: 
链表中,0 和 1 是相连接的，且 G 中不包含 2，所以 [0, 1] 是 G 的一个组件，同理 [3] 也是一个组件，故返回 2。
示例 2：

输入: 
head: 0->1->2->3->4
G = [0, 3, 1, 4]
输出: 2
解释: 
链表中，0 和 1 是相连接的，3 和 4 是相连接的，所以 [0, 1] 和 [3, 4] 是两个组件，故返回 2。

思路：先做G的哈希，然后遍历链表，重复不统计（使用flag判断），没在G的时候清空flag
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_map<int, int> sb;
        for (int i = 0; i < G.size(); i++) {
            sb[G[i]] = 1;
        }
        // 统计
        int max = 0;
        // 去重
        int flag = 0;
        
        while (head != NULL) {
            if (sb.count(head->val) > 0 && flag == 0) {
                max++;
                flag = 1;
            }
            else if (sb.count(head->val) == 0) {
                cout << head->val << endl;
                flag = 0;
            }
            head = head->next;
        }

        return max;
    }
};
