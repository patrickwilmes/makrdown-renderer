/*
* Copyright (c) 2024, Patrick Wilmes <p.wilmes89@gmail.com>
* All rights reserved.
*
* SPDX-License-Identifier: BSD-2-Clause
*/
#include <stdio.h>
#include <stdlib.h>

#include "file.h"

int main(const int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    char *content = file_read(filename);
    printf("Content: %s\n", content);
    free(content);

    return 0;
}
