#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void delay(int number_of_seconds) { 
    // Converting time into milli_seconds 
    int milli_seconds = 1000 * number_of_seconds; 
  
    // Stroing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not acheived 
    while (clock() < start_time + milli_seconds); 
} 

int main() {
    printf("Esperando 3 segundos....\n");
    delay(3);
    printf("Feito.... passaram 3 segundos");
    return 1;
}
 
