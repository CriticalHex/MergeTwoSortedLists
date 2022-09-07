#include<iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode root;
    ListNode* output = &root;
    ListNode* co1 = list1;
    ListNode* co2 = list2;
    bool l1End = false;
    bool l2End = false;

    if (co1 == nullptr and co2 == nullptr) {
        return nullptr;
    }

    else if (co1 == nullptr and co2 != nullptr) {
        l1End = true;
        while (!l2End) {
            output->val = co2->val;
            if (co2->next == nullptr) {
                l2End = true;
            }
            else {
                co2 = co2->next;
            }
            if (!l1End or !l2End) {
                output->next = new ListNode;
                output = output->next;
            }
        }
    }

    else if (co2 == nullptr and co1 != nullptr) {
        while (!l1End) {
            output->val = co1->val;
            if (co1->next == nullptr) {
                l1End = true;
            }
            else {
                co1 = co1->next;
            }
            if (!l1End or !l2End) {
                output->next = new ListNode;
                output = output->next;
            }
        }
    }

    else {
        while (!l1End and !l2End) {
            if (co1->val < co2->val) {
                output->val = co1->val;
                if (co1->next == nullptr) {
                    l1End = true;
                }
                else {
                    co1 = co1->next;
                }
                if (!l1End or !l2End) {
                    output->next = new ListNode;
                    output = output->next;
                }
            }
            else {
                output->val = co2->val;
                if (co2->next == nullptr) {
                    l2End = true;
                }
                else {
                    co2 = co2->next;
                }
                if (!l1End or !l2End) {
                    output->next = new ListNode;
                    output = output->next;
                }
            }
        }
        while (!l2End) {
            output->val = co2->val;
            if (co2->next == nullptr) {
                l2End = true;
            }
            else {
                co2 = co2->next;
            }
            if (!l1End or !l2End) {
                output->next = new ListNode;
                output = output->next;
            }
        }
        while (!l1End) {
            output->val = co1->val;
            if (co1->next == nullptr) {
                l1End = true;
            }
            else {
                co1 = co1->next;
            }
            if (!l1End or !l2End) {
                output->next = new ListNode;
                output = output->next;
            }
        }
    }
    return &root;
}

int main() {
    ListNode in1(1,new ListNode(2, new ListNode(4)));
    //ListNode in1(9);
    ListNode* co1 = &in1;
    ListNode in2(1, new ListNode(3, new ListNode(4)));
    //ListNode in2(3);
    ListNode* co2 = &in2;

    ListNode* result = mergeTwoLists(&in1, &in2);
    bool coEnd = false;
    int current = 0;
    while (!coEnd) {
        current = result->val;
        if (result->next == nullptr) {
            coEnd = true;
        }
        else {
            result = result->next;
        }
        cout << current << endl;
    }
}