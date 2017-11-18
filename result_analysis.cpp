#include"result_analysis.h"
#include<iostream>
#include<algorithm>
#define num_of_user 500
#define top_k 5
using namespace std;

void result_analysis(){
   
	 ifstream infile1("C:\\Wasif\\projecta\\result\\user_profile_2k_nn_real.txt");
	 ifstream infile2("C:\\Wasif\\projecta\\result\\user_profile_2k_nn_newe.txt");
     ofstream outfile("C:\\Wasif\\projecta\\result\\accuracy.txt",std::ofstream::out | std::ofstream::app);
	int i,j,k,u1,u2,t_count,f_count,*ptr;
	int* user1=new int[num_of_user];
	int* user2=new int[num_of_user];
	double f;

       t_count=0;//match
       f_count=0;//unmatch

  for(i=1;i<=num_of_user;i++)
    {   
		 infile1>>u1;
         infile2>>u2;

        for(j=0;j<top_k;j++)
        {
           infile1>>user1[j];
		   cout<<"u1: "<<user1[j]<<endl;
           infile2>>user2[j]>>f;
           cout<<"u2: "<<user2[j]<<endl;
        }
		
        int u_t_count=0;
		
        for(k=0;k<top_k;k++)
        {
          //cout<<"user1 "<<user1[k]<<" "<<"user2 "<<user2[k]<<endl;
          ptr=find(user2,user2+top_k,user1[k]);
           if((ptr-user2)<top_k)
           {
			//cout<<"matched"<<endl;
            t_count++;
            u_t_count++;

		   }
           else f_count++;

        }
        cout<<"user: "<<i<<"match: "<<u_t_count<<endl;


    }
     //cout<<t_count<<endl;
    //cout<<f_count<<endl;
    int total=t_count+f_count;
    double accuracy= t_count/(double)total;

    cout<<"Accuracy :"<<accuracy<<endl;
   //outfile<<"Feature set: "<<index<<" accuracy: "<<accuracy<<endl;


  }


