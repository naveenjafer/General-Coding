#include <iostream>
using namespace std;

int x_change[4] = {0,0,1,-1};
int y_change[4] = {1,-1,0,0};

bool within_bounds(int x, int y)
{
  if(x < 4 && y < 4 && x >= 0 && y >= 0)
  {
    return(true);
  }
  else
  {
    return(false);
  }
}
void maze(int m[4][4], int &soln, int x,int y, int path[4][4])
{
  cout<<"called with x and y "<<x<<" "<<y<<endl;
  if(x == 3 & y == 3)
  {
    // reached end of path.
    soln = 1;
    for(int i = 0 ; i < 4 ; i++)
    {
      for(int j = 0 ; j < 4 ; j++)
      {
        cout<<path[i][j]<<" ";
      }
      cout<<endl;
    }
    return;
  }
  int path_dup[4][4];
  for(int i = 0 ; i < 4 ; i++)
  {
    for(int j = 0 ; j < 4 ; j++)
    {
      path_dup[i][j] = path[i][j];
    }
  }
  for(int i = 0 ; i < 4 ; i++)
  {
    cout<<x<<" "<<y<<" valuof x and y "<<endl;
    if(within_bounds(x+x_change[i], y+y_change[i]) && m[x+x_change[i]][y+y_change[i]] == 1 && path_dup[x+x_change[i]][y+y_change[i]] != 1)
    {
         path_dup[x+x_change[i]][y+y_change[i]] = 1;
         maze(m,soln,x+x_change[i],y+y_change[i],path_dup);
         if(soln == 1)
         {
           return;
         }
         for(int ii = 0 ; ii < 4 ; ii++)
         {
           for(int jj = 0 ; jj < 4 ; jj++)
           {
             path_dup[ii][jj] = path[ii][jj];
           }
         }
      }
  }
}
int main()
{
  int m[4][4] = { {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };
  int soln = 0;
  int path[4][4] = {{1,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
  maze(m,soln,0,0, path);
  if(soln == 0)
  {
    cout<<"No solution found";
  }

}
