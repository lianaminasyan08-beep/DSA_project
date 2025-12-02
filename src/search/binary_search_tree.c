#include "binary_search_tree.h"
#include <stdio.h>
#include <stdlib.h>

Node *create_node(int value){
    if (value == NULL) return NULL;

    Node *node = malloc(sizeof(Node));

    if (node == NULL) return NULL;
    node->value = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

Node *binary_insert(Node *root, int value){
    if (root == NULL && value != NULL){
        Node *new_node = create_node(value);

        if (new_node == NULL) return NULL; // free(new_node) should i write it or not?

        return new_node;
    }


    Node *current = root;
    Node *parent = NULL;

    while (current != NULL){
        parent = current;

        if (value < current->value) // or it should be <=?
            current = current->left;
        else
            current = current->right; 
    }

    Node *newNode = create_node(value);

    if (newNode == NULL) return NULL;

    if (value < parent->value)
        parent->left = newNode;
    else
        parent->right = newNode;

    return newNode; // or i should return integer (1 or 0)??
}

Node *binary_search(Node *root, int target){
    if (root == NULL) return NULL;

    Node *current = root;

    while (current != NULL){
        if (current->value == target) return current;

        if (target > current->value){
            current = current->right;
        }
        else{
            current = current->left;
        }
    }

    return NULL; // maybe it should return integer
}

Node *binary_search_recursive(Node *root, int target){
    if (root == NULL) return NULL;

    if (target == root->value) return root;

    if (target > root->value) {
        return binary_search_recursive(root->right, target);
    }
    else{
        return binary_search_recursive(root->left, target);
    }
}