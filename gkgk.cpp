#include <stdio.h>
#include <string.h>
#include <assert.h>

int main()
{
    char empty_arr[5] = {0};
    char arr[] = "yes";

    assert(empty_arr == NULL);
    printf("%s", strcat(empty_arr, arr));
    
}