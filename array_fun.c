#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
  char freq[10]={0}; 
    char *s = malloc (1024 * sizeof(char)); 
    scanf("%[^\n]",s);
    for(int i = 0;i < strlen(s);i++)
    {
        if (s[i] >= '0' && s[i] <= '9'){ 
            freq[s[i]-'0']++;   //Updates the frequency count in freq using the digit as an index
        }
    }
    for (int i = 0 ; i < 10; i++)
        printf("%d ",freq[i]);
    
    free(s);
}