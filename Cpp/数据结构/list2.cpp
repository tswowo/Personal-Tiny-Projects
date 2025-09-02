#include<iostream>
#include<stdexcept>  // 用于异常处理
using namespace std;

template<typename T>
class myList2{
private:
    static const int maxNum=1000;
    T* val;
    int* next;
    size_t _size;
    size_t _pos;

public:
    myList2() {
        val = new T[maxNum];
        next = new int[maxNum];
        for (int i = 0; i < maxNum; i++)
            next[i] = -1;
        _size = 0;
        _pos=1;
    }

    ~myList2() {
        delete[] val;
        delete[] next;
    }

    void push_front(const T& value) {
        next[_pos]=next[0];
        next[0]=_pos;
        val[_pos]=value;
        _pos++;
        _size++;
    }

    void push_back(const T& value) {
        int cur=0;
        while(next[cur]!=-1)
            cur=next[cur];
        next[cur]=_pos;
        val[_pos]=value;
        _pos++;
        _size++;
    }

    void pop_front()
    {
        if(empty())
            throw out_of_range("Pop front error: list is empty");
        next[0]=next[next[0]];
        _size--;
    }

    void pop_back() {
        if (empty())
            throw out_of_range("Pop back error: list is empty");
        int cur = 0;
        while (next[next[cur]] != -1)
            cur = next[cur];
        next[cur] = -1;
        _size--;
    }

    size_t size() const { return _size; }
    bool empty() const { return _size == 0; }

    // 插入元素
    void insert(size_t pos, const T& value) {
        if (pos > _size) {
            throw out_of_range("Insert error: position out of range");
        }
        int cur=0;
        for(size_t i=0;i<pos&&cur!=-1;i++)
            cur=next[cur];
        next[_pos]=next[cur];
        next[cur]=_pos;
        val[_pos]=value;
        _pos++;
        _size++;
    }

    // 删除元素
    void erase(size_t pos) {
        if (pos >= _size) {
            throw out_of_range("Erase error: position out of range");
        }
        int cur=0;
        for(size_t i=0;i<pos&&cur!=-1;i++)
            cur=next[cur];
        next[cur]=next[next[cur]];
        _size--;
    }

    // 重载[]运算符
    T& operator[](size_t pos) {
        if (pos >= _size)
            throw out_of_range("operator[] error: index out of range");
        // 从第一个实际节点开始遍历
        size_t cur=next[0];
        for (size_t i = 0; i < pos; ++i)
            cur = next[cur];
        return val[cur];
    }

    // 打印链表
    void print() const {
        size_t cur = next[0];
        while (cur != -1) {
            cout << val[cur] << " ";
            cur = next[cur];
        }
        cout << endl;
    }
};

int main() {
    try {
        myList2<int> list;
        list.push_back(1);
        list.push_back(2);
        list.push_back(3);
        cout << "List size: " << list.size() << endl;  // 输出：3
        cout << "Element at index 1: " << list[1] << endl;  // 输出：2
        list.print();  // 输出：1 2 3

        list.insert(1, 5);
        cout << "Element at index 1 after insertion: " << list[1] << endl;  // 输出：5
        list.print();  // 输出：1 5 2 3

        list.erase(2);
        cout << "List size after deletion: " << list.size() << endl;  // 输出：3
        list.print();  // 输出：1 5 3
    }
    catch (const out_of_range& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
    