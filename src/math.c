#include "math.h"
#include "_include.h"

double sgn(double value)
{
	if(value < 0)
		return -1;
	else if(value > 0)
		return 1;
	else
		return 0;
}
float  sgnf(float value)
{
	if(value < 0)
		return -1;
	else if(value > 0)
		return 1;
	else
		return 0;
}
long double sgnl(long double value)
{
	if(value < 0)
		return -1;
	else if(value > 0)
		return 1;
	else
		return 0;
}

double ln(double value)
{
	return log(value);
}
float lnf(float value)
	{
	return logf(value);
}
long double lnl(long double value)
{
	return logl(value);
}

double lg(double value)
{
	return log10(value);
}
float lgf(float value)
{
	return log10f(value);
}
long double lgl(long double value)
{
	return log10l(value);
}

double logx(double value, double base)
{
	return log(value)/log(base);
}
float logxf(float value, float base)
{
	return logf(value)/logf(base);
}
long double logxl(long double value, long double base)
{
	return logl(value)/logl(base);
}

double root(double value, double ex)
{
	return pow(value, 1/ex);
}
float rootf(float value, float ex)
{
	return powf(value, 1/ex);
}
long double rootl(long double value, long double ex)
{
	return powl(value, 1/ex);
}

double acosh(double value)
{
	return ln(value + sqrt(value*value - 1));
}
float acoshf(float value)
{
	return lnf(value + sqrtf(value*value - 1));
}
long double acoshl(long double value)
{
	return lnl(value + sqrtl(value*value - 1));
}

double asinh(double value)
{
	return ln(value + sqrt(value*value + 1));
}
float asinhf(float value)
{
	return lnf(value + sqrtf(value*value + 1));
}
long double asinhl(long double value)
{
	return lnl(value + sqrtl(value*value + 1));
}

double atanh(double value)
{
	return ln((1 + value)/(1 - value));
}
float atanhf(float value)
{
	return lnf((1 + value)/(1 - value));
}
long double atanhl(long double value)
{
	return lnl((1 + value)/(1 - value));
}

double sum(double (*func)(int64_t value), int64_t start, int64_t end)
{
	double result = 0;
	int64_t i;
	for(i = start; i <= end; ++i)
		result += func(i);
	return result;
}
float sumf(float (*func)(int64_t value), int64_t start, int64_t end)
{
	float result = 0;
	int64_t i;
	for(i = start; i <= end; ++i)
		result += func(i);
	return result;
}
long double suml(long double (*func)(int64_t value), int64_t start, int64_t end)
{
	long double result = 0;
	int64_t i;
	for(i = start; i <= end; ++i)
		result += func(i);
	return result;
}

double product(double (*func)(int64_t value), int64_t start, int64_t end)
{
	double result = 1;
	int64_t i;
	for(i = start; i <= end; ++i)
		result *= func(i);
	return result;
}
float productf(float (*func)(int64_t value), int64_t start, int64_t end)
{
	float result = 1;
	int64_t i;
	for(i = start; i <= end; ++i)
		result *= func(i);
	return result;
}
long double productl(long double (*func)(int64_t value), int64_t start, int64_t end)
{
	long double result = 1;
	int64_t i;
	for(i = start; i <= end; ++i)
		result *= func(i);
	return result;
}
