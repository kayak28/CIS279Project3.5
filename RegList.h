//RegList.h
#include <iostream>
using namespace std;

class RegList
{
	public:
		RegList(int capa);
		//~RegList();
		void addStudent(int stuId);
		void removeStudent(int stuId);
		int removeStudent(int stuId);
		int removeFromFront();
		bool isEnrolled(int stuId)const;
		friend ostream& operator<<(ostream& out, const RegList& obj);
		bool isFull() const;
		bool isEmpty() const;
		int listSize() const;


		/* data */
	private:
		int capacity;
		int manyNodes;
		node* head;

};