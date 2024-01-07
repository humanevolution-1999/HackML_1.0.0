#include<string>
#include<unordered_map>

// Initialize an empty unordered_map for storing binary dest values
    std::unordered_map<std::string, std::string> binary_dest_values;

// Initialize an empty unordered_map for storing binary comp values
    std::unordered_map<std::string, std::string> binary_comp_values;

// Initialize an empty unordered_map for storing binary jump values
    std::unordered_map<std::string, std::string> binary_jmp_values;

void init_coder_instructions()
{
    // Insert instruction code in dest_instruction_set
    binary_dest_values[""] = "000";
    binary_dest_values["M"] = "001";
    binary_dest_values["D"] = "010";
    binary_dest_values["MD"] = "011";
    binary_dest_values["A"] = "100";
    binary_dest_values["AM"] = "101";
    binary_dest_values["AD"] = "110";
    binary_dest_values["AMD"] = "111";

    // Insert instruction code in comp_instruction_set
    binary_comp_values["0"] = "0101010";
    binary_comp_values["1"] = "0111111";
    binary_comp_values["-1"] = "0111010";
    binary_comp_values["D"] = "0001100";
    binary_comp_values["A"] = "0110000";
    binary_comp_values["!D"] = "0001101";
    binary_comp_values["!A"] = "0110011";
    binary_comp_values["-D"] = "0001111";
    binary_comp_values["D+1"] = "0011111";
    binary_comp_values["A+1"] = "0110111";
    binary_comp_values["D-1"] = "0001110";
    binary_comp_values["A-1"] = "0110010";
    binary_comp_values["D+A"] = "0000010";
    binary_comp_values["D-A"] = "0010011";
    binary_comp_values["A-D"] = "0000111";
    binary_comp_values["D&A"] = "0000000";
    binary_comp_values["D|A"] = "0010101";
    binary_comp_values["M"] = "1110001";
    binary_comp_values["!M"] = "1110001";
    binary_comp_values["-M"] = "1110011";
    binary_comp_values["M+1"] = "1110111";
    binary_comp_values["M-1"] = "1110010";
    binary_comp_values["D+M"] = "1000010";
    binary_comp_values["D-M"] = "1010011";
    binary_comp_values["M-D"] = "1000111";
    binary_comp_values["D&M"] = "1000000";
    binary_comp_values["D|M"] = "1010101";

    // Insert instruction code in jump instruction set
    binary_jmp_values[""] = "000";
    binary_jmp_values["JGT"] = "001";
    binary_jmp_values["JEQ"] = "010";
    binary_jmp_values["JGE"] = "011";
    binary_jmp_values["JLT"] = "100";
    binary_jmp_values["JNE"] = "101";
    binary_jmp_values["JLE"] = "110";
    binary_jmp_values["JMP"] = "111";

}


std::string get_dest_binary(std::string &dest)
{
    
    // Use a switch statement to return the binary value based on the destination mnemonic
    switch(binary_dest_values.count(dest)) {
        case 1:
            return binary_dest_values[dest];
        default:
            // Handle the case where the destination mnemonic is not found
            return "Destination mnemonic not recognized";
    }
}

std::string get_comp_binary(std::string &comp)
{

    // Use a switch statement to return the binary value based on the operation code
    switch(binary_comp_values.count(comp)) {
        case 1:
            return binary_comp_values[comp];
        default:
            // Handle the case where the operation code is not found
            return "Operation code not recognized";
    }
    
}

std::string get_jump_binary(std::string &jump)
{
    // Use a switch statement to return the binary value based on the jump mnemonic
    switch(binary_jmp_values.count(jump)) {
        case 1:
            return binary_jmp_values[jump];
        default:
            // Handle the case where the jump mnemonic is not found
            return "Jump mnemonic not recognized";
    }
}

