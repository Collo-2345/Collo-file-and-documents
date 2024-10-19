#include<stdio.h>
int main(){
    // a simple calculator to perform arithmetic operation .
    // declare  variables.
    char operator;
    int num1,num2;
    // prompt user to choose an operator to perform arithmetic calculation
    printf("Choose an ARITHMETIC OPERATOR: ");
    scanf("%C",&operator);

    // prompt user to enter to number to perform arithmetic operation.
    printf("Enter two number to perform arithmetic operation.\n ");
    scanf("%d%d",&num1,&num2);

    switch (operator){
        case '+':
            printf("Addition of two number is:%d",num1+num2);
        break;

        case '-':
            printf("Subtraction of two number is :%d",num1-num2);
        break;

        case '/':
            printf("Division of two number is:%d",num1/num2);
        break;

        case '*':
            printf("Multiplication of two number is:%d",num1*num2);
        break;

        case '%':
            printf("Module of two number is:%d",num1%num2);
        break;

        Default:
            printf("You have enter the wrong ARITHMETIC OPERATOR.\n ");
            printf("Enter the correct arithmetic such as '*','+','/','%%','/':\n ");
        break;}

        return 0;

}



