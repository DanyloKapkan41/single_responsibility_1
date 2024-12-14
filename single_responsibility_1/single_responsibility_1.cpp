#include <iostream>
#include <string>
using namespace std;
// Клас для валідації даних користувача
class UserValidator {
public:
    bool validate(const string& username, const string& password) {
        return !username.empty() && password.length() >= 8;
    }
};

// Клас для збереження користувача
class UserManager {
public:
    explicit UserManager(UserValidator& validator) : validator(validator) {}

    void saveUser(const string& username, const string& password) {
        if (validator.validate(username, password)) {
            cout << "User saved: " << username << endl;
        }
        else {
            cout << "Invalid user data!" << endl;
        }
    }

private:
    UserValidator& validator;
};

int main() {
    string choice, name;
    UserValidator validator;
    UserManager userManager(validator);
    do {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter the password: ";
        cin >> choice;
        userManager.saveUser(name, choice);
    } while (choice != "exit");
    return 0;
}

/*
* 
* Без дотримання SRP:
Клас відповідає за декілька завдань:
* 
#include <iostream>
#include <string>

class UserManager {
public:
    void saveUser(const std::string& username, const std::string& password) {
        if (validateUser(username, password)) {
            std::cout << "User saved: " << username << std::endl;
        } else {
            std::cout << "Invalid user data!" << std::endl;
        }
    }

private:
    bool validateUser(const std::string& username, const std::string& password) {
        return !username.empty() && password.length() >= 8;
    }
};

*/