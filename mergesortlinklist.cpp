#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct List {
    Node* top;
};

void Push(List& l, int data) {
    Node* p = new Node;
    if (p == NULL) {
        cout << "Stack Overfolow" << endl;
        return;
    }
    p->data = data;
    p->next = l.top;
    l.top = p;
}

void printList(List l)
{
    for (Node* p = l.top; p; p = p->next) {
        cout << p->data << " ";
    }
    cout << endl;
}

Node* merge(Node* Node1, Node* Node2)
{
    Node* merged = new Node;
    Node* temp = new Node;
    merged = temp;
    while (Node1 != NULL && Node2 != NULL) {

        if (Node1->data <= Node2->data) {
            temp->next = Node1;
            Node1 = Node1->next;
        }

        else {
            temp->next = Node2;
            Node2 = Node2->next;
        }
        temp = temp->next;
    }

    while (Node1 != NULL) {
        temp->next = Node1;
        Node1 = Node1->next;
        temp = temp->next;
    }

    while (Node2 != NULL) {
        temp->next = Node2;
        Node2 = Node2->next;
        temp = temp->next;
    }

    return merged->next;
}

Node* getMid(Node* head)
{
    Node* a = head;
    Node* b = head->next;

    while (!a->next && (!b && !b->next)) {
        a = a->next;
        b = b->next->next;
    }
    return a;
}

Node* sort(Node* head1)
{
    if (head1->next == NULL) {
        return head1;
    }
    Node* mid = new Node;
    Node* head2 = new Node;
    mid = getMid(head1);
    head2 = mid->next;
    mid->next = NULL;
    Node* head = merge(sort(head1), sort(head2));
    return head;
}

int main(void)
{
    List l;
    l.top = NULL;
    int n[] = { 7, 10, 5, 20, 3, 2 };
    for (int i = 0; i < 6; i++) {
        Push(l,n[i]); // inserting in the list
    }
    cout << "Sorted Linked List is: \n";
    l.top = sort(l.top);
    printList(l); // printing the sorted list returned
                       // by sort()
    return 0;
}
