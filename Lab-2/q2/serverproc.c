#include "cal.h"
#include <stdio.h>
cal_out *cal_proc_1_svc(cal_in *in, struct svc_req *rqstp) {
    static cal_out out;
    if(in->arg1==1){
        out = in->arg2 + in->arg3;
    }
    else if(in->arg1==2){
        out = in->arg2 - in->arg3;
    }
    else if(in->arg1==3){
        out = in->arg2 * in->arg3;
    }
    else if(in->arg1==4){
        out = in->arg2 / in->arg3;
    }
    else if(in->arg1==5){
        out = in->arg2 | in->arg3;
    }
    else if(in->arg1==6){
        out = in->arg2 & in->arg3;
    }
    else if(in->arg1==7){
        out = in->arg2 ^ in->arg3;
    }
    else{
        out=-1;
    }
    return(&out);
}