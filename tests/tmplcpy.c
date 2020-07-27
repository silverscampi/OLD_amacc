#include <stdio.h>

int main() {
    int a = 0xF0;
    int b = 0x0F;
    printf("a: %h\nb:%h\na|b: %h\n", a, b, a|b);

    return 0;
}