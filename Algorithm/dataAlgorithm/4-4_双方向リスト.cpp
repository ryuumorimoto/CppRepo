#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <cstdio>
#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef struct List {
    int value;
    List *prev, *next;
} List;

void show(List* list) {
    while (1) {
        cout << list->value;
        list = list->next;
        if (list == nullptr) {
            cout << endl;
            break;
        } else {
            cout << " ";
        }
    }
}
int main() {
    int N;
    cin >> N;
    char order[20];
    List head;
    head.next = nullptr;
    head.prev = nullptr;
    /*List content[MAXORDER];
    int index = 0;*/
    rep(i, N) {
        int tmp;
        scanf("%s", order);
        // cout << tmp << " " << order << strcmp(order, "insert") << endl;

        if (strcmp(order, "insert") == 0) {
            scanf("%d", &tmp);
            List* list = new List;
            // 代入されるもの更新
            list->value = tmp;
            list->prev = &head;
            list->next = head.next;
            // 代入されたものの後の更新
            if (head.next != nullptr) {
                head.next->prev = list;
            }
            // headの更新
            head.next = list;
            if (head.prev == nullptr) {
                head.prev = list;
                // cout << "set head pref " << head.prev->value << endl;
            }
        } else if (strcmp(order, "delete") == 0) {
            scanf("%d", &tmp);
            List* list = head.next;
            int count = 0;
            while (1) {
                // cout << count << " " << list->value << endl;
                if (list->value == tmp) {
                    list->prev->next = list->next;
                    if (list->next != nullptr) {
                        list->next->prev = list->prev;
                    } else {
                        head.prev = list->prev;
                    }
                    free(list);
                    break;
                }
                list = list->next;
                if (list == nullptr) {
                    break;
                }
                // count += 1;
            }
        } else if (strcmp(order, "deleteFirst") == 0) {
            head.next->next->prev = &head;
            List* list = head.next;
            head.next = head.next->next;
            // cout << list->value << endl;
            free(list);

        } else if (strcmp(order, "deleteLast") == 0) {
            /*List* list = head.next;
            while (1) {
                if (list->next == nullptr) {
                    list->prev->next = nullptr;
                    free(list);
                    break;
                } else {
                    list = list->next;
                }
            }*/
            // cout << "value: " << head.prev->value << endl;
            head.prev->prev->next = nullptr;
            if (head.prev != nullptr) {
                List* list = head.prev;
                head.prev = head.prev->prev;
                free(list);
            }
        }
        // show(head.next);
    }
    List* list = head.next;
    show(list);

    return 0;
}