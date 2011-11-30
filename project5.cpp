#include<iostream>
#include<string>
#include<stdlib.h> //string to float (atof)
#include<sstream> //float to string (ostringstreamObject.str())
#include<iomanip> //formatting (setw, right, left, etc)
#include<fstream> //outputting to file
#include<cctype> //verifying string
#include<vector>

using namespace std;

//helper functions
void importStudents();
void exportStudents();
bool verify(string);
bool verify(double);
void getInfo(int,int,int);
string getLetter(float);
double getNumeric(double,double,double);


//global info
static ifstream ifs;
static ofstream ofs;
vector<struct Student> studentVector;

//struct representing a student
typedef struct Student {

	string college;
	string department;
	string professor;
	string studentName;
	string social;
	double firstExam;
	double secondExam;
	double finalExam;
	double finalGradeNumeric;
	string finalGradeLetter;

};

int main()
{

ifs.open("input.txt");
ofs.open("output.txt");

importStudents();
exportStudents();

return 0;

}

void importStudents()
{

	while(ifs.good())
	{
		//set vars

		string college;
		string department;
		string professor;
		string studentName;
		string social;
		string firstExamAlpha;
		double firstExam;
		string secondExamAlpha;
		double secondExam;
		string finalExamAlpha;
		double finalExam;

		//grab data as strings

		getline(ifs,college,',');
		getline(ifs,department,',');
		getline(ifs,professor,',');
		getline(ifs,studentName,',');
		getline(ifs,social,',');
		getline(ifs,firstExamAlpha,',');
		getline(ifs,secondExamAlpha,',');
		getline(ifs,finalExamAlpha,'\n');

		//convert test grades to doubles

		firstExam = atof(firstExamAlpha.c_str());
		secondExam = atof(secondExamAlpha.c_str());
		finalExam = atof(finalExamAlpha.c_str());

		//detect corruption in input file and exit if it's there

		if(!verify(social))
			exit(1);
		if(!verify(firstExam))
			exit(1);
		if(!verify(secondExam))
			exit(1);
		if(!verify(finalExam))
			exit(1);

		//crunch final numeric and letter grades

		double finalNumeric = getNumeric(firstExam,secondExam,finalExam);
		string finalLetter = getLetter(finalNumeric);

		//store all in struct and insert into vector

		Student temp;

		temp.college = college;
		temp.department = department;
		temp.professor = professor;
		temp.studentName = studentName;
		temp.social = social;
		temp.firstExam = firstExam;
		temp.secondExam = secondExam;
		temp.finalExam = finalExam;
		temp.finalGradeNumeric = finalNumeric;
		temp.finalGradeLetter = finalLetter;

		studentVector.push_back(temp);

		//if we're at the end of the file, this function throws the EOF flag and ifs.good() will then return false, ending the loop

		ifs.peek();

	}

}

void exportStudents()
{

	    //output to file

for(int i = 0; i < studentVector.size() ; i++)
{
ofs << setw(25) << fixed << showpoint << setprecision(2) << right << "College: " << left <<  studentVector[i].college << endl;
ofs << setw(25) << fixed << showpoint << setprecision(2) << right << "Department: " << left <<  studentVector[i].department << endl;
ofs << setw(25) << fixed << showpoint << setprecision(2) << right << "Professor: " << left << studentVector[i].professor << endl;
ofs << setw(25) << fixed << showpoint << setprecision(2) << right << "Student: " << left <<  studentVector[i].studentName << endl;
ofs << setw(25) << fixed << showpoint << setprecision(2) << right << "Social: " << left <<  studentVector[i].social << endl;
ofs << setw(25) << fixed << showpoint << setprecision(2) << right << "First Grade: " << left <<  studentVector[i].firstExam << endl;
ofs << setw(25) << fixed << showpoint << setprecision(2) << right << "Second Grade: " << left <<  studentVector[i].secondExam << endl;
ofs << setw(25) << fixed << showpoint << setprecision(2) << right << "Last Grade: " << left <<  studentVector[i].finalExam << endl;
ofs << setw(25) << fixed << showpoint << setprecision(2) << right << "Final Numeric: " << left <<  studentVector[i].finalGradeNumeric << endl;
ofs << setw(25) << fixed << showpoint << setprecision(2) << right << "Final Letter: " << left <<  studentVector[i].finalGradeLetter << endl;
ofs << setw(25) << fixed << showpoint << setprecision(2) << "==================================================" << endl;
}

}


bool verify(string social)
{
	int length = social.length();

	//make sure we have a string with the proper length like 123-12-1234
	if(length != 11)
		return false;

	for(int i=0 ; i < length ; i++)
	{
		if( isdigit( social.c_str()[i] ) )
		{
			continue;
		}
		else if(social.c_str()[i] == '-' && ( i == 3 || i == 6) )
		{
			continue;
		}
		return false;

	}
	return true;
}


bool verify(double grade)
{
	if(grade > 100 || grade < 0)
		return false;
	return true;
}

//no need for getInfo; pulling from input file now.

//report back letter grade
string getLetter(float finalNumericGrade)
{

	if(finalNumericGrade < 60 && finalNumericGrade >= 0)
	{
		return "F";
	}
	else if(finalNumericGrade < 70)
	{
		return "D";
	}
	else if(finalNumericGrade < 80)
	{
		return "C";
	}
	else if(finalNumericGrade < 90)
	{
		return "B";
	}
	else if(finalNumericGrade <= 100)
	{
		return "A";
	}
	else if(finalNumericGrade > 100 || finalNumericGrade < 0)
	{
		cout << "Nice try. Run the program again.";
                return "E";
	}

}

double getNumeric(double test1, double test2, double final)
{

	return (test1*.25 + test2*.25 + final*.5);

}
