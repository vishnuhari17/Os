#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main() {
    // File pointers for various files used in the assembler
    FILE *f1, *f2, *f3, *f4, *f5, *f6;

    // Variables used in the assembler
    int lc, sa, i = 0, k = 0, j = 0, pgmlen, len, l = 0;
    char name[10], opnd[10], la[10], mne[10], s1[10], mne1[10], opnd1[10], addr[10], label[10];
    char lcs[10], m[10][10], s2[10];
    char sym[10], symaddr[10], obj1[10], obj2[10];

    // Open necessary files: input file, operation table, symbol table, output file, modification file
    f1 = fopen("in.txt", "r");  // Input file containing assembly program
    f2 = fopen("optab.txt", "r");  // Operation code table (mnemonics to machine codes)
    f3 = fopen("symtab1.txt", "w+");  // Symbol table 1 (stores symbols/labels without address initially)
    f4 = fopen("symtab2.txt", "w+");  // Symbol table 2 (stores symbols/labels with address)
    f5 = fopen("out.txt", "w+");  // Output file containing machine code/object code
    f6 = fopen("modi.txt", "w+");  // Modification file (records of modification)

    // Read the first line from the input file: la (label), mne (mnemonic), opnd (operand)
    fscanf(f1, "%s%s%s", la, mne, opnd);

    // If the mnemonic is 'START', initialize the starting address (sa) and location counter (lc)
    if(strcmp(mne, "START") == 0) {
        sa = atoi(opnd);  // Convert operand to integer (starting address)
        strcpy(name, la);  // Store the program name (label)
        lc = sa;  // Initialize the location counter to starting address
    }

    strcpy(s1, "*");  // Initialize s1 to '*', used later for symbol handling
    fscanf(f1, "%s%s%s", la, mne, opnd);  // Read next instruction (la, mne, opnd)

    // Main loop to process each instruction until 'END' mnemonic is reached or file ends
    while(strcmp(mne, "END") != 0 && !feof(f1)) {
        if(strcmp(la, "-") == 0) {  // If there is no label ('-')
            // Read the operation table (optab.txt) to match the mnemonic and get machine code
            fscanf(f2, "%s%s", mne1, opnd1);
            while(!feof(f2)) {
                if(strcmp(mne1, mne) == 0) {  // If mnemonic matches in the operation table
                    // Write symbol and machine code to appropriate files
                    fprintf(f3, "%s\t%s\n", opnd, s1);  // Symbol with no address (symtab1.txt)
                    fprintf(f5, "%s\t%s\n", opnd1, opnd);  // Output (out.txt)
                    fprintf(f6, "%d\t%s\n", lc + 1, opnd);  // Modification record (modi.txt)
                    lc = lc + 3;  // Update location counter (assuming instruction size is 3 bytes)
                    break;  // Exit loop after finding match
                }
                fscanf(f2, "%s%s", mne1, opnd1);  // Continue searching optab
            }
        } else {  // If there is a label present
            rewind(f3);  // Reset symbol table 1 for reading
            fscanf(f3, "%s%s", sym, symaddr);  // Read symbols from symtab1
            while(!feof(f3)) {
                if(strcmp(sym, la) == 0) {  // If symbol matches the label
                    sprintf(lcs, "%d", lc);  // Convert location counter to string
                    fprintf(f4, "%s\t%s\n", la, lcs);  // Write label and address to symtab2.txt
                    // Handle different types of mnemonics:
                    if(strcmp(mne, "RESW") == 0)  // Reserve word
                        lc = lc + 3 * atoi(opnd);  // Update lc by the number of words (each 3 bytes)
                    else if(strcmp(mne, "BYTE") == 0) {  // Handle BYTE (literal constant)
                        len = strlen(opnd);
                        for(k = 2; k < len - 1; k++) {  // Extract the bytes from the operand
                            s2[l++] = opnd[k];
                        }
                        sprintf(m[i++], "%s", s2);  // Store bytes in m array for text record
                        lc = lc + 1;  // Update lc by 1 byte
                    } else if(strcmp(mne, "RESB") == 0)  // Reserve byte
                        lc = lc + atoi(opnd);  // Update lc by the number of bytes reserved
                    else if(strcmp(mne, "WORD") == 0) {  // Handle WORD (constant)
                        sprintf(m[i++], "%s", opnd);  // Store word in m array for text record
                        lc = lc + 3;  // Update lc by 3 bytes
                    }
                    break;  // Exit loop after finding matching label
                }
                fscanf(f3, "%s%s", sym, symaddr);  // Continue searching symtab1
            }
        }
        rewind(f2);  // Reset operation table for the next mnemonic
        fscanf(f1, "%s%s%s", la, mne, opnd);  // Read next instruction
    }

    // After END, process object code generation:
    rewind(f5);  // Reset output file for reading
    rewind(f4);  // Reset symbol table 2 for reading

    pgmlen = lc - sa;  // Calculate program length
    printf("H^%s^00%d^0%d\n", name, sa, pgmlen);  // Header record (program name, start address, length)

    printf("T^00%d^0%d", sa, pgmlen);  // Text record starts with the starting address and length
    fscanf(f5, "%s%s", obj1, obj2);  // Read object code from out.txt
    j = i;  // Store current i for later

    while(!feof(f5)) {  // Loop through output file to generate text records
        fscanf(f4, "%s%s", la, lcs);  // Read symbol table 2
        while(!feof(f4)) {
            if(strcmp(obj2, la) == 0) {  // If operand matches label in symtab2
                printf("^%s0000", obj1);  // Print object code
                break;
            }
            fscanf(f4, "%s%s", la, lcs);  // Continue searching symtab2
        }
        fscanf(f5, "%s%s", obj1, obj2);  // Read next object code
        rewind(f4);  // Reset symtab2 for next search
    }

    // Output the stored bytes (BYTE and WORD) from m array
    for(i = 0; i < j; i++)
        printf("^%s", m[i]);

    // Handle modification records for external symbols
    rewind(f5);
    rewind(f4);
    fscanf(f5, "%s%s", obj1, obj2);
    rewind(f6);
    while(!feof(f5)) {
        fscanf(f4, "%s%s", la, lcs);
        while(!feof(f4)) {
            fscanf(f6, "%s\t%s", addr, label);
            while(!feof(f6)) {
                if((strcmp(obj2, la) == 0) && (strcmp(la, label) == 0)) {  // Check for modification
                    printf("\nT^%s^02", addr);  // Print modification address
                    printf("^%s", lcs);  // Print label corresponding to address
                    break;
                }
                fscanf(f6, "%s%s", addr, label);  // Read next modification record
            }
            fscanf(f4, "%s%s", la, lcs);  // Continue searching symtab2
            rewind(f6);  // Reset modification file
        }
        fscanf(f5, "%s%s", obj1, obj2);  // Read next object code
        rewind(f4);  // Reset symtab2
    }

    printf("\nE^00%d\n", sa);  // End record (execution start address)
}

