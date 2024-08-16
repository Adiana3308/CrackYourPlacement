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
    int length(ListNode*head){
        int size=0;
        ListNode* curr = head;
        while(curr!=NULL){
            size++;
            curr=curr->next;
        }
        return size;
    }
    ListNode*solve(ListNode*headA,ListNode*headB,int diff){
        ListNode*curr1 = headA;
        ListNode*curr2 = headB;
        for(int i=0;i<diff;i++){
            if(curr1==NULL){
                return NULL;
            }
            curr1=curr1->next;
        }

        while(curr1!=NULL && curr2!=NULL){
            if(curr1==curr2){
                return curr1;
            }
            curr1=curr1->next;
            curr2=curr2->next;
        }
        return NULL;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = length(headA);
        int lenB = length(headB);
        int diff=0;
        if(lenA>lenB){
            diff=lenA-lenB;
            return solve(headA,headB,diff);
        }
        else{
            diff = lenB-lenA;
            return solve(headB,headA,diff);
        }
    }
};
