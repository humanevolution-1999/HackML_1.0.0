#include<string>
#include<algorithm>
#include<unordered_map>
#include<iostream>
#include "parser.h"
#include "symbol_table.h"
#define INSTRUCTION_SIZE 16
int curr_uninit_memory_address = 16;

//defines an unordered map to store internally defined symbols
std::unordered_map<std::string, int> internal_symbol;

//defines an unordered map to store user defined variables
std::unordered_map<std::string,int> variable_table;

//defines an unordered map to store label variables
std::unordered_map<std::string,int>label_table;

void init_internal_symbol()
{
    // Insert key-value pairs individually
    internal_symbol["R0"]=0;
    internal_symbol["R1"] = 1;
    internal_symbol["R2"] = 2;
    internal_symbol["R3"] = 3;
    internal_symbol["R4"] = 4;
    internal_symbol["R5"] = 5;
    internal_symbol["R6"] = 6;
    internal_symbol["R7"] = 7;
    internal_symbol["R8"] = 8;
    internal_symbol["R9"] = 9;
    internal_symbol["R10"] = 10;
    internal_symbol["R11"] = 11;
    internal_symbol["R12"] = 12;
    internal_symbol["R13"] = 13;
    internal_symbol["R14"] = 14;
    internal_symbol["R15"] = 15;
}


std::string to_binary(int val)
{
    std::string binary_var="";
    while(val>0)
    {
        int rem=val%2;
        char current_char= rem +'0';
        binary_var.push_back(current_char);
        val/=2;
    }
    while(binary_var.size()<16)
    {
        binary_var.push_back('0');
    }
    std::reverse(binary_var.begin(),binary_var.end());
    return binary_var;
}

bool is_internal_symbol(std::string &symbol)
{
    if(internal_symbol.find(symbol)!=internal_symbol.end())
        return true;
    return false;
}

std::string get_internal_symbol(std::string &val)
{
    if(val=="R0")
        return to_binary(0);
    else if(val=="R1")
        return to_binary(1);
    else if(val=="R2")
        return to_binary(2);
    else if(val=="R3")
        return to_binary(3);
    else if(val=="R4")
        return to_binary(4);
    else if(val=="R5")
        return to_binary(5);
    else if(val=="R6")
        return to_binary(6);
    else if(val=="R7")
        return to_binary(7);
    else if(val=="R8")
        return to_binary(8);
    else if(val=="R9")
        return to_binary(9);
    else if(val=="R10")
        return to_binary(10);
    else if(val=="R11")
        return to_binary(11);
    else if(val=="R12")
        return to_binary(12);
    else if(val=="R13")
        return to_binary(13);
    else if(val=="R14")
        return to_binary(14);
    else
        return to_binary(15);
    
}

bool is_external_symbol_defined(std::string &symbol)
{
    if(variable_table.find(symbol)!=variable_table.end())
        return true;
    return false;
}

void add_variable_symbol(std::string &symbol)
{
    variable_table[symbol]=curr_uninit_memory_address;
    curr_uninit_memory_address++;
}

bool is_label_symbol_defined(std::string &symbol)
{
    if(label_table.find(symbol)!=label_table.end())
        return true;
    return false;
}

void add_label_symbol(std::string &symbol, int line)
{
    label_table[symbol]=line;
}

std::string get_variable_symbol(std::string &symbol)
{
    if(internal_symbol.find(symbol)!=internal_symbol.end())
        return get_internal_symbol(symbol);
    return to_binary(variable_table[symbol]);
}

std::string get_label_symbol(std::string &symbol)
{
    if(internal_symbol.find(symbol)!=internal_symbol.end())
        return get_internal_symbol(symbol);
    return to_binary(label_table[symbol]);
}

std::string get_constant_binary(std::string &symbol)
{
    int val =std::stoi(symbol);
    return to_binary(val);
}