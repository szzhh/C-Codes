#include<math.h> 
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h> 
#include "engine.h"  
#include "DNA.h"

using namespace std;

//清空vector 
template < class T >
void ClearVector( vector< T >& vt ) 
{
    vector< T > vtTemp;
    vtTemp.swap( vt );
}
bool draw(double z1[][181],double size)
{

	Engine *ep;

	// open engine
	if (!(ep = engOpen("\0")))
	{
		fprintf(stderr, "\nCan't start MATLAB engine\n");
		return EXIT_FAILURE;
	}

	double xx[20] = { -0.8,-0.4,0.0,0.6,-0.8,-0.4,0.0,0.6,-0.8,-0.4,0.2,0.6,-0.8,-0.4,0.2,0.6,-0.8,-0.2,0.2,0.6 };
	double yy[20] = { -0.4,-0.4,0.8,-0.8,-0.2,-0.6,1.0,-0.6,0.0,-0.8,-0.8,-0.4,-0.2,-0.8,-0.6,-0.2,-0.4,-0.6,-0.4,0.0 };
	double zz[20] = { 0.477,0.825,0.600,0.000,0.566,0.693,0.000,0.529,0.600,0.477,0.566,0.693,0.566,0.566,0.775,0.775,0.447,0.775,0.894,0.800 };



	mxArray *X = NULL, *Y = NULL, *Z = NULL, *Z1 = NULL, *result = NULL;
	X = mxCreateDoubleMatrix(1, 20, mxREAL);
	Y = mxCreateDoubleMatrix(1, 20, mxREAL);
	Z = mxCreateDoubleMatrix(1, 20, mxREAL);
	Z1 = mxCreateDoubleMatrix(181, 181, mxREAL);
	memcpy((void *)mxGetPr(X), (void *)xx, sizeof(xx));
	memcpy((void *)mxGetPr(Y), (void *)yy, sizeof(yy));
	memcpy((void *)mxGetPr(Z), (void *)zz, sizeof(zz));
	memcpy((void *)mxGetPr(Z1), (void *)z1, size);
	engPutVariable(ep, "X", X);
	engPutVariable(ep, "Y", Y);
	engPutVariable(ep, "Z", Z);
	engPutVariable(ep, "Z1", Z1);// put data to engine

	// execute matlab operations
	engEvalString(ep, "scatter3(X,Y,Z,'*');");
	engEvalString(ep, "hold on");
	engEvalString(ep, "X1=-0.8:0.01:1;");
	engEvalString(ep, "Y1=-0.8:0.01:1;");
	engEvalString(ep, "[X1,Y1]=meshgrid(X1,Y1);");
	engEvalString(ep, "mesh(X1,Y1,Z1);");
	engEvalString(ep, "hold off;");

	fgetc(stdin);

	// clean operation
	mxDestroyArray(X);
	mxDestroyArray(Y);
	mxDestroyArray(Z);
	mxDestroyArray(Z1);
	engEvalString(ep, "close;");

	engClose(ep);// 关闭引擎
}

int main(){
	srand(time(NULL));
	double x1[181], y1[181], zz1[181][181];
	double tt = -0.8;
	for (int ii = 0; ii <= 180; ii++)
	{
		x1[ii] = tt;
		y1[ii] = tt;
		tt += 0.01;
	}

	vector<DNA> population;//DNA组（种族）
	for(int i=0;i<prine_number;i++){
		population.push_back(DNA());
	}
	vector <float> p_c_p;//适应性数组
	int add_c_p=0;//适应性倒数和
	ClearVector(p_c_p);
	for(int i=0;i<population.size();i++){
		if(isnan(population[i].c_p)||isinf(population[i].c_p)||population[i].c_p>1.0e+004){
			population.erase(population.begin()+i);
			i--;
		}
	}
	for(int i=0;i<population.size();i++){
		for(int j=0;j<population.size()-i-1;j++){
			if(population[j].c_p>population[j+1].c_p){
				DNA tamporary=population[j];
				population[j]=population[j+1];
				population[j+1]=tamporary;
			}
		}
		p_c_p.insert(p_c_p.begin(),population[population.size()-1-i].c_p);
		add_c_p+=1/p_c_p[0];
	}
	//每代的繁衍 
	for(int generation=0;generation<max_generation;generation++){
		int S=population.size();
		//繁衍过程 
		for(int i=0;i<num_pre_generation;i++){
			DNA t1,t2;
			float tp1=0,tp2=0;
			tp1=rand()%10000/10000.0;tp2=rand()%10000/10000.0;
			for(int i=0;i<S;i++){
				tp1-=1/(add_c_p*p_c_p[i]);
				tp2-=1/(add_c_p*p_c_p[i]);
				if(tp1<=0){
					t1=population[i];
					tp1=100;
				}
				if(tp2<=0){
					t2=population[i];
					tp2=100;
				}
				if(tp1>1&&tp2>1){
					break;
				}
			}
			population.push_back(DNA(t1,t2));
		}
		ClearVector(p_c_p);
		for(int i=0;i<population.size();i++){
			if(isnan(population[i].c_p)||isinf(population[i].c_p)||population[i].c_p>max_c_p){
				population.erase(population.begin()+i);
				i--;
			}
		}
		for(int i=0;i<population.size();i++){
			for(int j=0;j<population.size()-i-1;j++){
				if(population[j].c_p>population[j+1].c_p){
					DNA tamporary=population[j];
					population[j]=population[j+1];
					population[j+1]=tamporary;
				}
			}
			p_c_p.insert(p_c_p.begin(),population[population.size()-1-i].c_p);
		}
		if((generation+1)%die_generation==0){
			population.erase(population.begin()+population.size()-int(population.size()*die_rate),population.begin()+population.size());
		}
		p_c_p.erase(p_c_p.begin()+p_c_p.size()-int(p_c_p.size()*die_rate),p_c_p.begin()+p_c_p.size());
		for(int i=0;i<p_c_p.size();i++){
			add_c_p+=1/p_c_p[i];
		}
		//在这里用population[0].output(x,y)输出z
		
	}
	//最后的输出函数 
	for(int i=0;i<population.size();i++){
		cout<<population[i].code<<' '<<population[i].c_p<<endl;
	}
	cout<<population.size();

	for (int ii = 0; ii <= 180; ii++)
	{
		for (int jj = 0; jj <= 180; jj++)
		{
			zz1[ii][jj] = population[0].output(x1[ii], y1[jj]);
		}
	}

	//draw(zz1,sizeof(zz1));
}

