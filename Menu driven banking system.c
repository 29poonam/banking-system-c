#include <stdio.h>
#include <stdlib.h>

  int acc_no[100];
  int pin_no[100];
  float balance[100];
  char name[100][100];
  int total_accounts=0;
  void welcome()
  {
      printf("==================================================================================================================\n");
      printf("                                          WEL-COME TO MINI BANK\n");
      printf("==================================================================================================================\n");
  }

  void menu()
  {
      printf("                                        *******************************\n");
      printf("                                           SIMPLE BANKING SYSTEM * \n");
      printf("                                        *********************************\n");
      printf("                                          1. CREATE ACCOUNT\n");
      printf("                                          2. LOGIN\n");
      printf("                                          3. EXIT\n");

   }
   void user_menu()
   {
       printf("                                      =======USER-MENU======\n");
       printf("                                           1. DEPOSIT\n");
       printf("                                           2. WITHDRAW\n");
       printf("                                           3. CHECK_BALANCE\n");
       printf("                                           4. LOGOUT\n");
   }

  void creat_account()
  {
      printf("                                         ENTER NAME:\n");
      scanf("%s",name[total_accounts]);
      printf("                                         ENTER ACCOUNT_NUMBER:\n");
      scanf("%d",&acc_no[total_accounts]);
      printf("                                         ENTER PIN:\n");
      scanf("%d",&pin_no[total_accounts]);
      balance[total_accounts]=0;
      total_accounts++;

  }
  int login()
  {
      int i, acc,p;
      printf("                                         ENTER ACCOUNT NUMBER:\n");
      scanf("%d",&acc);
      printf("                                         ENTER PIN NUMBER:\n");
      scanf("%d",&p);
      for(i=0;i<total_accounts;i++)
      {
          if(acc==acc_no[i]&&p==pin_no[i])
          return i;
      }
      return -1;
  }
  void deposit(int user)
  {
      float amt;
      printf("                                        ENTER THE AMOUNT TO BE DEPOSITED:\n");
      scanf("%f",&amt);
      balance[user]+=amt;
      printf("                                      ~~  Amount Deposited Successfully .~~\n");
      printf("                                      :: Total Amount : %f\n",balance[user]);
  }
  void withdraw( int user)
  {
    float amt;
    printf("                                        ENTER THE AMOUNT TO BE WITHDRAWAN:\n");
    scanf("%f",&amt);
    if(amt>balance[user])
    {
        printf("                                    You Have Insufficient Balance..\n");
    }
    else
    {
        balance[user]-=amt;
        printf("                                  ~~ Amount Have Been Withdrawn.~~\n");
        printf("                                  :: Total Balance Amount :%f\n",balance[user]);
    }
  }
  void check_balance(int user)
  {
      printf("                                   =========ACCOUNT DETAILS============\n");
      printf("                                   *     NAME :  %s\n ",name[user]);
      printf("                                   *     ACCOUNT_NUMBER : %d\n",acc_no[user]);
      printf("                                   *    BALANCE  : %f\n",balance[user]);
      printf("                                   ======================================\n");
  }

int main()
{
    int choice;
    welcome();
    while(1)
    {
    printf("                                                                                                           \n");
    menu();
    printf("                                                                                                           \n");
    printf("                                          ENTER YOUR CHOICE:\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        creat_account();
        printf("                       ===================================================================\n");
        printf("                                   <<< ACCOUNT CREATED SUCCESFULLY >>>\n");
        printf( "                      ====================================================================\n");
        break;
        case 2:
           int user= login();
           if(user==-1)
           {
            printf("                                        Login__Failed\n");
           }
           else
           {
             int ch;
             printf("                                      =====================\n");
             printf("                                        Login Successful\n ");
             printf("                                      =====================\n");
             while(1)
             {
             user_menu();
             printf("                                      Enter choice:\n");
             scanf("%d",&ch);
             if(ch==1)
                deposit(user);
           else if(ch==2)
                withdraw(user);
            else if(ch==3)
                check_balance(user);
           else if(ch==4)
            break;
           else
            printf("                                     << Invalid Choice >>\n");
           }
           }
           break;
        case 3:
            printf("                                   // THANKU FOR VISITING US \\ \n");
            return 0;
            break;
        default:
            printf("                                     << Please Enter Valid Choice>>\n");
    }
    }

    return 0;
}
