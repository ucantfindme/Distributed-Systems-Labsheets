struct pap_in { /* The arguments of the procedure */
    int arg0;
    char arg1[20];
    char arg2[20];
    char arg3[20];
};
typedef char pap_out[2000]; /* The return value of the procedure */
program PAP_PROG {
    version PAP_VERS {
        pap_out PAP_PROC(pap_in) = 1; /* Procedure number = 1 */
    } = 1; /* Version number = 1 */
} = 0x3543000; /* Program number = 0x3543000 */