#include <stdio.h>
#include <stdlib.h>

int main() {
    int sparse1[5][6] = {
        {0, 0, 0, 3, 0, 0},
        {0, 1, 0, 4, 0, 0},
        {0, 0, 0, 0, 0, 2},
        {1, 0, 3, 0, 0, 0},
        {0, 0, 0, 7, 0, 0}
    };

    int sparse2[5][6] = {
        {1, 0, 0, 0, 5, 0},
        {0, 0, 6, 0, 0, 0},
        {0, 2, 0, 0, 0, 0},
        {0, 0, 0, 7, 0, 0},
        {3, 0, 0, 0, 9, 0}
    };

    int trip1[30][3]; // Initialize an array to store triplet representation of sparse1
    int con1 = 0; // Initialize a counter for the number of non-zero elements in sparse1

    // Convert sparse1 into triplet format
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 6; j++) {
            if (sparse1[i][j] != 0) {
                trip1[con1][0] = i; // Row index
                trip1[con1][1] = j; // Column index
                trip1[con1][2] = sparse1[i][j]; // Value
                con1++;
            }
        }
    }

    int trip2[30][3]; // Initialize an array to store triplet representation of sparse2
    int con2 = 0; // Initialize a counter for the number of non-zero elements in sparse2

    // Convert sparse2 into triplet format
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 6; j++) {
            if (sparse2[i][j] != 0) {
                trip2[con2][0] = i; // Row index
                trip2[con2][1] = j; // Column index
                trip2[con2][2] = sparse2[i][j]; // Value
                con2++;
            }
        }
    }

    int res[10][3]; // Initialize an array to store the result of addition
    int final = 0; // Initialize a counter for the number of non-zero elements in the result

    // Add corresponding elements from trip1 and trip2 into res
    for (int i = 0; i < con1; i++) {
        res[final][0] = trip1[i][0]; // Row index
        res[final][1] = trip1[i][1]; // Column index
        res[final][2] = trip1[i][2] + trip2[i][2]; // Sum of values
        final++;
    }

    // Print the result in triplet format
    for (int i = 0; i < final; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }

    return 0;
}
