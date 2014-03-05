//RegList.cpp

	RegList(int capacity);
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
