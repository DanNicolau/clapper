int led = 13 ;// LED pin for debugging
int sound = 2;//digital sound input
int val;

bool isOn = false;
int minDelay = 100;
int maxDelay = 600;
int t1;
int t2;

void setup ()
{
  pinMode (led, OUTPUT) ;// define LED as output interface
  
  pinMode(sound, INPUT);

  Serial.begin(9600);
}
 
void loop ()
{

  val = digitalRead(sound);

  if (val){
    t1 = t2;
    t2 = millis();
    if (t2-t1 > minDelay && t2-t1 < maxDelay){
      isOn = !isOn;
    }
  }
  
  digitalWrite(led, isOn);
  Serial.println(isOn);
}
