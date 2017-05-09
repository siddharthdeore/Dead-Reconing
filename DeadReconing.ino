#define led_pin 13

#define pin_left_enc_A 2
#define pin_left_enc_B 3
#define pin_right_enc_A 4
#define pin_right_enc_B 5

#deifine PI   3.1415927
#define TWO_PI  6.2831853

#define enc_cpr 400
#define track_width 10
#define wheel_dia 4

#define counts_per_cm enc_cpr/(PI*wheel_dia)
#define rad_per_count TWO_PI/(counts_per_cm*PI*track_width)


volatile uint32_t left_count,right_count;
float delta_count,avg_distance,left_distance,right_distance,theta;
void setup() {

}

void loop() {
  left_distance = left_count/counts_per_cm;
  right_distance  = right_count/counts_per_cm;
  avg_distance  = (left_distance+right_distance)/2;
  delta_count = left_count - right_count;
  theta = delta_count * rad_per_count;
}
void isr_enc_left() {
if(digitalRead(pin_left_enc_B))
  left_count++;
else
  left_count--;
}

void isr_enc_left() {
if(digitalRead(pin_right_enc_B))
  right_count++;
else
  right_count--;
}
