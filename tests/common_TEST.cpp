#include <common.h>

#include <gtest/gtest.h>

#define PAR_DIR ROOT_DIR "/Par/"

namespace {

char str2int(char c) {
  switch (c) {
  case 'A':
  case 'a':
  case '0':
    return 0;
  case 'C':
  case 'c':
  case '1':
    return 1;
  case 'G':
  case 'g':
  case '2':
    return 2;
  case 'T':
  case 't':
  case '3':
    return 3;
  }
  return 4;
}

} // namespace

TEST(Common, GetStack) {
  double stackEntropies[625], stackEnthalpies[625];
  getStack(stackEntropies, stackEnthalpies, PAR_DIR);
}

TEST(Common, GetStackint2) {
  double stackint2Entropies[625], stackint2Enthalpies[625];
  getStackint2(stackint2Entropies, stackint2Enthalpies, PAR_DIR);
}

TEST(Common, GetDangle) {
  double dangleEntropies3[125], dangleEnthalpies3[125], dangleEntropies5[125],
      dangleEnthalpies5[125];
  getDangle(dangleEntropies3, dangleEnthalpies3, dangleEntropies5,
            dangleEnthalpies5, PAR_DIR);
}

TEST(Common, GetLoop) {
  double hairpinLoopEntropies[30], interiorLoopEntropies[30],
      bulgeLoopEntropies[30], hairpinLoopEnthalpies[30],
      interiorLoopEnthalpies[30], bulgeLoopEnthalpies[30];
  getLoop(hairpinLoopEntropies, interiorLoopEntropies, bulgeLoopEntropies,
          hairpinLoopEnthalpies, interiorLoopEnthalpies, bulgeLoopEnthalpies,
          PAR_DIR);
}

TEST(Common, GetTstack) {
  double tstackEntropies[625], tstackEnthalpies[625];
  getTstack(tstackEntropies, tstackEnthalpies, PAR_DIR);
}

TEST(Common, GetTstack2) {
  double tstack2Entropies[625], tstack2Enthalpies[625];
  getTstack2(tstack2Entropies, tstack2Enthalpies, PAR_DIR);
}

TEST(Common, GetNumLine) {
  EXPECT_EQ(16, get_num_line(PAR_DIR, 0));
  EXPECT_EQ(77, get_num_line(PAR_DIR, 1));
}

TEST(Common, GetTriloop) {
  int numTriloops = get_num_line(PAR_DIR, 0);
  char *triloopEntropies1 = (char *)malloc(numTriloops * 5);
  char *triloopEnthalpies1 = (char *)malloc(numTriloops * 5);
  double *triloopEntropies2 = (double *)malloc(numTriloops * sizeof(double));
  double *triloopEnthalpies2 = (double *)malloc(numTriloops * sizeof(double));
  getTriloop(triloopEntropies1, triloopEnthalpies1, triloopEntropies2,
             triloopEnthalpies2, PAR_DIR, str2int);
  free(triloopEnthalpies2);
  free(triloopEntropies2);
  free(triloopEnthalpies1);
  free(triloopEntropies1);
}

TEST(Common, GetTetraloop) {
  int numTetraloops = get_num_line(PAR_DIR, 1);
  char *tetraloopEntropies1 = (char *)malloc(numTetraloops * 6);
  char *tetraloopEnthalpies1 = (char *)malloc(numTetraloops * 6);
  double *tetraloopEntropies2 =
      (double *)malloc(numTetraloops * sizeof(double));
  double *tetraloopEnthalpies2 =
      (double *)malloc(numTetraloops * sizeof(double));
  getTetraloop(tetraloopEntropies1, tetraloopEnthalpies1, tetraloopEntropies2,
               tetraloopEnthalpies2, PAR_DIR, str2int);
  free(tetraloopEnthalpies2);
  free(tetraloopEntropies2);
  free(tetraloopEnthalpies1);
  free(tetraloopEntropies1);
}