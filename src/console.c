#include "console.h"
#include "_include.h"

char lastdelim;
error errorcode;
char congetlastdelim(void)
{
	return lastdelim;
}

#pragma region define conread(type)
#define conread(type)					\
type conread##type(inttype t)			\
{										\
	type value;							\
	char format[5];						\
	int pos = 0;						\
	int size = sizeof(type);			\
	format[pos++] = '%';				\
	switch(size)						\
	{									\
	case sizeof(int8_t):				\
		format[pos++] = 'h';			\
		format[pos++] = 'h';			\
		break;							\
	case sizeof(int16_t):				\
		format[pos++] = 'h';			\
		break;							\
	case sizeof(int32_t):				\
		format[pos++] = 'l';			\
		break;							\
	case sizeof(int64_t):				\
		format[pos++] = 'l';			\
		format[pos++] = 'l';			\
		break;							\
	}									\
	format[pos] = getinttype(t);		\
	format[pos + 1] = '\0';				\
	if(scanf(format, &value))			\
		errorcode = no;					\
	else								\
		errorcode = nothingread;		\
	return value;						\
}
#pragma endregion
	   conread(int8_t)
	   conread(uint8_t)
	   conread(int16_t)
	   conread(uint16_t)
	   conread(int32_t)
	   conread(uint32_t)
	   conread(int64_t)
	   conread(uint64_t)
#undef conread

float conreadfloat(void)
{
	float result;
	if(scanf("%f", &result))
		errorcode = no;
	else
		errorcode = nothingread;
	return result;		

}
double conreaddouble(void)
{
	double result;
	if(scanf("%lf", &result))
		errorcode = no;
	else
		errorcode = nothingread;
	return result;		

}
long double conreadldouble(void)
{
	double result;
	if(scanf("%Lf", &result))
		errorcode = no;
	else
		errorcode = nothingread;
	return result;		

}

#pragma region define conreadline(type)
#define conreadline(type)				\
type conreadline##type(inttype t)	\
{										\
	type value;							\
	char format[5];						\
	int pos = 0;						\
	int size = sizeof(type);			\
	format[pos++] = '%';				\
	switch(size)						\
	{									\
	case sizeof(int8_t):				\
		format[pos++] = 'h';			\
		format[pos++] = 'h';			\
		break;							\
	case sizeof(int16_t):				\
		format[pos++] = 'h';			\
		break;							\
	case sizeof(int32_t):				\
		format[pos++] = 'l';			\
		break;							\
	case sizeof(int64_t):				\
		format[pos++] = 'l';			\
		format[pos++] = 'l';			\
		break;							\
	}									\
	format[pos] = getinttype(t);		\
	format[pos + 1] = '\0';				\
	if(scanf(format, &value))			\
		errorcode = no;					\
	else								\
		errorcode = nothingread;		\
	while(getchar() != '\n');			\
	return value;						\
}
#pragma endregion
	   conreadline(int8_t)
	   conreadline(uint8_t)
	   conreadline(int16_t)
	   conreadline(uint16_t)
	   conreadline(int32_t)
	   conreadline(uint32_t)
	   conreadline(int64_t)
	   conreadline(uint64_t)
#undef conreadline

float conreadlinefloat(void)
{
	float result;
	if(scanf("%f", &result))
		errorcode = no;
	else
		errorcode = nothingread;
	while(getchar() != '\n');
	return result;		

}
double conreadlinedouble(void)
{
	double result;
	if(scanf("%lf", &result))
		errorcode = no;
	else
		errorcode = nothingread;
	while(getchar() != '\n');
	return result;		

}
long double conreadlineldouble(void)
{
	double result;
	if(scanf("%lf", &result))
		errorcode = no;
	else
		errorcode = nothingread;
	while(getchar() != '\n');
	return result;		

}

char		conreadchar			(void)
{
	int c;
	if(c = getchar() == EOF)
		errorcode = nothingread;
	else
		errorcode = no;
	return c;
}
char		conreadlinechar		(void)
{
	int c0 = 0, c = 1;
	while (c != '\n' && c != '\0')
	{
		if(c == EOF)
		{
			errorcode = nothingread;
			return 0;
		}
		 c = getchar();
		 if(c0 == 0)
			 c0 = c;
	}
	errorcode = no;
	return c0;
}
void		conreadnewline		(void)
{
	int c;
	while(c = getchar() && c != '\n')
	{
		if(c == EOF)
		{
			errorcode = nothingread;
			return;
		}
	}
	errorcode = no;
}

char*	conreadline( char* str, size_t maxsize)
{
	size_t i;
	int c;
	for(i = 0; (c = getchar()) != '\n' && c != '\0' && i < maxsize - 1 ; ++i)
	{
		if(c == EOF)
		{
			errorcode = nothingread;
			return 0;
		}
		str[i] = c;
	}
	errorcode = no;
	str[i] = '\0';
	return str;
}
size_t conreadtok(char* str, size_t maxsize, const char* delim)
{
	size_t i, i2;
	char c;
	for(i = 0; c = getchar(), c != '\n' && c != '\0' && i < maxsize - 1; ++i)
		for(i2 = 0; delim[i2]; ++i2)
			if(delim[i2] == c)
			{
				lastdelim = c;
				str[i] = '\0';
				if(i != 0)
					return i;
				--i;
			}
			else
				str[i] = c;
	lastdelim = c;
	str[i] = '\0';
	return i;
}
size_t conreadlinetok(char* str, size_t maxsize, const char* delim)
{
	size_t i, i2;
	size_t found = 0;
	char c;

	for(i = 0; c = getchar() != '\n' && c != '\0'; ++i)
	{
		if(i < maxsize && !found)
		{
			for(i2 = 0; delim[i2]; ++i2)
				if(c == delim[i2])
				{
					lastdelim = c;
					str[i] = '\0';
					found = i;
					if(i == 0)
						--i;
				}
				else
					str[i] = c;
		}
	}
	if(!found)
	{
		if(i < maxsize)
		{
			str[i] = '\0';
			return i;
		}
		else
		{
			str[maxsize - 1] = '\0';
			return maxsize;
		}
	}
	return found;
}





