#include<iostream>
#define min(a,b) ((a)<(b)?(a):(b))

using namespace std;

template<typename T>
class xxb{
    private:
        static const size_t maxSize=100;
        size_t _size=0;
        T _begin[maxSize];
    public:
        bool empty()
        {
            return _size == 0;
        }
        size_t size()
        {
            return _size;
        }
        void print()
        {
            for (size_t i = 0; i < _size; ++i)
                cout << _begin[i] << " ";
            cout << endl;
        }
        void push_back(const T& value)
        {
            if (_size < maxSize)
                _begin[_size++] = value;
            else
                cerr << "Error: List is full." << endl;
        }
        void insert(size_t pos,T val)
        {
            if(_size<maxSize&&pos<=_size)
            {
                for(size_t i=_size;i>pos;--i)
                    _begin[i]=_begin[i-1];
                _begin[pos]=val;
                ++_size;
            }
        }
        void erase(size_t pos,int count=1)
        {
            if(pos<_size)
            {
                count=min(count,_size-pos);
                for(size_t i=pos;i<_size-count;i++)
                    _begin[i]=_begin[i+count];
                _size-=count;
            }
        }
        void erase(size_t posBegin,size_t posEnd)
        {
            if(posBegin<_size&&posEnd<=_size&&posBegin<posEnd)
            {
                for(size_t i=posBegin;i<_size-(posEnd-posBegin);++i)
                    _begin[i]=_begin[i+(posEnd-posBegin)];
                _size-=(posEnd-posBegin);
            }
        }
        T& operator[](size_t index)
        {
            if (index < _size)
                return _begin[index];
            throw out_of_range("Index out of range");
        }
};

int main()
{
    xxb<int>a;
    int n=102;
    for(int i=0;i<n;i++)
    {
        a.push_back(i);
    }
    cout<<a.size()<<endl;
    a.insert(2, 100);
    a.erase(3);
    a.print();
    return 0;
}