//Queue Cyclic

#include <iostream>

using namespace std;

class Queue{
   int *Q ,H,T,Size,Count=0;
   public:
       int getCount(){return Count;}
       int getTCount(){return T;}
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
    else if( (IsFull()==true) && H!=0){  //queue still empty but the front of queue empty
            int d=Count-T;
            Q[Count-T]=value;
        }

  else cout<<"Queue is Full"<<endl;
}

int Queue::DeQ(){
   if(!IsEmpty()){
    return Q[H++];
    }
    else if (IsFull()==true && H!=0){

        return Q[Count-T--];
    }

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

   cout<<"start of for"<<endl;
   for(int i=0;i<5;i++){

    cout<<q1.DeQ()<<endl;
   }
    cout<<"End of for"<<endl;

   cout<<q1.Peak()<<endl;



    return 0;
}
