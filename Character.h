#pragma once
#include <SFML/Graphics.hpp>
#include <time.h>
#include <vector>
#include<sstream>
#include <list>
#include<iostream>
#include<math.h>
#include<cstdlib>
#include "Animation.h"
using namespace std;
using namespace sf;
class Vatthe{
protected:
    string name;//cho biet ten cua object
    string status;
    bool end_;// check xem no da chet hay chua false laf chet, true laf chua

public:
    float x,y,dx,dy,R,angle;
    Animation ami;
    int ap = 0;
    int app_px = 0;
    Vatthe(){};
    void Setting(Animation &a ,int X ,int Y,float Angle=0)
    {
        ami = a;
        x = X+100;
        y = Y+300;
        angle = Angle;
        R = 20;
        end_= true;
     //   name = "";
    }
    virtual void update(){
        ami.update(13);
        }

    float getx()
    {
        return x;
    }
    float gety()
    {
        return y;
    }
    float getr()
    {
        return R;
    }
    void set_name(string ss)
    {

        name = ss;
    }
    // in object ra man hinh
    void draw__(RenderWindow &rw)
    {

        ami.sprite.setPosition(x,y);
        rw.draw(ami.sprite);

    }
    bool get_end()
    {

        return end_;
    }
    virtual void set_hp(float x){};
    virtual float get_hp(){};
    virtual int get_explo(){};
    virtual void set_explo(int x){};
    void set_end(bool x)
    {
        end_ = x;
    }
    string get_name()
    {
        return name;
    }
    virtual ~Vatthe(){};

};



class Player : public Vatthe{

private:
    int life;
    float mana;
    float hp;
    int explo;
    //string name;

public:
    Player ()
    {
        mana = 1000;
        hp = 1000;
        dx = 0;
        dy = 0;
        end_ = true;
        name = "Player";
        explo = 0;
      //  point = 0;
    }
    void set_mana(float x)
    {

        mana += x;
    }
    float get_mana()
    {
        return mana;
    }
    void set_hp(float x)
    {

        hp += x;
    }
    float get_hp()
    {
        return hp;
    }
    void set_explo(int x)
    {
        explo+=x;
    }
    int get_explo()
    {

        return explo;
    }
    void update(){
        ami.update(13);

      //  x += dx, y += dy;
		dx = 0, dy = 0;
		if (x > 640) x = 640; if (x < -80) x =-80 ;

    }

};




class bullet_ri : public Vatthe
{
private:
    int dm;

public:
    bullet_ri()
    {
        name = "bullet";

    }
    bullet_ri(string s)
    {
        name = s;
    }
    void appear(int xx,int yy)
    {
        x = xx;
        y = yy;
    }
    void update()
    {

        x+=3;
        if(x>750 || x<-100) end_ = true;

    }


};


class bullet_le : public Vatthe
{
private:
    int dm;

public:
    bullet_le()
    {
        name = "bullet";
        end_ =  true;
      //  R = 5;
    }

    void appear(int xx,int yy)
    {
        x = xx;
        y = yy;
    }
    void update()
    {
        //if(t== "Right")
        x-=3;
        if(x>750 || x<-100) end_ = false;


    }


};

class dragon_fire : public Vatthe{
public:
    dragon_fire()
    {
        name = "Fire";
        end_  =true;
    }
    void appear(int xx,int yy)
    {
        x = xx;
        y = yy;
    }
    void update()
    {
        ami.update(12);
        x+=1;
        if(y<=0)
        y+=0.5;
        if(y>=0) end_ = false;

    }
};
class enemies_le: public Vatthe{
private:
    int lev;
public:
    enemies_le()
    {
        y = -50;
      //  R = 10;
        name = "ene_le";
        end_ = true;
        lev = 2;
    }
    void set_move(int x)
    {
        lev = x;
    }
    void update()
    {
        ami.update(13);
        x+=0.1*lev;
        if( x>=800) end_ = false;
    }


};


class enemies_ri: public Vatthe{
private:
    int lev;
public:
    enemies_ri()
    {
        y = -50;
      //  R = 10;
        name = "ene_ri";
        end_ = true;
        lev= 2;
    }
    void set_move(int x)
    {

        lev = x;
    }
    void update()
    {
        ami.update(13);
        x-=0.1*lev;
        if(x<-200) end_ = false;
    }


};
class ene_sky_le : public Vatthe{
    int lev;
public:
    ene_sky_le()
    {
        y = -150;
        end_ = true;
        name = "ene_sky_le";
        lev = 2;
    }
        void set_move(int x)
    {

        lev = x;
    }
    void update()
    {
        ami.update(13);
        x+=0.2*lev;
        if(x>800) end_ = false;
    }

};
class ene_sky_ri : public Vatthe{
    int lev;
public:
    ene_sky_ri()
    {
        y = -150;
        end_ = true;
        name = "ene_sky_ri";
        lev = 2;
    }
        void set_move(int x)
    {

        lev = x;
    }
    void update()
    {
        ami.update(13);
        x-=0.2*lev;
        if(y<0&& x >= 350)
        y+=0.05*lev;
        else y-=0.05*lev;
        if(x<-250) end_ = false;
    }

};

