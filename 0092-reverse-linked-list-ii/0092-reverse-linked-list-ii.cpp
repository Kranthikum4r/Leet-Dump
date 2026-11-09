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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || left == right) return head;

        int len = 1;
        ListNode* temp = head;
        ListNode* temp1 = NULL;

        ListNode* cur;
        ListNode* prev;
        while(temp) {
            if(len == left) {
                ListNode* tail = temp;
                ListNode* cur = temp;
                ListNode* prev = temp1;

                while(len <= right) {
                    ListNode* next = cur->next;
                    cur->next = prev;
                    prev = cur;
                    cur = next;
                    len++;
                }

                // connect head of reversed list to previous part
                if(temp1) {
                    temp1->next = prev;
                }
                else {
                    head = prev;
                }

                // connect end of reversed list to next part of original list
                tail->next = cur;

                break;
            }

            temp1 = temp;
            temp = temp->next;
            len++;
        }
        
        return head;
    }
};