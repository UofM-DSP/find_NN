#include"run_time.h"
#include<algorithm>

using namespace std;
void run_time()
{
	ifstream infile("C:\\Wasif\\find_NN\\without lsh_plaintext\\euclid_time_30k.txt");
	float score,sum;
	sum=0;
	int i=1;
	while(infile>>score)
	{
		cout<<score<<endl;
		sum=sum+score;
		i++;
		//if(i>=25)break;
	}
	cout<<"number of val"<<i-1<<endl;
	float runtime=sum/(i-1);
	cout<<"runtime"<<runtime<<endl;

}