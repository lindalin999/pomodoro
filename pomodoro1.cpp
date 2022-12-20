#include<bits/stdc++.h> 
#include<conio.h>
#include <windows.h>
using namespace std;
int main(){
	
	float t=0,w;				//t番茄鐘個數 w工作件數 
	float studytime,resttime;		//宣告每個番茄鐘的工作時長、休息時長
	float total; 				//total最後完成%數
	string content[10];			//content欲完成工作內容 
	int im[10];				//重要程度
	
	cout<<"1.設定番茄鐘"<<endl;
	cout<<"請設定每個番茄鐘的工作時長、休息時長："<<endl;
	cin>>studytime>>resttime;
	int ssec=studytime*60; 					//轉換成秒數，方便後面計時器運行 
	int rsec=resttime*60;
	cout<<endl;
	
	cout<<"2.To-do list"<<endl;
	cout<<"請輸入工作件數： "; 
	cin>>w;
	cout<<"請依編號輸入工作內容、重要程度："<<endl;
	for(int i=0;i<w;i++){
		cout<<"task "<<i+1<<":";			
		cin>>content[i]>>im[i];
		t=t+im[i];
	} 
	cout<<endl;
	
	for(int i=0;i<w;i++){					//泡沫排序法(由時長小到大排先後順序) 
		for(int j=i+1;j<w;j++){
			if(im[i]>im[j]){
				swap(content[i],content[j]);
			}
		}
	}
	cout<<"建議順序"<<endl;
	for(int i=0;i<w;i++){
		cout<<"List "<<i+1<<"："<<content[i]<<endl;
	}
	cout<<endl;
	
	cout<<"----計時開始請按下鍵盤上的's'----"<<endl<<endl;
	if(getch()=='s'){
		for(int k=0;k<t;k++){						//k紀錄目前到第幾個番茄鐘
			/*工作時間*/ 
			for(int i=ssec;i>=0;i--){
        		cout <<"Pomodoro "<<k+1<<"--剩餘時間："<<setw(3)<<i/60<<"："<<setw(2)<<i%60;		//set函式限制計時器顯示位數 
        		cout << string(100,'\b');           //退格，以免重複印出 
        		Sleep(1);            			//延遲一秒--每個倒數時間間隔一秒 
    		}

    		/*休息時間*/ 
    		for(int i=rsec;i>=0;i--){
        		cout <<"Rest time "<<k+1<<"--剩餘時間："<<setw(3)<<i/60<<"："<<setw(2)<<i%60;
        		cout << string(100,'\b');          
        		Sleep(1);            		
    		}			
			cout<<endl;								//一輪循環結束--繼續下一個循環 
		}
		
		cout<<endl;
    	cout<<"按任一鍵結束程式"<<endl;
   		system("pause > nul");           			//按任一鍵結束程式 
   		cout<<endl;
	}
	cout<<endl; 

	int y=0;
	for(int i=0;i<w;i++){
		cout<<"List "<<i+1<<"："<<content[i]<<" 是否完成?(請用y/n回答)"<<endl;
		if(getch()=='y') y++;
		else if(getch()=='n') y+=0;
	} 
	cout<<endl<<"完成進度："<<setw(4)<<(y/w)*100<<"%"<<endl;
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
			 
			for(int i=ssec;i>=0;i--){
        		cout <<"Pomodoro "<<k+1<<"--剩餘時間："<<setw(3)<<i/60<<"："<<setw(2)<<i%60;		//setw函式限制計時器顯示位數 
        		cout << string(100,'\b');        //退格，以免重複印出 
        		Sleep(1000);			 //延遲一秒--每個倒數時間間隔一秒 
    		}
    		
    		cout<<"請輸入在這個番茄鐘中你所完成的工作編號：(若無請輸入'0')"<<endl;
    		cin>>finish[k];
    		if(finish[k]!=0) ff++;			//代表當次番茄鐘有完成任務 
    		
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
