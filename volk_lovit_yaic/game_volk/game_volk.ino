#include <SoftwareSerial.h>
#include <Nextion.h>
#include <Bounce2.h>

Bounce bouncer_left_up = Bounce();
Bounce bouncer_left_down = Bounce();
Bounce bouncer_right_up = Bounce();
Bounce bouncer_right_down = Bounce();

SoftwareSerial nextion(10,11); //tx-10, rx-11

//яйца
int max_count_eggs = 1;
int now_count_eggs = 0;
bool egg10 = 0, egg11 = 0, egg12 = 0;
bool egg20 = 0, egg21 = 0, egg22 = 0;
bool egg30 = 0, egg31 = 0, egg32 = 0;
bool egg40 = 0, egg41 = 0, egg42 = 0;

//кнопки
int left_up = 41;
int left_down = 39;
int right_up = 9;
int right_down = 12;
bool b_left_up = 0, b_left_down = 0, b_right_up = 0, b_right_down = 0;


//счетчик
int ochki = 0;
int health =3 ;
long long old_time = 1000;
float koef_of_time = 1;

//рестарт
int time_restart = 10;

void ostanowka_peredichi() {
  
  nextion.write(0xff);
  nextion.write(0xff);
  nextion.write(0xff);
  
}

void clear_wolf(){

  nextion.print("p2.pic=11");
  ostanowka_peredichi();
  nextion.print("p3.pic=10");
  ostanowka_peredichi();
  nextion.print("p4.pic=13");
  ostanowka_peredichi();
  nextion.print("p6.pic=14");
  ostanowka_peredichi();
  
}

void clear_displey(){
  
  clear_wolf();
  
  nextion.print("t16.txt=\"");
  nextion.print("         ");
  nextion.print("\"");
  ostanowka_peredichi();
  nextion.print("p0.pic=12");
  ostanowka_peredichi();
  nextion.print("p1.pic=12");
  ostanowka_peredichi();
  nextion.print("t0.txt=\" ");
  nextion.print(" ");
  nextion.print("\"");
  ostanowka_peredichi();
  nextion.print("t1.txt=\" ");
  nextion.print(" ");
  nextion.print("\"");
  ostanowka_peredichi();
  nextion.print("t2.txt=\" ");
  nextion.print(" ");
  nextion.print("\"");
  ostanowka_peredichi();
  nextion.print("t3.txt=\" ");
  nextion.print(" ");
  nextion.print("\"");
  ostanowka_peredichi();
  nextion.print("t4.txt=\" ");
  nextion.print(" ");
  nextion.print("\"");
  ostanowka_peredichi();
  nextion.print("t5.txt=\" ");
  nextion.print(" ");
  nextion.print("\"");
  ostanowka_peredichi();
  nextion.print("t6.txt=\" ");
  nextion.print(" ");
  nextion.print("\"");
  ostanowka_peredichi();
  nextion.print("t7.txt=\" ");
  nextion.print(" ");
  nextion.print("\"");
  ostanowka_peredichi();
  nextion.print("t8.txt=\" ");
  nextion.print(" ");
  nextion.print("\"");
  ostanowka_peredichi();
  nextion.print("t9.txt=\" ");
  nextion.print(" ");
  nextion.print("\"");
  ostanowka_peredichi();
  nextion.print("t10.txt=\" ");
  nextion.print(" ");
  nextion.print("\"");
  ostanowka_peredichi();
  nextion.print("t11.txt=\" ");
  nextion.print(" ");
  nextion.print("\"");
  ostanowka_peredichi();
  
}

void risovka_volka(){

  if(!digitalRead(left_up)  and !b_left_up){

    clear_wolf();
    nextion.print("p0.pic=12");
    ostanowka_peredichi();
    
    nextion.print("p1.pic=2");
    ostanowka_peredichi();
    nextion.print("p4.pic=6");
    ostanowka_peredichi();

    b_left_up = 1;
    b_left_down = 0;
    b_right_up = 0;
    b_right_down = 0;
    
  }

  if(!digitalRead(left_down) and !b_left_down){
    
    clear_wolf();
    nextion.print("p0.pic=12");
    ostanowka_peredichi();
    
    nextion.print("p1.pic=2");
    ostanowka_peredichi();
    nextion.print("p6.pic=7");
    ostanowka_peredichi();

    b_left_up = 0;
    b_left_down = 1;
    b_right_up = 0;
    b_right_down = 0;
    
  }

  if(!digitalRead(right_up) and !b_right_up){
    
    clear_wolf();
    nextion.print("p1.pic=12");
    ostanowka_peredichi();
    
    nextion.print("p0.pic=5");
    ostanowka_peredichi();
    nextion.print("p3.pic=3");
    ostanowka_peredichi();

    b_left_up = 0;
    b_left_down = 0;
    b_right_up = 1;
    b_right_down = 0;
    
  }

  if(!digitalRead(right_down) and !b_right_down){
    
    clear_wolf();
    nextion.print("p1.pic=12");
    ostanowka_peredichi();
    
    nextion.print("p0.pic=5");
    ostanowka_peredichi();
    nextion.print("p2.pic=4");
    ostanowka_peredichi();

    b_left_up = 0;
    b_left_down = 0;
    b_right_up = 0;
    b_right_down = 1;
    
  }
  
}

