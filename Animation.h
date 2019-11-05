
#pragma once
#include <SFML/Graphics.hpp>
#include <time.h>
#include <vector>
#include<sstream>
#include <list>
#include<iostream>
#include<math.h>
#include<cstdlib>

using namespace std;
using namespace sf;
class Animation
{
private:

	vector <IntRect> frame;
	vector < Texture > frames;
	vector < Texture > hinh;
	vector < IntRect > khung;
	string tt;
    string st;
    int sizehinh,sizekhung;
public:
    Sprite sprite;
    double Frame, speed,fr;
    Animation(){};
    // dua hinh anh vao vaf set khung hinh cho hinh anh day
	Animation(int b, int e,double sp)
	{
	    frames.clear();
	    frame.clear();
	    Frame  = 0;
	    fr = 0;
	    sizekhung = 0;
	    sizehinh = 0;
	    speed  = sp;
	    for(int i = b ; i <= e ; i ++)
        {
            Texture t;
            string s="";
            string sm = "mega/";
            stringstream ss;
            ss << i;
            ss >> s;
            s+=".png";
            t.loadFromFile(sm+s);// dua anh vao
            frames.push_back(t);// luu vao 1 vector hinh
            frame.push_back(IntRect(0,0,t.getSize().x , t.getSize().y));//luu khung anh
           // cout << t.getSize().y <<" "<< t.getSize().x <<endl;
        }

	}
	// cai dat trang thai "Stay" laf dung yen , "Run" la chay
	void set_tt(string t)
	{

	    tt = t;
	}
	string get_tt()
	{
	    return tt;
	}
	// cai dat huong "Right","Left",Up
	void set_st(string s)
	{
	    st = s;
	}
	string get_st()
	{
	    return st;
	}
        // tao sqrite de in ra man hinh tung khung hinhf 1 va vi tri khoi dau cua no
        //sprite.setTexture(hinh[0]);
        //sprite.setTextureRect(khung[0]);
        //sprite.setOrigin(-100,-300);
	void set_ani(int be, int ed)
	{

	    khung.clear();

	    hinh.clear();
	    //Frame = 0;
	    //fr = 0;
	   // speed = sp;
	    for(int i = be ; i <= ed ; i++ )
        {
            hinh.push_back(frames[i]);
            khung.push_back(frame[i]);
        }
        // tao sqrite de in ra man hinh tung khung hinhf 1 va vi tri khoi dau cua no
        sprite.setTexture(hinh[0]);
        sprite.setTextureRect(khung[0]);
        sprite.setOrigin(-100,-300);


	}

	void App()
	{
	    hinh.clear();
	    khung.clear();
	    for(int i = 0 ; i <= 16 ; i++ )
            {
                hinh.push_back(frames[i]);
                khung.push_back(frame[i]);
            }
        sprite.setTexture(hinh[0]);
        sprite.setTextureRect(khung[0]);
        sprite.setOrigin(-100,-300);
	}
	void Run()
	{
	    khung.clear();
        hinh.clear();
	    if(tt == "Right")
        {
            if(st != "Up")
            for(int i = 34 ; i <= 47 ; i++ )
            {
                hinh.push_back(frames[i]);
                khung.push_back(frame[i]);
            }
            if(st == "Up")
                {
                    for(int i = 22 ; i <= 22 ; i++ )
                    {
                        hinh.push_back(frames[i]);
                        khung.push_back(frame[i]);
                    }
                }

        }
        if( tt == "Left")
        {
            if(st != "Up")
            for(int i = 95 ; i <= 108 ; i++ )
            {
                hinh.push_back(frames[i]);
                khung.push_back(frame[i]);
            }
            if(st == "Up")
                {
                    for(int i = 83 ; i <= 83 ; i++ )
                    {
                        hinh.push_back(frames[i]);
                        khung.push_back(frame[i]);
                    }
                }

        }
        sprite.setTexture(hinh[0]);
        sprite.setTextureRect(khung[0]);
        sprite.setOrigin(-100,-300);

	}
	void Jump()
	{
	    khung.clear();
	    hinh.clear();
        if(tt == "Right")
        {
            for(int i = 22 ; i <= 22 ; i++ )
            {
                hinh.push_back(frames[i]);
                khung.push_back(frame[i]);
            }
        }
        if(tt == "Left")
        {
            for(int i = 83 ; i <= 83 ; i++ )
            {
                hinh.push_back(frames[i]);
                khung.push_back(frame[i]);
            }
        }
        sprite.setTexture(hinh[0]);
        sprite.setTextureRect(khung[0]);
        sprite.setOrigin(-100,-300);
	}
	void Fire()
	{
	    hinh.clear();
	    khung.clear();
        if(st == "Run")
        {
            if(tt == "Right")
            {

                for(int i = 50 ; i <= 77 ; i++ )
                {
                    hinh.push_back(frames[i]);
                    khung.push_back(frame[i]);
                }

            }
            if(tt == "Left")
            {
                for(int i = 111 ; i <= 138 ; i++ )
                {
                    hinh.push_back(frames[i]);
                    khung.push_back(frame[i]);
                }
            }
        }
        if(st == "Stay")
        {
            if(tt == "Right")
            {
                for(int i = 48 ; i <= 49 ; i++ )
                {
                    hinh.push_back(frames[i]);
                    khung.push_back(frame[i]);
                }
            }
            if(tt == "Left")
            {
                for(int i = 109 ; i <= 110 ; i++ )
                {
                    hinh.push_back(frames[i]);
                    khung.push_back(frame[i]);
                }
            }
        }
        if(st == "Up")
        {
            if(tt == "Right")
            {
                for(int i = 32 ; i <= 33 ; i++ )
                {
                    hinh.push_back(frames[i]);
                    khung.push_back(frame[i]);
                }
            }
            if(tt == "Left")
            {
                for(int i = 93 ; i <= 94 ; i++ )
                {
                    hinh.push_back(frames[i]);
                    khung.push_back(frame[i]);
                }
            }
        }
      //  if(st == "Up")
        sprite.setTexture(hinh[0]);
        sprite.setTextureRect(khung[0]);
        sprite.setOrigin(-100,-300);

	}
	void Power()
	{
	    hinh.clear();
	    khung.clear();
	    if(tt == "Right")
            {
                for(int i =4  ; i <= 6 ;i++ )
                {
                    hinh.push_back(frames[i]);
                    khung.push_back(frame[i]);
                }
            }
            if(tt == "Left")
            {
                for(int i = 174 ; i <= 176 ; i++ )
                {
                    hinh.push_back(frames[i]);
                    khung.push_back(frame[i]);
                }
            }
            sprite.setTexture(hinh[0]);
            sprite.setTextureRect(khung[0]);
            sprite.setOrigin(-100,-300);
	}
	void Bul()
	{
        hinh.clear();
        khung.clear();
        for(int i =0 ; i <= 0 ; i++)
        {
            hinh.push_back(frames[i]);
            khung.push_back(frame[i]);
        }

        sprite.setTexture(hinh[0]);
        sprite.setTextureRect(khung[0]);
        sprite.setOrigin(-100,-300);
	}

