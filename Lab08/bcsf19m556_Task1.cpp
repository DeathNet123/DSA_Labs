#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

#define DUMMY 0
//Car Class Node...
class CarNode
{
    private:
        string company, brand, transmission, engine_capacity, seating_capacity, registered;
        int milage;
        float price;
        
    public:
        CarNode *next;
        CarNode *prev;
        //Non Paramerterized Constructor..
        CarNode()
        {
            this->company = "";
            this->brand = "";
            this->transmission = "";
            this->engine_capacity ="";
            this->seating_capacity = "";
            this->registered = "";
            this->milage = 0;
            this->price = 0.0f;
            this->next = NULL;
        }
        CarNode(string company, string brand,  string registered, int milage, float price, string transmission = "Automatic", string engine_capacity = "660 CC", string seating_capacity = "Capacity 4", CarNode *next = NULL, CarNode *prev = NULL)
        {
            this->company = company;
            this->brand = brand;
            this->registered = registered;
            this->milage = milage;
            this->price = price;
            this->transmission = transmission;
            this->engine_capacity = engine_capacity;
            this->seating_capacity = seating_capacity;
            this->next = next;
            this->prev = prev;
        }

        void show(void)
        {
            cout<<setw(10)<<company<<setw(10)<< brand<<setw(20)<<transmission<<setw(20)<<engine_capacity<<setw(20)<<seating_capacity<<setw(10)<<registered<<setw(10)<<milage<<setw(21)<<right<<price;
        }

        friend ostream& operator <<(ostream& os, const class CarNode &Car)
        {
            os<<Car.company<<' '<<Car.brand<<' '<<Car.engine_capacity<<" [ "<<Car.price<<" only ]"<<'\n';
            os<<Car.transmission<<' '<<Car.registered<<'\n';
            os<<"Seating Capacity: "<<Car.seating_capacity<<'\n';
            os<<"Milage: "<<Car.milage<<'\n';
            return os;
        }
        friend class ShowRoom;

};

class ShowRoom
{
    private:
        CarNode *head, *tail;
        void searchTransmission(string transmission)
        {
            cout<<"\nSearch Results for the Transmission: "<<transmission<<endl;
            CarNode *idx;
            for(idx = head->next; idx != NULL; idx = idx->next)
            {
                if(idx->transmission == transmission)
                    cout<<*idx;
            }
        }
    public:
        ShowRoom()
        {
            head = new CarNode();
            tail = NULL;
        }
        void addNewCar()
        {
            CarNode *newCar = new CarNode();
            if(tail == NULL)
            {
                head->next = newCar;
                newCar-> next = NULL;
                newCar->prev = head;
                tail = newCar;
            }
            else
            {
                tail->next = newCar;
                newCar->prev = tail;
                newCar->next = NULL;
                tail = newCar;
            }
        }
        //This function is replicating if i get time i will change it........
        void addNewCar(string company, string brand,  string registered, int milage, float price, string transmission = "Automatic", string engine_capacity = "660 CC", string seating_capacity = "Capacity 4", CarNode *next = NULL, CarNode *prev = NULL)
        {
            CarNode *newCar = new CarNode(company, brand, registered, milage, price, transmission, engine_capacity, seating_capacity);
            if(tail == NULL)
            {
                head->next = newCar;
                newCar-> next = NULL;
                newCar->prev = head;
                tail = newCar;
            }
            else
            {
                tail->next = newCar;
                newCar->prev = tail;
                newCar->next = NULL;
                tail = newCar;
            }
        }
        void SearchCompany(string company = "")
        {
            cout<<"\nSearch Results for the company: "<<company<<endl;
            CarNode *idx;
            for(idx = head->next; idx != NULL; idx = idx->next)
            {
                if(idx->company == company)
                    cout<<*idx;
            }
        }
        void SearchBrand(string brand = "")
        {
            cout<<"\nSearch Results for the Brand: "<<brand<<endl;
            CarNode *idx;
            for(idx = head->next; idx != NULL; idx = idx->next)
            {
                if(idx->brand == brand)
                    cout<<*idx;
            }
        }
        void SearchManual()
        {
            searchTransmission("Manual");
        }
        void SearchAutomatic()
        {
            searchTransmission("Automatic");
        }

        void SearchInPriceRange(int low, int high)
        {
            cout<<"\nSearch Results for the Price Range Between: "<<low<<'-'<<high<<'\n';
            CarNode *idx;
            for(idx = head->next; idx != NULL; idx = idx->next)
            {
                if(idx->price >= low && idx->price <= high)
                    cout<<*idx;
            }
        }
        friend ostream& operator << (ostream& os, const class ShowRoom &room)
        {
            os<<setw(10)<<"Company"<<setw(10)<<"Brand"<<setw(20)<<"Transmission"<<setw(20)<<"Engine_capacity"<<setw(20)<<"Seating_capacity"<<setw(15)<<"Registered"<<setw(10)<<"Milage"<<setw(20)<<"Price"<<"\n";
            CarNode *idx;
            for(idx = room.head->next; idx != NULL; idx = idx->next)
            {
                idx->show();
                os<<'\n';
            }
            return os;
        }
};
int main(void)
{
    ShowRoom room;
  
    room.addNewCar("Toyota", "Yaris", "No", 0, 220000.0f, "Automatic", "1800cc", "6 Capacity");
    room.addNewCar("Toyota", "Corolla", "No", 0, 220000.0f, "Automatic", "1800cc", "6 Capacity");
    //room.SearchCompany("Toyota");
   // room.SearchBrand("Corolla");
   cout<<room;
    return 0;
}