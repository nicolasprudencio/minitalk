#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void replaceSubstring(char *string, const char *find, const char *replace) {
    char *position;
    int findLen = strlen(find);
    int replaceLen = strlen(replace);

    // Find the first occurrence of 'find' in 'string'
    position = strstr(string, find);

    while (position != NULL) {
        // Replace 'find' with 'replace' in 'string'
        memmove(position + replaceLen, position + findLen, strlen(position + findLen) + 1);
        memcpy(position, replace, replaceLen);

        // Find the next occurrence of 'find' in 'string'
        position = strstr(position + replaceLen, find);
    }
}

int main() {
    FILE *file;
    char filename[100];
    char buffer[1000];

    printf("Enter the directory path: ");
    scanf("%s", filename);

    // Open each .c file in the specified directory
    file = popen("find $filename -type f -name '*.c'", "r");
    if (file == NULL) {
        printf("Error in opening directory.\n");
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), file)) {
        // Remove the newline character from the filename
        buffer[strcspn(buffer, "\n")] = '\0';

        // Open the .c file for reading and writing
        FILE *cfile = fopen(buffer, "r+");
        if (cfile == NULL) {
            printf("Error in opening file: %s\n", buffer);
            continue;
        }

        // Read the entire contents of the file into a buffer
        fseek(cfile, 0, SEEK_END);
        long fsize = ftell(cfile);
        fseek(cfile, 0, SEEK_SET);
        char *content = malloc(fsize + 1);
        fread(content, 1, fsize, cfile);
        content[fsize] = '\0';

        // Replace "fds" with "fds" in the file's content
        replaceSubstring(content, "fds", "fds");

        // Move the file pointer to the beginning and write the modified content
        fseek(cfile, 0, SEEK_SET);
        fwrite(content, 1, strlen(content), cfile);

        // Truncate the file if the new content is shorter than the original
        long newSize = ftell(cfile);
        if (newSize < fsize)
            ftruncate(fileno(cfile), newSize);

        // Close the file and free the allocated memory
        fclose(cfile);
        free(content);

        printf("Modified file: %s\n", buffer);
    }

    pclose(file);

    printf("Replacement completed.\n");

    return 0;
}

