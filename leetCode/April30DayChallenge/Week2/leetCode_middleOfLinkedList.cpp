#include<bits/stdc++>

using namespace std;

class ListNode{
	public:
	ListNode * next;
};

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL)
        {
            fast = fast->next;
            if (fast == NULL)
            {
                return slow;
            }
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

int main(){

	return 0;
}
