#include "binary_search_tree.h"
#include <stdio.h>
#include <assert.h>

void test_create_node() {
    printf("Testing create_node...\n");
    
    // Test normal creation
    Node *node1 = create_node(10);
    assert(node1 != NULL);
    assert(node1->value == 10);
    assert(node1->left == NULL);
    assert(node1->right == NULL);
    printf("✓ Created node with value 10\n");
    
    // Test invalid value (commented out as value is int, not pointer)
    // Node *node2 = create_node(NULL);
    // assert(node2 == NULL);
    // printf("✓ NULL value returns NULL\n");
    
    free(node1);
}

void test_binary_insert() {
    printf("\nTesting binary_insert...\n");
    
    // Test 1: Insert into empty tree
    Node *root = NULL;
    root = binary_insert(root, 50);
    assert(root != NULL);
    assert(root->value == 50);
    printf("✓ Created root with value 50\n");
    
    // Test 2: Insert smaller value
    Node *left_child = binary_insert(root, 30);
    assert(left_child != NULL);
    assert(root->left != NULL);
    assert(root->left->value == 30);
    printf("✓ Inserted 30 (left child of 50)\n");
    
    // Test 3: Insert larger value
    Node *right_child = binary_insert(root, 70);
    assert(right_child != NULL);
    assert(root->right != NULL);
    assert(root->right->value == 70);
    printf("✓ Inserted 70 (right child of 50)\n");
    
    // Test 4: Insert more values to build tree
    binary_insert(root, 20);
    binary_insert(root, 40);
    binary_insert(root, 60);
    binary_insert(root, 80);
    
    // Verify tree structure
    assert(root->left->left->value == 20);
    assert(root->left->right->value == 40);
    assert(root->right->left->value == 60);
    assert(root->right->right->value == 80);
    printf("✓ Built complete tree structure\n");
    
    // Test 5: Insert duplicate value (goes to right)
    Node *dup = binary_insert(root, 40);
    assert(dup != NULL);
    assert(root->left->right->right != NULL);
    assert(root->left->right->right->value == 40);
    printf("✓ Duplicate value 40 inserted to right\n");
    
    // Cleanup (in real implementation, you'd need a free_tree function)
    printf("Note: Memory cleanup needed after tests\n");
}

void test_binary_search() {
    printf("\nTesting binary_search (iterative)...\n");
    
    // Build a test tree
    Node *root = create_node(50);
    binary_insert(root, 30);
    binary_insert(root, 70);
    binary_insert(root, 20);
    binary_insert(root, 40);
    binary_insert(root, 60);
    binary_insert(root, 80);
    
    // Test 1: Search for existing values
    Node *found = binary_search(root, 50);
    assert(found != NULL);
    assert(found->value == 50);
    printf("✓ Found root value 50\n");
    
    found = binary_search(root, 20);
    assert(found != NULL);
    assert(found->value == 20);
    printf("✓ Found leaf value 20\n");
    
    found = binary_search(root, 40);
    assert(found != NULL);
    assert(found->value == 40);
    printf("✓ Found internal value 40\n");
    
    // Test 2: Search for non-existing values
    found = binary_search(root, 25);
    assert(found == NULL);
    printf("✓ Correctly returned NULL for non-existing value 25\n");
    
    found = binary_search(root, 100);
    assert(found == NULL);
    printf("✓ Correctly returned NULL for non-existing value 100\n");
    
    // Test 3: Search in empty tree
    Node *empty_root = NULL;
    found = binary_search(empty_root, 10);
    assert(found == NULL);
    printf("✓ Correctly returned NULL for empty tree\n");
}

