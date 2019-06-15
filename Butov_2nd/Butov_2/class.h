class Table {
private:
	char* name;
	char group;
	char* place;
	unsigned int count;
public:
	Table();
	~Table();
	char* get_name();
	char get_group();
	char* get_place();
	int get_count();
	void set_name(char* source);
	void set_group();
	void set_place(char* source);
	void set_count();
	void show();
};