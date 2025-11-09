#include "sort_algorithms.h"
#include <string.h>

void sortByName(FileInfo files[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (strcmp(files[j].name, files[j + 1].name) > 0) {
        FileInfo temp = files[j];
        files[j] = files[j + 1];
        files[j + 1] = temp;
      }
    }
  }
}
void sortBySize(FileInfo files[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (files[j].size > files[j + 1].size) {
        FileInfo temp = files[j];
        files[j] = files[j + 1];
        files[j + 1] = temp;
      }
    }
  }
}
