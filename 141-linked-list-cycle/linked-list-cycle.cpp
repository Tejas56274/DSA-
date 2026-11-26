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
    // Returns true if the linked list contains a cycle, false otherwise.
    bool hasCycle(ListNode *head) {
        // An empty list cannot have a cycle.
        if (head == nullptr) return false;

        ListNode *slow = head; // moves one step at a time
        ListNode *fast = head; // moves two steps at a time
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true; // pointers met -> cycle detected
            }
        }
        return false; // fast reached the end -> no cycle
    }
};