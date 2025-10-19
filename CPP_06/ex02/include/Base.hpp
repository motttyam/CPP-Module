#ifndef BASE_HPP
#define BASE_HPP

class A;
class B;
class C;

class Base { public: virtual ~Base(); };
    
    Base * generate(void);
    void identify(Base *p);
    void identify(Base &p);

#endif