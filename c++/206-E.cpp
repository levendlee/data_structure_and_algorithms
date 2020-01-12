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
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        auto pre = head, cur = head->next;
        pre->next = nullptr;
        while (cur) {
            auto tmp = cur->next;   // tmp is the 3rd
            cur->next = pre;        // 2nd points 1st
            pre = cur;              // 2nd become 1st
            cur = tmp;              // 3rd become 2nd
        }
        return pre;
    }
};