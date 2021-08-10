#include <stdio.h> /* printf */

int main(void) 
{
    int n = 1;
    
    if (*(char*)&n) 
    {
        printf("Little endian\n");
    } 
    else 
    {
        printf("Big endian\n");
    }  
    
    return 0; 
}
