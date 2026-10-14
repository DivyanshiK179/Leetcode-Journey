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
    bool hasCycle(ListNode *head) {
        ListNode *temp=head;
        unordered_set<ListNode *> set;
        while(temp!=NULL)
        {
            if(set.contains(temp))
            {
                return true;
            }
            set.insert(temp);
            temp=temp->next;
        }
        return false;
    }
};