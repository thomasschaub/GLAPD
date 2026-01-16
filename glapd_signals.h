#pragma once

extern void notify_about_to_check_candidate_primer_region(int current, int total);

/**
 * num_targets: the number of targets we are trying to amplify
 */
extern void notify_about_to_check_primer_set_candidate(int num_targets, int current, int total);

extern void notify_found_primer_set_candidate(const char* f3, const char* f2, const char* f1c, const char* b1c, const char* b2, const char* b3, const char* lf, const char* lb);