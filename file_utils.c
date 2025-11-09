#include "file_utils.h"
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

int getFiles(const char *path, FileInfo files[], int *count) {
  DIR *dir;
  struct dirent *entry;
  struct stat fileStat;
  char fullPath[512];

  dir = opendir(path);
  if (dir == NULL) {
    return -1;
  }

  *count = 0;
  while ((entry = readdir(dir)) != NULL) {
    // remove current folder and parent folder
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
      continue;
    }
    // storing the full file path
    snprintf(fullPath, sizeof(fullPath), "%s/%s", path, entry->d_name);
    // getting file info and storing it in the stat struct
    stat(fullPath, &fileStat);
    // checking for regular files and counting them only
    if (S_ISREG(fileStat.st_mode)) {
      strcpy(files[*count].name, entry->d_name);
      files[*count].size = fileStat.st_size;
      (*count)++;
    }
  }

  closedir(dir);
  return 0;
}
