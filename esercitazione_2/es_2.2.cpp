#include<iostream>
#include<algorithm>	
#include<cmath>
int main()
{
	double m=0, med=0, M=0, devstd=0, sum=0,sumdev=0;
	static const int N = 10;
	double arr[N]={0.0,1.0,3.0,6.0,3.0,7.0,0.0,3.0,4.0,2.0};
	
	//media
	for (int i=0; i<N;i++){
			sum=sum+arr[i];
	}
	med=sum/N;
	std::cout<< med << "\n";
	
	//massimo
	for (int i=0; i<N-1;i++){
		if (i==0){
			M=arr[i];
		}
		else{
			if (std::max(arr[i],arr[i+1])>M){
				M=std::max(arr[i],arr[i+1]);
			
	}}}
	std::cout<< M << "\n";
	
	//minimo
	for (int i=0; i<N-1;i++){
		if (i==0){
			m=arr[i];
		}
		else{
			if (std::min(arr[i],arr[i+1])<m){
				m=std::min(arr[i],arr[i+1]);
			
	}}}
	std::cout<< m << "\n";
	
	//dev std
	for (int i=0; i<N;i++){
		sumdev=sumdev+pow((arr[i]-med),2);
		
	}
	devstd=sqrt(sumdev/N);
	std::cout<< devstd << "\n";
	
	return 0;
}