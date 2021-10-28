#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H
#include "main.h"

void insert(Node* node, ){
    if(root == NULL){
        this->root = new Node;
    }
    else{
        pWalk = root;
        while(pWalk != NULL){
            node->parent = pWalk;
        } 
    }
}
class SymbolTable
{
public:
    class Node
    {
    private:
        Node* left;
        Node* right;
        Node* parent;
        string name;
        string type;
        string state;
        int level;
    public:
        Node()
        {
            name = "";
            type = "";
            stat = "";
            level = -1;
            left = NULL;
            right = NULL;
            parent = NULL;
        }    
        Node(string name, int type, string stat, int level, Node* parent : name(name), type(type), stat(stat), level(NULL), left(NULL), right(NULL), parent(parent)){
            string getName(){
                return this->name;
            }
            string getType(){
                return this->type;
            }
            string getStat(){
                return this->stat;
            }
            int getLevel(){
                return this->level;
            }
        };
    }
protected:
    Node* root;
public:
    SymbolTable(): root(NULL);
public:
       
    public:
    SymbolTable() {}
    void run(string filename);
    int isFistKeyHigher(Node* a, Node* b){
        if(a->level > b->level) return 1; // a>b
        else if(a->level < b->level) return 2; // a<b
        else{
            if ((a->name).compare(b->name) > 0) return 1;
            else if((a->name).compare(b->name) < 0) return 2;
            else return 3; // a = b
        }
    }
};
#endif