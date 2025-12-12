#include <stdio.h>
#include "vector/c_vector.h"

void print_vector(Vector *vec) {
    printf("  Vector: [");
    for (int i = 0; i < current_size(vec); i++) {
        printf("%d", get_value_at_index(vec, i));
        if (i < current_size(vec) - 1) {
            printf(", ");
        }
    }
    printf("], Size: %d, Capacity: %d\n", current_size(vec), current_capacity(vec));
}

int main() {
    printf("--- Vector Module Demo ---\n\n");

    Vector *vec = create_vector(2);

    // 1. Console output demonstrating push_back() and automatic resizing
    printf("1. Add at End and Automatic Resizing:\n\n");
    print_vector(vec);
    for (int i = 0; i < 5; i++) {
        add_at_end(vec, i * 10);
        printf("  Adding %d: ", i * 10);
        print_vector(vec);
    }
    printf("\n");

    // 2. Example showing get() and set() operations on elements
    printf("2. Get and Set Operations:\n\n");
    printf("  Getting element at index 3: %d\n", get_value_at_index(vec, 3));
    printf("  Setting element at index 3 to 99\n");
    set_at_index(vec, 3, 99);
    printf("  Getting element at index 3: %d\n\n", get_value_at_index(vec, 3));
    print_vector(vec);

    destroy_vector(vec);

    return 0;
}
