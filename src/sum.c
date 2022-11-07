#include "sum.h"

int sum(int a[], int n){

    if (n == 0){ //tjekker om der er noget at summere

    return 0;
} 
    else{

    return a[n - 1] + sum(a, n-1); // beregner sum recursivt
}
    return 0;
}