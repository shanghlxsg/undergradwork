#include <bits/stdc++.h>
using namespace std;

int main() {
    int T,diff;
    unsigned long long A,median,tempmedian,maxsize,minsize;
    priority_queue<unsigned long long, vector<unsigned long long>> max;
    //max heap for smaller half
    priority_queue<unsigned long long, vector<unsigned long long>, greater<unsigned long long> > min;
    //min heap for bigger half
    
    cin>>T; //get number of test cases
    
    for(int i=0;i<T;i++){ //for each test case
        cin>>N; //get number of integers in this test case
        //reset values for each test case
        median=0;
        maxsize=0; //size of max heap s
        minsize=0; //size of min heap b
        while(!max.empty()){
          max.pop();
        }
        while(!min.empty()){
          min.pop();
        }
        //take in first integer A
        cin>>A;
        max.push(A);
        maxsize++;
        median=A; //first median
        
        for(unsigned long long j=1;j<size;j++){
            cin>>A;
            //allocate integer A to heap
            if(A<=max.top()){
                max.push(A);
            	maxsize++;
            }else{
                min.push(A);
            	minsize++;
            }

            diff=maxsize-minsize;
            //balance min and max heap sizes
            if(diff==2){
                min.push(max.top());
                minsize++;
                max.pop();
                maxsize--;
            }else if(diff==-2){
                max.push(min.top());
                maxsize++;
                min.pop();
                minsize--;
            }
            
            //calculate median
            if(j%2){
                tempmedian=(max.top()+min.top())/2;
            }else{
                if(maxsize<minsize){ //median in min heap
                    tempmedian=min.top();
                }else{ //median in max heap
                    tempmedian=max.top();
                }
            }
            median+=tempmedian;
        } //end of for loop

        cout<<median<<endl;
    }
    return 0;
}