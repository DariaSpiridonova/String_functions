#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define STLEN 40

char *my_fgets(char *arr, const int n, FILE *fp);
int my_puts(const char *str);
char *my_strchr(const char *str, int ch);
size_t my_strlen(const char *str);
char *my_strcpy(char *dest, const char *src);
char *my_strncpy(char *dest, const char *src, size_t count);
char *my_strcat(char *dest, const char *src);
char *my_strncat(char *dest, const char *src, size_t count);
char *my_strdup(const char *str1);
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream);
void test_my_fgets();
void test_my_puts();
void test_my_strchr();
void test_my_strlen();
void test_my_strcpy();
void test_my_strncpy();
void test_my_strcat();
void test_my_strncat();
void test_my_strdup();
void test_my_getline();

int main()
{
    test_my_fgets();
    test_my_puts();
    test_my_strchr();
    test_my_strlen();
    test_my_strcpy();
    test_my_strncpy();
    test_my_strcat();
    test_my_strncat();
    test_my_strdup();
    test_my_getline();

    return 0;
}

void test_my_fgets()
{
    FILE *fp = fopen("test_string.exe", "r");

    char string[STLEN] = {};
    char *str = my_fgets(string, STLEN, fp);

    fclose(fp);

    if (strcmp(str, "Hello to everyone!\n") == 0 && strcmp(str, string) == 0)
        printf("fgets success\n");
    else
        printf("fgets fail, expected <str> = <string> = <Hello to everyone!\n>, get <str> = <%s>, <string> = <%s>", str, string);
}

void test_my_puts()
{
    char str[] = "Hello world!";
    int result = 0;

    printf("my_puts prints ");

    if ((result = my_puts(str)) == 1)
    {
        printf("my_puts success\n");
    }
    else
        printf("my_puts failed\n");
}

void test_my_strchr()
{
    char str[] = "Hello world!";
    char *symbol = &str[6];

    if (strcmp(my_strchr(str, 'w'), symbol) == 0)
        printf("my_strchr success\n");
    else
        printf("my_strchr fail, expected <str> = <world!>, symbol = <w>, get <str> = <%s>, symbol = <%c>\n", my_strchr(str, 'w'), *my_strchr(str, 'w'));
}

void test_my_strlen()
{
    char str[] = "Hello world!";

    if (my_strlen(str) == 12)
        printf("my_strlen success\n");
    else
        printf("my_strlen fail, expected length = 12, get length = %d\n", my_strlen(str));
}

void test_my_strcpy()
{
    const char str1[] = "Hello, world!";
    char str2[STLEN] = {};
    my_strcpy(str2, str1);
    if (strcmp(str1, str2) == 0)
        printf("my_strcpy success\n");
    else
        printf("my_strcpy fail, expected str2 = %s, get str2 = %s\n", str1, str2);
}

void test_my_strncpy()
{
    const char str1[] = "Hello, world!";
    char str2[STLEN] = {};
    my_strncpy(str2, str1, 7);
    if (strcmp("Hello, ", str2) == 0)
        printf("my_strncpy success\n");
    else
        printf("my_strncpy fail, expected str2 = <Hello, >, get str2 = %s\n", str2);
}

void test_my_strcat()
{
    char str1[STLEN] = "Hello, ";
    const char str2[] = "my beautiful world!";
    my_strcat(str1, str2);
    if (strcmp(str1, "Hello, my beautiful world!") == 0)
        printf("my_strcat success\n");
    else
        printf("my_strcat fail, expected <str1> = <Hello, my beautiful world!>, get <str1> = <%s>\n", str1);
}

void test_my_strncat()
{
    char str1[STLEN] = "Hello, ";
    const char str2[] = "my beautiful world!";
    my_strncat(str1, str2, 12);
    if (strcmp(str1, "Hello, my beautiful") == 0)
        printf("my_strncat success\n");
    else
        printf("my_strncat fail, expected <str1> = <Hello, my beautiful>, get <str1> = <%s>\n", str1);
}

