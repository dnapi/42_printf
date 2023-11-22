#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

//int main(int argc, char const *argv[]) 
int	main(void)
{
	int len;
	int len_ft;
	char *s = "\x01\x02\a\v\f\r\n";

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

    len =       printf("text+%p\n", (void *)-3);
    len_ft = ft_printf("text+%p\n", (void *)-3);
    printf("delta len = %d\n\n", len - len_ft);


    printf("test error 1\n");
    len =       printf("%Z");
    printf("ft\n");
    len_ft =	ft_printf("%Z\n");
//    len_ft =  ft_printf("\x01\x02\a\v\f\r\n");
//  	len_ft =   ft_printf("\001\002\007\v\010\f\r\n");
//   	len_ft = 0;
    printf("len = %d\n\n", len);
    printf("len_ft = %d\n\n", len_ft);



    printf("test write 1\n");
	write(1, s, 8);
    printf("test write 2 in loop\n");
	while (*s)
		printf("write =%d\n",(int)write(10, s++, 1));
    printf("end of test write 2 in loop\n");

    return 0;
}
