#ifndef coder_h
#define coder_h
#include<string>
#include<unordered_map>

extern std::unordered_map<std::string, std::string> binary_dest_values;
extern std::unordered_map<std::string, std::string> binary_comp_values;
extern std::unordered_map<std::string, std::string> binary_jmp_values;
void init_coder_instructions();
std::string get_dest_binary(std::string &symbol);
std::string get_comp_binary(std::string &symbol);
std::string get_jump_binary(std::string &symbol);
#endif