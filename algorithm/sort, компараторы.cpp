// std::sort(...) - ������� ����������. ��������� � ������� O( n*log(n) ), �� � ������ ������ O( n*n )

// ���������� � ����������� ����������� �������
bool compareFunction(const std::string& left, const std::string& right) { return left.length() < right.length(); }
std::sort(strings.begin(), end.begin(), compareFunction);

// ���������� � ����������� ����������� ������
auto comlareLambda = [](const std::string& left, const std::string& right) { return left.length() < right.length(); }
std::sort(strings.begin(), end.begin(), comlareLambda);

// ����� ����� ���� ����������� ��������� ������ � ���� ������ ������ ���� �������� �������� ��������� (��� ������� ������� ���������) 
bool operator< (const T& t) { return value < t.value; }
bool operator< (const T& lhs, const T& rhs) { return lhs.value < rhs.value; } // ������������� ������ ������� �������, ���� ������ ������������
// ����� ����� ����������� ��� �����������
std::sort(listT.begin(), listT.begin());

// ��������� �� std ���������� ���������� ������������� ���������, �� ���� �������� ����������� ��� ������ ������� begin-end �������, ������ QList
QList<QString> strings;
std::sort(std::begin(strings), std::end(strings), compare);

/*
���������� ��������������������. ��������������� ��������� O( n*log(n) ) � ����� ������.
������ ���������� � ���� ����������� � 2-5 ��� ��������� ������� ���������� sort().
partial_sort( v.begin(), v.end(), v.end() );

���������� ��������. ��������� O( n*log(n) ) ��� O( n*log(n)*log(n) ),
���� ��� �������������� ������
stable_sort( v.begin(), v.end() );

// ���������� � ���� (heap) - �������� �������, ��������������� ���������� � �����
// (�� ���� � �������� �������, ������������ � ���������� ���� ����������).
// ��������� O( n+n*log(n) )
make_heap( v.begin(), v.end() );
sort_heap( v.begin(), v.end() );
*/

