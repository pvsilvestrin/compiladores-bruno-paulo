//SEMANTIC ANALISYS 2012

#include "astree.h"

void checkDeclarations(ASTREE *root);
void checkUtilization(ASTREE *root);
void checkDataTypes(ASTREE *root);
void checkFunctionCallParameters(ASTREE *root);
void checkListParams(ASTREE *declParams, ASTREE *callParams, ASTREE *root);
int checkExpressionType(ASTREE *expression);