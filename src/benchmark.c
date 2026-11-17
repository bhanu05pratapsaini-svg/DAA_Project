#include "benchmark.h"
#include "algorithms.h"
#include <stdio.h>
#include <time.h>
void run_benchmarks(void){int a[2000];for(int i=0;i<2000;i++)a[i]=(2000-i)%317;clock_t s=clock();merge_sort(a,2000);clock_t e=clock();printf("merge sort n=2000 CPU seconds %.6f\n",(double)(e-s)/CLOCKS_PER_SEC);}
