#include <iostream>
#include <string>
#include "list.h"



int main(int argc, char ** argv){

    list Alex;

    Alex.addNode(28);
    Alex.addNode(27);
    Alex.addNode(26);
    Alex.addNode(25);

    Alex.printList();
    Alex.deleteNode(27);
    Alex.printList();

    Alex.insertFront(10);
    std::cout<<"-----\n";
    Alex.printList();
    std::cout<<Alex.listSize();

    std::cout<<"----\n";
    Alex.insertAtIndex(200,3);
    Alex.printList();
    Alex.deleteNode(200);
    Alex.printList();
    Alex.deleteList();
    Alex.printList();


    //-------------------// insert into the list using command line args 
    for(int i = 1; i < argc; i++){
        Alex.addNode(std::stoi(argv[i]));
    }

    Alex.printList();

    return 0;
}