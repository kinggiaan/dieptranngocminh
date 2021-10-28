#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H
#include "main.h"

class SymbolTable
{
public:
    class Node;
protected:
    Node* root;
public:
    SymbolTable(): root(NULL){};
public:
    class Node
    {
    private:
        Node* left;
        Node* right;
        Node* parent;
        string name;
        string type;
        string stat;
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
        Node(string name, string type, string stat, int level, Node* parent) : name(name), type(type), stat(stat), level(NULL), left(NULL), right(NULL), parent(parent){}
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
    void insert(Node* node, bool& redeclared, int& num_comp, int& num_splay){
    if(this->root == NULL){
        this->root = new Node(node->name, node->type, node->stat, node->level,NULL);

    }
    else{
        Node* pWalk = this->root;
        while(pWalk != NULL){
            node->parent = pWalk;
            if(isFistKeyHigher(node, pWalk) == 1){
                pWalk = pWalk->right;
            }
            else if(isFistKeyHigher(node, pWalk) == 2){
                pWalk = pWalk->left;
            }
            else redeclared = true;
        } 
        if(isFistKeyHigher(node, node->parent) == 1){
            node->parent->right = new Node(node->name, node->type, node->stat, node->level, node->parent);
        }
        else if(isFistKeyHigher(node, node->parent) == 2){
            node->parent->left = new Node(node->name, node->type, node->stat, node->level, node->parent);
        }
    }
}
};

#endif
