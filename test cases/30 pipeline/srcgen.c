#include<stdio.h>
#include<assert.h>

int main(int argc, char **argv) {
    const int ARRSIZE = 80;
    char arr[ARRSIZE];
    if(argc != 3) {
        fprintf(stderr, "%s <input file> <output file>\n", argv[0]);
        return 1;
    }
    char *ifilename = argv[1];
    char *ofilename = argv[2];
    printf("%s\n", ifilename);
    FILE *ifile = fopen(ifilename, "r");
    if(!ifile) {
        fprintf(stderr, "Could not open source file %s.\n", ifilename);
        return 1;
    }
    FILE *ofile = fopen(ofilename, "w");
    if(!ofile) {
        fprintf(stderr, "Could not open target file %s\n", ofilename);
        return 1;
    }
    size_t bytes;
    bytes = fread(arr, 1, ARRSIZE, ifile);
    assert(bytes < 80);
    assert(bytes > 0);
    fwrite(arr, 1, bytes, ofile);

    fclose(ifile);
    fclose(ofile);
    return 0;
}