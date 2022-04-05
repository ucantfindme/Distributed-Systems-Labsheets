/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "cal.h"

/* Default timeout can be changed using clnt_control() */
static struct timeval TIMEOUT = { 25, 0 };

cal_out *
cal_proc_1(argp, clnt)
	cal_in *argp;
	CLIENT *clnt;
{
	static cal_out clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call(clnt, CAL_PROC, xdr_cal_in, argp, xdr_cal_out, &clnt_res, TIMEOUT) != RPC_SUCCESS)
		return (NULL);
	return (&clnt_res);
}