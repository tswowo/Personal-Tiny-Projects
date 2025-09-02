#include<iostream>
using namespace std;

template<typename T>
class myQueue{
    private:
        static const size_t maxSize=100;
        size_t _size=0;
        T _begin[maxSize];
    public:
        void push(const T& val)
        {
            if (_size < maxSize)
            {
                _begin[_size++] = val;
            }
            else
            {
                cerr << "Error: Queue is full." << endl;
            }
        }
        void pop()
        {
            if (_size > 0)
            {
                for (size_t i = 0; i < _size - 1; ++i)
                {
                    _begin[i] = _begin[i + 1];
                }
                --_size;
            }
            else
            {
                cerr << "Error: Queue is empty." << endl;
            }
        }
        T front()
        {
            if (_size > 0)
            {
                return _begin[0];
            }
            cerr << "Error: Queue is empty." << endl;
            return T();
        }
        bool empty()
        {
            return _size == 0;
        }
        size_t size()
        {
            return _size;
        }
};

int main()
{
    myQueue<string>q;
    q.push("Hello");
    q.push("World");
    cout << "Front element: " << q.front() << endl;
    q.pop();
    cout << "Front element after pop: " << q.front() << endl;
    cout << "Queue size: " << q.size() << endl;
    return 0;
}