

struct Listnode{
    int data;
    Listnode* next;

    Listnode() : data(0), next(nullptr){}
    Listnode(int x) : data(x), next(nullptr){}
    Listnode(int x, Listnode* next) : data(x),next(next){}
};


class Linkedlist{
    
    private:
    Listnode* head = nullptr;
    int size = 0;

    public:

    Linkedlist() :head(nullptr), size(0){};

    void insertAtHead(int data);
    void insertAtTail(int data);
    void insertAtIndex(int data, int index);
    void deleteNode(int delData);
    void printList();

    ~Linkedlist();


};