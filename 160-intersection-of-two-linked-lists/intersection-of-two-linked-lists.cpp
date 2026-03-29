class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Agar koi bhi list khali hai toh intersection ho hi nahi sakta
        if (headA == NULL || headB == NULL) return NULL;

        ListNode* a = headA;
        ListNode* b = headB;

        // Jab tak dono pointers same node pe na pahunch jayein
        while (a != b) {
            // Agar pointer 'a' end tak pahunch gaya, toh use headB pe bhej do
            // Nahi toh use ek kadam aage badhao
            if (a == NULL) {
                a = headB;
            } else {
                a = a->next;
            }

            // Agar pointer 'b' end tak pahunch gaya, toh use headA pe bhej do
            // Nahi toh use ek kadam aage badhao
            if (b == NULL) {
                b = headA;
            } else {
                b = b->next;
            }
        }

        // Ya toh ye intersection node pe honge, ya dono NULL pe (agar intersection nahi hai)
        return a;
    }
};