#include "binary_search_tree.h"
#include <stdio.h>

// Helper function to print tree (in-order traversal)
void print_in_order(Node *root) {
    if (root == NULL) return;
    
    print_in_order(root->left);
    printf("%d ", root->value);
    print_in_order(root->right);
}

// Helper function to print tree (pre-order traversal)
void print_pre_order(Node *root) {
    if (root == NULL) return;
    
    printf("%d ", root->value);
    print_pre_order(root->left);
    print_pre_order(root->right);
}

// Helper function to free tree memory
void free_tree(Node *root) {
    if (root == NULL) return;
    
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

int main() {
    printf("=== Binary Search Tree Example Usage ===\n\n");
    
    // Example 1: Create and populate a BST
    printf("Example 1: Creating and populating a BST\n");
    Node *root = NULL;
    
    // Insert values
    int values[] = {50, 30, 70, 20, 40, 60, 80, 15, 25, 35, 45};
    int n = sizeof(values) / sizeof(values[0]);
    
    printf("Inserting values: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", values[i]);
        if (i == 0) {
            root = binary_insert(root, values[i]);
        } else {
            binary_insert(root, values[i]);
        }
    }
    printf("\n");
    
    // Display tree
    printf("In-order traversal (sorted): ");
    print_in_order(root);
    printf("\n");
    
    printf("Pre-order traversal: ");
    print_pre_order(root);
    printf("\n\n");
    
    // Example 2: Searching for values
    printf("Example 2: Searching for values\n");
    int search_values[] = {40, 25, 90, 50};
    
    for (int i = 0; i < 4; i++) {
        int target = search_values[i];
        Node *result_iterative = binary_search(root, target);
        Node *result_recursive = binary_search_recursive(root, target);
        
        printf("Searching for %d:\n", target);
        printf("  Iterative: %s\n", result_iterative ? "FOUND" : "NOT FOUND");
        printf("  Recursive: %s\n", result_recursive ? "FOUND" : "NOT FOUND");
        
        if (result_iterative && result_recursive) {
            printf("  Both methods agree: value = %d\n", result_iterative->value);
        }
        printf("\n");
    }
    
    // Example 3: Creating a BST from user input
    printf("Example 3: Building BST from scratch\n");
    Node *custom_root = NULL;
    
    // Simulate user input
    int user_values[] = {100, 50, 150, 25, 75, 125, 175};
    int m = sizeof(user_values) / sizeof(user_values[0]);
    
    printf("Building tree with values: ");
    for (int i = 0; i < m; i++) {
        printf("%d ", user_values[i]);
        if (i == 0) {
            custom_root = create_node(user_values[i]);
        } else {
            binary_insert(custom_root, user_values[i]);
        }
    }
    printf("\n");
    
    printf("Resulting tree (in-order): ");
    print_in_order(custom_root);
    printf("\n");
    
    // Test edge cases
    printf("\nExample 4: Edge cases\n");
    Node *single = create_node(42);
    printf("Single node tree search for 42: %s\n", 
           binary_search(single, 42) ? "FOUND" : "NOT FOUND");
    printf("Single node tree search for 99: %s\n", 
           binary_search(single, 99) ? "FOUND" : "NOT FOUND");
    
    // Cleanup
    free_tree(root);
    free_tree(custom_root);
    free_tree(single);
    
    printf("\n=== Example completed successfully ===\n");
    
    return 0;
}