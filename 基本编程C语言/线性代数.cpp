#include<iostream>//written by 李明晰
#include<iomanip>
#include<math.h>
using namespace std;
class matrix
{
private:
	float a[101][101];//基础数组
	float b[101][101];//乘数数组
	float c[101][101][101];//积数组
	float d[101][101][101];//和数组
	float tr[101][101];//转置矩阵
	float algc[101][101];//余子式
	float fol[101][101];//伴随矩阵
	float in[101][101];//逆矩阵
	float tra[101][101];//梯形阵
	float tri[101][101];//三角阵
	float algc_tri[101][101];//余子式的三角阵
	float sim[101][101];//行最简形
	float agm[101][101];//增广矩阵
	float tra_agm[101][101];//增广矩阵的梯形阵
	float sim_agm[101][101];//增广矩阵的行最简形
	float sol[101][101];//基础解系
	int n;//阶数n
	int i;//行数i
	int j;//列数j
	int jj;//增广矩阵列数jj
	int k;//第k行
	int l;//第l列
	int R;//秩
	int RR;//增广矩阵的秩
public:
	bool higher;//是否超出数组行列范围
	bool full;//判断是否满秩
	bool square;//判断是否为方阵
	void if_square();//是否为方阵
	void if_full();//是否满秩
	void divider()//分割线
	{int q;
	for(q=1;q<=40;q++){cout<<"* ";}
	cout<<endl;
	}
	void chg_tr();//矩阵转置
	void chg_add();//矩阵相加
	void chg_mal();//矩阵乘法
	void chg_fol();//求伴随矩阵
	void chg_in();//求逆阵
	void chg_tri(int);//化三角阵
	void chg_algc_tri(int);//余子式化三角阵
	void chg_tra();//化梯形阵
	void chg_tra_agm();//增广矩阵化梯形阵
	void chg_sim();//化行最简形
	void chg_sim_agm();//增广矩阵化行最简形
	void basic_solution(bool);//求线性方程组通解
	int caclR();//求秩
	int caclR_agm();//求增广矩阵的秩
	float caclalgc(int kk,int ll);//代数余子式
	float determinant();//求行列式
	void inputa(bool);//输入矩阵
	void outputsim();//输出行最简形
	void outputa();//输出矩阵
	void outputtra();//输出梯形阵
	void outputtr();//输出转置矩阵
	void outputin();//输出逆阵
};
void matrix::inputa(bool sq)//输入矩阵
{
	divider();
	if(sq==false){
		cout<<"主人~先输入矩阵的行数和列数吧!"<<endl;
		cout<<"行:";
		cin>>i;
		cout<<"列:";
		cin>>j;
		if(i==j)n=i;
	}
	if(sq==true){
		cout<<"主人~先输入方阵的阶数吧!"<<endl;
		cout<<"阶数:";
		cin>>n;
		i=j=n;
	}
	divider();
	if(i>100||j>100){
		cout<<"无法操作如此高阶的方阵呀……"<<endl;
		higher=true;
	}
	else{
		cout<<"接下来输入矩阵吧主人~"<<endl<<"矩阵:"<<endl;;
		for(k=1;k<=i;k++){
			for(l=1;l<=j;l++){
				cin>>a[k][l];
			}
		}
	}
	divider();
}
void matrix::if_square()//是否为方阵
{
	if(i!=j)square=false;
	else square=true;
}
void matrix::outputa()//输出矩阵
{
	for(k=1;k<=i;k++){
		for(l=1;l<=j;l++){
			cout.precision(2);
			cout.width(5);
			cout.setf(ios::left);
			cout<<a[k][l];
		}
		cout<<endl;
	}
}
void matrix::outputsim()//输出行最简形
{
	for(k=1;k<=i;k++){
		for(l=1;l<=j;l++){
			cout.setf(ios::fixed);
			cout.precision(2);
			cout.width(8);
			cout.setf(ios::left);
			cout<<sim[k][l];
		}
		cout<<endl;
	}
}
void matrix::outputtra()//输出梯形阵
{
	for(k=1;k<=i;k++){
		for(l=1;l<=j;l++){
			cout.setf(ios::fixed);
			cout.precision(2);
			cout.width(8);
			cout.setf(ios::left);
			cout<<tra[k][l];
		}
		cout<<endl;
	}
}
void matrix::outputtr()//输出转置矩阵
{
	for(k=1;k<=i;k++){
		for(l=1;l<=j;l++){
			cout.setf(ios::fixed);
			cout.precision(2);
			cout.width(8);
			cout.setf(ios::left);
			cout<<tr[k][l];
		}
		cout<<endl;
	}
}
void matrix::outputin()//输出逆阵
{
	for(k=1;k<=i;k++){
		for(l=1;l<=j;l++){
			cout.setf(ios::fixed);
			cout.precision(2);
			cout.width(8);
			cout.setf(ios::left);
			cout<<in[k][l];
		}
		cout<<endl;
	}
}
void matrix::chg_tr()//矩阵转置
{
	for(k=1;k<=i;k++){
		for(l=1;l<=j;l++){
			tr[l][k]=a[k][l];
		}
	}
	outputtr();
}
void matrix::chg_add()//矩阵加法
{
	int d0,ctost;
	bool ctn;
	for(k=1;k<=i;k++){
		for(l=1;l<=j;l++){
			d[0][k][l]=a[k][l];
		}
	}
	for(d0=0,ctn=true;ctn==true;d0++){
		cout<<"主人输入要加上的"<<i<<"×"<<j<<"矩阵吧"<<endl;
		for(k=1;k<=i;k++){
			for(l=1;l<=j;l++){
				cin>>b[k][l];
			}
		}
		for(k=1;k<=i;k++){
			for(l=1;l<=j;l++){
				d[d0+1][k][l]=d[d0][k][l]+b[k][l];
			}
		}
		cout<<"主人,矩阵相加的结果为:"<<endl;
		for(k=1;k<=i;k++){
			for(l=1;l<=j;l++){
				cout.setf(ios::fixed);
				cout.precision(2);
				cout.width(8);
				cout.setf(ios::left);
				cout<<d[d0+1][k][l];
			}
			cout<<endl;
		}
		if(d0==100){
			cout<<"主人快停下吧,我受不了"<<endl;
			break;
		}
		divider();
		cout<<"主人要不要加下一个矩阵呢?(连加!=0/结束=0)"<<endl<<"判断指令:";
		cin>>ctost;
		if(ctost==0)ctn=false;
	}
}
void matrix::chg_mal()//矩阵乘法
{
	int ib,jb,l1,lr,ctost,c0=0;
	bool lor,ctn;
	for(k=1;k<=i;k++){
		for(l=1;l<=j;l++){
			c[0][k][l]=a[k][l];
		}
	}
	for(ctn=true;ctn==true;c0++){
		cout<<"主人要左乘还是右乘呢?(左乘=1/右乘=2)"<<endl<<"判断指令:";
		cin>>lr;
		if(lr!=1&&lr!=2){
			for(;lr!=1&&lr!=2;){
				cout<<"主人输入的不对呢~要重新输入哦(左乘=1/右乘=2)"<<endl<<"判断指令:";
				cin>>lr;
				divider();
			}
		}
		if(lr==2)lor=true;
		else if(lr==1)lor=false;
		if(lor==true){
			cout<<"要先输入右乘矩阵的列数呢~"<<endl;
			cin>>jb;
			cout<<"输入要右乘的"<<j<<"×"<<jb<<"的矩阵吧主人"<<endl;
			for(k=1;k<=j;k++){
				for(l=1;l<=jb;l++){
					cin>>b[k][l];
				}
			}
			divider();
			for(k=1;k<=i;k++){
				for(l=1;l<=jb;l++){
					c[c0+1][k][l]=0;
					for(l1=1;l1<=j;l1++){
						c[c0+1][k][l]=c[c0+1][k][l]+c[c0][k][l1]*b[l1][l];
					}
				}
			}
			cout<<"主人,矩阵相乘的结果为:"<<endl;;
			for(k=1;k<=i;k++){
				for(l=1;l<=jb;l++){
					cout.setf(ios::fixed);
					cout.precision(2);
					cout.width(8);
					cout.setf(ios::left);
					cout<<c[c0+1][k][l];
				}
				cout<<endl;
			}
		}
		if(lor==false){
			cout<<"要先输入左乘矩阵的行数呢~"<<endl;
			cin>>ib;
			cout<<"输入要左乘的"<<ib<<"×"<<j<<"的矩阵吧主人"<<endl;
			for(k=1;k<=ib;k++){
				for(l=1;l<=j;l++){
					cin>>b[k][l];
				}
			}
			divider();
			for(k=1;k<=ib;k++){
				for(l=1;l<=j;l++){
					c[c0+1][k][l]=0;
					for(l1=1;l1<=j;l1++){
						c[c0+1][k][l]=c[c0+1][k][l]+b[k][l1]*c[c0][l1][l];
					}
				}
			}
			cout<<"主人,矩阵相乘的结果为:"<<endl;
			for(k=1;k<=ib;k++){
				for(l=1;l<=j;l++){
					cout.setf(ios::fixed);
					cout.precision(2);
					cout.width(8);
					cout.setf(ios::left);
					cout<<c[c0+1][k][l];
				}
				cout<<endl;
			}
		}
		if(c0==100){
			cout<<"主人快停下吧,我受不了"<<endl;
			break;
		}
		divider();
		cout<<"主人要不要乘下一个矩阵呢?(连乘!=0/结束=0)"<<endl<<"判断指令:";
		cin>>ctost;
		if(ctost==0)ctn=false;
	}
}
float matrix::caclalgc(int kk,int ll)//求代数余子式
{
	int k1,l1;
	for(k1=1,k=1;k<=n;k++,k1++){
		if(k==kk)k++;
		for(l1=1,l=1;l<=n;l1++,l++){
			if(l==ll)l++;
			algc[k1][l1]=a[k][l];
		}
	}
	int p;
	float D=1;
	for(p=1;p<=n-1;p++)chg_algc_tri(p);
	for(p=1;p<=n-1;p++)D*=algc_tri[p][p];
	return D;
}
void matrix::chg_fol()//求伴随矩阵
{
	int k2,l2;
	for(k2=1;k2<=n;k2++){
		for(l2=1;l2<=n;l2++){
			fol[l2][k2]=caclalgc(k2,l2);
		}
	}
}
void matrix::chg_in()//求逆阵
{
	float D;
	D=determinant();
	chg_fol();
	for(k=1;k<=i;k++){
		for(l=1;l<=j;l++){
			in[k][l]=fol[k][l];
			in[k][l]=in[k][l]/D;
		}
	}
}
void matrix::chg_tri(int t)//化为三角阵
{
	int g,b,d,e,y,z;
	float c;
	if(t==1){
		for(y=1;y<=i;y++){
			for(z=1;z<=j;z++){
				tri[y][z]=a[y][z];
			}
		}
	}
	if(tri[t][t]==0){
		for(g=t+1;g<=n;g++){
			if(tri[g][t]!=0){
				for(b=1;b<=n;b++)swap(tri[t][b],tri[g][b]);
				break;
			}
		}
	}
	if(tri[t][t]!=0){
		for(d=t+1;d<=n;d++){
			c=tri[d][t]/tri[t][t];
			for(e=1;e<=n;e++){
				tri[d][e]=tri[d][e]-c*tri[t][e];
			}
		}
	}
}
void matrix::chg_algc_tri(int t)//余子式化为三角阵
{
	int g,b,d,e,y,z;
	float c;
	if(t==1){
		for(y=1;y<=i-1;y++){
			for(z=1;z<=j-1;z++){
				algc_tri[y][z]=algc[y][z];
			}
		}
	}
	if(algc_tri[t][t]==0){
		for(g=t+1;g<=n-1;g++){
			if(algc_tri[g][t]!=0){
				for(b=1;b<=n-1;b++){swap(algc_tri[t][b],algc_tri[g][b]);}
				break;
			}
		}
	}
	if(algc_tri[t][t]!=0){
		for(d=t+1;d<=n-1;d++){
			c=algc_tri[d][t]/algc_tri[t][t];
			for(e=1;e<=n-1;e++){
				algc_tri[d][e]=algc_tri[d][e]-c*algc_tri[t][e];
			}
		}
	}
}
float matrix::determinant()//求行列式
{
	int p;
	float D=1;
	for(p=1;p<=n;p++)chg_tri(p);
	for(p=1;p<=n;p++)D*=tri[p][p];
	return D;
}
void matrix::chg_tra()//化梯形阵
{
	float f;
	int b,c,d,e;
	int w,x,y,z;
	for(y=1;y<=i;y++){
		for(z=1;z<=j;z++){
			tra[y][z]=a[y][z];
		}
	}
	for(w=x=1;x<=j;w++,x++){
		if(fabs(tra[w][x]-0)<1e-6){
			for(b=w+1;b<=i;b++){
				if(tra[b][w]!=0){
					for(c=1;c<=j;c++){swap(tra[w][c],tra[b][c]);}
					break;
				}
			}
		}
		if(fabs(tra[w][x]-0)>1e-6){
			for(d=w+1;d<=i;d++){
				f=tra[d][x]/tra[w][x];
				for(e=1;e<=j;e++){
					tra[d][e]=tra[d][e]-f*tra[w][e];
				}
			}
		}
		if(tra[w][x]==0)w-=1;
	}
}
void matrix::chg_tra_agm()//增广矩阵化梯形阵
{
	float f;
	int b,c,d,e;
	int w,x,y,z;
	for(y=1;y<=i;y++){
		for(z=1;z<=jj;z++){
			tra_agm[y][z]=agm[y][z];
		}
	}
	for(w=x=1;x<=jj;w++,x++){
		if(tra_agm[w][x]==0){
			for(b=w+1;b<=i;b++){
				if(tra_agm[b][w]!=0){
					for(c=1;c<=jj;c++){swap(tra_agm[w][c],tra_agm[b][c]);}
					break;
				}
			}
		}
		if(fabs(tra_agm[w][x]-0)>1e-6){
			for(d=w+1;d<=i;d++){
				f=tra_agm[d][x]/tra_agm[w][x];
				for(e=1;e<=jj;e++){
					tra_agm[d][e]=tra_agm[d][e]-f*tra_agm[w][e];
				}
			}
		}
		if(tra_agm[w][x]==0)w-=1;
	}
}
void matrix::chg_sim()//化行最简形
{
	int b,c;
	float f;
	chg_tra();
	for(k=1;k<=i;k++){
		for(l=1;l<=j;l++){
			sim[k][l]=tra[k][l];
		}
	}
	for(k=1;k<=i;k++){
		for(l=1;l<=j;l++){
			if(fabs(sim[k][l]-0)>1e-6)break;
		}
		if(l<=j){
			for(b=l;b<=j;b++){
				sim[k][b]=sim[k][b]/sim[k][l];
			}
			for(b=k-1;b>=1;b--){
				f=sim[b][l]/sim[k][l];
				for(c=1;c<=j;c++){
					sim[b][c]=sim[b][c]-f*sim[k][c];
				}
			}
		}
	}
}
void matrix::chg_sim_agm()//增广矩阵化行最简形
{
	int b,c;
	float f;
	chg_tra_agm();
	for(k=1;k<=i;k++){
		for(l=1;l<=jj;l++){
			sim_agm[k][l]=tra_agm[k][l];
		}
	}
	for(k=1;k<=i;k++){
		for(l=1;l<=jj;l++){
			if(fabs(sim_agm[k][l]-0)>1e-6)break;
		}
		if(l<=j){
			for(b=l;b<=jj;b++){
				sim_agm[k][b]=sim_agm[k][b]/sim_agm[k][l];
			}
			for(b=k-1;b>=1;b--){
				f=sim_agm[b][l]/sim_agm[k][l];
				for(c=1;c<=jj;c++){
					sim_agm[b][c]=sim_agm[b][c]-f*sim_agm[k][c];
				}
			}
		}
	}
}
void matrix::basic_solution(bool equal)//求线性方程组通解
{
	if_full();
	if(equal==true&&full==true)cout<<"方程组只有零解"<<endl;
	else{
		int au[101];
		bool aut[101];
		int p,q=1,r=j,k1,l1;
		for(p=1;p<=100;p++)*(au+p)=0;
		for(k=1;k<=100;k++){
			aut[k]=false;
			for(l=1;l<=100;l++){
				sol[k][l]=0;
			}
		}
		chg_sim();
		for(k=i;k>=1;k--){//确定真未知数
			for(l=1;l<=j;l++){
				if(sim[k][l]!=0)break;
			}
			if(l==j+1)continue;
			for(p=l+1;;p++){
				if(p>r){
					r=l-1;
					break;
				}			
				*(au+q)=p;
				q++;
			}
		}
		for(p=1;p<=100;p++){
			if(au[p]==0){
				p--;
				break;
			}
		}
		for(l=p;l>=1;l--){
			sol[au[l]][l]=1;
			aut[au[l]]=true;
		}
		for(l=p;l>=1;l--){
			for(k=1,k1=1;k<=j-p;k++,k1++){
				for(;k<=i;k++){
					if(aut[k]==false)break;
				}
				sol[k][l]=-sim[k1][au[l]];
			}
		}
		l1=p;
		if(equal==true){
			cout<<"主人,通解为:"<<endl;
			cout<<"(";
			for(p=1;p<=j;p++){
				printf("x%d",p);
				if(p==j)break;
				cout<<",";
			}
			cout<<")T=";
			for(l=1;l<=l1;l++){
				printf("k%d(",l);
				for(k=1;k<=j;k++){
					cout<<sol[k][l];
					if(k==j)break;
					cout<<",";
				}
				cout<<")T";
				if(l==l1)break;
				cout<<"+";
			}
		}
		if(equal==false){
			jj=j+1;
			for(k=1;k<=i;k++){
				for(l=1;l<=j;l++){
					agm[k][l]=a[k][l];
				}
			}
			cout<<"输入方程组的常数项吧主人"<<endl;
			for(k=1;k<=i;k++)cin>>agm[k][jj];
			chg_sim_agm();
			for(k=1;k<=i;k++)sol[k][0]=agm[k][jj];
			R=caclR();
			RR=caclR_agm();
			if(RR>R)cout<<"方程组无解呢主人";
			else if(i==j&&R==n){
				cout<<"方程组有唯一解呢主人"<<endl<<"方程组的解向量为(";
				for(k=1;;k++){
					cout<<sol[k][0];
					if(k==i)break;
					cout<<",";
				}
				cout<<")";
			}
			else{
				cout<<"主人,通解为";
				cout<<"主人,通解为:"<<endl;
				cout<<"(";
				for(p=1;p<=j;p++){
					printf("x%d",p);
					if(p==j)break;
					cout<<",";
				}
				cout<<")T=";
				cout<<"(";
				for(k=1;;k++){
					cout<<sol[k][0];
					if(k==i)break;
					cout<<",";
				}
				cout<<")T+";
				for(l=1;l<=l1;l++){
					printf("k%d(",l);
					for(k=1;k<=j;k++){
						cout<<sol[k][l];
						if(k==j)break;
						cout<<",";
					}
					cout<<")T";
					if(l==l1)break;
					cout<<"+";
				}
			}
		}
		cout<<endl;
	}
}
int matrix::caclR()//求秩
{
	bool zero=true;
	int m;
	chg_tra();
	for(m=i;zero==true&&m>=1;m--){
		if(fabs(tra[m][j]-0)>1e-6)zero=false;
	}
	m+=1;
	return m;
}
int matrix::caclR_agm()//求增广矩阵的秩
{
	bool zero=true;
	int m;
	chg_tra_agm();
	for(m=i;zero==true&&m>=1;m--){
		if(fabs(tra_agm[m][j]-0)>1e-6)zero=false;
	}
	m+=1;
	return m;
}
void matrix::if_full()//判断是否满秩
{
	R=caclR();
	if(i==j&&R==n)full=true;
	else full=false;
}
int main()
{
	int yon;
	bool inside,outside,square,equal;
	cout<<"LMX is charming!"<<endl;
	matrix *mat;
	for(outside=true;outside==true;){
		mat=new matrix;
		int which;
		enum way {CHGTR=1,CHGTA,CALR,CHGSR,BSSL,CALAD,CALML,CALD,CALIN};//(矩阵转置,化梯形阵,求秩,化行最简形,求基础解系,矩阵相加,矩阵相乘,行列式,求逆)
		way way1;
		cout<<"主人~这次要操作的矩阵是不是方阵呢?(方阵=!0/非方阵=0)"<<endl;
		cout<<"判断指令:";
		cin>>yon;
		if(yon==0)square=0;
		else square=1;
		mat->inputa(square);
		if(mat->higher==true)return 0;
		for(inside=true;inside==true;){
			cout<<"主人想要做什么呢?"<<endl;
			if(square==true){
				cout<<"(矩阵转置=1,化梯形阵=2,求秩=3,化行最简形=4,求基础解系=5,矩阵相加=6,矩阵相乘=7,行列式=8,求逆=9)"<<endl;
				cout<<"操作指令:";
				do{
					cin>>yon;
					if(yon>8)cout<<"输入错误,主人要重新输入哦"<<endl;
				}while(yon>8);
			}
			if(square==false){
				cout<<"(矩阵转置=1,化梯形阵=2,求秩=3,化行最简形=4,求基础解系=5,矩阵相加=6,矩阵相乘=7)"<<endl;
				cout<<"操作指令:";
				do{
					cin>>yon;
					if(yon>8)cout<<"输入错误,主人要重新输入哦~"<<endl;
				}while(yon>8);
			}
			which=yon;
			mat->divider();
			way1=way(which);
			if(way1==CHGTR){
				cout<<"主人,转置矩阵为:"<<endl;
				mat->chg_tr();
			}
			if(way1==CALD){
				float D;
				if(mat->higher==true)return 0;
				D=mat->determinant();
				cout.setf(ios::fixed);
				cout.precision(4);
				cout<<"这个行列式的值是"<<endl<<"*"<<D<<"*呢"<<endl;
				cout.unsetf(ios::fixed);
			}
			if(way1==CHGTA){
				mat->chg_tra();
				mat->outputtra();
			}
			if(way1==CALR){
				cout<<"该矩阵的秩为"<<mat->caclR()<<"呢"<<endl;
			}
			if(way1==CHGSR){
				mat->chg_sim();
				mat->outputsim();
			}
			if(way1==BSSL){
				cout<<"主人输入的矩阵是齐次方程组吗?(齐次方程组=!0/非齐次方程组=0)"<<endl;
				cout<<"判断指令:";
				cin>>yon;
				if(yon==0)equal=false;
				else equal=true;
				mat->basic_solution(equal);
			}
			if(way1==CALAD){
				mat->chg_add();
			}
			if(way1==CALML){
				mat->chg_mal();
			}
			if(way1==CALIN){
				mat->if_square();
				if(square==false)cout<<"该矩阵无法求逆阵呢~主人"<<endl;
				else{
					mat->chg_in();
					cout<<"主人,矩阵的逆为:"<<endl;
					mat->outputin();
				}
			}
			mat->divider();
			cout<<"主人还想要对这个矩阵再做些什么吗?(yes=!0/no=0)"<<endl;
			cout<<"判断指令:";
			cin>>yon;
			if(yon==0)inside=0;
			else inside=1;
		}
		delete mat;
		cout<<"主人还想要操作别的矩阵吗?(yes=!0/no=0)"<<endl;
		cout<<"判断指令:";
		cin>>yon;
		if(yon==0)outside=0;
		else outside=1;
	}
	return 0;
}
