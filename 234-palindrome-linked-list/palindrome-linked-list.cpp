class Solution {
public:
    // 1. Reverse karne ka function (Jo humne pehle sikha tha)
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr != NULL) {
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) return true;

        // STEP 1: Middle dhundo (Slow-Fast Pointer)
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // STEP 2: Middle ke baad waali list ko Reverse karo
        ListNode* secondHalfHead = reverseList(slow->next);

        // STEP 3: Dono halves ko compare karo
        ListNode* firstHalfHead = head;
        ListNode* temp = secondHalfHead; // Taaki baad mein reverse wapas kar sakein (optional)
        
        while (secondHalfHead != NULL) {
            // "val" matlab dibbe ke andar ka number
            if (firstHalfHead->val != secondHalfHead->val) {
                return false; // Agar match nahi hua toh palindrome nahi hai
            }
            firstHalfHead = firstHalfHead->next;
            secondHalfHead = secondHalfHead->next;
        }

        return true; 
    }
};