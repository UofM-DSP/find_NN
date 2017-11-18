#include"result_analysis_lsh.h"
#include<iostream>
#include<algorithm>
#define num_of_user 5000
#define top_k 20
//#define bucket_size 3014
using namespace std;

void result_analysis_lsh_genome(){
   
	
     ofstream outfile("C:\\Wasif\\find_NN\\result_genome\\accuracy\\lsh_genome_3500_10k_top20_fp_hamming.txt",std::ofstream::out | std::ofstream::app);
	 for(int q=1;q<=50;q++)
	 {
		  string file_name1,file_name2;
		  file_name1="C:\\Wasif\\find_NN\\Lsh_bucket_genome\\3500_10k\\bucket_u";
		 file_name2="C:\\Wasif\\find_NN\\top_5_nn_genome\\nns_10k_hamming\\result_nn";
			char ch1,ch2,ch3;
		 if(q<10)
		 {
			 ch1=q+'0';

		 file_name1+=ch1;
		 file_name1=file_name1+".txt";
		  file_name2+=ch1;
		 file_name2=file_name2+".txt";
      }
      else if (q>=10&&q<100)
      {

        ch1=(q/10)+'0';

      file_name1+=ch1;
	  file_name2+=ch1;
      ch2=(q%10)+'0';
      file_name1+=ch2;
	   file_name2+=ch2;
      file_name1=file_name1+".txt";
	  file_name2=file_name2+".txt";

      }
		  ifstream infile( file_name1);
	   ifstream infile1( file_name1);
	  ifstream infile2( file_name2);

	//  ifstream infile1("C:\\Wasif\\find_NN\\lsh_bucket\\bucket_u1.txt");
	//  ifstream infile2("C:\\Wasif\\find_NN\\NN\\top_50_jaccard\\result_nn2.txt");
	  int index=0,temp;
	  while(infile>>temp)
    {   
		 
		 index++;
		 //cout<<user1[i]<<endl;
    }
	 int bucket_size=index-1;
	 cout<<"bucket size is"<<bucket_size<<endl;
	int i,j,k,u1,u2,t_count,f_count,*ptr;
	int* user1=new int[bucket_size];
	int* user2=new int[top_k+5];
	double f;
	

       t_count=0;//match
       f_count=0;//unmatch

  for(i=0;i<bucket_size;i++)
    {   
		 infile1>>user1[i];
		// cout<<user1[i]<<endl;
    }
  sort(user1,user1+bucket_size);
  for(i=0;i<bucket_size;i++)
  {
	//  cout<<user1[i]<<endl;
  }
//  fclose( infile1);

          infile2>>u2;
		//  cout<<"u2"<<u2<<endl;

	    for(j=0;j<top_k;j++)
		 {
           infile2>>user2[j]>>f;
        //   cout<<"u2: "<<user2[j]<<endl;
         }
		
        int u_t_count=0;
		
        for(k=0;k<top_k;k++)
        {
         
          ptr=find(user1,user1+bucket_size,user2[k]);
           if((ptr-user1)<bucket_size)
           {
            t_count++;
            u_t_count++;
			cout<<"matched:"<<user2[k]<<endl;

		   }
           else f_count++;

        }
        cout<<"user: "<<i<<"match: "<<u_t_count<<endl;

    int total=t_count+f_count;
    double accuracy= t_count/(double)total;
	double fp;
	fp=f_count/(10000-(double)total);

    cout<<"Accuracy :"<<accuracy<<endl;
	outfile<<accuracy<<endl;
	//outfile<<fp<<endl;
  }
}


