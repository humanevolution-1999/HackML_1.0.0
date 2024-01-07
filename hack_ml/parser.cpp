#include<string>
#include<fstream>
#include<algorithm>
#include<iostream>
#include "parser.h"
#include "coder.h"

int curr_c_instruction_char_cnt=0;

bool check_validity_constant(std::string &symbol)
{
    for(int i=0;i<symbol.size();i++)
        if(symbol[i]<'0' || symbol[i]>'9')
            return false;
    return true;
}

bool check_validity_symbol(std::string &symbol)
{
    for(int i=0;i<symbol.size();i++)
    {
        if(!((symbol[i]>='a' && symbol[i]<='z') || symbol[i]=='$' || symbol[i]=='_' || symbol[i]==':' || (symbol[i]>='0' && symbol[i]<='9') || (symbol[i]>='A' || symbol[i]<='Z')))
            return false;
    }
    return true;
}


bool check_validity_dest(std::string &val)
{
    if(binary_dest_values.find(val)!=binary_dest_values.end())
        return true;
    return false;
}

bool check_validity_comp(std::string &val)
{
    if(binary_comp_values.find(val)!=binary_comp_values.end())
        return true;
    return false;
}

bool check_validity_jump(std::string &val)
{
    if(binary_jmp_values.find(val)!=binary_jmp_values.end())
        return true;
    return false;
}

Instruction_statement_type instruction_type(std::string &instn_line)
{
    if(instn_line[0]=='@')
        return a_instruction;
    else if(instn_line[0]=='(')
        return l_instruction;
    else if(instn_line[0]=='/')
        return cmnt_instruction;
    else
        return c_instruction;

}

Symbol_value_type symbol_type(std::string &symbol)
{
    if(symbol[0]>='0' && symbol[0]<='9')
    {
        if(check_validity_constant(symbol)==false)
            return invalid;
        return constant;
    }
    else 
    {
        if(check_validity_symbol(symbol)==false)
            return invalid;  
        return variable;
    } 
}

std::string parse_label(std::string &line)
{
    std::string val(line.begin()+1,line.begin()+line.size()-1);
    return val;
}

std::string parse_variable(std::string &line)
{
    std::string val(line.begin()+1,line.end());
    return val;
}

std::string parse_c_instruction_dest(std::string &line)
{
    while(curr_c_instruction_char_cnt<line.size() && line[curr_c_instruction_char_cnt]!='=')
        curr_c_instruction_char_cnt++;
    if(curr_c_instruction_char_cnt==line.size())
    {
        curr_c_instruction_char_cnt=0;
        return "";
    }
    std::string val(line.begin(),line.begin()+curr_c_instruction_char_cnt);
    //increment curr_character_cnt to point to the next character to '=' sign
    curr_c_instruction_char_cnt++;
    return val;
}

std::string parse_c_instruction_comp(std::string &line)
{
    std::string val;
    while(curr_c_instruction_char_cnt<line.size() && line[curr_c_instruction_char_cnt]!=';')
    {
        val.push_back(line[curr_c_instruction_char_cnt]);
        curr_c_instruction_char_cnt++;
    }
    //increment curr_character_cnt to point to the next character to ';' sign
    curr_c_instruction_char_cnt++;
    return val;
}

std::string parse_c_instruction_jmp(std::string &line)
{
    std::string val;
    while(curr_c_instruction_char_cnt<line.size())
    {
        val.push_back(line[curr_c_instruction_char_cnt]);
        curr_c_instruction_char_cnt++;
    }
    curr_c_instruction_char_cnt=0;
    return val;
}


