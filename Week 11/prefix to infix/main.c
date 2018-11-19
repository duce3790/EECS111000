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
        ungetc(c, stdin);   //�p�G��J���Ʀr���u�@�Ӧ줸�p +234 456
        scanf("%d", &ans); //�ڭ̪�code�O�@���s����@�Ӧ줸
        printf("%d", ans); //�ҥH�j��2�줸���ƭn�γo��function ungetc
    }
    return ans;
}
