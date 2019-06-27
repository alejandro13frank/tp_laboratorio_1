#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

int parser_EntregasFromText(FILE* pFile , LinkedList* pArrayListEntregas);
int parser_EntregasFromBinary(FILE* pFile , LinkedList* pArrayListEntregas);
#endif
