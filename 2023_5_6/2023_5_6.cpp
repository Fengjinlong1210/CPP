#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

/*
继承


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
	//基类的private成员在派生类中不可见，需要父类处理，只能通过父类的成员函数访问
protected:
	int _sex;
	//基类的protected成员在派生类中可以被访问
};

class Student : public Person  //语法 （派生类 ：继承方式 基类）
	//派生类访问基类成员的权限是（继承方式和基类成员的限定符）其中的最小值
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
	st1.Print(); //派生类可以继承父类的成员
	return 0;
}*/

/*
基类和派生类对象的赋值


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
	//子类对象可以给父类对象赋值, 包括指针和引用
	Student st;
	Person p1 = st;
	Person* pp = &st;
	Person& rp = st;

	//父类对象无法给子类对象赋值
	//st = p1;

	//父类对象的指针可以通过强制类型转换赋值给子类对象的指针
	Person p2;
	Student* pst = (Student*)(&p2);
	//此时p2是一个子类的指针
	pst->_id = 10;
	return 0;
}*/

/*
父类和子类拥有独立的作用域

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

	int _same = 123;  //同时定义名字相同的成员，称为隐藏
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
		cout << "P.same:" << Person::_same << endl; //通过::指定作用域
	}

	void func()
	{
		cout << "Student::func" << endl;
	}	//子类中的func和父类中的func不构成函数重载，因为函数重载需要在同一个作用域中
		//子类和父类的func称为隐藏或重定义

	int _id;
private:
	int _same = 456;
};

//父类和子类都有相同的_same 成员s
//子类在访问时，会优先访问自己的成员
//最好不要在父子类中定义同名成员

int main()
{
	Person p;
	Student S;
	S.Print();
	S.func();
	return 0;
}*/

/*
派生类的默认成员函数


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
		:_id(id), Person(10)  //当基类没有默认构造函数时，派生类需要主动调用基类的构造函数
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

//1.默认构造函数：派生类会自动并且优先调用基类的默认构造函数，用来初始化基类那一部分的成员
		//如果基类没有默认的构造函数，则必须在派生类的初始化列表主动调用基类的构造函数

//2.派生类拷贝构造函数必须调用基类的拷贝构造函数，完成对基类的拷贝初始化

//3.派生类operator=必须调用基类的operator=完成基类复制

//4.派生类析构函数被调用之后会自动调用基类的析构函数,先清理派生类的成员,再清理基类成员

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

//设计一个不被继承的类
/*
class A
{
public:
	static A Call() //通过静态成员函数调用默认构造
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
类的静态成员
所有派生类与基类共用一个static成员变量, 只有一个static实例

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
继承与友元: 友元函数不被派生类所继承
*/