/*  
     hackerrank question :

     For each integer n in the interval (a, b) (given as input):
     If 1 <= n <= 9 then print the English representation of it in lowercase. 
     That is "one" for 1, "two" for 2, and so on.
     Else if n > 9 and it is an even number, then print "even".
     Else if n > 9 and it is an odd number, then print "odd".

*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void print_numbers(int start,int stop);

int main() 
{
    int a, b;
    scanf("%d\n%d", &a, &b);
    
    /** input validation
     * calls the function only if the start and stop values are greater than zero and the end value is less than 500 
     * else returns an error message 
     */

    (a>0 && b>0 && b<500)? print_numbers(a,b):printf("Something went wrong...\n");
    
    return 0;
}

void print_numbers(int start,int stop){
        for(int i=start;i<stop+1;i++){ 
              switch(i){
                     case 1:
                             printf("one\n");break;
                     case 2:
                             printf("two\n");break;
                     case 3:
                             printf("three\n");break;
                     case 4: 
                             printf("four\n");break;
                     case 5:
                             printf("five\n");break;
                     case 6:
                             printf("six\n");break;
                     case 7:
                             printf("seven\n");break;
                     case 8:
                             printf("eight\n");break;
                     case 9:
                             printf("nine\n");break;
                     default:
                            (i%2 == 0)?printf("even\n"):printf("odd\n"); break;      
        }
    }
}