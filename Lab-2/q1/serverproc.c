#include "add.h"
#include <stdio.h>
add_out *add_proc_1_svc(add_in *in, struct svc_req *rqstp) {
    printf("#");
    static add_out out;
    out = in->arg1 + in->arg2;
    return(&out);
}

//Done By:
//N Sai Pavan Krishna
//AM.EN.U4CSE19347