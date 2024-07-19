#include <iostream>
#include <thread>
#include <atomic>

std::atomic<int> count(1);

void PrintNumber(int num, int next_num) {
	while (true) {
		if (count.load() == num) {
			std::cout << "thread" << num << std::endl;
			count.store(next_num);
			break;
		}
	}
}


int main() {
	//�}���`�X���b�h
	
	std::thread first(PrintNumber,1,2);
	std::thread second(PrintNumber,2,3);
	std::thread theard(PrintNumber,3,4);

	//�\��
	first.join();
	second.join();
	theard.join();



	return 0;
}