#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main() {
    
    map<int, string> M;
    M[0] = "Claire";
    M[1] = "Laura";
    M[9] = "Sasha";
    M[6] = "Riley";
    M[8] = "Jamie";
    
// перебор всех элементов
    for(auto &m:M)
        cout<< m.first <<" : "<< m.second << endl;
	
// перенос map в vector
    vector<pair<int, string>> V;
    V.resize(M.size());  // размер должен быть выделен заранее!!!
    
    copy(M.begin(), M.end(), V.begin()); 
    
    cout << "vector: "<< endl; 
    for(auto &i:V) cout<< i.first << ":" << i.second << "; "; 
    cout << endl << endl;
	
	
    return 0;
}