#include <iostream>  
#include <cstdio>  
using namespace std;  
#define N 100005  
__int64 sum[N << 2];  
__int64 mark[N << 2];  
__int64 basic_num[N<<2]; 
__int64 k[N<<2];


struct {
    int left;
    int right;
    int A_sum;
    int B_sum;
    int k;
}

inline void pushUp (int o)  
{  
    sum[o] = sum[o << 1] + sum[o << 1 | 1];  
}  
  
void pushDown (int o, int len)  
{  
    if (mark[o]) {  
        //因为o的儿子节点可能被多次延迟标记，并且o的儿子节点的延迟标记没有向o的孙子节点移动，所以用“+=”  
        mark[o << 1] += mark[o];  
        mark[o << 1 | 1] += mark[o];  
        /*此处用mark[o]乘以区间长度，不是mark[o<<1], 因为o的儿子节点如果被多次标记，之前被标记时， 
          就已经对sum[o<<1]更新过了。 
        */  
        sum[o << 1] += mark[o] * (len - (len >> 1));   
        sum[o << 1 | 1] += mark[o] * (len >> 1);  
        mark[o] = 0; //将标记向儿子节点移动后，父节点的延迟标记去掉  
    }  
}  
  
void build (int l, int r, int o)  
{  
    mark[o] = 0;  
    if (l == r)  
    {  
        sum[o]=basic_num[l];  
        return;  
    }  
    int m = (l + r) >> 1;  
    build (l, m, o << 1);  
    build (m + 1, r, o << 1 | 1);  
    pushUp (o);//sum值初始化   
}  
  
void update (int L, int R, __int64 c, int l, int r, int o)//L，R是要更新的区间   
{  
    if (l >= L && r <= R)  
    {  
        mark[o] += c;  
        sum[o] += c * (r - l + 1);  
        return;  
    }  
    /*当要对被延迟标记过的这段区间的儿子节点进行更新时，先要将延迟标记向儿子节点移动 
    当然，如果一直没有对该段的儿子节点更新，延迟标记就不需要向儿子节点移动，这样就使 
    更新操作的时间复杂度仍为O（logn），也是使用延迟标记的原因。 
    */  
    pushDown(o, r - l + 1); //将已有的延迟下放      
    int m = (l + r) >> 1;  
    if (m >= L) update (L, R, c, l, m, o << 1);  
    if (m < R) update (L, R, c, m + 1, r, o << 1 | 1);  
    pushUp (o);  
}  
  
__int64 query (int L, int R, int l, int r, int o)  
{  
    if (l >= L && r <= R)   
    return sum[o];  
    //要取o子节点的值时，也要先把o的延迟标记向下移动  
    pushDown(o, r - l + 1);  
    int m = (l + r) >> 1;  
    __int64 ret = 0;  
    if (m >= L) ret += query (L, R, l, m, o << 1);  
    if (m < R) ret += query (L, R, m + 1, r, o << 1 | 1);  
    return ret;  
}  
  
int main()  
{  
    int n, q, a, b;  
    __int64 c;  
    char op;  
    scanf ("%d%d", &n,&q);  
    for(int i=1;i<=n;i++)  
    scanf("%lld",&basic_num[i]);  
    build (1, n, 1);  
    while (q--)  
    {  
        getchar();  
        scanf ("%c %d %d", &op, &a, &b);  
        if (op == '3') printf ("%lld\n", query (a, b, 1, n, 1));  
        else  
        {  
            scanf ("%lld", &c);  
            update (a, b, c, 1, n, 1);  
        }  
    }  
    return 0;  
}  