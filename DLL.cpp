#include "Node.h"
#include "DLL.h"
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std ;

DLL::DLL(){

     length = 0 ;
     head = tail = 0 ;
}

void DLL::link( Node *first , Node *second ){

     if( first )
          first->next = second ;
     if( second )
          second->prev = first ;
}

void DLL::insert_front( int value ){
     length++ ;
     Node *item = new Node( value ) ;

     if(!head )
          head = tail = item ;
     else{
          link( item , head ) ;
          head = item ;
     }

     head->prev = nullptr ;
}

void DLL::insert_end( int value ){

     Node *item = new Node( value ) ;
     length++ ;

     if( !head )
          head = tail = item ;
     else{

          link( tail , item ) ;
          tail = item ;
     }

}

void DLL::embed_after( Node *prev , int value ){

     Node *item = new Node( value ) ;

     Node *curr = prev->next ;

     link( prev , item ) ;
     link( item , curr ) ;
}

void DLL::insert_sorted( int value ){

     if( !head || value <= head->data )
          insert_front( value ) ;
     else if( value >= tail->data )
          insert_end( value ) ;
     else{

          for( Node *curr = head ; curr ; curr = curr->next ){

               if( value <= curr->data ){
                    embed_after( curr->prev , value ) ;

                    break ;
               }
          }
     }
}

void DLL::delete_front(){

     if( !head )
          return;
     Node *curr = head->next ;
     delete_node( head ) ;
     head = curr ;

     if( !head )
          tail = head ;
     else
          head->prev = nullptr ;

}

void DLL::delete_end(){

     if( !head )
          return;

     Node *newTail = tail->prev ;
     delete_node( tail ) ;
     tail = newTail ;

     if( !tail )
          head = tail ;
     else
          tail->next = nullptr ;
}

Node *DLL::delete_link( Node *curr ){

     Node *previous = curr->prev ;
     link( curr->prev , curr->next ) ;
     delete_node(curr) ;

     return previous ;
}

void DLL::delete_node_withValue( int value ){

     if( !head )
          return ;

     else if( head->data == value ){

          delete_front() ;

     }else{

     for( Node *curr = head ; curr ; curr= curr->next ){

          if( curr->data == value ){

               curr = delete_link( curr ) ;

               if( !curr->next ){
                    tail = curr ;
                    break ;
               }
          }

     }
     }
}


void DLL::delete_allNodes_withValue( int value ){

     if( !head )
          return ;

     else if( head->data == value ){

          delete_front() ;

     }else{

     for( Node *curr = head ; curr ; curr= curr->next ){

          if( curr->data == value ){

               curr = delete_link( curr ) ;

               if( !curr->next ){
                    tail = curr ;
               }
          }

     }
     }

}

void DLL::delete_even_position(){

     if( !head || length <= 1 )
          return;

     for( Node *curr = head->next ; curr ; curr = curr->next ){

          curr = delete_link( curr ) ;

          if( !curr->next ){

               tail = curr ;

          }else{
               curr = curr->next ;
          }

     }

}

bool DLL::is_palindrome(){

     int len = length / 2 ;
     Node *left = head , *right = tail ;

     while( len-- ){

          if( left->data != right->data )
               return 0 ;
          left = left->next ;
          right = tail->prev ;
     }
     return 1 ;

}

/*void DLL::swap_head_tail( Node *head , Node *tail){

     Node *next_head = head->next , *prev_tail = tail->prev ;

     link( tail , next_head ) ;
     link( prev_tail , head ) ;
     head = prev_tail->next ;
     tail = next_head->prev ;
     link( nullptr , tail ) ;
     link( head , nullptr ) ;
}*/

int DLL::find_middle(){

     Node *left = head , *right = tail ;

     while( right != left && left->next != right ){

          left = left->next , right = right->prev ;
     }
     return right->data ;
}

Node* DLL::get_nth_node( int i ){

     int j = 1 ;

     for( Node *curr = head ; curr ; j++ , curr = curr->next ){
          if( i == j )
               return curr ;
     }
     return nullptr ;
}

Node* DLL::get_Back_nth_nod( int i ){

     int j = 0 ;

     for( Node *curr = tail ; curr ; curr = curr->prev ){
          if( i == ++j )
               return curr ;
     }
     return nullptr ;
}

void DLL::back_for_ward( int i ){

     if( !head )
          return ;
     Node *first = get_nth_node( i ) , *second = get_Back_nth_nod( i ) ;

     if( first == second )
          return ;

     if( first->prev == second )
          swap( first , second ) ;

     Node *prev_first=first->prev , *prev_second=second->prev , *next_first=first->next , *next_second=second->next ;

     if( first->next = second ){
          link( prev_first , second ) ;
          link( second , first ) ;
          link( first , next_second ) ;
     }else{

          link( prev_first , second ) ;
          link( second , next_first ) ;

          link( prev_second , first ) ;
          link( first , next_second ) ;
     }
     if( !prev_first && !next_second )
          head = second , tail = first ;

}

void DLL::reverse_(){

     Node *first = head , *second = head->next , *next_move = nullptr ;
     while( second ){
         next_move = second->next ;
         link( second , first ) ;
         first = second , second= next_move ;
     }
     swap( head , tail ) ;
     head->prev = tail->next = 0 ;
}

void DLL::print(){

     for( Node *curr = head ; curr ; curr = curr->next ){

          cout << curr->data << " " ;

     }
     cout << endl ;
}
void DLL::print_reverse(){

     for( Node *curr = tail ; curr ; curr = curr->prev ){
          cout << curr->data << " " ;
     }
     cout << endl ;
}
void DLL::print_addresses(){

     for( Node *curr = head ; curr ; curr = curr->next ){

          cout << curr << " " ;

     }
     cout << endl ;
}
/*DLL::~DLL(){
     cout << "Des. \n" ;

     for( Node *curr = head ; curr ; curr = curr->next ){

          cout << curr->data << " " ;
          delete curr ;
     }
}
*/
void DLL::delete_node( Node *node ){
     delete node ;
     length-- ;
}

