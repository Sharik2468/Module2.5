#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <array>
#include <vector>

using namespace std;

class Vector
{
private:
	int x, y, z;
	string* Info;
public:
	Vector(int x1, int y1, int z1, string a1) { x = x1; y = y1; z = z1; Info = new string(a1); }
	Vector& operator = (Vector& other) 
	{
		x = other.x;
		y = other.y;
		z = other.z;
		if (other.Info) {
			if (Info) delete Info;
			Info = new string(*(other.Info));
			cout << "Deep Copy";
		}
		return(*this);
	}


};

int main()
{
	// unordered map
	std::unordered_map<int, std::string> umap;

	// Inserting elements into the map
	umap.insert(std::make_pair(1, "a"));
	umap.insert(std::make_pair(2, "b"));
	umap.insert(std::make_pair(3, "c"));
	umap.insert(std::make_pair(4, "d"));

	size_t evenCount = count_if(umap.begin(), umap.end(), [](std::unordered_map<int, string>::value_type vt) {return vt.first % 2 == 0; });
	cout << "even numbers: " << evenCount << " found" << endl;

	array<int, 5> arr;
	arr.fill(11);
	for (int i = 0; i < 5; ++i)
		cout << arr[i] << " ";
	cout << endl;

	//vector<int> a(1);

	vector<Vector> a,b;
	a.push_back(*new Vector(0,0,0,"aa"));
	b.push_back(*new Vector(1,2,3,"ab"));

	std::copy(a.begin(), a.end(), b.begin());

	return 0;
}