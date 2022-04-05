struct add_in { /* The arguments of the procedure */
long arg1;
long arg2;
};
typedef long add_out; /* The return value of the procedure */
program ADD_PROG {
version ADD_VERS {
add_out ADD_PROC(add_in) = 1; /* Procedure number = 1 */
} = 1; /* Version number = 1 */
} = 0x3543000; /* Program number = 0x3543000 */