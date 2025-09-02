#include<iostream>

using namespace std;


template<typename T>
class myStack{
    private:
        static const size_t maxSize=100;
        size_t _size=0;
        T _begin[maxSize];
    public:
        void push(const T&val)
        {
            if(_size==maxSize-1)
            {
                cerr << "Error: Stack is full." << endl;
                return;
            }
            _begin[_size++]=val;
        }
        // void push(const T val)
        // {
        //     if(_size==maxSize-1)
        //     {
        //         cerr << "Error: Stack is full." << endl;
        //         return;
        //     }
        //     _begin[_size++]=val;
        // }
        T top()
        {
            if(_size>0)
                return _begin[_size-1];
            cerr << "Error: Stack is empty." << endl;
            return T();
        }
        void pop()
        {
            if(_size>0)
            {
                _size--;
                return;
            }
            cerr << "Error: Stack is empty." << endl;
        }
};

int main()
{
    myStack<int> st;
    st.push(10);
    cout << "Top element: " << st.top() << endl;
    st.pop();
    cout << "Top element after pop: " << st.top() << endl;
    return 0;
}
