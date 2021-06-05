#include <iostream>
#include "Node.h"
#include "DLL.h"


using namespace std;

int main(){

    DLL doubly_linkedList ;

    doubly_linkedList.insert_front(5) ;
    doubly_linkedList.insert_front(1) ;
    doubly_linkedList.insert_front(8) ;
    doubly_linkedList.insert_front(2) ;

    doubly_linkedList.print() ;
    doubly_linkedList.delete_node_withValue( 5 ) ;
    doubly_linkedList.print() ;
    doubly_linkedList.insert_end(5) ;
    doubly_linkedList.insert_end(6) ;
    doubly_linkedList.insert_end(1) ;
    doubly_linkedList.print() ;
    doubly_linkedList.delete_allNodes_withValue( 1 ) ;
    doubly_linkedList.print() ; // 8 4 4 1
    doubly_linkedList.insert_end(9) ;
    doubly_linkedList.print() ; // 2 8 5 6 9
    doubly_linkedList.delete_even_position() ;
    doubly_linkedList.print() ; // 2 5 9
    cout << doubly_linkedList.is_palindrome() << endl ; // false
    doubly_linkedList.insert_end(9) ;
    doubly_linkedList.print() ;
    doubly_linkedList.print_addresses() ;
    doubly_linkedList.reverse_() ;
    doubly_linkedList.print() ;
    doubly_linkedList.print_addresses() ;
    cout << doubly_linkedList.find_middle() << endl ;
    doubly_linkedList.print_reverse() ; // 9 9 5 2
    doubly_linkedList.back_for_ward( 2 ) ;
    doubly_linkedList.print() ;


}
