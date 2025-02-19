#include<stdio.h>
float atmtransaction(int choice,float balance){
       float amount;

       switch(choice){
        case 1:
        printf("enter the amount to withdraw\n");//withdraw
        scanf("%f",&amount);

        if(amount>balance){
            printf("insufficient balance");
        }
        else{
            balance-=amount;
            printf("success remaining balance is%f\n",balance);
        }
        break;
        case 2:
        printf("enter the amount to deposit\n");
        scanf("%f",&amount);
        balance+=amount;
        printf("the total deposit amount is %f\n",balance);
        break;
        case 3:
        printf("current balance is %f",balance);
        break;
       }
       return balance;
}


int main(){
          float balance=10000.0f;
          int choice;

        printf("1.withdraw\n");
        printf("2.deposit\n");
        printf("3.bankbalance\n");

        printf("enter the choice\n");
        scanf("%d", &choice);

        balance=atmtransaction(choice,balance);
    return 0;
}
