/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "add.h"

bool_t
xdr_add_in(xdrs, objp)
	XDR *xdrs;
	add_in *objp;
{

	if (!xdr_long(xdrs, &objp->arg1))
		return (FALSE);
	if (!xdr_long(xdrs, &objp->arg2))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_add_out(xdrs, objp)
	XDR *xdrs;
	add_out *objp;
{

	if (!xdr_long(xdrs, objp))
		return (FALSE);
	return (TRUE);
}
