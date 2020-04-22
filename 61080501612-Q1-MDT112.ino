void setup()
{

    //start serial connection

    Serial.begin(9600); 

    pinMode(2,INPUT_PULLUP); 

    pinMode(3,OUTPUT);

    pinMode(4,OUTPUT);

    pinMode(5,OUTPUT);

    pinMode(6,OUTPUT);

    pinMode(7,OUTPUT);

    pinMode(8,OUTPUT);

    pinMode(9,OUTPUT);

    pinMode(10,OUTPUT);

    pinMode(11,OUTPUT);

    pinMode(12,OUTPUT);

    pinMode(13,OUTPUT);

     for(int light = 3 ; light <= 13 ;light++)
     {

        pinMode(light,OUTPUT);

    }

    tone(8,200,500); 
    
    delay(250); 

    tone(8,400,100); 

}

int bright = 3;

int time = 100;

int press = 1;

void loop()

{

    for(bright = 3 ; bright <= 13 ; bright++) 
    { 

        if(bright == 8)
        {

            digitalWrite(bright,0);

            continue;

        }

        digitalWrite(bright,1); // เปิด

        delay(time);

        digitalWrite(bright,0); // ปิด

        if ( digitalRead(2) == 0 ){

            press = press * 2;

            time = time / 2;

            Serial.println("Faster X 2 (Current Speed : X" + String(press) + ")");

            tone(8,400,100);

            delay(500);

        }

        else  
        {

        }

    }

    for( bright= 13 ; bright >= 3 ;bright--) // ลง

    {

        if(bright == 8)
        {

            digitalWrite(bright,0); 

            continue;

        }

        digitalWrite(bright,1); // เปิด

        delay(time);

        digitalWrite(bright,0); // ปิด

        if ( digitalRead(2) == 0 )
        {

            press = press * 2;

            Serial.println("Faster X 2 (Current Speed : X" + String(press) + ")");

            tone(8,400,100);

            time = time / 2;

            delay(500);
 
        }

        else  

        {

        }

    }

}
