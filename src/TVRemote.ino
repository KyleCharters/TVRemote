#include <IRTransmitter.h>

//Set pin that infrared led is connected to
#define IR_PIN D0
//Set pin that led is connected to
#define LED_PIN D7

//All options
unsigned int tv_on[31] = {564, 564, 1692, 564, 564, 564, 1692, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 1692, 564, 564, 564, 1692, 564, 564, 564, 1692, 564, 1692};
unsigned int tv_off[31] = {1692, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 1692, 564, 1692, 564, 564, 564, 1692, 564, 1692};
unsigned int tv_hdmi_1[31] = {1692, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 564};
unsigned int tv_hdmi_2[31] = {564, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 1692, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 564};
unsigned int tv_hdmi_3[31] = {1692, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 564};
unsigned int tv_channel_up[31] = {564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692};
unsigned int tv_channel_down[31] = {1692, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692};
unsigned int tv_volume_up[31] = {564, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692};
unsigned int tv_volume_down[31] = {1692, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692};
unsigned int tv_mute_on[31] = {564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 564, 564, 1692, 564, 1692};
unsigned int tv_mute_off[31] = {1692, 564, 564, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 564, 564, 1692, 564, 1692};
unsigned int tv_num_0[31] = {564, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 564, 564, 1692, 564, 1692, 564, 1692};
unsigned int tv_num_1[31] = {1692, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564, 564, 564, 1692, 564, 1692, 564, 1692};
unsigned int tv_num_2[31] = {564, 564, 1692, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 1692, 564, 1692, 564, 564, 564, 1692, 564, 1692, 564, 1692};
unsigned int tv_num_3[31] = {1692, 564, 1692, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 1692, 564, 564, 564, 1692, 564, 1692, 564, 1692};
unsigned int tv_num_4[31] = {564, 564, 564, 564, 1692, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 564, 564,1692, 564, 1692, 564, 564, 564, 1692, 564, 564, 564, 1692, 564, 1692, 564, 1692};
unsigned int tv_num_5[31] = {1692, 564, 564, 564, 1692, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 1692, 564, 564, 564, 1692, 564, 1692, 564, 1692};
unsigned int tv_num_6[31] = {564, 564, 1692, 564, 1692, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 1692, 564, 1692, 564, 1692};
unsigned int tv_num_7[31] = {1692, 564, 1692, 564, 1692, 564, 564, 564, 1692,564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 1692, 564, 1692, 564, 1692};
unsigned int tv_num_8[31] = {564, 564, 564, 564, 564, 564, 1692, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564, 564, 564, 564, 564, 1692, 564, 1692, 564, 1692};
unsigned int tv_num_9[31] = {1692, 564, 564, 564, 564, 564, 1692, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 1692, 564, 564, 564, 564, 564, 1692, 564, 1692, 564, 1692};
unsigned int tv_ok[31] = {564, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 1692, 564, 1692, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564, 564, 564, 1692};
unsigned int tv_up[31] = {1692, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564, 564, 564, 1692};
unsigned int tv_down[31] = {564, 564, 1692, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564, 564, 564, 1692};
unsigned int tv_left[31] = {1692, 564, 1692, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564, 564, 564, 1692};
unsigned int tv_right[31] = {564, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564, 564, 564, 1692, 564, 1692, 564, 564, 564, 1692};
unsigned int tv_exit[31] = {1692, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 1692, 564, 1692, 564, 564, 564, 1692, 564, 1692, 564, 564, 564, 1692};
unsigned int tv_enter[31] = {1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564};

//Skeleton for every signal
unsigned int signalData[68] = {9024, 4512, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 1692, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564,
  1692, 564, 1692, 564, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 564, 39756};

//Initialize ir library
IRTransmitter transmitter(IR_PIN, LED_PIN);

void transmit(unsigned int * data){
  //Replace middle section of skeleton with specified option
  for (int i = 35; i < 66; i++)
    signalData[i] = data[i - 35];

  //Send signal through ir led
  transmitter.Transmit(signalData, 68);
}

void receivedAction(const char *event, const char *data){
  //Decide action based on first character
  switch (data[0]) {
    case '0':
      transmit(tv_num_0);
      break;
    case '1':
      transmit(tv_num_1);
      break;
    case '2':
      transmit(tv_num_2);
      break;
    case '3':
      transmit(tv_num_3);
      break;
    case '4':
      transmit(tv_num_4);
      break;
    case '5':
      transmit(tv_num_5);
      break;
    case '6':
      transmit(tv_num_6);
      break;
    case '7':
      transmit(tv_num_7);
      break;
    case '8':
      transmit(tv_num_8);
      break;
    case '9':
      transmit(tv_num_9);
      break;
    case 'a':
      transmit(tv_on);
      break;
    case 'b':
      transmit(tv_off);
      break;
    case 'c':
      transmit(tv_hdmi_1);
      break;
    case 'd':
      transmit(tv_hdmi_2);
      break;
    case 'e':
      transmit(tv_hdmi_3);
      break;
    case 'f':
      transmit(tv_channel_up);
      break;
    case 'g':
      transmit(tv_channel_down);
      break;
    case 'h':
      transmit(tv_volume_up);
      break;
    case 'i':
      transmit(tv_volume_down);
      break;
    case 'j':
      transmit(tv_mute_on);
      break;
    case 'k':
      transmit(tv_mute_off);
      break;
    case 'l':
      transmit(tv_ok);
      break;
    case 'm':
      transmit(tv_up);
      break;
    case 'n':
      transmit(tv_down);
      break;
    case 'o':
      transmit(tv_left);
      break;
    case 'p':
      transmit(tv_right);
      break;
    case 'q':
      transmit(tv_exit);
      break;
    case 'r':
      transmit(tv_enter);
      break;
  }
}

void setup() {
  //Subscribe to "tv_event" events
  Particle.subscribe("tv_event", receivedAction);
}
