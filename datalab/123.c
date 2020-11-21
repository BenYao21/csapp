#include<stdio.h>
int main() {
    int a = 0xaa;
    int b = ~a + 1;
    int x = (a>>31)^(b>>31);
    printf("%x\n",x);
    return 0;
}
