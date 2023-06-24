#include<iostream>
#include<math.h>
using namespace std;

// 平方平均
double QM(double x,double y){
    return sqrt((x*x+y*y)/2.0);
}
// 算术平均
double AM(double x,double y){
    return (x+y)/2.0;
}
// 几何平均
double GM(double x,double y){
    return sqrt(x*y);
}
// 调和平均
double HM(double x,double y){
    return (2.0/(1.0/x+1.0/y));
}
// 负二次方平均
double MM(double x,double y){
    return sqrt(2.0/(1.0/(x*x)+1.0/(y*y)));
}
// 算术-几何平均
double AGM(double x,double y){
	double a[100];
	double b[100];
	a[0]=x;
	b[0]=y;
	for(int i=0;i<99;i++){
		a[i+1]=(a[i]+b[i])/2;
		b[i+1]=sqrt(a[i]*b[i]);
	}
	//cout<<a[99]<<" "<<b[99]<<endl;
	return (a[99]+b[99])/2;
}
// 几何-调和平均
double GHM(double x,double y){
	double a[100];
	double b[100];
	a[0]=x;
	b[0]=y;
	for(int i=0;i<99;i++){
		a[i+1]=sqrt(a[i]*b[i]);
		b[i+1]=2.0/(1.0/a[i]+1.0/b[i]);
	}
	//cout<<a[99]<<" "<<b[99]<<endl;
	return (a[99]+b[99])/2;
}
// 算术-调和平均
double AHM(double x,double y){
	double a[100];
	double b[100];
	a[0]=x;
	b[0]=y;
	for(int i=0;i<99;i++){
		a[i+1]=(a[i]+b[i])/2;
		b[i+1]=2.0/(1.0/a[i]+1.0/b[i]);
	}
	//cout<<a[99]<<" "<<b[99]<<endl;
	return (a[99]+b[99])/2;
}
// 平方-算术平均
double QAM(double x,double y){
	double a[100];
	double b[100];
	a[0]=x;
	b[0]=y;
	for(int i=0;i<99;i++){
		a[i+1]=sqrt((a[i]*a[i]+b[i]*b[i])/2);
		b[i+1]=(a[i]+b[i])/2;
	}
	//cout<<a[99]<<" "<<b[99]<<endl;
	return (a[99]+b[99])/2;
}
// 平方-几何平均
double QGM(double x,double y){
	double a[100];
	double b[100];
	a[0]=x;
	b[0]=y;
	for(int i=0;i<99;i++){
		a[i+1]=sqrt((a[i]*a[i]+b[i]*b[i])/2);
		b[i+1]=sqrt(a[i]*b[i]);
	}
	//cout<<a[99]<<" "<<b[99]<<endl;
	return (a[99]+b[99])/2;
}
// 平方-负二次方平均
double QMM(double x,double y){
	double a[100];
	double b[100];
	a[0]=x;
	b[0]=y;
	for(int i=0;i<99;i++){
		a[i+1]=sqrt((a[i]*a[i]+b[i]*b[i])/2);
		b[i+1]=sqrt(2.0/(1.0/(a[i]*a[i])+1.0/(b[i]*b[i])));
	}
	//cout<<a[99]<<" "<<b[99]<<endl;
	return (a[99]+b[99])/2;
}
// 几何-负二次方平均
double GMM(double x,double y){
	double a[100];
	double b[100];
	a[0]=x;
	b[0]=y;
	for(int i=0;i<99;i++){
		a[i+1]=sqrt(a[i]*b[i]);
		b[i+1]=sqrt(2.0/(1.0/(a[i]*a[i])+1.0/(b[i]*b[i])));
	}
	//cout<<a[99]<<" "<<b[99]<<endl;
	return (a[99]+b[99])/2;
}

int main(){

    bool hasStarted = true;
    while(hasStarted){
        double a,b;
        
        cout<<"Please input two positive numbers:"<<endl;
        cin>>a>>b;
        if(a<=0||b<=0){
            hasStarted = false;
            cout<<"Stop!"<<endl;
        }
        else{
            double qm;
            double am;
            double gm;
            double hm;
            double mm;

            double agm;
            double qam;

            qm=QM(a,b);
            am=AM(a,b);
            gm=GM(a,b);
            hm=HM(a,b);
            mm=MM(a,b);

            agm=AGM(a,b);
            qam=QAM(a,b);
            
            //cout<<"QM\t"<<"AM\t"<<"GM\t"<<"HM\t"<<"MM\t"<<endl;
            //cout<<qm<<"\t"<<am<<"\t"<<gm<<"\t"<<hm<<"\t"<<mm<<"\t"<<endl;

            cout<<"QM\t"<<"QAM\t"<<"AM\t"<<"AGM\t"<<"GM\t"<<"HM\t"<<"MM\t"<<endl;
            cout<<qm<<"\t"<<qam<<"\t"<<am<<"\t"<<agm<<"\t"<<gm<<"\t"<<hm<<"\t"<<mm<<"\t"<<endl;
        }
    }
    
    return 0;
}
