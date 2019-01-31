class String{
	public :
		int length;
		char* str;
		char* sub;
		String();
		String(const char* c);
		int len();
		int indexof(char);
		char* substring(int ,int);
		String operator+(const String );
		String operator=(const String);
		~String();

};
		

