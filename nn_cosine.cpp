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
#include<cmath>
#define ROWS 100
#define LIMIT 50
//#define q 1
//#define feature_set_size 17
//#define query_n 3


using namespace std;


void nn_cosine()
{

	 string user[50005];
	//int limit=Limit;
	ifstream infile;
	infile.open("C:\\Wasif\\find_NN\\user_profile_f_17_50k.txt");
	int index=1;
	string s;
	while(infile>>s)
	{
	    user[index]=s;
	  //  cout<< user[i]<<endl;
	    index++;
	    if(index>20000)break;
	}
	for(int q=18;q<=20;q++)
	{
		/*
	    string file_name;
        file_name="top_50_cosine\\result_nn";
        char ch1,ch2,ch3;
       if(q<10)
      {
        ch1=q+'0';

      file_name+=ch1;
      file_name=file_name+".txt";
      }
      else if (q>=10&&q<100)
      {

        ch1=(q/10)+'0';

      file_name+=ch1;
      ch2=(q%10)+'0';
      file_name+=ch2;
      file_name=file_name+".txt";

      }*/
   //   cout<<file_name<<endl;
     // char *file_n=file_name.c_str();


//	ofstream outfile(file_name.c_str(),std::ofstream::out);

	string query;

	query=user[q];
	 std::multimap<float,int> items;
clock_t begin = clock();
	for(int i=1;i<=20000;i++)
	{

		//distance portion
	//	for (int i = 0; i <user.size(); i++)
		//{
			if(i==q)continue;

			int match=0;
			int missmatch=0;



		//int* tmp = ;
			int len= query.length();
		//	int len= 1000;
		//	cout<<"lengh is"<<len<<endl;
		int mul=0;
		int query_f_sum=0, feature_sum=0;

		 for (int j= 0; j < len; j++)
			{
			    //char val1,val2

				mul+=(query[j]-'0')*(user[i][j]-'0');
                query_f_sum+=(query[j]-'0');
                feature_sum+=(user[i][j]-'0');
			}


		float dist,sim;
		//int n= match+missmatch;

		sim=(float)mul/sqrt((float)query_f_sum*(float)feature_sum);
		dist=1-sim;
	//	if( dist<= 0.5)
		//{
		//cout<<"point"<<i<<endl;
	//	printf("distance %f\n",dist);
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
	clock_t end = clock();
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        cout<<"time spent is: "<<time_spent<<endl;
	//cout<<"result"<<endl;
	//outfile<<q<<endl;
	for(int j=0;j<LIMIT;j++)
	{
	//	cout<<results[j]<<endl;
	//	outfile<<results[j]<<endl;
	}
	//	outfile<<endl;
		items.clear();

	//}

	}
}