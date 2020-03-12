#include <iostream>
#include <memory>
using namespace std;

struct Kullanim {
	uint32_t kullanilan_bellek;
	uint32_t bosalan_bellek;
	uint32_t mevcut_bellek() {
		return kullanilan_bellek - bosalan_bellek;
	}
};

static Kullanim diyagram;

void* operator new(size_t size) {
	diyagram.kullanilan_bellek += size;
	return malloc(size);
}

void operator delete(void* memory,size_t size) {
	diyagram.bosalan_bellek += size;
	free(memory);
}

struct object {
	int x, y, s, f;
};

int main() {
	cout << diyagram.mevcut_bellek() << endl;
	string a = "sadfef";
	cout << diyagram.mevcut_bellek() << endl;
	object* b = new object;
	cout << diyagram.mevcut_bellek() << endl;
	delete b;
	cout << diyagram.mevcut_bellek() << endl;
	return 0;
}