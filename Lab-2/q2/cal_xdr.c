/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "cal.h"

bool_t
xdr_cal_in(xdrs, objp)
	XDR *xdrs;
	cal_in *objp;
{

	if (!xdr_long(xdrs, &objp->arg1))
		return (FALSE);
	if (!xdr_long(xdrs, &objp->arg2))
		return (FALSE);
	if (!xdr_long(xdrs, &objp->arg3))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_cal_out(xdrs, objp)
	XDR *xdrs;
	cal_out *objp;
{

	if (!xdr_long(xdrs, objp))
		return (FALSE);
	return (TRUE);
}
