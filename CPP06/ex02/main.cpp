#include "Base.hpp"

Base *generate(void)
{
	Base *obj;
	int selector;
	
	selector = std::rand() % 3;
	switch (selector)
	{
		case (0):
			obj = new A();
			break;
		case (1):
			obj = new B();
			break;
		case (2):
			obj = new C();
			break;
		default:
			obj = NULL;
	}
	return obj;
}

void identify(Base *p)
{
	A *a = dynamic_cast<A*>(p);
	B *b = dynamic_cast<B*>(p);
	C *c = dynamic_cast<C*>(p);

	if(a)
		std::cout << "Type: A" << std::endl;
	else if(b)
		std::cout << "Type: B" << std::endl;
	else if(c)
		std::cout << "Type: C" << std::endl;
	else
		std::cout << "Wrong type" << std::endl;
}

void identify(Base &p)
{
	try{
		A &a = dynamic_cast<A&>(p);
		std::cout << "Type: A" << std::endl;
		(void)a;
		return ;
	}
	catch (const std::exception &e){
		(void)e;
	}
	try{
		B &b = dynamic_cast<B&>(p);
		std::cout << "Type: B" << std::endl;
		(void)b;
		return ;
	}
	catch(const std::exception &e){
		(void)e;
	}
	try{
		C &c = dynamic_cast<C&>(p);
		std::cout << "Type: C" << std::endl;
		(void)c;
		return ;
	}
	catch(std::exception &e){
		(void)e;
	}
}

int main(void)
{
	std::srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		Base *ptr = generate();
		std::cout << "Object " << i + 1 << " (pointer): ";
		identify(ptr);
		std::cout << "Object " << i + 1 << " (reference): ";
		identify(*ptr);
		delete ptr;
		std::cout << std::endl;
	}
	return 0;
}