/* MERGE SORT
 selection , bubble, insertion sorts have O(n^2) average case TC
 Merge sort has O(n*logn)
 recursion is the pre requisite

 it will be entirely different from previous algos

 we will divide the array in two possible equal halves 
 even sized array will give equal halves but nit in odd sized
 now we will sort these halves then merge them 
 but how to merge
 we shall lets say make a function that that takes the two arrays that are needed to be merged and a third array which will be the merged array
 say i , j & k are pointers to elements of left , right and final array 
 now compare elements in left and right and keep putting into final array,  and incrementing the pointer

 but how to even sort these sublists of arrays??
 we can futher divide the arrays so to arrive at futher sub problems
 we can keep dividing till we have only one element in sub arrays
 now combine( or merge ) these lists so that they give sorted superlists
 just like we did in above merging

 all this should be done recursively

 . this sorting falls in category of divide and conquer algorithm category
 . this is a recursive algorithm
 . it is also a stable sorting algorithm, say we want to sort points of pair of x and y coordinate 
   we can do that too, but in sorting (2,5) & (2,3) the relative order in the final sorted is same as the original list

 . it is not an in-place sorting algorithm unlike buuble sort that uses only temporary space
 . SC of merge sort is O(N) , actually theta noation should be used
 . TC is O(nlogn) in worst case here too theta
 . 

*/