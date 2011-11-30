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
		getline(ifs,finalExamAlpha,',');

		//convert test grades to double

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

		//store all in struct and insert into vector



	}

}

void exportStudents()
{

	//output info with appropriate labelling.
	for( int a = 0 ; a < 2 ; a++)
	{

	  for( int b = 0 ; b < 2 ; b++)
	  {

	    for( int c = 0 ; c < 2 ; c++)
	    {

	    //grab appropriate headings
	    getInfo(a,b,c);

	    for( int d = 0; d < 2 ; d++)

	    {

	    //output to console

	    //cout << setw(25) << right << "College: " << left << college << endl;
	    //cout << setw(25) << right << "Department: " << left << department << endl;
	    //cout << setw(25) << right << "Professor: " << left << professor << endl;
	    cout << setw(25) << right << "College: " << left << array[a][b][c][d][0] << endl;
	    cout << setw(25) << right << "Department: " << left << array[a][b][c][d][1] << endl;
	    cout << setw(25) << right << "Professor: " << left << array[a][b][c][d][2] << endl;
	    cout << setw(25) << right << "Student Name: " << left << array[a][b][c][d][3] << endl;
	    cout << setw(25) << right << "Student Social: " << left << array[a][b][c][d][4] << endl;
	    cout << setw(25) << right << "Grade: " << left << array[a][b][c][d][5] << endl;
	    cout << setw(25) << "==================================================" << endl;

	    //output to file

	    //ofs << setw(25) << fixed << showpoint << setprecision(2) << right << "College: " << left << college << endl;
	    //ofsExport << setw(25) << fixed << showpoint << setprecision(2) << right << "Department: " << left << department << endl;
	    //ofsExport << setw(25) << fixed << showpoint << setprecision(2) << right << "Professor: " << left << professor << endl;
	    ofsExport << setw(25) << fixed << showpoint << setprecision(2) << right << "College: " << left << array[a][b][c][d][0] << "\n";
	    ofs << setw(25) << fixed << showpoint << setprecision(2) << right << "Department: " << left << array[a][b][c][d][1] << endl;
	    ofs << setw(25) << fixed << showpoint << setprecision(2) << right << "Professor: " << left <<  array[a][b][c][d][2] << endl;
	    ofs << setw(25) << fixed << showpoint << setprecision(2) << right << "Student Name: " << left <<  array[a][b][c][d][3] << endl;
	    ofs << setw(25) << fixed << showpoint << setprecision(2) << right << "Student Social: " << left <<  array[a][b][c][d][4] << endl;
	    ofs << setw(25) << fixed << showpoint << setprecision(2) << right << "Grade: " << left <<  array[a][b][c][d][5] << endl;
	    ofs << setw(25) << fixed << showpoint << setprecision(2) << "==================================================" << endl;

	    }//end d

	    }//end c

	  }//end b

	}//end a

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
