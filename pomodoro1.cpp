#include<bits/stdc++.h> 
#include<conio.h>
#include <windows.h>
using namespace std;
int main(){
	float t,studytime,resttime,ff=0,w;
	int finish[55],k=0;
	string content[55];
	
	cout<<"1.設定番茄鐘"<<endl;
	cout<<"請依序設定番茄鐘個數、每個番茄鐘的工作時長、休息時長："<<endl;
	cin>>t>>studytime>>resttime;
	int ssec=studytime*60; 
	int rsec=resttime*60;
	
	cout<<"2.To-do list"<<endl;
	cout<<"請輸入工作件數： "; 
	cin>>w;
	cout<<"請依編號輸入工作科目/類型、工作內容："<<endl;
	for(int i=0;i<w;i++){
		cout<<"task "<<i+1<<":";
		cin>>content[i];
	} 
	
	cout<<"計時開始請按下鍵盤上的's'"<<endl;
	if(getch()=='s'){
		if(k<t){
			for(int i=ssec;i>=0;i--){
        		cout <<"Pomodoro "<<k+1<<"--剩餘時間："<<setw(3)<<i/60<<"："<<setw(2)<<i%60;
        		cout << string(100,'\b');           //退格，以免重複印出 
        		Sleep(1000);            			//延遲一秒--每個倒數時間間隔一秒 
    		}
    		cout<<"請輸入在這個番茄鐘中你所完成的工作編號：(若無請輸入'0')"<<endl;
    		cin>>finish[k];
    		if(finish[k]!=0) ff++;
    		
    		for(int i=rsec;i>=0;i--){
        		cout <<"Rest time "<<k+1<<"--剩餘時間："<<setw(3)<<i/60<<"："<<setw(2)<<i%60;
        		cout << string(100,'\b');           //退格，以免重複印出 
        		Sleep(1000);            			//延遲一秒--每個倒數時間間隔一秒 
    		}
    		k++;
		}
		cout<<endl;
    	cout<<"按任一鍵結束程式"<<endl;
   		system("pause > nul");           		//按任一鍵結束程式 
   		cout<<endl;
	}
	for(int i=0;i<t;i++){
		cout<<"Pomodoro "<<i+1<<"		"<<content[finish[i]-1]<<'\n';
	} 
	float last=ff/w;
	cout<<"進度："<<setw(4)<<last*100<<"%"<<endl; 
    return 0;
}
