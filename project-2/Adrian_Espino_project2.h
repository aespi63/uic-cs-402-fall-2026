
// be sure to change FIRSTNAME and LASTNAME with your own first and last name
#ifndef Adrian_Espino_PROJECT2
#define Adrian_Espino_PROJECT2

#include <functional>
#include <string>
#include "sha256.h"

// function declarations
std::vector<unsigned int> birthday_attack_1(std::function<unsigned short(unsigned int)> hash_function);
std::vector<unsigned int> birthday_attack_2(std::function<unsigned short(unsigned int)> hash_function);
std::string merkle_commit(const std::vector<std::string>& list, std::function<std::string(std::string)> hash_function);
std::vector<std::pair<std::string,std::string>> merkle_open_position(const std::vector<std::string>& list, std::function<std::string(std::string)> hash_function, const unsigned int i);
int merkle_verify_position(const std::string root, const std::vector<std::pair<std::string, std::string>>& proof, std::function<std::string(std::string)> hash_function, const unsigned int i);
int merkle_verify_full(const std::string root, const std::vector<std::string>& list, std::function<std::string(std::string)> hash_function);


//Helpers
std::vector<unsigned int> floyd_collision(std::function<unsigned short(unsigned int)> hash_function, unsigned int start);
std::string merkle_commit_range(const std::vector<std::string>& list, std::function<std::string(std::string)> hash_function, unsigned int start, unsigned int end);
void merkle_open_helper(const std::vector<std::string>& list, std::function<std::string(std::string)> hash_function, unsigned int start, unsigned int end, unsigned int i, std::string side, std::vector<std::pair<std::string,std::string>>& proof);

#endif
