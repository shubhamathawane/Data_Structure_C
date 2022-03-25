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
