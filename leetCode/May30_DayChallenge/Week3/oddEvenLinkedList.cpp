#include<bits/stdc++.h>

using namespace std;

#define PRINT cout << "PASS\n"; else cout << "FAIL\n";

// Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.
// 
// You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.
// Input: 1->2->3->4->5->NULL
// Output: 1->3->5->2->4->NULL


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == NULL)
            return head;

        ListNode *even = head;
        ListNode *odd = head->next;
        ListNode *oddHead = odd;

        while (odd != NULL && odd->next != NULL)
        {
            // update next value to next even or odd
            even->next = even->next->next;
            odd->next = odd->next->next;
            // add them to list
            even = even->next;
            odd = odd->next;
        }
        even->next = oddHead;
        return head;
    }
};


int main()
{
    Solution s;

    return 0;
}