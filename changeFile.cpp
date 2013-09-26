// =====================================================================================
// 
//       Filename:  changeFile.cpp
// 
//    Description:  this is to deal with the files
// 
//        Version:  1.0
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  ZY, 
// 
// =====================================================================================

#include	<iostream>
#include   <fstream>
#include   <cstdlib>

using namespace std;

int main()
{
	ifstream in;
	in.open("oregon.dat");
	if(! in)
	{
		cout<<"can't open file!"<<endl;
		exit(-1);
	}

	char p[300];
	//in.getline(p,300);
	//in.getline(p,300);
	//in.getline(p,300);
	//in.getline(p,300);
	//cout<<p<<endl;
	
	int graph[50000];
	for(int i=0;i<50000;i++)
		graph[i]=-1;
	int index=0;
	
	int node;
	int d=0;
	while(in>>node)
	{
		d++;
		int i;
		for( i=0;i<=index;i++)
			if(graph[i]==node)
				break;
		if(i>index)
		{
			index++;
			graph[i-1]=node;
		}
	}
	cout<<index<<endl;
	d=d/2;
	cout<<d<<endl;
	in.close();

	ofstream out;
	out.open("oregonp1.dat");
	out<<index<<"\t"<<d<<endl;
	for(int i=1;i<=index;i++)
	{
		out<<i<<'\t'<<i<<endl;
	}
	in.open("oregon.dat");
	//in.getline(p,300);
	//in.getline(p,300);
	//in.getline(p,300);
	//in.getline(p,300);
	//cout<<p<<endl;

	int a,b;
	while(in>>a && in>>b)
	{
		int i;
		for( i=0;i<index;i++)
			if(graph[i]==a)
				break;
		out<<i+1<<'\t';

		for(i=0;i<index;i++)
			if(graph[i]==b)
				break;

		out<<i+1<<endl;
	}
	
	in.close();
	out.close();
}
