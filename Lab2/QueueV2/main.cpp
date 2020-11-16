//Queue with Shifting

#include <iostream>

using namespace std;

class Queue{
   int *Q ,H,T,Size,Count=0;
   public:

       int getTail(){return T;}
       Queue(int length){
           cout<<"Constructor"<<endl;
           Size=length;
           H=0;
           T=0;
           Q=new int [Size];}
       ~Queue(){cout<<"Object is Ended"<<endl;delete []Q;}
       int IsFull(){return Count==Size;}
       int IsEmpty(){return Count==0;}
       void EnQ(int value);
       int DeQ();
       int Peak();
};

void Queue::EnQ(int value){
  if(IsFull()==false){  //queue still empty and the front of queue full
        Q[T++]=value;
        ++Count;
    }



  else cout<<"Queue is Full"<<endl;
}

int Queue::DeQ(){
    int res;
   if(!IsEmpty()){
      --Count;
     res=Q[0];
    //queue still empty but the front of queue empty
            H=0;
            for(int i=0;i<T;i++){
                Q[i]=Q[i+1];}
            --T;


    }
return res;
}

int Queue::Peak()
{
    return Q[T-1];

}

int main()
{
   Queue q1(5);
   q1.EnQ(1);
   q1.EnQ(2);
   q1.EnQ(3);
   q1.EnQ(4);
   q1.EnQ(5);
   cout<<q1.Peak()<<endl;
   cout<<q1.Peak()<<endl;
   cout<<q1.DeQ()<<endl;

   q1.EnQ(6);

   cout<<q1.Peak()<<endl;

    cout<<"start of for"<<endl;
   for(int i=0;i<4;i++){

    cout<<q1.DeQ()<<endl;
   }
    cout<<"End of for"<<endl;

   cout<<q1.Peak()<<endl;


    return 0;
}