	void Enemies_le()
	{
	    hinh.clear();
        khung.clear();
        for(int i =141 ; i <= 149 ; i++)
        {
            hinh.push_back(frames[i]);
            khung.push_back(frame[i]);
        }

        sprite.setTexture(hinh[0]);
        sprite.setTextureRect(khung[0]);
        sprite.setOrigin(-100,-290);
	}
	void Enemies_ri()
	{
	    hinh.clear();
        khung.clear();
        for(int i =150 ; i <= 154 ; i++)
        {
            hinh.push_back(frames[i]);
            khung.push_back(frame[i]);
        }

        sprite.setTexture(hinh[0]);
        sprite.setTextureRect(khung[0]);
        sprite.setOrigin(-100,-290);
	}
    void Enemies_sky_le()
	{
	    hinh.clear();
        khung.clear();
        for(int i = 191 ; i <= 197 ; i++)
        {
            hinh.push_back(frames[i]);
            khung.push_back(frame[i]);
        }

        sprite.setTexture(hinh[0]);
        sprite.setTextureRect(khung[0]);
        sprite.setOrigin(-100,-290);
	}
	void Enemies_sky_ri()
	{
        hinh.clear();
        khung.clear();
        for(int i = 205 ;i <= 212 ; i++)
        {
            hinh.push_back(frames[i]);
            khung.push_back(frame[i]);
        }

        sprite.setTexture(hinh[0]);
        sprite.setTextureRect(khung[0]);
        sprite.setOrigin(-100,-290);

	}
    void Explo()
    {
        hinh.clear();
        khung.clear();
        for(int i =0 ; i < 18 ; i++)
        {
            hinh.push_back(frames[i]);
            khung.push_back(frame[i]);
        }

        sprite.setTexture(hinh[0]);
        sprite.setTextureRect(khung[0]);
        sprite.setOrigin(-100,-290);
    }
    void fire()
    {
         hinh.clear();
        khung.clear();
        for(int i =0 ; i < 4 ; i++)
        {
            hinh.push_back(frames[i]);
            khung.push_back(frame[i]);
        }

        sprite.setTexture(hinh[0]);
        sprite.setTextureRect(khung[0]);
        sprite.setOrigin(-100,-290);
    }

	void update(int sp)
	{
		Frame += speed;
		int size = hinh.size();
		sizehinh = Frame;
		if (Frame > size) Frame -= size;
		if (size > 0)
			sprite.setTexture(hinh[int(Frame)]);
            // 0 + 0,4, 0,8; 1,2
        fr += speed;
        size = khung.size();
        sizekhung = fr;
		if (fr > size) fr -= size;
		if (size > 0)
			sprite.setTextureRect(khung[int(fr)]);
	}
	bool isEnd()
	{

	    return fr + speed > khung.size();

	}

};


