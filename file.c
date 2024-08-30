/*
* Copyright (c) 2024, Patrick Wilmes <p.wilmes89@gmail.com>
* All rights reserved.
*
* SPDX-License-Identifier: BSD-2-Clause
*/
#include "file.h"
#include <stdio.h>
#include <stdlib.h>

char * file_read(const char * filename) {
    FILE *file =  fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "File could not be opened\n");
        return NULL;
    }

    if (fseek(file, 0, SEEK_END) != 0) {
        fprintf(stderr, "fseek to end of file failed\n");
        fclose(file);
        return NULL;
    }

    const long file_size = ftell(file);
    if (file_size == -1) {
        fprintf(stderr, "ftell to end of file failed\n");
        fclose(file);
        return NULL;
    }

    if (fseek(file, 0, SEEK_SET) != 0) {
        fprintf(stderr, "fseek to begin of file failed\n");
        fclose(file);
        return NULL;
    }

    char *buffer = (char*)malloc(file_size + 1);
    if (!buffer) {
        fprintf(stderr, "malloc failed\n");
        fclose(file);
        return NULL;
    }

    size_t read_size = fread(buffer, 1, file_size, file);
    if (read_size != file_size) {
        fprintf(stderr, "fread failed\n");
        free(buffer);
        fclose(file);
        return NULL;
    }

    buffer[file_size] = '\0';

    fclose(file);
    return buffer;
}
