/*Given a Circular Linked List node, which is sorted in non-descending order, write a function to insert a value insertVal into the list such that it remains a sorted circular list. The given node can be a reference to any single node in the list and may not necessarily be the smallest value in the circular list.

If there are multiple suitable places for insertion, you may choose any place to insert the new value. After the insertion, the circular list should remain sorted.

If the list is empty (i.e., the given node is null), you should create a new single circular list and return the reference to that single node. Otherwise, you should return the originally given node*/
/*
Case 1). The value of new node sits between the minimal and maximal values of the current list. As a result, it should be inserted within the list
Case 2). The value of new node goes beyond the minimal and maximal values of the current list, either less than the minimal value or greater than the maximal value. In either case, the new node should be added right after the tail node (i.e. the node with the maximal value of the list).
Case 3). Finally, there is one case that does not fall into any of the above two cases. This is the case where the list contains uniform values.
*/
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        //if LL is empty
        if(!head){
            Node *tmp = new Node(insertVal,NULL);
            tmp->next=tmp;
            return tmp;
        }
        Node *cur=head->next,*prev=head;
        bool fl=false;
        do{
            if(cur->val>=insertVal && insertVal>=prev->val){
                fl=true;
            }
            else if(prev->val>cur->val){
                if(insertVal>=prev->val || insertVal<=cur->val){
                    fl=true;
                }
            }
            if(fl){
                prev->next = new Node(insertVal,cur);
                return head;
            }
            prev=cur;
            cur=cur->next;
        }while(prev!=head);
        prev->next = new Node(insertVal,cur);
        return head;
    }
};
