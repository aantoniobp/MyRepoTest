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
      LCodeLine.back() == '>') {
        //std::cout << "Valid script line!\n";
        return true; 
  } else {
    std::cout << "Invalid script line!\n";
    return false; 
  }
}

// numwordsLine function to count the number of words in a script line
unsigned numWordsLine (std::string LCodeLine){
  //
  unsigned count = 0;
  std::stringstream strm(LCodeLine); 
  std::string strword;
  std::vector <string> str_vect;
  //std::cout << strm.str() << std::endl;
  while (strm >> strword ) {
    //std::cout << strword << std::endl;
    //count++;
    str_vect.push_back(strword);
  }
  /*int state = OUT;
  unsigned count = 0; 
  const char* LCodeLineStr = LCodeLine.c_str();
  while (*LCodeLineStr) {
    //
    if (*LCodeLineStr == ' ')
    state = OUT;
    else if (state == OUT) {
      //
      state = IN;
      ++count;
    }
    ++LCodeLineStr;
  }*/
  return str_vect.size(); 

}


bool isOpeningLine(std::string LCodeLine){
  // 
  if (isValidScriptLine(LCodeLine)) {
    //delete first and last characters
    LCodeLine.erase(LCodeLine.begin());
    LCodeLine.pop_back();
    std::cout << " Number of words in line: " << numWordsLine(LCodeLine) << std::endl;


  }
  return false;
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
    isOpeningLine(CodeVector.at(i));
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
