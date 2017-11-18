#include "hamming_distance.h"
#include <tchar.h>
#include<cstdio>
#include<iostream>
#include <fstream>
#include<time.h>
#include <string>
#include <string>
#include<cstring>
#include <vector>
#include <bitset>
#include<cmath>
#include <map>
#define ROWS 100
#define LIMIT 50
#define len 7000
//#deine len 500
//#define q 1
//#define feature_set_size 17
//#define query_n 3


using namespace std;
//void jaccardDistance(char** input,  int query, int limit,int rows)
void hamming_distance()
{
    string* user=new string[10005];
	//int limit=Limit;
	ifstream infile;
	infile.open("db_encoded_Col_3500_Row_10000.txt");
	int index=1;
	string s;
	while(infile>>s)
	{
	    user[index]=s;
		cout<<user[index]<<endl;
	    index++;
	    if(index>9999)break;
		
	}

	for(int q=1;q<=50;q++)
	{
        /* string query="";
         std::multimap<float,int> items;

		ofstream outfile_runtime("result\\runtime\\result_plain_euclid_5k.txt",std::ofstream::out | std::ofstream::app);

	query=user[q];

clock_t enc_begin = clock();


	for(int i=1;i<=5000;i++)
	{
			if(i==q)continue;
			int match=0;
			int missmatch=0;


		 for (int j=0;j<7000;j=j+2)
			{


				if(query.at(j)!= user[i].at(j)||query.at(j+1)!= user[i].at(j+1))
					missmatch++;
				else
					{
					//if(features[i][j]==1)
						match++;

          }
			}

		float dist,sim;
		int n= match+missmatch;

		sim=(float)match/(float)n;
		dist=sqrt((double)missmatch);
		//cout<<"point"<<i<<endl;
	//	printf("distance %f\n",dist);

		items.insert(std::pair<float,int>(dist,i));

	}

	clock_t enc_end = clock();
double encrypt_time=(double)(enc_end-enc_begin)/ CLOCKS_PER_SEC;
outfile_runtime<<encrypt_time<<endl;
//outfile<<q<<endl;


		int tmp=0,i=0,j=0;
		int* results = new int[LIMIT];
	for (std::multimap<float,int>::iterator it=items.begin(); it!=items.end(); ++it)
    {
		results[j++]=(*it).second;
		if(tmp!=(*it).first)
			i++;
		if(i>=LIMIT)
			break;
    }

		items.clear();*/

	}

	//return 0;
}

