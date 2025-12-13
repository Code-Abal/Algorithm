using namespace std;
#include <iostream>
#include <string>

int main()
{
	while (1)
	{
		string name, group;
		int age, weight; cin >> name >> age >> weight;

		if (name == "#" && age == 0 && weight == 0) break;

		if (age > 17 || weight >= 80) group = "Senior";
		else group = "Junior";

		cout << name << " " << group << "\n";
	}
	return 0;
}

