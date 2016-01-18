/*
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL) return NULL;

        ListNode* new_head = head->next ? head->next : head;
        ListNode* cur = new ListNode(0);
        cur->next = head;

        while (cur->next != NULL) {
            ListNode* first = cur->next;
            ListNode* second = first->next;
            if (second == NULL) {
                break;
            }
            ListNode* third = second->next;

            second->next = first;
            cur->next = second;
            cur = first;
            first->next = third;
        }

        return new_head;
    }
};

int main() {
    ListNode* first = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* fourth = new ListNode(4);

    first->next = second;
    second->next = third;
    third->next = fourth;

    Solution solution;
    ListNode* new_head = solution.swapPairs(first);

    return 0;
}
*/
