#include <stdio.h>
#include "bst/binary_search_tree.h"

// Forward declarations for traversal functions (not in header)
void inorder_traversal(Node *root);
void preorder_traversal(Node *root);
void postorder_traversal(Node *root);

int main() {
    printf("--- BST Module Demo ---\n\n");

    // 1. Diagram of a sample BST
    printf("1. Sample BST Diagram:\n\n");
    printf("    Root: 50\n");
    printf("    Structure:\n\n");
    printf("          50\n");
    printf("         /  \\\n");
    printf("       30    70\n");
    printf("      / \\   / \\\n");
    printf("    20  40 60  80\n\n");

    // Create the BST
    Node *root = NULL;
    root = binary_insert(root, 50);
    binary_insert(root, 30);
    binary_insert(root, 20);
    binary_insert(root, 40);
    binary_insert(root, 70);
    binary_insert(root, 60);
    binary_insert(root, 80);

    // 2. Console output of inorder traversal
    printf("2. Inorder Traversal (Sorted Order):\n\n");
    printf("  ");
    inorder_traversal(root);
    printf("\n\n");

    // 3. Console output of preorder and postorder traversals
    printf("3. Preorder and Postorder Traversals:\n\n");
    printf("  Preorder: ");
    preorder_traversal(root);
    printf("\n");
    printf("  Postorder: ");
    postorder_traversal(root);
    printf("\n\n");

    destroy_binary_search_tree(root);

    return 0;
}

// Traversal function implementations (not in library source)
void inorder_traversal(Node *root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->value);
        inorder_traversal(root->right);
    }
}

void preorder_traversal(Node *root) {
    if (root != NULL) {
        printf("%d ", root->value);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

void postorder_traversal(Node *root) {
    if (root != NULL) {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf("%d ", root->value);
    }
}
