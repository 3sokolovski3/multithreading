#include<iostream>
#include<thread>
#include<chrono>

int Sum(int a, int b)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	std::cout << "ID potoka =  " << "======================\t" << "SUM STARTED\t========================= " << std::endl;

	std::this_thread::sleep_for(std::chrono::milliseconds(2000));

	std::cout << "ID potoka  = " << "======================\t" << "SUM STOPED\t=========================" << std::endl;
	return a + b;

}

int main()
{
	///std::thread th (DW,23,4);
	//int q = 5;
	//DW(q);
	//std::cout << q;
	//std::thread th(Sum,std::ref(q));
	int result;
	std::thread th([&result]()
		{
			result = Sum(2, 5);
		});


	for (size_t i = 0; i < 10; i++)
	{
		std::cout << "ID POTOKA = " << std::this_thread::get_id() << "\t MAIN " << i << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}


	th.join();
	std::cout << "SuM result  = " << result;;
	return 0;
}
