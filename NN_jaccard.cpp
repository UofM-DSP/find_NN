#include"NN_jaccard.h"
//#define q 1
//#define feature_set_size 17
//#define query_n 3


using namespace std;
//void jaccardDistance(char** input,  int query, int limit,int rows)
void jaccard()
{
    string user[5005];
	//int limit=Limit;
	ifstream infile;
	infile.open("without lsh_plaintext\\jaccard_time_50k.txt");
	int index=1;
	string s;
	cout<<"call is here"<<endl;
	while(infile>>s)
	{
		cout<<s<<endl;
	    user[index]=s;
	  //  cout<< user[i]<<endl;
	  //  index++;
	  //  if(index>5000)break;
		cout<<"lenth is"<<s.length();
	}
	/*
	for(int q=1;q<=50;q++)
	{
	    string file_name;
        file_name="top_5_nn_genome\\result_nn";
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

      }
      cout<<file_name<<endl;
     // char *file_n=file_name.c_str();


	ofstream outfile(file_name.c_str(),std::ofstream::out);

	string query;

	query=user[q];
	 std::multimap<float,int> items;

	for(int i=1;i<=5000;i++)
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
			cout<<"lengh is"<<len<<endl;

		 for (int j= 0; j < len; j++)
			{
				//int f1,f2;
				//f1=query_features.at(m)-'0';
		     //	f2=feature[i].at(m)-'0';
			//	cout<<

				if(query.at(j)== '0' && user[i].at(j)=='0')
					{
					continue;
					}

				if(query.at(j)== user[i].at(j))
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
		cout<<"point"<<i<<endl;
		printf("distance %f\n",dist);
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
	//}

	}
	//}*/
	//getch();
	//return 0;
}

