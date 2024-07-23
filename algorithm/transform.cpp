// transform vector -> list
    vector<int> vi {45,45,78,54,12,485,8,5};
    list<int> li;
    li.resize(10); // размер должен быть выделен заранее!!!
    
    transform(vi.begin(), vi.end(), li.begin(), [](int i) { return i+1; }); // i+1!!! i++ почему-то не меняет!!!
    
    cout << "vector: "<< endl; 
    for(auto &i:vi) cout<< i << "\t"; 
    cout << endl << endl; 
    
    cout << "transform in list: "<< endl; 
    for(auto &i:li) cout<< i << "\t"; 
    cout << endl << endl;