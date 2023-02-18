/**
 *author:xyz_123
 *created:07-02-2023(14:46:44)
 **/
#include <bits/stdc++.h>
using namespace std;
class Queue
{
public:
    int *arr;
    int arr_cap;
    int size;
    int l;
    int r;
    Queue()
    {
        arr = new int[1];
        arr_cap = 1;
        size = 0;
        l = 0;
        r = -1;
    }
    // remove cicular
    void remove_circular()
    {
        if (l > r)
        {
            int *temp;
            temp = new int[arr_cap];
            for (int i = l; i < arr_cap; i++)
            {
                temp[i] = arr[i];
            }
            for (int i = 0; i < r; i++)
            {
                temp[i] = arr[i];
            }
            swap(temp, arr);
            delete[] temp;
        }
    }
    // increase size
    void increase_size()
    {
        remove_circular();
        int *temp;
        temp = new int[arr_cap * 2];
        for (int i = 0; i < arr_cap; i++)
        {
            temp[i] = arr[i];
        }
        swap(arr, temp);
        arr_cap = arr_cap * 2;
    }
    // enQueue......
    void enqueue(int val)
    {
        if (size == arr_cap)
        {
            increase_size();
        }
        r++;
        if (r == arr_cap)
        {
            r = 0;
        }
        arr[r] = val;
        size++;
    }
    // dequeue......
    void dequeue()
    {
        if (size == 0)
        {
            cout << "queue is empty!\n";
            return;
        }
        l++;
        if (l == arr_cap)
        {
            l = 0;
        }
        size--;
    }
    // front.....
    void front()
    {
        if (size == 0)
        {
            cout << "queue is empty!\n";
            return;
        }
        cout << arr[l] << "\n";
    }
};
int main()
{
    Queue q;
    q.enqueue(35);
    q.front();
    q.dequeue();
    q.enqueue(70);
    q.front();
    q.dequeue();
    q.enqueue(305);
    q.front();
    q.dequeue();
    q.enqueue(305);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    // q.front();
    return 0;
}