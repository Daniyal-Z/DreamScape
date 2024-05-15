#ifndef USERPASS_H
#define USERPASS_H
#include <iostream>

bool checkUsername(const std::string& username);
bool checkPassword(const std::string& username, const std::string& password);
int newUser(const std::string& username, const std::string& password);
bool forgotPassword(const std::string& username, const std::string& newPassword);

#endif // USERPASS_H
