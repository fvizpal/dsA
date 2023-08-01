#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;


// maximum frequency number question 
int maximumFrequency(vector<int> &arr, int n ){

    unordered_map<int , int> count;

    int maxFreq = 0;
    int maxAns = 0;

    for( int i = 0; i < arr.size(); i++){
        count[arr[i]]++;
        maxFreq = max(maxFreq, count[arr[i]]);
    }

    for( int i = 0; i < arr.size(); i++){
        if(maxFreq == count[arr[i]]){
            maxAns = arr[i];
            break;
        }
    }
    return maxAns;
}  // here TC is O( n )

 

int main(){

    //creation
    unordered_map<string, int> m;

    //insertion

    //making pair
    //1
    pair<string, int > p = make_pair("babbar", 3);
    m.insert(p);

    //2
    pair<string,int> pair2("love", 2);
    m.insert(pair2);

    //3
    m["mera"] = 1;
    m["mera"] = 2; // isse uppar creation hua // now its updation
    // these three are all ways of inserting the pairs into the map
    // there is always single entry for every  key 

    //searching
    cout << m["mera"] << endl ; //2
    cour << m.at["babbar"] << endl; //3

    //trivia
    cout << m.at["unknown"]; // gives error
    cout << m["unknown"]; // will give '0' since it creates here
    // if swap 34 and 35 line then both will give zero

    //size
    cout << m.size() << endl;

    // to check presence
    m.count("bro"); // gives boolean 0 or 1 // on entering key
    
    //erase
    m.erase("love"); // key deni padegi 

    //traversing
    for( auto i:m){
        cout << i.first << " " << i.second << endl;

    }
    // or use iterator
    unordered_map<string, int> :: iterator it = m.begin();
    while( it != m.end()){
        cout << it -> first << " " << it -> second << endl;
        it++;
    }
    // in unoredered_map chize random order m print hoti h 
    // simple map m jese dala ho vese hi hota hai
    

    return 0;
}