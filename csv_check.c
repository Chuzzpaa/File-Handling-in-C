#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include"csv_check.h"

void trim(char *str) {
    int l = strlen(str);
    if (str[l-1] == '\n') {
        str[l-1] = 0;
    } 
}

int is_valid(char file[], FILE *check_file){
    if (check_file==NULL)
    {
        perror("Unable to open file");
        return 1;
    }
    else
    {
        printf("%s is a valid file.\n",file);
        return 0;
    }

}
int main(){
    int check =0;
    char filename[32];
    printf("Enter a file name to search: ");
    fgets(filename,32,stdin);
    trim(filename);
    
    FILE *fp = fopen(filename,"r");
    check =is_valid(filename,fp);
    if (check == 1)
    {
        exit(1);
    }

    char buffer[100];
    while (fgets(buffer,sizeof(buffer)-1,fp)!=NULL)
    {
        char *token;
        char *remaining = buffer;
        while ((token=strtok_r(remaining,",", &remaining))!=NULL)
        {
            trim(token);
            printf("%-7s", token);
        }
        printf("\n");
    }
    
    fclose(fp);
    return 0;
}