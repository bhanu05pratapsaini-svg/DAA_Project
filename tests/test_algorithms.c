#include "algorithms.h"
#include "parking.h"
#include <assert.h>
#include <stdio.h>
int main(void){int a[]={5,1,4,2,3};merge_sort(a,5);for(int i=0;i<5;i++)assert(a[i]==i+1);assert(binary_search_iter(a,5,4)==3);assert(binary_search_rec(a,0,4,9)==-1);int b[]={-2,1,-3,4,-1,2,1,-5,4};assert(max_subarray(b,9)==6);assert(fast_power(3,13,97)==31);assert(n_queens_count(4)==2);int w[]={2,3,4},v[]={4,5,8};assert(knapsack01(w,v,3,5)==9);assert(lcs_length("PARKING","PARK")==4);int ss[]={3,5,7};assert(subset_sum(ss,3,10));ParkingLot l;parking_init(&l);assert(parking_add_space(&l,(ParkingSpace){1,"A",1,0,10,0,0}));assert(parking_add_driver(&l,(Driver){2,"Sam",0,50}));assert(parking_reserve(&l,2,1,10,20));assert(!parking_reserve(&l,2,1,15,25));puts("all small tests passed");return 0;}
