#include <stdio.h>
#include <stdlib.h>

int main(){
    int sparse1[5][6] = {
        {0 , 0 , 0 , 3 , 0, 0 },
        {0 , 1 , 0 , 4 , 0, 0 },
        {0 , 0 , 0 , 0 , 0, 2 },
        {1 , 0 , 3 , 0 , 0, 0 },
        {0 , 0 , 0 , 7 , 0, 0 }
    };

    int sparse2[5][6] = {
        {0 , 4 , 0 , 3 , 0, 0 },
        {0 , 0 , 0 , 0 , 0, 0 },
        {0 , 0 , 0 , 3 , 0, 0 },
        {0 , 6 , 0 , 0 , 0, 9 },
        {1 , 0 , 0 , 0 , 0, 0 }
    };

    int trip1[10][3]; 
    int con1 = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 6; j++) {
            if (sparse1[i][j] != 0) {
                trip1[con1][0] = i;
                trip1[con1][1] = j;
                trip1[con1][2] = sparse1[i][j];
                con1++;
            }
        }
    }

    int trip2[30][3];
    int con2 = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 6; j++) {
            if (sparse2[i][j] != 0) {
                trip2[con2][0] = i;
                trip2[con2][1] = j;
                trip2[con2][2] = sparse2[i][j];
                con2++;
            }
        }
    }

   
    int result[30][3];
    int res = 0;

    for (int i = 0; i < con1; i++) {
        int row1 = trip1[i][0];
        int col1 = trip1[i][1];
        int value1 = trip1[i][2];

        for (int j = 0; j < con2; j++) {
            int row2 = trip2[j][0];
            int col2 = trip2[j][1];
            int value2 = trip2[j][2];

            if (col1 == row2) {
                result[res][0] = row1;
                result[res][1] = col2;
                result[res][2] += value1 * value2;
                res++;
            }
        }
    }

    for (int i = 0; i < res; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