#pragma region define conwrite(type)
#define conwrite(type)					\
void conwrite##type(inttype t, type value)\
{										\
	char format[5];						\
	int pos = 0;						\
	int size = sizeof(type);			\
	format[pos++] = '%';				\
	switch(size)						\
	{									\
	case sizeof(int8_t):				\
		format[pos++] = 'h';			\
		format[pos++] = 'h';			\
		break;							\
	case sizeof(int16_t):				\
		format[pos++] = 'h';			\
		break;							\
	case sizeof(int32_t):				\
		format[pos++] = 'l';			\
		break;							\
	case sizeof(int64_t):				\
		format[pos++] = 'l';			\
		format[pos++] = 'l';			\
		break;							\
	}									\
	format[pos] = getinttype(t);		\
	format[pos + 1] = '\0';				\
	if(printf(format, &value))			\
		errorcode = no;					\
	else								\
		errorcode = nothingread;		\
}
#pragma endregion
	   conwrite(int8_t)
	   conwrite(uint8_t)
	   conwrite(int16_t)
	   conwrite(uint16_t)
	   conwrite(int32_t)
	   conwrite(uint32_t)
	   conwrite(int64_t)
	   conwrite(uint64_t)
#undef conwrite

void		conwritefloat		(floattype t, int width, int precision, float value)
{
	char format[6] = "%*.* ";
	format[4] = getfloattype(t);
	if(printf(format, width, precision, value))
		errorcode = no;
	else
		errorcode = nothingwrite;	
}
void		conwritedouble		(floattype t, int width, int precision, double value)
{
	char format[6] = "%*.* ";
	format[4] = getfloattype(t);
	if(printf(format, width, precision, value))
		errorcode = no;
	else
		errorcode = nothingwrite;	
}
void		conwriteldouble		(floattype t, int width, int precision, long double value)
{
	char format[7] = "%L*.* ";
	format[4] = getfloattype(t);
	if(printf(format, width, precision, value))
		errorcode = no;
	else
		errorcode = nothingwrite;	
}

#pragma region define conwriteline(type)
#define conwriteline(type)				\
void conwriteline##type(inttype t, type value)\
{										\
	char format[6];						\
	int pos = 0;						\
	int size = sizeof(type);			\
	format[pos++] = '%';				\
	switch(size)						\
	{									\
	case sizeof(int8_t):				\
		format[pos++] = 'h';			\
		format[pos++] = 'h';			\
		break;							\
	case sizeof(int16_t):				\
		format[pos++] = 'h';			\
		break;							\
	case sizeof(int32_t):				\
		format[pos++] = 'l';			\
		break;							\
	case sizeof(int64_t):				\
		format[pos++] = 'l';			\
		format[pos++] = 'l';			\
		break;							\
	}									\
	format[pos] = getinttype(t);		\
	format[pos + 1] = '\n';				\
	format[pos + 2] = '\0';				\
	if(printf(format, value))			\
		errorcode = no;					\
	else								\
		errorcode = nothingread;		\
}
#pragma endregion
	   conwriteline(int8_t)
	   conwriteline(uint8_t)
	   conwriteline(int16_t)
	   conwriteline(uint16_t)
	   conwriteline(int32_t)
	   conwriteline(uint32_t)
	   conwriteline(int64_t)
	   conwriteline(uint64_t)
#undef conwriteline

void		conwritelinefloat		(floattype t, int width, int precision, float value)
{
	char format[7] = "%*.* \n";
	format[4] = getfloattype(t);
	if(printf(format, width, precision, value))
		errorcode = no;
	else
		errorcode = nothingwrite;	
}
void		conwritelinedouble		(floattype t, int width, int precision, double value)
{
	char format[7] = "%*.* \n";
	format[4] = getfloattype(t);
	if(printf(format, width, precision, value))
		errorcode = no;
	else
		errorcode = nothingwrite;	
}
void		conwritelineldouble		(floattype t, int width, int precision, long double value)
{
	char format[8] = "%*.*L \n";
	format[5] = getfloattype(t);
	if(printf(format, width, precision, value))
		errorcode = no;
	else
		errorcode = nothingwrite;	
}

void		conwritechar		(char c)
{
	putchar(c);
}
void		conwritenewline		(void)
{
	putchar('\n');
}

size_t		conwrite			(const char* str)
{
	fputs(str,stdout);
}
size_t		conwriteline		(const char* str)
{
	size_t n;
	n = fwrite(str,sizeof(char),strlen(str),stdout);
	putchar('\n');
	return n;

}

