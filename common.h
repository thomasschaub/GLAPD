#pragma once

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef char (*str2int_fn)(char c);

void getStack(double stackEntropies[], double stackEnthalpies[], char *path);

void getStackint2(double stackint2Entropies[], double stackint2Enthalpies[],
                  char *path);

void getDangle(double dangleEntropies3[], double dangleEnthalpies3[],
               double dangleEntropies5[], double dangleEnthalpies5[],
               char *path);

void getLoop(double hairpinLoopEntropies[30], double interiorLoopEntropies[30],
             double bulgeLoopEntropies[30], double hairpinLoopEnthalpies[30],
             double interiorLoopEnthalpies[30], double bulgeLoopEnthalpies[30],
             char *path);

void getTstack(double tstackEntropies[], double tstackEnthalpies[], char *path);

void getTstack2(double tstack2Entropies[], double tstack2Enthalpies[],
                char *path);

int get_num_line(char *path, int flag);

void getTriloop(char *triloopEntropies1, char *triloopEnthalpies1,
                double *triloopEntropies2, double *triloopEnthalpies2,
                char *path, str2int_fn str2int);

void getTetraloop(char *tetraloopEntropies1, char *tetraloopEnthalpies1,
                  double *tetraloopEntropies2, double *tetraloopEnthalpies2,
                  char *path, str2int_fn str2int);

#ifdef __cplusplus
}
#endif