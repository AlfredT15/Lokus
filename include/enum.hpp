#ifndef ENUM_H
#define ENUM_H

enum DataType
{
	INT_DTYPE,
	FLOAT_DTYPE,
	STRING_DTYPE,
	CHAR_DTYPE,
	BOOL_DTYPE,
	VOID_DTYPE,
	LIST_DTYPE,
    FUNC_DTYPE,
	ERROR_DTYPE,
    TNI
};

enum OperationType
{
    ADD_TYPE,
    SUB_TYPE,
    MUL_TYPE,
    DIV_TYPE,
    EE_TYPE,
    NE_TYPE,
    LT_TYPE,
    GT_TYPE,
    LTE_TYPE,
    GTE_TYPE
};

#endif