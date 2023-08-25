#include <stdio.h>
#include <stdlib.h>

int main(){
    int sparse[5][6] = {
        {0 , 0 , 0 , 3 , 0, 0 },
        {0 , 1 , 0 , 4 , 0, 0 },
        {0 , 0 , 0 , 0 , 0, 2 },
        {1 , 0 , 3 , 0 , 0, 0 },
        {0 , 0 , 0 , 7 , 0, 0 }
    };

    
    int trans[6][5]; 

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 6; j++) {
            trans[j][i] = sparse[i][j]; 
        }
    }

    int sum = 0;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 5; j++) {
            if (trans[i][j] != 0) {
                sum++;
            }
        }
    }

    int s[sum][3];
    int k = 0;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 5; j++) {
            if (trans[i][j] != 0) {
                s[k][0] = i;
                s[k][1] = j;
                s[k][2] = trans[i][j];
                k++;
            }
        }
    }

 
    for (int i = 0; i < sum; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", s[i][j]);
        }
        printf("\n");
    }

    return 0;
}
