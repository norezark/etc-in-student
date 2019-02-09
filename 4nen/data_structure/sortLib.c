#define N 2000000

int buffer[N];

void getData(int A[], int n, char filename[50])
{
    int i;
    FILE *fp;

    fp=fopen(filename,"r");

    for(i = 0; i < n;i++){

        fscanf(fp,"%d ", &A[i]);
    }

    fclose(fp);
}

void printAns(int A[], int n)
{
    int i;
    for(i = 0; i < n; i++){
        printf("%6d",A[i]);
    }
    printf("\n");
}

void swap(int *s, int *t)
{
    int temp;

    temp = *s;
    *s = *t;
    *t = temp;
}

//Bubble Sort
void bubble(int A[], int n)
{
    int i,j;

    for(i = 0;i < n;i++){
        for( j = n - 1; j > i; j--){
            if ( A[j] < A[j-1] ){
                swap( &A[j], &A[j-1]);
            }
        }
    }
}

//Quick Sort
//book pp.8-9
void quickSort(int bottom, int top, int data[])
{
    int lower, upper, div, temp;

    if( bottom >= top) {
        return;
    }


    div = data[bottom];  //pivot

    for( lower = bottom, upper = top; lower < upper; ){

        //left part
        while( lower <= upper && data[lower] <= div){
            lower++;
        }

        //right part
        while(lower <= upper && data[upper] > div){
            upper--;
        }

        if( lower < upper){
            swap(&data[lower], &data[upper]);
        }
    }

    //move the first element to the divided point
    swap(&data[bottom], &data[upper]);

    //recursion
    quickSort(bottom, upper-1, data);
    quickSort(upper + 1, top, data);
}


//C quick sort function :qsort
//book pp.10-11
int compare(const void *arg1, const void *arg2){
    return(*((int *)arg1) - *((int *)arg2));
}

void cQsort(int sort[N],int n)
{
    qsort(sort, n, sizeof(sort[0]), compare);
}

//quick sort
//see ibaraki's book pp.96-101

//choose the  pivot:
//the first larger element between the different A[0] and A[k]
int pivot(int i,int j,int A[])
{
    int pv, k;

    k = i + 1;

    while(A[i] == A[k] && k <= j)
        k++;


    if ( k > j)
        //all elments have same value
        pv = -1;
    else if(A[i] >= A[k])
        //A[0] is larger
        pv = i;
    else
        //A[k] is larger
        pv = k;

    return (pv);
}

//partition with the pivot
int partition(int i, int j, int a, int A[])
{
    int left,right,k;

    left = i, right = j;

    while(left <= right){
        while(A[left] < a)
            left++;


        while(A[right] >= a)
            right--;


        if(left <= right){
            swap(&A[left], &A[right]);
            left++;
            right--;
        }
        else
            break;

    }
    return(left);
}

void iba_quicksort(int i, int j, int A[])
{
    int a, pv, k;

    pv = pivot(i, j, A);

    if( pv != -1){

        a = A[pv];
        k= partition(i, j, a, A);

        iba_quicksort(i, k-1, A);
        iba_quicksort(k, j, A);

    }
    return;
}




//Merge Sort
//book pp.14-15
void mergeSort(int n, int data[], int buffer[])
{
    int i, j, k, m;

    if ( n <= 1){
        return;
    }

    m = n / 2;    //dividing


    //partition recursion

    mergeSort(m, data, buffer);
    mergeSort(n - m, data + m, buffer);

    //merge
    for( i = 0; i < m; i++){
        buffer[i] = data[i];
    }

    j = m;
    i = k = 0;

    while(i < m && j < n){ //
        if ( buffer[i] <= data[j]){
            data[k++] = buffer[i++];
        }else{
            data[k++] = data[j++];
        }
    }

    while(i < m){
        data[k++] = buffer[i++];
    }
}

//time measurement of four sorting programs
void timeMeasure(int A[], int n)
{
    FILE * fp;


    clock_t before;
    double elapsed;

    before =(double) clock();

    //measure testing
    //quickSort(0, n-1, A);
    //cQsort(A,n);
    mergeSort(n, A, buffer);


    elapsed=((double)clock() - before)/CLOCKS_PER_SEC;

    // printAns(A,n);

    //testing answer
    fp = fopen("time.csv","a");
    fprintf(fp, "\n  n    time(s)\n %d, %.5lf,",n,elapsed);
    fclose(fp);

}
