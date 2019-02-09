#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#define MASK 0555

int main(int argc, char *argv[]){
    struct stat buf[1];
    mode_t mode;
    if (stat(argv[1], buf) != 0) {
        fprintf(stderr, "Cannot read i-node\n");
        exit(1);
    }
    mode = (buf[0].st_mode & MASK);
    if (chmod(argv[1], mode) != 0) {
        fprintf(stderr, "Cannot change mode\n");
    }
    return 0;
}
