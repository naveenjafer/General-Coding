#include <iostream>
using namespace std;

int x_change[8] = {1,-1,-2,-2,-1,1,2,2};
int y_change[8] = {2,2,1,-1,-2,-2,-1,1};
bool safety_check(int x, int y)
{
  if(x <= 7 && y <= 7 && x>= 0 && y >=0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void backtrack(int x, int y, int board[8][8],int step, int &answer)
{
  //cout<<step<<endl;

  if(step == 63)
  {
  //  cout<<step<<endl;
    for(int i = 0 ; i < 8 ; i++)
    {
      for(int j = 0 ; j < 8 ; j++)
      {
        cout<<board[i][j]<<" ";
      }
      cout<<endl;
    }
    answer = 1;
    return;
  }
  int board_dup[8][8];
  for(int i = 0 ; i < 8 ; i++)
  {
    for(int j = 0 ; j < 8 ; j++)
    {
      board_dup[i][j] = board[i][j];
    }
  }
  for(int i = 0 ; i < 8 ; i++)
  {
    if(safety_check((x + x_change[i]),(y + y_change[i]) ) && board_dup[x + x_change[i]][y + y_change[i]] == -1)
    {
    //  cout<<"came for value of i"<<i<<endl;
      board_dup[x + x_change[i]][y + y_change[i]] = step+1;
      cout<<x + x_change[i]<<" "<<y + y_change[i]<<" "<<step+1<<endl;
    /*  if(step >= 60)
      {
        cout<<x + x_change[i]<<" "<<y + y_change[i]<<" "<<step+1<<"value of i"<<i<<endl;
        cout<<step<<endl;
      } */
      cout<<endl;
      /*for(int ii = 0 ; ii < 8 ; ii++)
      {
        for(int jj = 0 ; jj < 8 ; jj++)
        {
          cout<<board_dup[ii][jj]<<" ";
        }
        cout<<endl;
      }*/
      backtrack(x + x_change[i], y + y_change[i], board_dup, step + 1, answer);
      if(answer == 1)
      {
        return;
      }
      for(int ii = 0 ; ii < 8 ; ii++)
      {
        for(int jj = 0 ; jj < 8 ; jj++)
        {
          board_dup[ii][jj] = board[ii][jj];
        }
      }
    }

  }
}
int main()
{
  int board[8][8];

  for(int i = 0 ; i < 8 ; i++)
  {
    for(int j = 0 ; j < 8 ; j++)
    {
      board[i][j] = -1;
    }
  }
  board[0][0] = 0;
  int answer = 0;
    backtrack(0,0,board,0,answer);

    if(answer == 0)
    {
      cout<<"Solution does not exist";
    }
    else
    {

      cout<<"solution exists";
    }
}
