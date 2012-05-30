
#include "tacs.h"
#include "astree.h"

TAC *codeGenerate(ASTREE *root);
TAC* makeOps(int type, TAC* op1, TAC* op2);
TAC* makeIf(TAC* cond, TAC* then, TAC* els);
TAC* makeWhile(TAC* expr, TAC* cmd);
TAC* makeDoWhile(TAC* expr, TAC* cmd);
TAC* funcDecl(HASH_ELEMENT* symbol, TAC* type, TAC* params, TAC* cmds);