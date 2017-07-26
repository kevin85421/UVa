/*******************************************************/
/* UVa 514 Rails                                       */
/* Author: Kevin Chen                                  */
/* Version: 2017/07/26                                 */
/*******************************************************/

//key word : stack

#include <iostream>
#include <stack>
#include <cstdio>
#include <string>
using namespace std;

bool possible(stack<int>& railB ,const int coachesNum){
	stack<int> railA;
	stack<int> station;
	int Awant = coachesNum ;
	
	for(int i = 0; i < 2*coachesNum ;i++){
		if(!station.empty()){
			if(station.top() == Awant){
				railA.push(station.top());
				station.pop();
				Awant--;
				if(Awant == 0) return true;
			}else{
				if(railB.size() != 0){
					station.push(railB.top());
					railB.pop();
				}else{
					return false;
				}
			}
		}else{
			station.push(railB.top());
			railB.pop();	
		}
	}
}


int main(){
	while(1){
		int coachesNum = 0;
		scanf("%d",&coachesNum);
		
		if(coachesNum == 0) break;
		
		while(1){
			stack<int> railB;
			int n = 0; 
			for(int i = 0;i < coachesNum;i++ ){
				scanf("%d",&n);
				railB.push(n);
				if(n==0) break;
			}
			if(railB.top() == 0) break;

			if(possible(railB , coachesNum)) printf("Yes\n");
			else printf("No\n");
		}
		printf("\n");
		
	}
	
	return 0;

}