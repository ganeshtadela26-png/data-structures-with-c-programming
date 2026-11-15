#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    if (top != -1)
        return stack[top--];

    printf("Error: Stack Underflow\n");
    exit(1);
}

char peek()
{
    if (top != -1)
        return stack[top];

    return '\0';
}

int priority(char ch)
{
    if (ch == '(')
        return 0;
    else if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '^')
        return 3;
    else
        return 0;
}

void reverseString(char str[])
{
    int i, j;
    char temp;

    for (i = 0, j = strlen(str) - 1; i < j; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main()
{
    char string[100], rev[100];
    int i = 0;
    char *ptr;
    char x;

    printf("Enter the expression: ");
    fgets(string, sizeof(string), stdin);

    /* Remove newline */
    string[strcspn(string, "\n")] = '\0';

    /* Reverse the input */
    reverseString(string);

    /* Interchange brackets */
    for (i = 0; string[i] != '\0'; i++)
    {
        if (string[i] == '(')
            string[i] = ')';
        else if (string[i] == ')')
            string[i] = '(';
    }

    ptr = string;
    i = 0;

    while (*ptr != '\0')
    {
        if (isalnum((unsigned char)*ptr))
        {
            rev[i++] = *ptr;
        }

        else if (*ptr == '(')
        {
            push(*ptr);
        }

        else if (*ptr == ')')
        {
            while (top != -1 && peek() != '(')
            {
                x = pop();
                rev[i++] = x;
            }

            if (top != -1 && peek() == '(')
                pop();
        }

        else
        {
            while (top != -1 &&
                   priority(peek()) > priority(*ptr))
            {
                x = pop();
                rev[i++] = x;
            }

            push(*ptr);
        }

        ptr++;
    }

    /* Pop remaining operators */
    while (top != -1)
    {
        x = pop();
        rev[i++] = x;
    }

    rev[i] = '\0';

    /* Reverse postfix result to get prefix */
    reverseString(rev);

    printf("Prefix expression: %s\n", rev);

    return 0;
}