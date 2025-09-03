#include<iostream>
using namespace std;

#define size 100

class Queue
{
string arr [size] ;
int front,rear;

public:
Queue()

{
front = 0;
rear = -1;
}

void enqueue (string x)
{ if
(rear== size-1)
{cout<<"queue overflow"<<endl;

return;
}


arr[++rear] = x;


}


string dequeue()
{
if (front>rear)
{cout<<"queue underflow"<<endl;
return" ";
}

return arr[front++];

}



bool isempty(){
return (front>rear);
}


bool isfull()
{ return rear =size-1;
}

};
void binary(int n)
{
Queue q;
q.enqueue("1");

for(int i=1; i<=n; i++)
 {string s = q.dequeue();

 cout<<s;
 if(i<n) cout<<"," ;
 q.enqueue (s+"0");
 q.enqueue (s+"1");
}
}

int main()
{
int n ;
cin>>n;
binary(n);
return 0;
}




