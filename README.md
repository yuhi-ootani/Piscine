Overview
This repository, Piscine, contains a collection of programming exercises and projects that are organized into multiple “hubs” corresponding to different modules of the Piscine curriculum (such as C modules and Shell modules). 
github.com
 The repository does not include a high-level description, but the folder names (e.g., c00_hub, c01_hub, ..., c11_hub, Shell00, Shell01_hub, BSQ, rush01_hub, rush02_hub) indicate that it covers fundamental C programming exercises, intermediate C challenges, shell scripting tasks, and two “rush” final projects. 
github.com
github.com
 Additionally, the primary programming language is C (95%), with accompanying Makefiles (3%) and Shell scripts (1.9%), plus a small amount of Perl, reflecting typical tools and languages used in a 42 Piscine environment. 
github.com

Repository Structure
Below is a brief description of the main directories and their likely contents, based on standard Piscine naming conventions and the folder list: 
github.com

Shell00/

Contains the very first set of shell scripting exercises, typically covering basic Linux commands, redirections, simple pipelines, and file manipulations. 
github.com

Shell01_hub/

Includes more advanced shell scripting assignments, such as scripting loops, conditionals, and more complex file operations. 
github.com

c00_hub/

Encompasses the basic C module (C00), which generally covers fundamental topics like Hello World, variables, control flow (if, for, while), simple functions, and basic recursion. 
github.com
github.com

c01_hub/

Contains exercises in C module 1 (C01), often focusing on pointers, strings, functions that manipulate strings (e.g., strlen, strcpy), and simple memory operations. 
github.com

c02_hub/

Holds tasks from C module 2 (C02), which typically delve into arrays of strings, more complex pointer arithmetic, and basic data structure manipulation (e.g., arrays of integers). 
github.com

c03_hub/

Corresponds to C module 3 (C03), covering functions with multiple pointers, advanced string manipulation (e.g., strstr, strdup), and dynamic memory allocation. 
github.com

c04_hub/

Includes C module 4 (C04) exercises, which introduce function pointers, callback patterns, and simple sorting or searching algorithms. 
github.com

c05_hub/

Contains C module 5 (C05) problems, frequently focused on more complex pointer-to-pointer scenarios, two-dimensional arrays, and custom implementations of standard functions (e.g., converting strings to integers). 
github.com

c06_hub/

Holds C module 6 (C06) assignments, often about using malloc/free for dynamic memory, building basic data structures (like linked lists), or implementing fundamental algorithms (e.g., prime number search). 
github.com

c07_hub/

Corresponds to C module 7 (C07), which usually introduces more advanced concepts such as struct types, complex memory allocation patterns, and possibly basic file I/O in C. 
github.com

c08_hub/ and c08_sub_hub/

These folders cover C module 8 (C08). They typically include more intricate topics like dynamic memory management for multi-dimensional arrays, recursion in depth, and custom implementations of standard library routines. The “sub” hub likely contains extension or bonus exercises for C08. 
github.com

c09_hub/ and c09_sub_hub/

Represent C module 9 (C09), which often introduces bitwise operations, working with binary representations, and implementing basic bit-level algorithms. The “sub” hub again probably holds additional or optional tasks. 
github.com

c11_hub/

Covers C module 11 (C11). At 42 Piscine, C11 exercises generally involve mastering low-level memory handling (pointers to pointers), understanding the C preprocessor, and possibly rudimentary file descriptor I/O. 
github.com

BSQ/ and BSQ_REVIEW/

The “BSQ” (Biggest Square) project is a classic 42 Piscine final project, where the task is to find the largest square in a given map read from a file, using dynamic programming or efficient scanning algorithms. 
github.com
 The BSQ_REVIEW folder may contain code review notes, improved versions, or personal reflections on the BSQ project. 
github.com

rush01_hub/ and rush02_hub/ (plus rush01_hub/ex00 and rush02_hub/ex00)

These correspond to the “Rush” events, which are short, time-limited (usually 48–72 hours) final projects in the Piscine. The rush01_hub/ex00 and rush02_hub/ex00 subfolders likely contain the initial exercise for each rush, which often combine C and Unix tools to produce a small but non-trivial program under time pressure. 
github.com

rush02_Y/

The naming suggests an alternative or extended solution set for the second rush (rush02). It might be the user’s own enhanced version (hence the suffix _Y). 
github.com

Purpose and Learning Goals
Each hub directory reflects one module or project in the Piscine curriculum, which is designed to teach students fundamental to intermediate skills in C programming and Unix shell usage within a strict, exercise-based framework. 
github.com
 Specifically:

Shell modules (Shell00/, Shell01_hub/): develop proficiency with Linux shell commands, scripting, and text processing (e.g., awk, grep, sed). 
github.com

