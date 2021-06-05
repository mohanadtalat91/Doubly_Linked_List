#ifndef NODE_H
#define NODE_H


struct Node{

     Node *next ;
     Node *prev ;
     int data ;

     Node( int value ) ;
     ~Node() ;
};

#endif // NODE_H
