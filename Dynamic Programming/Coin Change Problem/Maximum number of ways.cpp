#include<bits/stdc++.h>
using namespace std;
int main()
{
int n, amount;
cout << "Enter the Numbers of Coin: ";
cin >> n;
int coin[n];
cout << "Enter the Coins:" << endl;
for(int i = 0; i < n; i++)
cin >> coin[i];
cout << "Enter the Amount of Coin: ";
cin >> amount;
int table[n][amount+1];
for(int i = 0; i < n; i++)
table[i][0] = 1;
for(int j=1; j <= amount; j++)
{
if(j % coin[0] == 0)
{
table[0][j] = 1;
}

else
{
table[0][j] = 0;
}
}
for(int i=1; i<n; i++)
{
for(int j=1; j<=amount; j++)
{
if(j >= coin[i])
{
table[i][j] = table[i-1][j] +
table[i][j-coin[i]];
}
else
{
table[i][j] = table[i-1][j];
}
}
}
cout << "Maximum Number Ways of Coin Change : " <<
table[n-1][amount] << endl;
return 0;
}
