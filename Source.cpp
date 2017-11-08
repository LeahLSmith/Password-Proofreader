#inlcude"PasswordProofreader.h"

int main(){
    std::cout << "Welcome to Password Proofreader v1.\nFirst, set your password specifications." << endl;
    Proofreader p;
    p.defineSpecifications();
    p.tryPassword();

    return 0;
}