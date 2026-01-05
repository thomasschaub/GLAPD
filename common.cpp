#include "common.h"

#include <cctype>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <unistd.h>

extern "C" {

static void readLoop(FILE *file, double *v1, double *v2, double *v3) {
  char *line, *p, *q;

  line = (char *)malloc(200);
  memset(line, '\0', 200);
  fgets(line, 200, file);

  p = line;
  while (isspace(*p))
    p++;
  while (isdigit(*p))
    p++;
  while (isspace(*p))
    p++;

  q = p;
  while (!isspace(*q))
    q++;
  *q = '\0';
  q++;
  if (!strcmp(p, "inf"))
    *v1 = 1.0 * INFINITY;
  else
    sscanf(p, "%lf", v1);
  while (isspace(*q))
    q++;

  p = q;
  while (!isspace(*p))
    p++;
  *p = '\0';
  p++;
  if (!strcmp(q, "inf"))
    *v2 = 1.0 * INFINITY;
  else
    sscanf(q, "%lf", v2);
  while (isspace(*p))
    p++;

  q = p;
  while (!isspace(*q) && (*q != '\0'))
    q++;
  *q = '\0';
  if (!strcmp(p, "inf"))
    *v3 = 1.0 * INFINITY;
  else
    sscanf(p, "%lf", v3);
}

void getStack(double stackEntropies[], double stackEnthalpies[],
              const char *path) {
  int i, j, ii, jj;
  FILE *sFile, *hFile;
  char *line;

  i = strlen(path) + 20;
  line = (char *)malloc(i);
  memset(line, '\0', i);
  strcpy(line, path);
  strcat(line, "stack.ds");
  if (access(line, 0) == -1) {
    printf("Error! Don't have %s file!\n", line);
    exit(1);
  }
  sFile = fopen(line, "r");
  if (sFile == NULL) {
    printf("Error! Can't open the %s file!\n", line);
    exit(1);
  }

  memset(line, '\0', i);
  strcpy(line, path);
  strcat(line, "stack.dh");
  if (access(line, 0) == -1) {
    printf("Error! Don't have %s file!\n", line);
    exit(1);
  }
  hFile = fopen(line, "r");
  if (hFile == NULL) {
    printf("Error! Can't open the %s file!\n", line);
    exit(1);
  }
  free(line);

  line = (char *)malloc(20);
  memset(line, '\0', 20);
  for (i = 0; i < 5; ++i) {
    for (ii = 0; ii < 5; ++ii) {
      for (j = 0; j < 5; ++j) {
        for (jj = 0; jj < 5; ++jj) {
          if (i == 4 || j == 4 || ii == 4 || jj == 4) // N
          {
            stackEntropies[i * 125 + ii * 25 + j * 5 + jj] = -1.0;
            stackEnthalpies[i * 125 + ii * 25 + j * 5 + jj] = 1.0 * INFINITY;
          } else {
            if (fgets(line, 20, sFile) == NULL) {
              printf("Error! When read parameters in getStack function!\n");
              exit(1);
            }
            if (strncmp(line, "inf", 3) == 0)
              stackEntropies[i * 125 + ii * 25 + j * 5 + jj] = 1.0 * INFINITY;
            else
              stackEntropies[i * 125 + ii * 25 + j * 5 + jj] = atof(line);

            if (fgets(line, 20, hFile) == NULL) {
              printf("Error! When read parameters in getStack function!\n");
              exit(1);
            }
            if (strncmp(line, "inf", 3) == 0)
              stackEnthalpies[i * 125 + ii * 25 + j * 5 + jj] = 1.0 * INFINITY;
            else
              stackEnthalpies[i * 125 + ii * 25 + j * 5 + jj] = atof(line);

            if (fabs(stackEntropies[i * 125 + ii * 25 + j * 5 + jj]) >
                    999999999 ||
                fabs(stackEnthalpies[i * 125 + ii * 25 + j * 5 + jj]) >
                    999999999) {
              stackEntropies[i * 125 + ii * 25 + j * 5 + jj] = -1.0;
              stackEnthalpies[i * 125 + ii * 25 + j * 5 + jj] = 1.0 * INFINITY;
            }
          }
        }
      }
    }
  }
  fclose(sFile);
  fclose(hFile);
  free(line);
}

void getStackint2(double stackint2Entropies[], double stackint2Enthalpies[],
                  const char *path) {
  int i, j, ii, jj;
  FILE *sFile, *hFile;
  char *line;

  i = strlen(path) + 20;
  line = (char *)malloc(i);
  memset(line, '\0', i);
  strcpy(line, path);
  strcat(line, "stackmm.ds");
  if (access(line, 0) == -1) {
    printf("Error! Don't have %s file!\n", line);
    exit(1);
  }
  sFile = fopen(line, "r");
  if (sFile == NULL) {
    printf("Error! Can't open the %s file!\n", line);
    exit(1);
  }

  memset(line, '\0', i);
  strcpy(line, path);
  strcat(line, "stackmm.dh");
  if (access(line, 0) == -1) {
    printf("Error! Don't have %s file!\n", line);
    exit(1);
  }
  hFile = fopen(line, "r");
  if (hFile == NULL) {
    printf("Error! Can't open the %s file!\n", line);
    exit(1);
  }
  free(line);

  line = (char *)malloc(20);
  memset(line, '\0', 20);
  for (i = 0; i < 5; ++i) {
    for (ii = 0; ii < 5; ++ii) {
      for (j = 0; j < 5; ++j) {
        for (jj = 0; jj < 5; ++jj) {
          if (i == 4 || j == 4 || ii == 4 || jj == 4) {
            stackint2Entropies[i * 125 + ii * 25 + j * 5 + jj] = -1.0;
            stackint2Enthalpies[i * 125 + ii * 25 + j * 5 + jj] =
                1.0 * INFINITY;
          } else {
            if (fgets(line, 20, sFile) == NULL) {
              printf("Error! When read parameters in getStackint2 function!\n");
              exit(1);
            }
            if (strncmp(line, "inf", 3) == 0)
              stackint2Entropies[i * 125 + ii * 25 + j * 5 + jj] =
                  1.0 * INFINITY;
            else
              stackint2Entropies[i * 125 + ii * 25 + j * 5 + jj] = atof(line);

            if (fgets(line, 20, hFile) == NULL) {
              printf("Error! When read parameters in getStackint2 function!\n");
              exit(1);
            }
            if (strncmp(line, "inf", 3) == 0)
              stackint2Enthalpies[i * 125 + ii * 25 + j * 5 + jj] =
                  1.0 * INFINITY;
            else
              stackint2Enthalpies[i * 125 + ii * 25 + j * 5 + jj] = atof(line);

            if (fabs(stackint2Entropies[i * 125 + ii * 25 + j * 5 + jj]) >
                    999999999 ||
                fabs(stackint2Enthalpies[i * 125 + ii * 25 + j * 5 + jj]) >
                    999999999) {
              stackint2Entropies[i * 125 + ii * 25 + j * 5 + jj] = -1.0;
              stackint2Enthalpies[i * 125 + ii * 25 + j * 5 + jj] =
                  1.0 * INFINITY;
            }
          }
        }
      }
    }
  }
  fclose(sFile);
  fclose(hFile);
  free(line);
}

void getDangle(double dangleEntropies3[], double dangleEnthalpies3[],
               double dangleEntropies5[], double dangleEnthalpies5[],
               const char *path) {
  int i, j, k;
  FILE *sFile, *hFile;
  char *line;

  i = strlen(path) + 20;
  line = (char *)malloc(i);
  memset(line, '\0', i);
  strcpy(line, path);
  strcat(line, "dangle.ds");
  if (access(line, 0) == -1) {
    printf("Error! Don't have %s file!\n", line);
    exit(1);
  }
  sFile = fopen(line, "r");
  if (sFile == NULL) {
    printf("Error! Can't open the %s file!\n", line);
    exit(1);
  }

  memset(line, '\0', i);
  strcpy(line, path);
  strcat(line, "dangle.dh");
  if (access(line, 0) == -1) {
    printf("Error! Don't have %s file!\n", line);
    exit(1);
  }
  hFile = fopen(line, "r");
  if (hFile == NULL) {
    printf("Error! Can't open the %s file!\n", line);
    exit(1);
  }
  free(line);

  line = (char *)malloc(20);
  memset(line, '\0', 20);
  for (i = 0; i < 5; ++i)
    for (j = 0; j < 5; ++j)
      for (k = 0; k < 5; ++k) {
        if (i == 4 || j == 4) {
          dangleEntropies3[i * 25 + k * 5 + j] = -1.0;
          dangleEnthalpies3[i * 25 + k * 5 + j] = 1.0 * INFINITY;
        } else if (k == 4) {
          dangleEntropies3[i * 25 + k * 5 + j] = -1.0;
          dangleEnthalpies3[i * 25 + k * 5 + j] = 1.0 * INFINITY;
        } else {
          if (fgets(line, 20, sFile) == NULL) {
            printf("Error! When read parameters in getDangle function!\n");
            exit(1);
          }
          if (strncmp(line, "inf", 3) == 0)
            dangleEntropies3[i * 25 + k * 5 + j] = 1.0 * INFINITY;
          else
            dangleEntropies3[i * 25 + k * 5 + j] = atof(line);

          if (fgets(line, 20, hFile) == NULL) {
            printf("Error! When read parameters in getDangle function!\n");
            exit(1);
          }
          if (strncmp(line, "inf", 3) == 0)
            dangleEnthalpies3[i * 25 + k * 5 + j] = 1.0 * INFINITY;
          else
            dangleEnthalpies3[i * 25 + k * 5 + j] = atof(line);

          if (fabs(dangleEntropies3[i * 25 + k * 5 + j]) > 999999999 ||
              fabs(dangleEnthalpies3[i * 25 + k * 5 + j]) > 999999999) {
            dangleEntropies3[i * 25 + k * 5 + j] = -1.0;
            dangleEnthalpies3[i * 25 + k * 5 + j] = 1.0 * INFINITY;
          }
        }
      }

  for (i = 0; i < 5; ++i)
    for (j = 0; j < 5; ++j)
      for (k = 0; k < 5; ++k) {
        if (i == 4 || j == 4) {
          dangleEntropies5[i * 25 + j * 5 + k] = -1.0;
          dangleEnthalpies5[i * 25 + j * 5 + k] = 1.0 * INFINITY;
        } else if (k == 4) {
          dangleEntropies5[i * 25 + j * 5 + k] = -1.0;
          dangleEnthalpies5[i * 25 + j * 5 + k] = 1.0 * INFINITY;
        } else {
          if (fgets(line, 20, sFile) == NULL) {
            printf("Error! When read parameters in getDangle function!\n");
            exit(1);
          }
          if (strncmp(line, "inf", 3) == 0)
            dangleEntropies5[i * 25 + j * 5 + k] = 1.0 * INFINITY;
          else
            dangleEntropies5[i * 25 + j * 5 + k] = atof(line);

          if (fgets(line, 20, hFile) == NULL) {
            printf("Error! When read parameters in getDangle function!\n");
            exit(1);
          }
          if (strncmp(line, "inf", 3) == 0)
            dangleEnthalpies5[i * 25 + j * 5 + k] = 1.0 * INFINITY;
          else
            dangleEnthalpies5[i * 25 + j * 5 + k] = atof(line);

          if (fabs(dangleEntropies5[i * 25 + j * 5 + k]) > 999999999 ||
              fabs(dangleEnthalpies5[i * 25 + j * 5 + k]) > 999999999) {
            dangleEntropies5[i * 25 + j * 5 + k] = -1.0;
            dangleEnthalpies5[i * 25 + j * 5 + k] = 1.0 * INFINITY;
          }
        }
      }
  fclose(sFile);
  fclose(hFile);
  free(line);
}

void getLoop(double hairpinLoopEntropies[30], double interiorLoopEntropies[30],
             double bulgeLoopEntropies[30], double hairpinLoopEnthalpies[30],
             double interiorLoopEnthalpies[30], double bulgeLoopEnthalpies[30],
             const char *path) {
  int k;
  FILE *sFile, *hFile;
  char *line;

  k = strlen(path) + 20;
  line = (char *)malloc(k);
  memset(line, '\0', k);
  strcpy(line, path);
  strcat(line, "loops.ds");
  if (access(line, 0) == -1) {
    printf("Error! Don't have %s file!\n", line);
    exit(1);
  }
  sFile = fopen(line, "r");
  if (sFile == NULL) {
    printf("Error! Can't open the %s file!\n", line);
    exit(1);
  }

  memset(line, '\0', k);
  strcpy(line, path);
  strcat(line, "loops.dh");
  if (access(line, 0) == -1) {
    printf("Error! Don't have %s file!\n", line);
    exit(1);
  }
  hFile = fopen(line, "r");
  if (hFile == NULL) {
    printf("Error! Can't open the %s file!\n", line);
    exit(1);
  }
  free(line);

  for (k = 0; k < 30; ++k) {
    readLoop(sFile, &interiorLoopEntropies[k], &bulgeLoopEntropies[k],
             &hairpinLoopEntropies[k]);
    readLoop(hFile, &interiorLoopEnthalpies[k], &bulgeLoopEnthalpies[k],
             &hairpinLoopEnthalpies[k]);
  }
  fclose(sFile);
  fclose(hFile);
}

void getTstack(double tstackEntropies[], double tstackEnthalpies[],
               const char *path) {
  int i1, j1, i2, j2;
  FILE *sFile, *hFile;
  char *line;

  i1 = strlen(path) + 20;
  line = (char *)malloc(i1);
  memset(line, '\0', i1);
  strcpy(line, path);
  strcat(line, "tstack_tm_inf.ds");
  if (access(line, 0) == -1) {
    printf("Error! Don't have %s file!\n", line);
    exit(1);
  }
  sFile = fopen(line, "r");
  if (sFile == NULL) {
    printf("Error! Can't open the %s file!\n", line);
    exit(1);
  }

  memset(line, '\0', i1);
  strcpy(line, path);
  strcat(line, "tstack.dh");
  if (access(line, 0) == -1) {
    printf("Error! Don't have %s file!\n", line);
    exit(1);
  }
  hFile = fopen(line, "r");
  if (sFile == NULL) {
    printf("Error! Can't open the %s file!\n", line);
    exit(1);
  }
  free(line);

  line = (char *)malloc(20);
  memset(line, '\0', 20);
  for (i1 = 0; i1 < 5; ++i1)
    for (i2 = 0; i2 < 5; ++i2)
      for (j1 = 0; j1 < 5; ++j1)
        for (j2 = 0; j2 < 5; ++j2)
          if (i1 == 4 || j1 == 4) {
            tstackEnthalpies[i1 * 125 + i2 * 25 + j1 * 5 + j2] = 1.0 * INFINITY;
            tstackEntropies[i1 * 125 + i2 * 25 + j1 * 5 + j2] = -1.0;
          } else if (i2 == 4 || j2 == 4) {
            tstackEntropies[i1 * 125 + i2 * 25 + j1 * 5 + j2] = 0.00000000001;
            tstackEnthalpies[i1 * 125 + i2 * 25 + j1 * 5 + j2] = 0.0;
          } else {
            if (fgets(line, 20, sFile) == NULL) {
              printf("Error! When read parameters in getTstack function!\n");
              exit(1);
            }
            if (strncmp(line, "inf", 3) == 0)
              tstackEntropies[i1 * 125 + i2 * 25 + j1 * 5 + j2] =
                  1.0 * INFINITY;
            else
              tstackEntropies[i1 * 125 + i2 * 25 + j1 * 5 + j2] = atof(line);

            if (fgets(line, 20, hFile) == NULL) {
              printf("Error! When read parameters in getTstack function!\n");
              exit(1);
            }
            if (strncmp(line, "inf", 3) == 0)
              tstackEnthalpies[i1 * 125 + i2 * 25 + j1 * 5 + j2] =
                  1.0 * INFINITY;
            else
              tstackEnthalpies[i1 * 125 + i2 * 25 + j1 * 5 + j2] = atof(line);

            if (fabs(tstackEntropies[i1 * 125 + i2 * 25 + j1 * 5 + j2]) >
                    999999999 ||
                fabs(tstackEnthalpies[i1 * 125 + i2 * 25 + j1 * 5 + j2]) >
                    999999999) {
              tstackEntropies[i1 * 125 + i2 * 25 + j1 * 5 + j2] = -1.0;
              tstackEnthalpies[i1 * 125 + i2 * 25 + j1 * 5 + j2] =
                  1.0 * INFINITY;
            }
          }
  fclose(sFile);
  fclose(hFile);
  free(line);
}

void getTstack2(double tstack2Entropies[], double tstack2Enthalpies[],
                const char *path) {
  int i1, j1, i2, j2;
  FILE *sFile, *hFile;
  char *line;

  i1 = strlen(path) + 20;
  line = (char *)malloc(i1);
  memset(line, '\0', i1);
  strcpy(line, path);
  strcat(line, "tstack2.ds");
  if (access(line, 0) == -1) {
    printf("Error! Don't have %s file!\n", line);
    exit(1);
  }
  sFile = fopen(line, "r");
  if (sFile == NULL) {
    printf("Error! Can't open the %s file!\n", line);
    exit(1);
  }

  memset(line, '\0', i1);
  strcpy(line, path);
  strcat(line, "tstack2.dh");
  if (access(line, 0) == -1) {
    printf("Error! Don't have %s file!\n", line);
    exit(1);
  }
  hFile = fopen(line, "r");
  if (sFile == NULL) {
    printf("Error! Can't open the %s file!\n", line);
    exit(1);
  }
  free(line);

  line = (char *)malloc(20);
  memset(line, '\0', 20);
  for (i1 = 0; i1 < 5; ++i1)
    for (i2 = 0; i2 < 5; ++i2)
      for (j1 = 0; j1 < 5; ++j1)
        for (j2 = 0; j2 < 5; ++j2)
          if (i1 == 4 || j1 == 4) {
            tstack2Enthalpies[i1 * 125 + i2 * 25 + j1 * 5 + j2] =
                1.0 * INFINITY;
            tstack2Entropies[i1 * 125 + i2 * 25 + j1 * 5 + j2] = -1.0;
          } else if (i2 == 4 || j2 == 4) {
            tstack2Entropies[i1 * 125 + i2 * 25 + j1 * 5 + j2] = 0.00000000001;
            tstack2Enthalpies[i1 * 125 + i2 * 25 + j1 * 5 + j2] = 0.0;
          } else {
            if (fgets(line, 20, sFile) == NULL) {
              printf("Error! When read parameters in getTstack2 function!\n");
              exit(1);
            }
            if (strncmp(line, "inf", 3) == 0)
              tstack2Entropies[i1 * 125 + i2 * 25 + j1 * 5 + j2] =
                  1.0 * INFINITY;
            else
              tstack2Entropies[i1 * 125 + i2 * 25 + j1 * 5 + j2] = atof(line);

            if (fgets(line, 20, hFile) == NULL) {
              printf("Error! When read parameters in getTstack2 function!\n");
              exit(1);
            }
            if (strncmp(line, "inf", 3) == 0)
              tstack2Enthalpies[i1 * 125 + i2 * 25 + j1 * 5 + j2] =
                  1.0 * INFINITY;
            else
              tstack2Enthalpies[i1 * 125 + i2 * 25 + j1 * 5 + j2] = atof(line);

            if (fabs(tstack2Entropies[i1 * 125 + i2 * 25 + j1 * 5 + j2]) >
                    999999999 ||
                fabs(tstack2Enthalpies[i1 * 125 + i2 * 25 + j1 * 5 + j2]) >
                    999999999) {
              tstack2Entropies[i1 * 125 + i2 * 25 + j1 * 5 + j2] = -1.0;
              tstack2Enthalpies[i1 * 125 + i2 * 25 + j1 * 5 + j2] =
                  1.0 * INFINITY;
            }
          }
  fclose(sFile);
  fclose(hFile);
  free(line);
}

int get_num_line(const char *path, int flag) {
  FILE *fp;
  int i, size;
  char *line;

  i = strlen(path) + 20;
  line = (char *)malloc(i);
  memset(line, '\0', i);
  strcpy(line, path);
  if (flag == 0)
    strcat(line, "triloop.ds");
  else
    strcat(line, "tetraloop.ds");

  if (access(line, 0) == -1) {
    printf("Error! Don't have %s file!\n", line);
    exit(1);
  }
  fp = fopen(line, "r");
  if (fp == NULL) {
    printf("Error! Can't open the %s file!\n", line);
    exit(1);
  }

  size = 0;
  while (fgets(line, i, fp) != NULL)
    size++;
  return size;
}

void getTriloop(char *triloopEntropies1, char *triloopEnthalpies1,
                double *triloopEntropies2, double *triloopEnthalpies2,
                const char *path, str2int_fn str2int) {
  FILE *sFile, *hFile;
  int i, turn;
  char *line, seq[10], value[10];

  i = strlen(path) + 20;
  line = (char *)malloc(i);
  memset(line, '\0', i);
  strcpy(line, path);
  strcat(line, "triloop.ds");
  if (access(line, 0) == -1) {
    printf("Error! Don't have %s file!\n", line);
    exit(1);
  }
  sFile = fopen(line, "r");
  if (sFile == NULL) {
    printf("Error! Can't open the %s file!\n", line);
    exit(1);
  }

  turn = 0;
  while (fscanf(sFile, "%s\t%s\n", seq, value) != EOF) {
    for (i = 0; i < 5; i++)
      triloopEntropies1[5 * turn + i] = str2int(seq[i]);
    if (value[0] == 'i')
      triloopEntropies2[turn] = 1.0 * INFINITY;
    else
      triloopEntropies2[turn] = atof(value);
    turn++;
  }
  fclose(sFile);

  i = strlen(path) + 20;
  memset(line, '\0', i);
  strcpy(line, path);
  strcat(line, "triloop.dh");
  if (access(line, 0) == -1) {
    printf("Error! Don't have %s file!\n", line);
    exit(1);
  }
  hFile = fopen(line, "r");
  if (hFile == NULL) {
    printf("Error! Can't open the %s file!\n", line);
    exit(1);
  }
  free(line);

  turn = 0;
  while (fscanf(hFile, "%s\t%s\n", seq, value) != EOF) {
    for (i = 0; i < 5; i++)
      triloopEnthalpies1[turn * 5 + i] = str2int(seq[i]);
    if (value[0] == 'i')
      triloopEnthalpies2[turn] = 1.0 * INFINITY;
    else
      triloopEnthalpies2[turn] = atof(value);
    turn++;
  }
  fclose(hFile);
}

void getTetraloop(char *tetraloopEntropies1, char *tetraloopEnthalpies1,
                  double *tetraloopEntropies2, double *tetraloopEnthalpies2,
                  const char *path, str2int_fn str2int) {
  FILE *sFile, *hFile;
  int i, turn;
  char *line, seq[10], value[10];

  i = strlen(path) + 20;
  line = (char *)malloc(i);
  memset(line, '\0', i);
  strcpy(line, path);
  strcat(line, "tetraloop.ds");
  if (access(line, 0) == -1) {
    printf("Error! Don't have %s file!\n", line);
    exit(1);
  }
  sFile = fopen(line, "r");
  if (sFile == NULL) {
    printf("Error! Can't open the %s file!\n", line);
    exit(1);
  }

  turn = 0;
  while (fscanf(sFile, "%s\t%s\n", seq, value) != EOF) {
    for (i = 0; i < 6; i++)
      tetraloopEntropies1[turn * 6 + i] = str2int(seq[i]);
    if (value[0] == 'i')
      tetraloopEntropies2[turn] = 1.0 * INFINITY;
    else
      tetraloopEntropies2[turn] = atof(value);
    turn++;
  }
  fclose(sFile);

  memset(line, '\0', i);
  strcpy(line, path);
  strcat(line, "tetraloop.dh");
  if (access(line, 0) == -1) {
    printf("Error! Don't have %s file!\n", line);
    exit(1);
  }
  hFile = fopen(line, "r");
  if (hFile == NULL) {
    printf("Error! Can't open the %s file!\n", line);
    exit(1);
  }
  free(line);

  turn = 0;
  while (fscanf(hFile, "%s\t%s\n", seq, value) != EOF) {
    for (i = 0; i < 6; i++)
      tetraloopEnthalpies1[6 * turn + i] = str2int(seq[i]);
    if (value[0] == 'i')
      tetraloopEnthalpies2[turn] = 1.0 * INFINITY;
    else
      tetraloopEnthalpies2[turn] = atof(value);
    turn++;
  }
  fclose(hFile);
}
}