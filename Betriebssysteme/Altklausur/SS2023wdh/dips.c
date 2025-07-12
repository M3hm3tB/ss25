#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <errno.h>
#include "sem.h"
#include "sha1.h"

#define MAX_FILES 200

static void die(const char msg[]) {
    perror(msg);
    exit(EXIT_FAILURE);
}

static void err(const char msg[]) {
    fprintf(stderr, "%s", msg);
    exit(EXIT_FAILURE);
}

typedef struct file {
    char* name;
    char* hash;
} file_t;

static file_t files[MAX_FILES];
static size_t file_count = 0;
static size_t error_count = 0;
static size_t finished_count = 0;

int main(void){
    size_t anzahlFile = parse_file();
    if (anzahlFile == 0){
        printf("Keine Einträge")
        return EXIT_SUCCESS;
    } 

    if(sem_init(&thread_sem, 0, 10) != 0){
        die("sem_init");
    }
}

size_t parse_file(void){
    FILE *file = fopen("checksums.txt", "r");
    if (!file) die("fopen");

    char line[300];
    size_t idx = 0;

    while (fgets(line, sizeof line, file)){
        size_t len = strlen(line);
        if (len > 0 && (line[line-1] == '\n')) 
        line[--len] = '\0'      
        
        char *seperator = strchr(line, '/');
        if (!seperator) die("strchr")
        *seperator = '\0';
        char *name = line;
        char *hash = seperator + 1;

        size_t namelen = strlen(name);
        if(namelen == 0 || namelen > 256)
            err("Dateiname zu lang oder leer");
        if(strlen(hash) != 40)
            err("Hash hat nicht genau 40 Zeichen");

        files[idx].name = strdup(name);
        files[idx].hash = strdup(hash);

        idx++;
    }

    fclose(file);
    file_count = idx;
    return idx;
}

void *thread_start(void *sfile){

}