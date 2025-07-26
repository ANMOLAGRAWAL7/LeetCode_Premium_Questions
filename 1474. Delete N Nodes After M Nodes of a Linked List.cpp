/*
You are given the head of a linked list and two integers m and n.

Traverse the linked list and remove some nodes in the following way:

Start with the head as the current node.
Keep the first m nodes starting with the current node.
Remove the next n nodes
Keep repeating steps 2 and 3 until you reach the end of the list.
Return the head of the modified list after removing the mentioned nodes.
*/
class Solution {
public:
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode* main=head;
        ListNode* cur=head;
        while(main){
            int mc=m,nc=n;
            while(main && mc){
                cur=main;
                main=main->next;
                mc--;
            }
            while(main && nc){
                main=main->next;
                nc--;
            }
            cur->next=main;
        }
        return head;
    }
};
