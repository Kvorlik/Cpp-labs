class Table {
private:
	friend Table operator + (const Table&, const Table&);
	char* name;
	char* group;
	char* place;
	unsigned int count;
public:
	Table();
	Table(const Table&);
	~Table();
	char* get_name();
	char* get_group();
	char* get_place();
	int get_count();
	void set_name(char*);
	void set_group(char*);
	void set_place(char*);
	void set_count();
	void show();
	int operator == (const Table&);
	Table& operator = (const Table&);
};