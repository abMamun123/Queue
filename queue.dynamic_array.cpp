#include <bits/stdc++.h>
using namespace std;
class Queue
{
public:
    int *a;
    int array_cap;
    int l, r, size;
    Queue()
    {
        a = new int[1];
        array_cap = 1;
        l = 0;
        r = -1;
        size = 0;
    }
    void remove_circular()
    {
        if (l > r)
        {
            int *tmp = new int[array_cap];
            int idx = 0;
            for (int i = l; i < array_cap; i++)
            {
                tmp[idx] = a[i];
                idx++;
            }
            for (int i = 0; i < r; i++)
            {
                tmp[idx] = a[i];
                idx++;
            }
            swap(a, tmp);
            delete[] tmp;
            l = 0;
            r = array_cap - 1;
        }
    }
    void increase_size()
    {
        remove_circular();
        int *tmp = new int[array_cap * 2];
        for (int i = 0; i < array_cap; i++)
        {
            tmp[i] = a[i];
            swap(tmp, a);
            delete[] tmp;
            array_cap = array_cap * 2;
        }
    }
    // insert in queue.....
    void enqueue(int val)
    {
        if (size == array_cap)
            increase_size();
        r++;
        if (r == array_cap)
        {
            r = 0;
        }
        a[r] = val;
        size++;
    }
    // delete in queue.....
    void dequeue()
    {
        if (size == 0)
        {
            cout << "queue is empty!\n";
            return;
        }
        l++;
        if (l == array_cap)
            l = 0;
        size--;
    };
    // front element
    void front()
    {
        if (size == 0)
        {
            cout << "queue is empty!\n";
            return;
        }
        cout<<a[l]<<"\n";
    }
    int getSize(){
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
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.front();
    cout << q.getSize() << endl;
    queue<string> qu;
    qu.push("my name is");
    qu.front();
    return 0;
}