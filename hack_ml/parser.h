#ifndef parser_h
#define parser_h
enum Instruction_statement_type
{
    a_instruction,
    l_instruction,
    cmnt_instruction,
    c_instruction,
};

enum Symbol_value_type
{
    constant,
    variable,
    invalid,
};

Instruction_statement_type instruction_type(std::string &instn_line);
Symbol_value_type symbol_type(std::string &symbol);

bool check_validity_constant(std::string &);
bool check_validity_symbol(std::string &);
bool check_validity_comp(std::string &);
bool check_validity_dest(std::string &);
bool check_validity_jump(std::string &);

std::string parse_label(std::string &line);
std::string parse_variable(std::string &line);
std::string parse_c_instruction_dest(std::string &line);
std::string parse_c_instruction_comp(std::string &line);
std::string parse_c_instruction_jmp(std::string &line);

#endif