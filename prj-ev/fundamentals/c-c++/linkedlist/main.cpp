#include <iostream>

using namespace std;

struct linknode{

    int data;
    linknode *nextLink;
};

linknode *head;

void insertBegin(int x){

    linknode* temp = new linknode();
    temp->data = x;
    temp->nextLink = head;
    head = temp;
}

void printAll(){
    linknode* temp = head;
    cout << "List is: ";
    while(temp != NULL){
        cout << " " << temp->data;
        temp = temp->nextLink;
    }
    cout << endl;
}

int main()
{
    head = NULL;

//    linknode* temp = new linknode();
//    temp->data = 333;
//    temp->nextLink = NULL;

//    head = temp;

    int listCount, data;
    cout << "How many numbers: ";
    cin >> listCount;
    cout << endl;

    for(int i = 0; i < listCount; i++){

        cout << "Enter the number: ";
        cin >> data;
        insertBegin(data);
        printAll();
    }

    ///Traversal
//    linknode *temp1 = head;
//    while(temp1->nextLink != NULL){
//        temp1 = temp1->nextLink;
//    }
    ///

    return 0;
}

/// Thx to youtube channel "mycodeschool"
