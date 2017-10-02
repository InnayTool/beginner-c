#include "file.h"
#include "_include.h"
char lastdelim;
error errorcode;
char filegetlastdelim(void)
{
	return lastdelim;
}

file_t * fileopen(const char* filename, uint32_t mode)
{
	char m[5] = {0,0,0,0,0};

	if(mode & 0x01)
	{
		if(mode & 0x02)
			m[0] = 'a';
		else
			m[0] = 'r';
	}
	else
	{
		if(mode & 0x02)
			m[0] = 'w';
		else
		{
			errorcode = wrongParameters;
			return 0;
		}
	}
	if(mode & update)
		m[1] = '+';
	if(mode & binary)
		m[2] = 'b';
	return fopen(filename, m);
		
}
int	fileflush(file_t* f)
{
	return fflush(f);
}
int	fileclose(file_t* f)
{
	if(!f)
		return EOF;
	else
		return fclose(f);
}
int	filegetpos(file_t* f, fpos_t* pos)
{
	return fgetpos(f, pos);
}
int	filesetpos(file_t* f, fpos_t* pos)
{
	return fsetpos(f, pos);
}
void filesetposend(file_t* f)
{
	char buf[100];
	while(!feof(f))
		fread(buf, 1, 100,f);
}
void filesetposbegin(file_t* f)
{
	rewind(f);
}



#pragma region define fileread(type)
#define fileread(type)					\
type fileread##type(file_t* f, inttype t)\
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
	if(fscanf(f, format, &value))		\
		errorcode = no;					\
	else								\
		errorcode = nothingread;		\
	return value;						\
}
#pragma endregion
	   fileread(int8_t)
	   fileread(uint8_t)
	   fileread(int16_t)
	   fileread(uint16_t)
	   fileread(int32_t)
	   fileread(uint32_t)
	   fileread(int64_t)
	   fileread(uint64_t)
#undef fileread


float filereadfloat(file_t* f)
{
	float result;
	if(fscanf(f, "%f", &result))
		errorcode = no;
	else
		errorcode = nothingread;
	return result;		

}
double filereaddouble(file_t* f)
{
	double result;
	if(fscanf(f, "%lf", &result))
		errorcode = no;
	else
		errorcode = nothingread;
	return result;		

}
long double filereadldouble(file_t* f)
{
	double result;
	if(fscanf(f, "%lf", &result))
		errorcode = no;
	else
		errorcode = nothingread;
	return result;		

}



#pragma region define filereadline(type)
#define filereadline(type)				\
type filereadline##type(file_t* f, inttype t)	\
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
	if(fscanf(f, format, &value))		\
		errorcode = no;					\
	else								\
		errorcode = nothingread;		\
	while(fgetc(f) != '\n');			\
	return value;						\
}
#pragma endregion
	   filereadline(int8_t)
	   filereadline(uint8_t)
	   filereadline(int16_t)
	   filereadline(uint16_t)
	   filereadline(int32_t)
	   filereadline(uint32_t)
	   filereadline(int64_t)
	   filereadline(uint64_t)
#undef filereadline

float filereadlinefloat(file_t* f)
{
	float result;
	if(fscanf(f, "%f", &result))
		errorcode = no;
	else
		errorcode = nothingread;
	while(fgetc(f) != '\n');
	return result;		

}
double filereadlinedouble(file_t* f)
{
	double result;
	if(fscanf(f, "%lf", &result))
		errorcode = no;
	else
		errorcode = nothingread;
	while(fgetc(f) != '\n');
	return result;		

}
long double filereadlineldouble(file_t* f)
{
	double result;
	if(fscanf(f, "%lf", &result))
		errorcode = no;
	else
		errorcode = nothingread;
	while(fgetc(f) != '\n');
	return result;		

}

char*	filereadline(file_t* f, char* str, size_t max)
{
	size_t i;
	int c;
	for(i = 0; (c = fgetc(f)) != '\n' && c != '\0' && i < max - 1 ; ++i)
		if(c == EOF)
			return 0;
		else
			str[i] = c;
	str[i] = '\0';
	return str;
}

size_t	filereadtok	(file_t* f, char* str, size_t max, const char* delim)
{
	size_t i1, i2;
	int c;
	for(i1 = 0; i1 < max; ++i1)
	{
		c = fgetc(f);
		if(c == EOF)
		{
			str[i1] = '\0';
			return i1;
		}
		str[i1] = c;
		for(i2 = 0; delim[i2] != '\0'; ++i2)
			if(delim[i2] == str[i1])
			{
				if(i1 == 0)
					--i1;
				else
				{
					str[i1] = '\0';
					return i1;
				}
			}
	}
}

