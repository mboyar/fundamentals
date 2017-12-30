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

