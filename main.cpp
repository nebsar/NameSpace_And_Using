/* 
 * File:   main.cpp
 * Author: Eagleye
 *
 * Created on September 11, 2018, 9:05 PM
 */

#include <iostream>
#include <utility>
#include <vector>
#include <iterator>
#include <string>

class A {
public:

    using classA = A; /* to use a custom name instead of a TYPE or CLASS NAME
                       *  if you use this inside the class you can use it only
                       * inside this class or inside derived classes.
                       */

    using str = std::string; /* This example is the same usage of below line of code */

    typedef int number; /* to define a type_name out of existing types
                         * this usage is NOT FOR CLASS!!!!!!!!!!!
                         */

    void f(int a);

private:

    number num = 0;
};

using classA = A; /*if we use this globally and before the class declaration 
                    * we can use it globally
                    */

class B : private classA {
public:

    void g() {
        using namespace std; // local scope namespace calling;
        cout << "from D" << '\n';
    }

    void h() {
        using std::cout;

        cout << "From D function h()" << '\n';
    }

    /*   using namespace std; /* this is illegal, since a namespace is called in class scope
     * a namespace should be called locally in a function
     * or globally out of the class scope.
     */

    using classA::f; /* since B is derived from A in "private" access specifier 
                 * if we want to use f() function from A then we need to 
                 * declare as "using A::f;" in the class scope
                 * Since class A is named as classA, we use classA::f to demonstrate the usage 
                 */
};

class C : public classA { /* Since classA is defined as a custom name of class A
                           * globally we can use it here                         
                           */
public:

    using A::f; /* to overcome the name hiding we use this declaration;*/
    void f(); /* this function does not overrides the function inside classA
               * in order to override the function, f function should be declare as virtual
               * or we should use "using A::f;" !!!!!!!!!!!!!!!!!!!!
               */

};

//A::f; // this usage is illegal, since this is out of class scope.

//////////////////* Anonymous namespace*///////////////////////////////////////

//static void h() {
//    std::cout << "h() static function" << '\n';
//}

static void k() {
    std::cout << "k() static function" << '\n';
}

namespace {

    void k() {
        std::cout << "k() anonymous namespace" << '\n';
    }

    void h() {
        k(); // function h() calls the function k() in the same namespace.
        std::cout << "h() anonymous namespace" << '\n';
    }


}
///////////////////////////////////////////////////////////////////////////////

int main(int argc, char** argv) {


    h();

    return 0;
}

