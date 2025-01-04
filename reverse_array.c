#include<stdio.h>
#include<stdlib.h>
void reverse_array(int *arr ,int n);
void get_array_input(int *arr,int n);
int main()
{
    int n;
    scanf("%d",&n);
    int *arr=(int *)malloc(n * sizeof(int));
    
    get_array_input(arr,n);
    reverse_array(arr ,n);

    for(int i=0;i<n;i++)
        printf("%d\t",arr[i]);
}
void get_array_input(int *arr,int n)
{
    for(int i=0;i<n;i++)
         scanf("%d",&arr[i]);
}

void reverse_array(int *arr ,int n)
{   
    for(int i=0;i<n;i++){
              temp=arr[i];
              arr[i]=arr[n-1];
              arr[n-1]=temp;
              n--;
    }
}