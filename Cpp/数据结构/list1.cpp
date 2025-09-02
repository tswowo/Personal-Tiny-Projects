#include<iostream>
#include<stdexcept>  // 用于异常处理
using namespace std;

template<typename T>
class myList1{
private:
    struct listNode{
        T val;
        listNode* next;
        listNode(const T& value = T()) : val(value), next(nullptr) {}
    };
    
    typedef listNode Node;
    Node* head;
    size_t _size;

public:
    myList1() {
        head = new Node();
        head->next = nullptr;
        _size = 0;
    }

    ~myList1() {
        clear();
        delete head;
    }

    void clear() {
        _size = 0;
        Node* cur = head->next;
        while (cur != nullptr) {
            Node* next = cur->next;
            delete cur;
            cur = next;
        }
        head->next = nullptr;
    }

    void push_front(const T& val) {
        Node* newNode = new Node(val);
        newNode->next = head->next;
        head->next = newNode;
        _size++;
    }

    void push_back(const T& val) {
        Node* newNode = new Node(val);
        Node* cur = head;
        while (cur->next != nullptr)
            cur = cur->next;
        cur->next = newNode;
        _size++;
    }

    void pop_front()
    {
        if (empty())
            throw out_of_range("Pop front error: list is empty");
        Node* toDelete=head->next;
        head->next=toDelete->next;
        delete toDelete;
        _size--;
    }
    
    void pop_back() {
        if (empty())
            throw out_of_range("Pop back error: list is empty");

        Node* cur = head;
        // 遍历找到倒数第二个节点
        while (cur->next->next != nullptr)
            cur = cur->next;

        Node* tailNode = cur->next;
        cur->next = nullptr;
        delete tailNode;
        _size--;
    }

    size_t size() const { return _size; }
    bool empty() const { return _size == 0; }

    // 插入元素
    void insert(size_t pos, const T& val) {
        if (pos > _size) {
            throw out_of_range("Insert error: position out of range");
        }
        Node* newNode = new Node(val);
        Node* prev = head;
        for (size_t i = 0; i < pos; ++i)
            prev = prev->next;
        newNode->next = prev->next;
        prev->next = newNode;
        _size++;
    }

    // 删除元素
    void erase(size_t pos) {
        if (pos >= _size) {  // 有效位置是0到_size-1
            throw out_of_range("Erase error: position out of range");
        }
        Node* prev = head;
        for (size_t i = 0; i < pos; ++i)
            prev = prev->next;
        Node* toDelete = prev->next;
        prev->next = toDelete->next;
        delete toDelete;
        _size--;
    }

    // 重载[]运算符
    T& operator[](size_t pos) {
        if (pos >= _size)
            throw out_of_range("operator[] error: index out of range");
        // 从第一个实际节点开始遍历
        Node* cur = head->next;
        for (size_t i = 0; i < pos; ++i)
            cur = cur->next;
        return cur->val;
    }

    // 打印链表
    void print() const {
        Node* cur = head->next;
        while (cur != nullptr) {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }
};

int main() {
    try {
        myList1<int> list;
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
    