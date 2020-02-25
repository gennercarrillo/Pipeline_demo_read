
/************************************************************************/
//               Data piping from an external input file		//
//		 trought C++, to the linux console			//
//									//
//		In this particular example a simple console		//
//			commmand is send				//
//									//	
//		Finally the result is outputed to the console		//
//									//
//									//
//		Author: Genner Andres Carrillo       25/02/2020		//
//									//
//		plaintext file >> C++ (pipe) >>  Linux term		//
//									//
// ver:1.0  compiled g++ for linux					//
/************************************************************************/

#include<cstdlib>
#include<cstdio>
#include<array>
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

void pipefunction(string datastr)					//object function to call the pipe
{
	std::array<char,80> buffer;					//create an array structure for the buffer
	FILE *pipe = popen(datastr.c_str(),"r"); 			//fill a file with the data from strcmd
	if(!pipe)							//check if file readable
	{
		std::cerr << "cannot open pipe to read"<< endl;
		return;
	}
	int c=0;
	while(fgets(buffer.data(), 80, pipe) != NULL)			//while the input is different from null
	{
		c++;
		std::cout << c << "" << buffer.data();			//takes the data to the buffer
	}
	pclose(pipe);
}

int main(void)
{ 
	string datastr = "";
	int count=0;
	while(count<1)
	{
		std::cout<<"Input a linux console command:";	
		ifstream input; 					//Declare file streams.
	
	     	input.open("dataIn.txt");				//Open the input file
			if(!input){
			std::cout << "dataIn.txt file not found!" << endl;
			return 0;
			}

		std::getline(input,datastr); 			//Get the info from the file
		pipefunction(datastr);				//Invoke the pipeline function to send info to the linux console
	
	count++;
	}
	return 0;
}

