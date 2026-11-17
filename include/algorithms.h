#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include <stddef.h>
void merge_sort(int *a, size_t n);
void quick_sort(int *a, int lo, int hi);
int binary_search_iter(const int *a, int n, int key);
int binary_search_rec(const int *a, int lo, int hi, int key);
long long max_subarray(const int *a, int n);
long long fast_power(long long base, unsigned exp, long long mod);
int celebrity(const int *matrix, int n);
int activity_select(const int *start, const int *end, int n, int *chosen);
int knapsack01(const int *weight, const int *value, int n, int capacity);
int lcs_length(const char *a, const char *b);
int subset_sum(const int *a, int n, int target);
int n_queens_count(int n);
void matrix_multiply(const long long *a, const long long *b, long long *c, int n);
void naive_search(const char *text, const char *pattern);
void rabin_karp_search(const char *text, const char *pattern);
void kmp_search(const char *text, const char *pattern);
void automaton_search(const char *text, const char *pattern);
#endif
