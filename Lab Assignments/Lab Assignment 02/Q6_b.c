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
        {1 , 0 , 0 , 0 , 5, 0 },
        {0 , 0 , 6 , 0 , 0, 0 },
        {0 , 2 , 0 , 0 , 0, 0 },
        {0 , 0 , 0 , 7 , 0, 0 },
        {3 , 0 , 0 , 0 , 9, 0 }
    };

    int trip1[30][3]; 
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

    int res[10][3];
    int final = 0;

    for (int i = 0; i < con1; i++) {
        res[final][0] = trip1[i][0];
        res[final][1] = trip1[i][1];
        res[final][2] = trip1[i][2] + trip2[i][2]; 
        final++;
    }


    for (int i = 0; i < final; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }

    return 0;
}
