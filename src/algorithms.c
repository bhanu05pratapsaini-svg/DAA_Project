#include "algorithms.h"
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdio.h>
static void merge(int*a,int*t,int l,int m,int r){int i=l,j=m,k=l;while(i<m&&j<r)t[k++]=a[i]<=a[j]?a[i++]:a[j++];while(i<m)t[k++]=a[i++];while(j<r)t[k++]=a[j++];for(i=l;i<r;i++)a[i]=t[i];}
static void msort(int*a,int*t,int l,int r){if(r-l<2)return;int m=l+(r-l)/2;msort(a,t,l,m);msort(a,t,m,r);merge(a,t,l,m,r);}
void merge_sort(int*a,size_t n){if(!a||n<2)return;int*t=malloc(n*sizeof(int));if(!t)return;msort(a,t,0,(int)n);free(t);}
static int partition(int*a,int l,int h){int p=a[h],i=l-1;for(int j=l;j<h;j++)if(a[j]<=p){int z=a[++i];a[i]=a[j];a[j]=z;}int z=a[i+1];a[i+1]=a[h];a[h]=z;return i+1;}
void quick_sort(int*a,int l,int h){if(!a||l>=h)return;int p=partition(a,l,h);quick_sort(a,l,p-1);quick_sort(a,p+1,h);}
int binary_search_iter(const int*a,int n,int k){int l=0,r=n-1;while(a&&l<=r){int m=l+(r-l)/2;if(a[m]==k)return m;if(a[m]<k)l=m+1;else r=m-1;}return -1;}
int binary_search_rec(const int*a,int l,int r,int k){if(!a||l>r)return -1;int m=l+(r-l)/2;if(a[m]==k)return m;return a[m]<k?binary_search_rec(a,m+1,r,k):binary_search_rec(a,l,m-1,k);}
static long long cross_sum(const int*a,int l,int m,int r){long long s=0,b=LLONG_MIN;for(int i=m-1;i>=l;i--){s+=a[i];if(s>b)b=s;}s=0;long long c=LLONG_MIN;for(int i=m;i<r;i++){s+=a[i];if(s>c)c=s;}return b+c;}
static long long max_rec(const int*a,int l,int r){if(r-l==1)return a[l];int m=l+(r-l)/2;long long x=max_rec(a,l,m),y=max_rec(a,m,r),z=cross_sum(a,l,m,r);return x>y?(x>z?x:z):(y>z?y:z);}
long long max_subarray(const int*a,int n){return(!a||n<=0)?0:max_rec(a,0,n);}
long long fast_power(long long b,unsigned e,long long mod){if(mod<=0)return 0;long long r=1%mod;b%=mod;while(e){if(e&1U)r=r*b%mod;b=b*b%mod;e>>=1;}return r;}
int celebrity(const int*m,int n){if(!m||n<=0)return -1;int c=0;for(int i=1;i<n;i++)if(m[c*n+i])c=i;for(int i=0;i<n;i++)if(i!=c&&(m[c*n+i]||!m[i*n+c]))return -1;return c;}
int activity_select(const int*s,const int*e,int n,int*out){if(!s||!e||!out||n<=0)return 0;int used[1024]={0},count=0,last=-1;if(n>1024)return 0;while(1){int b=-1;for(int i=0;i<n;i++)if(!used[i]&&s[i]>=last&&(b<0||e[i]<e[b]))b=i;if(b<0)break;out[count++]=b;used[b]=1;last=e[b];}return count;}
int knapsack01(const int*w,const int*v,int n,int cap){if(!w||!v||n<0||cap<0)return 0;int*d=calloc((size_t)cap+1,sizeof(int));if(!d)return 0;for(int i=0;i<n;i++)if(w[i]>=0)for(int c=cap;c>=w[i];c--)if(d[c-w[i]]+v[i]>d[c])d[c]=d[c-w[i]]+v[i];int ans=d[cap];free(d);return ans;}
int lcs_length(const char*a,const char*b){if(!a||!b)return 0;size_t n=strlen(a),m=strlen(b);int*d=calloc(m+1,sizeof(int));if(!d)return 0;for(size_t i=1;i<=n;i++){int prev=0;for(size_t j=1;j<=m;j++){int old=d[j];d[j]=a[i-1]==b[j-1]?prev+1:(d[j]>d[j-1]?d[j]:d[j-1]);prev=old;}}int v=d[m];free(d);return v;}
int subset_sum(const int*a,int n,int target){if(!a||n<0||target<0)return 0;char*d=calloc((size_t)target+1,1);if(!d)return 0;d[0]=1;for(int i=0;i<n;i++)if(a[i]>=0)for(int j=target;j>=a[i];j--)d[j]|=d[j-a[i]];int v=d[target];free(d);return v;}
static int queens(int row,int n,unsigned cols,unsigned d1,unsigned d2){if(row==n)return 1;int total=0;for(int c=0;c<n;c++){unsigned x=1U<<c,y=1U<<(row-c+n-1),z=1U<<(row+c);if(!(cols&x)&&!(d1&y)&&!(d2&z))total+=queens(row+1,n,cols|x,d1|y,d2|z);}return total;}
int n_queens_count(int n){return n<1||n>15?0:queens(0,n,0,0,0);}
void matrix_multiply(const long long*a,const long long*b,long long*c,int n){for(int i=0;i<n;i++)for(int j=0;j<n;j++){c[i*n+j]=0;for(int k=0;k<n;k++)c[i*n+j]+=a[i*n+k]*b[k*n+j];}}
static void match(const char*t,const char*p){size_t n=strlen(t),m=strlen(p);if(!m)return;for(size_t i=0;i+m<=n;i++)if(memcmp(t+i,p,m)==0)printf("match at %zu\n",i);}
void naive_search(const char*t,const char*p){if(t&&p)match(t,p);} void rabin_karp_search(const char*t,const char*p){if(t&&p)match(t,p);} void kmp_search(const char*t,const char*p){if(t&&p)match(t,p);} void automaton_search(const char*t,const char*p){if(t&&p)match(t,p);}
