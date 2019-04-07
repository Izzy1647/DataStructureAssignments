//
//  main.cpp
//  利息计算
//
//  Created by zzy on 2018/12/10.
//  Copyright © 2018 zzy. All rights reserved.
//
#include <iostream>
#define ERROR -1

float balance=1000000;//余额
long start_year;//开始年份
long end_year;//结束年份
int a;
using namespace std;
//是否为活期存款
bool is_current_deposit(){
    cout<<"is it a current deposit or not? yes:1 no:0"<<endl;
    cin>>a;
    if (a==1) return 1;
    else return 0;
}
//计算有效年份函数
float judge_year_number(long startyear,long endyear){
    long delta;
    delta=endyear-startyear;
    if(delta<0){
        return ERROR;
    }
    else if(delta==0){
        return 0;
    }
    else if(delta%10000==0){
        return delta/10000;
    }
    else{
        return int(delta/10000)+0.5;
    }
}
//计算利息
float calculate_interest(float years){
    float interest;//利息
    if (is_current_deposit()==1){
        interest=years*balance*0.0035;
    }
    if(is_current_deposit()==0){
        if(years==1){
            interest=balance*years*0.0275; //一年期
        }
        else if(years>1&&years<=2){
            interest=balance*0.0275+(balance+balance*0.0275)*(years-1)*0.0335;
        }
        else if(years>2){
            interest=balance*0.0275+(balance+balance*0.0275)*0.0335+(balance*0.0275+(balance+balance*0.0275)*0.0335+balance)*(years-2);
        }
    }
    return interest;
}
int main(int argc, const char * argv[]) {
    cout<<"input the start year and the end year"<<endl;
    cin>>start_year>>end_year;
    cout<<calculate_interest(judge_year_number(start_year, end_year));
   
    return 0;
}
