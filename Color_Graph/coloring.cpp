#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int dinh, canh;
string colorpoint[21];
string color[20] = {"GhostWhite", "PeachPuff1", "LightCyan1", "LightGoldenrod1", "LemonChiffon", "MintCream", "AliceBlue", "LavenderBlush", "MistyRose", "white", "black", "DarkSlateGray", "SlateGray", "LightGray", "MidnightBlue", "NavyBlue", "CornflowerBlue", "MediumSlateBlue", "SteelBlue", "DarkSeaGreen"};
vector<vector<int>> ke;

int main()
{
    freopen("dothi.dot", "w", stdout);
    cin>>dinh>>canh;
    ke.resize(dinh+1);
    int i, temp1, temp2;
    int *edge;
    edge = (int*) malloc (canh*2*sizeof(int)); 
    for(i = 0; i<canh; i++)
    {
        cin>>temp1>>temp2;
        edge[i*2] = temp1;
        edge[i*2+1] = temp2;
        ke.at(temp1).push_back(temp2);
        ke.at(temp2).push_back(temp1);
    }
    colorpoint[1] = color[0];
    int check;
    // Coloring each nodes.
    for (i = 2; i<=dinh; i++)// By order from 2 to end.
    {
        for (temp1 = 0; temp1<i; temp1++) // Try color from 1 to i
        {
            check = 1;
            for (temp2 = 0; temp2<ke.at(i).size(); temp2++)
            {
                if(ke.at(i).at(temp2)<i)
                {
                    if(colorpoint[ke.at(i).at(temp2)] == color[temp1])
                    {
                        check = 0;
                        break;
                    }
                }
            } 
            if(check == 1)
            {
                colorpoint[i] = color[temp1];
                break;
            }
        }
    }
    // Ending
    cout<<"graph dothi\n";
    cout<<"{\n";
    for (i = 0; i<dinh; i++)
    {
        cout<<"   "<<i+1;
        cout<<" [fillcolor="<<colorpoint[i+1]<<", style=filled];\n";
    }
    for(i = 0; i<canh; i++)
    {
        cout<<"   "<<edge[i*2]<<" -- "<<edge[i*2+1]<<";"<<endl;
    }
    cout<<"}";
    return 0;
}