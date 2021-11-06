import subprocess
import os
import sys

folders = [
    "0000-0099",
    "0100-0199",
    "0200-0299",
    "0300-0399",
    "0400-0499",
    "0500-0599",
    "0600-0699",
    "0700-0799"
]

def run_problem(problem_num):
    folder = folders[problem_num // 100]

    rel_filepath = os.path.join(folder, f'p{problem_num:04}.cpp')
    abs_binpath  = os.path.join('/tmp', f'p{problem_num:04}')

    compile_command = ["g++", "-std=c++17", "-O3", "-march=native", "-mtune=native", rel_filepath, "-o", abs_binpath]
    run_command = [abs_binpath]

    subprocess.run(compile_command)
    subprocess.run(abs_binpath)


run_problem(int(sys.argv[1]))
