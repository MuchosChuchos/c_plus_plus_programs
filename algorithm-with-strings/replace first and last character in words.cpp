#include <iostream>
#include <string>
#include <Windows.h>

int main()
{
 
    using namespace std;
    
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    string str;
    cout << "������ ����� ���->";
    getline(cin, str);
    int first(0), i(0);
    char buf;
 
    //������� ������� ������� � �����
    int last = str.length()-1;
    while(str[i] == ' '||str[i] == ','||str[i] == '!'||str[i] == '/'||str[i] == '.'||str[i] == '?')        //������� ������ ������
        first = ++i;
 
    if (str[last] == ' '||str[last] == ','||str[last] == '!'||str[last] == '/'||str[last] == '.'||str[last] == '?')      //������� ��������� ������
        while(str[last] == ' '||str[last] == ','||str[last] == '!'||str[last] == '/'||str[last] == '.'||str[last] == '?')
            last--;
 
    for (i; i < last; i++) 
    {
 
        if (str[i] == ' '||str[i] == ','||str[i] == '!'||str[i] == '/'||str[i] == '.'||str[i] == '?')
        {
    
            buf = str[first];
            str[first] = str[i-1];
            str[i-1] = buf; 
            first = i+1;
    
        }
        while(str[i] == ' '||str[i] == ','||str[i] == '!'||str[i] == '/'||str[i] == '.'||str[i] == '?')     //����� ���������� ����� ����� ��������
            if (i != str.length())
                first = ++i;
                
    }
 
    //������ ������� ������� � ��������� �����
    buf = str[first];
    str[first] = str[last];
    str[last] = buf;
        
    cout << "����� ����� ���:" <<str;
 
    cin.get();
    return 0;
 
}
