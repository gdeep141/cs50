#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int keyvalue(char index);
int encrypt(char messageindex, int keyvalue);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("please enter only one keyword\n");
        return 1;
    }
    
    //ensures all characters of key are letters    
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (isalpha(argv[1][i]) == 0) //returns 0 = False, 1 = True
            {
                printf("please enter a key containing only letters\n");
                return 1;
            }
        }

    string key = argv[1];
    string message = GetString();
    int y = strlen(key);
    
    for (int i = 0, n = strlen(message), j = i; i < n; i++)
    {
        if ( isalpha(message[i]) )
        {
            encrypt( message[i], keyvalue( key[j % y]) );
            j++;
        }

        else 
            printf("%c", message[i]);
    }  
    printf("\n");
}

//convert key index to numeric value for encryption
int keyvalue(char index)
{
    if ( isupper(index) )
        return index - 65;
        
    else
        return index - 97;
}

//encrypt message index using key value
int encrypt(char messageindex, int keyvalue)
{
    int encrypted;  //middle step in calculation
    
    if ( isupper(messageindex) )
    {
        encrypted = (messageindex - 65 + keyvalue) % 26;
        printf("%c", encrypted + 65);
    }
    
    else if ( islower(messageindex) )
    {
        encrypted = (messageindex - 97 + keyvalue) % 26;
        printf("%c", encrypted + 97);
    }
    return 0;
}