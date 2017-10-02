#include "lib.h"

#ifndef __SimpleCEnums
#define __SimpleCEnums
#ifndef __cplusplus
typedef enum
{
	false,
	true
} bool;
#endif
typedef enum _error
{
	no,
	wrongParameters,
	nothingread,
	nothingwrite
}		error;
typedef enum _fileopenmode
{
	read = 1,
	write = 2,
	append = 3,
	update = 4,
	binary = 8
} fileopenmode;
typedef enum _inttype
{
	num,
	hex,
	oct,
	dec,
	udec
}		inttype;
typedef enum _floattype
{
	exponentl,
	exponentu,
	floating,
	compactl,
	compactu,
	hexfloatl,
	hexfloatu
}	floattype;

#endif//__SimpleCEnums



typedef unsigned int uint; 