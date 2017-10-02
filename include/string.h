#include "types.h"


int8_t		strreadint8_t			(const char* str, inttype t);
uint8_t		strreaduint8_t			(const char* str, inttype t);
int16_t		strreadint16_t			(const char* str, inttype t);
uint16_t	strreaduint16_t			(const char* str, inttype t);
int32_t		strreadint32_t			(const char* str, inttype t);
uint32_t	strreaduint32_t			(const char* str, inttype t);
int64_t		strreadint64_t			(const char* str, inttype t);
uint64_t	strreaduint64_t			(const char* str, inttype t);
			
float		strreadfloat			(const char* str);
double		strreaddouble			(const char* str);
long double strreadldouble			(const char* str);


void		strwriteint8_t			(char* str, size_t max, inttype t, int8_t	value);
void		strwriteuint8_t			(char* str, size_t max, inttype t, uint8_t	value);
void		strwriteint16_t			(char* str, size_t max, inttype t, int16_t	value);
void		strwriteuint16_t		(char* str, size_t max, inttype t, uint16_t	value);
void		strwriteint32_t			(char* str, size_t max, inttype t, int32_t	value);
void		strwriteuint32_t		(char* str, size_t max, inttype t, uint32_t	value);
void		strwriteint64_t			(char* str, size_t max, inttype t, int64_t	value);
void		strwriteuint64_t		(char* str, size_t max, inttype t, uint64_t	value);
											 
void		strwritefloat			(char* str, size_t max, floattype t, float value);
void		strwritedouble			(char* str, size_t max, floattype t, double value);
void		strwriteldouble			(char* str, size_t max, floattype t, long double value);