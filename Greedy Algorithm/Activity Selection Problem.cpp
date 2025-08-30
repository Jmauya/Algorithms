#include<bits/stdc++.h>
using namespace std;
struct Activity
{
    string a_name;
    double s_time, e_time;
};
bool comp(Activity a1, Activity a2)
{
    return (a1.e_time<a2.e_time);
}
int main()
{
    int n;
   cout << "Enter the number of activities: ";
   cin >> n;
    Activity arr[n];
    for(int i=0; i<n; i++)
    {
    cin >> arr[i].a_name >> arr[i].s_time >> arr[i].e_time;
    }
    sort(arr, arr+n, comp);
    int ans=1, index=0;
    vector<string>v;
    v.push_back(arr[0].a_name);
    for(int i=1; i<n; i++)
    {
        if(arr[i].s_time>=arr[index].e_time)
        {
            ans++;
            index = i;
            v.push_back(arr[i].a_name);
        }
    }
    cout << "Total selected Activity: " << ans << endl;
    for(int i=0; i<v.size()-1; i++)
    {
        cout << v[i] << ", ";
    }
    cout<<v[v.size()-1]<<".";
    return 0;
}
