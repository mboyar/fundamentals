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

void insertListMember(linknode* head, float a){

    linknode* temp1 = (linknode*)malloc(sizeof(linknode*));
    temp1->val = a;
    temp1->next = NULL;

    linknode* temp2 = head;
    int i = 0;
    int n = 0;
    while(temp2 != NULL){
        linknode* temp3 = temp2->next;

        if (temp2->val <= temp1->val && temp1->val <= temp3->val){

            temp2->next = temp1;
            temp1->next = temp3;
            break;
        }

        i++;
        temp2 = temp2->next;
    }
}
