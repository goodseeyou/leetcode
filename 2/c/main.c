/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    add(l1,l2,0);
    return l1;
}

void add(struct ListNode* l1, struct ListNode* l2, int carry){
    l1->val = l1->val+l2->val+carry;
    int next_carry = l1->val/10;
    l1->val %= 10;
    
    if(l1->next == NULL && l2->next == NULL){
        if(next_carry){
            l1->next = (struct ListNode*) malloc(sizeof(struct ListNode));
            l1->next->val = next_carry;
            l1->next->next = NULL;
        }
    } else if(l2->next == NULL){
        l2->val = 0;
        add(l1->next, l2,next_carry);
    } else if(l1->next == NULL){
        l1->next = l2->next;
        l2->val=0;
        l2->next = NULL;
        add(l1->next,l2, next_carry);
    } else {
        add(l1->next, l2->next,next_carry);
    }
    
}
