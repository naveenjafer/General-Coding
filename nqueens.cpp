#include <iostream>
using namespace std;

bool checkValid(int m[4][4], int x, int y)
{
  bool valid = true;
  if(!(x >= 0 && x <= 3 && y >= 0 && y <= 3))
  {
    return false;
  }
  for(int i = 0 ; i < 4 ; i++)
  {
    for(int j = 0 ; j < 4 ; j++)
    {
      if(m[i][j] == 1)
      {
        if(i == x || j == y)
        {
          valid = false;
          return false;
        }
      }
    }
  }

  for(int i = -1 ; i <= 1 ; i+=2)
  {
    for(int j = -1 ; j <= 1 ; j+=2)
    {
      int dummy_x = x;
      int dummy_y = y;
      while(dummy_x >= 0 && dummy_x <=3 && dummy_y >= 0 && dummy_y <= 3)
      {
        if(m[dummy_x][dummy_y] == 1)
        {
          valid = true;
          return false;
        }
        dummy_x+=i;
        dummy_y+=j;
      }
    }
  }
  cout<<"value of x and y in check"<<x << " "<< y<< endl;
  for(int i = 0 ; i < 4 ; i++)
  {
    for(int j = 0 ; j < 4 ; j++)
    {
      cout<<m[i][j]<<" ";
    }
    cout<<endl;
  }

  return true;
}
void nqueen(int m[4][4], int queens_left, int x, int y, int &answer)
{
  cout<<"n queens for the following x and y called"<<x << " "<<y<<" "<<endl;
  int dupm[4][4];
  for(int i = 0 ; i < 4 ; i++)
  {
    for(int j = 0 ; j < 4 ; j++)
    {
      dupm[i][j] = m[i][j];
    }
  }
  if(checkValid(m, x, y))
  {
    // valid config
    dupm[x][y] = 1;
    queens_left--;
    if(queens_left == 0)
    {
      cout<<"********";
      answer = 1;
      for(int ii = 0 ; ii < 4 ; ii++)
      {
        for(int jj = 0 ; jj < 4 ; jj++)
        {
          cout<<dupm[ii][jj]<<" ";
        }
        cout<<endl;
      }
      cout<<"SOLUTION!!!!!!!!!!!!!!!!!!!!!!!!"<<endl<<endl;
      return;
    }
    for(int i = 0 ; i < 4 ; i++)
    {

        cout<<"before n queen call with x and y"<<x<<" "<<y<<endl;
        nqueen(dupm, queens_left, x+1, i, answer);
        if(answer == 1)
        {
          return;
        }
        for(int ii = 0 ; ii < 4 ; ii++)
        {
          for(int jj = 0 ; jj < 4 ; jj++)
          {
            dupm[ii][jj] = m[ii][jj];
          }
        }
        dupm[x][y] = 1;


    }

  }

}

int main()
{
  int n = 4;
  int m[4][4];
  for(int i = 0 ; i < n ; i ++)
  {
    for(int j = 0 ; j < n ; j++)
    {
      m[i][j] = 0;
    }
  }
  int answer = 0;
  for(int i = 0 ; i < 4 ; i++)
  {
    nqueen(m, n, 0, i, answer);
  }
  if(answer == 1)
  {
    cout<<"FOund";
  }
  else
  {
    cout<<"no soln";
  }
  return 1;
}
