#include <stdio.h>
#include <stdlib.h>

typedef struct node_
{
    struct node_* m_next;
    int m_value;
} node_t;

node_t* node_new(int value)
{
    node_t* node = (node_t*)malloc(sizeof(node_t));
    node->m_next = NULL;
    node->m_value = value;
    return node;
}

void node_print(node_t* node)
{
    if (node) {
        printf("%d\n", node->m_value);
    }
}

void node_delete(node_t* node)
{
    if (node) {
        printf("node_delete: %d\n", node->m_value);
        free(node);
    }
}

void list_print(node_t* head)
{
    while (head) {
        node_print(head);
        head = head->m_next;
    }
}

node_t* list_push_front(node_t* head, node_t* node)
{
    // pushing front, so new node is also the new head.
    node_t* new_head = NULL;
    if (node) {
        node->m_next = head;
        new_head = node;
    }
    return new_head;
}

node_t* list_push_back(node_t* head, node_t* node)
{
    // pushing back means we have to traverse to end of list to insert
    if (node) {
        if (head) {
            node_t* i = head;
            while (i->m_next) {
                i = i->m_next;
            }
            i->m_next = node;
            node->m_next = NULL;
        } else {
            head = node;
        }
    }
    return head;
}

node_t* list_create_push_front(int n)
{
    node_t* head = NULL;
    for (int i = 0; i < n; ++i) {
        node_t* node = node_new(i);
        head = list_push_front(head, node);
    }
    return head;
}

node_t* list_create_push_back(int n)
{
    node_t* head = NULL;
    for (int i = 0; i < n; ++i) {
        node_t* node = node_new(i);
        head = list_push_back(head, node);
    }
    return head;
}

node_t* list_delete(node_t* head)
{
    while (head) {
        node_t* node = head;
        head = head->m_next;
        node_delete(node);
    }
    return head;
}

node_t* list_reverse(node_t* head)
{
    node_t* new_head = NULL;
    if (head) {
        node_t* a = head;
        node_t* b = head->m_next;
        new_head = a;
        while (b) {
            new_head = b;
            if (a == head) {
                a->m_next = NULL;
            }
            node_t* next_a = b;
            node_t* next_b = b->m_next;
            b->m_next = a;
            a = next_a;
            b = next_b;
        }
    }
    return new_head;
}

int main(int argc, char** argv)
{
    int n = 0;
    if (argc > 1) {
        sscanf(argv[1], "%d", &n);
    }
    node_t* head = list_create_push_back(n);
    printf("forward:\n");
    list_print(head);
    head = list_reverse(head);
    printf("reversed:\n");
    list_print(head);
    head = list_delete(head);

    return 0;
}
