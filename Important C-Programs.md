### 1. Leap Year Program

 Leap years are the year where an extra, or intercalary, days is added to the end of the shortest month, February. 

If a year is exactly divisible by 4 and not divisible by 100 then it’s a Leap year. Else if year is exactly divisible by 400 then its’ Leap year. Else it’s a Common year.

```c
#include <stdio.h>

int main()
{
	int year;
	scanf("%d", &year);
	if ((year % 400 == 0) || (year % 4 == 0 && year % 100 == 0))
	{
		printf("%d is a leap year", year);
	}
	else
	{
		printf("%d is not leap year", year);
	}

	return 0;
}
```

### 2. Factorial Program

Factorial of number(n) is the product of all positive descending integers. Factorial of  n is denoted by N!

Example : `5! = 5*4*3*2*1  = 120`

```c
// Factorial in C without recursion..
#include <stdio.h>

int main()
{
    int num, i;
    long int fact;
    printf("Enter an Integer Number : ");
    scanf("%d", &num);

    fact = 1;

    for (i = num; i >= 1; i--)
    {
        fact *= i;
    }
    printf("Factorial of %d is %ld ", num, fact);

    return 0;
}
```

### 3. Reverse Numbers.

The logic Used to reverse a number is also Used in palindrome, Armstrong or to find sum of digits of a number with a little change in it.

```c
// Reverse a Number in C
#include <stdio.h>

int main()
{
    int n, reverse = 0, rem;
    printf("Enter a number : ");
    scanf("%d", &n);

    while (n != 0)
    {
        rem = n % 10;
        reverse = reverse * 10 + rem;
        n /= 10;
    }
    printf("Reversed Number: %d", reverse);
    return 0;
}
```

### 4. 3 Ways to Swap two numbers:

```c
//3 ways to swap the numbers in c
#include <stdio.h>

int main()
{
    int num1, num2;
    int temp;

    printf("Etner First Number : ");
    scanf("%d", &num1);
    printf("Etner Second Number : ");
    scanf("%d", &num2);

    // Using 3rd variable
    temp = num1;
    num1 = num2;
    num2 = temp;
    printf("\nUsing 3rd Variable : ");
    printf("\nFirst Number %d and Second Number %d", num1, num2);

    // Without using 3rd variable
    num1 = num1 + num2;
    num2 = num1 - num2;
    num1 = num1 - num2;
    printf("\nWithout using 3rd Variable : ");
    printf("\nFirst Number %d and Second Number %d", num1, num2);

    // using XOR operator
    num1 = num1 ^ num2;
    num2 = num2 ^ num1;
    num1 = num1 ^ num2;
    printf("\nusing XOR Operator : ");
    printf("\nFirst Number %d and Second Number %d", num1, num2);

    return 0;
}
```

### 5. Perfect Number Program

A perfect number is a positive integer that is equal to the sum of it’s positive divisors, excluding the number itself.

**Example**: `6 (1+2+3) = 6`

```c
// C Program to check whether the given number is th Perfect Number
#include <stdio.h>

int main()
{
    int num, rem, sum = 0, i;
    printf("Enter a number : ");
    scanf("%d", &num);

    // find all divisors and add them
    for (i = 1; i < num; i++)
    {
        rem = num % i;
        if (rem == 0)
        {
            sum += i;
        }
    }

    if (sum == num)
    {
        printf("%d is a Perfect Number : ", num);
    }
    else
    {
        printf("%d is not a Perfect Number : ", num);
    }
    return 0;
}
```

### 6. Fibonacci Series Without recursion:

In case of Fibonacci series, next number is the sum of previous two numbers for example `0,1,1,2,3,5,8,13` etc. The first two numbers of Fibonacci series are 0 and 1.

```c
// Fibpnacci Series withou recursion:
#include <stdio.h>
int main()
{
    int n1 = 0, n2 = 1, n3, i, number;
    printf("Enter the number of elements : ");
    scanf("%d", &number);
    printf("\n%d %d", n1, n2); // printing 0 and 1;
    // loop starts from 2 because 0 and 1 are already printed
    for (i = 2; i < number; i++)
    {
        n3 = n1 + n2;
        printf(" %d", n3);
        n1 = n2;
        n2 = n3;
    }
    return 0;
}
```

### 7. Fibonacci Series using recursion:

Many people prefers to code some programs like factorial or  Fibonacci using recursion method. for those you don’t know about recursion, “When a function calls itself it is call recursion”.

```c
// Fibonacci series program in c using recursion
#include <stdio.h>
void printfFibonacci(int n)
{
    static int n1 = 0, n2 = 1, n3;
    if (n > 0)
    {
        n3 = n1 + n2;
        n1 = n2;
        n2 = n3;
        printf("%d ", n3);
        printfFibonacci(n - 1);
    }
}
int main()
{
    int n;
    printf("Enter the number of element : ");
    scanf("%d", &n);
    printf("Fibonacci Series : ");
    printf("%d %d ", 0, 1); // Printing 0 and 1
    printfFibonacci(n - 2); // n-2 because 2 numbers are already printed

    return 0;
}
```

### 8. Prime Numbers Program

Prime number is a number that is greater than 1 and divided by 1 or itself.

Example : `2,3,5,7,13` etc.

**Fact**: 2 is the only even prime number.

```c
// C Program to find prime number
#include <stdio.h>
int main()
{
    int n, i, m = 0, flag = 0;
    printf("Enter the number to check prime : ");
    scanf("%d", &n);
    m = n / 2;
    for (i = 2; i <= m; i++)
    {
        if (n % i == 0)
        {
            printf("Number is not prime");
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        printf("Number is prime");
    }
    return 0;
}
```

### 9. Palindrome Program

A palindrome number is a number that is same after reverse.

For example : `121, 34543, 343,131,48984` are the palindrome numbers.

```c
// C Program to find palindrome
#include <stdio.h>
int main()
{
    int n, r, sum = 0, temp;
    printf("Enter the number : ");
    scanf("%d", &n);
    temp = n;
    while (n > 0)
    {
        r = n % 10;
        sum = (sum * 10) + r;
        n = n / 10;
    }
    if (temp == sum)
    {
        printf("Number is palindrome");
    }
    else
    {
        printf("Number is not palindrome");
    }
    return 0;
}
```

### 10. Armstrong Number:

Armstrong number is a number that is equal to the sum of cubes of it’s digits. For example `0,1,153,370, and 407` are the Armstrong numbers.

Example : `153 = (1*1*1)+(5*5*5)+(3*3*3)`

```c
// Program to check Armstrong Number in c.
#include <stdio.h>
int main()
{
    int n, r, sum = 0, temp;
    printf("Enter the number : ");
    scanf("%d", &n);
    temp = n;
    while (n > 0)
    {
        r = n % 10;
        sum = sum + (r * r * r);
        n = n / 10;
    }
    // Check sum of cubes is equal to original no.
    if (temp == sum)
    {
        printf("%d Number is armstrong", temp);
    }
    else
    {
        printf("%d Number is not armstrong", temp);
    }
    return 0;
}
```
