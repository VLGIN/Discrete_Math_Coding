#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>

using namespace std;
int *dinh;
bool *dis;
int *prufer;
int po = 0;
vector<vector<int>> ke;

void printfPrufer(int n)
{
    int i, j, k;
    for (i = 1; i<=n; i++)
    {
        if(ke.at(i).size() == 1 && dis[i] == false)
        {
            dis[i] = true;
            prufer[po] = ke.at(i).back();
            po++;
            for (j = 0; j<=n; j++)
            {
                if(dis[j] == false)
                {
                    for (k = 0; k<ke.at(j).size(); k++)
                    {
                        if(ke.at(j).at(k) == i) 
                        {
                            ke.at(j).erase(ke.at(j).begin()+k);
                            break;
                        }
                    }
                }
            }
            printfPrufer(n);
            break;
        }
    }
}

int main()
{
    int n, i, temp1, temp2;
    scanf("%d", &n);
    ke.resize(n+1);
    prufer = (int*) malloc (n*sizeof(int));
    dis = (bool*) malloc ((n+1)*sizeof(bool));
    dinh = (int*) malloc ((n+1)*sizeof(int));
    for(i = 0; i<n; i++)
    {
        scanf("%d %d", &temp1, &temp2);
        ke.at(temp1).push_back(temp2);
        ke.at(temp2).push_back(temp1);
    }
    for(i = 0; i<=n; i++)
    {
        dis[i] = false;
    }
    printfPrufer(n);
    for(i = 0; i<n-1; i++)
    {
        printf("%d\t", prufer[i]);
    }
    return 0;
}