#include <stdio.h>
#include <time.h>

time_t pegaData(){
    char dateStr[9];
	return _strdate(dateStr);
}

time_t pegaHora(){
    char HoraStr[9];
	return _strtime(HoraStr);
}


int main () {
   char data[20];
   char hora[20];
   strcpy(data, pegaData());
   strcpy(hora, pegaHora());
     
   printf("Data: %s\nHora: %s\n\n", data, hora);
  
   return(0);
}
