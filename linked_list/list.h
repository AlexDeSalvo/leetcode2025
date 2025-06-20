

class list{
    private: //Data that functions access go here

    typedef struct node{
        int data; //stores data of each node 
        node* next; //pointer to next node 

    } *nodeptr;

    int size;
    nodeptr head; //pointer to top of list
    nodeptr curr; //pointer to curr node
    nodeptr temp;

    public: //Function prototypes go here
    
    //constructor function
    list();

    void addNode(int addData); //adds da,ta
    void insertFront(int addData);//inserts data at front
    void insertAtIndex(int addData,int index);//inserts data at given position
    void deleteNode(int delData); //deletes node
    void printList();//prints the list
    int listSize();//returns the size of list
    void deleteList();//deletes the entire list




};