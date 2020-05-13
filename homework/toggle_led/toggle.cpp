#include<iostream>
#include<fstream>
#include<string>
using namespace std;

#define LED3_PATH "/sys/class/gpio/gpio20"
void writeLED(string filename,string value)
{

   fstream fs;
   string path(LED3_PATH);
   fs.open((path + filename).c_str(), fstream::out);
   fs << value;
   fs.close();  
}
int main()
{
   for(int i=0;i<100000;i++)
       {
    writeLED("/value", "1");
    writeLED("/value","0");   
 };
      return 0;

}
