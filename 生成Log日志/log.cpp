#include <stdio.h> 
#include <stdlib.h> 



int main() 
{ 
    // Open a file pointer named "log.txt" for writing (w+) 
    // If you google c file i/o you'll find all the specifiers for 
    // writing, reading, writing and reading, etc. I just chose 
    // only writing here as an example 
    FILE* fp; 
    fp = fopen("log.txt", "w"); 

    // Generate whatever you want logged here, "data" is just an example 
    char* data = "The data to be logged...11111111111111111"; 

    // This lines writes the info in "data" to the file pointer specified 
    fputs(data, fp); 

    // Always remember to close your files 
    fclose(fp); 

    return EXIT_SUCCESS; 
} 