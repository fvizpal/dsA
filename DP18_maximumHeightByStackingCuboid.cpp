#include<bits/stdc++.h>
/*
Maximum height by stacking a cuboid
 given n cuboid
 ith coboids' lenght width and height are given
 choose a subset of cuboid and place on top of each other 
 cuboid placed should have smaller area of face than on which it is kept
 we can rearrange dimensions anyhow that is cuboid can be rotated anyhow

    Algo
     1. sort all three dimensional rows given 
     2. last column shall be assumed as height 
     3. remaining columsns ( 1 and 2) shall be considered lenght and width no respectively
     4. now sorting cubes on the basis of their base, that is first column
     5. fir sabse bade wale ko sabse neeche rkhenge
     6. toh in  a way this prooblem has been converted to longest increasing subsequence problem
     7. use logic of LIS problem
*/
bool check(vector<int> base, vector<int> newBox){
   if( newBox[0] <= base[0] && newBox[1] <= base[1] && newBox[2] <= base[2]){
      return true;
   } else {
      return false;
   }
}

//LIS ka code
int solveSO( int n, vector<int> &a){
    //vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
    vector<int> currRow(n+1, 0);
    vector<int> nextRow(n+1, 0);

    for( int curr = n-1; curr >= 0; curr--){
        for( int prev = curr-1; prev >= -1; prev--){
            //include
            int take = 0;
            if( prev == -1 || check(a[curr], a[prev])){
                take = a[curr][2] + nextRow[curr+1];
            }

            //exclude
            int notTake = 0 + nextRow[prev+1]; // +1 in prev to deal with the indexing problem

            currRow[prev+1] = max(take, notTake);
        }
        nextRow = currRow
    }
    return nextRow[0];
}

int maxheight(vector<vector<int>> &cuboids){
   for ( auto &a : cuboids){
      sort( a.begin(), a.end());
   }

   sort( cuboids.beign(), cuboids.end());


   return solveSO(cuboids.size(), cuboids);

}