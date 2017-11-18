#include"Lsh_bucket.h"
#include<iostream>
#include<algorithm>
#define num_of_user 250005
#define top_k 5
int bucket[5000][25000];
 //int n_user=10000;
//vector< vector<int> > bucket_n(10000, vector<int>(10000));


using namespace std;
void lsh_bucket()
{    
	memset( bucket[5000], 0, 5000);
	for(int k=1;k<5;k++)
	{
		//cout<<"value"<<bucket[1][k]<<endl;
	}
	cout<<"hello from lsh"<<endl;
	ifstream infile1("C:\\Wasif\\find_NN\\bucket_f_30_10k_signature_7_stage.txt");
	// ifstream infile2("C:\\Wasif\\projecta\\result\\user_profile_2k_nn_newe.txt");
    // ofstream outfile("C:\\Wasif\\find_NN\\bucket_u4_50k_7.txt",std::ofstream::out | std::ofstream::app);
	long int i,j,k,u1,u2,t_count,f_count,*ptr,p;
	string* user1=new string[num_of_user];
	int* user2=new int[num_of_user];
	
	double f;
	long int n=250000;
   
	
	
  for(i=1;i<=n;i++)
    {   
		 infile1>>user1[i];
		// cout<<user1[i]<<endl;
	}
  int user_id;
  
     
for(int u=1;u<=50;u++)
{
	string file_name;
   file_name="C:\\Wasif\\find_NN\\lsh_bucket_f_30\\bucket_u";
	 char ch1,ch2,ch3;
       if(u<10)
      {
        ch1=u+'0';

      file_name+=ch1;
      file_name=file_name+".txt";
      }
      else if (u>=10&&u<100)
      {

        ch1=(u/10)+'0';

      file_name+=ch1;
      ch2=(u%10)+'0';
      file_name+=ch2;
      file_name=file_name+".txt";

      }
	 ofstream outfile(file_name,std::ofstream::out | std::ofstream::app);
	

  for(int r=0;r<5;r++)
  {   
	  user_id=1;
	  cout<<"stage: "<<r<<endl;
	//for(i=1+r*n_user;i<r*n_user+5;i++)  
	  for(i=u+r*50000;i<r*50000+u+1;i++)
	{  
		 cout<<"target user:"<<" "<<i<<endl;
		p=0;
	 // for(j=1+r*n_user;j<r*n_user+n_user;j++)
		for(j=1+r*50000;j<r*50000+50000;j++)
	  {
		  if(i==j)continue;
		  if(user1[i]==user1[j])
		  {
			//  cout<<"sim: "<<j<<endl;
			//  bucket[i][p]=j;
			//  bucket_n[user_id].push_back(j-r*50000);
			  int similar=j-r*50000;
			   outfile<<similar<<endl;
			  p++;
		  }
		  
	  }
		 user_id++;
		 cout<<"number of buckets: "<<p<<endl;
	}
  }
 // fclose(outfile);
}

  /*

int count;

  for(i=1;i<5;i++)
  {
		 cout<<"for user: "<<i<<endl;
		 count=0;
	  for(int k=bucket_n[i].size()-1;k>=bucket_n[i].size()-1000;k--)
		{
			count++;
		  if(bucket_n[i][k]==0)
		   { 
			   //cout<<"number of bucket less than 2000" <<" "<<j<<endl;
			    break;
		   }
		  cout<<"bucket: of user: "<<i<<" count: "<<count<<" "<<bucket_n[i][k]<<endl;
		  if(i==1)
		  {
			   outfile<<bucket_n[i][k]<<endl;
		  }
		 
		}
	  cout<<endl;
	
  }*/
}

 