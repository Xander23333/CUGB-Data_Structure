#include <bits/stdc++.h>
using namespace std;

int X[10];
int ans = 0;
void dfs(int line)
{
  if (line >= 8)
  {
    ++ans;
    return;
  }
  bool flag;
  for (int col = 0; col < 8; ++col)
  {
    flag = true;
    for (int i = 0; i < line; ++i)
    {
      int j = X[i];
      if (!(col != j && abs(line - i) != abs(col - j)))
      {
        flag = false;
        break;
      }
    }
    if (flag)
    {
      X[line] = col;
      dfs(line + 1);
    }
  }
}

int top = 0;
void undfs()
{
  ans = 0;
  X[top++] = -1;
  while (top != 0)
  {
    // for (int i = 0; i < top; ++i)
    //   cout << i << " " << X[i] << endl;
    // cout << endl;
    // cout<<top<<endl;
    if (top > 8)
    {
      ++ans;
      --top;
    }
    else
    {
      if (X[top - 1] >= 7)
        --top;
      else
      {
        ++X[top-1];

        bool flag = true;
        int line = top - 1, col = X[top - 1];
        for (int i = 0; i < top - 1; ++i)
        {
          int j = X[i];
          if (!(col != j && abs(line - i) != abs(col - j)))
          {
            flag = false;
            break;
          }
        }
        if (flag) X[top++] = -1;

      }
    }
  }
}
int main()
{
  undfs();
  cout << ans << endl;
}