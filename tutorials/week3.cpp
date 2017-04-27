
//TASK 1
struct record{
	char name[50];
	int age;
	double payRate;	
};

bool updateRecord(fstream &fp, const record &r)
{
	if (!fp.good()) return false;

	fp.seekg(0, ios::beg);
	bool found=false;
	record tmp;
	while (!fp.eof() && !found) {
		fp.read((char *)(&tmp), sizeof(record));
		if (strcmp(tmp.name, r.name)==0)
			found=true;
	}

	tmp = r;
	if(found) {
		p.seekg(-sizeof(record), ios::cur);
		fp.write((char *)(&tmp), sizeof(record));
		return true;
	}
	return false;
}

//HASHING
h1(x)=x mod 23
h2(x)=x mod 11;

