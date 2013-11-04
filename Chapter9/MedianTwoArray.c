#include <stdio.h>
#include <stdlib.h>

int MedianTwoArray(int *px, int xleft, int xright,
                   int *py, int yleft, int yright){
    if(xleft == xright && yleft == yright)
        return px[xleft] < py[yleft] ? px[xleft] : py[yleft];
    int xmid = (xleft + xright)/2;
    int ymid = (yleft + yright)/2;
    if(px[xmid] == py[ymid])
        return px[xmid];
    else if(px[xmid] > py[ymid]){
        if((xright-xleft+1)%2)
            return MedianTwoArray(px, xleft, xmid, py, ymid, yright);
        else
            return MedianTwoArray(px, xleft, xmid, py, ymid+1, yright);
        }
    else{
        if((xright-xleft+1)%2)
            return MedianTwoArray(px, xmid, xright, py, yleft, ymid);
        else
            return MedianTwoArray(px, xmid+1, xright, py, yleft, ymid);
    }
}
int main(int argc, char *argv[]){
    FILE *pfid1 = fopen(argv[1], "r");
    FILE *pfid2 = fopen(argv[2], "r");
    int length1, length2;
    fscanf(pfid1, "%d", &length1);
    fscanf(pfid2, "%d", &length2);
    int *px = (int *)malloc(sizeof(int)*length1);
    int *py = (int *)malloc(sizeof(int)*length2);
    for(int i = 0; i < length1; i++)
        fscanf(pfid1, "%d", px+i);
    for(int i = 0; i < length2; i++)
        fscanf(pfid2, "%d", py+i);

    printf("Median: %d\n", MedianTwoArray(px, 0, length1-1, py, 0, length2-1));

    free(px);
    free(py);
    fclose(pfid1);
    fclose(pfid2);
    return 0;
}
