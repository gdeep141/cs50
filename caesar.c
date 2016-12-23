#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int shiftupper(char index);
int shiftlower(char index);

int key;

int main(int argc, string argv[])
{
    if (argc != 2)
        {
            printf("Please enter one number \n");
            return 1;
        }

    key = atoi(argv[1]);
        
    string s = GetString();
    
    for (int i = 0, n = strlen(s); i < n; i++)
        {
            if ( isupper(s[i]) )
                shiftupper(s[i]);
            
            else if ( islower(s[i]) )
                shiftlower(s[i]);   
            
            else
                printf("%c", s[i]);
        }

    printf("\n");
}

//shift upper character
int shiftupper(char index)
{
    int alpha = index - 65;
    int encrypted = (alpha + key) % 26;
    printf("%c", encrypted + 65);
    
    return 0;
}

//shift lower character
int shiftlower(char index)
{
    int alpha = index - 97;
    int encrypted = (alpha + key) % 26;
    printf("%c", encrypted + 97);
    
    return 0;
}