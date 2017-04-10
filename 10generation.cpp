#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int kk;
void helper(int k, int last, int *arr)
{
  if(k == last)
  {
    for(int i = 0 ; i < k ; i++)
    {
      cout<<arr[i];
    }
    cout<<endl;
    return;
  }
  if(arr[last-1] == 0)
  {
    arr[last] = 1;
    helper(k, last+1, arr);
    arr[last] = 0;
    helper(k, last+1, arr);
  }
  else
  {
    arr[last] = 0;
    helper(k, last+1, arr);
  }

}
int main()
{
  cin>>kk;
  int arr[kk];
  arr[0] = 0;
  helper(kk,1,arr);
  arr[0] = 1;
  helper(kk,1,arr);
  return 1;
}
