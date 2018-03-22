#define DATA_FILE_NAME "input.txt"

int main() {
	Database db = new Database(DATA_FILE_NAME);
	findFrequentSet(db);
	delete db;
	return 0;
}