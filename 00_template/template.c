#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *fi;
FILE *fo;

void solveCase(unsigned n)
{
    // TODO : Solve Test Case Here

    fprintf(fo, "Case #%u: \n", n+1);
}

// Performs string magic to basically replace input_xxxx.txt with output_xxxx.txt
char *getOutName(char *inName) {
    char *outName;
    unsigned len;

    // Should be always 14, but I don't know for sure 
    len = strlen(inName);

    // Allocating Space for the Output Name
    outName = (char * ) malloc(sizeof(char) * len + 2);
    
    // Copying "output"
    strcpy(outName, "output");
    // Copying "_xxxx.txt"
    strcpy(outName + 6, inName + 5);

    return outName;
}

int main(int argc, char *argv[])
{

    char * in_name;
    char * ot_name;

    unsigned TN;

    // Get File Names or Complain
    if (argc != 2) {
        fprintf(stderr, "Error. Please Provide a File.\n");
        exit(1);
    }

    in_name = argv[1];
    ot_name = getOutName(in_name);

    // Open Files or Complain
    fi = fopen(in_name, "r");
    fo = fopen(ot_name, "w");

    if (fi == NULL || fo == NULL)
    {
        fprintf(stderr, "Ouch. Could not Open Files.\n");
        fprintf(stderr, "Does `%s` exists?\n", in_name);
        exit(1);
    } else printf("Works.\n");


    // Get the number of test Cases
    fscanf(fi, "%u", &TN);

    for (unsigned tc = 0; tc < TN; tc++) {
        // TODO : Interpret Input File Here and pass to `solveCase`
    
        solveCase(tc);
    }

    // Close Files
    fclose(fo);
    fclose(fi);

    return 0;
}
