#include "string.h"
#include "_include.h"
error errorcode;


#pragma region define strread(type)
#define strread(type)					\
type strread##type(const char* str, inttype t, char** end)\
{										\
	type value;							\
	char format[7];						\
	size_t n;							\
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
	format[pos + 1] = '%';				\
	format[pos + 2] = 'n';				\
	format[pos + 3] = '\0';				\
	if(sscanf(str, format, &value, &n))	\
		errorcode = no;					\
	else								\
		errorcode = nothingread;		\
		*end = str + n;					\
	return value;						\
}
#pragma endregion
	   strread(int8_t)
	   strread(uint8_t)
	   strread(int16_t)
	   strread(uint16_t)
	   strread(int32_t)
	   strread(uint32_t)
	   strread(int64_t)
	   strread(uint64_t)
#undef strread

float		strreadfloat			(const char* str, char** end)
{
	float result;
	size_t n;
	if(sscanf(str, "%f%n", &result, &n))
		errorcode = no;
	else
		errorcode = nothingread;
	*end = str + n;
	return result;		
}
double		strreaddouble			(const char* str, char** end)
{
	double result;
	size_t n;
	if(sscanf(str, "%f%n", &result, &n))
		errorcode = no;
	else
		errorcode = nothingread;
	*end = str + n;
	return result;		
}
long double strreadldouble			(const char* str, char** end)
{
	double result;
	size_t n;
	if(sscanf(str, "%Lf", &result, &n))
		errorcode = no;
	else
		errorcode = nothingread;
	*end = str + n;
	return result;		
}

#pragma region define strwrite(type)
#if _MSC_VER
#define snprintf _snprintf
#endif
#define strwrite(type)					\
void strwrite##type(char* str, size_t max, inttype t, type value)\
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
	if(snprintf(str, max, format, &value))\
		errorcode = no;					\
	else								\
		errorcode = nothingwrite;		\
}
#pragma endregion
	   strwrite(int8_t)
	   strwrite(uint8_t)
	   strwrite(int16_t)
	   strwrite(uint16_t)
	   strwrite(int32_t)
	   strwrite(uint32_t)
	   strwrite(int64_t)
	   strwrite(uint64_t)
#undef strwrite

void	strwritefloat	(char* str, size_t max, floattype t, int width, int precision, float value)
{
	char format[7] = "%*.* \n";
	format[4] = getfloattype(t);
	if(snprintf(str, max, format, width, precision, value))
		errorcode = no;
	else
		errorcode = nothingwrite;	
}
void	strwritedouble	(char* str, size_t max, floattype t, int width, int precision, double value)
{
	char format[7] = "%*.* \n";
	format[4] = getfloattype(t);
	if(snprintf(str, max, format, width, precision, value))
		errorcode = no;
	else
		errorcode = nothingwrite;	
}
void	strwriteldouble	(char* str, size_t max, floattype t, int width, int precision, long double value)
{
	char format[8] = "%L*.* \n";
	format[4] = getfloattype(t);
	if(snprintf(str, max, format, width, precision, value))
		errorcode = no;
	else
		errorcode = nothingwrite;	
}