// DesignPatternsTest.cpp : Defines the entry point for the application.
//

#include "DesignPatternsTest.h"


//Test Code for Base Factory Method

void TestClientCode(DesignPatterns::Creational::Creator& creator) {
	std::cout << "TestClientCode: " << creator.GetCurrentOpeartion() << std::endl;
}


int main()
{

	DesignPatterns::Creational::ProductImplementation_A pr;

	Lib::A a(5);

	std::cout << "Dll Libraries: " << a.getX() << std::endl;

	std::shared_ptr<int> x = std::make_shared<int>(1), y = std::make_shared<int>(1);
	DesignPatterns::Basic::Command *cmd = new DesignPatterns::Basic::MoveCommand(x, y);

	cmd->execute();

	std::cout << "DesignPatterns find_package: " << "(" << *x << "," << *y << ")" << std::endl;


	Idioms::MyFunctionality* myFunc = new Idioms::MyFunctionality(2);

	std::cout << "CRTP:" << std::endl;
	myFunc->scale(2);
	std::cout << "scale by 2: " << myFunc->getValue() << std::endl;

	myFunc->setToOpposite();
	std::cout << "setToOpposite: " << myFunc->getValue() << std::endl;

	myFunc->square();
	std::cout << "square: " << myFunc->getValue() << std::endl;

	std::cout << "DesignPatterns_Creational" << std::endl;
	DesignPatterns::Creational::Creator* creator = new DesignPatterns::Creational::CreatorProduct_A();
	TestClientCode(*creator);

	auto product_A = creator->FactoryMethod();

	std::cout << "Operation on Product_A: " << product_A->Operation() << std::endl;

	delete creator;
	return 0;
}

