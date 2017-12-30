#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;


/// ======================================================

/// given a structure definition of a link list member, such as:

typedef struct _linknode {
    float val;
    struct _linknode * next;
}  linknode ;

/// please write a C function, which takes a HEAD pointer to a link list made up of the above structure instances,
/// and a new float value a,
/// and goes through the link list, finds the link list members that the value falls in between
/// ( link linst member x.val <= a <= link list member y.val ).
/// Then the function should create a new link list member instance, and add it in between those two elements

int insertListMember(linknode **ptrHead, float a){

    if(*ptrHead == NULL){

        *ptrHead = (linknode *)malloc(sizeof(linknode));

        (*ptrHead)->val = a;
        (*ptrHead)->next = NULL;
        return 1;
    }

    linknode* temp1 = (linknode*)malloc(sizeof(linknode));

    if(temp1 == NULL){

        printf("Buffer cannot be allocated\n");
        return -1;
    }

    temp1->val = a;
    temp1->next = NULL;

    linknode* temp2 = *ptrHead;
    linknode* temp3 = temp2->next;

    while(temp3 != NULL){

        if (temp2->val <= temp1->val && temp1->val <= temp3->val){

            temp2->next = temp1;
            temp1->next = temp3;
            break;
        }

        temp2 = temp2->next;
        temp3 = temp3->next;
    }

    if(temp3 == NULL){

        printf("Case: Out of homework scope\n");
        return -2;
    }

    return 0;
}

//int insertListMember(linknode *head, float a){

//    if(head == NULL){

//        head = (linknode *)malloc(sizeof(linknode));

//        head->val = a;
//        head->next = NULL;
//        return 1;
//    }

//    linknode* temp1 = (linknode*)malloc(sizeof(linknode));

//    if(temp1 == NULL){

//        printf("Buffer cannot be allocated\n");
//        return -1;
//    }

//    temp1->val = a;
//    temp1->next = NULL;

//    linknode* temp2 = head;
//    while(temp2 != NULL){
//        linknode* temp3 = temp2->next;

//        if (temp2->val <= temp1->val && temp1->val <= temp3->val){

//            temp2->next = temp1;
//            temp1->next = temp3;
//            break;
//        }

//        temp2 = temp2->next;
//    }

//    return 0;
//}

linknode* insertBegin(linknode* m_head, float x){

    linknode* temp = new linknode();
    temp->val = x;
    temp->next = m_head;
    m_head = temp;

    return m_head;
}

void printAll(linknode* p_head){
    linknode* temp = p_head;
    cout << "List is: ";
    while(temp != NULL){
        cout << " " << temp->val;
        temp = temp->next;
    }
    cout << endl;
}

void printUsage(char* arg0){

    printf("Usage: %s [--readylist|--manuallist]\n", arg0);
}

int main(int argc, char **argv){

    if (argc != 2){
        printUsage(argv[0]);
        return -1;
    }

    linknode* head = NULL;

    if (strcmp(argv[1], "--readylist") == 0){

        head = insertBegin(head, 7.2);
        head = insertBegin(head, 2.3);
        head = insertBegin(head, 1.5);

        printAll(head);
    }
    else if(strcmp(argv[1], "--manuallist") == 0){

        int listCount;
        float data;
        cout << "How many numbers: ";
        cin >> listCount;
        cout << endl;

        for(int i = 0; i < listCount; i++){

            cout << "Enter the number: ";
            cin >> data;
            head = insertBegin(head, data);
            printAll(head);
        }
    }
    else{

        printUsage(argv[0]);
        return -1;
    }


    while(1){

        ///
        float insertValue;
        cout << "Give insert number: ";
        cin >> insertValue;
        cout << endl;

        insertListMember(&head, insertValue);
        cout << "After insert n.th element: " << endl;
        printAll(head);
    }

    return 0;
}
