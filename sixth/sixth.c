#include "linkedlist.h"
#include<stdio.h> 
#include<stdlib.h> 
#define _GNU_SOURCE

struct treeNode{ 
    int key; 
    struct treeNode* left;
    struct treeNode* right; 
};
typedef struct treeNode tree_node;

void inorder(tree_node* root); 
tree_node* insert(tree_node* node, int key);

int main(int argc, char *argv[]) {
    FILE* fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    //int value;
    //char letter[1];

    //checks if the file doesn't exist or it is blank
    fp = fopen(argv[1], "r");
    if(fp == NULL){
         printf("error");
         return 0;
    }
    if (NULL != fp){
        fseek(fp, 0, SEEK_END);
        int size = ftell(fp);
        if(size == 0){ 
            printf("0\n");
            exit(EXIT_FAILURE);
        }
    }
    
    fp = fopen(argv[1], "r");
    tree_node* root = NULL;

    //loops through each line
    //int count = 0;
    while ((read = getline(&line, &len, fp)) != -1) {
        int size = sizeof(line)/sizeof(line[0]);
        char number[size];
        arrayCopy(line, number, 2, size);
        int num = atoi(number);

        root = insert(root, num);
    }
    inorder(root);
    free(line);
    exit(EXIT_SUCCESS);
    return 0;
}

//inorder traversal
void inorder(tree_node* root){ 
    if (root != NULL) { 
        inorder(root->left);
        printf("%d\t", root->key);
        inorder(root->right); 
    } 
} 

//insert node
tree_node* insert(tree_node* node, int key){ 
    tree_node* temp =  (tree_node*)malloc(sizeof(tree_node)); 
    temp->key = key; 
    temp->left = NULL;
    temp->right = NULL;

    if (node == NULL) 
        return temp; 
    if (key < node->key) 
        node->left  = insert(node->left, key); 
    else if (key > node->key) 
        node->right = insert(node->right, key);    
    return node; 
}