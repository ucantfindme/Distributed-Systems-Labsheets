#include "paper.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct paper{
    char author[20];
    char title[20];
    char content[20];
};
struct paper papers[300];
int i=0;
char* pap_proc_1_svc(pap_in *in, struct svc_req *rqstp) {
    static pap_out out;

    if(in->arg0==0){
        strcpy(papers[i].author,in->arg1);
        strcpy(papers[i].title,in->arg2);
        strcpy(papers[i].content,in->arg3);
        i++;
        strcpy(out,"Paper Saved Successfully!");
    }
    else if(in->arg0==1){
        strcpy(out,"Available Papers:\n");
        for(int j=0;j<i;j++){
            char* te[20];
            sprintf(te,"%d",j);
            strcat(out,te);
            strcat(out,"-");
            strcat(out,papers[j].title);
            strcat(out,"-");
            strcat(out,papers[j].author);
            strcat(out,"\n");
        }
    }
    else if(in->arg0==2){
        int t=atoi(in->arg1);
        if(t<i){
            strcpy(out,papers[t].title);
            strcat(out,"-");
            strcat(out,papers[t].author);
            strcat(out,"\n");
        }
        else{
            strcat(out,"Given Paper Number doesn't exist");
        }
    }
    else if(in->arg0==3){
        int t=atoi(in->arg1);
        if(t<i){
            strcpy(out,papers[t].title);
            strcat(out,"-");
            strcat(out,papers[t].author);
            strcat(out,"\n");
            strcat(out,papers[t].content);
            strcat(out,"\n");
        }
        else{
            strcpy(out,"Given Paper Number doesn't exist");
        }
    }
    else{
        strcpy(out,"Error Occured, Try Again!");
    }
    return(&out);
}
