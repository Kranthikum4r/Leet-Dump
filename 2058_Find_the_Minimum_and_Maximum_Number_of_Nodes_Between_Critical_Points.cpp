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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> result = {-1, -1};

        int minDist = INT_MAX;

        ListNode* prev = head;
        ListNode* curr = head->next;
        int currIdx = 1;
        int prevIdx = 0;
        int firstIdx = 0;

        while(curr->next != nullptr) {
            if((curr->val < prev->val && curr->val < curr->next->val) ||
                (curr->val > prev->val && curr->val > curr->next->val)) {
                // first critical point
                if(prevIdx == 0) {
                    prevIdx = currIdx;
                    firstIdx = currIdx;
                }
                else {
                    minDist = min(minDist, currIdx - prevIdx);
                    prevIdx = currIdx;
                }
            }

            // Move to the next node and update indices
            currIdx++;
            prev = curr;
            curr = curr->next;
        }

        if(minDist != INT_MAX) {
            int maxDist = prevIdx - firstIdx;
            result = {minDist, maxDist};
        }

        return result;
    }
};