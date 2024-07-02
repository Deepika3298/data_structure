#include <iostream>
#include <vector>

int main() {
    // Original vector
    std::vector<int> original_vector = {1, 2, 3};

    // Vector to be inserted
    std::vector<int> insert_vector = {4, 5, 6};

    // Insert the new vector elements at a specific position
    // Inserting at the end in this example
    original_vector.insert(original_vector.end(), insert_vector.begin(), insert_vector.end());

    // Print the resized vector with the new elements
    for (int val : original_vector) {
        std::cout << val << " ";
    }

    return 0;
}