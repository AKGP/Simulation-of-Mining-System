#include <iostream>
#include <random>
#include <chrono>
#include <vector>
using namespace std;
int main(int, char*[]) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    std::default_random_engine generator (seed);

    std::uniform_real_distribution<double> distribution (0.0,1.0);


    int H[50]={0},T[50]={0},interval = 10;
    double Values[500];
    for (int i=0; i<500;i++){
      Values[i] = distribution(generator);
    }

    for(int i =0;i<500;i+=interval){
      for(int j =0;j<i;j++){
        if(Values[j]>0.5){
          H[j/interval]+=1;
        }
        else{
          T[j/interval] +=1;
        }
      }
    }
    cout<<"Head,Tail,P(H),P(T)"<<endl;
    for (int i=49; i>=0;i--){
      cout<<H[i]<<","<<T[i]<<","<<float(H[i])/float(H[i]+T[i])<<","<<float(T[i])/float(H[i]+T[i])<<endl;
    }
  return 0;
}