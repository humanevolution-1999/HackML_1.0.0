#include<iostream>
#include<stdio.h>
#include<fstream>
#include<sstream>
#include "symbol_table.h"
#include "coder.h"
#include "parser.h"
#include "filehandler.h"


int main(int argc, char* argv[])
{
    if(argc!=2)
    {
        std::cout<<"Invalid Input\n";
        return 1;

    }
    //store line buffer from input file
    std::string line;
    
    //taking input from user
    std::string input_str=argv[1];

    //converting the input string to string stream
    std::istringstream input_file(input_str);
    

    //initiating the internal binary table
    init_coder_instructions();
    init_internal_symbol();
   

    //initiating line number
    int line_num=0;
    while(std::getline(input_file,line))
    {
        //increment line_count
        line_num++;
        //file_1_symbol_parse.line_num++;
        //std::cout<<line<<"\n";

        
        //check for instruction type
        if(instruction_type(line)==a_instruction)
        {
            std::string parsed_add = parse_variable(line);

            //handling for invalid symbols
            if(symbol_type(parsed_add)==invalid)
            {
                //std::cerr<<"line "<<file_1_symbol_parse.line_num<<": invalid instruction";
                std::cerr<<"line "<<line_num<<": invalid instruction";
                return 1;
            }
            else if(symbol_type(parsed_add)==variable)
            {
                //add an unknown variable
                if(is_internal_symbol(parsed_add)==false)
                {
                    if(is_external_symbol_defined(parsed_add)==false)
                        add_variable_symbol(parsed_add);
                } 
            }
        }
        else if (instruction_type(line)==l_instruction)
        {
            //parse the label 
            std::string parsed_var= parse_label(line);

            //handling for invalid label name
            if(symbol_type(parsed_var)==invalid)
            {
                std::cerr<<"line "<<line_num<<": invalid instruction";
                return 1;
            }
            else if(symbol_type(parsed_var)==variable)
            {
                if(is_internal_symbol(parsed_var)==false)
                {
                    //add the label variable to the label table
                    if(is_label_symbol_defined(parsed_var)==false)
                        add_label_symbol(parsed_var,line_num+1);
                }
            }
        }  
    }

   

    std::istringstream input_file_2(input_str);
    
    //re-initiating line_num
    line_num=0;

    while(std::getline(input_file_2,line))
    {
        //increment line number
        line_num++;
        if(instruction_type(line)==a_instruction)
        {
            
            std::string parsed_var = parse_variable(line);
            if(symbol_type(parsed_var)==constant)
            {
                //convert constant to 16 bit binary
                std::string temp = get_constant_binary(parsed_var);
            }
            else if(symbol_type(parsed_var)==variable)
            {
                //convert variable to 16 bit binary. Also the variable name is guaranteed to be syntactically correct since it's already checked in the first pass
                std::string temp = get_variable_symbol(parsed_var);
                std::cout<<temp<<"\n";
            }
        }
        else if(instruction_type(line)==c_instruction)
        {

            std::string out_instruction = "111";

            //get destination part of the c instruction
            std::string dest_binary;
            dest_binary = parse_c_instruction_dest(line);
            //std::cout<<"dest "<<dest_binary<<"\n";
            if(check_validity_dest(dest_binary)==false)
            {
                std::cerr<<"Line "<<line_num<<": invalid destination instruction";
                return 1;
            }
            else
                //convert to binary destn instn
                out_instruction += get_dest_binary(dest_binary);

            //get comp part of the c instruction
            std::string comp_binary;
            comp_binary = parse_c_instruction_comp(line);
           
            //error handling in case of invalid computation instruction
            if(check_validity_comp(comp_binary)==false)
            {
                std::cerr<<"Line "<<line_num<<": invalid computation instruction"<<"\n";
                return 1;
            }
            else
                //convert to binary comp instn
                out_instruction += get_comp_binary(comp_binary);

            //get jump part of the c instruction
            std::string jump_binary;
            jump_binary = parse_c_instruction_jmp(line);

            //error handling in case of invalid jump instruction
            if(check_validity_jump(jump_binary)==false)
            {
                std::cerr<<"Line "<<line_num<<": invalid jump instruction";
                return 1;
            }
            else
                //convert to binary jump instn
                out_instruction +=get_jump_binary(jump_binary);

            std::cout<<out_instruction<<"\n";
        }
    }

    //outputFile.close();
    //file_1.m_inputFile("sample.txt");
    //std::cout<<"end of program \n";
    return 0;
}
