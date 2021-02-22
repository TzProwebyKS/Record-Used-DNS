#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    FILE *cmdOutput = popen("ipconfig /displaydns", "r");
    FILE *recordsFile = fopen("records.txt", "w+");
    
    char word[MAX_PATH];
    
    while (fgets(word, sizeof(word), cmdOutput)) {
        fputs(word, recordsFile);
    }

    fclose(cmdOutput);
    fclose(recordsFile);
   
    return 0;
}