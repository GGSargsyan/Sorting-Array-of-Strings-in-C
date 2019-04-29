#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char* a, const char* b) 
{
    return strcmp(a, b);
}

int lexicographic_sort_reverse(const char* a, const char* b) 
{
    return strcmp(b, a);
}

int distinct(const char* s) 
{
    int letters[26] = {0, }, total = 0;
    while (*s != '\0') 
    {
        if (letters[*s-'a'] == 0) 
        {
            total += 1;
            letters[*s-'a']++;
        }
        s++;
    }
    return total;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) 
{
    int res = distinct(a) - distinct(b);
    return (res) ? res : lexicographic_sort(a, b);
}

int sort_by_length(const char* a, const char* b) 
{
    int res = strlen(a) - strlen(b);
    return (res) ? res : lexicographic_sort(a, b);
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b))
{
    for (int i = 0; i < len; i++) 
    {
        for (int j = i; j > 0; j--) 
        {
            if (cmp_func(arr[j], arr[j-1]) <= 0) 
            {
                char *tmp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = tmp;
            }
            else {
                break;
            }
        }
    }
}


int main() 
{
    int n;
    FILE *f = fopen("Sample Input 0", "r");
    FILE *c = fopen("Sample Out 0", "w");
    //scanf("%d", &n);
    
    fscanf(f, "%d", &n);
   
    char** arr;
    arr = (char**)malloc(n * sizeof(char*));
    
    //uncomment these if reading in from std input
    for(int i = 0; i < n; i++)
    {
        *(arr + i) = malloc(1024 * sizeof(char));
        fscanf(f, "%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
    fclose(f);
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
    {
        //printf("%s\n", arr[i]);
        fprintf(c, "%s\n", arr[i]);
    }
    //printf("\n");
    fprintf(c, "\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
    {
        //printf("%s\n", arr[i]);
        fprintf(c, "%s\n", arr[i]);
    }
    //printf("\n");
    fprintf(c, "\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
    {
        //printf("%s\n", arr[i]);
        fprintf(c, "%s\n", arr[i]);
    }
    //printf("\n");
    fprintf(c, "\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
    {
        //printf("%s\n", arr[i]);
        fprintf(c, "%s\n", arr[i]);
    }
    //printf("\n");
    fprintf(c, "\n");
    
    fclose(c);
}