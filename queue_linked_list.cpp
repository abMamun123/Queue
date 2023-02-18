/**
 *author:xyz_123
 *created:06-02-2023(00:05:52)
 **/
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
class Queue
{
public:
    node *head;
    node *tail;
    int size;
    Queue()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    // create new node
    node *create_new_node(int val)
    {
        node *new_node = new node;
        new_node->data = val;
        new_node->next = NULL;
        return new_node;
    }
    // insert at head
    void insert_at_head(int val)
    {
        size++;
        node *new_node = create_new_node(val);
        if (head == NULL)
        {
            head = new_node;
            tail = new_node;
            return;
        }
        node *a = head;
        new_node->next = a;
        head = new_node;
    }
    // insert at tail
    void enqueue(int val)
    {
        size++;
        node *new_node = create_new_node(val);
        if (tail == NULL)
        {
            tail = new_node;
            head = new_node;
            return;
        }
        node *a = tail;
        a->next = new_node;
        tail = new_node;
    }
    // delete at head
    void dequeue()
    {
        if (head == NULL)
        {
            return;
        }
        node *a = head;
        head = a->next;
        delete a;
        size--;
    }
    // print queue
    void print()
    {
        if (head == NULL)
        {
            return;
        }
        node *a = head;
        while (a != NULL)
        {
            cout << a->data << " ";
            a = a->next;
        }
        cout << endl;
    }
    void getSize(){
        cout<<size<<endl;
    }
    void front(){
        if (head == NULL)
        {
            return;
        } 
        cout<<head->data<<"\n";
    }
};
int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.front();
    return 0;
}