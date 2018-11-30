#include <stdio.h>

float cal(){
    char c = getchar();
    if (c == '+')
        return cal() + cal();
    else if (c == '-')
        return cal() - cal();
    else if (c == '*')
        return cal() * cal();
    else if (c == '/')
        return cal() / cal();
    else
        return c - '0';
}

int main(){
    printf("%.3f", cal());
    return 0;
}
