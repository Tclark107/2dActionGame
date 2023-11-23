#include <fstream>

class TestBase
{
	public:
		TestBase();

		void addOneToGrade();
		int getGrade();

	private:
		int grade = 0;
		bool debugMode = 0;

		std::ofstream logFile;
		std::ofstream debugFile;

		void Initialize();
		bool checkObjectCreated(/*template*/);

};
