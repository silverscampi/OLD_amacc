#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int my_atoi(char *s)
{
    int res;
    res = 0;
    while (*s) {
        if (*s < '0' || '9' < *s)
            return 0;
        res = res * 10 + (*s - '0');
        ++s;
    }
    return res;
}

int main(int argc, char **argv) {

    if (argc < 3) {
        printf("usage: %s <file> <#bytes to read>\n", argv[0]);
        exit(1);
    }

    char *p, *s;
    int fd, readsz, writesz;
    int bytes = my_atoi(argv[2]);

    printf("bytes: %d\n", bytes);

    if(!((p = malloc(bytes)) && (s = malloc(8)))) {
        printf("failed to malloc!\n");
        exit(1);
    }

    fd = open(argv[1], 2);
    readsz = read(fd, p, bytes);
    printf("read %d bytes\n____________________\n%s\n____________________\n",
          readsz, p);

//written!
    s[0] = 'w';
    s[1] = 'r';
    s[2] = 'i';
    s[3] = 't';
    s[4] = 't';
    s[5] = 'e';
    s[6] = 'n';
    s[7] = '!';
    
    writesz = write(fd, s, 8);
    printf("wrote %d bytes\n", writesz);

    close(fd);
    free(p);
    free(s);

    return 0;
}