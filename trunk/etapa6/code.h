
#include "tacs.h"
#include "astree.h"

TAC *codeGenerate(ASTREE *root);
TAC* outputParams(TAC* params);
void funCall(TAC* params, ASTREE* funcTree);
HASH_ELEMENT* findArg(int argCount, ASTREE* tree);
TAC* makeOps(int type, TAC* op1, TAC* op2);
TAC* makeIf(TAC* cond, TAC* then, TAC* els);
TAC* makeWhile(TAC* expr, TAC* cmd);
TAC* makeDoWhile(TAC* expr, TAC* cmd);
TAC* funcDecl(HASH_ELEMENT* symbol, TAC* type, TAC* params, TAC* cmds);
TAC* makeAtrVec(HASH_ELEMENT* symbol, TAC* exprIndex, TAC* cmd);