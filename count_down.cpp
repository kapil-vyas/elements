#include <iostream>
using std::cin;
using std::cout;

int main() {
	for(int i=1;i<=5;i++) {
		for(int j=1;j<=6-i;j++) {
			cout<< "#";
		}
		cout<<"\n";
	}
	return 0;
}

