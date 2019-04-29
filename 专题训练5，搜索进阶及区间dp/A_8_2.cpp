#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 10000 + 5, maxe = 50000 + 5;
int n, m, q, num, head[maxn], value[maxn], ans[maxe];
bool vis[2 * maxn];
struct edge
{
    int x, y;
} edge[2 * maxn];
struct operation
{
    char str[10];
    int x, y;
} operation[maxe];

int find(int x)
{
    if (head[x] == x)
        return x;
    return head[x] = find(head[x]);
}

void Union(int x, int y)
{
    int fx = find(x), fy = find(y);
    if (fx != fy)
    {
        if (value[fx] > value[fy])
            head[fy] = fx;
        else if (value[fy] > value[fx])
            head[fx] = fy;
        else if (fy > fx)
            head[fy] = fx;
        else
            head[fx] = fy;
    }
}

int main()
{
    scanf("%d", &n);
    while (1)
    {
        num = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &value[i]);
            head[i] = i;
        }
        scanf("%d", &m);
        for (int i = 0; i < m; i++)
        {
            scanf("%d %d", &edge[i].x, &edge[i].y);
            vis[i] = false;
        }
        scanf("%d", &q);
        for (int i = 0; i < q; i++)
        {
            scanf("%s", operation[i].str);
            if (!strcmp("query", operation[i].str))
                scanf("%d", &operation[i].x);
            else
            {
                scanf("%d %d", &operation[i].x, &operation[i].y);
                for (int j = 0; j < m; j++)
                    if ((edge[j].x == operation[i].x && edge[j].y == operation[i].y) || (edge[j].y == operation[i].x && edge[j].x == operation[i].y))
                    {
                        vis[j] = true;
                        break;
                    }
            }
        }
        for (int i = 0; i < m; i++)
            if (!vis[i])
                Union(edge[i].x, edge[i].y);
        for (int i = q - 1; i >= 0; i--)
        {
            if (!strcmp(operation[i].str, "destroy"))
                Union(operation[i].x, operation[i].y);
            else
            {
                int fx = find(operation[i].x);
                ans[++num] = (fx == operation[i].x ? -1 : fx);
            }
        }
        for (int i = num; i > 0; i--)
            printf("%d\n", ans[i]);
        if (scanf("%d", &n) != EOF)
            printf("\n");
        else
            break;
    }
    return 0;
}