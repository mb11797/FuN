#include<iostream>
#include<list>
#include<algorithm>
#include<iomanip>
using namespace std;
int b[10]={0};
list<char> listy;
list<char> ::iterator it;
list<char> listy_total[100000];
int index=0;
int number=0;
bool move(string str,int l,int for_index,int i)
{
	if(b[i]==0)
	{
		b[i]=1;
		//cout<<"Single Character"<<str[i];

		listy.push_back(str[i]);
		if((for_index+1)==(l))
		{
			//when meet the child node
			//Show the list
			int match=0;
			for(int i=0;i<=number;i++)
			{
				if(listy==listy_total[i])
				{
					//cout<<"Matched";
					match=1;
				}
			}
			if(match==0)
			{
				number=number+1;
				for(it=listy.begin();it!=listy.end();++it)
				{
					//cout<<*it;
					listy_total[number].push_back(*it);
				}
			}
			index=index+1;
			b[i]=0;
        	listy.pop_back();
			return true;
		}
		for(int j=0;j<l;j++)
		{

			int result=move(str,l,for_index+1,j);
		}
		b[i]=0;
		listy.pop_back();
		return true;
	}
	else
	{
		return true;
	}
}
main()
{
	string str;
	cin>>str;
	int l=str.length();
	int for_index=0;
	for(int i=0;i<l;i++)
	{
		int result=move(str,l,for_index,i);
	}
	list <char> :: iterator it;
	std::sort(listy_total,listy_total+number);
	for(int i=0;i<=number;i++)
	{
		for(it = listy_total[i].begin(); it != listy_total[i].end(); ++it)
    	{
    		cout << *it;
		}
		cout<<"\n";
	}
}
