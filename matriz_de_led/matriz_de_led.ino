int col[]={12,4,10,9,3};
byte fil[]={8,13,7,11,6,2,5};

int i,k=0,t=100;

void setup()
{
  
  for(i=0;i<5;i++)
  {
    pinMode(col[i],OUTPUT);
    digitalWrite(col[i],HIGH);
  }
  for(i=0;i<7;i++)
  {
    pinMode(fil[i],OUTPUT);
    digitalWrite(fil[i],LOW);
  }
  Serial.begin(9600);
  Serial.println("\t Universidad Nacional Pedro Ruiz Gallo");
  Serial.println("\t \t Digite Letra ");
}

void A()
{
  do
  {
    
    for(i=1;i<4;i++)
    {
      digitalWrite(fil[0],HIGH);
      digitalWrite(fil[4],HIGH);
      digitalWrite(col[i],LOW);
      delay(1);
      digitalWrite(col[i],HIGH);
      digitalWrite(fil[0],LOW);
      digitalWrite(fil[4],LOW);
    }
    for(i=1;i<7;i++)
    {
      digitalWrite(col[0],LOW);
      digitalWrite(col[4],LOW);
      digitalWrite(fil[i],HIGH);
      delay(1);
      digitalWrite(fil[i],LOW);
      digitalWrite(col[0],HIGH);
      digitalWrite(col[4],HIGH);
    }
    k++;
  }while(!(k==t)); 
}
void B()
{
  do
  {
      for(i=0;i<4;i++)
      {
        digitalWrite(fil[0],HIGH);
        digitalWrite(fil[3],HIGH);
        digitalWrite(fil[6],HIGH);
        digitalWrite(col[i],LOW);
        delay(1);
        digitalWrite(col[i],HIGH);
        digitalWrite(fil[0],LOW);
        digitalWrite(fil[3],LOW);
        digitalWrite(fil[6],LOW);
      }    
      
      for(i=0;i<7;i++)
      {
        digitalWrite(col[0],LOW);
        digitalWrite(fil[i],HIGH);
        delay(1);
        digitalWrite(fil[i],LOW);
        digitalWrite(col[0],HIGH);
      }
      for(i=1;i<6;i++)
      {
        
        if(i==3)
        {
          continue;
        }
        digitalWrite(col[4],LOW);
        digitalWrite(fil[i],HIGH);
        delay(1);
        digitalWrite(fil[i],LOW);
        digitalWrite(col[4],HIGH);
      }
    k++;
  }while(!(k==t)); 
}
void C()
{
  do
  {
    for(i=1;i<4;i++)
    {
      digitalWrite(fil[0],HIGH);
      digitalWrite(fil[6],HIGH);
      digitalWrite(col[i],LOW);
      delay(1);
      digitalWrite(col[i],HIGH);
      digitalWrite(fil[0],LOW);
      digitalWrite(fil[6],LOW);
    }
    for(i=1;i<6;i++)
    {
      digitalWrite(col[0],LOW);
      digitalWrite(fil[i],HIGH);
      delay(1);
      digitalWrite(fil[i],LOW);
      digitalWrite(col[0],HIGH);
    }
    for(i=1;i<6;i+=4)
    {
      digitalWrite(col[4],LOW);
      digitalWrite(fil[i],HIGH);
      delay(1);
      digitalWrite(fil[i],LOW);
      digitalWrite(col[4],HIGH);
    }
    k++;
  }while(!(k==t)); 
}
void D()
{
  do
  {
      for(i=0;i<4;i++)
      {
        digitalWrite(fil[0],HIGH);
        digitalWrite(fil[6],HIGH);
        digitalWrite(col[i],LOW);
        delay(1);
        digitalWrite(col[i],HIGH);
      }    
      
      for(i=0;i<7;i++)
      {
        digitalWrite(col[0],LOW);
        digitalWrite(fil[i],HIGH);
        delay(1);
        digitalWrite(fil[i],LOW);
        digitalWrite(col[0],HIGH);
      }
      for(i=1;i<6;i++)
      {
        
        digitalWrite(col[4],LOW);
        digitalWrite(fil[i],HIGH);
        delay(1);
        digitalWrite(fil[i],LOW);
        digitalWrite(col[4],HIGH);
      }
    k++;
  }while(!(k==t)); 
}
void E()
{
  do
  {
    for(i=1;i<4;i++)
    {
      digitalWrite(fil[0],HIGH);
      digitalWrite(fil[3],HIGH);
      digitalWrite(fil[6],HIGH);
      digitalWrite(col[i],LOW);
      delay(1);
      digitalWrite(col[i],HIGH);
    }
    for(i=0;i<7;i++)
    {
      digitalWrite(col[0],LOW);
      digitalWrite(fil[i],HIGH);
      delay(1);
      digitalWrite(fil[i],LOW);
      digitalWrite(col[0],HIGH);
    }
    for(i=0;i<7;i+=6)
    {
      digitalWrite(col[4],LOW);
      digitalWrite(fil[i],HIGH);
      delay(1);
      digitalWrite(fil[i],LOW);
      digitalWrite(col[4],HIGH);
    }
    k++;
  }while(!(k==t)); 
}
void FF()
{
  do
  {
    for(i=0;i<5;i++)
    {
      digitalWrite(fil[0],HIGH);
      digitalWrite(fil[3],HIGH);
      digitalWrite(col[i],LOW);
      delay(1);
      digitalWrite(col[i],HIGH);
    }
    for(i=0;i<7;i++)
    {
      digitalWrite(col[0],LOW);
      digitalWrite(fil[i],HIGH);
      delay(1);
      digitalWrite(fil[i],LOW);
    }
    k++;
  }while(!(k==t)); 
}
void GG()
{
  do
  {
    for(i=0;i<4;i++)
    {
      digitalWrite(fil[0],HIGH);
      digitalWrite(fil[3],HIGH);
      digitalWrite(fil[6],HIGH);
      digitalWrite(col[i],LOW);
      delay(1);
      digitalWrite(col[i],HIGH);
      digitalWrite(fil[0],LOW);
      digitalWrite(fil[3],LOW);
      digitalWrite(fil[6],LOW);
    }
    for(i=1;i<6;i++)
    {
      digitalWrite(col[0],LOW);
      digitalWrite(fil[i],HIGH);
      delay(1);
      digitalWrite(fil[i], LOW);
      digitalWrite(col[0],HIGH);
    }
    for(i=3;i<6;i++)
    {
      digitalWrite(col[4],LOW);
      digitalWrite(fil[i],HIGH);
      delay(1);
      digitalWrite(fil[i],LOW);
      digitalWrite(col[4],HIGH);
    }
    k++;
  }while(!(k==t)); 
}
void H()
{
  do
  {
    for(i=0;i<5;i++)
    {
      digitalWrite(fil[3],HIGH);
      digitalWrite(col[i],LOW);
      delay(1);
      digitalWrite(col[i],HIGH);
    }
    for(i=0;i<7;i++)
    {
      digitalWrite(col[0],LOW);
      digitalWrite(col[4],LOW);
      digitalWrite(fil[i],HIGH);
      delay(1);
      digitalWrite(fil[i],LOW);
    }
    k++;
  }while(!(k==t)); 
}
void I()
{
  do
  {
    for(i=0;i<5;i++)
    {
      digitalWrite(fil[0],HIGH);
      digitalWrite(fil[6],HIGH);
      digitalWrite(col[i],LOW);
      delay(1);
      digitalWrite(col[i],HIGH);
      digitalWrite(fil[0],LOW);
      digitalWrite(fil[6],LOW);
    }
    for(i=0;i<7;i++)
    {
      digitalWrite(col[2],LOW);
      digitalWrite(fil[i],HIGH);
      delay(1);
      digitalWrite(fil[i],LOW);
      digitalWrite(col[2],HIGH);
    }
    k++;
  }while(!(k==t));
} 
void JJ()
{
  do
  {
    for(i=0;i<5;i++)
    {
      digitalWrite(fil[0],HIGH);
      digitalWrite(col[i],LOW);
      delay(1);
      digitalWrite(col[i],HIGH);
      digitalWrite(fil[0],LOW);
    }
    for(i=0;i<3;i++)
    {
      digitalWrite(fil[6],HIGH);
      digitalWrite(col[i],LOW);
      delay(1);
      digitalWrite(col[i],HIGH);
      digitalWrite(fil[6],LOW);
    }
    for(i=4;i<6;i++)
    {
      digitalWrite(col[0],LOW);
      digitalWrite(fil[i],HIGH);
      delay(1);
      digitalWrite(fil[i],LOW);
      digitalWrite(col[0],HIGH);
    }
    for(i=1;i<6;i++)
    {
      digitalWrite(col[2],LOW);
      digitalWrite(fil[i],HIGH);
      delay(1);
      digitalWrite(fil[i],LOW);
      digitalWrite(col[2],HIGH);
    }
    k++;
  }while(!(k==t));
}  
void KK()
{
  do
  {
    for(i=0;i<2;i++)
    {
      digitalWrite(fil[3],HIGH);
      digitalWrite(col[i],LOW);
      delay(1);
      digitalWrite(col[i],HIGH);
      digitalWrite(fil[3],LOW);
    }
    for(i=0;i<7;i++)
    {
      digitalWrite(col[0],LOW);
      digitalWrite(fil[i],HIGH);
      delay(1);
      digitalWrite(fil[i],LOW);
      digitalWrite(col[0],HIGH);
    }
    for(i=2;i<6;i+=2)
    {
      digitalWrite(col[2],LOW);
      digitalWrite(fil[i],HIGH);
      delay(1);
      digitalWrite(fil[i],LOW);
      digitalWrite(col[2],HIGH);
    }
    for(i=1;i<6;i+=4)
    {
      digitalWrite(col[3],LOW);
      digitalWrite(fil[i],HIGH);
      delay(1);
      digitalWrite(fil[i],LOW);
      digitalWrite(col[3],HIGH);
    }
    for(i=0;i<7;i+=6)
    {
      digitalWrite(col[4],LOW);
      digitalWrite(fil[i],HIGH);
      delay(1);
      digitalWrite(fil[i],LOW);
      digitalWrite(col[4],HIGH);
    }
    k++;
  }while(!(k==t));
} 
void LL()
{
  do
  {
    for(i=0;i<5;i++)
    {
      digitalWrite(fil[6],HIGH);
      digitalWrite(col[i],LOW);
      delay(1);
      digitalWrite(col[i],HIGH);
      digitalWrite(fil[6],LOW);
    }
    for(i=0;i<7;i++)
    {
      digitalWrite(col[0],LOW);
      digitalWrite(fil[i],HIGH);
      delay(1);
      digitalWrite(fil[i],LOW);
      digitalWrite(col[0],HIGH);
    }
    k++;
  }while(!(k==t));
} 
void MM()
{
  do
  {
    
    for(i=1;i<4;i+=2)
    {
      digitalWrite(fil[1],HIGH);
      digitalWrite(col[i],LOW);
      delay(1);
      digitalWrite(col[i],HIGH);
      digitalWrite(fil[1],LOW);
    }
      digitalWrite(fil[2],HIGH);
      digitalWrite(col[2],LOW);
      delay(1);
      digitalWrite(col[2],HIGH);
      digitalWrite(fil[2],LOW);
    for(i=0;i<7;i++)
    {
      digitalWrite(col[0],LOW);
      digitalWrite(col[4],LOW);
      digitalWrite(fil[i],HIGH);
      delay(1);
      digitalWrite(fil[i],LOW);
      digitalWrite(col[0],HIGH);
      digitalWrite(col[4],HIGH);
    }
    k++;
  }while(!(k==t));
}
void NN()
{
  do
  {
    
      digitalWrite(fil[1],HIGH);
      digitalWrite(col[1],LOW);
      delay(1);
      digitalWrite(col[1],HIGH);
      digitalWrite(fil[1],LOW);  
    
      digitalWrite(fil[2],HIGH);
      digitalWrite(col[2],LOW);
      delay(1);
      digitalWrite(col[2],HIGH);
      digitalWrite(fil[2],LOW);
      
      digitalWrite(fil[3],HIGH);
      digitalWrite(col[3],LOW);
      delay(1);
      digitalWrite(col[3],HIGH);
      digitalWrite(fil[3],LOW);
      
    for(i=0;i<7;i++)
    {
      digitalWrite(col[0],LOW);
      digitalWrite(col[4],LOW);
      digitalWrite(fil[i],HIGH);
      delay(1);
      digitalWrite(fil[i],LOW);
      digitalWrite(col[0],HIGH);
      digitalWrite(col[4],HIGH);
    }
    k++;
  }while(!(k==t));
}
void O()
{
  do
  {
    for(i=1;i<4;i++)
    {
      digitalWrite(fil[0],HIGH);
      digitalWrite(fil[6],HIGH);
      digitalWrite(col[i],LOW);
      delay(1);
      digitalWrite(col[i],HIGH);
      digitalWrite(fil[0],LOW);
      digitalWrite(fil[6],LOW);
    }
    for(i=1;i<6;i++)
    {
      digitalWrite(col[0],LOW);
      digitalWrite(col[4],LOW);
      digitalWrite(fil[i],HIGH);
      delay(1);
      digitalWrite(fil[i],LOW);
      digitalWrite(col[0],HIGH);
      digitalWrite(col[4],HIGH);
    }
    k++;
  }while(!(k==t)); 
}
void P()
{
  do
  {
    for(i=0;i<4;i++)
    {
      digitalWrite(fil[0],HIGH);
      digitalWrite(fil[3],HIGH);
      digitalWrite(col[i],LOW);
      delay(1);
      digitalWrite(col[i],HIGH);
      digitalWrite(fil[0],LOW);
      digitalWrite(fil[3],LOW);
    }
    for(i=0;i<7;i++)
    {
      digitalWrite(col[0],LOW);
      digitalWrite(fil[i],HIGH);
      delay(1);
      digitalWrite(fil[i],LOW);
      digitalWrite(col[0],HIGH);
    }
    for(i=1;i<3;i++)
    {
      digitalWrite(col[4],LOW);
      digitalWrite(fil[i],HIGH);
      delay(1);
      digitalWrite(fil[i],LOW);
      digitalWrite(col[4],HIGH);
    }
    k++;
  }while(!(k==t)); 
}
void QQ()
{
  do
  {
    
      digitalWrite(fil[4],HIGH);
      digitalWrite(col[2],LOW);
      delay(1);
      digitalWrite(col[2],HIGH);
      digitalWrite(fil[4],LOW);  
    
      digitalWrite(fil[5],HIGH);
      digitalWrite(col[3],LOW);
      delay(1);
      digitalWrite(col[3],HIGH);
      digitalWrite(fil[5],LOW);
      
      digitalWrite(fil[6],HIGH);
      digitalWrite(col[4],LOW);
      delay(1);
      digitalWrite(col[4],HIGH);
      digitalWrite(fil[6],LOW);
    for(i=1;i<4;i++)
    {
      digitalWrite(fil[0],HIGH);
      digitalWrite(fil[6],HIGH);
      digitalWrite(col[i],LOW);
      delay(1);
      digitalWrite(col[i],HIGH);
      digitalWrite(fil[0],LOW);
      digitalWrite(fil[6],LOW);
    }
    for(i=1;i<6;i++)
    {
      digitalWrite(col[0],LOW);
      digitalWrite(col[4],LOW);
      digitalWrite(fil[i],HIGH);
      delay(1);
      digitalWrite(fil[i],LOW);
      digitalWrite(col[0],HIGH);
      digitalWrite(col[4],HIGH);
    }
    k++;
  }while(!(k==t)); 
}
void RR()
{
  do
  {
    
      digitalWrite(fil[4],HIGH);
      digitalWrite(col[2],LOW);
      delay(1);
      digitalWrite(col[2],HIGH);
      digitalWrite(fil[4],LOW);  
    
      digitalWrite(fil[5],HIGH);
      digitalWrite(col[3],LOW);
      delay(1);
      digitalWrite(col[3],HIGH);
      digitalWrite(fil[5],LOW);
      
      digitalWrite(fil[6],HIGH);
      digitalWrite(col[4],LOW);
      delay(1);
      digitalWrite(col[4],HIGH);
      digitalWrite(fil[6],LOW);
    for(i=0;i<4;i++)
    {
      digitalWrite(fil[0],HIGH);
      digitalWrite(fil[3],HIGH);
      digitalWrite(col[i],LOW);
      delay(1);
      digitalWrite(col[i],HIGH);
      digitalWrite(fil[0],LOW);
      digitalWrite(fil[3],LOW);
    }
    for(i=0;i<7;i++)
    {
      digitalWrite(col[0],LOW);
      digitalWrite(fil[i],HIGH);
      delay(1);
      digitalWrite(fil[i],LOW);
      digitalWrite(col[0],HIGH);
    }
    for(i=1;i<3;i++)
    {
      digitalWrite(col[4],LOW);
      digitalWrite(fil[i],HIGH);
      delay(1);
      digitalWrite(fil[i],LOW);
      digitalWrite(col[4],HIGH);
    }
    k++;
  }while(!(k==t)); 
}
void SSS()
{
  do
  {
      digitalWrite(fil[1],HIGH);
      digitalWrite(fil[2],HIGH);
      digitalWrite(fil[5],HIGH);
      digitalWrite(col[0],LOW);
      delay(1);
      digitalWrite(col[0],HIGH);
      digitalWrite(fil[1],LOW);  
      digitalWrite(fil[2],LOW);    
      digitalWrite(fil[5],LOW);
      
      digitalWrite(fil[1],HIGH);
      digitalWrite(fil[4],HIGH);
      digitalWrite(fil[5],HIGH);
      digitalWrite(col[4],LOW);
      delay(1);
      digitalWrite(col[4],HIGH);
      digitalWrite(fil[1],LOW);  
      digitalWrite(fil[4],LOW);    
      digitalWrite(fil[5],LOW);
      
    for(i=1;i<4;i++)
    {
      digitalWrite(fil[0],HIGH);
      digitalWrite(fil[3],HIGH);
      digitalWrite(fil[6],HIGH);
      digitalWrite(col[i],LOW);
      delay(1);
      digitalWrite(col[i],HIGH);
      digitalWrite(fil[0],LOW);
      digitalWrite(fil[3],LOW);
      digitalWrite(fil[6],LOW);
      
    }
    k++;
  }while(!(k==t)); 
}
void T()
{
  do
  {
    for(i=0;i<5;i++)
    {
      digitalWrite(fil[0],HIGH);
      digitalWrite(col[i],LOW);
      delay(1);
      digitalWrite(col[i],HIGH);
      
    }
    for(i=0;i<7;i++)
    {
      digitalWrite(col[2],LOW);
      digitalWrite(fil[i],HIGH);
      delay(1);
      digitalWrite(fil[i],LOW);
    }
    k++;
  }while(!(k==t)); 
}
void U()
{
  do
  {
    for(i=1;i<4;i++)
    {
      digitalWrite(fil[6],HIGH);
      digitalWrite(col[i],LOW);
      delay(1);
      digitalWrite(col[i],HIGH);
      digitalWrite(fil[6],LOW);
    }
    for(i=0;i<6;i++)
    {
      digitalWrite(col[0],LOW);
      digitalWrite(col[4],LOW);
      digitalWrite(fil[i],HIGH);
      delay(1);
      digitalWrite(fil[i],LOW);
      digitalWrite(col[0],HIGH);
      digitalWrite(col[4],HIGH);
    }
    k++;
  }while(!(k==t)); 
}
void V()
{
  do
  {
     
      digitalWrite(col[1],LOW);
      digitalWrite(fil[5],HIGH);
      delay(1);
      digitalWrite(col[1],HIGH);
      digitalWrite(fil[5],LOW);
      delay(1);
      
      digitalWrite(col[3],LOW);
      digitalWrite(fil[5],HIGH);
      delay(1);
      digitalWrite(col[3],HIGH);
      digitalWrite(fil[5],LOW);
      delay(1);
      
      digitalWrite(col[2],LOW);
      digitalWrite(fil[6],HIGH);
      delay(1);
      digitalWrite(col[2],HIGH);
      digitalWrite(fil[6],LOW);
      delay(1);
    for(i=0;i<5;i++)
    {
      digitalWrite(col[0],LOW);
      digitalWrite(col[4],LOW);
      digitalWrite(fil[i],HIGH);
      delay(1);
      digitalWrite(fil[i],LOW);
      digitalWrite(col[0],HIGH);
      digitalWrite(col[4],HIGH);
    }
    k++;
  }while(!(k==t)); 
}
void W()
{
  do
  {
      digitalWrite(col[1],LOW);
      digitalWrite(fil[5],HIGH);
      delay(1);
      digitalWrite(col[1],HIGH);
      digitalWrite(fil[5],LOW);
      delay(1);
      
      digitalWrite(col[3],LOW);
      digitalWrite(fil[5],HIGH);
      delay(1);
      digitalWrite(col[3],HIGH);
      digitalWrite(fil[5],LOW);
      delay(1);
      
      digitalWrite(col[2],LOW);
      digitalWrite(fil[4],HIGH);
      delay(1);
      digitalWrite(col[2],HIGH);
      digitalWrite(fil[4],LOW);
      delay(1);
    
    for(i=0;i<7;i++)
    {
      digitalWrite(col[0],LOW);
      digitalWrite(col[4],LOW);
      digitalWrite(fil[i],HIGH);
      delay(1);
      digitalWrite(fil[i],LOW);
      digitalWrite(col[0],HIGH);
      digitalWrite(col[4],HIGH);
    }
    k++;
  }while(!(k==t)); 
}
void X()
{
  do
  {
      digitalWrite(col[2],LOW);
      digitalWrite(fil[3],HIGH);
      delay(1);
      digitalWrite(col[2],HIGH);
      digitalWrite(fil[3],LOW);
      delay(1);
      
    
    for(i=0;i<7;i++)
    {
      if(i==2)
        {
          continue;
        }
     if(i==3)
        {
          continue;
        }
      if(i==4)
        {
          continue;
        }
      digitalWrite(col[0],LOW);
      digitalWrite(col[4],LOW);
      digitalWrite(fil[i],HIGH);
      delay(1);
      digitalWrite(fil[i],LOW);
      digitalWrite(col[0],HIGH);
      digitalWrite(col[4],HIGH);
    }
      
    for(i=2;i<5;i+=2)
    {
      digitalWrite(col[1],LOW);
      digitalWrite(col[3],LOW);
      digitalWrite(fil[i],HIGH);
      delay(1);
      digitalWrite(fil[i],LOW);
      digitalWrite(col[1],HIGH);
      digitalWrite(col[3],HIGH);
    }
    k++;
  }while(!(k==t)); 
}
void Y()
{
  do
  {
      digitalWrite(col[1],LOW);
      digitalWrite(col[3],LOW);
      digitalWrite(fil[2],HIGH);
      delay(1);
      digitalWrite(col[1],HIGH);
      digitalWrite(col[3],HIGH);
      digitalWrite(fil[2],LOW);
      delay(1);
    
    for(i=0;i<2;i++)
    {
      digitalWrite(col[0],LOW);
      digitalWrite(col[4],LOW);
      digitalWrite(fil[i],HIGH);
      delay(1);
      digitalWrite(fil[i],LOW);
      digitalWrite(col[0],HIGH);
      digitalWrite(col[4],HIGH);
    }
    for(i=3;i<7;i++)
    {
      digitalWrite(col[2],LOW);
      digitalWrite(fil[i],HIGH);
      delay(1);
      digitalWrite(fil[i],LOW);
      digitalWrite(col[2],HIGH);
    }
    k++;
  }while(!(k==t)); 
}
void Z()
{

  do
  {
      digitalWrite(col[1],LOW);
      digitalWrite(fil[4],HIGH);
      delay(1);
      digitalWrite(fil[4],LOW);
      digitalWrite(col[1],HIGH);
      
      digitalWrite(col[2],LOW);
      digitalWrite(fil[3],HIGH);
      delay(1);
      digitalWrite(fil[3],LOW);
      digitalWrite(col[2],HIGH); 
      
      digitalWrite(col[3],LOW);
      digitalWrite(fil[2],HIGH);
      delay(1);
      digitalWrite(fil[2],LOW);
      digitalWrite(col[3],HIGH); 
    for(i=0;i<7;i++)
    {
      if(i==2)
        {
          continue;
        }
      if(i==3)
        {
          continue;
        }
      if(i==4)
        {
          continue;
        }
      digitalWrite(col[0],LOW);
      digitalWrite(fil[i],HIGH);
      delay(1);
      digitalWrite(fil[i],LOW);
      digitalWrite(col[0],HIGH);  
    }
    for(i=0;i<7;i++)
    {
      if(i==2)
        {
          continue;
        }
      if(i==3)
        {
          continue;
        }
      if(i==4)
        {
          continue;
        }
      digitalWrite(col[4],LOW);
      digitalWrite(fil[i],HIGH);
      delay(1);
      digitalWrite(fil[i],LOW);
      digitalWrite(col[4],HIGH);  
    }
    for(i=1;i<4;i++)
    {
   
      digitalWrite(fil[0],HIGH);
      digitalWrite(fil[6],HIGH);
      digitalWrite(col[i],LOW);
      delay(1);
      digitalWrite(fil[0],LOW);
      digitalWrite(fil[6],LOW);
      digitalWrite(col[i],HIGH);  
    }
    k++;
  }while(!(k==t)); 
}
void loop()
{
  
  char num;
  
  if(Serial.available()>0 )
  {
    num=Serial.read();
   
    
              if(num=='A')
              {
                Serial.print("LETRA RECIBIDA = ");
                Serial.println(num);
                A();
                k=0;
                //delay(3000);
              }
              else if(num=='B')
              {
                Serial.print("LETRA RECIBIDA = ");
                Serial.println(num);
                B();
                k=0;
                //delay(3000);
              }
              else if(num=='C')
              {
                Serial.print("LETRA RECIBIDA = ");
                Serial.println(num);
                C();
                k=0;
                //delay(3000);
              }
              else if(num=='D')
              {
                Serial.print("LETRA RECIBIDA = ");
                Serial.println(num);
                D();
                k=0;
                //delay(3000);
              }
              else if(num=='E')
              {
                Serial.print("LETRA RECIBIDA = ");
                Serial.println(num);
                E();
                k=0;
                //delay(3000);
              }
              else if(num=='F')
              {
                Serial.print("LETRA RECIBIDA = ");
                Serial.println(num);
                FF();
                k=0;
                //delay(3000);
              }
              else if(num=='G')
              {
                Serial.print("LETRA RECIBIDA = ");
                Serial.println(num);
                GG();
                k=0;
                //delay(3000);
              }
              
              else if(num=='H')
              {
                Serial.print("LETRA RECIBIDA = ");
                Serial.println(num);
                H();
                k=0;
                //delay(3000);
              }
              else if(num=='I')
              {
                Serial.print("LETRA RECIBIDA = ");
                Serial.println(num);
                I();
                k=0;
                //delay(3000);
              }
              else if(num=='J')
              {
                Serial.print("LETRA RECIBIDA = ");
                Serial.println(num);
                JJ();
                k=0;
                //delay(3000);
              }
              
              else if(num=='K')
              {
                Serial.print("LETRA RECIBIDA = ");
                Serial.println(num);
                KK();
                k=0;
                //delay(3000);
              }
              else if(num=='L')
              {
                Serial.print("LETRA RECIBIDA = ");
                Serial.println(num);
                LL();
                k=0;
                //delay(3000);
              }
              else if(num=='M')
              {
                Serial.print("LETRA RECIBIDA = ");
                Serial.println(num);
                MM();
                k=0;
                //delay(3000);
              }
              else if(num=='N')
              {
                Serial.print("LETRA RECIBIDA = ");
                Serial.println(num);
                NN();
                k=0;
                //delay(3000);
              }
              else if(num=='O')
              {
                Serial.print("LETRA RECIBIDA = ");
                Serial.println(num);
                O();
                k=0;
                //delay(3000);
              }
              else if(num=='P')
              {
                Serial.print("LETRA RECIBIDA = ");
                Serial.println(num);
                P();
                k=0;
                //delay(3000);
              }
              else if(num=='Q')
              {
                Serial.print("LETRA RECIBIDA = ");
                Serial.println(num);
                QQ();
                k=0;
                //delay(3000);
              }
              else if(num=='R')
              {
                Serial.print("LETRA RECIBIDA = ");
                Serial.println(num);
                RR();
                k=0;
                //delay(3000);
              }
              else if(num=='S')
              {
                Serial.print("LETRA RECIBIDA = ");
                Serial.println(num);
                SSS();
                k=0;
                //delay(3000);
              }
              else if(num=='T')
              {
                Serial.print("LETRA RECIBIDA = ");
                Serial.println(num);
                T();
                k=0;
                //delay(3000);
              }
              else if(num=='U')
              {
                Serial.print("LETRA RECIBIDA = ");
                Serial.println(num);
                U();
                k=0;
                //delay(3000);
              }
              else if(num=='V')
              {
                Serial.print("LETRA RECIBIDA = ");
                Serial.println(num);
                V();
                k=0;
                //delay(3000);
              }
              else if(num=='W')
              {
                Serial.print("LETRA RECIBIDA = ");
                Serial.println(num);
                W();
                k=0;
                //delay(3000);
              }
              else if(num=='X')
              {
                Serial.print("LETRA RECIBIDA = ");
                Serial.println(num);
                X();
                k=0;
                //delay(3000);
              }
              else if(num=='Y')
              {
                Serial.print("LETRA RECIBIDA = ");
                Serial.println(num);
                Y();
                k=0;
                //delay(3000);
              }
              else if(num=='Z')
              {
                Serial.print("LETRA RECIBIDA = ");
                Serial.println(num);
                Z();
                k=0;
                //delay(3000);
              }
              else
              {
                Serial.println("Letra no Encontrada");
                delay(500);
              }
  }
}
