#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

// isValidScriptLine funtion to detect is a script line is valid
bool isValidScriptLine(std::string LCodeLine) {
  if (LCodeLine.front() == '<' &&
      LCodeLine.back() == '>') {
        std::cout << "Valid script line!\n";
        return true; 
  } else {
    std::cout << "Invalid script line!\n";
    return false; 
  }
}


int main() {
  //Definitions

  int N, Q;
  int i = 0;
  // User input 
  std::string Msg0 = "How many Lines? ...";
  std::string Msg1 = "How many Queries? ...";
  std::vector<string> MsgsVector;
  MsgsVector.push_back(Msg0);
  MsgsVector.push_back(Msg1);
  
  //Code Vector
  std::vector<string> CodeVector;
  std::string CodeLine;

  // Body 
  std::cout << "Program Satarts...!" << std::endl;
  std::cout << MsgsVector.at(0).c_str() << std::endl;
  std::cin >> N;
  std::cout << MsgsVector.at(1).c_str() << std::endl;
  std::cin >> Q; 

  std::cout << "Capture your script lines..." << std::endl;

  while (i < N) {
    std::getline(std::cin, CodeLine);
    if (!CodeLine.empty()){
      CodeVector.push_back(CodeLine);
      i++;
    }
  }

  i = 0;

  while (i < N) {
    isValidScriptLine(CodeVector.at(i));
    i++;
  }
  
  



  
  //Outputs
  std::cout << "Inputs: \n N =" << N << "\n Q =" << Q << std::endl;
  i = 0;
  while (i < N) {
    std::cout << CodeVector.at(i) << std::endl;
    i++;
  }
  
  }
