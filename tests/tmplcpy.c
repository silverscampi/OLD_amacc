#include <stdio.h>

int main() {
    
    int a, b;
    
    // OR
    a = 0xF0;
    b = 0x0F;
    printf("a:\t%x\nb:\t%x\na|b:\t%x\n\n", a, b, a|b);  // 0xFF

    // XOR
    a = 0x55555555;
    b = 0xFFFF0000;
    printf("a:\t%x\nb:\t%x\na^b:\t%x\n\n", a, b, a^b);  // 0xAAAA5555
    
    // AND
    a = 0xAAAA;
    b = 0x5555;
    printf("a:\t%x\nb:\t%x\na&b:\t%x\n\n", a, b, a&b);  // 0x0000

    // SHL
    a = 0x1000;
    b = 5;
    printf("a:\t%x\na<<1:\t%x\n", a, a<<1);
    printf("b:\t%d\na:\t%x\na<<b:\t%x\n\n", b, a, a<<b);  // 0x20000

    // SHR
    a = 0xabcdef;
    b = 8;
    printf("a:\t%x\na>>4:\t%x\n", a, a>>4);               // 0xABCDE
    printf("b:\t%d\na:\t%x\na>>b:\t%x\n\n", b, a, a>>b);  // 0xABCD

    // ADD
    a = 86;
    b = 92;
    printf("a:\t%d\nb:\t%d\na+b:\t%d\n", a, b, a+b);    // 178
    a = 832649;
    b = 239904;
    printf("a:\t%d\nb:\t%d\na+b:\t%d\n\n", a, b, a+b);  // 1072553

    // SUB
    a = 86;
    b = 92;
    printf("a:\t%d\nb:\t%d\na-b:\t%d\n", a, b, a-b);    // -6
    a = 832649;
    b = 239904;
    printf("a:\t%d\nb:\t%d\na-b:\t%d\n\n", a, b, a-b);  // 592745

    // MUL
    a = 86;
    b = 92;
    printf("a:\t%d\nb:\t%d\na*b:\t%d\n", a, b, a*b);    // 7912
    a = -428;
    b = 5998;
    printf("a:\t%d\nb:\t%d\na*b:\t%d\n", a, b, a*b);    // −2567144

    return 0;
}
