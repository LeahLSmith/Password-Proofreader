#include<string>
#include<iostream>

struct UserInformation{
string username;
string pw;
};

class Proofreader {
public:
    Proofreader();
    ~Proofreader();

    //getters
    int getCharsRequired();
    int getLettersRequired();
    int getNumbersRequired();
    int getSymbolsRequired();
    //setters
    void setCharsRequired(int c);
    void setLettersRequired(int l);
    void setNumbersRequired(int n);
    void setSymbolsRequired(int s);
    //define required password components
    void defineSpecifications(); // 1. Ask for specifications for character counts.

    bool retrievePassword(); // 2. Get user password and scan input (inline MASM).
    void tryPassword(); // engine that keeps trying new passwords until it is accepted
    string showErrors(); // 3. Show errors (if any).
    void storeInDatabase(); // 5. Store in database.

private:
    UserInformation userInfo;

    int numCharsRequired,
    numLettersRequired,
    numNumbersRequired,
    numSymbolsRequired;

    int specifications[4];

    bool passwordAccepted;
    string errorMsg;
};

Proofreader::Proofreader(){

    userInfo.username = "";
    userInfo.pw = "";
    
    int numCharsRequired,
    numLettersRequired,
    numNumbersRequired,
    numSymbolsRequired = 0;

    passwordAccepted = true;
    errorMsg = "";
}

Proofreader::~Proofreader(){}

int Proofreader::getCharsRequired(){
    return specifications[0];
}
int Proofreader::getLettersRequired(){
    return specifications[1];
}
int Proofreader::getNumbersRequired(){
    return specifications[2];
}
int Proofreader::getSymbolsRequired(){
    return specifications[3];
}

void Proofreader::setCharsRequired(int c){
    specifications[0] = c;
}
void Proofreader::setLettersRequired(int l){
    specifications[1] = l;
}
void Proofreader::setNumbersRequired(int n){
    specifications[2] = n;
}
void Proofreader::setSymbolsRequired(int s){
    specifications[3] = s;
}

// 1. Ask for specifications for character counts.
void Proofreader::defineSpecifications(){
    std::cout << "Number of characters required: ";
    std::cin >> numCharsRequired;
    std::cout << "\nNumber of letters required: ";
    std::cin >> numLettersRequired;
    std::cout << "\nNumber of numbers required: ";
    std::cin >> numNumbersRequired;
    std::cout << "\nNumber of symbols required: ";
    std::cin >> numSymbolsRequired;
    
   setCharsRequired(numCharsRequired);
   setLettersRequired(numLettersRequired);
   setNumbersRequired(numNumbersRequired);
   setSymbolsRequired(numSymbolsRequired);
    } 

// 2. Get user password and scan input (inline MASM).
bool Proofreader::retrievePassword(){
    //inline MASM here

    int totalChars,
    totalLetters,
    totalNumbers,
    totalSymbols;

    if (totalChars < getCharsRequired()){
        passwordAccepted = false;
        errorMsg += "* not enough total characters\n";
    } else if (totalLetters < getLettersRequired()){
        passwordAccepted = false;
        errorMsg += "* not enough letters\n";        
    } else if (totalNumbers < getNumbersRequired()){
        passwordAccepted = false;
        errorMsg += "* not enough numbers\n";        
    } else if (totalSymbols < getSymbolsRequired()){
        passwordAccepted = false;
        errorMsg += "* not enough symbols\n";
    }
    return passwordAccepted;
}

// 3. Show errors (if any).
string Proofreader::showErrors(){
    if (retrievePassword()){
        std::cout << "Password accepted." << endl;
    } else {
        std::cout << "Password not accepted. Error(s) found: \n" << errorMsg << "\nPlease try another password." << endl;
        errorMsg = ""; // reset error message for next try
    }
}

//4. Repeat steps 2 and 3 until password is accepted. (while loop)
void Proofreader::tryPassword(){
    do {
        retrievePassword();
        showErrors();
    }while (retrievePassword == false); // pw not accepted
}

