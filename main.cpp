#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>

#define OUT 0
#define IN 1

using namespace std;

// isValidScriptLine funtion to detect is a script line is valid
bool isValidScriptLine(std::string LCodeLine) {
  if (LCodeLine.front() == '<' &&
      LCodeLine.back() == '>' &&
      LCodeLine.size() > 2) {
        //std::cout << "Valid script line!\n";
        return true; 
  } else {
    std::cout << "Invalid script line!\n";
    return false; 
  }
}

// stringLine2Vect function to convert a script line from string to vector
vector <string> stringLine2Vect(std::string LCodeLine){
  //
  unsigned count = 0;
  std::stringstream strm(LCodeLine); 
  std::string strword;
  std::vector <string> str_vect;
  while (strm >> strword ) {
    str_vect.push_back(strword);
  }
  return str_vect; 
}


bool isOpeningLine(std::string LCodeLine){
  // 
  vector <string> LCodeLineVect;
  vector <string> LCodeLineVectTmp;
  bool flag = false;
  if (isValidScriptLine(LCodeLine)) {
    //delete first and last characters
    LCodeLine.erase(LCodeLine.begin());
    LCodeLine.pop_back();
    LCodeLineVect = stringLine2Vect(LCodeLine);
    
    //Store and delete tag-name
    LCodeLineVect.erase(LCodeLineVect.begin());
    
    if (LCodeLineVect.size() >= 3) {
      //
      for (int i = 0;i < 3; i++) {
      LCodeLineVectTmp.push_back(LCodeLineVect.front());
      LCodeLineVect.erase(LCodeLineVect.begin());
      }
      if (LCodeLineVectTmp.at(1) == "=")
      flag = true; 
      
    }
    else
      //String is not longer enought to be a valid opening line , it has to be 1 or greater that 3
      flag = false;
    

  }
  return flag;
}



//bool isClosingLine(std::string LCodeLine)


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
    if (!CodeLine.empty() && (isValidScriptLine(CodeLine))){
      CodeVector.push_back(CodeLine);
      i++;
    } 
  }

  i = 0;

  while (i < N) {
    //isValidScriptLine(CodeVector.at(i));
    if (isOpeningLine(CodeVector.at(i))) {
      std::cout << "Line is open line" << std::endl;
    } else 
      std::cout << "Line is not open line" << std::endl;
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
