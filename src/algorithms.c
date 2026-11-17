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


typedef struct {
    unsigned long long frequency;
    int left;
    int right;
    int min_symbol;
    int symbol;
} HuffmanNode;

static int huffman_less(const HuffmanNode nodes[], int a, int b) {
    if (nodes[a].frequency != nodes[b].frequency)
        return nodes[a].frequency < nodes[b].frequency;
    return nodes[a].min_symbol < nodes[b].min_symbol;
}

static void heap_push(int heap[], int *size, int value, const HuffmanNode nodes[]) {
    int i = (*size)++;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (!huffman_less(nodes, value, heap[parent])) break;
        heap[i] = heap[parent];
        i = parent;
    }
    heap[i] = value;
}

static int heap_pop(int heap[], int *size, const HuffmanNode nodes[]) {
    int answer = heap[0];
    int last = heap[--(*size)];
    int i = 0;
    while (2 * i + 1 < *size) {
        int child = 2 * i + 1;
        if (child + 1 < *size && huffman_less(nodes, heap[child + 1], heap[child]))
            child++;
        if (!huffman_less(nodes, heap[child], last)) break;
        heap[i] = heap[child];
        i = child;
    }
    if (*size > 0) heap[i] = last;
    return answer;
}

static void huffman_walk(const HuffmanNode nodes[], int node, char path[],
                         int depth, HuffmanCode codes[], unsigned long long *bits) {
    if (nodes[node].left < 0 && nodes[node].right < 0) {
        int length = depth == 0 ? 1 : depth;
        if (depth == 0) path[0] = '0';
        path[length] = '\0';
        HuffmanCode *out = &codes[nodes[node].symbol];
        out->symbol = (unsigned char)nodes[node].symbol;
        out->frequency = nodes[node].frequency;
        out->bit_length = length;
        memcpy(out->bits, path, (size_t)length + 1);
        *bits += nodes[node].frequency * (unsigned long long)length;
        return;
    }
    if (nodes[node].left >= 0) {
        path[depth] = '0';
        huffman_walk(nodes, nodes[node].left, path, depth + 1, codes, bits);
    }
    if (nodes[node].right >= 0) {
        path[depth] = '1';
        huffman_walk(nodes, nodes[node].right, path, depth + 1, codes, bits);
    }
}

int huffman_build(const unsigned char *data, size_t length,
                  HuffmanCode codes[256], unsigned long long *total_bits) {
    unsigned long long frequency[256] = {0};
    HuffmanNode nodes[511];
    int heap[511], heap_size = 0, node_count = 0, distinct = 0;
    if (!codes || !total_bits || (!data && length != 0)) return -1;
    memset(codes, 0, sizeof(HuffmanCode) * 256);
    *total_bits = 0;
    for (size_t i = 0; i < length; i++) frequency[data[i]]++;
    for (int i = 0; i < 256; i++) {
        if (frequency[i] == 0) continue;
        nodes[node_count] = (HuffmanNode){frequency[i], -1, -1, i, i};
        heap_push(heap, &heap_size, node_count, nodes);
        node_count++;
        distinct++;
    }
    if (distinct == 0) return 0;
    while (heap_size > 1) {
        int left = heap_pop(heap, &heap_size, nodes);
        int right = heap_pop(heap, &heap_size, nodes);
        nodes[node_count] = (HuffmanNode){
            nodes[left].frequency + nodes[right].frequency,
            left, right,
            nodes[left].min_symbol < nodes[right].min_symbol ?
                nodes[left].min_symbol : nodes[right].min_symbol,
            -1
        };
        heap_push(heap, &heap_size, node_count, nodes);
        node_count++;
    }
    char path[256];
    huffman_walk(nodes, heap_pop(heap, &heap_size, nodes), path, 0, codes, total_bits);
    return distinct;
}

typedef struct { int start, end, original; } IntervalItem;
typedef struct { int end, room; } RoomEnd;

static int compare_intervals(const void *a, const void *b) {
    const IntervalItem *x = a, *y = b;
    if (x->start != y->start) return x->start < y->start ? -1 : 1;
    if (x->end != y->end) return x->end < y->end ? -1 : 1;
    return x->original < y->original ? -1 : x->original > y->original;
}

static void room_heap_push(RoomEnd heap[], int *size, RoomEnd value) {
    int i = (*size)++;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[p].end < value.end ||
            (heap[p].end == value.end && heap[p].room <= value.room)) break;
        heap[i] = heap[p];
        i = p;
    }
    heap[i] = value;
}

static RoomEnd room_heap_pop(RoomEnd heap[], int *size) {
    RoomEnd answer = heap[0], last = heap[--(*size)];
    int i = 0;
    while (2 * i + 1 < *size) {
        int c = 2 * i + 1;
        if (c + 1 < *size &&
            (heap[c + 1].end < heap[c].end ||
             (heap[c + 1].end == heap[c].end && heap[c + 1].room < heap[c].room)))
            c++;
        if (last.end < heap[c].end ||
            (last.end == heap[c].end && last.room <= heap[c].room)) break;
        heap[i] = heap[c];
        i = c;
    }
    if (*size > 0) heap[i] = last;
    return answer;
}

int interval_partition(const int *start, const int *end, int n, int *room_for_interval) {
    if (n < 0 || (n > 0 && (!start || !end || !room_for_interval))) return -1;
    if (n == 0) return 0;
    IntervalItem *items = malloc((size_t)n * sizeof(*items));
    RoomEnd *heap = malloc((size_t)n * sizeof(*heap));
    if (!items || !heap) { free(items); free(heap); return -1; }
    for (int i = 0; i < n; i++) {
        if (end[i] <= start[i]) { free(items); free(heap); return -1; }
        items[i] = (IntervalItem){start[i], end[i], i};
    }
    qsort(items, (size_t)n, sizeof(*items), compare_intervals);
    int heap_size = 0, rooms = 0;
    for (int i = 0; i < n; i++) {
        int room;
        if (heap_size > 0 && heap[0].end <= items[i].start) {
            RoomEnd previous = room_heap_pop(heap, &heap_size);
            room = previous.room;
        } else {
            room = ++rooms;
        }
        room_for_interval[items[i].original] = room;
        room_heap_push(heap, &heap_size, (RoomEnd){items[i].end, room});
    }
    free(items);
    free(heap);
    return rooms;
}
