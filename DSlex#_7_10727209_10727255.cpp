// 10727209 王冠勛 10727255 周子騰
#include <iostream>      // cin,cout,endl
#include <iomanip>       // setw ( make the space length same )
#include <string>        // c_str,length
#include <cstdlib>       // strtoul, system  
#include <cmath>         // sqrt   
using namespace std ;
int getNum (int,int) ; 
int fSeries( int num )  ;              
void iterativeFib( int num ) ;
void iterativefactor ( unsigned long long num, unsigned long long & amount , unsigned long long & ans, unsigned long long & ans2 ) ;
void recursiveFib(int num, int & i, unsigned long long a, unsigned long long b, unsigned long long total, unsigned long long & amount ) ;
void recursivefactor( unsigned long long total, unsigned long long & temp, unsigned long long & amount, bool & finded ) ;
void check( unsigned long long total, unsigned long long  temp, unsigned long long  amount, bool finded ) ;
void check2( unsigned long long total, unsigned long long  & temp, unsigned long long  & amount, bool & finded ) ;
int main(void) {
    int num, i = 1 ;
	unsigned long long total, amount ;
	unsigned long long a = 0 ;
	unsigned long long b = 1 ;
    int small = 0, big = 100 ;
    int command = 0 ;
	
	do { 
	
		cout << endl << " Fibonacci Series Generator " ;
		cout << endl << " 0.Quit                     " ;
		cout << endl << " 1.Iterative generation     " ;
		cout << endl << " 2.Recursive generation     " ;
		cout << endl << "****************************" ;
		cout << endl << "Input a command ( 0 , 1 , 2 ) :" ;
		
		cin >> command ;
		switch ( command ) {
			case 0 : break ;
			case 1 : 
			    
	            num = getNum ( small, big ) ;
	            
			    iterativeFib( num ) ;
				
				break ;
			case 2 :  
			    num = getNum ( small, big ) ;
			    
				recursiveFib(num, i,  a,  b,  total, amount ) ;
				break ;

				
				
				
			default : cout << "Command does not exist ! "  << endl ;
			        
		} // end switch
	} while ( command != 0 ) ; // 在command不是為0的情況下做以上的事 
	
	system("pause") ;  
	return 0 ;
  
  
} // main


int getNum (int minNum , int maxNum ) {
	int temp ;
	string inputS ;
	bool isNum ;
	
	do {
		cout << endl << "Input a number : " ;
		cin >> inputS ;
		isNum = true ;
		for ( int i = 0 ; ( i < inputS.length() ) && (isNum) ; i ++ ) // 一個一個字元檢查是否為數字 
			if ( ('0' > inputS[i]) || (inputS[i] > '9') ) 
				isNum = false ;
				
		if ( ! isNum )
			continue ; // 如果字串非數字時繼續 
		temp = strtoul(inputS.c_str(), NULL, 10 ) ; // 將字串轉為十進位 
		if( (temp >= minNum) && (temp <= maxNum) ) 
			break ;
	} while(true) ;
	
	
	return temp ;
} // getNum 判斷出input是否為數字之字串 是的話轉為數字 

void iterativeFib( int num ) {
	unsigned long long temp, small = 0, big = 0 ;
    unsigned long long n = 0 ;
    int i = 0 ;
	unsigned long long a = 0, b = 1 ;
	for ( i = 1 ; i <= num ; i++ ) {
		
    	temp = a + b ; 
      	a = b ;
      	b = temp ;
      	cout << "[  "<< i << "]" ; // 第幾個費式數列
      	cout << temp << "=" ;
    	iterativefactor (temp, n, small, big) ;


     }
    cout << "<Outter loop : " << i - 2  << " times>" << endl ;

} // iterativeFib() 利用迴圈計算費氏數列 

void iterativefactor ( unsigned long long num, unsigned long long & amount , unsigned long long & ans, unsigned long long & ans2 ) {
	amount = 1 ;
    unsigned long long temp = sqrt( num ) ; // 求這個數的根號 並且從中間開始找因子 
 	while ( (num%temp)!= 0 ) {
  		temp -= 1 ;
  		amount++ ;
    } // 檢驗哪些是因數 
  
  
 	ans = temp ;
  	ans2 = num/ans;
  	cout << ans << " * " << ans2 ;
  	cout << "(Inner loop : " << amount << "times)" << endl ; 
} // iterativefactor() 利用迴圈計算最接近的因子 


void recursiveFib(int num, int & i, unsigned long long a, unsigned long long b, unsigned long long total, unsigned long long & amount ) {
	unsigned long long inner = 0 ;
	unsigned long long temp, number = 0 ;
    
	if ( i > num ) { //直到找出所有的費氏數列 
		cout << "(Outer recursion : " << i - 1<< " times)" << endl ;
		i = 1 ;
	}
	
	else {
    	
		
    	temp = a + b ;
      	a = b ;
      	b = temp ;
      	cout << "[  "<< i << "]" ;
      	cout << temp << "=" ;
      	i++ ;
      	check( temp, 0, inner, false ) ; // 找出費氏數列時 將因子給找出並印出
        return recursiveFib( num, i, a, b, total, amount ) ;  


     }
     
		
	} // recursiveFib() 以遞迴計算費氏數列 
	

void check( unsigned long long total, unsigned long long  temp, unsigned long long  amount, bool finded ) { // 需要以兩個遞迴來分擔次數 以免程式跑到一半跳出 
	unsigned long long num = 0 ;
	if ( finded == true) {
		cout << "        (Inner recursion :    " << amount << " times)" << endl ;
    }
    else {
    	check2( total, temp, num, finded ) ;
    	amount = amount + num ;
    	num = 0 ;

    	return check( total, temp, amount, finded ) ;
    	
	}
  
  	
} 


void check2( unsigned long long total, unsigned long long  & temp, unsigned long long  & amount, bool & finded ) { // 需要以兩個遞迴來分擔次數 以免程式跑到一半跳出 
	unsigned long long num = 0 ;
	if ( finded == true) {
		;
    }
    else {
    	recursivefactor (total, temp, num, finded) ;
    	amount = amount + num ;
    	num = 0 ;
        if ( amount > 300000)
            ;
        else  
    		return check2( total, temp, amount, finded ) ;
    	
	}
  
  	
} 

void recursivefactor( unsigned long long total, unsigned long long & temp, unsigned long long & amount, bool & finded ) {
	
	unsigned long long ans, ans2 ;
	if ( temp == 0)
	  temp = sqrt( total ) ; // 在第一次進function時將數開根號並且從中間向下找因子 
	if ( total % temp == 0 ) {
	    ans = temp ;
		ans2 = total / ans ;
		amount++ ;
		finded = true ;
		cout << ans << " * " << ans2 ;
		
	}
	else if ( amount < 20000){
		temp-- ; 
		amount++ ;
		if ( total % temp == 0 ) 
			finded = true ;
		return recursivefactor( total, temp, amount, finded ) ;
		
	}
	
	
} // recursivefactor() 以遞迴計算出最接近的因子 

	
	
	
