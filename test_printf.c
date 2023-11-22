#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

//int main(int argc, char const *argv[]) 
int	main(void)
{
	int len;
	int len_ft;

    //printf("%f\n", average(3, 1, 2, 3));
    //printf("%f%d\n", average(3, 1, 2, 3),10,5,"ds");
	fflush(stdout);
    len =       printf("text+%c+text+%%+%s+%x+%X+%u+%d\n", 'b',"d", 123, 12,12, -11);
    len_ft = ft_printf("text+%c+text+%%+%s+%x+%X+%u+%d\n", 'b',"d", 123, 12,12, -11);
    printf("delta len = %d\n\n", len - len_ft);
 
    len =       printf("text+%d+%i+%p+%p\n", 12, -11, NULL, &len);
    len_ft = ft_printf("text+%d+%i+%p+%p\n", 12, -11, NULL, &len);
    printf("delta len = %d\n\n", len - len_ft);

    len =       printf("text+%s+%s\n", (char *)NULL, "");
    len_ft = ft_printf("text+%s+%s\n", (char *)NULL, "");
    printf("delta len = %d\n\n", len - len_ft);

    len =       printf("text+%llu\n",(unsigned long long) (void *)-3);
    len =       printf("text+%p\n", (void *)-3);
    len_ft = ft_printf("text+%p\n", (void *)-3);
    printf("delta len = %d\n\n", len - len_ft);

    return 0;
}
