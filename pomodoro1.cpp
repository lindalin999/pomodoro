#include<bits/stdc++.h> 
#include<conio.h>
#include <windows.h>
using namespace std;
int main(){
	float t,ff=0,w;							//宣告t番茄鐘個數、ff完成件數、w工作件數 
	float studytime,resttime;				//宣告每個番茄鐘的工作時長、休息時長
	float total,finish[10]; 				//total完成%數、每個工作進度%
	string content[10];						//欲完成工作內容 
	int timee[10],im[10];
	
	cout<<"1.設定番茄鐘"<<endl;
	cout<<"請依序設定番茄鐘個數、每個番茄鐘的工作時長、休息時長："<<endl;
	cin>>t>>studytime>>resttime;
	int ssec=studytime*60; 				//轉換成秒數，方便後面計時器運行 
	int rsec=resttime*60;
	cout<<endl;
	
	cout<<"2.To-do list"<<endl;
	cout<<"請輸入工作件數： "; 
	cin>>w;
	cout<<"請依編號輸入工作內容、預計花費番茄鐘個數，並輸入重要程度(1-5)："<<endl;
	for(int i=0;i<w;i++){
		cout<<"task "<<i+1<<":";		//事先將每項工作編號，方便後續操作 
		cin>>content[i]>>timee[i]>>im[i];
	} 
	cout<<endl;

	 
	cout<<"----計時開始請按下鍵盤上的's'----"<<endl;
	if(getch()=='s'){
		for(int k=0;k<t;k++){						//k紀錄目前到第幾個番茄鐘
			/*工作時間*/ 
			for(int i=ssec;i>=0;i--){
        		cout <<"Pomodoro "<<k+1<<"--剩餘時間："<<setw(3)<<i/60<<"："<<setw(2)<<i%60;		//set函式限制計時器顯示位數 
        		cout << string(100,'\b');           //退格，以免重複印出 
        		Sleep(1000);            			//延遲一秒--每個倒數時間間隔一秒 
    		}
    		cout<<"請問完成工作件數、編號及進度(%)"<<endl;
    		cin>>a;
    		for(int i=0;i<a;i++){
    			cin>>b; 
			}
			cout<<endl;

    		/*休息時間*/ 
    		for(int i=rsec;i>=0;i--){
        		cout <<"Rest time "<<k+1<<"--剩餘時間："<<setw(3)<<i/60<<"："<<setw(2)<<i%60;
        		cout << string(100,'\b');          
        		Sleep(1000);            		
    		}			
			cout<<endl;							//一輪循環結束--繼續下一個循環 
		}
		
		cout<<endl;
    	cout<<"按任一鍵結束程式"<<endl;
   		system("pause > nul");           			//按任一鍵結束程式 
   		cout<<endl;
	}
	cout<<endl; 

	for(int i=0;i<w;i++){
		total+=finish[i];
		total=total/w;
	} 
	cout<<"完成進度："<<total<<endl; 
    return 0;
}

/*#include<bits/stdc++.h> 
#include<conio.h>
#include <windows.h>
using namespace std;
int main(){
	float t,ff=0,w;			//t番茄鐘個數、ff完成件數、w工作件數 
	float studytime,resttime;	//番茄鐘的工作時長、休息時長
	int finish[55];			//每個番茄鐘所完成的工作 
	string content[55];		//欲完成工作內容 
	
	cout<<"1.設定番茄鐘"<<endl;
	cout<<"請依序設定番茄鐘個數、每個番茄鐘的工作時長、休息時長："<<endl;
	cin>>t>>studytime>>resttime;
	int ssec=studytime*60; 				//轉換成秒數，方便後面計時器運行 
	int rsec=resttime*60;
	cout<<endl;
	
	cout<<"2.To-do list"<<endl;
	cout<<"請輸入工作件數： "; 
	cin>>w;
	cout<<"請依編號輸入工作內容："<<endl;
	for(int i=0;i<w;i++){
		cout<<"task "<<i+1<<":";		//事先將每項工作編號，方便後續使用者紀錄工作進度 
		cin>>content[i];
	} 
	cout<<endl;
	 
	cout<<"----計時開始請按下鍵盤上的's'----"<<endl;
	if(getch()=='s'){
		for(int k=0;k<t;k++){
			/*工作時間*/ 
			for(int i=ssec;i>=0;i--){
        		cout <<"Pomodoro "<<k+1<<"--剩餘時間："<<setw(3)<<i/60<<"："<<setw(2)<<i%60;		//setw函式限制計時器顯示位數 
        		cout << string(100,'\b');        //退格，以免重複印出 
        		Sleep(1000);			 //延遲一秒--每個倒數時間間隔一秒 
    		}
    		/*登記工作進度*/ 
    		cout<<"請輸入在這個番茄鐘中你所完成的工作編號：(若無請輸入'0')"<<endl;
    		cin>>finish[k];
    		if(finish[k]!=0) ff++;			//代表當次番茄鐘有完成任務 
    		/*休息時間*/ 
    		for(int i=rsec;i>=0;i--){
        		cout <<"Rest time "<<k+1<<"--剩餘時間："<<setw(3)<<i/60<<"："<<setw(2)<<i%60;
        		cout << string(100,'\b');          
        		Sleep(1000);            		
    		}			
			cout<<endl;			//一輪循環結束--繼續下一個循環 
		}
		
		cout<<endl;
    	cout<<"按任一鍵結束程式"<<endl;
   		system("pause > nul");           	//按任一鍵結束程式 
   		cout<<endl;
	}
	cout<<endl; 
	for(int i=0;i<t;i++){
		if(finish[i]>=1) cout<<"Pomodoro "<<i+1<<"---------- "<<content[finish[i]-1]<<endl;
		else cout<<"Pomodoro "<<i+1<<"---------- X "<<endl;
	} 
	float last=ff/w;
	cout<<"進度："<<setw(4)<<last*100<<"%"<<endl; 	//將進度轉換成%後輸出 
    return 0;
}
*/
