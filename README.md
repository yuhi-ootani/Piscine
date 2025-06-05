# Piscine

## Summary  
This repository, **Piscine**, is a personal archive of 42 Piscine C and Shell exercises, organized into multiple “hub” directories corresponding to each module and project in the standard Piscine curriculum. It includes foundational shell scripting tasks, progressive C modules (from C00 through C11), and final projects such as BSQ and two Rush events. :contentReference[oaicite:0]{index=0}

## Repository Structure  
- **Shell00/**: Contains the initial shell scripting exercises for learning basic Linux commands and redirections.  
- **Shell01_hub/**: Holds more advanced Shell assignments, including scripting loops and conditionals.  
- **c00_hub/** through **c11_hub/**: Each folder corresponds to a C module (C00–C11), progressing from basic syntax and control flow to pointers, memory management, and data structures.  
- **c08_sub_hub/** and **c09_sub_hub/**: Contain supplementary or bonus exercises for modules C08 and C09, respectively.  
- **BSQ/** and **BSQ_REVIEW/**: Implement the “Biggest Square” project, a common Piscine challenge that finds the largest square in a map using dynamic programming.  
- **rush01_hub/ex00/** and **rush02_hub/ex00/**: Include the initial exercises for the Rush 01 and Rush 02 events—time-constrained projects that integrate multiple Piscine skills.  
- **rush02_Y/**: Likely contains an alternate or personal version of the Rush 02 project. :contentReference[oaicite:1]{index=1}

## Languages and Tools  
- **C (95.0%)**: Core language used in nearly all exercises and projects.  
- **Makefile (3.0%)**: Build and compilation scripts for each C module and project.  
- **Shell (1.9%)**: Scripts for Shell00 and Shell01 exercises.  
- **Perl (0.1%)**: Rarely used, possibly for minor utilities or test harnesses. :contentReference[oaicite:2]{index=2}

## How to Use This Repository  
1. **Clone the repository**:  
   ```bash
   git clone https://github.com/yuhi-ootani/Piscine.git
   cd Piscine
   ``` :contentReference[oaicite:3]{index=3}

2. **Navigate to a module or project**:  
   Each “hub” directory (e.g., `c00_hub/`, `Shell00/`, `BSQ/`) contains subfolders for individual exercises or projects. :contentReference[oaicite:4]{index=4}

3. **Compile C exercises**:  
   - Most C modules include a `Makefile`.  
   - Running `make` will produce an executable (often named `ex00`, `ex01`, etc.), and `make clean` removes compiled artifacts. :contentReference[oaicite:5]{index=5}

4. **Run Shell exercises**:  
   - For directories under `Shell00/` or `Shell01_hub/`, execute the provided `.sh` files in a Bash-compatible shell to verify behavior. :contentReference[oaicite:6]{index=6}

5. **Review projects**:  
   - **BSQ**: Change into `BSQ/` to find source files and a `Makefile` for the “Biggest Square” challenge.  
   - **Rush 01 & Rush 02**: Explore `rush01_hub/ex00/` and `rush02_hub/ex00/` for time-limited project code and build instructions. :contentReference[oaicite:7]{index=7}

## Notes  
- No official subject PDFs are included; to fully understand exercise requirements, refer to the standard 42 Piscine curriculum materials, which are not provided here.  
- Use this repository as a reference to compare solutions, practice compilation, and study code organization, but avoid copying solutions directly if you are currently enrolled in a Piscine.  
- No LICENSE or formal documentation is provided; assume “All rights reserved” for personal code. :contentReference[oaicite:8]{index=8}
