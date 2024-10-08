#ifndef STRUCTS_H
#define STRUCTS_H

/* Include Standard Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdarg.h>
#include <string.h>
#include <limits.h>

/* Struct Definitions */
typedef struct {
    FILE* orderFile; 
    char name[30];
    char address[30];
    char paymentMethod[20];
    char cpf[12];
} TUser;

typedef struct Produto {
    int cod;
    unsigned long int qtd;
    char name[30];
    char due_date[11];
    double value;
} TProd;

typedef struct Orderlist {
    int cod;
    int numOfTypes;
    char date[11];
    double value;
} TOrder;

/* User Functions */
TUser* user(char *name, char *address, char *paymentMethod, char *cpf);
int sizeUser(void);
int qtdUserInFile(FILE* file);
void printUser(TUser *user);
void generateUserBase(const char *filename, int numberOfUsers);
void generateRandomCPF(char* cpf);
void generateRandomName(char* name);
void generateRandomAddress(char* address);
void generateRandomPaymentMethod(char* paymentMethod);

/* Product Functions */
TProd* prod(int cod, int qtd, char *name, char *duedate, double value);
void save(TProd *prod, FILE *out);
TProd* readProd(FILE *in);
void printProd(TProd *prod);
int sizeProd(void);
int number_of_products(FILE* arq);
void c_ordenate_database(FILE *out, int tam);
void mix_up(int *vet, int MAX, int exchanges);
void c_disorded_database(FILE *out, int tam, int exchanges);
void printBase(FILE *out);
TProd* findProdSequential(int cod, FILE *arq);
void displayEditMenu(TProd *p);
void editProduct(int cod, FILE *stock);
void processEditChoice(int choice, TProd *p);
void posSearchProcess(TProd* p);
void preRemoveProcess(TProd* p, FILE *stock);
TProd* searchAndPrintProd(TProd* p, FILE* stock);

/* Order Functions */
TOrder* order(TUser* user, int numOfTypes, char *date);
void orderPrint(TOrder *order);

#endif /* STRUCTS_H */
