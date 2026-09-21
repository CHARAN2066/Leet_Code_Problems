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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head -> next == NULL)
        return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        int cnt = 0, v;
        ListNode* prev = dummy, *temp = head, *k;
        while (temp != NULL) {
            if (temp -> next != NULL && temp -> val == temp -> next -> val) {
                v = temp->val;
                while (temp != NULL && temp -> val == v) {
                    temp = temp -> next;
                }
                prev->next = temp;
            }
            else {
                prev = temp;
                temp = temp -> next;
            }
        }
        // if (dummy == NULL)
        // cout<<"s";
        return dummy->next;
    }
};