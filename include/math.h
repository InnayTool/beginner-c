#include "types.h"

#define pi 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
#define e  2.7182818284590452353602874713526624977572470936999595749669676277240766303535475945713821785251664274

double sgn(double value);
float  sgnf(float value);
long double sgnl(long double value);

double ln(double value);
float lnf(float value);
long double lnl(long double value);

double lg(double value);
float lgf(float value);
long double lgl(long double value);

double logx(double value, double base);
float logxf(float value, float base);
long double logxl(long double value, long double base);

double root(double value, double ex);
float rootf(float value, float ex);
long double rootl(long double value, long double ex);

double acosh(double value);
float acoshf(float value);
long double acoshl(long double value);

double asinh(double value);
float asinhf(float value);
long double asinhl(long double value);

double atanh(double value);
float atanhf(float value);
long double atanhl(long double value);

double sum(double (*func)(int64_t value), int64_t start, int64_t end);
float sumf(float (*func)(int64_t value), int64_t start, int64_t end);
long double suml(long double (*func)(int64_t value), int64_t start, int64_t end);

double product(double (*func)(int64_t value), int64_t start, int64_t end);
float productf(float (*func)(int64_t value), int64_t start, int64_t end);
long double productl(long double (*func)(int64_t value), int64_t start, int64_t end);