#include <stdio.h>
#include <math.h>

long int fact (int n)
{
if (n <= 1)
{
return 1;
}
else
{
return n * fact (n - 1);
}
}

double bin (long int n, long int k)
{
return 1.0 * fact (n) / fact (k) / fact (n - k);
}

double bernoulli (long int n)
{
if (n <= 0)
{
return 1.0;
}
else
{
double sum = 0;
for (long k = 1; k <= n; k++)
{
sum += bin (n + 1, k + 1) * bernoulli (n - k);
}
return -1.0 / (n + 1) * sum;
}
}

int main ()
{
double x;
scanf ("%lf", &x);
double cur = 1.0 / x;
double perf = (exp (x) + exp (-x)) / (exp (x) - exp (-x));
double eps = perf / 1000;
int counter = 1;
do
{
cur = cur + pow (2, 2 * counter) * bernoulli (2 * counter) * pow (x, 2 * counter - 1) / fact (2 * counter);
counter += 1;

}
while (fabs (cur - perf) > eps);
printf ("%lf", cur);
return 0;
}
