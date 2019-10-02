#include "linkedlist.h"

void arrayCopy(char* sourceArray, char* destArray, int start, int end) { 
    int i = 0;
    while (start < end){
        destArray[i] = sourceArray[start];
        i++;
        start++;
    }
}

node_t* push(int value, node_t* head){

    node_t *result = malloc(sizeof(node_t));
    result->value = value;
    result->next = NULL;
    result->prev = NULL;
    //blank value = 4
    //8      :   value - 8
    //1 6    :   1 - value - 6
    //1 3    :   1 - 3 - value
    //1 4 5  :   1 - value - 4 - 5

    // No linked list exists yet -> create & return head
    if(head==NULL){
        return result;
    }
    // replacing head 
    if (value <= head->value) {
        result->next = head;
        head->prev = result;
        return result;
    }
    // head is initialized
    node_t* temp = head;
    while(temp!= NULL) {
        // push stuff
        if(temp->value < value && temp->next== NULL){
            temp->next = result;
            result->prev = temp;
            return head;
        }
        if(temp->value < value && temp->next->value >= value){
            result->next = temp->next;
            temp->next = result;
            result->prev = temp;
            return head;
        }
        else {
            temp = temp->next; 
        }
    }
    return head;
    
}

node_t* delete(int value, node_t* head){
    // blank                : ignore
    // 1(value)             : blank
    // 1 - 2(value) - 3     : 1 - 3
    // 1 - 2(value) -2 - 3  : 1 - 2 - 3
    if(head==NULL){
        return head;
    }
    //node_t* temp = head;
    node_t* toBeDeleted = getNode(value, head);

    if (toBeDeleted==NULL) {
        return head;
    }
    
    if(toBeDeleted == head){
        head = head->next;
        return head;
    }
    if (toBeDeleted->next==NULL) {
        toBeDeleted->prev->next = NULL;
        return head;
    }
    toBeDeleted->prev->next = toBeDeleted->next;
     return head;
}

void printlist(node_t* head){
    node_t *temp = head;
    while(temp != NULL){
        printf("%d  ", temp->value);
        temp = temp->next;
    }
}

node_t* getNode(int value, node_t* head) {
    // find value in LL
    node_t* temp = head;
    while(temp!= NULL) {
        if (temp->value==value) {
            return temp;
        }
        temp = temp->next; 
    }
    return NULL;
}

void uniqueNum(node_t* head){
    //traverses the linked list and prints: if the previously printed number is the same as the current, skip
    int prev;
    node_t* temp = head;
    while(temp!= NULL) {
        if(prev != temp->value){
            if(temp->next==NULL)
                printf("%d", temp->value);
            else
                printf("%d\t", temp->value);
        }
        prev = temp->value;
        temp = temp->next; 
    }
}
 








 