#ifndef _CALC_GRM_H_
#define _CALC_GRM_H_

#define _ONLY_TOKEN_	
#include "calc.lex.h"
#undef	_ONLY_TOKEN_

enum {
	N_Stmt,
	N_LineExp,
	N_E,
};

#define TOTAL_NTER	3

enum {
	P_LHS_NStmt_RHS_NStmt_NLineExp,
	P_LHS_NStmt_RHS_NLineExp,
	P_LHS_NLineExp_RHS_NE_TNL,
	P_LHS_NLineExp_RHS_TERROR_TNL,
	P_LHS_NE_RHS_NE_TPLUS_NE,
	P_LHS_NE_RHS_NE_TMINUS_NE,
	P_LHS_NE_RHS_NE_TMUL_NE,
	P_LHS_NE_RHS_NE_TDIV_NE,
	P_LHS_NE_RHS_NE_TMOD_NE,
	P_LHS_NE_RHS_NE_TEXPO_NE,
	P_LHS_NE_RHS_TLPAREN_NE_TRPAREN,
	P_LHS_NE_RHS_TLPAREN_TERROR_TRPAREN,
	P_LHS_NE_RHS_TID_TEQUAL_NE,
	P_LHS_NE_RHS_TMINUS_NE,
	P_LHS_NE_RHS_TPLUS_NE,
	P_LHS_NE_RHS_TNUM,
	P_LHS_NE_RHS_TID,
};

#define TOTAL_PROD	18

static int
calc_rhs_prod_table[TOTAL_PROD] = {
	[P_LHS_NStmt_RHS_NStmt_NLineExp] = 2,
	[P_LHS_NStmt_RHS_NLineExp] = 1,
	[P_LHS_NLineExp_RHS_NE_TNL] = 2,
	[P_LHS_NLineExp_RHS_TERROR_TNL] = 2,
	[P_LHS_NE_RHS_NE_TPLUS_NE] = 3,
	[P_LHS_NE_RHS_NE_TMINUS_NE] = 3,
	[P_LHS_NE_RHS_NE_TMUL_NE] = 3,
	[P_LHS_NE_RHS_NE_TDIV_NE] = 3,
	[P_LHS_NE_RHS_NE_TMOD_NE] = 3,
	[P_LHS_NE_RHS_NE_TEXPO_NE] = 3,
	[P_LHS_NE_RHS_TLPAREN_NE_TRPAREN] = 3,
	[P_LHS_NE_RHS_TLPAREN_TERROR_TRPAREN] = 3,
	[P_LHS_NE_RHS_TID_TEQUAL_NE] = 3,
	[P_LHS_NE_RHS_TMINUS_NE] = 2,
	[P_LHS_NE_RHS_TPLUS_NE] = 2,
	[P_LHS_NE_RHS_TNUM] = 1,
	[P_LHS_NE_RHS_TID] = 1,
};

static int
calc_lhs_prod_table[TOTAL_PROD] = {
	[P_LHS_NStmt_RHS_NStmt_NLineExp] = N_Stmt,
	[P_LHS_NStmt_RHS_NLineExp] = N_Stmt,
	[P_LHS_NLineExp_RHS_NE_TNL] = N_LineExp,
	[P_LHS_NLineExp_RHS_TERROR_TNL] = N_LineExp,
	[P_LHS_NE_RHS_NE_TPLUS_NE] = N_E,
	[P_LHS_NE_RHS_NE_TMINUS_NE] = N_E,
	[P_LHS_NE_RHS_NE_TMUL_NE] = N_E,
	[P_LHS_NE_RHS_NE_TDIV_NE] = N_E,
	[P_LHS_NE_RHS_NE_TMOD_NE] = N_E,
	[P_LHS_NE_RHS_NE_TEXPO_NE] = N_E,
	[P_LHS_NE_RHS_TLPAREN_NE_TRPAREN] = N_E,
	[P_LHS_NE_RHS_TLPAREN_TERROR_TRPAREN] = N_E,
	[P_LHS_NE_RHS_TID_TEQUAL_NE] = N_E,
	[P_LHS_NE_RHS_TMINUS_NE] = N_E,
	[P_LHS_NE_RHS_TPLUS_NE] = N_E,
	[P_LHS_NE_RHS_TNUM] = N_E,
	[P_LHS_NE_RHS_TID] = N_E,
};

#define ERROR_SLOT	0
#define START_SYMBOL	N_Stmt

enum {
	_SHIFT	= 0x1000,
	_REDUCE	= 0x2000,
	_GOTO	= 0x4000,
};

