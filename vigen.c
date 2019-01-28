/* Includes. */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <cs50.h>


int main(int argc, char *argv[])
{
    /* Initialyzing variables. */
    string uppers = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string lowers = "abcdefghijklmnopqrstuvwxyz";


    /* Validating the arguments. */
    if (argc == 2)
    {
        string keyword = argv[1];

        for (int k = 0; k < strlen(keyword);)
        {
            if (isalpha(keyword[k]))
            {
                ++k;
            }
            else
            {
                printf("%s\n", "Invalid keyword.");
                return 1;
            }
        }

        /* Prompt the user for the text to encrypt. */
        string p_text = get_string("plaintext: ");


        int key;
        char k_char;

        printf("ciphertext: ");

        int i = 0;  // This will iterate over the plain text.
        int j = 0;  // This will iterate over the keyword.

        while (i < strlen(p_text))
        {
            if (isalpha(p_text[i]))
            {
                // To turn around the keyword.
                // Test if j = strlen(keyword) and set to 0 if true.
                if (j == strlen(keyword))
                {
                    j = 0;
                }

                else
                {
                    //Take one key from keyword each round.
                    if (isupper(p_text[i]))  /* Uppercase encrypting. */
                    {
                        //Get its value-index-
                        k_char = keyword[j];
                        if (isupper(k_char))
                        {
                            key = k_char - 65;
                        }

                        else
                        {
                            key = k_char - 97;
                        }
                        //Use it as the key to encrypt.
                        int u_ch = (int) p_text[i];
                        char up_c = uppers[((u_ch - 65) + key) % 26];
                        printf("%c", up_c);
                        ++i;
                        ++j;
                    }

                    else if (islower(p_text[i]))  /* Lowercase encrypting. */
                    {
                        //Get its value-index-
                        k_char = keyword[j];
                        if (isupper(k_char))
                        {
                            key = k_char - 65;
                        }

                        else
                        {
                            key = k_char - 97;
                        }
                        //Use it as the key to encrypt.
                        int l_ch = (int) p_text[i];
                        char low_c = lowers[((l_ch - 97) + key) % 26];
                        printf("%c", low_c);
                        ++i;
                        ++j;
                    }
                }
            }

            else
            {
                printf("%c", p_text[i]);
                ++i;
            }
        }
        printf("\n");
        return 0;
    }

    else
    {
        printf("%s\n", "Invalid entry");
        return 1;
    }
}