// Name: Devarsh Patel 
//Class (CECS 282-04)
//Project Name (Prog 3 – Structs and Pointers)
// Due Date: (10/07/2020)
// 
//   I certify that this program is my own original work. I did not copy any part of this program from           
//   any other source. I further certify that I typed each and every line of code in this program
#include<iostream>
#include<cstring>
#include<string>
#include <time.h>
using  namespace std;

class myDate
{
private:
	int day;
	int month;
	int year;

public:

	myDate();
	myDate(int M, int D, int Y);
	void display();
	void increaseDate(int N);
	void decreaseDate(int N);
	int daysBetween(myDate D);
	void setMonth(int M);
    void setDay(int D);
    void setYear(int Y);
	int getMonth();
	int getDay();
	int getYear();
	int dayOfYear();
    string toString();
	int Greg2Julian(int year, int month, int day);

    void Julian2Greg(int JD, int &year,int &month,int &day);

};

struct Student
{
	char name[10];
	int studentID;
	char grade;
	myDate birthday;
	string homeTown;
};


myDate::myDate()
{
	day = 1;
	month = 1;
	year = 2000;
}

myDate::myDate(int M, int D, int Y)

{
    int JD;
    JD = Greg2Julian(year,month,day);

    Julian2Greg(JD,year,month,day);
    
	if (M < 1 || M > 12 || D < 1 || D > 31)
	{
		day = 1;
		month = 1;
		year = 2001;
	}
	else
	{
		day = D;
		month = M;
		year = Y;
	}
}

void myDate::increaseDate(int N)
{

	int date;
	date = Greg2Julian(getYear(), getMonth(), getDay());
	date = date + N;
	Julian2Greg(date, year, month, day);

}

void myDate::decreaseDate(int N)
{
	int date;
	date = Greg2Julian(getYear(), getMonth(), getDay());
	date = date - N;
	Julian2Greg(date, year, month, day);

}

int myDate::daysBetween(myDate D)
{
	int myDay;
	int julian;

	myDay = Greg2Julian(D.getYear(), D.getMonth(), D.getDay());
	julian = Greg2Julian(year, month, day);

	return myDay - julian;
}
void myDate::setMonth(int M)
{
    month = M;
}

void myDate::setDay(int D)
{
    day = D;
}

void myDate::setYear(int Y)
{
    year = Y;
}

int myDate::getMonth()
{

	return month;

}

int myDate::getDay()
{

	return day;
}

int myDate::getYear()
{
	return year;
}

int myDate::dayOfYear()
{
	myDate x(1, 1, year);
	return (daysBetween(x) - 1) * -1;

}

int myDate::Greg2Julian(int year, int month, int day)
{
	int julian, a, y, m;

	a = (14 - month) / 12;
	y = (year + 4800) - a;
	m = month + (12 * a) - 3;

	julian = day + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045;

	return julian;

}
void myDate::Julian2Greg(int JD, int& year, int& month, int& day)
{
	int J, I, K, L, N;
	L = JD + 68569;
	N = 4 * L / 146097;
	L = L - (146097 * N + 3) / 4;
	I = 4000 * (L + 1) / 1461001;
	L = L - 1461 * I / 4 + 31;
	J = 80 * L / 2447;
	K = L - 2447 * J / 80;
	L = J / 11;
	J = J + 2 - 12 * L;
	I = 100 * (N - 49) + I + L;
	year = I;
	month = J;
	day = K;
}

