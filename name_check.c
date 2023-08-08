#include <stdio.h>
#include <string.h>
#include "name_check.h"

int is_valid_name(char name[]){
    int i =0;
    if (name[i] <'A'||name[i]>'Z')
    {
        if (name[i+1]<'a'||name[i+1]>'z')
        {
            return 0;
        }
    }
    return 1;
}

void trim(char *str) {
    int l = strlen(str);
    if (str[l-1] == '\n') {
        str[l-1] = 0;
    } 
}

int main(){
    FILE *fp = fopen("names.txt","r");
    if (fp==NULL)
    {
        perror("Error opening file");
    }
    char buffer[128];

    while (fgets(buffer,sizeof(buffer)-1,fp) != NULL)//loop until we reach the end of file
    {
        trim(buffer);//remove new line character if present

        int flag=0;
        flag =is_valid_name(buffer);
        if (flag ==1)
        {
        puts(buffer);
        }
    }          

    fclose(fp);
    return 0;
}