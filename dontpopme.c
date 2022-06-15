#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *path = "/bin/ls";
char *arg = "-la";

void change()
{
    printf("[*] Hmmm ... change is in the air but we aren't quite there.\n");
    path = "/bin/uname";
    arg = "-a";
}


void runCode()
{
    printf("[*] If you figure out my name, you are hired.\n");
    execl(path, arg, NULL);
}


int main(int argc, char **argv) {
    char humanName[5];
    char resumeText[8];

    printf("[*] LEAK! Main is at %p\n", &main);

    printf("[*] Enter your name and make sure you have uploaded resume.txt!!\n");
    scanf("%5s", humanName);

    printf("[*] Checking now for resume.txt..\n");
    if (access("resume.txt", F_OK) == 0) {
    // file exists
      printf("[*] Resume.txt found, reading contents now\n");
      FILE *resume=fopen("resume.txt","rb");
      fseek(resume,0,SEEK_END);
      size_t fs = ftell(resume);
      fseek(resume, 0, SEEK_SET);
      fread(resumeText, 1, fs, resume);
      fclose(resume);
    } else {
    // file doesn't exist
      printf("[*] Your silly ass didnt upload a file.\n");
    }

    return 0;
}
