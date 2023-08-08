#include <stdio.h>
#include<stdlib.h>
#include<string.h>

void trim(char *str) { //rmove newline character
    int l = strlen(str);
    if (str[l-1] == '\n') {
        str[l-1] = 0;
    } 
}

void get_information(char name[], char email[], char phone[]){ //get information from user
    printf("Enter a name: ");
    fgets(name, 32, stdin);
    trim(name);

    printf("Enter your e-mail: ");
    fgets(email, 128, stdin);
    trim(email);

    printf("Enter your Phone number: ");
    fgets(phone, 12, stdin);
    trim(phone); 
}
int check_user(FILE *fp, const char name[], const char email[], const char phone[]) {
    fseek(fp, 0, SEEK_SET);
    char buffer[200];
    char saved_name[32];
    char saved_email[128];
    char saved_phone[12];
    
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        trim(buffer);
        sscanf(buffer, "%31[^,],%127[^,],%11s",saved_name, saved_email, saved_phone); //extract each field individually for comparison
        //"," is set as delimiter, numbers after %reads that many numbers of characters
        //Data is stored in corresponding variable

        if (strcmp(saved_name, name) == 0 && strcmp(saved_email, email) == 0 && strcmp(saved_phone, phone) == 0) {
            return 1; // User found
        }
    }
    return 0; // User not found
}

int main(){
    FILE *users = fopen("users.csv", "a+"); //open csv file
    char name[32]; char email[128]; char phone[12]; 
    char data[200];
    get_information(name,email,phone); //get information using a function
    snprintf(data,sizeof(data),"%s,%s,%s\n",name,email,phone);  //store with data into some var
    
    int flag =0;
    flag = check_user(users,name,email,phone);
    if (flag==1)  //If equal, print message and exit, else append and close.
    {
        printf("User found.\n");
    }
    else
    {
        fseek(users,0,SEEK_END);
        fprintf(users,"%s,%s,%s\n",name,email,phone);
        printf("New user.\n");
    }
    fclose(users);
    return 0;
}
 