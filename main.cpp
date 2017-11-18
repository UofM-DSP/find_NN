
#include <cstdio>
#include <stdio.h>
#include <vector>
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
#include"similarity_calculation.h"
#include"result_analysis.h"
#include"Lsh_bucket.h"
#include"Lsh_bucket_genome.h"
#include"result_analysis_lsh.h"
#include"result_analysis_lsh_genome.h"
#include"run_time.h"
#include"nn_cosine.h"
#include"NN_jaccard.h"
#include"hamming_distance.h"
#define ROWS 100
#define ATTRS 800
#define LIMIT 5
#define times  50
#define feature_set_size 8
//#define query_n 3

using namespace std;

int main()
{
	
	char** buffer = new char*[ROWS];
	
	ifstream infile; 
	
	infile.open("C:\\Wasif\\projecta\\dataset\\Minhash_2000_signature.txt"); 
	//infile.open("C:\\Wasif\\projecta\\dataset\\user_profile_2000.txt");
  //  infile.open("C:\\Wasif\\projecta\\dataset\\user_profile_f_17_50000.txt"); 

		std::string line;
		
		int i=0;
		if (infile.is_open()) {
			while (std::getline(infile, line))
			{
			   //cout<<"reading: "<<i<<" "<<line<<endl;
				buffer[i] = new char[line.size() + 1];
				const char* tmp = line.c_str();
				strcpy(buffer[i],(char*) tmp);
				
				i++;
				if(i>ROWS)break;	

			}
			//	infile.close();
		}else{
			cout<<"not opened"<<endl;
		}
		
	//	clock_t begin = clock();
		//cout<<i<<":"<<buffer[4] <<endl;
	   
		int query_n;
	//	for(int q=0;q<ROWS;q++)
	//	{
		//	query_n=q;
			//jaccardDistance(buffer,query_n,LIMIT,ROWS);
		//   jaccardDistance();
			// hammingDistance( buffer,incoming,0,LIMIT, ROWS*ATTRS,ROWS);
			//euclidieanDistance(eid, buffer,incoming,0,LIMIT, ROWS*ATTRS,ROWS);
	//		//cosineDistance(eid, buffer,incoming,0,LIMIT, ROWS*ATTRS,ROWS);
	//	}
		//lsh_bucket();
		//lsh_bucket_genome();
	//run_time();
	//	jaccard();
		//result_analysis_lsh_genome();
		hamming_distance();

	//	nn_cosine();
			cout<<"done"<<endl;
		
	//	clock_t end = clock();
		
	//result_analysis();
	std::getchar();
	return 0;
}




