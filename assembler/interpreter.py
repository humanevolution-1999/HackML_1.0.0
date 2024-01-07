import subprocess
import sys
import os

def intepret(input_file):

    #converting the string into multiline string
    lines_splitlines = input_file.splitlines()
    multiline_string=""
    for line in lines_splitlines:
        multiline_string += line + "\n"
    
    # Path to the directory containing the C++ files
    cpp_directory = "/Users/rana.madhvendra/Desktop/Assembler_Hack/hack_ml"

    # List of C++ source files
    cpp_files = ["main.cpp", "coder.cpp", "parser.cpp", "symbol_table.cpp"]

    # Path to the compiled C++ program
    cpp_program = os.path.join(cpp_directory, "cpp_function")

    # Compile the C++ program
    compile_command = ["g++"] + cpp_files + ["-o", cpp_program]
    compilation_result = subprocess.run(compile_command, cwd=cpp_directory, stderr=subprocess.PIPE, text=True)

    if compilation_result.returncode != 0:
        compilation_err = compilation_result.stderr
        print(f"Compilation Error:\n{compilation_err}")
        return compilation_err

    # Construct the command to run the compiled C++ program with arguments
    print(multiline_string)
    run_command = [cpp_program] + [multiline_string]

    try:
        # Run the C++ program using subprocess
        result = subprocess.run(run_command, cwd=cpp_directory, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)

        # Check if the subprocess ran successfully
        if result.returncode == 0:
            output = result.stdout
        else:
            output = f"Error: {result.stderr}"
    except Exception as e:
        output = f"An error occurred: {str(e)}"
    output_lines=[]
    for line in output.splitlines():
        output_lines.append(line)
    print(output_lines)
    return output_lines
