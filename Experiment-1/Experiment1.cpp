#include <bits/stdc++.h>

using namespace std;
using namespace chrono;


void complexRec(int n,int& operation,int depth,int& maxdepth) {
    
    maxdepth=max(depth,maxdepth);
   if (n <= 2) {
       return;
   }


   int p = n;
   while (p > 0) {
       vector<int> temp(n);
       for (int i = 0; i < n; i++) {
           temp[i] = i ^ p;
           operation++;
       }
       p >>= 1;
       operation+=1;
       operation++;
   }


   vector<int> small(n);
   for (int i = 0; i < n; i++) {
       small[i] = i * i;
       operation++;
   }


   reverse(small.begin(), small.end());
   operation+=n;


   complexRec(n / 2,operation,depth+1,maxdepth);
   complexRec(n / 2,operation,depth+1,maxdepth);
   complexRec(n / 2,operation,depth+1,maxdepth);
}

int main() {

    vector<int> inputs = {16, 32, 64, 128};
    int operation=1,maxdepth=0;
    for (int n : inputs) {

        operation = 0;

        auto start = high_resolution_clock::now();
        complexRec(n, operation,0,maxdepth);
        auto end = high_resolution_clock::now();

        auto duration = duration_cast<milliseconds>(end - start);

        cout << "n = " << n << endl;
        cout << "Operations = " << operation << endl;
        cout << "Recursion Depth = " << maxdepth << endl;
        cout << "Time Taken = " << duration.count() << " ms\n";
        cout << "-----------------------------\n";
    }
    return 0;
}
