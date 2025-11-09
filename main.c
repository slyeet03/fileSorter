#include "file_utils.h"
#include "sort_algorithms.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  // in case user does not put any argument
  if (argc < 2) {
    printf("No folder given\n");
    return 1;
  }

  FileInfo files[200];
  int count = 0;

  // read files
  if (getFiles(argv[1], files, &count) == -1) {
    printf("cannot open folder");
    return 1;
  }

  printf("Total files fount: %d\n", count);
  int choice;
  printf("\n Choose sorting method:\n");
  printf("1. by Name\n");
  printf("2. by Size\n");
  scanf("%d", &choice);

  switch (choice) {
  case 1:
    sortByName(files, count);
    break;
  case 2:
    sortBySize(files, count);
    break;
  default:
    printf("Invalid Choice");
    return 1;
  }

  printf("\nSorted files:\n");
  for (int i = 0; i < count; i++) {
    printf("%-30s %10ld bytes\n", files[i].name, files[i].size);
  }

  return 0;
}
