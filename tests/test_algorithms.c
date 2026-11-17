#include "algorithms.h"
#include "parking.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>
int main(void){int a[]={5,1,4,2,3};merge_sort(a,5);for(int i=0;i<5;i++)assert(a[i]==i+1);assert(binary_search_iter(a,5,4)==3);assert(binary_search_rec(a,0,4,9)==-1);int b[]={-2,1,-3,4,-1,2,1,-5,4};assert(max_subarray(b,9)==6);assert(fast_power(3,13,97)==31);assert(n_queens_count(4)==2);int w[]={2,3,4},v[]={4,5,8};assert(knapsack01(w,v,3,5)==9);assert(lcs_length("PARKING","PARK")==4);int ss[]={3,5,7};assert(subset_sum(ss,3,10));ParkingLot l;parking_init(&l);assert(parking_add_space(&l,(ParkingSpace){1,"A",1,0,10,0,0}));assert(parking_add_driver(&l,(Driver){2,"Sam",0,50}));assert(parking_reserve(&l,2,1,10,20));assert(!parking_reserve(&l,2,1,15,25));HuffmanCode codes[256]; unsigned long long bits=0;
 const unsigned char sample[]="aaaaabbc";
 assert(huffman_build(sample,sizeof(sample)-1,codes,&bits)==3);
 assert(bits==11); assert(codes[(unsigned char)'a'].bit_length==1);
 assert(codes[(unsigned char)'b'].bit_length==2);
 assert(codes[(unsigned char)'c'].bit_length==2);
 assert(huffman_build(NULL,0,codes,&bits)==0 && bits==0);
 int starts[]={0,1,2,3,3,5},ends[]={4,2,3,5,6,7},rooms[6];
 assert(interval_partition(starts,ends,6,rooms)==3);
 for(int i=0;i<6;i++) for(int j=i+1;j<6;j++)
   if(rooms[i]==rooms[j]) assert(ends[i]<=starts[j] || ends[j]<=starts[i]);
 int adjacent_s[]={0,2,4},adjacent_e[]={2,4,6},adjacent_r[3];
 assert(interval_partition(adjacent_s,adjacent_e,3,adjacent_r)==1);
 assert(interval_partition(NULL,NULL,0,NULL)==0);
 int bad_s[]={4},bad_e[]={4},bad_r[1]; assert(interval_partition(bad_s,bad_e,1,bad_r)==-1);
 puts("all small tests passed");return 0;}
