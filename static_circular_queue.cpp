/**
 *author:Abu Jafar Shiddik
 *created:25-02-2023(12:36:36)
 **/
#include <bits/stdc++.h>
using namespace std;
const int max_size = 100;

class Queue
{
public:
    int a[max_size];
    int l, r, size;
    Queue()
    {
        l = 0;
        r = -1;
        size = 0;
    }
    // enqueue
    void enqueue(int x)
    {
        if (size == max_size)
        {
            cout << "Queue is full!\n";
            return;
        }
        r++;
        if (r == max_size)
            r = 0;
        a[r] = x;
        size++;
    }
    // dequeue
    void dequeue()
    {
        if (size == 0)
        {
            cout << "Queue is empty!\n";
            return;
        }
        l++;
        if (l == max_size)
            l = 0;
        size--;
    }
    // front
    int front()
    {
        if (size == 0)
        {
            cout << "Queue is empty!\n";
            return -1;
        }
        return a[l];
    }
};
int main()
{
    Queue q;
    q.enqueue(4);
    q.enqueue(40);
    q.enqueue(45);
    q.enqueue(50);
    cout << q.front() << "\n";
    q.dequeue();
    cout << q.front() << "\n";
    q.dequeue();
    cout << q.front() << "\n";
    q.dequeue();
    cout << q.front() << "\n";
    q.dequeue();
    cout << q.front() << "\n";
    return 0;
}