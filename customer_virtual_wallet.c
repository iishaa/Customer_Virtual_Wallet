#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

int CreateAcc(int ind); // this function create a new account

void SearchACustomer(int acc_no); //this function search an existing account

void PayBill(int acc_no); //this function will pay the bill and show the total amount of the customer

void printAllCustomers(); // this function display all the customers account

void AddBalance(int acc_no); // this function is used to add balance in existing account

 void DeleteAccount(int acc_no);//this function used to delete the account

struct account{
    char first[50];
    char last[50];
    int acct_no;
    char mobile_no[11];
    char city1[100];
    char city2[100];
    float balance;
}customer[1000];

int cust_count=0,acc_no=0,id=100001,i=0;
char choice;

void main(){
    printf("\n\t\t<<<----------------------***************----------------------->>>\n\n");
    printf("\t\t\t\tWELCOME TO CUSTOMER VIRTUAL WALLET\n\n");
    printf("\t\t\t1. Add New Customer Wallet.\n");
    printf("\t\t\t2. Search Existing Customer Account.\n");
    printf("\t\t\t3. Pay the Bills.\n");
    printf("\t\t\t4. Print All Customers Details.\n");
    printf("\t\t\t5. Top-Up Balance.\n");
    printf("\t\t\t6. Delete Account.\n");
    printf("\t\t\t7. Exit.\n");
    printf("\n\t\t<<<----------------------***************----------------------->>>\n");

    printf("\nSelect what you want to do ?:-\t");

    while(1){
        scanf("%c",&choice);
        switch(choice){
        case '1':
            cust_count +=1;
            printf("\n\tSerial number:- %d\n",cust_count);
            int id = CreateAcc(i);
            i += 1;
            printf("\n\tYour account number is:- %d\n\n",id);
            main();
            break;
        case '2':
            printf("\n\tEnter account number:-");
            scanf("%d",&acc_no);
            SearchACustomer(acc_no);
            main();
            break;
        case '3':
            printf("\n\tEnter account number:-");
            scanf("%d",&acc_no);
            PayBill(acc_no);
            main();
            break;
        case '4':
            printAllCustomers();
            main();
            break;
        case '5':
            printf("\n\tEnter account number:-");
            scanf("%d",&acc_no);
            AddBalance(acc_no);
            main();
            break;
        case '6':
            printf("\n\tEnter account number:-");
            scanf("%d",&acc_no);
            DeleteAccount(acc_no);
            main();
            break;
        case '7':
            printf("\n\t\t<<<----------------------Saved Successfully------------------------>>>\n");
            printf("\t\t\t\t\t THANKS FOR USING :)");
            exit(0);
            break;
        }
    }
    return;
}

int CreateAcc(int ind){
    customer[ind].acct_no = id++;
    printf("\n\tEnter Customer Name:-\t");
    scanf("%s %s",&customer[ind].first,&customer[ind].last);


    printf("\n\tEnter Mobile number:-\t");
    scanf("%s",&customer[ind].mobile_no);

    printf("\n\tEnter City:-\t");
    scanf("%s %s",&customer[ind].city1,&customer[ind].city2);

    printf("\n\tHow much balance you want to add in your wallet:-\t");
    scanf("%f",&customer[ind].balance);

    return customer[ind].acct_no;
}

void SearchACustomer(int acc_no){
    int temp=0;
   for(int i=0;i<cust_count;i++){
        if(customer[i].acct_no == acc_no){
            temp = i;
        }
   }
        if(customer[temp].acct_no == acc_no){
            printf("\n\tCustomer ID is:-%d\t\n",customer[temp].acct_no);
            printf("\tCustomer name is:-%s %s\t\n",customer[temp].first,customer[temp].last);
            printf("\tCustomer mobile number is:-%s\t\n",customer[temp].mobile_no);
            printf("\tCustomer city name is:-%s %s\t\n",&customer[temp].city1,&customer[temp].city2);
            printf("\tAccount balance is:-%.2f\t\n\n",customer[temp].balance);

        }else
            printf("\n\tCustomer not found!! :( \n\n");

   return;

}


void PayBill(int acc_no){
    float amount=0;
    int add,temp=0;

    for(int i=0;i<cust_count;i++){
           if(customer[i].acct_no==acc_no)
                temp = i;
    }
        if(customer[temp].acct_no==acc_no){
            printf("\n\tEnter the amount you have to pay:-");
            scanf("%f",&amount);
            if(customer[temp].balance>amount){
                customer[temp].balance -= amount;
                printf("\n\tRemaining balance:-%.2f\n",customer[temp].balance);
            }
            else{
                printf("\n\tYour balance is low---\n");
                printf("\n\tWant to add balance to your wallet:\n\n\t press 1 for 'yes' otherwise 2 for 'NO':- ");
                scanf(" %d",&add);
                if(add == 1){
                    AddBalance(acc_no);
                }
                else{
                    printf("\n\tThank You For Using :)\n\n");
                }
            }
        }
        else{
            printf("\tCustomer not found!! :(\n\n");
        }
        return;
    }



void printAllCustomers(){
    for(int i = 0;i<cust_count;i++){
        printf("CUSTOMER---%d\n",(i+1));
        printf("\t Customer ID is:-%d\t\n",customer[i].acct_no);
        printf("\t Customer name is:-%s %s\t\n",customer[i].first,customer[i].last);
        printf("\t Customer mobile number is:-%s\t\n",customer[i].mobile_no);
        printf("\t Customer city name is:-%s %s\t\n",&customer[i].city1,&customer[i].city2);
        printf("\t Account balance is:-%.2f\t\n\n",customer[i].balance);
    }
    return;
}
void AddBalance(int acc_no){
    float amount=0;
    int temp =0;

    for(int i=0;i<cust_count;i++){
        if(customer[i].acct_no==acc_no)
            temp = i;
    }
        if(customer[temp].acct_no == acc_no){
            printf("\n\tEnter the amount to add in your wallet:-\t");
            scanf("%f",&amount);
            customer[temp].balance += amount;
            printf("\n\tYour updated balance is %.2f\n",customer[temp].balance);
        }
        else{
            printf("\tCutomer not found!! :(\n\n");
        }
        return;
    }

void DeleteAccount(int acc_no){
    int temp;
    for(int i=0;i<cust_count;i++){
        if(customer[i].acct_no == acc_no){
            temp=i;
            break;
        }
    }
    for(int i=temp+1;i<cust_count;i++){
        customer[i-1] = customer[i];
    }
    cust_count--;
    printAllCustomers();
    printf("\n\t Account deleted successfully :)");
    return;
}



