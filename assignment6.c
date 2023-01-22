//
// Created by HtetZarni on 17/01/2023.
//

#include "stdio.h"
#include "stdlib.h"
#define SIZE 100

struct userDB {

    int id;
    int age;
    char name[30];
    char email[50];
    char password[50];

};

struct userDB userInfo[SIZE];
int userInfoIndex = 0;
int emailFound = -1;
int passwordFound = -1;
void registration();
void login();
void dataPrinting();
void stringCompare(char userInput[50]);
void passwordCompare(char userInput[50], int userIndex);
int characterCounting(char userInput[50]);
void writingDataToFIle();
void loadingDataFromFile();
int emailValidation(char email[50]);

// the main page function
// you can register , login and can even exit if you want.

void main_page() {
    int userInputValue = 0;
    printf("\tTHIS IS THE HOME PAGE!\n");
    printf("Press 1 To Register | Press 2 To Login | Press 3 To Exit : ");
    scanf("%d",&userInputValue);

    if(userInputValue == 1) {
        registration();
    } else if(userInputValue == 2) {
        login();
    } else if(userInputValue == 3) {
        exit(1);
    }
}


int main() {

    loadingDataFromFile();
    dataPrinting();
    main_page();

    return 0;
}

void registration() {
    char userInputEmail[50];
        printf("Enter your email \n");
        scanf("%s",&userInputEmail);

    if(!emailValidation(userInputEmail)) { // email validation point
        printf("Invalid email! Please try again!\n");
        registration(); // if the email validation function return falsy value, the registration function will be called again recursively
    } else {
        // email you typed is checked if it already exists or not here.
        emailFound = -1;
        stringCompare(userInputEmail);
        if(emailFound == -1) {
            for(int y=0; y<50; y++) {
                if(userInputEmail[y] == '\0') {
                    break;
                }
                userInfo[userInfoIndex].email[y] = userInputEmail[y];
            }
//            printf("\t %s \n",userInfo[userInfoIndex].email);
            printf("Enter your name \n");
            scanf("%s",&userInfo[userInfoIndex].name);
            printf("Enter your age \n");
            scanf("%d",&userInfo[userInfoIndex].age);
            printf("Enter your password \n");
            scanf("%s",&userInfo[userInfoIndex].password);

            userInfo[userInfoIndex].id = userInfoIndex + 1;
            userInfoIndex++;
        } else { // if it already exists! you ain't allowed to log in!
            printf("Email already exists!\n Try logging in again.\n");
            registration();
        }

    }

    writingDataToFIle();
    main_page();

}


void login() {

    int found = -1;
    char userEmail[50];
    char userPassword[50];
    printf("Enter your email\n");
    scanf("%s",&userEmail);

    emailFound = -1;
    stringCompare(userEmail);

    printf("Enter your password\n");
    scanf("%s",&userPassword);

    passwordFound = -1;
    passwordCompare(userPassword, emailFound);

    if(emailFound != -1 && passwordFound == 1) {
        printf("You are logged in, %s\n",userInfo[emailFound].name);
        printf("......You will be redirected to the home page.\n\n");
        main_page();
    } else {
        printf("\t%d\n",userInfoIndex);
        printf("Invalid email or password!\n");
        login();
    }



}

void dataPrinting() {
    for(int x=0; x<userInfoIndex; x++) {

        printf("%d: Name-%s | Age-%d | Email-%s | Password-%s \n",userInfo[x].id,userInfo[x].name,userInfo[x].age,userInfo[x].email,userInfo[x].password);

    }
}

void stringCompare(char emailInput[50]) {

    int sameCount = 0;
    int charCounting = characterCounting(emailInput);
    for(int x=0; x<userInfoIndex; x++) {

        int emailDataCount = characterCounting(userInfo[x].email);

        if(charCounting == emailDataCount) {
            for(int y=0; y<emailDataCount; y++) {
                if(emailInput[y] != userInfo[x].email[y]) {
                    break;
                } else {
                    sameCount++;
                }
            }
        }

        if(sameCount == charCounting) {
            emailFound = x;
            break;
        }
    }



}

void passwordCompare(char userInput[50], int userIndex) {

    int sameCount = 0;
    int inputPWCount = characterCounting(userInput);
    int pwCount = characterCounting(userInfo[userIndex].password);
        if(inputPWCount == pwCount) {

            for (int y = 0; y < pwCount; y++) {
                if (userInput[y] == userInfo[userIndex].password[y]) {
                    sameCount++;
                } else {
                    break;
                }
            }

            if(sameCount == pwCount) {
                passwordFound = 1;
            }
        }
}

int characterCounting(char toCount[50]) {

    int charCount = 0;
    for (int x = 0; x < 50; x++) {
        if(toCount[x] == '\0') {
            break;
        } else {
            charCount++;
        }
    }
    return charCount;
}

void writingDataToFIle() {

    FILE *fptr;
    fptr = fopen("db.txt","w");
    if(fptr == NULL) {
        printf("Error while writing data to the file(db.txt).\n");
    } else {

        for(int x=0; x<userInfoIndex; x++) {
            fprintf(fptr,"%d %s %d %s %s \n",userInfo[x].id,userInfo[x].name,userInfo[x].age,userInfo[x].email,userInfo[x].password);
        }
        printf("All data s were written to the file. \n");

    }
    fclose(fptr);
}

void loadingDataFromFile() {

    FILE *fptr;
    fptr = fopen("db.txt","r");
    if(fptr == NULL) {
        printf("Error while loading data from the file(db.txt).\n");
    } else {
        for(int x=0; x<SIZE; x++) {

            fscanf(fptr,"%d%s%d%s%s",&userInfo[x].id,&userInfo[x].name,&userInfo[x].age,&userInfo[x].email,&userInfo[x].password);

            if(userInfo[x].name[0] == '\0') {
                break;
            }
            userInfoIndex++;

        }
    }

}

int emailValidation(char email[50]) {
    int returnNum = 0;
    int y=0;

    for(int x=0; x<50; x++) {

        if(email[x] == '@') {
            y = 1;
        } else {
            if(y == 1 && email[x] == '.') {

                returnNum = 1;
                break;

            } else {
                continue;
            }
        }



    }
    printf("\t %d \n",y);
    printf("\t %d \n",returnNum);
    return returnNum;
}