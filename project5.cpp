#include<iostream>
#include<string>
#include<stdlib.h> //string to float (atof)
#include<sstream> //float to string (ostringstreamObject.str())
#include<iomanip> //formatting (setw, right, left, etc)
#include<fstream> //outputting to file

using namespace std;

//random comment

//helper functions
void importStudents(string[2][2][2][2][7]);
void exportStudents(string[2][2][2][2][7]);
void getInfo(int,int,int);
string getLetter(float);
bool verify(string);
bool verify(double);

//global info
static string college,department,professor;
static ofstream ofsImport;
static ofstream ofsExport;
string array [2][2][2][2][7] = { "\0" } ;

int main()
{

ofsImport.open("input.txt");
ofsExport.open("output.txt");

importStudents(array);
exportStudents(array);


return 0;

}

void importStudents(array string[2][2][2][2][7])
{

	//get student info
	for( int a = 0 ; a < 2 ; a++)
	{

	  for( int b = 0 ; b < 2 ; b++)
	  {

	    for( int c = 0 ; c < 2 ; c++)
	    {

	    //grab appropriate headings
	    getInfo(a,b,c);

	    for( int d = 0 ; d < 2 ; d++)

	    {

	    //display the branch we're collecting student data for
	    cout << "College: " << college << "\n"
	         << "Department: " << department << "\n"
	         << "Professor: " << professor << "\n";

	    //grab info for the branch
	    cout << "Student name?" << endl;
	    cin >> array[a][b][c][d][0];
	    cout << "Student Social social?" << endl;
	    cin >> array[a][b][c][d][1];

	    //first grade
	    array[a][b][c][d][2]="200";
	    while(atof(array[a][b][c][d][2].c_str()) > 100 || atof(array[a][b][c][d][2].c_str()) < 0 )
	    {
	    cout << "First test grade." << endl;
	    cin >> array[a][b][c][d][2];
	    }

	    //second grade
	    array[a][b][c][d][3]="200";
	    while(atof(array[a][b][c][d][3].c_str()) > 100 || atof(array[a][b][c][d][3].c_str()) < 0 )
	    {
	    cout << "Second test grade." << endl;
	    cin >> array[a][b][c][d][3];
	    }

	    //final grade
	    array[a][b][c][d][4]="200";
	    while(atof(array[a][b][c][d][4].c_str()) > 100 || atof(array[a][b][c][d][4].c_str()) < 0 )
	    {
	    cout << "Final test grade." << endl;
	    cin >> array[a][b][c][d][4];
	    }

	    //crunch final numeric
	    float numeric = atof(array[a][b][c][d][2].c_str())*.25 + atof(array[a][b][c][d][3].c_str())*.25 + atof(array[a][b][c][d][4].c_str())*.50 ;

	    //turn numeric into string to store into array
	    ostringstream temp;
	    temp << numeric;
	    array[a][b][c][d][5]=temp.str();

	    //get letter grade
	    array[a][b][c][d][6]=getLetter(numeric);

	    } //end d

	    } //end c

	  } //end b

	}//end a

}



void exportStudents(array string[2][2][2][2][7])
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

	    cout << setw(25) << right << "College: " << left << college << endl;
	    cout << setw(25) << right << "Department: " << left << department << endl;
	    cout << setw(25) << right << "Professor: " << left << professor << endl;
	    cout << setw(25) << right << "Student name: " << left << array[a][b][c][d][0] << endl;
	    cout << setw(25) << right << "Student social: " << left << array[a][b][c][d][1] << endl;
	    cout << setw(25) << right << "First test: " << left << array[a][b][c][d][2] << endl;
	    cout << setw(25) << right << "Second test: " << left << array[a][b][c][d][3] << endl;
	    cout << setw(25) << right << "Final exam: " << left << array[a][b][c][d][4] << endl;
	    cout << setw(25) << right << "Final numeric: " << left << array[a][b][c][d][5] << endl;
	    cout << setw(25) << right << "Final alphabetic: " << left << array[a][b][c][d][6] << endl;
	    cout << setw(25) << "==================================================" << endl;

	    //output to file

	    ofsExport << setw(25) << fixed << showpoint << setprecision(2) << right << "College: " << left << college << endl;
	    ofsExport << setw(25) << fixed << showpoint << setprecision(2) << right << "Department: " << left << department << endl;
	    ofsExport << setw(25) << fixed << showpoint << setprecision(2) << right << "Professor: " << left << professor << endl;
	    ofsExport << setw(25) << fixed << showpoint << setprecision(2) << right << "Student Name: " << left << array[a][b][c][d][0] << "\n";
	    ofsExport << setw(25) << fixed << showpoint << setprecision(2) << right << "Social: " << left << array[a][b][c][d][1] << endl;
	    ofsExport << setw(25) << fixed << showpoint << setprecision(2) << right << "First Test: " << left <<  array[a][b][c][d][2] << endl;
	    ofsExport << setw(25) << fixed << showpoint << setprecision(2) << right << "Second Test: " << left <<  array[a][b][c][d][3] << endl;
	    ofsExport << setw(25) << fixed << showpoint << setprecision(2) << right << "Final Exam: " << left <<  array[a][b][c][d][4] << endl;
	    ofsExport << setw(25) << fixed << showpoint << setprecision(2) << right << "Numeric Grade: " << left <<  array[a][b][c][d][5] << endl;
	    ofsExport << setw(25) << fixed << showpoint << setprecision(2) << right << "Letter Grade: " << left << array[a][b][c][d][6] << endl;
	    ofsExport << setw(25) << fixed << showpoint << setprecision(2) << "==================================================" << endl;

	    }//end d

	    }//end c

	  }//end b

	}//end a

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

