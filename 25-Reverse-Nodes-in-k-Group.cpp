class Solution {
public:
//asked to me in interview of cipher schools on 3rd october 2026
    ListNode* reverseKGroup(ListNode* head, int k) {

        // Dummy node makes handling the first group easier
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // groupPrev points to the node just before the current group
        ListNode* groupPrev = dummy;

        while (true) {

            // Find the kth node of the current group
            ListNode* kth = groupPrev;

            for (int i = 0; i < k && kth != NULL; i++) {
                kth = kth->next;
            }

            // Fewer than k nodes are left
            // So we don't reverse them
            if (kth == NULL)
                break;

            // Store the node after the current group
            ListNode* groupNext = kth->next;

            // Reverse the current group
            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;

            while (curr != groupNext) {
                ListNode* temp = curr->next;

                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            // Connect previous part to the reversed group
            ListNode* temp = groupPrev->next;
            groupPrev->next = kth;

            // temp is now the last node of the reversed group
            // Move groupPrev to it for the next group
            groupPrev = temp;
        }

        return dummy->next;
    }
};