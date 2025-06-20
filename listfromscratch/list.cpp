#include <iostream>
#include "list.h"


void Linkedlist::insertAtHead(int data){

    Listnode* newNode = new Listnode(data);

    if(!head){
        head = newNode;
    }else{
        newNode->next = head;
        head = newNode;
    }

    size++;
}


void Linkedlist::insertAtTail(int data){
    Listnode* newNode = new Listnode(data);

    if(!head){
        head = newNode;
        size++;
        return;
    }

    Listnode* curr = head;

    while(curr->next){
        curr = curr->next;
    }

    curr->next = newNode;
    size++;


}

void Linkedlist::deleteNode(int delData){

    if(!head) return; // list doesnt exist 

    

    Listnode* prev = head;
    Listnode* curr = head;

    if(curr->data == delData){
        head = head->next;
        delete curr;
        size--;
        return;
    }

    //while we arent at null at the data doesnt match keep traversing
    while(curr != nullptr && curr->data != delData){
        prev = curr;
        curr = curr->next;
    }

    //if we reach null no node found
    if(!curr){
        std::cout<<"Node not found\n";
    }

    //if we found our data and its at the end
    //that means curr->next points to null 
    //we set prev next to point to curr next making it the end
    //then delete curr.

    prev->next = curr->next;
    delete curr;
    size--;


}

void Linkedlist::printList(){

    if(!head) return; //no list

    Listnode* curr = head;
    while(curr){
        std::cout<<curr->data<<"\n";
        curr = curr->next;
    }


}

void Linkedlist::insertAtIndex(int data, int index){

    Listnode* newNode = new Listnode(data);

    if(index < 0 || index > size){
        std::cout<<"Out of bounds index\n";
        return;
    }

    if(index == 0){

        newNode->next = head;
        head = newNode;
        size++;
        return;
    }

    Listnode* curr = head;
    int counter = 0;

    while(curr && counter != index - 1){
        curr = curr->next;
        counter++;
    }


    newNode->next = curr->next;
    curr->next = newNode;

    size++;


}

Linkedlist::~Linkedlist(){
    Listnode* curr = head;

    while(curr){
        Listnode* tail = curr->next;
        delete curr;
        curr = tail;
    }

    head = nullptr;
    size = 0;

}
