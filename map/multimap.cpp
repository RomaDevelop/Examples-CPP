#include <iostream>
#include <map>
 
int main() {
    std::multimap<std::string, std::string> myMultimap;
 
    myMultimap.insert({"овощи", "чеснок"});
    myMultimap.insert({"овощи", "чеснок"});
    myMultimap.insert({"овощи", "лук"});
 
    myMultimap.insert({"фрукты", "яблоко"});
    myMultimap.insert({"фрукты", "банан"});
    myMultimap.insert({"фрукты", "груша"});
    myMultimap.insert({"фрукты", "апельсин"});
 
    myMultimap.insert({"овощи", "морковь"});
    myMultimap.insert({"овощи", "картофель"});
	
	myMultimap["ягоды"] = "черника"; // нельзя - no match for 'operator[]'
    
    std::cout << "все элементы по порядку\n";
    for (const auto& pair : myMultimap) {
        std::cout << pair.first << ": " << pair.second << '\n';
    }
 
    std::cout << "\nфрукты\n";
    auto range = myMultimap.equal_range("фрукты");
    for (auto it = range.first; it != range.second; ++it) {
        std::cout << "Элемент с ключом 1: " << it->second << "\n";
    }
 
    std::cout << "\nовощи\n";
    range = myMultimap.equal_range("овощи");
    for (auto it = range.first; it != range.second; ++it) {
        std::cout << "Элемент с ключом 1: " << it->second << "\n";
    }
    
    return 0;
}