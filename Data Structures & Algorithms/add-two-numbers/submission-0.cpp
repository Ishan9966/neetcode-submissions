/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* h1 = l1;
        ListNode* h2 = l2;
        ListNode h3;
        ListNode* h4 = &h3;

        int carry = 0;
        while (h1 != nullptr || h2 != nullptr) {
            int x = (h1 != nullptr) ? h1->val : 0;
            int y = (h2 != nullptr) ? h2->val : 0;

            int sum = x + y + carry;
            if (sum > 9) {
                sum = sum - 10;
                carry = 1;
            } else {
                carry = 0;
            }
            h4->next = new ListNode(sum);
            h4 = h4->next;
            if (h1) h1 = h1->next;
            if (h2) h2 = h2->next;
        }

        if (carry) {
           h4->next = new ListNode(carry);
        }

        return h3.next;
    }
};
