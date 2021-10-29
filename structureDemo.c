#include<stdio.h>
struct Account{
    int acc_num;
    char name[50];
    float balance;
    char address[100];
    char accountType[2];   //S<- Savings, C<- Current, SA<- Salary, FD<- fixed-deposit
};
int main()
{
    struct Account accounts[2];
    int i;
    for(i = 0; i < 2; i++){
        printf("\nEnter account number : ");
        scanf("%d",&accounts[i].acc_num);
        fflush(stdin);
        printf("\nEnter name : ");
        gets(accounts[i].name);
        printf("\nEnter balance : ");
        scanf("%f",&accounts[i].balance);
        fflush(stdin);
        printf("\nEnter address : ");
        gets(accounts[i].address);
        printf("\nEnter account type (S- Savings, C- Current): ");
        scanf("%s",accounts[i].accountType);
    }
    printf("\nAccounts details are as follows : ");
    for(i = 0; i < 2; i++){
        printf("\nAccount Number : %d", accounts[i].acc_num);
        printf("\nName : %s", accounts[i].name);
        printf("\nBalance : %8.2f", accounts[i].balance);
        printf("\nAddress : %s", accounts[i].address);
        printf("\nAccount type : %s",accounts[i].accountType);
    }
    struct Account *pAcc;
    pAcc = accounts;
	printf("\nAccounts details are as follows using structure pointer: ");
    for(i = 0; i < 2; i++, pAcc++){
        printf("\nAccount Number : %u", &(pAcc->acc_num));
        printf("\nName : %s", *(&(pAcc->name)));
        printf("\nBalance : %f", *(&(pAcc->balance)));
        printf("\nAddress : %s", *(&(pAcc->address)));
        printf("\nAccount type : %s",*(&(pAcc->accountType)));
    }

	return 0;
}
