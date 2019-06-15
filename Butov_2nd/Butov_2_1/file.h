class Myfile {
private:
	char* name;
	char* txtname;
	char* datname;
	FILE* txt;
	FILE* dat;
public:
	Myfile();
	~Myfile();
	void set_name(char *filename);
	int open_txt();
	int create_dat();
	void copy(char** buf);
	void close();
};