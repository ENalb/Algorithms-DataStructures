#include <iostream>
#include "gtree.h"

int f1(int x){
	return x * x;
}

int f2(int x){
	return 1 + x;
}

int f3(int x){
	return x;
}

int f4(int x){
	return x * 3;
}


int main(){
	GTree<int> g;
	g.insert(f1, 0, 0);
	g.insert(f2, 1, 0);
	g.insert(f3, 1, 1);
	g.insert(f4, 2, 0);

	int res = g.execute(10);
	std::cout << res << std::endl;
	
	g.remove(2, 0);

	int res2 = g.execute(10);
	std::cout << res2 << std::endl;
	
	g.traverse(g.getRoot());
}
