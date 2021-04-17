/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "calc.h"

bool_t
xdr_getval(xdrs, objp)
	XDR *xdrs;
	getval *objp;
{

	if (!xdr_int(xdrs, &objp->res))
		return (FALSE);
	if (!xdr_string(xdrs, &objp->val1, ~0))
		return (FALSE);
	if (!xdr_int(xdrs, &objp->val2))
		return (FALSE);
	if (!xdr_float(xdrs, &objp->val3))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_set_value_1_argument(xdrs, objp)
	XDR *xdrs;
	set_value_1_argument *objp;
{
	if (!xdr_string(xdrs, &objp->key, ~0))
		return (FALSE);
	if (!xdr_string(xdrs, &objp->val1, ~0))
		return (FALSE);
	if (!xdr_int(xdrs, &objp->val2))
		return (FALSE);
	if (!xdr_float(xdrs, &objp->val3))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_modify_value_1_argument(xdrs, objp)
	XDR *xdrs;
	modify_value_1_argument *objp;
{
	if (!xdr_string(xdrs, &objp->key, ~0))
		return (FALSE);
	if (!xdr_string(xdrs, &objp->val1, ~0))
		return (FALSE);
	if (!xdr_int(xdrs, &objp->val2))
		return (FALSE);
	if (!xdr_float(xdrs, &objp->val3))
		return (FALSE);
	return (TRUE);
}