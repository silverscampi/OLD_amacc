#include <stdio.h>

int main()
{
    int a = 86;
    char c = 33;
    int *p = &a;
    //printf("arg1 %s %s %s %s %s\n", "arg2", "arg3", "arg4", "arg5", "arg6");
    //printf("arg1 %s %s %s %s %s %s %s %s %s %s\n", "arg2", "arg3", "arg4", "arg5", "arg6", "arg7", "arg8", "arg9", "arg10", "arg11");
    printf("int: %d, char: %c, string: %s, pointer: %p\n", a, c, "this is a string literal", p);
    return 0;
}
