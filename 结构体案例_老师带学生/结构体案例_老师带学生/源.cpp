#include<iostream>
using namespace std;
#include<string>
#include<ctime>

struct Student {
	string sName;
	int score;
};

struct Teacher {
	string tName;

	struct Student sArray[5];

};

void allocatespace(struct Teacher tArray[], int len) {
	string nameSeed = "ABCDE";

	for (int i = 0; i < len; i++) {
		tArray[i].tName = "Teacher_";
		tArray[i].tName += nameSeed[i];

		for (int j = 0; j < 5; j++) {
			tArray[i].sArray[j].sName = "Student_";
			tArray[i].sArray[j].sName += nameSeed[j];

			int random = rand() % 61 + 40;
			tArray[i].sArray[j].score = random;
		}

	}
}
void printInfo(struct Teacher tArray[], int len){

	for (int i = 0; i < len; i++) {

			cout << "老师的姓名： " << tArray[i].tName << endl;

			for (int j = 0; j <5 ; j++) {

				cout << "\t学生的姓名： " << tArray[i].sArray[j].sName <<
					" 考试分数： " << tArray[i].sArray[j].score << endl;
			}
		}

	}



int main() {

	srand((unsigned int)time(NULL));

	struct Teacher tArray[3];

	int len = sizeof(tArray) / sizeof(tArray[0]);

	allocatespace(tArray, len);

	printInfo(tArray, len);



	system("pause");
	return 0;
}