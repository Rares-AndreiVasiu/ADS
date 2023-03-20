void findValues(int A[], int n, int vals[]) {
    int mn = A[0];
    int mx = A[0];
    int sum = A[0];
    
    for(int i = 1; i <n; ++i)
    {
       if(A[i] < mn)
       {
           mn = A[i];
       }
        
        if(A[i] > mx)
       {
           mx = A[i];
       }
        
      sum += A[i];
    }
    
    vals[0] = mn;
    vals[1] = mx;
    vals[2] = sum;
    return 0;
}




