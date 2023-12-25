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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Create a dummy head node to simplify the code
        ListNode dummyHead(0);
        ListNode* p = &dummyHead;
        
        // Set up initial values for the carry and the sum
        int carry = 0;
        int sum = 0;
        
        // Loop until one of the linked lists is empty
        while (l1 || l2) {
            // Calculate the sum of the current digits and the carry
            sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            // Calculate the new carry and the digit for the result
            carry = sum / 10;
            int digit = sum % 10;
            
            // Create a new node for the result and append it to the result linked list
            p->next = new ListNode(digit);
            p = p->next;
        }
        
        // If there's still a carry left, append a new node to the result linked list
        if (carry > 0) {
            p->next = new ListNode(carry);
        }
        
        // Return the result linked list, starting from the dummy head node's next node
        return dummyHead.next;
    }
};
