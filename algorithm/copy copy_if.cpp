// copy (перенос map в vector)
    vector<pair<int, string>> V;
    V.resize(M.size());  // размер должен быть выделен заранее!!! именно resize, не reserve
	// или можно копировать с применением back_inserter
	
    copy(M.begin(), M.end(), V.begin()); // можно копировать по условию (copy_if)
    
    cout << "vector: "<< endl; 
    for(auto &i:V) cout<< i.first << ":" << i.second << "; "; 
    cout << endl << endl;

// copy_if  без выделения размера заранее (back_inserter)

    vector<int> from {456,64,65,64,645,10,98,97,2348};
    vector<int> to;
    
    copy_if(from.begin(),from.end(), back_inserter(to),
			[](int a) { return a > 100; });   // по итогу в векторе будет 456 645 2348
	
	for(auto i:to) cout << i << " ";