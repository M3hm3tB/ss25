#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>


static void die(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}


int main(void){
    char *template = read_from_file("template.txt");
}




char *read_from_file(const char*filename){
    FILE *file = fopen(filename, "r");
    if (!file) die ("fopen");

    size_t bufsize = 10;
    size_t len = 0;
    char *buf = malloc(bufsize);
    if (!buf) die("malloc");

}



pid_t send_email(char *template, char *name, char *email)