#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include <vector>
#include<sstream>
#include <list>
#include<iostream>
#include<math.h>
#include<cstdlib>
#include "Animation.h"
#include "Character.h"
using namespace std;
using namespace sf;

// xu ly va tram cua 2 vat the thong qua toa do vaf ban kinh cua vat
bool VaCham(Vatthe *a, Vatthe *b)
{
	return ((b->getx() - a->getx())*(b->getx() - a->getx()) +(b->gety() - a->gety())*(b->gety()- a->gety())) <(a->R + b->R)*(a->R + b->R);
}



class Game_begin
{
private:

public:
    Game_begin(){};
    void start()
    {
        Time timelast = Time::Zero,ts = Time::Zero;
        Clock t_time;
        Clock fire;
        int key = 0,level = 2;
        int App = 0;
        list< Vatthe* > action;
        string tt="Right";
        bool Death = false;
        int point = 0;

//------------------Create BackGround---------------------
/*  lay anh tu file roi Sprite de lay khung hinh */


        RenderWindow app(VideoMode(820,430), "Megaman");
        Texture t1;
        t1.loadFromFile("214.png");
        Sprite spbg;
        spbg.setTexture(t1);
        spbg.setTextureRect(IntRect(0,10,1000,400));
//----------------Menu--------------------------------------
        Texture game_start;
        game_start.loadFromFile("backgound.png");
        Sprite sp;
        sp.setTexture(game_start);
        sp.setTextureRect(IntRect(0,0,1000,500));

        Texture game_over;
        game_over.loadFromFile("game_over.png");
        Sprite over;
        over.setTexture(game_over);
        over.setTextureRect(IntRect(0,0,1000,500));
//-------------Create kind of Sprite-------------------
        Animation Mega(0,176,0.05f);
        Animation Bullet_ri(139,139,0.03f);
        Animation Bullet_le(140,140,0.03f);
        Animation Fire(200,204,0.03f);
        Animation En(0,212,0.02f);
        Animation Ex(155,173,0.12f);
//---------------------CREATE Player--------------------------
        Player *p = new Player;
        p->Setting(Mega,200,-300,0);//tao ra vi tri ban dau
        p->ami.set_tt(tt);
        p->ami.set_st("Stay");// set trang thai dung hay di chuyen

        action.push_back(p);
//-------------Create Word in MENU--------------------------------------
        Font font;
        font.loadFromFile("Minecrafter.Reg.ttf");
        Text text;
        text.setFont(font);
        Font fo;
            fo.loadFromFile("Minecrafter.Reg.ttf");
            Text start,exit ,Gui,guide;
            start.setFont(fo);
            start.setString("PLAY");
            start.setPosition(350,30);
            exit.setFont(fo);
            exit.setString("EXIT");
            exit.setPosition(350,170);
            Gui.setFont(fo);
            Gui.setString("Press X to Play \n\nPress D to exit\n\nPress E to Guide");
            Gui.setCharacterSize(10);
            Gui.setPosition(350,250);
            guide.setFont(fo);
            guide.setString("GUIDE");
            //guide.setCharacterSize(10);
            guide.setPosition(350,100);


//----------------- Mana and HP------------------------------
        int hp  = 1000;
        RectangleShape hpBar;
        hpBar.setFillColor(Color::Red);
        hpBar.setSize(Vector2f((float)hp * 0.3f, 20.f));
        hpBar.setPosition(200.f, 10.f);
        float mana = 1000;
        RectangleShape manaBar;
        manaBar.setFillColor(Color :: Green);
        manaBar.setSize(Vector2f(mana*0.3f,20.f));
        manaBar.setPosition(200.f,45.f);
//------------------------ sound----------------------
        SoundBuffer bf,bfp;
        bf.loadFromFile("Explosion+1.wav");
        bfp.loadFromFile("Explosion+5.wav");

        Sound sound,soundp;
        soundp.setBuffer(bfp);
        sound.setBuffer(bf);
        string stt = "Stay";

//-----------------Create Enemies--------------------------
        int num_en_ri = 1;
        int num_en_le = 1;
        for(int i = 0 ; i < 1; i ++)
        {
            enemies_ri * er = new enemies_ri();
            er->Setting(En,570+rand()%200,-310,0);
            er->ami.Enemies_ri();
            action.push_back(er);
            enemies_le * el = new enemies_le();
            el ->Setting(En,-200-rand()%75,-310,0);
            el->ami.Enemies_le();
            action.push_back(el);
        }

        int num_sky =0;
        int num_sky_ri =0;
//----------------------GAME LOOP------------------------------
        while (app.isOpen())
        {


            Event event;

            while(app.pollEvent(event))
            {
                if(event.type == Event::Closed)
                {
                    app.close();
                }

            }
//-----------key = 0 : menu is openning ---------------------------------------
            if(key == 0)
            {
                app.clear();
                app.draw(sp);
                app.draw(start);
                app.draw(guide);
                app.draw(exit);
                app.draw(Gui);
                app.display();
                if(Keyboard :: isKeyPressed(Keyboard :: X))
                {
                    key = 1;
                    app.clear();
                }
                if(Keyboard :: isKeyPressed(Keyboard :: E))
                {
                    key = 3;
                    app.clear();
                }
                if(Keyboard :: isKeyPressed(Keyboard :: D))
                {
                    app.close();
                }

            }
            if(key == 3)
            {
                app.clear();
                app.draw(sp);
                Text Huong_dan;
                Huong_dan.setFont(fo);
                Huong_dan.setString("Press arrow up, left, right to jump,run left and right \n\nPress W to Fire\n\nPress Q to fill mana bar\n\n\n\nPress Tab to return");
                Huong_dan.setPosition(100,30);
                Huong_dan.setCharacterSize(15);
                app.draw(Huong_dan);
                app.display();
                if(Keyboard :: isKeyPressed(Keyboard :: Tab))
                {

                    key = 0;
                    app.clear();
                }
            }
//---------Game Start-------------------------------
            if(key == 1)
            {


                stt= "Stay";
                if(App <=390 )
                {
                    p->ami.speed = 0.02f;
                    p->ami.App();
                    p->ami.update(13);

                    App ++;
                }
                else{
                    p->ami.set_st("Stay");
                    p->ami.speed = 0.05f;
                    if( tt == "Right" )
                    {
                        if(p->y >=0)
                        {
                            p->ami.set_ani(17,20);
                            p->ami.set_st("Stay");
                            p->ami.speed = 0.03f;
                        }
                        else{
                            p->ami.set_ani(22,22);
                            p->ami.set_st("Up");
                        }
                    }

                    if( tt == "Left")
                    {
                        if(p->y >= 0)
                        {
                            p->ami.set_ani(78,81);
                            p->ami.set_st("Stay");
                        }
                        else
                        {
                            p->ami.set_ani(83,83); p->ami.set_st("Up");
                        }

                    }
                    if (Keyboard::isKeyPressed(Keyboard::Right))
                    {
                        tt= "Right";
                        stt = "Run";
                        p->ami.set_tt(tt);
                        if(p->y>=0)
                        {
                            p->ami.set_st("Run");
                          //  p->ami.speed = 0.052f;
                            p->x+=0.35;
                        }
                        else
                        {
                            p->ami.set_st("Up");//p->ami.speed = 0.03f;
                            p->x+=0.2;
                        }

                        p->ami.Run();

                    } //

                    if (Keyboard::isKeyPressed(Keyboard::Left) )
                    {
                        tt ="Left";
                        stt ="Run";
                        p->ami.set_tt(tt);
                        if(p->y>=0)
                        {
                            p->ami.set_st("Run");
                            //p->ami.speed = 0.052f;
                            p->x-=0.35;
                        }
                        else
                        {
                            p->ami.set_st("Up");//p->ami.speed = 0.03f;
                            p->x-=0.18;
                        }
                        p->ami.Run();

                    }

                    if (Keyboard::isKeyPressed(Keyboard::Up))
                    {
                        stt = "Run";
                        if(p->ami.get_tt() == "Right")
                        {
                            p->ami.Jump();
                            if(p->y >=-210)
                                p->y-=0.5;
                            if(p->get_mana()>0)
                                p->set_mana(-0.9f);
                            else if(p->y<=0) p->y+=0.6;
                        }
                        if(p->ami.get_tt()=="Left")
                        {
                            p->ami.Jump();
                            if(p->y >=-210)
                                p->y-=0.5;
                            if(p->get_mana()>0)
                                p->set_mana(-0.9f);
                            else if(p->y<0)p->y+=0.6;
                        }
                        p->ami.set_st("Up");
                        mana = p->get_mana();
                    }
//---------Tao Dan----------------------------------------------------
// dung clock de do thoi gian vien dapj ke tiep
                    if(Keyboard ::isKeyPressed(Keyboard::W))
                    {
                       // p->ami.speed = 0.2f;
                        p->ami.Fire();
                        if(tt == "Right")
                        if (timelast.asMilliseconds() > 200.0f)
                        {
                            timelast = Time :: Zero;
                            bullet_ri *b = new bullet_ri();
                            b->Setting(Bullet_ri, 0, -300 , 0);
                            b->ami.Bul();
                            b->appear(p->x+40,p->y+10);
                          //  b->ami.speed = 0.001f;

                            action.push_back(b);
                        }
                        if(tt == "Left")
                        {
                        if (timelast.asMilliseconds() > 200.0f)
                        {
                            bullet_le *b = new bullet_le();
                            b->Setting(Bullet_le, 0, -300 , 0);
                            b->ami.Bul();
                            b->appear(p->x-40,p->y+10);
                            timelast = Time::Zero;

                       // b->ami.speed = 0.001f;
                            action.push_back(b);
                        }

                        }
                        if(tt == "Right" && p->ami.get_st() == "Run")
                        {
                            p->x+=0.13;

                        }
                        if( tt == "Left" && p->ami.get_st() == "Run") p->x-=0.13;
                    }
                    // sau khi tao ra dan reset lai thoi gian dem = 0 de tiep tucj tinh thoi gian xuat hien cua dan
                    Time dt = t_time.restart();
                    timelast += dt;
                    t_time.restart();
                    if(Keyboard::isKeyPressed(Keyboard::Q))
                    {

                        p->ami.Power();
                        if(p->get_mana()<1000)
                        p->set_mana(3);

                    }



                    if (p->y < 0)
                        p->y += 0.25;
                    if (p->get_mana()< 1000)
                    {
                        p->set_mana(0.2);
                        mana = p->get_mana();
                    }


                }

		//------------------------------------------------------------------------
		//                  Check dead

                for(auto a: action)
                {
                    if(a->get_name() == "bullet")
                    {
                        if(a->x >700 || a->x<-100) a->set_end(false);
                    }

//---------------------Tao Dich Mat Dat-----------------------------------------------

                    if(a->get_name() == "ene_le" )
                    {
                        if(a->get_end() == false  )
                        {
                          //  if(num_en_le>0)
                            {
                                num_en_le=0;
                            }
                        }
                    }
                    if(a->get_name() == "ene_ri")
                    {
                        if(a->get_end() == false  )
                        {
                            {
                                num_en_ri=0;
                            }
                        }
                    }

//------------------------Dich Tren Troi--------------------------------------------------
                    if(a->get_name() == "ene_sky_le")
                    {
                        if(a->get_end() == false  )
                        {
                            if(num_sky == 1)
                            {
                                num_sky = 0;
                            }
                        }
                        else
                        {

                            if (ts.asMilliseconds() > 920.0f)
                            {
                                ts = Time :: Zero;
                                dragon_fire *df = new dragon_fire();

                                df->Setting(Fire, 0, -300 , 0);
                                df->appear(a->x+60,a->y+10);
                                df->ami.fire();

                        //    df->ami.speed = 0.001f;

                                action.push_back(df);
                            }
                            Time t = fire.restart();
                            ts += t;
                            fire.restart();
                        }


                    }
                    if(a->get_name() == "ene_sky_ri")
                    {
                        if(a->get_end() == false  )
                        {
                           // if(num_en_ri>0)
                            {
                                num_sky_ri=0;
                            }
                        }
                    }


                }
//----------------------------XU LY VA CHAM -----------------------------------------------------------------
                for(auto a: action)
                {
                    for(auto b:action)
                    {
                    //----------Va cham giua dich voi dan-----------------------
                        if((a->get_name() == "ene_le" || a->get_name() == "ene_ri"||a->get_name() == "ene_sky_le"|| a->get_name() =="ene_sky_ri") && b->get_name() == "bullet")
                        {
                            if(VaCham(a,b))
                            {
                                point+=10;
                                a->set_end(false);
                                b->set_end(false);
                                Vatthe * exp = new Vatthe();
                                exp->Setting(Ex,a->x-127,a->y-350,0);
                                exp->ami.Explo();
                                exp->set_name("Ex");
                                if(a->get_name() == "ene_le")num_en_le = 0;
                                if(a->get_name() == "ene_ri") num_en_ri=0;
                                if(a->get_name() == "ene_sky_le") num_sky = 0;
                                if(a->get_name() == "ene_sky_ri") num_sky_ri =0;
                                action.push_back(exp);

                            }
                        }
                    //--------Va Cham cua nguoi choi -------------------------------------
                        if(a->get_name() == "Player" && (b->get_name() == "ene_le" || b->get_name() == "ene_ri" ||b->get_name() == "ene_sky_le"||b->get_name()=="Fire" || b->get_name()=="ene_sky_ri" ))
                        {

                            if(VaCham(a,b))
                            {
                                a->set_hp(-1);

                                hp-=1;
                                if(a->get_hp() <= 0 )
                                {
                                    b->set_end(false);// khi mau giam ve 0 thi gan cho no la da chet
                                    Vatthe * exp = new Vatthe();
                                    exp->Setting(Ex,a->x-127,a->y-350,0);// cai dat vi tri
                                    exp->ami.Explo();
                                    exp->set_name("Player-Ex");
                                    action.push_back(exp);
                                    Death = true;
                                    a->set_end(false);
                                }
                            }

                        }
                    }
                }
//------------------------------Check dich va xoa di cac vat the da chet--------------------------------------------------------------------------------

            for(auto i= action.begin() ; i!= action.end();)
            {
                Vatthe *a = *i;


                if(a->get_end() == false)
                {
                    i = action.erase(i);

                }
                else i++;
                if(a->get_name() == "ene_le" || a->get_name() == "ene_ri" ||a->get_name() == "ene_sky_le" || a->get_name() == "ene_sky_ri")
                {

                    if(a->get_end() == false)
                    {
                        if(a->get_name() == "ene_le" )  num_en_le=0;
                        if(a->get_name() == "ene_ri" ) num_en_ri=0;
                        if(a->get_name() == "ene_sky_le")  num_sky = 0;
                        if(a->get_name() == "ene_sky_ri") num_sky_ri =0;
                        delete a;
                    }
                }



            }
//----------------------------SET LEVEL--------------------------------------------

            if (point % 200 == 0 && level <=5 && point >0 )
                level++;
//-----------------------------Create new Enemies---------------------------------
// dich cu chet tao lai dich moi
            if(num_en_ri == 0)
            {
                srand(time(NULL));

                for(int i = 0 ; i < 1 ; i++)
                {

                    enemies_ri * er = new enemies_ri();
                    er->Setting(En,450+rand()%150,-310,0);
                    er->ami.Enemies_ri();
                    er->set_move(level);
                    action.push_back(er);

                }
                num_en_ri = 1;
            }
            if(num_en_le == 0)
            {
                srand(time(NULL));
                for(int i = 0 ; i < 1 ; i++)
                {
                    enemies_le * er = new enemies_le();
                    er->Setting(En,-175-rand()%50,-310,0);
                    er->ami.Enemies_le();
                    {
                        er->set_move(level);
                    }
                    action.push_back(er);

                }
                num_en_le = 1;
            }
            if(point >= 100 && num_sky == 0)
            {
                srand(time(NULL));
                {
                    ene_sky_le * er = new ene_sky_le();
                    er->Setting(En,-175-rand()%50,-500,0);
                    er->ami.Enemies_sky_le();
                    {
                        er->set_move(level);
                    }
                    action.push_back(er);

                }
                num_sky = 1;
            }
            if(point >= 320 && num_sky_ri == 0)
                {
                    ene_sky_ri * en = new ene_sky_ri();
                    en->Setting(En,700+rand()%75,-450,0);
                    en->ami.Enemies_sky_ri();
                    {
                        en->set_move(level);
                    }
                    action.push_back(en);
                    num_sky_ri  =1;
                }
//---------------------- DRAW-------------------------
        app.clear(Color::Black);
		app.draw(spbg);
		for(auto a : action)
            {

                if(a->get_name() == "Ex")
                {
                    if(stt == "Run") a->ami.speed = 0.15f;

                    else  a->ami.speed = 0.11f;
                    if(a->ami.isEnd())
                    {
                        a->set_end(false);
                        sound.play();
                    }


                }
                if(a->get_name() == "Player-Ex")
                {
                    if(a->ami.isEnd())
                    {
                        soundp.play();
                        key = 2;
                    }
                }


            }
            //-----------update lai sau 1 vong lap game----------------
            for(auto a : action)
                a->update();
            //--------ve trang thai ra man hinh-------------------------------
            for(auto a : action)
                a->draw__(app);

            string s="";
            stringstream ss;
            ss << point ;
            ss >> s;

            text.setString(s);
            text.setPosition(600,0);
            app.draw( text );
            if(hp<0) hp =0;
            hpBar.setSize(Vector2f((float)hp * 0.3f, 20.f));
            app.draw (hpBar);
            manaBar.setSize(Vector2f(mana*0.3f,20.f));
            app.draw(manaBar);
            app.display();
            fflush(stdin);
        }
//----------------------Game OVER-----------------------------------------------------
        if(key == 2)
        {
            Text ans;
            ans.setFont(font);
            string s ="";
            stringstream ss;
            ss << point;
            ss >> s;
            s = "Your Point :  "+s;
            ans.setString(s+"\n\nPress Tab to return menu");
            ans.setFillColor(Color :: White);
            ans.setPosition(100,80);
//--------------------Reload the Game ----------------------------------------
            if(Keyboard::isKeyPressed(Keyboard :: Tab))
            {
                key = 0;
                level = 2;
                point = 0;
                timelast = Time::Zero;
                action.clear();
                App = 0;
                tt="Right";

                p = new Player();
                p->Setting(Mega,200,-300,0);
                p->ami.set_tt(tt);
                p->ami.set_st("Stay");
                action.push_back(p);
                num_en_le = 1;
                num_en_ri = 1;
                for(int i = 0 ; i < 1; i ++)
                {
                    enemies_ri * er = new enemies_ri();
                    er->Setting(En,570+rand()%200,-310,0);
                    er->ami.Enemies_ri();
                    action.push_back(er);
                    enemies_le * el = new enemies_le();
                    el ->Setting(En,-200-rand()%75,-310,0);
                    el->ami.Enemies_le();
                    action.push_back(el);
                }

                num_sky =0;
                num_sky_ri =0;
                hp = 1000;
                mana = 1000;
                Death = false;
            }
            fflush(stdin);
            app.draw(over);
            app.draw(ans);
            app.display();



        }
        fflush(stdin);
        fflush(stdout);

	}
    }


};
