#include "paper.h"
#include <string.h>
int main(int argc, char **argv) {
    CLIENT *cl;
    pap_in in;
    pap_out *out;
    if (argc<3) { 
        printf("Usage: paperclient <function> <machine address> <arguments>\n");
        printf("<function>: add, <arguments>: ‘Author Name’ ‘Paper Title’ 'paper.pdf'\n");
        printf("<function>: list, <arguments>: None\n");
        printf("<function>: detail, <arguments>: Number of paper\n");
        printf("<function>: fetch, <arguments>: Number of paper\n");
        return 1; 
    }
    cl = clnt_create(argv[2], PAP_PROG, PAP_VERS, "tcp");
    if(strcmp(argv[1],"add")==0){
        in.arg0=0;
        strcpy(in.arg1,argv[3]);
        strcpy(in.arg2,argv[4]);
        strcpy(in.arg3,argv[5]);
    } 
    else if(strcmp(argv[1],"list")==0){
        in.arg0=1;
    }
    else if(strcmp(argv[1],"detail")==0){
        in.arg0=2;
        strcpy(in.arg1,argv[3]);
    }
    else if(strcmp(argv[1],"fetch")==0){
        in.arg0=3;
        strcpy(in.arg1,argv[3]);
    }
    else{
        printf("Usage: paperclient <function> <machine address> <arguments>\n");
        printf("<function>: add, <arguments>: ‘Author Name’ ‘Paper Title’ 'paper.pdf'\n");
        printf("<function>: list, <arguments>: None\n");
        printf("<function>: detail, <arguments>: Number of paper\n");
        printf("<function>: fetch, <arguments>: Number of paper\n");
        return 1; 
    }
    out = pap_proc_1(&in, cl);
    if (out==NULL) { 
        printf("Error: %s\n",clnt_sperror(cl,argv[2])); 
    }
    else { 
        printf("Server Response:\n%s\n",out);
    }
    clnt_destroy(cl);
    return 0;
}
