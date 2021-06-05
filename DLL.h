#ifndef DLL_H
#define DLL_H
#include "Node.h"


class DLL{

    private:

         Node *head ;
         Node *tail ;
         int length ;

    public:

     DLL() ;
     Node *gethead(){ return head ; }
     Node *getTail(){ return tail ; }
     void delete_node( Node *node ) ;
     void link( Node *first , Node *second) ;
     // Insertion
     void insert_end( int value ) ;
     void insert_front( int value ) ;
     void embed_after( Node *prev , int value ) ;
     void insert_sorted( int value ) ;
     // Deletion
     void delete_front() ;
     void delete_end() ;
     Node *delete_link( Node *curr ) ;
     void delete_node_withValue( int value ) ;
     void delete_allNodes_withValue( int value ) ;
     void delete_even_position() ;
     void delete_odd_position() ;

     // Printing
     void print() ;
     void print_reverse() ;
     void print_addresses() ;
     // A nice methods
     bool is_palindrome() ;
     void swap_head_tail( Node *head , Node *tail) ;
     int find_middle() ;
     void back_for_ward( int i ) ;
     void reverse_() ;

     // get nodes
     Node* get_nth_node( int i ) ;
     Node* get_Back_nth_nod( int i ) ;
     //~DLL() ;


};

#endif // DLL_H
