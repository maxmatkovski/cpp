#include <iostream>
#include <string>

using namespace std;

// OBJECT ORIENTED PROGRAMMING IN C++


// creating an abstract class
class AbstractEmployee {
	virtual void AskForPromotion() = 0;
	// pure virtual makes this function obligatory

};

// AbstractEmployee contract is signed
class Employee :AbstractEmployee {
private:
	// Member Variables
	string Company;
	int Age;

protected:
	string Name;

public:
	
	// METHODS

	// getter and setter functions
	void setName(string name) {
		Name = name;
	}
	string getName() {
		return Name;
	}
	void setCompany(string company) {
		Company = company;
	}
	string getCompany() {
		return Company;
	}
	void setAge(int age) {
		if (age >= 18) {
		Age = age;
		}

	}
	int getAge() {
		return Age;
	}

	void IntroduceYourself() {
		cout << "Name: " << Name << endl;
		cout << "Company: " << Company << endl;
		cout << "Age: " << Age << endl;
	}
	// Creating a Constructor (same name as class)
	Employee(string name, string company, int age) {
		Name = name;
		Company = company;
		Age = age;
	}
	
	// implementation of abstract function (errors on Employee objects have dissapeared afterwards)
	void AskForPromotion() {
		if (Age > 30)
			cout << Name << " got promoted " << endl;
		else
			cout << Name << ", sorry no promotion for you" << endl;
	}

	virtual void Work() {
		cout << Name << " is checking email, task backlog, peforming tasks.. " << endl;
	} // add virtual to allow polymorphic reference
		// virtual essentially says check derived classes for additional
		// implementation and if there is, use that implementation
};

// Developer is Child class of Employee

class Developer : public Employee {
public:
	string FavProgrammingLanguage;

	// Need to create a DEFAULT CONSTRUCTOR for Developer
	// Since Developer is Derived from Employee
	// Need to copy parameters of default constructor for Employee to Developer 
	Developer(string name, string company, int age, string favProgrammingLanguage)
		: Employee(name, company, age)
		// Using Employee default Constructor to construct first three parameters
	{
		FavProgrammingLanguage = favProgrammingLanguage;
	}
	
	void FixBug() {
		cout << Name << " fixed bug using " << FavProgrammingLanguage << endl;
	} 

	void Work() {
		cout << Name << " is writing " << FavProgrammingLanguage << endl;
	}
};

class Teacher:public Employee {
public:
	string Subject;
	// constructor
	Teacher(string name, string company, int age, string subject)
		: Employee(name, company, age)
	{
		Subject = subject;
	}

	void PrepareLesson() {
		cout << Name << " is preparing a " << Subject << " lesson" << endl;}

	void Work() {
		cout << Name << " is teaching " << Subject << endl;
	}
	
};

int main() {

	Developer Ruben = Developer ("Ruben", "Facebook", 20, "C++");

	Teacher Dean = Teacher("Dean", "NA", 25, "Stats");
		
	Employee *e1 = &Ruben;
	Employee* e2 = &Dean;
	
	e1->Work();
	e2->Work();
}

/*

Encapsulation is the idea of creating private member variables
and using public functions to access these variables
(getter and setter functions)

Abstraction is hiding complex processses in simpler looking interfaces

Inheritance 
Base class (aka superclass or parent class)
Derived class (aka subclass or child class)

Polymorphism
Ability of an object to have many forms
Work() is an example of polymorphism

The most common use is when a parent clas reference is used to 
refer to a child class
*/
