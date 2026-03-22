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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0); // Dummy node handle karega edge cases (jaise head delete karna)
    dummy->next = head;
    ListNode* fast = dummy;
    ListNode* slow = dummy;

    // 1. Fast ko N steps aage le jao
    for (int i = 1; i <= n; i++) {
        fast = fast->next;
    }

    // 2. Dono ko tab tak chalao jab tak fast last node par na ho
    while (fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    // 3. Delete logic
    ListNode* nodeToDelete = slow->next;
    slow->next = slow->next->next;
    delete nodeToDelete;

    return dummy->next;
}
};