void test_binary_search_recursive() {
    printf("\nTesting binary_search_recursive...\n");
    
    // Build a test tree
    Node *root = create_node(50);
    binary_insert(root, 30);
    binary_insert(root, 70);
    binary_insert(root, 20);
    binary_insert(root, 40);
    binary_insert(root, 60);
    binary_insert(root, 80);
    
    // Test 1: Search for existing values
    Node *found = binary_search_recursive(root, 50);
    assert(found != NULL);
    assert(found->value == 50);
    printf("✓ Found root value 50\n");
    
    found = binary_search_recursive(root, 20);
    assert(found != NULL);
    assert(found->value == 20);
    printf("✓ Found leaf value 20\n");
    
    found = binary_search_recursive(root, 40);
    assert(found != NULL);
    assert(found->value == 40);
    printf("✓ Found internal value 40\n");
    
    // Test 2: Search for non-existing values
    found = binary_search_recursive(root, 25);
    assert(found == NULL);
    printf("✓ Correctly returned NULL for non-existing value 25\n");
    
    found = binary_search_recursive(root, 100);
    assert(found == NULL);
    printf("✓ Correctly returned NULL for non-existing value 100\n");
    
    // Test 3: Search in empty tree
    Node *empty_root = NULL;
    found = binary_search_recursive(empty_root, 10);
    assert(found == NULL);
    printf("✓ Correctly returned NULL for empty tree\n");
}

void test_edge_cases() {
    printf("\nTesting edge cases...\n");
    
    // Test 1: Very unbalanced tree (all right)
    Node *root1 = create_node(10);
    for (int i = 20; i <= 100; i += 10) {
        binary_insert(root1, i);
    }
    
    Node *found = binary_search(root1, 100);
    assert(found != NULL && found->value == 100);
    printf("✓ Found value in right-skewed tree\n");
    
    // Test 2: Very unbalanced tree (all left)
    Node *root2 = create_node(100);
    for (int i = 90; i >= 10; i -= 10) {
        binary_insert(root2, i);
    }
    
    found = binary_search(root2, 10);
    assert(found != NULL && found->value == 10);
    printf("✓ Found value in left-skewed tree\n");
    
    // Test 3: Single node tree
    Node *single = create_node(5);
    found = binary_search(single, 5);
    assert(found != NULL && found->value == 5);
    found = binary_search(single, 10);
    assert(found == NULL);
    printf("✓ Single node tree works correctly\n");
}

void test_comprehensive() {
    printf("\nRunning comprehensive test...\n");
    
    Node *root = NULL;
    
    // Insert random values
    int values[] = {50, 25, 75, 15, 35, 65, 85, 10, 20, 30, 40, 60, 70, 80, 90};
    int count = sizeof(values) / sizeof(values[0]);
    
    for (int i = 0; i < count; i++) {
        Node *result = binary_insert(root, values[i]);
        if (i == 0) {
            root = result; // First insertion returns new root
        }
        assert(result != NULL);
    }
    
    printf("✓ Inserted %d values\n", count);
    
    // Verify all values can be found
    for (int i = 0; i < count; i++) {
        Node *found = binary_search(root, values[i]);
        assert(found != NULL);
        assert(found->value == values[i]);
    }
    printf("✓ All values can be found with iterative search\n");
    
    // Verify with recursive search
    for (int i = 0; i < count; i++) {
        Node *found = binary_search_recursive(root, values[i]);
        assert(found != NULL);
        assert(found->value == values[i]);
    }
    printf("✓ All values can be found with recursive search\n");
    
    // Test non-existing values
    int non_existing[] = {5, 55, 95, 100, -5};
    for (int i = 0; i < 5; i++) {
        Node *found = binary_search(root, non_existing[i]);
        assert(found == NULL);
    }
    printf("✓ Non-existing values correctly return NULL\n");
}

int main() {
    printf("=== Binary Search Tree Test Suite ===\n\n");
    
    test_create_node();
    test_binary_insert();
    test_binary_search();
    test_binary_search_recursive();
    test_edge_cases();
    test_comprehensive();
    
    printf("\n=== All tests passed! ===\n");
    
    return 0;
}