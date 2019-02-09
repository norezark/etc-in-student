#include <stdio.h>

#define COLUMN 3
#define ROW 3

int main(void){
    int i, j, gain[COLUMN][ROW], min[ROW], max[COLUMN], minx, maxn;

    for(i=0; i<COLUMN; i++){
        for(j=0; j<ROW; j++){
            scanf(" %d", &gain[i][j]);
        }
    }

    for(i=0; i<COLUMN; i++){
        min[i] = gain[i][0];
        for(j=1; j<ROW; j++){
            if(min[i] > gain[i][j]) min[i] = gain[i][j];
        }
    }

    for(i=0; i<ROW; i++){
        max[i] = gain[0][i];
        for(j=1; j<COLUMN; j++){
            if(max[i] < gain[j][i]) max[i] = gain[j][i];
        }
    }

    minx = min[0];
    for(i=1; i<COLUMN; i++){
        if(minx < min[i]) minx = min[i];
    }

    maxn = max[0];
    for(i=1; i<ROW; i++){
        if(maxn > max[i]) maxn = max[i];
    }

    for(i=0; i<COLUMN; i++){
        for(j=0; j<ROW; j++){
            if(gain[i][j] == minx && gain[i][j] == maxn && minx == min[i] && maxn == max[j]){
                printf("サドル点 ; %d行目 %d列目 値 %d\n", i+1, j+1, gain[i][j]);
            }
        }
    }

    return 0;
}