char* fileread (file_t* f, char* str, size_t maxsize)
{
	maxsize = fread(str, sizeof(char) , maxsize - 1, f);
	str[maxsize] = '\0';
	return str;
}
size_t	filereadn(file_t* f, char* str, size_t n)
{
	return fread(str, sizeof(char) , n, f);
}



#pragma region define filewrite(type)
#define filewrite(type)					\
void filewrite##type(file_t* f, inttype t, type value)\
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
	if(fprintf(f, format, &value))		\
		errorcode = no;					\
	else								\
		errorcode = nothingread;		\
}
#pragma endregion
	   filewrite(int8_t)
	   filewrite(uint8_t)
	   filewrite(int16_t)
	   filewrite(uint16_t)
	   filewrite(int32_t)
	   filewrite(uint32_t)
	   filewrite(int64_t)
	   filewrite(uint64_t)
#undef filewrite

void		filewritefloat		(file_t* f, floattype t, int width, int precision, float value)
{
	char format[6] = "%*.* ";
	format[4] = getfloattype(t);
	if(fprintf(f, format, width, precision, value))
		errorcode = no;
	else
		errorcode = nothingwrite;	
}
void		filewritedouble		(file_t* f, floattype t, int width, int precision, double value)
{
	char format[6] = "%*.* ";
	format[4] = getfloattype(t);
	if(fprintf(f, format, width, precision, value))
		errorcode = no;
	else
		errorcode = nothingwrite;	
}
void		filewriteldouble	(file_t* f, floattype t, int width, int precision, long double value)
{
	char format[7] = "%L*.* ";
	format[5] = getfloattype(t);
	if(fprintf(f, format, width, precision, value))
		errorcode = no;
	else
		errorcode = nothingwrite;	
}

#pragma region define filewriteline(type)
#define filewriteline(type)				\
void filewriteline##type(file_t* f, inttype t, type value)\
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
	switch(t)							\
	{									\
	case dec:							\
		format[pos] = 'd';				\
		break;							\
	case udec:							\
		format[pos] = 'u';				\
		break;							\
	case hex:							\
		format[pos] = 'x';				\
		break;							\
	case oct:							\
		format[pos] = 'o';				\
		break;							\
	case num:							\
		format[pos] = 'i';				\
		break;							\
	}									\
	format[pos + 1] = '\n';				\
	format[pos + 2] = '\0';				\
	if(fprintf(f, format, &value))		\
		errorcode = no;					\
	else								\
		errorcode = nothingwrite;		\
}
#pragma endregion
	   filewriteline(int8_t)
	   filewriteline(uint8_t)
	   filewriteline(int16_t)
	   filewriteline(uint16_t)
	   filewriteline(int32_t)
	   filewriteline(uint32_t)
	   filewriteline(int64_t)
	   filewriteline(uint64_t)
#undef filewriteline

void		filewritelinefloat		(file_t* f, floattype t, int width, int precision, float value)
{
	char format[7] = "%*.* \n";
	format[4] = getfloattype(t);
	if(fprintf(f, format, width, precision, value))
		errorcode = no;
	else
		errorcode = nothingwrite;	
}
void		filewritelinedouble		(file_t* f, floattype t, int width, int precision, double value)
{
	char format[7] = "%*.* \n";
	format[4] = getfloattype(t);
	if(fprintf(f, format, width, precision, value))
		errorcode = no;
	else
		errorcode = nothingwrite;	
}
void		filewritelineldouble	(file_t* f, floattype t, int width, int precision, long double value)
{
	char format[8] = "%L*.* \n";
	format[4] = getfloattype(t);
	if(fprintf(f, format, width, precision, value))
		errorcode = no;
	else
		errorcode = nothingwrite;	
}


void		filewritechar			(file_t* f, char c)
{
	fputc(c, f);
}
void		filewritenewline		(file_t* f)
{
	fputc('\n', f);
}

size_t filewrite(file_t* f, const char* str)
{
	return fwrite(str, sizeof(char), strlen(str), f);
}
size_t filewriteline(file_t* f, const char* str)
{
	size_t n;
	n = fwrite(str, sizeof(char), strlen(str), f);
	putc('\n',f);
	return n + 1;
}
size_t filewriten(file_t* f, char* str, size_t n)
{
	return fwrite(str, sizeof(char), n, f);
}
