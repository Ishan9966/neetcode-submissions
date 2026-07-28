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
     
     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* h1 = list1;
        ListNode* h2 = list2;
        ListNode* h3 = nullptr;
        ListNode* h4 = nullptr;

        if (list1 == nullptr && list2 == nullptr) {
            return nullptr;
        } else if (list1 != nullptr && list2 == nullptr) {
            return list1;
        } else if(list1==nullptr && list2!=nullptr){
            return list2;
        }

        if (h1->val > h2->val) {
            h3 = h2;
            h2 = h2->next;
        } else {
            h3 = h1;
            h1 = h1->next;
        }
        h4 = h3;

        while (h1 != nullptr && h2 != nullptr) {
            if (h1->val >= h2->val) {
                h3->next = h2;
                h2 = h2->next;
                h3 = h3->next;
            } else {
                h3->next = h1;
                h1 = h1->next;
                h3 = h3->next;
            }
        }
        if (h1) {
            h3->next = h1;
        }
        if (h2) {
            h3->next = h2;
        }
        return h4;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()){
            return nullptr;
        }
        int i=1;
        for(i=1;i<lists.size();i++){
            lists[i]=mergeTwoLists(lists[i],lists[i-1]);
        }
        return lists[i-1];
    }
};
