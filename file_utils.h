#ifndef FILE_UTILS_H
#define FILE_UTILS_H

typedef struct {
  char name[256];
  long size;
} FileInfo;

int getFiles(const char *path, FileInfo files[], int *count);

#endif
