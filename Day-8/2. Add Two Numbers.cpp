class Solution {
public:
    ListNode* addTwoNumbers(ListNode* a, ListNode* b) {
        ListNode dummy(0), *cur = &dummy;
        int carry = 0;
        
        while (a || b || carry) {
            int sum = carry;
            if (a) sum += a->val, a = a->next;
            if (b) sum += b->val, b = b->next;
            
            carry = sum / 10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
        }
        
        return dummy.next;
    }
};
