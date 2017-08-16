/*******************************************************/
/* UVa 12207 That is Your Queue                        */
/* Author: Kevin Chen                                  */
/* Version: 2017/08/16                                 */
/*******************************************************/

//key word : double ended queue

#include <iostream>
#include <cstdio>
#include <deque>
#include <vector>

using namespace std;

void output(const vector<int>& v , const int& casenum){
	printf("Case %d:\n",casenum);
	for(int i = 0;i < v.size(); i++)
	{
		printf("%d\n",v[i]);
	}
}

int main(){
	int casenum = 1;
	while(1){
		int P = 0 , C = 0;
		scanf("%d %d",&P,&C);
		if(P==0 && C==0) break;
		
		deque<int> order;
		vector<int> ans;

		//initialize
		for(int i = 1;i <= P && i <= 1000;i++)
		{
			order.push_back(i);
		}
		
		for(int line = 0;line < C;line++)
		{
			char command = ' ';
			scanf(" %c",&command);

			if(command == 'E'){
				int emergency = 0;
				scanf("%d",&emergency);
				for(int j = 0;j < order.size();j++)
				{
					if(order[j] == emergency)
					{
						order.erase(order.begin()+j);
						break;
					} 
				}
				order.push_front(emergency);
				if(order.size() > 1000) order.pop_back();
			}else if(command == 'N'){
				ans.push_back(order.front());
				order.push_back(order.front());
				order.pop_front();
			}
		}
		output(ans,casenum);
		casenum ++ ;
	}
}
