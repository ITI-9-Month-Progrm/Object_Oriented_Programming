#include <iostream>

using namespace std;

class intArray{
    int *arr,Size;
public:
    int getSize(){return Size;}
    ///Constructors
    intArray(int L=5){
     Size=L;
     arr=new int[Size];
    }
   ///Copy Constructor
   intArray(const intArray &oldArr){
     Size=oldArr.Size;
     arr=new int[Size];
     for(int i=0;i<Size;i++)
        arr[i]=oldArr.arr[i];
   }
   ///Deconstructor
   ~intArray(){delete [] arr;}

   intArray& operator = (intArray &Right){
      Size=Right.Size;  ///arr2 is this
      delete [] arr;
      arr=new int[Size];
      for(int i=0;i<Size;i++){
        arr[i]=Right.arr[i];
      }

     return *this;
   }

   int & operator[](int index){    ///in case of not & with cin return Error
       if((index>=0) && (index<Size))
         return arr[index];}
intArray operator +(  intArray& a2)
{
  intArray a;
  for (int i = 0; i < Size; i++)
    a[i] = arr[i] + a2[i];
  return a;
}



    };


int main()
{

    intArray arr1(3),arr2;
    cout<<"Please Enter Values of Element arr1"<<endl;
    int s=arr1.getSize();
    for(int i=0;i<s;i++){
       cin>>arr1[i];
   }
   arr2=arr1;
   cout<<"Displaying Values of Element arr2"<<endl;
   for(int i=0;i<s;i++){
    cout<<arr2[i]<<endl;
   }
   intArray arr3=(arr1+arr2);     /// i have some problem her --> when i write arr3=arr1+arr2 cause error with = operator
   int sizeArr=arr1.getSize();
   cout<<"Displaying Values of Element arr3"<<endl;
   for (int i = 0; i < sizeArr; i++)
    cout << arr1[i] << '+' << arr2[i] << '=' << arr3[i] << ' '<<endl;


    return 0;
}
