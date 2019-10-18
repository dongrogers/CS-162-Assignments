#ifndef ten_h
#define ten_h
#include <iostream>

using namespace std;

class tenant{
	private:
		int budget;
		int score;
	public:
		tenant();
		int get_score() const;
		int get_budget() const;

		void set_budget(int num);
		void set_score(int num);

		const tenant& operator=(const tenant&);
};


#endif
