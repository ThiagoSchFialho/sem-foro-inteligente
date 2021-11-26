// C++ code
//
 int led1 = 2;
 int led2 = 3;
 int led3 = 4;
 int led4 = 6;
 int led5 = 7;

 //Sensor ultrassonico 1
 int echo1 = 9;
 int trig1 = 10;

 //Sensor ultrassonico 2
 int echo2 = 12;
 int trig2 = 13;

 //Variaveis utilizadas para o controle dos 
 //sensores ultrassonicos
 int duracao1 = 0;
 int distancia1 = 0;

 int duracao2 = 0;
 int distancia2 = 0;


void setup(){
  Serial.begin(9600);
  
  //Sensor1
  pinMode(echo1, INPUT);
  pinMode(trig1, OUTPUT);
  
  //Sensor2
  pinMode(echo2, INPUT);
  pinMode(trig2, OUTPUT);
  
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
}

void loop(){
  //----- MANIPULANDO OS SENSORES
  duracao1 = 0;
  duracao2 = 0;
  
  //----- Sensor 1
  digitalWrite(trig1, HIGH); //Gatilho do sensor enviando sinal
  delay(10);
  digitalWrite(trig1, LOW);
  
  duracao1 = pulseIn(echo1, HIGH); //Sensor recebendo o echo
  distancia1 = duracao1*0.017; //Calculo da distancia
  
  Serial.print(distancia1);
  Serial.println("cm  --  1");
  
  
  //----- Sensor 2
  digitalWrite(trig2, HIGH); //Gatilho do sensor enviando sinal
  delay(10);
  digitalWrite(trig2, LOW);
  
  duracao2 = pulseIn(echo2, HIGH); //Sensor recebendo o echo
  distancia2 = duracao2*0.017; //Calculo da distancia
  
  Serial.print(distancia2);
  Serial.println("cm  --  2");
  
  //-----
  
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  
  if(distancia1 > 330 && distancia2 < 300){
  	//dar passagem para as pessoas percebidos pelo sensor 2
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    
  }else if(distancia1 < 300 && distancia2 > 330){
  	//dar passagem para os carro percebidos pelo sensor 1
    digitalWrite(led1, HIGH);
    digitalWrite(led5, HIGH);
    
  }else{
    digitalWrite(led3,HIGH);
    digitalWrite(led4,HIGH);
    
    delay(4000);
    digitalWrite(led3,LOW);
    digitalWrite(led2,HIGH);
    delay(2000);
    
    digitalWrite(led5,HIGH);
    delay(400);
    
    digitalWrite(led5,LOW);
    delay(400);
    
    digitalWrite(led5,HIGH);
    delay(400);
    
    digitalWrite(led5,LOW);
    delay(400);
    
    digitalWrite(led5,HIGH);
    delay(200);
    digitalWrite(led2,LOW);
    digitalWrite(led4,LOW);
    digitalWrite(led1,HIGH);
    digitalWrite(led5,HIGH);
    delay(8000);
    
    digitalWrite(led5,LOW);    
    digitalWrite(led1,LOW); 
  }
}