#include "lpih.h"

int main(int argc, char **argv) {
    
    int opt;
    while ((opt = getopt(argc, argv, "abc")) != -1) {
        switch (opt) {
            case 'a':
                fprintf(stdout, "%c was provided\n", opt);
                break; 
                
            case 'b':
                fprintf(stdout, "%c was provided\n", opt);
                break;

            case 'c':
                fprintf(stdout, "%c was provided\n", opt);
        }

    }
    return 0;
}