void plus_ochki(){

  String write_ochki;
  
  ochki++;

  if(ochki < 10){ write_ochki = String("000" + String(ochki));}
  if(ochki >= 10 and ochki < 100){ write_ochki = String("00" + String(ochki));}
  if(ochki >= 100 and ochki < 1000){ write_ochki = String("0" + String(ochki));}
  
  nextion.print("t12.txt=\"");
  nextion.print(write_ochki);
  nextion.print("\"");
  ostanowka_peredichi();
  
}

void spaun_egg(){

  int index_spawn = random(1,5);

  if(index_spawn == 1){
    
    egg10 = 1;
    
    nextion.print("t0.txt=\" ");
    nextion.print(0);
    nextion.print("\"");
    ostanowka_peredichi();
    
  }

  if(index_spawn == 2){
    
    egg20 = 1;
    
    nextion.print("t3.txt=\" ");
    nextion.print(0);
    nextion.print("\"");
    ostanowka_peredichi();
    
  }

  if(index_spawn == 3){

    egg30 = 1;
    
    nextion.print("t6.txt=\" ");
    nextion.print(0);
    nextion.print("\"");
    ostanowka_peredichi();
    
  }

  if(index_spawn == 4){

    egg40 = 1;
    
    nextion.print("t9.txt=\" ");
    nextion.print(0);
    nextion.print("\"");
    ostanowka_peredichi();
    
  }
  
}

void move_eggs(){

  if(egg12){

    egg12 = 0;

    nextion.print("t2.txt=\" ");
    nextion.print(" ");
    nextion.print("\"");
    ostanowka_peredichi();
    
  }

  if(egg11){

    egg12 = 1;
    egg11 = 0;

    nextion.print("t1.txt=\" ");
    nextion.print(" ");
    nextion.print("\"");
    ostanowka_peredichi();
    nextion.print("t2.txt=\" ");
    nextion.print(0);
    nextion.print("\"");
    ostanowka_peredichi();
    
  }

  if(egg10){

    egg11 = 1;
    egg10 = 0;

    nextion.print("t0.txt=\" ");
    nextion.print(" ");
    nextion.print("\"");
    ostanowka_peredichi();
    nextion.print("t1.txt=\" ");
    nextion.print(0);
    nextion.print("\"");
    ostanowka_peredichi();
    
  }

  if(egg22){

    egg22 = 0;

    nextion.print("t5.txt=\" ");
    nextion.print(" ");
    nextion.print("\"");
    ostanowka_peredichi();
    
  }

  if(egg21){

    egg22 = 1;
    egg21 = 0;

    nextion.print("t4.txt=\" ");
    nextion.print(" ");
    nextion.print("\"");
    ostanowka_peredichi();
    nextion.print("t5.txt=\" ");
    nextion.print(0);
    nextion.print("\"");
    ostanowka_peredichi();
    
  }

  if(egg20){

    egg21 = 1;
    egg20 = 0;

    nextion.print("t3.txt=\" ");
    nextion.print(" ");
    nextion.print("\"");
    ostanowka_peredichi();
    nextion.print("t4.txt=\" ");
    nextion.print(0);
    nextion.print("\"");
    ostanowka_peredichi();
    
  }

  if(egg32){

    egg32 = 0;

    nextion.print("t8.txt=\" ");
    nextion.print(" ");
    nextion.print("\"");
    ostanowka_peredichi();
    
  }

  if(egg31){

    egg32 = 1;
    egg31 = 0;

    nextion.print("t7.txt=\" ");
    nextion.print(" ");
    nextion.print("\"");
    ostanowka_peredichi();
    nextion.print("t8.txt=\" ");
    nextion.print(0);
    nextion.print("\"");
    ostanowka_peredichi();
    
  }

  if(egg30){

    egg31 = 1;
    egg30 = 0;

    nextion.print("t6.txt=\" ");
    nextion.print(" ");
    nextion.print("\"");
    ostanowka_peredichi();
    nextion.print("t7.txt=\" ");
    nextion.print(0);
    nextion.print("\"");
    ostanowka_peredichi();
    
  }

  if(egg42){

    egg42 = 0;

    nextion.print("t11.txt=\" ");
    nextion.print(" ");
    nextion.print("\"");
    ostanowka_peredichi();
    
  }

  if(egg41){

    egg42 = 1;
    egg41 = 0;

    nextion.print("t10.txt=\" ");
    nextion.print(" ");
    nextion.print("\"");
    ostanowka_peredichi();
    nextion.print("t11.txt=\" ");
    nextion.print(0);
    nextion.print("\"");
    ostanowka_peredichi();
    
  }

  if(egg40){

    egg41 = 1;
    egg40 = 0;

    nextion.print("t9.txt=\" ");
    nextion.print(" ");
    nextion.print("\"");
    ostanowka_peredichi();
    nextion.print("t10.txt=\" ");
    nextion.print(0);
    nextion.print("\"");
    ostanowka_peredichi();
    
  }
  
}

