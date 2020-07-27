#include <stdio.h>

int main() {
    int a = 0xF0;
    int b = 0x0F;
    printf("a:\t%x\nb:\t%x\na|b:\t%x\n", a, b, a|b);

    return 0;
}
