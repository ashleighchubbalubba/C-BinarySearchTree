#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define _GNU_SOURCE

struct node{
    int value;
    struct node* next;
    struct node* prev;
};
typedef struct node node_t;

void arrayCopy(char* sourceArray, char* destArray, int start, int end);
void printlist(node_t* head);
node_t* push(int value, node_t* head);
node_t* delete(int value, node_t* head);
node_t* getNode(int value, node_t* head);
void uniqueNum(node_t* head);
