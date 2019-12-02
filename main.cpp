#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  //Definitions
  int N, Q;
  std::string Msg0 = "How many Lines? ...\n";
  std::string Msg1 = "How many Queries? ...\n";
  std::vector<string> MsgsVector;
  MsgsVector.push_back(Msg0);
  MsgsVector.push_back(Msg1);

  // 
  std::cout << "Program Satarts...!\n";
  std::cout << MsgsVector.at(0).c_str();
  std::cin >> N;
  std::cout << MsgsVector.at(1).c_str();
  std::cin >> Q; 

  


  
  

  //Outputs
  std::cout << N << Q;


  }
