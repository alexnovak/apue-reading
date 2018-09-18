#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]) {
  fprintf(stderr, "EACCESS: %s\n", strerror(EACCES));
  errno = ENODEV;
  perror(argv[0]);
  exit(0);
}