#define SHIFT(x)	(x | _SHIFT)
#define REDUCE(x)	(x | _REDUCE)
#define GOTO(x)	(x | _GOTO)
#define ACCEPT	(~0)

#define LR_START_STATE	0

static int
calc_lr_action_table[33][TOTAL_TOKEN] = {
/*   0 */	{[T_NUM]=SHIFT(9), [T_PLUS]=SHIFT(8), [T_MINUS]=SHIFT(7), [T_ID]=SHIFT(6), [T_LPAREN]=SHIFT(5), [T_ERROR]=SHIFT(4)},
/*   1 */	{[T_NUM]=SHIFT(9), [T_PLUS]=SHIFT(8), [T_MINUS]=SHIFT(7), [T_ID]=SHIFT(6), [T_LPAREN]=SHIFT(5), [T_ERROR]=SHIFT(4), [T_EOF]=ACCEPT,},
/*   2 */	{[T_EOF]=REDUCE(P_LHS_NStmt_RHS_NLineExp), [T_LPAREN]=REDUCE(P_LHS_NStmt_RHS_NLineExp), [T_MINUS]=REDUCE(P_LHS_NStmt_RHS_NLineExp), [T_PLUS]=REDUCE(P_LHS_NStmt_RHS_NLineExp), [T_NUM]=REDUCE(P_LHS_NStmt_RHS_NLineExp), [T_ID]=REDUCE(P_LHS_NStmt_RHS_NLineExp), [T_ERROR]=REDUCE(P_LHS_NStmt_RHS_NLineExp)},
/*   3 */	{[T_EXPO]=SHIFT(22), [T_MOD]=SHIFT(21), [T_DIV]=SHIFT(20), [T_MUL]=SHIFT(19), [T_MINUS]=SHIFT(18), [T_PLUS]=SHIFT(17), [T_NL]=SHIFT(16)},
/*   4 */	{[T_NL]=SHIFT(15)},
/*   5 */	{[T_NUM]=SHIFT(9), [T_PLUS]=SHIFT(8), [T_MINUS]=SHIFT(7), [T_ID]=SHIFT(6), [T_LPAREN]=SHIFT(5), [T_ERROR]=SHIFT(14)},
/*   6 */	{[T_EQUAL]=SHIFT(12), [T_RPAREN]=REDUCE(P_LHS_NE_RHS_TID), [T_EXPO]=REDUCE(P_LHS_NE_RHS_TID), [T_MOD]=REDUCE(P_LHS_NE_RHS_TID), [T_DIV]=REDUCE(P_LHS_NE_RHS_TID), [T_MUL]=REDUCE(P_LHS_NE_RHS_TID), [T_MINUS]=REDUCE(P_LHS_NE_RHS_TID), [T_PLUS]=REDUCE(P_LHS_NE_RHS_TID), [T_NL]=REDUCE(P_LHS_NE_RHS_TID)},
/*   7 */	{[T_NUM]=SHIFT(9), [T_PLUS]=SHIFT(8), [T_MINUS]=SHIFT(7), [T_ID]=SHIFT(6), [T_LPAREN]=SHIFT(5)},
/*   8 */	{[T_NUM]=SHIFT(9), [T_PLUS]=SHIFT(8), [T_MINUS]=SHIFT(7), [T_ID]=SHIFT(6), [T_LPAREN]=SHIFT(5)},
/*   9 */	{[T_RPAREN]=REDUCE(P_LHS_NE_RHS_TNUM), [T_EXPO]=REDUCE(P_LHS_NE_RHS_TNUM), [T_MOD]=REDUCE(P_LHS_NE_RHS_TNUM), [T_DIV]=REDUCE(P_LHS_NE_RHS_TNUM), [T_MUL]=REDUCE(P_LHS_NE_RHS_TNUM), [T_MINUS]=REDUCE(P_LHS_NE_RHS_TNUM), [T_PLUS]=REDUCE(P_LHS_NE_RHS_TNUM), [T_NL]=REDUCE(P_LHS_NE_RHS_TNUM)},
/*  10 */	{[T_RPAREN]=REDUCE(P_LHS_NE_RHS_TPLUS_NE), [T_EXPO]=REDUCE(P_LHS_NE_RHS_TPLUS_NE), [T_MOD]=REDUCE(P_LHS_NE_RHS_TPLUS_NE), [T_DIV]=REDUCE(P_LHS_NE_RHS_TPLUS_NE), [T_MUL]=REDUCE(P_LHS_NE_RHS_TPLUS_NE), [T_MINUS]=REDUCE(P_LHS_NE_RHS_TPLUS_NE), [T_PLUS]=REDUCE(P_LHS_NE_RHS_TPLUS_NE), [T_NL]=REDUCE(P_LHS_NE_RHS_TPLUS_NE)},
/*  11 */	{[T_RPAREN]=REDUCE(P_LHS_NE_RHS_TMINUS_NE), [T_EXPO]=REDUCE(P_LHS_NE_RHS_TMINUS_NE), [T_MOD]=REDUCE(P_LHS_NE_RHS_TMINUS_NE), [T_DIV]=REDUCE(P_LHS_NE_RHS_TMINUS_NE), [T_MUL]=REDUCE(P_LHS_NE_RHS_TMINUS_NE), [T_MINUS]=REDUCE(P_LHS_NE_RHS_TMINUS_NE), [T_PLUS]=REDUCE(P_LHS_NE_RHS_TMINUS_NE), [T_NL]=REDUCE(P_LHS_NE_RHS_TMINUS_NE)},
/*  12 */	{[T_NUM]=SHIFT(9), [T_PLUS]=SHIFT(8), [T_MINUS]=SHIFT(7), [T_ID]=SHIFT(6), [T_LPAREN]=SHIFT(5)},
/*  13 */	{[T_EXPO]=SHIFT(22), [T_MOD]=SHIFT(21), [T_DIV]=SHIFT(20), [T_MUL]=SHIFT(19), [T_MINUS]=SHIFT(18), [T_PLUS]=SHIFT(17), [T_RPAREN]=SHIFT(31)},
/*  14 */	{[T_RPAREN]=SHIFT(30)},
/*  15 */	{[T_EOF]=REDUCE(P_LHS_NLineExp_RHS_TERROR_TNL), [T_LPAREN]=REDUCE(P_LHS_NLineExp_RHS_TERROR_TNL), [T_MINUS]=REDUCE(P_LHS_NLineExp_RHS_TERROR_TNL), [T_PLUS]=REDUCE(P_LHS_NLineExp_RHS_TERROR_TNL), [T_NUM]=REDUCE(P_LHS_NLineExp_RHS_TERROR_TNL), [T_ID]=REDUCE(P_LHS_NLineExp_RHS_TERROR_TNL), [T_ERROR]=REDUCE(P_LHS_NLineExp_RHS_TERROR_TNL)},
/*  16 */	{[T_EOF]=REDUCE(P_LHS_NLineExp_RHS_NE_TNL), [T_LPAREN]=REDUCE(P_LHS_NLineExp_RHS_NE_TNL), [T_MINUS]=REDUCE(P_LHS_NLineExp_RHS_NE_TNL), [T_PLUS]=REDUCE(P_LHS_NLineExp_RHS_NE_TNL), [T_NUM]=REDUCE(P_LHS_NLineExp_RHS_NE_TNL), [T_ID]=REDUCE(P_LHS_NLineExp_RHS_NE_TNL), [T_ERROR]=REDUCE(P_LHS_NLineExp_RHS_NE_TNL)},
/*  17 */	{[T_NUM]=SHIFT(9), [T_PLUS]=SHIFT(8), [T_MINUS]=SHIFT(7), [T_ID]=SHIFT(6), [T_LPAREN]=SHIFT(5)},
/*  18 */	{[T_NUM]=SHIFT(9), [T_PLUS]=SHIFT(8), [T_MINUS]=SHIFT(7), [T_ID]=SHIFT(6), [T_LPAREN]=SHIFT(5)},
/*  19 */	{[T_NUM]=SHIFT(9), [T_PLUS]=SHIFT(8), [T_MINUS]=SHIFT(7), [T_ID]=SHIFT(6), [T_LPAREN]=SHIFT(5)},
/*  20 */	{[T_NUM]=SHIFT(9), [T_PLUS]=SHIFT(8), [T_MINUS]=SHIFT(7), [T_ID]=SHIFT(6), [T_LPAREN]=SHIFT(5)},
/*  21 */	{[T_NUM]=SHIFT(9), [T_PLUS]=SHIFT(8), [T_MINUS]=SHIFT(7), [T_ID]=SHIFT(6), [T_LPAREN]=SHIFT(5)},
/*  22 */	{[T_NUM]=SHIFT(9), [T_PLUS]=SHIFT(8), [T_MINUS]=SHIFT(7), [T_ID]=SHIFT(6), [T_LPAREN]=SHIFT(5)},
/*  23 */	{[T_EOF]=REDUCE(P_LHS_NStmt_RHS_NStmt_NLineExp), [T_LPAREN]=REDUCE(P_LHS_NStmt_RHS_NStmt_NLineExp), [T_MINUS]=REDUCE(P_LHS_NStmt_RHS_NStmt_NLineExp), [T_PLUS]=REDUCE(P_LHS_NStmt_RHS_NStmt_NLineExp), [T_NUM]=REDUCE(P_LHS_NStmt_RHS_NStmt_NLineExp), [T_ID]=REDUCE(P_LHS_NStmt_RHS_NStmt_NLineExp), [T_ERROR]=REDUCE(P_LHS_NStmt_RHS_NStmt_NLineExp)},
/*  24 */	{[T_EXPO]=SHIFT(22), [T_RPAREN]=REDUCE(P_LHS_NE_RHS_NE_TEXPO_NE), [T_MOD]=REDUCE(P_LHS_NE_RHS_NE_TEXPO_NE), [T_DIV]=REDUCE(P_LHS_NE_RHS_NE_TEXPO_NE), [T_MUL]=REDUCE(P_LHS_NE_RHS_NE_TEXPO_NE), [T_MINUS]=REDUCE(P_LHS_NE_RHS_NE_TEXPO_NE), [T_PLUS]=REDUCE(P_LHS_NE_RHS_NE_TEXPO_NE), [T_NL]=REDUCE(P_LHS_NE_RHS_NE_TEXPO_NE)},
/*  25 */	{[T_EXPO]=SHIFT(22), [T_RPAREN]=REDUCE(P_LHS_NE_RHS_NE_TMOD_NE), [T_MOD]=REDUCE(P_LHS_NE_RHS_NE_TMOD_NE), [T_DIV]=REDUCE(P_LHS_NE_RHS_NE_TMOD_NE), [T_MUL]=REDUCE(P_LHS_NE_RHS_NE_TMOD_NE), [T_MINUS]=REDUCE(P_LHS_NE_RHS_NE_TMOD_NE), [T_PLUS]=REDUCE(P_LHS_NE_RHS_NE_TMOD_NE), [T_NL]=REDUCE(P_LHS_NE_RHS_NE_TMOD_NE)},
/*  26 */	{[T_EXPO]=SHIFT(22), [T_RPAREN]=REDUCE(P_LHS_NE_RHS_NE_TDIV_NE), [T_MOD]=REDUCE(P_LHS_NE_RHS_NE_TDIV_NE), [T_DIV]=REDUCE(P_LHS_NE_RHS_NE_TDIV_NE), [T_MUL]=REDUCE(P_LHS_NE_RHS_NE_TDIV_NE), [T_MINUS]=REDUCE(P_LHS_NE_RHS_NE_TDIV_NE), [T_PLUS]=REDUCE(P_LHS_NE_RHS_NE_TDIV_NE), [T_NL]=REDUCE(P_LHS_NE_RHS_NE_TDIV_NE)},
/*  27 */	{[T_EXPO]=SHIFT(22), [T_RPAREN]=REDUCE(P_LHS_NE_RHS_NE_TMUL_NE), [T_MOD]=REDUCE(P_LHS_NE_RHS_NE_TMUL_NE), [T_DIV]=REDUCE(P_LHS_NE_RHS_NE_TMUL_NE), [T_MUL]=REDUCE(P_LHS_NE_RHS_NE_TMUL_NE), [T_MINUS]=REDUCE(P_LHS_NE_RHS_NE_TMUL_NE), [T_PLUS]=REDUCE(P_LHS_NE_RHS_NE_TMUL_NE), [T_NL]=REDUCE(P_LHS_NE_RHS_NE_TMUL_NE)},
/*  28 */	{[T_EXPO]=SHIFT(22), [T_MOD]=SHIFT(21), [T_DIV]=SHIFT(20), [T_MUL]=SHIFT(19), [T_RPAREN]=REDUCE(P_LHS_NE_RHS_NE_TMINUS_NE), [T_MINUS]=REDUCE(P_LHS_NE_RHS_NE_TMINUS_NE), [T_PLUS]=REDUCE(P_LHS_NE_RHS_NE_TMINUS_NE), [T_NL]=REDUCE(P_LHS_NE_RHS_NE_TMINUS_NE)},
/*  29 */	{[T_EXPO]=SHIFT(22), [T_MOD]=SHIFT(21), [T_DIV]=SHIFT(20), [T_MUL]=SHIFT(19), [T_RPAREN]=REDUCE(P_LHS_NE_RHS_NE_TPLUS_NE), [T_MINUS]=REDUCE(P_LHS_NE_RHS_NE_TPLUS_NE), [T_PLUS]=REDUCE(P_LHS_NE_RHS_NE_TPLUS_NE), [T_NL]=REDUCE(P_LHS_NE_RHS_NE_TPLUS_NE)},
/*  30 */	{[T_RPAREN]=REDUCE(P_LHS_NE_RHS_TLPAREN_TERROR_TRPAREN), [T_EXPO]=REDUCE(P_LHS_NE_RHS_TLPAREN_TERROR_TRPAREN), [T_MOD]=REDUCE(P_LHS_NE_RHS_TLPAREN_TERROR_TRPAREN), [T_DIV]=REDUCE(P_LHS_NE_RHS_TLPAREN_TERROR_TRPAREN), [T_MUL]=REDUCE(P_LHS_NE_RHS_TLPAREN_TERROR_TRPAREN), [T_MINUS]=REDUCE(P_LHS_NE_RHS_TLPAREN_TERROR_TRPAREN), [T_PLUS]=REDUCE(P_LHS_NE_RHS_TLPAREN_TERROR_TRPAREN), [T_NL]=REDUCE(P_LHS_NE_RHS_TLPAREN_TERROR_TRPAREN)},
/*  31 */	{[T_RPAREN]=REDUCE(P_LHS_NE_RHS_TLPAREN_NE_TRPAREN), [T_EXPO]=REDUCE(P_LHS_NE_RHS_TLPAREN_NE_TRPAREN), [T_MOD]=REDUCE(P_LHS_NE_RHS_TLPAREN_NE_TRPAREN), [T_DIV]=REDUCE(P_LHS_NE_RHS_TLPAREN_NE_TRPAREN), [T_MUL]=REDUCE(P_LHS_NE_RHS_TLPAREN_NE_TRPAREN), [T_MINUS]=REDUCE(P_LHS_NE_RHS_TLPAREN_NE_TRPAREN), [T_PLUS]=REDUCE(P_LHS_NE_RHS_TLPAREN_NE_TRPAREN), [T_NL]=REDUCE(P_LHS_NE_RHS_TLPAREN_NE_TRPAREN)},
/*  32 */	{[T_EXPO]=SHIFT(22), [T_MOD]=SHIFT(21), [T_DIV]=SHIFT(20), [T_MUL]=SHIFT(19), [T_MINUS]=SHIFT(18), [T_PLUS]=SHIFT(17), [T_RPAREN]=REDUCE(P_LHS_NE_RHS_TID_TEQUAL_NE), [T_NL]=REDUCE(P_LHS_NE_RHS_TID_TEQUAL_NE)},
};

