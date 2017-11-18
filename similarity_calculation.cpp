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
#include <map>
#include"result_analysis.h"

#define ROWS 100
#define LIMIT 5
//#define feature_set_size 17
//#define query_n 3

using namespace std;
//void jaccardDistance(char** input,  int query, int limit,int rows)
void jaccardDistance()
{
	//int limit=Limit;
	ifstream infile; 
	
		infile.open("C:\\Wasif\\projecta\\dataset\\Minhash_2000_signature_8.txt"); 
	//infile.open("C:\\Wasif\\projecta\\dataset\\user_profile_f_17_50000.txt"); 
//	infile.open("C:\\Wasif\\projecta\\dataset\\Minhash_2k_signature.txt");
	//ofstream outfile("C:\\Wasif\\projecta\\result\\user_profile_1000_nn.txt",std::ofstream::out | std::ofstream::app); 
	ofstream outfile("C:\\Wasif\\projecta\\result\\user_profile_2k_nn_new.txt"); 
	//ofstream outfile("C:\\Wasif\\projecta\\result\\user_profile_1000_nn.txt");
	string line;
//	string feature[ROWS+1];
	int i=0;
	//int user_profile[ROWS+1][17];
	//int** feat;
	vector<string> user;
		if (infile.is_open()) {
			while (std::getline(infile, line))
			{
				user.push_back(line);
			  //  feature[i]=line;
			//	user_profile[i]=line.c_str();
			 
			//  cout<< feature[i]<<endl;
				
				i++;
				if(i>ROWS)break;	

			}
			//	infile.close();
		}
		else
		{
			cout<<"not opened"<<endl;
		}
		for(int i=0;i<user.size();i++)
		{
		//	cout<<"vector"<<i<< " "<<user[i].at(16)<<endl;
		}

		
//}

		string query_features;
		
//	int* output;
	
	for(int q=0;q<user.size();q++)
	{

		 query_features=user[q];

		//int* query_features = features[query];
//		cout<<"query is"<< query_features<<endl;
		
		std::multimap<float,int> items;
		//distance portion
		for (int i = 0; i <user.size(); i++)
		{
			if(i==q)continue;
			int match=0;
			int missmatch=0;


		//int* tmp = ;
			int len= query_features.length();
		//	int len= 1000;
		//	cout<<"lengh is"<<len<<endl;
			
		 for (int j= 0; j < len; j++)
			{   
				//int f1,f2;
				//f1=query_features.at(m)-'0';
		     //	f2=feature[i].at(m)-'0';
			//	cout<<

				if(query_features.at(j)== '0' && user[i].at(j)=='0')
					{
					continue;
					}
				
				if(query_features.at(j)== user[i].at(j))
					match++;
				else
					{
					//if(features[i][j]==1) 
						missmatch++;
					
				    }
			}
		float dist,sim;
		int n= match+missmatch;

		sim=(float)match/(float)n;
		dist=1-sim;
	//	if( dist<= 0.5)
		//{
		//printf("distance %f\n",dist);
		//}
		
		items.insert(std::pair<float,int>(dist,i));
	
		// feature="";
	}
	



		int tmp=0,i=0,j=0;
		int* results = new int[LIMIT];
	for (std::multimap<float,int>::iterator it=items.begin(); it!=items.end(); ++it){
		//printf("%d:%d\n",(*it).first,(*it).second);
		results[j++]=(*it).second;
		if(tmp!=(*it).first)
			i++;
		if(i>=LIMIT)
			break;
	}
	//cout<<"result"<<endl;
	outfile<<q<<endl;
	for(int j=0;j<LIMIT;j++)
	{
	//	cout<<results[j]<<endl;
		outfile<<results[j]<<endl;
	}
		outfile<<endl;
		items.clear();
	}

		/*
		
		for(int l=0;l<ROWS;l++)
		{
			for(int k=0;k<feature_set_size;k++)
			{
				int fe=feature[l].at(k)-'0';
				//cout<<fe<<endl;
				user_profile[l][k]=fe;
				cout<<l<<" "<<user_profile[l][k]<<endl;
			}
			//cout<<l<<" "<<user_profile[l]<<endl;
		}*/

		//string query_features;
		
//	int* output;
	/*
	for(int q=0;q<ROWS;q++)
	{

		 query_features=feature[q];

		//int* query_features = features[query];
//		cout<<"query is"<< query_features<<endl;
		
		std::multimap<float,int> items;
		//distance portion
		for (int i = 0; i < ROWS; i++)
		{
			if(i==q)continue;
			int match=0;
			int missmatch=0;


		//int* tmp = ;
			int len= query_features.length();
		//	cout<<"lengh is"<<len<<endl;
			
		 for (int j= 0; j < len; j++)
			{   
				int f1,f2;
				//f1=query_features.at(m)-'0';
		     //	f2=feature[i].at(m)-'0';
			//	cout<<

				if(query_features.at(j)== '0' && feature[i].at(j)=='0')
					{
					continue;
					}
				
				if(query_features.at(j)== feature[i].at(j))
					match++;
				else
					{
					//if(features[i][j]==1) 
						missmatch++;
					
				    }
			}
		float dist,sim;
		int n= match+missmatch;

		sim=(float)match/(float)n;
		dist=1-sim;
	//	if( dist<= 0.5)
		//{
		//printf("distance %f\n",dist);
		//}
		
		items.insert(std::pair<float,int>(dist,i));
	
		// feature="";
	}
	



		int tmp=0,i=0,j=0;
		int* results = new int[LIMIT];
	for (std::multimap<float,int>::iterator it=items.begin(); it!=items.end(); ++it){
		//printf("%d:%d\n",(*it).first,(*it).second);
		results[j++]=(*it).second;
		if(tmp!=(*it).first)
			i++;
		if(i>=LIMIT)
			break;
	}
	//cout<<"result"<<endl;
	outfile<<q<<endl;
	for(int j=0;j<LIMIT;j++)
	{
	//	cout<<results[j]<<endl;
		outfile<<results[j]<<endl;
	}
		outfile<<endl;
		items.clear();
	}*/
	//free(result);
	
}