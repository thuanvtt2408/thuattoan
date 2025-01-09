#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* op = dummy;

        while (list1 && list2) {
            std::cout << "List1 head: " << list1->val << ", List2 head: " << list2->val << std::endl;

            if (list1->val <= list2->val) {
                std::cout << "Select from list1: " << list1->val << std::endl;
                op->next = list1;
                list1 = list1->next;
            } else {
                std::cout << "Select from list2: " << list2->val << std::endl;
                op->next = list2;
                list2 = list2->next;
            }
            op = op->next;

            std::cout << "Current merged list: ";
            printList(dummy->next);
            std::cout << "Press Enter to continue...\n";
            std::cin.get();
        }

        if (list1) {
            std::cout << "Remaining in list1: ";
            printList(list1);
        } else if (list2) {
            std::cout << "Remaining in list2: ";
            printList(list2);
        }

        op->next = list1 ? list1 : list2;

        return dummy->next;
    }

    void printList(ListNode* head) {
        while (head) {
            std::cout << head->val << " ";
            head = head->next;
        }
        std::cout << std::endl;
    }
};

ListNode* createList(const std::vector<int>& vals) {
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    for (int val : vals) {
        current->next = new ListNode(val);
        current = current->next;
    }
    return dummy->next;
}

int main() {
    Solution solution;

    std::vector<int> list1_vals = {1, 2, 4};
    std::vector<int> list2_vals = {1, 3, 4};

    ListNode* list1 = createList(list1_vals);
    ListNode* list2 = createList(list2_vals);

    std::cout << "Initial lists:\n";
    std::cout << "List1: ";
    solution.printList(list1);
    std::cout << "List2: ";
    solution.printList(list2);

    ListNode* mergedList = solution.mergeTwoLists(list1, list2);

    std::cout << "Merged list: ";
    solution.printList(mergedList);

    return 0;
}
