#include <stdio.h>
#include <stdarg.h>

int isTriangle(int x, int y, int z)
{
  return x < y + z && y < x + z && z < x + y ? 1 : 0;
}

int triangle(int n, ...)
{
  if (n < 3) {
    printf("Less of parameters!");
    return 0;
  }
  int result = 0;
  va_list ptr;
  va_start(ptr, n);
  int x = va_arg(ptr, int);
  int y = va_arg(ptr, int);
  int z = va_arg(ptr, int);
  printf("n = %d\n%d  %d  %d", n, x, y, z);
  if (isTriangle(x, y, z)) result++;
  for (int i = 0; i < n - 3; i++)
  {
    x = y;
    y = z;
    z =  va_arg(ptr, int);
    printf("  %d", z);
    if (isTriangle(x, y, z)) result++;
  }
  return result;
}

int main(void)
{

  printf("triangle:\n");
  int res = triangle(3, 1, 2, 3);
  printf("\nNumber of next to stayed points that may be edges of triangle: %d\n\n", res);

  printf("triangle:\n");
  res = triangle(9, 5, 4, 3, 5, 11, 2, 9, 2, 1);
  printf("\nNumber of next to stayed points that may be edges of triangle: %d\n\n", res);

  printf("triangle:\n");
  res = triangle(11, 1, 2, 3, 6, 4, 7, 2, 5, 4, 3, 5);
  printf("\nNumber of next to stayed points that may be edges of triangle: %d\n\n", res);

  getchar();
  return 0;
} 
