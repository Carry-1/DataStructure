# include<cstdio>
const int maxn = 30;
int n, V, maxValue = 0;
int w[maxn], c[maxn];

void DFS(int index, int sumW, int sumC)
{
    if(index==n)
    {
        if(sumW<=V&&sumC>=maxValue)
            maxValue=sumC;
        return;
    }
    DFS(index+1, sumW, sumC);
    DFS(index+1, sumW+w[index], sumC+c[index]);
}

int main()
{
    scanf("%d %d", &n, &V);
    for(int i =0; i<n; i++)
        scanf("%d", &w[i]);
    for(int j =0; j<n; j++)
        scanf("%d", &c[j]);
    DFS(0,0,0);
    printf("%d", maxValue);
    return 0;
}
