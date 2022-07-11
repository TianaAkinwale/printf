#include "main.h"

//If you made it here, it implies format[i] == '%'
//So we are interested in finding the character after format[i]
int check_specifier(const char *format, int count, int i, va_list args)
{
	int j;
	char *str;

	//for %%
	if (format[i + 1] == '%')
	{
		putchar(format[i]);
		count++;
		return count;
	}
	//for %c
	else if (format[i + 1] == 'c')
	{
		putchar(va_arg(args, int));
		count++;
		return count;
	}
	//for %s
	else if (format[i + 1] == 's')
	{
		str = va_arg(args, char *);
		if (str == NULL)
			str = "(null)";
		for (j = 0; str[j] != '\0'; j++)
		{
			putchar(str[j]);
			count++;
		}
		return count;
	}
	//else here implies if format character is none of the above
	else
	{
		putchar('%');
		putchar(format[i + 1]);
		//count = count + 2 because putchar was called twice in this
		//else block
		count = count + 2;
		return count;
	}
	return count;
}
