#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int STYLE_VARIABLES_LENGTH = 5;

const string stylesPath = "styles.css";
const string userStyles[STYLE_VARIABLES_LENGTH] = {
  "--MAIN-COLOR", 
  "--MAIN-COLOR-ALT", 
  "--SECONDARY-COLOR", 
  "--TERTIARY-COLOR", 
  "--MAIN-FONT-FAMILY"
};

void ReadUserInput() {
  string userInput[STYLE_VARIABLES_LENGTH] = {
    "",
    "",
    "",
    "",
    ""
  };

  int counter = 0;
  string input;

  while (counter < STYLE_VARIABLES_LENGTH) {
    cin >> userInput[counter];
    cout << userInput[counter];

    counter ++;
  }
}

bool isRoot(string text) {
  if (text.find(":root") != string::npos) {
    return true;
  }

  return false;
}

void openStylesFile() {
  string text;
  ifstream stylesFile(stylesPath);
  bool isWithinRoot = false;
  
  while (getline (stylesFile, text)) {
    if (isRoot(text)) isWithinRoot = true;

    if (isWithinRoot) {
      if (text.find("}") != string::npos) {
        isWithinRoot = false;
        break;
      };
      cout << text;
    }
  }

  stylesFile.close();
}


int main() { 
  //ReadUserInput();
  openStylesFile();
  return 0;
}