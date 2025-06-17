#include <cstdlib>
#include <iostream>
#include "list.h"


using namespace std; 

//define private data members
list::list(){
    head = nullptr;//points to start of linked list
    curr = nullptr;
    temp = nullptr;
    size = 0;
}

void list::addNode(int addData){
    //node pointer defined in list.h
    nodeptr n = new node;
    n->next = nullptr;//last element in list points to nothing 
    n->data = addData;// whatever we pass into the function is what will be in the node
    size++;
    //if the head is not pointing to null then we have a list
    if(head != nullptr){
        curr = head;
        //advances current pointer until it hits last node in list
        while(curr->next != nullptr){
            curr = curr->next; //current pointer points to next node in list
        }
        //once we reach last node, our curr pointer
        //points to the last node in the list
        curr->next = n;
        //if we dont have a list then n will be the head
    }else{
        head = n;
    }

}

void list::deleteNode(int delData){
    //deletion pointer points to nothing to start
    nodeptr delptr = nullptr;
    temp = head;
    curr = head;

    //if curr = null then we traversed the whole list 
    //while the data in current pointer does not equal our target delete data
    while(curr != nullptr && curr->data != delData){
        //temp points to the node we were just at
        temp = curr;
        //current points to the next
        //**important distiction is that the temp is pointing to the current then the current
        //is assigned to the next node */
        //makes it so the temp pointer is always trailing behind//
        curr = curr->next;
    }
    //passed through the list and didnt find the value
    if(curr == nullptr){
        cout<<delData<<" was not in the list \n";
        delete delptr;
    }
    else if(curr == head){
        delptr = curr;
        head = head->next;
        delete delptr;
        size--;
    }
    //when the target node is found the del
    else{
        //delete pointer is at current
        delptr = curr;
        //current assigns to next
        curr = curr->next;
        //temp.next assigns to current
        temp->next = curr;
        //this patches the gap after the delete

        delete delptr;
        size--;
        cout<<"The value "<<delData<<" was deleted\n";
    }

}

void list::insertFront(int addData){
    nodeptr n = new node;
    temp = head;
    n->next = temp;
    n->data = addData;
    size++;

    head = n;


}

void list::printList(){
    
    if(head == nullptr){
        cout<<"There is no list\n";
    }

    curr = head;
    
    while(curr!= nullptr){
        cout<<curr->data<<"\n";
        curr = curr->next;
    }


}

int list::listSize(){
    return size;
}

void list::insertAtIndex(int addData,int index){
    


    if(index < 0 || index > size){
        cout<<"Out of bounds index \n";
    }
    
    //if the index is 0 call the insert at front function 
    if(index == 0){
        insertFront(addData);
        return;
    }

    int counter = 0;
    //if not create new node 
    nodeptr n = new node;
    //set curr to the head
    curr = head;
    //traverse the list until we hit the index -1

    while(curr != nullptr && counter != index - 1){
        curr = curr->next;
        counter++;
    }
    //if we traverse all the way to the end without inserting we delete the node and return
    if(curr == nullptr){
        delete n;
        cout<<"Reached end of list without inserting\n";
        return;
    }

   n->data = addData;
   n->next = curr->next;
   curr->next = n;
   size++;

}

void list::deleteList(){
    curr = head;
    while(curr != nullptr){
        temp = curr;
        curr = curr->next;
        delete temp;
    }

    head = nullptr;
    size = 0;
    cout<<"The list has been deleted\n";
}


