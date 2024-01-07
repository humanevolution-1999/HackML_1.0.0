#ifndef symbol_table_h
#define symbol_table_h
#include<string>
#include<unordered_map>
extern std::unordered_map<std::string,int>internal_symbol;
extern std::unordered_map<std::string,int>variable_table;
extern std::unordered_map<std::string,int>label_table;
extern int curr_uninit_memory_address;
void init_internal_symbol();
std::string get_internal_symbol(std::string &symbol);
bool is_internal_symbol(std::string &symbol);
bool is_external_symbol_defined(std::string &symbol);
bool is_label_symbol_defined(std::string &symbol);
void add_variable_symbol(std::string &symbol);
void add_label_symbol(std::string &symbol, int value);
std::string get_variable_symbol(std::string &symbol);
std::string get_label_symbol(std::string &symbol);
std::string get_constant_binary(std::string &symbol);
#endif