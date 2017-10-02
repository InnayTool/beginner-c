#include "types.h"

char congetlastdelim(void);


int8_t		conreadint8_t			(inttype t);
uint8_t		conreaduint8_t			(inttype t);
int16_t		conreadint16_t			(inttype t);
uint16_t	conreaduint16_t			(inttype t);
int32_t		conreadint32_t			(inttype t);
uint32_t	conreaduint32_t			(inttype t);
int64_t		conreadint64_t			(inttype t);
uint64_t	conreaduint64_t			(inttype t);

float		conreadfloat			(void);
double		conreaddouble			(void);
long double conreadldouble			(void);

int8_t		conreadlineint8_t		(inttype t);
uint8_t		conreadlineuint8_t		(inttype t);
int16_t		conreadlineint16_t		(inttype t);
uint16_t	conreadlineuint16_t		(inttype t);
int32_t		conreadlineint32_t		(inttype t);
uint32_t	conreadlineuint32_t		(inttype t);
int64_t		conreadlineint64_t		(inttype t);
uint64_t	conreadulineint64_t		(inttype t);

float		conreadlinefloat		(void);
double		conreadlinedouble		(void);
long double conreadlineldouble		(void);

char		conreadchar				(void);
char		conreadlinechar			(void);
void		conreadnewline			(void);

char *		conreadline				(char* str, size_t n);
size_t		conreadtok				(char* str, size_t n, const char* delim);
size_t		conreadlinetok			(char* str, size_t n, const char* delim);

void		conwriteint8_t			(inttype t, int8_t	value);
void		conwriteuint8_t			(inttype t, uint8_t	value);
void		conwriteint16_t			(inttype t, int16_t	value);
void		conwriteuint16_t		(inttype t, uint16_t value);
void		conwriteint32_t			(inttype t, int32_t	value);
void		conwriteuint32_t		(inttype t, uint32_t value);
void		conwriteint64_t			(inttype t, int64_t	value);
void		conwriteuint64_t		(inttype t, uint64_t value);

void		conwritefloat			(floattype t, int width, int precision, float value);
void		conwritedouble			(floattype t, int width, int precision, double value);
void		conwriteldouble			(floattype t, int width, int precision, long double value);

void		conwritelineint8_t		(inttype t, int8_t	value);
void		conwritelineuint8_t		(inttype t, uint8_t	value);
void		conwritelineint16_t		(inttype t, int16_t	value);
void		conwritelineuint16_t	(inttype t, uint16_t value);
void		conwritelineint32_t		(inttype t, int32_t	value);
void		conwritelineuint32_t	(inttype t, uint32_t value);
void		conwritelineint64_t		(inttype t, int64_t	value);
void		conwritelineuint64_t	(inttype t, uint64_t value);

void		conwritelinefloat		(floattype t, int width, int precision, float);
void		conwritelinedouble		(floattype t, int width, int precision, double);
void		conwritelineldouble		(floattype t, int width, int precision, long double);

void		conwritechar			(char c);
void		conwritenewline			(void);

size_t		conwrite				(const char* str);
size_t		conwriteline			(const char* str);