void trap_egg(){

  if(egg12){
    
    now_count_eggs--;
    
    if(!b_right_up){health--;}
    
  }

  if(egg22){
    
    now_count_eggs--;
    
    if(!b_right_down){health--;}
    
  }

  if(egg32){
    
    now_count_eggs--;
    
    if(!b_left_up){health--;}
    
  }

  if(egg42){
    
    now_count_eggs--;
    
    if(!b_left_down){health--;}
    
  }
  
}

void write_health(){

  if(health == 2){

    nextion.print("t15.txt=\"");
    nextion.print(0);
    nextion.print("\"");
    ostanowka_peredichi();
    
    }

 if(health == 1){

    nextion.print("t14.txt=\"");
    nextion.print(0);
    nextion.print("\"");
    ostanowka_peredichi();
    
    }

  if(health == 0){

    nextion.print("t13.txt=\"");
    nextion.print(0);
    nextion.print("\"");
    ostanowka_peredichi();
    
    }
}

void tact(){

  plus_ochki();
  trap_egg();
  move_eggs();
  write_health();
  
  if(max_count_eggs > now_count_eggs) {
    
    spaun_egg();

    now_count_eggs++;
    
  }
  
}

void game_over(){

  nextion.print("t16.txt=\"");
  nextion.print("GAME OVER");
  nextion.print("\"");
  ostanowka_peredichi();
  
}

void restart(){

  long long old_time_restart = millis() - 1000;

  while(true){

    if(millis() - old_time_restart >= 1000){

      old_time_restart = millis();
      nextion.print("t17.txt=\"");
      nextion.print(time_restart);
      nextion.print("\"");
      ostanowka_peredichi();

      time_restart--;
      
    }

    if(time_restart < 0){asm("JMP 0");}
    
  }
  
}

void setup() {

  pinMode(left_up,INPUT_PULLUP);
  pinMode(left_down,INPUT_PULLUP);
  pinMode(right_up,INPUT_PULLUP);
  pinMode(right_down,INPUT_PULLUP);

  bouncer_left_up.attach(left_up);
  bouncer_left_up.interval(5);
  bouncer_left_down.attach(left_down);
  bouncer_left_down.interval(5);
  bouncer_right_up.attach(right_up);
  bouncer_right_up.interval(5);
  bouncer_right_down.attach(right_down);
  bouncer_right_down.interval(5);
  
  nextion.begin(9600);

  clear_displey();

  nextion.print("t13.txt=\"");
  nextion.print("h");
  nextion.print("\"");
  ostanowka_peredichi();
  nextion.print("t14.txt=\"");
  nextion.print("h");
  nextion.print("\"");
  ostanowka_peredichi();
  nextion.print("t15.txt=\"");
  nextion.print("h");
  nextion.print("\"");
  ostanowka_peredichi();
  nextion.print("t12.txt=\"");
  nextion.print("0000");
  nextion.print("\"");
  ostanowka_peredichi();
  nextion.print("p1.pic=2");
  ostanowka_peredichi();
  nextion.print("p4.pic=6");
  ostanowka_peredichi();

  b_left_up = 1;
  
}

void loop() {

  if(ochki == 0){

    koef_of_time = 1;
    max_count_eggs = 1;
    
  }

  if(ochki == 50){

    koef_of_time = 0.8;
    max_count_eggs = 2;
    
  }

  if(ochki == 100){

    koef_of_time = 0.7;
    max_count_eggs = 2;
    
  }

  if(ochki == 200){

    koef_of_time = 0.6;
    max_count_eggs = 2;
    
  }

  if(ochki == 300){

    koef_of_time = 0.5;
    max_count_eggs = 3;
    
  }

  if(ochki == 400){

    koef_of_time = 0.4;
    max_count_eggs = 3;
    
  }

  if(ochki == 600){

    koef_of_time = 0.3;
    max_count_eggs = 3;
    
  }

  if(ochki == 800){

    koef_of_time = 0.2;
    max_count_eggs = 3;
    
  }

  if(health > 0){
    
    if( bouncer_left_up.update() or bouncer_left_down.update() or bouncer_right_up.update()  or bouncer_right_down.update()) {risovka_volka();}

    if(millis() - old_time  >= 1000 * koef_of_time){

      old_time = millis();
    
      tact();
    
    }

  }

 else{
  
  clear_displey();
  game_over();
  restart();
  
 }

}
