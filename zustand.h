#ifndef ZUSTAND_H
#define ZUSTAND_H

class Ladegeraet;

class Zustand
{
public:
    virtual void bearbeiten( Ladegeraet* ) = 0;
};

class NichtLadend:public Zustand
{
private:
    static NichtLadend *nichtLadend;
    NichtLadend();
public:
    static NichtLadend* getNichtLadend();
    void bearbeiten( Ladegeraet* );
};

class NormalLadend:public Zustand
{
private:
    static NormalLadend *normalLadend;
    NormalLadend();
public:
    static NormalLadend* getNormalLadend();
    void bearbeiten( Ladegeraet* );
};

class SchnellLadend:public Zustand
{
private:
    static SchnellLadend *schnellLadend;
    SchnellLadend();
public:
    static SchnellLadend* getSchnellLadend();
    void bearbeiten( Ladegeraet* );
};

#endif // ZUSTAND_H
