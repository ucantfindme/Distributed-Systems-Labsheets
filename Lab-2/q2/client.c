#include "cal.h"
int main(int argc, char **argv) {
    CLIENT *cl;
    cal_in in;
    cal_out *out;
    printf("Available Options: 1. Add\t 2. Subtract\t 3. Multiply\t 4. Divide\t 5. OR\t 6. AND\t 7.XOR\n");
    if (argc!=5) { 
        printf("Usage: client <machine> <choice> <int1> <int2>\n\n");
        return 1; 
    }
    cl = clnt_create(argv[1], CAL_PROG, CAL_VERS, "tcp");
    in.arg1 = atol(argv[2]);
    in.arg2 = atol(argv[3]);
    in.arg3=atol(argv[4]);
    out = cal_proc_1(&in, cl);
    if (out==NULL) { 
        printf("Error: %s\n",clnt_sperror(cl,argv[1])); 
    }
    else { 
        printf("We received the result: %ld\n",*out); 
    }
    clnt_destroy(cl);
    return 0;
}