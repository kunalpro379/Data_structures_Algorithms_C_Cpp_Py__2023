class Car{
    private: int speed;
    public:
    Car(){
        speed=0;
    }
    void accelerate(){
        speed+=10;
    }
    int getSpeed(){
        return speed;
    }

};
int main(){
    Car c;
    c.accelerate();
}

/*
️Compilation

Class layout recorded

Functions compiled once

Object creation
Stack
┌─────────────┐
│ c.speed = 0 │ ← constructor ran
└─────────────┘

Method call
accelerate(&c)
LOAD speed
ADD 10
STORE speed

*/
/*
class Car {
public:
    int speed;
    void drive();
};

A class does NOT occupy memory by itself
Think of class as:
A compile-time blueprint
A type definition
A layout description
Compiler stores:
Member variable types & order
Member function signatures
Access rules (public/private/protected)

No RAM allocation yet
Class = instructions on how memory should look when an object is created
Object Instantiation
Car c1;
What happens behind the scenes

Compiler already knows Car layout

Stack memory is allocated for c1

Member variables get actual space
class Car {
    int speed;   // 4 bytes
};

Stack Memory
┌─────────────┐
│ c1.speed    │  ← 4 bytes
└─────────────┘
Object = actual memory block

Car* c2 = new Car();
Stack                Heap
┌─────────┐        ┌─────────────┐
│ c2 ptr  │ ───▶   │ speed       │
└─────────┘        └─────────────┘
| Thing            | Stored where          |
| ---------------- | --------------------- |
| Object pointer   | Stack                 |
| Object data      | Heap                  |
| Member functions | Code segment (shared) |

Member Variables
class Car {
public:
    int speed;
    float fuel;
};

Car object (8 bytes total)
┌─────────────┐
│ speed (4B)  │
├─────────────┤
│ fuel  (4B)  │
└─────────────┘

Every object has its own copy of member variables
Member variables are NOT shared

Car c1;
Car c2;
Stack
┌─────────────┐
│ c1.speed    │
│ c1.fuel     │
├─────────────┤
│ c2.speed    │
│ c2.fuel     │
└─────────────┘

Member Functions
class Car {
public:
    int speed;
    void drive() {
        speed += 10;
    }
};

Member functions do NOT live inside objects
They are stored once in memory.
How drive() works internally
Compiler converts:
c1.drive();
Into something like:
Car_drive(&c1);

void Car_drive(Car* this) {
    this->speed += 10;
}

this pointer
Automatically passed
Points to calling object

Code Segment:
┌───────────────────────┐
│ Car::drive()          │ ← single copy
└───────────────────────┘

Stack:
┌─────────────┐
│ c1.speed    │
└─────────────┘

*/
/*

Access Specifiers
public:
    int speed;

 Accessible everywhere
 No restriction
Compiler allows:

c1.speed = 100;

private
private:
    int speed;


Cannot access outside class

Important:
Private is NOT a memory protection

A compile-time rule
Compiler enforces it
Memory still exists normally
class Car {
private:
    int speed;
};
Car object memory
┌─────────────┐
│ speed       │ ← still there
└─────────────┘

protected
protected:
    int speed;
Accessible in:

Same class

Child classes (inheritance)

Still:
No special memory handling
Compiler access rule only


*/






















