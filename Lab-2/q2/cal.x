struct cal_in { /* The arguments of the procedure */
long arg1;
long arg2;
long arg3;
};
typedef long cal_out; /* The return value of the procedure */
program CAL_PROG {
version CAL_VERS {
cal_out CAL_PROC(cal_in) = 1; /* Procedure number = 1 */
} = 1; /* Version number = 1 */
} = 0x3543000; /* Program number = 0x3543000 */