
  memset(used,sizeof used,0);
  used[stax][stay] = 1;  
  top = N*N;
  dfs(stax,stay,0);
  printf("the shortest:\n");  
  print_path(ans);  