string myDate::toString()
{
	int mon = 0;
	string monthName[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	string someString = monthName[month-1] + ", " + to_string(day) + ", " + to_string(year);
    return someString;
}

void display(Student* s[])
{
	cout << "Name\t" << "StudentID\t" << "Grade\t" << "Birthday\t" << "Home Town" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << s[i]->name << "\t" << s[i]->studentID << "\t" << s[i]->grade << "\t" << s[i]->birthday.toString() << "\t" << s[i]->homeTown << endl;
	}

}
/*void swap(Student **X, Student **Y)
{
    Student *temp;
    temp = *X;
    *X = *Y;
    *Y = temp;
}
*/
void populate(Student* s[])
{
	int R;
	for (int i = 0; i < 10; i++)
	{
		s[i] = new Student;
	}
	strcpy(s[0]->name, "Devarsh");
	s[0]->homeTown = "Anaheim";

	strcpy(s[1]->name, "Vrutik");
	s[1]->homeTown = "Cypress";

	strcpy(s[2]->name, "Smit");
	s[2]->homeTown = "Long beach";

	strcpy(s[3]->name, "George");
	s[3]->homeTown = "Anaheim Hills";

	strcpy(s[4]->name, "Steven");
	s[4]->homeTown = "Pioneer";

	strcpy(s[5]->name, "Grey");
	s[5]->homeTown = "Cerritos";

	strcpy(s[6]->name, "Alex");
	s[6]->homeTown = "Newport Beach";

	strcpy(s[7]->name, "Dhwani");
	s[7]->homeTown = "Buena Park";

	strcpy(s[8]->name, "Rishika");
	s[8]->homeTown = "Huntington beach";

	strcpy(s[9]->name, "Rifat");
	s[9]->homeTown = "Graden Grove";

	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		char letter[] = { 'A','B','C','D', 'F' };
		R = letter[rand() % 5];
		s[i]->grade = R;
	}

	for (int i = 0; i < 10; i++)
	{
		R = 267099030 + rand() % 268099030;
		s[i]->studentID = R;
	}
     
    
	for (int i = 0; i < 10; i++)
	{
		int rYear = (rand()%(2006 - 2000))+2000;
		int rMonth = (rand()%12)+1;
		int rDays = (rand()%30)+1;
		s[i]->birthday.Greg2Julian(rYear,rMonth,rDays);
		s[i]->birthday.setMonth(rMonth);
        s[i]->birthday.setDay(rDays);
        s[i]->birthday.setYear(rYear);

	}
}
void sortByName(Student *Nameptr[])
{
    //Bubble sort and print
    for (int i=0; i<10-1; i++)
    {
        for (int j=0; j < 10-i-1; j++)
        {
            if (strcmp(Nameptr[j]->name, Nameptr[j+1]->name) > 0)
            {
                swap(Nameptr[j], Nameptr[j+1]);
            }
        }
    }
    display(Nameptr);
}

void sortByStudentID(Student *StudID[])
{
    //Bubble sort and print
    for (int i=0; i<10-1; i++)
    {
        for (int j=0; j < 10-i-1; j++)
        {
            if (StudID[j]->studentID> StudID[j+1]->studentID)
            {
                swap(StudID[j], StudID[j+1]);
            }
        }
    }
    display(StudID);
}
void sortByGrade(Student *Gptr[])
{
    //Bubble sort and print
    for (int i=0; i<10-1; i++)
    {
        for (int j=0; j < 10-i-1; j++)
        {
            if (Gptr[j]->grade> Gptr[j+1]->grade)
            {
                swap(Gptr[j], Gptr[j+1]);
            }
        }
    }
    display(Gptr);
}

void sortByHomeTown(Student *HTptr[])
{
    //Bubble sort and print
    for (int i=0; i<10-1; i++)
    {
        for (int j=0; j < 10-i-1; j++)
        {
            if (HTptr[j]->homeTown> HTptr[j+1]->homeTown)
            {
                swap(HTptr[j], HTptr[j+1]);
            }
        }
    }
    display(HTptr);
}

void sortByBirthday(Student *Bptr[])
{
    //Bubble sort and print
   
    for (int i=0; i<10-1; i++)
    {
        for (int j=0; j < 10-i-1; j++)
        {
            int M, D, Y, month, day, year;
            M = Bptr[j]->birthday.getMonth();
            D = Bptr[j]->birthday.getDay();
            Y = Bptr[j]->birthday.getYear();
            month = Bptr[j+1]->birthday.getMonth();
            day = Bptr[j+1]->birthday.getDay();
            year = Bptr[j+1]->birthday.getYear();
            
            if (Bptr[j]->birthday.Greg2Julian(Y,M,D) > Bptr[j+1]->birthday.Greg2Julian(year, month, day))
            {
                swap(Bptr[j], Bptr[j+1]);
            }
        }
    }
    display(Bptr);
}

int main()
{
	Student* stuPrt[10];
	populate(stuPrt);
	
	int x;
	cout << "1) Display list sorted by Name:" << endl;
	cout << "2) Display list sorted by StudentId:" << endl;
	cout << "3) Display list sorted by Grade:" << endl;
	cout << "4) Display list sorted by Birthday:" << endl;
	cout << "5) Display list sorted by Home Town:" << endl;
	cout << "6) Exit:" << endl;

	cout << "\nEnter your choice from menu: ";
	cin >> x;
	while (x != 6)
	{
		switch (x)
		{
		case 1:
			sortByName(stuPrt);
			break;
		case 2:
			sortByStudentID(stuPrt);
			break;
		case 3:
			sortByGrade(stuPrt);
			break;
		case 4:
			sortByBirthday(stuPrt);
			break;
		case 5:
			sortByHomeTown(stuPrt);
			break;
		default:
			cout << "You have to choose between 1 to 6.:" << endl;
		}
	
	    	cout << "\nEnter your choice from menu: ";
	    	cin >> x;
	
	}
}

