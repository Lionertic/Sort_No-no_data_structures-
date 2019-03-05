#include <stdio.h>
#include <iostream>
using namespace std;

int final, flag = 0;
int power_ten(int pow)
{
  int result=1;
  while (pow != 0) {
        result *= 10;
        --pow;
    }
    return result;
}
int size_of (int n)
{
  int i=0;
  while (n!=0){
      n /= 10;
      ++i;
  }
  return i;
}

void rearrange (int no, int ind)
{

  int temp = final, s = 0, r;

  for (int j = 0; j < ind; j++){
      r = temp % 10;
      temp /= 10;
      s = s + r * power_ten(j);
  }

  temp *= 10;
  temp += no;

  if(s!=0){
    int n = size_of (s);
    temp = temp *power_ten(n);
  }
  temp += s;
  final = temp;
}

void arrange (int no)
{
  if (flag == 0){
      final = no;
      flag = 1;
  }
  else{
      int temp, j=0,r;
      temp = final;
      while (temp !=0){
	       r = temp % 10;
	       temp /= 10;
	         if (r >= no)
	            j++;
	         else{
	             rearrange (no, j);
	             return;
             }
	    }
      rearrange (no, j);
    }
}

int main ()
{
  int i, temp, r, q;
  cout<<"Enter the number to sort(int size)"<<endl;
  cin >> i;
  temp = i;
  while (temp !=0 ){
      r = temp % 10;
      temp /= 10;
      arrange (r);
  }
  cout <<"Sorted No is"<<final;
  return 0;
}
