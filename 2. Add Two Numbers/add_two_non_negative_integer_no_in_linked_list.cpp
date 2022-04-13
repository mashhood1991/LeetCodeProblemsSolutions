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

/*
        
                        2 -> 4 -> 3
                        5 -> 6 -> 4

sub_sum=                7    10   8
sum (sub_sum%10),s=     7    0    8   
c(sub_sum>=10 => c =1)= 0    1

dummy 7 -> 0 -> 8
*/        
        int carry = 0;
        int sub_sum = 0;
        ListNode *dummyNode, *currentNode;
        dummyNode   = new ListNode(); //to return the sum as linked list using dummy node
        currentNode = dummyNode; //pointer to current node to return thr ouput
        
        while(l1 || l2 || carry)
        {
            sub_sum = carry;
            if (l1)
            {
                sub_sum += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                sub_sum += l2->val;
                l2 = l2->next;
            }
            carry = floor(sub_sum/10); // returns the largest integer smaller than or equal to argument (in this case max number is can be 19 so 1) 
            //sub_sum = sub_sum % 10; //right side sub_sum is the actual sum 
            currentNode->next = new ListNode(sub_sum % 10); //to point the next node
            currentNode = currentNode->next;
        }
        return dummyNode->next;        
    }
};
