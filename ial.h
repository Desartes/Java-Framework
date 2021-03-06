#ifndef IAL_H_
#define IAL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "lex_key.h"
#include "err.h"


#define I_SORT 27


/*
*	Knuth-Morris-Prattov algoritmus
*	Quick sort algoritmus
*/
int *mall_kmp(char *pod, int len_p);
int kmp(char *ret,char *pod);
void quickSort( int[], int, int);
int partition( int[], int, int);

/*
*
*/
typedef struct {
  int instType;
  void *addr1;
  void *addr2;
  void *addr3;
  key typ;
} tInstr;

typedef struct listItem {
  tInstr instruction;
  struct listItem *next;
} *tListItemPtr;


typedef struct {
  struct listItem *first;
  struct listItem *last;
  struct listItem *active;
} tList;

void Listinit(tList *L);
void DisposeList(tList *L);
void InsertFirst(tList *L,tInstr instr);
void InsertLast(tList *L, tInstr instr);





/*
*	Praca s TS-tabulkou pomocou binnary tree
*/ 
struct var
{
	char key_val[BUFFER_SIZE];
	void *data;
	key typ;

	struct var *Lnode;
	struct var *Rnode;
};







typedef struct
{
	struct func *local;
	struct var *global;
}bin_tree;

struct func
{
	char key_val[BUFFER_SIZE];
	key typ;
	void *data;
	bin_tree *premen;
	struct func *Lnode;
	struct func *Rnode;
};

typedef struct bin_item {
  char key_val[BUFFER_SIZE];
  bin_tree *tree;
  struct bin_item *next;
} *binListitem;

typedef struct {
  struct bin_item *first;
  struct bin_item *last;
  struct bin_item *active;
} binList;





/*
*	inicializacia listu stromov
*
*/
void Biteminit(binList *BL);
void BinInsertLast(binList *BL, bin_tree *tree,char *class);


bin_tree *Tree_search(binList *BL,char *class);
/*
*	funkcie na pracu s bin tree pre variabiles
*
*/
void TSinit(bin_tree *table);
struct var *TSnodcreate(char *name, key typ, void *data);/*vytvorenie uzlu pre binnary tree prva pre premenne druha pre funkcie*/
int TSinsert(bin_tree *table, struct var *in);//priradenie uzla do binnary tree , volas len prvu druha je volana prvou
int TSNinsert(struct var **mark_nod, struct var *in);/*funkcie na inicializaciu prazdneho binnary tree*/
struct var * TSsearch(bin_tree *table, char *key);//vyhladanie uzla v binnary tree, opet volas len prvu
struct var * TSNsearch(struct var *mark_nod, char *key);


/*
*	funkcie na pracu stromov funkcii
*
*/
struct func * TSFnodcreate(char * name, key typ);
struct func *TSfuncsearch(bin_tree * table, char * key);
struct func * TSNfuncsearch(struct func *mark_nod, char *key);
int TSFinsert(bin_tree *table, struct func *in);
int TSNFinsert(struct func **mark_nod, struct func *in);
/*
*	toto je funkcia ktorou vkladas premennu alebo variabile do pola v binnary tree 
*	f_nazov je nazov funkcie AR_nazov je nazov premennej alebo parametru 
*	
*	Zavolas len prvu s nazvom funkcie do ktorej chces pridat premennu 
 *	typom premennej datami premenej a ono to samo vytvori node a aj priradi do binnary tree premen 
 *	akurat musis predtym vytvorit bin tree a zavolat funkciu na inicializaciu bin tree 
 *	+ tento tree nieje v zozname(liste) bin tree odkazes sa nan len cez tu strukturu funkcie jednotlivej
*/
int TSfuncinsert(bin_tree *table,char *f_nazov,char *AR_nazov,key typ,void *data,bin_tree *premen);
int TSNfuncinsert(struct func **mark_nod,char *f_nazov,char *AR_nazov,key typ,void *data,bin_tree *premen);

/*
int TScopy(bin_tree *table, bin_tree *N_table);//rekurzivne skopiruje cely binnary tree , opet volas len prvu
struct node *TSNcopy(struct node *nod);
*/
int DisposeALL(binList *list);//ostrani komplet vsetko ohladom binnary tree vratane class a celeho listu

int TSdispose(bin_tree * table);//odstrani cely konkretny binnary tree vratane elementov premennych pre funkcie v pliste opet volas len
int TSNdispose(struct var ** mark_nod);
int TSNFdispose(struct func **mark_nod);
//int TSFpardispose(struct f_elem *pList);

#endif