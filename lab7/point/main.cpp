//
// Created by Krzysiek on 23.04.2017.
//

#include "Point3D.h"

int main(){
    algebra::Point3D p1;
    std::cout <<"\n";
    algebra::Point3D p2(1,2,3);
    std::cout << "\n\n";

 /* Odp zadanie 5

    Podczas tworzenia obiektu Point3D najpierw wywolywany jest konstruktor
    (odpowiednio parametryczny lub nie) Point3D, który następnie wywołuje
    odpowiedni konstruktor Point.

    Podobnie najpierw wywoływany jest destruktor ~Point3D, który wywołuje
    destruktor ~Point.
*/

    algebra::Point p(3,1);
    double d=p.Distance(p2);
    std::cout << "odleglosc: "<< d << std::endl;

/*  Odp zadanie 6

    wywolując metodę odlegość dla punktu typu Point dając jako arguement obiekt
    Point3D następuje niejawne rzutowanie obiektu Point3D na obiekt Point,
    czyli metoda pomija argument z_.

*/



/*  Odp zadanie 7

    wywołanie cout << p2 << endl nie zostanie wykonane. kompilator zaprotestuje:

 error: no match for 'operator<<' (operand types are 'std::ostream
 and 'algebra::Point3D')

    czyli nie odnajduje odpowiedniego operatora dla podanych typów.

*/

    return 0;
}