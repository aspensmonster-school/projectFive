#include<iostream>
#include<string>
#include<stdlib.h> //string to float (atof)
#include<sstream> //float to string (ostringstreamObject.str())
#include<iomanip> //formatting (setw, right, left, etc)
#include<fstream> //outputting to file
#include<cctype> //verifying string

using namespace std;

//helper functions
void importStudents(string[2][2][2][2][6]);
void exportStudents(string[2][2][2][2][6]);
bool verify(string);
bool verify(double);
void getInfo(int,int,int);
string getLetter(float);
double getNumeric(double,double,double);


//global info
static string college,department,professor;
static ofstream ofsImport;
static ofstream ofsExport;
string array[2][2][2][2][6];

int main()
{

ofsImport.open("input.txt");
ofsExport.open("output.txt");

importStudents(array);
exportStudents(array);

return 0;

}

void importStudents(string array[][2][2][2][6])
{

	//get student info
	for( int a = 0 ; a < 1 ; a++)
	{

	  for( int b = 0 ; b < 1 ; b++)
	  {

	    for( int c = 0 ; c < 1 ; c++)
	    {

	    //grab appropriate headings
	    getInfo(a,b,c);

	    for( int d = 0 ; d < 1 ; d++)

	    {

	    //set info from getInfo into array
	    array[a][b][c][d][0] = college;
	    array[a][b][c][d][1] = department;
	    array[a][b][c][d][2] = professor;

	    //display the branch we're collecting student data for
	    cout << "College: " << college << "\n"
	         << "Department: " << department << "\n"
	         << "Professor: " << professor << "\n";

	    //get name
	    string tempName;
	    cout << "Student name?" << endl;
	    getline(cin,tempName);
	    array[a][b][c][d][3] = tempName;
	    ofsImport << tempName << endl;

	    //
	    string tempSocial = "0";
	    while( !verify(tempSocial) )
	    {
	    cout << "Student Social social?" << endl;
	    cin >> tempSocial;
	    }
	    ofsImport << tempSocial << endl;

	    array[a][b][c][d][4] = tempSocial;

	    //first grade
	    double tempFirst = -1;
	    while( !verify(tempFirst) )
	    {
	    cout << "First test grade." << endl;
	    cin >> tempFirst;
	    }
	    ofsImport << tempFirst << endl;

	    //second grade
	    double tempSecond = -1;
	    while( !verify(tempSecond) )
	    {
	    cout << "Second test grade." << endl;
	    cin >> tempSecond;
	    }
	    ofsImport << tempSecond << endl;

	    //final grade
	    double tempFinal = -1;
	    while( !verify(tempFinal) )
	    {
	    cout << "Final test grade." << endl;
	    cin >> tempFinal;
	    }
	    ofsImport << tempFinal << endl;

	    //crunch final numeric
	    float numeric = getNumeric(tempFirst, tempSecond, tempFinal);

	    //get letter grade
	    array[a][b][c][d][5]=getLetter(numeric);

	    /*

	    //Spec update: No longer need to store numeric final grade. Only storing letter grade.

	    //turn numeric into string to store into array
	    ostringstream temp;
	    temp << numeric;
	    array[a][b][c][d][5]=temp.str();

	    */


	    } //end d

	    } //end c

	  } //end b

	}//end a

}

void exportStudents(string array[][2][2][2][6])
{

	//output info with appropriate labelling.
	for( int a = 0 ; a < 1 ; a++)
	{

	  for( int b = 0 ; b < 1 ; b++)
	  {

	    for( int c = 0 ; c < 1 ; c++)
	    {

	    //grab appropriate headings
	    getInfo(a,b,c);

	    for( int d = 0; d < 1 ; d++)

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

	    //ofsExport << setw(25) << fixed << showpoint << setprecision(2) << right << "College: " << left << college << endl;
	    //ofsExport << setw(25) << fixed << showpoint << setprecision(2) << right << "Department: " << left << department << endl;
	    //ofsExport << setw(25) << fixed << showpoint << setprecision(2) << right << "Professor: " << left << professor << endl;
	    ofsExport << setw(25) << fixed << showpoint << setprecision(2) << right << "College: " << left << array[a][b][c][d][0] << "\n";
	    ofsExport << setw(25) << fixed << showpoint << setprecision(2) << right << "Department: " << left << array[a][b][c][d][1] << endl;
	    ofsExport << setw(25) << fixed << showpoint << setprecision(2) << right << "Professor: " << left <<  array[a][b][c][d][2] << endl;
	    ofsExport << setw(25) << fixed << showpoint << setprecision(2) << right << "Student Name: " << left <<  array[a][b][c][d][3] << endl;
	    ofsExport << setw(25) << fixed << showpoint << setprecision(2) << right << "Student Social: " << left <<  array[a][b][c][d][4] << endl;
	    ofsExport << setw(25) << fixed << showpoint << setprecision(2) << right << "Grade: " << left <<  array[a][b][c][d][5] << endl;
	    ofsExport << setw(25) << fixed << showpoint << setprecision(2) << "==================================================" << endl;

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

//depending on which branch of our tree structure (expressed via a multidimensional array...?) we're working with, set the data appropriately
void getInfo(int a,int b,int c)
{

    if( a == 0 )
    {
      college = "Science and Engineering";

      if( b == 0 )
      {
        department = "Computer Science";

        if( c == 0 )
        	professor = "Dr Moonis Ali";
        else if( c == 1 )
        	professor = "Dr Some Guy";
      }
      else if( b == 1 )
      {
	department = "Mechanical Engineering";

        if( c == 0 )
                professor = "Dr Mech E Man";
        else if( c == 1 )
                professor = "Dr Statics Lover";

      }

    } //end a=0
    else if( a == 1 )
    {
    college = "Mathematics";

      if( b == 0 )
      {
       department = "Combinatorics";

        if( c == 0 )
                professor = "Dr Loves Combinatorics";
        else if( c == 1 )
                professor = "Dr Loves Comibnatoircs MORE";
      }
      else if( b == 1 )
      {
       department = "Graph Theory";

        if( c == 0 )
                professor = "Dr Cartesian Man";
        else if( c == 1 )
                professor = "Dr Polar Man";

      }
    

    } //end a=1

}

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
