/**
 *author:xyz_123
 *created:05-02-2023(14:46:04)
 **/
#include <bits/stdc++.h>
using namespace std;
const int max_size = 5;
class Queue
{
public:
    int l, r, size;
    int a[max_size];
    Queue()
    {
        l = 0;
        r = -1;
        size = 0;
    }
    // enter element in queue...
    void enqueue(int val)
    {
        if (size == max_size)
        {
            cout << "queue is full!\n";
            return;
        }
        r++;
        if (r == max_size)
        {
            r = 0;
        }
        a[r] = val;
        size++;
    }
    // delete element in queue...
    void dequeue()
    {
        if (size == 0)
        {
            cout << "queue is empty!\n";
            return;
        }
        l++;
        if (l == max_size)
        {
            l = 0;
        }

        size--;
    }
    // front element..
    void front()
    {
        if (size == 0)
        {
            cout << "queue is empty!\n";
            return;
        }
        cout << a[l] << endl;
    }
    int getSize()
    {
        return size;
    }
};
int main()
{
    Queue q;
    cout << q.getSize() << endl;
    q.enqueue(5);
    q.enqueue(15);
    q.enqueue(25);
    q.enqueue(45);
    q.enqueue(65);
    cout << q.getSize() << endl;
    return 0;
}