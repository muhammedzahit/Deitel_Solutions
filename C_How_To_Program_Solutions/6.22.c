/*6.22 (Total Sales) Use a double-subscripted array to solve the following problem. A company has
four salespeople (1 to 4) who sell five different products (1 to 5). Once a day, each salesperson passes
in a slip for each different type of product sold. Each slip contains:
a) The salesperson number
b) The product number
c) The total dollar value of that product sold that day
Thus, each salesperson passes in between 0 and 5 sales slips per day. Assume that the information
from all of the slips for last month is available. Write a program that will read all this information
for last month’s sales and summarize the total sales by salesperson by product. All totals should be
stored in the double-subscripted array sales . After processing all the information for last month,
print the results in tabular format with each column representing a particular salesperson and each
row representing a particular product. Cross total each row to get the total sales of each product for
last month; cross total each column to get the total sales by salesperson for last month. Your tabular
printout should include these cross totals to the right of the totaled rows and to the bottom of the
totaled columns.*/
/* saleinformation.txt:(seller-product-money)
1-2-5 1-3-6 2-1-20 2-5-13 2-4-4 2-4-15 3-3-8 3-1-9 3-5-8 4-3-2 4-1-1 4-1-11 4-2-15 1-1-11 1-3-10 1-5-9 1-1-7 2-1-4 2-3-20 2-4-7 2-4-17 3-3-19 3-4-8
4-1-15 4-5-20 4-4-11 4-5-18 1-1-3 2-3-3 2-3-2 2-2-1 3-1-12 3-5-15 3-5-2 3-2-6 4-1-13 4-4-5 1-5-16 2-2-1 2-1-16 3-1-11 3-5-9 4-3-7 4-2-20 4-5-9 4-4-13
1-1-12 1-3-9 1-4-14 2-5-4 2-1-15 2-2-8 2-3-2 3-5-20 3-4-5 3-5-2 4-1-19 4-2-13 4-2-15 4-4-10 4-1-8 1-1-2 1-5-8 2-1-14 3-3-1 4-2-15 4-1-14 4-4-3 4-2-12
4-5-20 1-2-12 1-3-18 2-2-1 2-4-20 2-2-8 3-5-20 4-5-17 1-1-9 2-2-7 2-4-13 2-4-15 2-5-2 2-5-14 3-4-2 3-1-18 3-4-6 4-4-10 1-5-12 1-3-18 1-5-11 1-2-15
2-3-17 2-4-8 2-5-19 2-2-12 2-2-1 3-3-18 3-2-2 4-1-8 1-1-9 1-5-11 1-4-20 2-3-10 2-1-6 2-2-14 2-4-11 3-3-9 3-2-13 3-5-8 3-2-20 3-2-19 4-4-19 4-1-6 4-1-9
4-5-4 1-4-12 1-1-19 1-2-4 1-2-16 1-4-2 2-1-2 3-5-13 3-5-19 3-3-4 4-3-7 1-1-12 2-4-2 2-3-13 2-3-7 2-2-13 3-2-4 4-3-17 4-5-19 1-5-9 1-2-15 1-3-19 1-4-4
1-4-16 2-4-19 3-2-20 3-4-6 3-1-13 3-1-6 4-4-10 4-3-12 4-5-16 1-3-16 1-2-14 1-2-5 2-2-20 3-2-3 4-2-18 4-4-15 4-3-9 4-4-8 1-2-8 1-4-14 1-4-18 2-1-7 2-2-6
2-2-16 2-2-13 3-5-4 3-4-14 4-1-17 4-3-14 4-2-12 1-3-19 1-4-15 1-5-9 1-1-2 1-5-3 2-3-5 2-5-12 2-1-4 2-3-18 3-3-2 3-4-18 3-5-15 3-4-9 3-3-16 4-5-7 1-3-5
1-1-16 1-4-10 1-5-17 1-4-3 2-5-3 2-2-4 3-4-3 3-2-11 3-2-9 3-3-17 4-5-4 1-4-10 2-3-14 2-1-7 3-3-17 3-5-13 4-4-1 4-5-14 4-2-5 1-3-10 1-4-11 1-4-14 1-4-8
2-1-7 2-2-4 3-1-17 3-5-16 4-4-12 4-1-1 1-1-2 2-3-6 2-4-11 2-5-2 2-2-6 2-4-14 3-3-12 3-5-17 3-3-1 3-4-6 4-3-1 4-3-6 4-4-6 1-5-9 1-5-11 1-3-17 1-2-7 1-2-16
2-5-8 2-1-13 2-2-3 3-4-12 3-3-12 3-2-15 4-4-2 4-5-14 4-4-17 4-3-20 4-4-11 1-2-5 1-5-16 1-5-8 1-2-7 2-2-5 2-4-11 3-5-4 3-3-2 3-4-3 4-2-2 4-5-3 1-3-2 1-2-7
2-5-3 3-3-3 3-1-12 3-1-16 4-1-17 4-2-15 1-5-17 2-3-19 2-2-7 2-4-7 2-3-14 3-2-11 3-3-10 4-1-19 4-3-18 4-4-14 4-4-4 1-1-12 1-5-2 2-5-10 2-5-17 3-2-3 3-3-7
3-5-5 3-2-4 4-4-5 4-3-6 4-1-11 1-1-5 2-2-10 3-5-6 3-4-2 4-5-13 4-1-14 4-5-17 4-1-8 1-4-9 2-3-3 2-5-7 3-5-18 3-2-14 4-1-19 4-3-12 4-1-8 4-1-1 4-3-10 1-5-15
1-1-8 1-3-4 1-4-11 1-4-3 2-5-12 3-2-16 4-5-9 4-5-12 1-4-3 1-5-15 1-3-19 2-4-3 3-4-19 3-5-15 3-2-13 3-1-10 3-1-5 4-3-12 4-5-14 4-5-4 4-2-20 1-1-19 1-5-4
1-4-11 1-3-17 2-3-13 2-1-6 2-2-4 3-2-1 3-2-15 3-4-9 4-2-13 4-3-3 4-4-1
*/
#include <stdio.h>
int main(){
    int s=0,i,j,a,b,c;
    FILE *file;
    file = fopen("salesinformation.txt","r+");
    while (fscanf(file,"%d-%d-%d ",&a,&b,&c) != EOF){
        s++;
    }
    fclose(file);
    int sales[4][5] = {0};
    int money[5] = {0};
    file = fopen("salesinformation.txt","r+");
    for (i=0; i<s; i++){
        fscanf(file,"%d-%d-%d ",&a,&b,&c);
        ++sales[a-1][b-1];
        money[b-1] += c;
    }
    fclose(file);
    int seller1 = sales[0][0]+sales[0][1]+sales[0][2]+sales[0][3]+sales[0][4];
    int seller2 = sales[1][0]+sales[1][1]+sales[1][2]+sales[1][3]+sales[1][4];
    int seller3 = sales[2][0]+sales[2][1]+sales[2][2]+sales[2][3]+sales[2][4];
    int seller4 = sales[3][0]+sales[3][1]+sales[3][2]+sales[3][3]+sales[3][4];
    printf("          %8s %8s %8s %8s %8s","product1","product2","product3","product4","product5\n");
    for (i=0; i<4; i++){
        printf("Seller %d:",i+1);
        for (j=0; j<5; j++){

            printf("%8d",sales[i][j]);
        }
        if (i == 0) printf("  =  %d sales",seller1);
        if (i == 1) printf("  =  %d sales",seller2);
        if (i == 2) printf("  =  %d sales",seller3);
        if (i == 3) printf("  =  %d sales",seller4);
        printf("\n\n");
    }
    int product1= sales[0][0]+sales[1][0]+sales[2][0]+sales[3][0];
    int product2= sales[0][1]+sales[1][1]+sales[2][1]+sales[3][1];
    int product3= sales[0][2]+sales[1][2]+sales[2][2]+sales[3][2];
    int product4= sales[0][3]+sales[1][3]+sales[2][3]+sales[3][3];
    int product5= sales[0][4]+sales[1][4]+sales[2][4]+sales[3][4];
    printf("SumOfSale:%8d%8d%8d%8d%8d",product1,product2,product3,product4,product5);

    printf("\n\nMoney from product 1 : %d $",money[0]);
    printf("\nMoney from product 2 : %d $",money[1]);
    printf("\nMoney from product 3 : %d $",money[2]);
    printf("\nMoney from product 4 : %d $",money[3]);
    printf("\nMoney from product 5 : %d $",money[4]);
    printf("\n\nTOTAL PROFIT: %d $",money[0]+money[1]+money[2]+money[3]+money[4]);
    return 0;
}