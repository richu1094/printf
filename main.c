#include <stdio.h>
#include "ft_printf.h"

int main() {
    int ret1, ret2;
    
    int num = 42;
    char ch = 'A';
    char *str = "Hello, world!";
    void *ptr = &num;
    unsigned int u_num = 4294967295;
    unsigned int hex_num_lower = 0x255f;
    unsigned int hex_num_upper = 0x255F;

    printf("---- Test 1: Integer ----\n");
    ret1 = ft_printf("%d\n", num);
    ret2 = printf("%d\n", num);
    printf("Return values: ft_printf = %d, printf = %d\n\n", ret1, ret2);

    printf("---- Test 2: String ----\n");
    ret1 = ft_printf("%s\n", str);
    ret2 = printf("%s\n", str);
    printf("Return values: ft_printf = %d, printf = %d\n\n", ret1, ret2);

    printf("---- Test 3: Char ----\n");
    ret1 = ft_printf("%c\n", ch);
    ret2 = printf("%c\n", ch);
    printf("Return values: ft_printf = %d, printf = %d\n\n", ret1, ret2);

    printf("---- Test 4: Pointer ----\n");
    ret1 = ft_printf("%p\n", ptr);
    ret2 = printf("%p\n", ptr);
    printf("Return values: ft_printf = %d, printf = %d\n\n", ret1, ret2);

    printf("---- Test 5: Hexadecimal ----\n");
    ret1 = ft_printf("%x\n", hex_num_lower);
    ret2 = printf("%x\n", hex_num_lower);
    printf("Return values: ft_printf = %d, printf = %d\n\n", ret1, ret2);

    printf("---- Test 6: Hexadecimal ----\n");
    ret1 = ft_printf("%X\n", hex_num_upper);
    ret2 = printf("%X\n", hex_num_upper);
    printf("Return values: ft_printf = %d, printf = %d\n\n", ret1, ret2);

    printf("---- Test 7: Unsigned ----\n");
    ret1 = ft_printf("%u\n", u_num);
    ret2 = printf("%u\n", u_num);
    printf("Return values: ft_printf = %d, printf = %d\n\n", ret1, ret2);

    printf("---- Test 8: Percent ----\n");
    ret1 = ft_printf("%%\n");
    ret2 = printf("%%\n");
    printf("Return values: ft_printf = %d, printf = %d\n\n", ret1, ret2);

    return 0;
}
