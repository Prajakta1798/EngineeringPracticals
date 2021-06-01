#include <iostream>
using namespace std;
const int MAX =31;
class Weather
{
public: //access specifier
int hightemp,lowtemp,rainamt,snowamt; //variable declaration
float avghitemp;
float avglowtemp;
float avgrainamt;
float avgsnowamt;
Weather() //default constructor
{
hightemp=0;
lowtemp=0;
rainamt=0;
snowamt=0;
avghitemp=0;
avglowtemp=0;
avgrainamt=0;
avgsnowamt=0;
}
void getinfo()
{
cin>>hightemp>>lowtemp>>rainamt>>snowamt; //default values overwritten
}
}; //Class definition complete
int main()
{
Weather wt[MAX]; //Declaring array of objects
static int a,b,c,d,count; //static variable values are common for all objects
int n=0;
char ans;
do
{
cout << "Enter high temp, low temp, amout of rain and amount of snow values of day::" << n;
wt[n].getinfo();
count++;n++; // count will store number of days
cout << "Do you want to enter values for another day (y/n)?: " ;
cin >> ans;
} while (ans != 'n' );
for(int i=0;i<count;i++)
{
a=a+wt[i].hightemp; // summation of variable values
b=b+wt[i].lowtemp;
c=c+wt[i].rainamt;
d=d+wt[i].snowamt;
}
a=a/count; //calculate average
b=b/count;
c=c/count;
d=d/count;
cout<<"Average High Temperature value \t"<<a<<"\t degree celcius"<<endl;
cout<<"Average low Temperature value \t"<<b<<"\t degree celcius"<<endl;
cout<<"Average amount of rain value \t"<<c<<"\t mm"<<endl;
cout<<"Average amount of snow value \t"<<d<<"\t mm"<<endl;
return 0;
}

