/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _ADD_H_RPCGEN
#define _ADD_H_RPCGEN

#define RPCGEN_VERSION	199506

#include <rpc/rpc.h>


struct add_in {
	long arg1;
	long arg2;
};
typedef struct add_in add_in;
#ifdef __cplusplus
extern "C" bool_t xdr_add_in(XDR *, add_in*);
#elif __STDC__
extern  bool_t xdr_add_in(XDR *, add_in*);
#else /* Old Style C */
bool_t xdr_add_in();
#endif /* Old Style C */


typedef long add_out;
#ifdef __cplusplus
extern "C" bool_t xdr_add_out(XDR *, add_out*);
#elif __STDC__
extern  bool_t xdr_add_out(XDR *, add_out*);
#else /* Old Style C */
bool_t xdr_add_out();
#endif /* Old Style C */


#define ADD_PROG ((rpc_uint)0x3543000)
#define ADD_VERS ((rpc_uint)1)

#ifdef __cplusplus
#define ADD_PROC ((rpc_uint)1)
extern "C" add_out * add_proc_1(add_in *, CLIENT *);
extern "C" add_out * add_proc_1_svc(add_in *, struct svc_req *);

#elif __STDC__
#define ADD_PROC ((rpc_uint)1)
extern  add_out * add_proc_1(add_in *, CLIENT *);
extern  add_out * add_proc_1_svc(add_in *, struct svc_req *);

#else /* Old Style C */
#define ADD_PROC ((rpc_uint)1)
extern  add_out * add_proc_1();
extern  add_out * add_proc_1_svc();
#endif /* Old Style C */

#endif /* !_ADD_H_RPCGEN */
