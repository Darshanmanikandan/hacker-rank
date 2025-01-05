/**
 *  hackerrank question :
 * 
 * Print a pattern of numbers from 1 to n as shown below. Each of the numbers is separated by a single space.
 * 
 *    555555555 
 *    544444445 
 *    543333345 
 *    543222345 
 *    543212345 
 *    543222345 
 *    543333345 
 *    544444445 
 *    555555555
 * 
 */

#include<stdio.h>
void pattern_printing(int n);
int main()
{
    int n;
    scanf("%d",&n);
    if(n)
        pattern_printing(n);
    else 
        printf("something went wrong...");
    return 0;
}

void pattern_printing(int n)
{   
    int limit = (n*2)-1 ;

    for(int i=0;i<limit;i++){
        for(int j=0;j<limit;j++){

           int min_distance = i < j ? i : j;
            min_distance = min_distance < (limit - i - 1) ? min_distance : (limit - i - 1);
            min_distance = min_distance < (limit - j - 1) ? min_distance : (limit - j - 1);

            printf("%d ", n - min_distance);
        }
        printf("\n");
    }
}
