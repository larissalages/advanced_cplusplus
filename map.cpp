#include <iostream>
#include <map>

using namespace std;

class Person
{
private:
	string name;
	int age;

public:
	//Default Constructor
	Person(): name(""), age(0){
	}

	Person(string name, int age): name(name), age(age){
	}

	void print(){
		cout << name << ": " << age << endl;
	}
};


int main()
{
	map<string,int> ages;

	ages["Manu"] = 23;
	ages["Brunno"] = 22;
	ages["Thamy"] = 30;

	pair<string,int> addToMap("Tonho",23);
	ages.insert(addToMap);

	ages.insert(make_pair("Emir",25));

	cout << ages["Brunno"] << endl;

	for(map<string,int>::iterator it = ages.begin(); it != ages.end(); it++)
	{
		cout << it->first <<": " << it->second << endl;
	}

	//With my own class:

	map<int,Person> people;

	people[0] = Person("Manu",23);
	people[1] = Person("Brunno",22);
	people[2] = Person("Thamy",30);
	people[3] = Person("Tonho",23);

	for(map<int,Person>::iterator it = people.begin(); it != people.end(); it++)
	{
		cout << it->first << ": "; //The first key is the index
		it->second.print(); //The second key is the Person
	}

	return 0;
}