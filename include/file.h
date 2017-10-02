#include "types.h"
typedef FILE file_t;

char filegetlastdelim(void);


file_t*		fileopen				(const char* filename, uint32_t mode);
int			fileflush				(file_t* f);
int			fileclose				(file_t* f);

int			filegetpos				(file_t* f, fpos_t* pos);
int			filesetpos				(file_t* f, fpos_t* pos);
void		filesetposbegin			(file_t* f);
void		filesetposend			(file_t* f);

error		filegeterror			(void);
char		filegetlastdelim		(void);



int8_t		filereadint8_t			(file_t* f, inttype t);
uint8_t		filereaduint8_t			(file_t* f, inttype t);
int16_t		filereadint16_t			(file_t* f, inttype t);
uint16_t	filereaduint16_t		(file_t* f, inttype t);
int32_t		filereadint32_t			(file_t* f, inttype t);
uint32_t	filereaduint32_t		(file_t* f, inttype t);
int64_t		filereadint64_t			(file_t* f, inttype t);
uint64_t	filereaduint64_t		(file_t* f, inttype t);

float		filereadfloat			(file_t* f);
double		filereaddouble			(file_t* f);
long double filereadldouble			(file_t* f);

int8_t		filereadlineint8_t		(file_t* f, inttype t);
uint8_t		filereadlineuint8_t		(file_t* f, inttype t);
int16_t		filereadlineint16_t		(file_t* f, inttype t);
uint16_t	filereadlineuint16_t	(file_t* f, inttype t);
int32_t		filereadlineint32_t		(file_t* f, inttype t);
uint32_t	filereadlineuint32_t	(file_t* f, inttype t);
int64_t		filereadlineint64_t		(file_t* f, inttype t);
uint64_t	filereadulineint64_t	(file_t* f, inttype t);

float		filereadlinefloat		(file_t* f);
double		filereadlinedouble		(file_t* f);
long double filereadlineldouble		(file_t* f);

char *		filereadline			(file_t* f, char* str, size_t max);
size_t		filereadtok				(file_t* f, char* str, size_t max, const char* delim);

char*		fileread				(file_t* f, char* str, size_t max);
size_t		filereadn				(file_t* f, char* str, size_t n);

void		filewriteint8_t			(file_t* f, inttype t, int8_t	value);
void		filewriteuint8_t		(file_t* f, inttype t, uint8_t	value);
void		filewriteint16_t		(file_t* f, inttype t, int16_t	value);
void		filewriteuint16_t		(file_t* f, inttype t, uint16_t	value);
void		filewriteint32_t		(file_t* f, inttype t, int32_t	value);
void		filewriteuint32_t		(file_t* f, inttype t, uint32_t	value);
void		filewriteint64_t		(file_t* f, inttype t, int64_t	value);
void		filewriteuint64_t		(file_t* f, inttype t, uint64_t	value);
			
void		filewritefloat			(file_t* f, floattype t, int width, int precision, float value);
void		filewritedouble			(file_t* f, floattype t, int width, int precision, double value);
void		filewriteldouble		(file_t* f, floattype t, int width, int precision, long double value);
			
void		filewritelineint8_t		(file_t* f, inttype t, int8_t	value);
void		filewritelineuint8_t	(file_t* f, inttype t, uint8_t	value);
void		filewritelineint16_t	(file_t* f, inttype t, int16_t	value);
void		filewritelineuint16_t	(file_t* f, inttype t, uint16_t	value);
void		filewritelineint32_t	(file_t* f, inttype t, int32_t	value);
void		filewritelineuint32_t	(file_t* f, inttype t, uint32_t	value);
void		filewritelineint64_t	(file_t* f, inttype t, int64_t	value);
void		filewritelineuint64_t	(file_t* f, inttype t, uint64_t	value);
			
void		filewritelinefloat		(file_t* f, floattype t, float value);
void		filewritelinedouble		(file_t* f, floattype t, double value);
void		filewritelineldouble	(file_t* f, floattype t, long double value);
			
void		filewritechar			(file_t* f, char c);
void		filewritenewline		(file_t* f);
			
size_t		filewrite				(file_t* f, const char* str);
size_t		filewriteline			(file_t* f, const char* str);
size_t		filewriten				(file_t* f, char* str, size_t n);

