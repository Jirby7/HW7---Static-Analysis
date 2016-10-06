#include <iostream>
#include <string>

class Homes {
	public:
		Homes();
		virtual void output(std::ostream& outs)const = 0;
		virtual void input(std::istream& ins) = 0;
		virtual void input() = 0;
		virtual void output() = 0;

	protected:
};
	
class Panda: public Homes {
	public:
		Panda();
		void input(std::istream& ins);
		void input();
		void output(std::ostream& outs)const;
		void output();
			
	private:
		double bamboo;
		int trees;
		double area;
};
		
class Eagle: public Homes {
	public:
		Eagle();
		void input(std::istream& ins);
		void input();
		void output(std::ostream& outs)const;
		void output();
	
	private:
		std::string food;
		double thickness;
		double height;
};

class Groundhog: public Homes {
	public:
		Groundhog();
		void input(std::istream& ins);
		void input();
		void output(std::ostream& outs)const;
		void output();
	
	private:
		double radius;	
		double depth;
};

class Dog: public Homes {
	public:
		Dog();
		void input(std::istream& ins);
		void input();
		void output(std::ostream& outs)const;
		void output();
			
	private:
		double diameter;
		double height;
		int windows;
		double length;
		std::string color;
};

class Fish: public Homes {
	public:
		Fish();
		void input(std::istream& ins);
		void input();
		void output(std::ostream& outs)const;
		void output();
			
	private:
		double gallons;
		int toys;
		std::string toyType;
};