C modules (c00_hub/ through c11_hub/): build a step-by-step understanding of C, starting from basic syntax and control structures, moving through pointers and memory allocation, up to data structures and file I/O. 
github.com

BSQ project (BSQ/): apply dynamic programming techniques to a real file-processing problem, reinforcing memory management and algorithmic thinking. 
github.com

Rush projects (rush01_hub/, rush02_hub/): simulate real-world, time-constrained development under a team environment, combining knowledge from multiple modules. 
github.com

Prerequisites
To work on or review the exercises and projects in this repository, the following are generally required: 
github.com

A Unix-like Environment (Linux, macOS, WSL on Windows, etc.)

Access to a Bash-compatible shell to run scripts in Shell00/ and Shell01_hub/. 
github.com

GNU Compiler Collection (GCC) (or any C compiler)

To compile C programs in c00_hub/ through c11_hub/ and the BSQ/rush folders. 
github.com

Make

Many exercises use Makefile for compilation and testing. 
github.com

Basic Knowledge of C and Shell (if starting from scratch, see 42 Piscine curriculum).

While the repository is self-contained in terms of code, understanding the instructions and expected outputs usually relies on the official Piscine subject PDFs (not included here). 
github.com

How to Navigate and Use This Repository
Clone the repository

bash
Copy
Edit
git clone https://github.com/yuhi-ootani/Piscine.git
cd Piscine
github.com

Browse module-by-module

Each directory named cXX_hub or Shell0X contains subdirectories/exercises. For example:

bash
Copy
Edit
cd c00_hub
ls
github.com

Read the subject PDF (if available)

In a standard 42 Piscine, each exercise folder includes a subject PDF or text file explaining the requirements. In this personal repository, source code files (.c, .h) and Makefile might be present without the PDF. To fully understand the task requirements, one often refers to the official Piscine assignments (externally hosted). 
github.com

Compile and Test

Most C exercises provide a Makefile that supports at least the following targets:

make or make all: compile the source code. 
github.com

make clean: remove compiled artifacts. 
github.com

Some modules include automated tests (e.g., a run or test target). 
github.com

Work on Shell exercises

For shell scripting assignments (Shell00/, Shell01_hub/), look for .sh files. Typically, you run:

bash
Copy
Edit
bash ex00/subject.sh  # or similar
github.com

Review Projects (BSQ, Rush)

BSQ

Change directory to BSQ/ and examine the source files for the solution to the “Biggest Square” challenge. There may be a Makefile to build a single executable (e.g., bsq) that reads from a map file. 
github.com

Rush Projects

Enter rush01_hub/ex00/ or rush02_hub/ex00/ to find the starting point of each rush. These folders likely contain a single main C file or a collection of files with a Makefile. 
github.com

Example: Building a C Module Exercise
Below is a generic example for compiling and running an exercise from c01_hub/:

bash
Copy
Edit
cd c01_hub/ex00      # Example: first exercise in C01
make                 # Compile the code, typically produces ex00 executable
./ex00 "Hello World" # Run with arguments to verify behavior
make clean           # Clean up the compiled object files and binary
All commands and expected behaviors may vary slightly by module; refer to each exercise’s Makefile and source comments. 
github.com

Contribution & Usage Notes
No Upstream Contributions Expected

Since this repository mirrors one individual’s Piscine solutions, there is no collaborative contribution workflow (no open issues or pull requests). 
github.com

Educational Reference Only

Use the code here as reference or inspiration for learning C and shell scripting. Copying solutions verbatim is discouraged if you are undergoing the Piscine, as independent problem-solving is a core educational goal. 
github.com

License

The repository does not include a LICENSE file. In the absence of an explicit license, assume “All rights reserved” for personal code. If you wish to reuse or adapt code, please reach out to the owner for permission. 
github.com

Supported Languages & Tools
According to GitHub’s language statistics, this repository uses the following languages: 
github.com

C (95.0%): Core language for Piscine exercises and projects. 
github.com

Makefile (3.0%): Build scripts for compiling C exercises. 
github.com

Shell (1.9%): Scripts for Shell00 and Shell01 modules. 
github.com

Perl (0.1%): Possibly used for minor utilities or test harnesses (if any). 
github.com

Summary
In summary, yuhi-ootani/Piscine is a personal archive of 42 Piscine C and Shell exercises, organized into “hubs” that correspond to individual modules (from C00 to C11 and Shell00/01), plus final projects (BSQ) and rush events (rush01, rush02). 
github.com
github.com
 Each hub folder contains source code files and Makefiles for compilation, allowing users to study solved examples or practice building their own solutions. 
github.com
 The repository does not include formal documentation or instructions beyond the code, so users must rely on official Piscine subject materials (not included) to fully understand each exercise’s requirements. 
github.com

