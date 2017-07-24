/*******************************************************/
/* UVa 455 Periodic Strings                            */
/* Author: Kevin Chen                                  */
/* Version: 2017/07/24                                 */
/*******************************************************/

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

bool isPeriodic(const string& str , int period){
	string periodicStr = str.substr(0,period);
	for(int i = period ; i + period <= str.length() ; i = i + period ){
		if(periodicStr != str.substr(i,period)) return false;
	} 
	return true; 
}

int main(){
	
	int testCase = -1;
	scanf("%d",&testCase);
	string str;
	bool emptyLine = false;
	while(testCase > 0){
		bool print = false;
		cin >> str;
		if(emptyLine) printf("\n");
		else emptyLine = true; 
		
		for(int period = 1; period <= str.length() / 2 ; period ++){
			if(isPeriodic(str,period) && str.length()%period == 0){
				printf("%d\n",period);
				print = true;
				break;
			} 
		}

		if(!print) printf("%d\n",str.length());
		
		testCase--;
	}
	
	return 0; 
	
}