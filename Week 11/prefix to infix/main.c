//  week 11 2018/11/19
//  prefix to infix by htchen
//  sample input: * + 2 3 + 4 + - 5 6 - 7 8
//  sample output: ((2+3)*(4+((5-6)+(7-8))))=10
#include <stdio.h>
#include <ctype.h>

int calculate(void);

int main(void)
{
    printf("=%d\n", calculate());
    return 0;
}

int calculate(void)
{
    int c;
    int ans;
    int op1, op2;

    c = getchar();
    if (isspace(c)) {
        ans = calculate();
    } else if (c=='+') {
        printf("(");
        op1 = calculate();
        printf("+");
        op2 = calculate();
        printf(")");
        ans = op1 + op2;
    } else if (c=='-') {
        printf("(");
        op1 = calculate();
        printf("-");
        op2 = calculate();
        printf(")");
        ans = op1 - op2;
    } else if (c=='*') {
        printf("(");
        op1 = calculate();
        printf("*");
        op2 = calculate();
        printf(")");
        ans = op1 * op2;
    } else if (isdigit(c)) {
        ungetc(c, stdin);   //如果輸入的數字不只一個位元如 +234 456
        scanf("%d", &ans); //我們的code是一次存取單一個位元
        printf("%d", ans); //所以大於2位元的數要用這個function ungetc
    }
    return ans;
}
