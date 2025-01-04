#include<stdio.h>
#include<stdlib.h>
void get_array_input(int *arr,int n);
int sum_of_arrayelements(int *arr,int n);
int main(){
    int n;
    scanf("%d",&n);
    int *arr=(int *)malloc(n * sizeof(int));
    get_array_input(arr,n);
    printf("%d\n",sum_of_arrayelements(arr,n));
    free(arr);
}

void get_array_input(int *arr,int n)
{   
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
}

int sum_of_arrayelements(int *arr,int n){
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=arr[i];
    return sum;
}