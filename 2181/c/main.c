/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeNodes(struct ListNode* head){
    struct ListNode* lastValid=head;
    struct ListNode* hold=head;
    for(int sum=0;hold!=NULL;){
        if(hold->val == 0 && sum !=0){
            lastValid->val = sum;
            lastValid->next = hold->next;
            sum=0;
            lastValid = hold->next;
        } else{
            sum += hold->val;
        }
        hold = hold->next;
    }
    return head;
}
