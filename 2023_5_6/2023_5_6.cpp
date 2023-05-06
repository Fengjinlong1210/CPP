#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

/*
�̳�


class Person
{
public:
	Person()
	{
		cout << "Person()" << endl;
		_age = 0;
		_name = "NULL";
	}

	void Print()
	{
		cout << "age: " << _age << endl;
		cout << "name: " << _name << endl;
	}
private:
	int _age;
	string _name;
	//�����private��Ա���������в��ɼ�����Ҫ���ദ��ֻ��ͨ������ĳ�Ա��������
protected:
	int _sex;
	//�����protected��Ա���������п��Ա�����
};

class Student : public Person  //�﷨ �������� ���̳з�ʽ ���ࣩ
	//��������ʻ����Ա��Ȩ���ǣ��̳з�ʽ�ͻ����Ա���޶��������е���Сֵ
{
public:
	Student()
	{
		cout << "Student()" << endl;
		_id = 12345;
		this->_sex = 1;
	}
private:
	int _id;
};

int main()
{
	Student st1;
	st1.Print(); //��������Լ̳и���ĳ�Ա
	return 0;
}*/

/*
��������������ĸ�ֵ


class Person
{
public:
	Person()
	{
		cout << "Person()" << endl;
	}
protected:
	int _age;
	int _sex;
	string _name;
};

class Student : public Person
{
public:
	Student()
	{
		cout << "Student()" << endl;
	}

	int _id;
private:

};

int main()
{
	//���������Ը��������ֵ, ����ָ�������
	Student st;
	Person p1 = st;
	Person* pp = &st;
	Person& rp = st;

	//��������޷����������ֵ
	//st = p1;

	//��������ָ�����ͨ��ǿ������ת����ֵ����������ָ��
	Person p2;
	Student* pst = (Student*)(&p2);
	//��ʱp2��һ�������ָ��
	pst->_id = 10;
	return 0;
}*/

/*
���������ӵ�ж�����������

class Person
{
public:
	Person()
	{
		cout << "Person()" << endl;
	}

	void func()
	{
		cout << "Person::func" << endl;
	}

protected:
	int _age;
	int _sex;
	string _name;

	int _same = 123;  //ͬʱ����������ͬ�ĳ�Ա����Ϊ����
};

class Student : public Person
{
public:
	Student()
	{
		cout << "Student()" << endl;
	}

	void Print()
	{
		cout << "same: " << _same << endl;
		cout << "P.same:" << Person::_same << endl; //ͨ��::ָ��������
	}

	void func()
	{
		cout << "Student::func" << endl;
	}	//�����е�func�͸����е�func�����ɺ������أ���Ϊ����������Ҫ��ͬһ����������
		//����͸����func��Ϊ���ػ��ض���

	int _id;
private:
	int _same = 456;
};

//��������඼����ͬ��_same ��Աs
//�����ڷ���ʱ�������ȷ����Լ��ĳ�Ա
//��ò�Ҫ�ڸ������ж���ͬ����Ա

int main()
{
	Person p;
	Student S;
	S.Print();
	S.func();
	return 0;
}*/

/*
�������Ĭ�ϳ�Ա����


class Person
{
public:
	Person(int age)
		:_age(age)
	{
		cout << "Person()" << endl;
	}

	Person(const Person& p)
	{
		cout << "Person(const Person& p)" << endl;
		_age = p._age;
	}

	Person& operator=(const Person& p)
	{
		cout << "Person& operator=(const Person& p)" << endl;
		if (this != &p)
		{
			_age = p._age;
		}
		return *this;
	}

	~Person()
	{
		cout << "~Person()" << endl;
	}
protected:
	int _age;
};

class Student : public Person
{
public:
	Student(int id = 100)
		:_id(id), Person(10)  //������û��Ĭ�Ϲ��캯��ʱ����������Ҫ�������û���Ĺ��캯��
	{
		cout << "Student()" << endl;
	}

	Student(const Student& s)
		:Person(s), _id(s._id)
	{
		cout << "Student(const Student& s)" << endl;
	}

	Student& operator=(const Student& s)
	{
		cout << "Student& operator=(const Student& s)" << endl;
		if (this != &s)
		{
			Person::operator=(s);
			_id = s._id;
		}
		return *this;
	}

	~Student()
	{
		cout << "~Student()" << endl;
	}
protected:
	int _id;
};

//1.Ĭ�Ϲ��캯������������Զ��������ȵ��û����Ĭ�Ϲ��캯����������ʼ��������һ���ֵĳ�Ա
		//�������û��Ĭ�ϵĹ��캯�����������������ĳ�ʼ���б��������û���Ĺ��캯��

//2.�����࿽�����캯��������û���Ŀ������캯������ɶԻ���Ŀ�����ʼ��

//3.������operator=������û����operator=��ɻ��ิ��

//4.��������������������֮����Զ����û������������,������������ĳ�Ա,����������Ա

int main()
{
	Student s;
	Student s2(s); 
	Student s3;
	Student s4;
	s3 = s4;
	return 0;
}

*/

//���һ�������̳е���
/*
class A
{
public:
	static A Call() //ͨ����̬��Ա��������Ĭ�Ϲ���
	{
		return A();
	}
private:
	A()
	{
		cout << "A()" << endl;
	}
};

int main()
{
	A aa = A::Call();
}*/


/*
��ľ�̬��Ա
��������������๲��һ��static��Ա����, ֻ��һ��staticʵ��

class parent
{
public:
	parent()
	{
		++count;
	}

	static int GetCount()
	{
		return count;
	}
protected:
	static int count;
};
int parent::count = 0;

class child : public parent
{
public:
protected:
	int _num;
};

class son : public child
{
protected:
	int _size;
};

int main()
{
	parent p1;
	parent p2;
	child c1;
	child c2;
	son s1;
	son s2;
	int ret = parent::GetCount();
	cout << ret << endl;
	return 0;
}*/


/*
�̳�����Ԫ: ��Ԫ�����������������̳�
*/