//
// Created by htetzarni on 15/11/2022.
//

#include "stdio.h"
#include "stdlib.h"
#include "time.h"

int db[100];
int dbMoney[100];
int lotteryNums[90];
int main() {

    int userAge = 0;
    int userId = 0;
    int userId2 = 0;
    int userNum;
    int userOption;
    int userPlayOption;
    int userMoney;
    int userInputMoney = 0;
    int moneyAmount;
    int dbindex = 0;
    int flag = 0;
    int globalFlag = 0;
    srand(time(NULL));

    

    // loop for lottery numbers
    for(int i=0; i<90; i++) {
        int j = 10;
        lotteryNums[i] = j;
        j++;
    }

        printf("Enter your age: ");
        scanf("%d",&userAge);

        if(userAge > 17) {
            printf("You are allowed to play this game.\n Welcome Sir.\n");
            while (true) {
                printf("Press 1 to Log-in.\nPress 2 to Register.\nPress 3 to Step Back.\nPress 4 to Quit :");
                scanf("%d",&userOption);


                    if(userOption == 1) {
                        printf("This__Is__LogIn__Page!\n");
                        printf("Enter your Id: ");
                        scanf("%d",&userId);

                        for(int i=0; i<100; i++) {
                            if(db[i] == userId) {
                                userMoney = dbMoney[i];
                                flag = 1;

                            }
                        }

                        if(flag == 1) {
                            printf("You are logged in and READY TO PLAY!\n");
                            printf("Balance status: %d\n",userMoney);


                            while (userMoney > 0) {
                                printf("<<<Two-Digit-Lottery-Game>>>\n\n");
                                printf("Choose your favourite number :");
                                scanf("%d",&userNum);
                                userMoney -= 200; // each round costs 200ks, so subtract userMoney by 200.


                                while (true) {
                                    int randNum = rand()%90;
                                    if(randNum < 10) {
                                        randNum += 10;
                                    }
                                    printf("The Lottery Number is...... %d\n",randNum);

                                    if(userMoney == 0) {
                                        printf("Not enough money to play again.\n");
                                    }

                                    if(userNum == lotteryNums[randNum]) {
                                        printf("Congrats! You've just won the lottery!\n");
                                        break;
                                    } else {
                                        printf("Good Luck Next Time!\n");
                                        break;
                                    }
                                }

                            }


                        } else {
                            printf("Your Id doesn't exist.\n");
                            break;
                        }



                    } else if(userOption == 2) {

                        if(globalFlag == 1) {
                            globalFlag++; // bug fixed point!
                            break;
                        }

                        printf("This__Is__Register__Page!\n");
                        printf("Please Enter Your Id:");
                        scanf("%d",&userId);


                        for(int i=0; i<100; i++) {
                                if(db[i] == userId) {
                                    flag = 1;
                                }
                        }
                        while (true) {
                            if(flag == 1) {
                                printf("User's Id already exists.\n");
                                break;
                            } else {
                                printf("Confirm your Id: ");
                                scanf("%d",&userId2);

                                if(userId == userId2) {
                                    db[dbindex] = userId2;
                                    dbindex++;

                                    printf("Registration Succeed!\n1000ks free bonus is added to your account.\n");

                                    printf("Would you like to top-up more to your account?\n Press 1 to Top-up. Press 2 to continue with free bonus: ");

                                    scanf("%d",&userPlayOption);

                                    // if user wants to top-up,
                                    if(userPlayOption == 1) {
                                        printf("Please enter any amount of money: ");
                                        scanf("%d",&moneyAmount);
                                        userInputMoney += (moneyAmount + 1000);// adding to the user's account balance
                                        dbMoney[dbindex - 1] = userInputMoney; // have to subtract 1 from dbindex becuz increment is already done.

                                    // if user wants to continue, enter except 1;
                                    } else {
                                        dbMoney[dbindex - 1] = 1000; // same comment as line 144 here
                                        break;
                                    }

                                    break;
                                } else {
                                    printf("Ids don't match.\n");
                                }
                            }
                        }


                    } else if(userOption == 3) {
                        break;
                    } else if(userOption == 4) {
                        exit(1);
                    }

                }
            } else {
            printf("You can't play this game.\n");

        }




    return 0;
}