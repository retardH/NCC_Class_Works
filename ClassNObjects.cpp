//
// Created by HtetZarni on 14/12/2022.
//

#include "iostream"

using namespace std;

int main() {

    class Car {

    protected:
        string ownerName;

    private:
        int ownershipID;

    public:
        string brandName;
        int modelNumber;
        int enginePower;

        void idSetter(int id) {
            ownershipID = id;
            cout << "Owner's ID is " << ownershipID <<endl;
        }


    };
    class derivedCar : public Car {  // derived class(inheritance)

    public:

        void ownerNamePrint(string name) {

            ownerName = name;

            cout << "Owner's name is " << ownerName << endl ;

        }


    };

    Car BMW;
    BMW.brandName = "BMW";
    cout<<BMW.brandName<<endl;
    BMW.idSetter(776688);

    derivedCar Toyota;
    Toyota.ownerNamePrint("Hpaungsuez");

    return 0;
};