#define _CRT_SECURE_NO_WARNINGS

#include <cstdlib>
#include <cstring>
#include <iostream>

using std::cout;
using std::endl;

class String {
public:
	// ���죺Ĭ�ϣ����Σ����������졢�ƶ�����
	String(const char *str = nullptr);
	String(const String &other);
	String(String &&other);

	// ����
	~String();

	// ��ֵ��������ֵ���ƶ���ֵ
	String &operator=(const String &other);	
	String &operator=(String &&other);

private:
	char *m_data;
};

String::String(const char *str)
{
	if (str == nullptr) {
		m_data = new char[1];
		*m_data = '\0';
		cout << "Default constructor" << endl;
	}
	else {
		int length = strlen(str);
		m_data = new char[length + 1];
		strcpy(m_data, str);
		cout << "Pass argument constructor" << endl;
	}
}

String::String(const String &other)
{
	int length = strlen(other.m_data);
	m_data = new char[length + 1];
	strcpy(m_data, other.m_data);
	cout << "Copy constructor" << endl;
}


String::String(String &&other)
{
	m_data = other.m_data;
	other.m_data = nullptr;
	cout << "Move constructor" << endl;
}

String::~String()
{
	delete[] m_data;
	cout << "Destructor" << endl;
}

String &String::operator=(const String &other)
{
	if (this != &other) {
		if (!m_data) delete[] m_data;
		int length = strlen(other.m_data);
		m_data = new char[length + 1];
		strcpy(m_data, other.m_data);
	}
	cout << "Copy assignment" << endl;
	return *this;
}

String &String::operator=(String &&other)
{
	if (this != &other) {
		delete[] m_data;
		m_data = other.m_data;
		other.m_data = nullptr;
	}
	cout << "Move assignment" << endl;
	return *this;
}

int main()
{
	{
		// ���ԣ�Ĭ�Ϲ���
		String s1;

		// ���ԣ����ι���
		String s2("hello world");

		// ���ԣ���������
		String s3(s1);

		// ���ԣ��ƶ�����
		String s4(std::move(s3));

		// ���ԣ�������ֵ
		String s5;
		s5 = s4;

		// ���ԣ��ƶ���ֵ
		String s6;
		s6 = std::move(s5);

		// ���ԣ��Զ�����

	}
	system("pause");
	return 0;
}
