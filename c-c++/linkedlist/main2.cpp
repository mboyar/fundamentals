#include <iostream>

using namespace std;

struct linknode{

    int data;
    linknode *nextLink;
};

linknode* insertBegin(linknode* m_head, int x){

    linknode* temp = new linknode();
    temp->data = x;
    temp->nextLink = m_head;
    m_head = temp;

    return m_head;
}

void printAll(linknode* p_head){
    linknode* temp = p_head;
    cout << "List is: ";
    while(temp != NULL){
        cout << " " << temp->data;
        temp = temp->nextLink;
    }
    cout << endl;
}

int main()
{
    linknode* head = NULL;

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
        head = insertBegin(head, data);
        printAll(head);
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