void test_my_strdup()
{
    const char str1[] = "Hello, world!";
    char *str1_copy = my_strdup(str1);

    if (strcmp(str1, str1_copy) == 0)
        printf("my_strdup success\n");
    else
        printf("my_strdup fail, expected str1_copy = <Hello, world!>, get str1_copy = %s\n", str1_copy);
}

void test_my_getline()
{
    size_t n = 1;
    char *pointer = (char *)calloc(n, sizeof(char));

    FILE *fp = fopen("test_string.exe", "r");

    ssize_t num_of_items_read = 18;

    if (num_of_items_read == my_getline(&pointer, &n, fp))
        printf("my_getline success\n");
    else
        printf("my_getline fail, expected num_of_items_read = 18, get num_of_items_read = %d\n", num_of_items_read);

    fclose(fp);
}

char *my_fgets(char *arr, const int n, FILE *fp)
{
    unsigned char ch = (unsigned char)fgetc(fp);
    if (ch == EOF)
        return NULL;
    if (ch == '\n')
        return NULL;
    *arr = ch;

    int i = 0;
    while ((ch = (unsigned char)fgetc(fp)) != EOF && i < n - 1 && ch != '\n')
    {
        arr[++i] = ch;
    }
    if (ch == '\n')
        arr[++i] = '\n';
    arr[++i] = '\0';

    return arr;
}

int my_puts(const char *str)
{
    if (str == NULL)
        return EOF;
    while (*str != '\0')
    {
        putc(*str++, stdout);
    }
    putc('\n', stdout);

    return 1;
}

char *my_strchr(const char *str, int ch)
{
    const char *symbol = NULL;
    while (*str != '\0')
    {
        if (*str == (char)ch)
        {
            symbol = str;
            return (char *)symbol;
        }
        str++;
    }
    if (ch == '\0') return (char *)str;

    return (char *)symbol;
}

size_t my_strlen(const char *str)
{
    assert(str != NULL);

    size_t length = 0;
    while (*str++ != '\0')
        length++;

    return length;
}

char *my_strcpy(char *dest, const char *src)
{
    return my_strncpy(dest, src, __SIZE_MAX__);
}

char *my_strncpy(char *dest, const char *src, size_t count)
{
    assert(dest != NULL && src != NULL);

    size_t i = 0;
    while (i < count && src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';

    return dest;
}

char *my_strcat(char *dest, const char *src)
{
    return my_strncat(dest, src, __SIZE_MAX__);
}

char *my_strncat(char *dest, const char *src, size_t count)
{
    assert(dest != NULL && src != NULL);

    size_t len = 0;

    while (dest[len] != '\0')
        len++;

    size_t i = 0;
    while (src[i] != '\0' && i < count)
        dest[len++] = src[i++];
    dest[len] = '\0';

    return dest;
}

char *my_strdup(const char *str1)
{
    int n = STLEN;
    char *str_copy = (char *)malloc(n);

    char ch = 0;
    int i = 0, count = 0;
    while ((ch = str1[i]) != '\0')
    {
        if (i < n)
        {
            str_copy[i] = ch;
            i++;
            count++;
        }
        if (i == n)
        {
            str_copy = (char *)realloc(str_copy, n * 2);
            n *= 2;
        }
    }
    str_copy[i] = '\0';

    return str_copy;
}

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
    if (stream == NULL)
        return -1;

    if (*lineptr == NULL)
    {
        *lineptr = (char *)calloc(8, sizeof(char));
        *n = 8;
    }

    char ch = 0;
    size_t count = 0;
    while ((ch = (char)fgetc(stream)) != '\n' && ch != '\0' && ch != EOF)
    {
        if (count < *n - 1)
        {
            (*lineptr)[count] = ch;
            count++;
        }
        if (count == *n - 1)
        {
            *n *= 2;
            *lineptr = (char *)realloc(*lineptr, *n);
        }
    }
    if (ch == '\n')
        (*lineptr)[count++] = '\n';
    (*lineptr)[count] = '\0';

    *n = count;

    return *n;
}