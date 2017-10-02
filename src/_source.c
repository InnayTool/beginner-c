#include "_include.h"

char getfloattype(floattype t)
{
	switch(t)
	{
	case exponentl:
		return 'e';
	case exponentu:
		return 'E';
	case floating:
		return 'f';
	case compactl:
		return 'g';
	case compactu:
		return 'G';
	case hexfloatl:
		return 'a';
	case hexfloatu:
		return 'A';
	}
}
char getinttype(inttype t)
{
	switch(t)
	{
	case dec:
		return 'd';
	case udec:
		return 'u';
	case hex:
		return 'x';
	case oct:
		return 'o';
	case num:
		return 'i';
	}				
}