static int
calc_lr_goto_table[33][TOTAL_NTER] = {
/*   0 */	{[N_E]=GOTO(3), [N_LineExp]=GOTO(2), [N_Stmt]=GOTO(1)},
/*   1 */	{[N_LineExp]=GOTO(23), [N_E]=GOTO(3)},
/*   2 */	{},
/*   3 */	{},
/*   4 */	{},
/*   5 */	{[N_E]=GOTO(13)},
/*   6 */	{},
/*   7 */	{[N_E]=GOTO(11)},
/*   8 */	{[N_E]=GOTO(10)},
/*   9 */	{},
/*  10 */	{},
/*  11 */	{},
/*  12 */	{[N_E]=GOTO(32)},
/*  13 */	{},
/*  14 */	{},
/*  15 */	{},
/*  16 */	{},
/*  17 */	{[N_E]=GOTO(29)},
/*  18 */	{[N_E]=GOTO(28)},
/*  19 */	{[N_E]=GOTO(27)},
/*  20 */	{[N_E]=GOTO(26)},
/*  21 */	{[N_E]=GOTO(25)},
/*  22 */	{[N_E]=GOTO(24)},
/*  23 */	{},
/*  24 */	{},
/*  25 */	{},
/*  26 */	{},
/*  27 */	{},
/*  28 */	{},
/*  29 */	{},
/*  30 */	{},
/*  31 */	{},
/*  32 */	{},
};

static int
calc_sync_token[TOTAL_NTER][9] = {
	[N_Stmt] = { T_ERROR, T_ID, T_NUM, T_PLUS, T_MINUS, T_LPAREN, T_EOF, -1 },
	[N_LineExp] = { T_ERROR, T_ID, T_NUM, T_PLUS, T_MINUS, T_LPAREN, T_EOF, -1 },
	[N_E] = { T_NL, T_PLUS, T_MINUS, T_MUL, T_DIV, T_MOD, T_EXPO, T_RPAREN, -1 },
};

#endif /* _CALC_GRM_H_ */
