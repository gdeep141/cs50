#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int decrypt_lower(char character, int key);
int decrypt_upper(char character, int key);

int main(void)
{
    printf("Please enter code to be decrypted: \n");
    string s = GetString();
    
    printf("Do you know the key used to encrypt this message? (y/n) ");
    string yesno = GetString();
    if ( strcmp(yesno, "y") == 0 )
    {
        printf("Please enter the key used to decrypt this message: ");
        int key = GetInt();
        
        for (int i = 0, n = strlen(s); i < n; i++)
        {
            if ( islower(s[i]) )
                decrypt_lower(s[i], key);
            
            else if ( isupper(s[i]) )
                decrypt_upper(s[i], key);
            
            else
                printf("%c", s[i]);
        }
    }
    
    else if ( strcmp(yesno, "n") == 0 )
    {
        for (int key = 0; key < 26; key++)
        {
            for (int i = 0, n = strlen(s); i < n; i++)
            {
                if ( islower(s[i]) )
                    decrypt_lower(s[i], key);
                
                else if ( isupper(s[i]) )
                    decrypt_upper(s[i], key);
                
                else
                    printf("%c", s[i]);
            }
            printf("\n");
        }
    }
    
    printf("\n");
}

int decrypt_lower(char character, int key)
{
    character = character - 97;
    if (character - key >= 0)
    {
        int decrypted = (character - key) % (27 - key);
        printf("%c", decrypted + 97);
    }
    
    else
    {
        int decrypted = 26 - (key % 26); 
        printf("%c", decrypted + 97);
    }
    return 0;
}

int decrypt_upper(char character, int key)
{
    character = character - 65;
    if (character - key >= 0)
    {
        int decrypted = character - key;
        printf("%c", decrypted + 65);
    }
    else
    {
        int decrypted = 26 - (26 % key);
        printf("%c", decrypted + 65);
    }
    return 0;
}