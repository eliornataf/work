#include <stdio.h> /* printf */

void TowerOfHanoi(int diskNum, char from_rod, char to_rod, char via_rod) 
{ 
    if (diskNum) 
    { 
        TowerOfHanoi(diskNum - 1, from_rod, via_rod , to_rod);
        printf("Move %d from %c to %c\n", diskNum, from_rod, to_rod);
        TowerOfHanoi(diskNum - 1, via_rod, to_rod, from_rod);
    } 
} 
 
int main() 
{ 
    int diskNum = 3;
    
    TowerOfHanoi(diskNum, 'A', 'C', 'B');
    
    return 0; 
} 
