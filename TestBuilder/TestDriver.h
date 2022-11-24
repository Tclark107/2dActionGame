class TesterBase
{
	public:

	private:
		int grade = 0;
		bool debugMode = 0;

		std::ofstream logFile;
		std::ofstream debugFile;

		void Initialize();
		bool checkObjectCreated(/*template*/);
		int getGrade();
		void addOneToGrade();

};
