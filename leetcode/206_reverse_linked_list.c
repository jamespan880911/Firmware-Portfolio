/*
思路：
維護三個指標，一直反下去。最後記得回傳的是pre

關鍵點：
main()測試的時候可以直接用Stack（靜態）變數就好，比較簡單（不用一直malloc跟free），賦值再串起來。
*/

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head) {
    if (!head){
        return NULL;
    }

    struct ListNode *pre = NULL;
    struct ListNode *cur = head;
    struct ListNode *next_tmp = head->next;

    while (cur) {
        next_tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next_tmp;
    }

    return pre;
}

//輔助函式
void printList(struct ListNode *head) {
    struct ListNode *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    struct ListNode n1, n2, n3, n4, n5;

    n1.val = 1;
    n2.val = 2;
    n3.val = 3;
    n4.val = 4;
    n5.val = 5;

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = NULL;

    printList(&n1);

    struct ListNode *new_head = reverseList(&n1);

    printList(new_head);

    return 0;
}