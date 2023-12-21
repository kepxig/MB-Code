#include <stdio.h>
#include <string.h>

int main()
{
    char sentence[100];
    char subject[20] = "", verb[20] = "", object[20] = "";
    char* token;
    printf("Enter a sentence: ");
    fgets(sentence, 100, stdin);

    token = strtok(sentence, " ");

    while (token != NULL) {
        if (strcmp(token, "is") == 0 || strcmp(token, "are") == 0 || strcmp(token, "am") == 0) {
            strcpy(verb, token);
        }
        else if (strcmp(token, "a") != 0 && strcmp(token, "an") != 0 && strcmp(token, "the") != 0 && strcmp(token, "of") != 0 && strcmp(token, "in") != 0 && strcmp(token, "on") != 0 && strcmp(token, "at") != 0 && strcmp(token, "to") != 0 && strcmp(token, "for") != 0 && strcmp(token, "with") != 0) {
            if (subject[0] == '\0') {
                strcpy(subject, token);
            }
            else {
                strcpy(object, token);
            }
        }
        token = strtok(NULL, " ");
    }

    printf("%s %s %s", subject, verb, object);

    return 0;
}