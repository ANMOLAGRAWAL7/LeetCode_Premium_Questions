/*
Given a non-negative integer represented as a linked list of digits, plus one to the integer.
The digits are stored such that the most significant digit is at the head of the list.
*/
class Solution {
public:
    ListNode* plusOne(ListNode* head) 
    {
        if(!head) return new ListNode(1); // if NULL return a new node
        if(addOne(head) != 0) // if we still have carry, create a new head and link to head
        {
            ListNode * newHead = new ListNode(1);
            newHead->next = head;
            head = newHead;
        }
        return head;
    }
private:
    int addOne(ListNode* node)
    {
        int carry = node->next ? addOne(node->next) : 1;  // if last node, add 1, otherwise add carry
        int sum = node->val + carry;
        node->val = sum % 10;
        return sum/10;
    }
};
