//====================================================================
# моё

class ServerChannel : public ICANChannel
{
	QString ipAdress;
	int portCmd;
	int portData;
	
	std::tuple<QString, int, int> GetIP();
};

std::tuple<QString, int, int> ServerChannel::GetIP()
{
	return {ipAdress, portCmd, portData};
}

void ServerChannel::SetIP(std::tuple<QString, int, int> Tuple_IP_portCmd_portData)
{
	ipAdress = get<0>(Tuple_IP_portCmd_portData);
	portCmd = get<1>(Tuple_IP_portCmd_portData);
	portData = get<2>(Tuple_IP_portCmd_portData);
}
//====================================================================
# из 21 фичи https://habr.com/ru/companies/otus/articles/741428/

auto get_employee_detail()
{
    // делаем что-нибудь . . . 
    return std::make_tuple(32, " Vishal Chovatiya", "Bangalore");
}

string name;
std::tie(std::ignore, name, std::ignore) = get_employee_detail();
//====================================================================
# из СТЛ

#include <iostream>
#include <stdexcept>
#include <string>
#include <tuple>
 
std::tuple<double, char, std::string> get_student(int id)
{
    switch (id)
    {
        case 0: return {3.8, 'A', "Lisa Simpson"};
        case 1: return {2.9, 'C', "Milhouse Van Houten"};
        case 2: return {1.7, 'D', "Ralph Wiggum"};
        case 3: return {0.6, 'F', "Bart Simpson"};
    }
 
    throw std::invalid_argument("id");
}
 
int main()
{
    const auto student0 = get_student(0);
    std::cout << "ID: 0, "
              << "GPA: " << std::get<0>(student0) << ", "
              << "grade: " << std::get<1>(student0) << ", "
              << "name: " << std::get<2>(student0) << '\n';
 
    const auto student1 = get_student(1);
    std::cout << "ID: 1, "
              << "GPA: " << std::get<double>(student1) << ", "
              << "grade: " << std::get<char>(student1) << ", "
              << "name: " << std::get<std::string>(student1) << '\n';
 
    double gpa2;
    char grade2;
    std::string name2;
    std::tie(gpa2, grade2, name2) = get_student(2);
    std::cout << "ID: 2, "
              << "GPA: " << gpa2 << ", "
              << "grade: " << grade2 << ", "
              << "name: " << name2 << '\n';
 
    // C++17 structured binding:
    const auto [gpa3, grade3, name3] = get_student(3);
    std::cout << "ID: 3, "
              << "GPA: " << gpa3 << ", "
              << "grade: " << grade3 << ", "
              << "name: " << name3 << '\n';
}