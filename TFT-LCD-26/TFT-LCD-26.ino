#define LCD_REST 16
#define LCD_CS 17
#define LCD_WR 18
#define LCD_RS 19

void main_Write_COM(int DH){
	unsigned char i;
	int temp;
	digitalWrite(LCD_RS,LOW);
	digitalWrite(LCD_CS,LOW);
	for(i=0;i<16;i++)
	{
		temp=(DH&0x01);
		if(temp)
			digitalWrite(i,HIGH);
		else
			digitalWrite(i,LOW);
		DH=DH>>1;
	}
	digitalWrite(LCD_WR,LOW);
	digitalWrite(LCD_WR,HIGH);
	digitalWrite(LCD_CS,HIGH);
}

void main_Write_DATA(int DH){
	unsigned char i;
	int temp;
	digitalWrite(LCD_RS,HIGH);
	digitalWrite(LCD_CS,LOW);
	for(i=0;i<16;i++)
	{
		temp=(DH&0x01);
		if(temp)
			digitalWrite(i,HIGH);
		else
			digitalWrite(i,LOW);
		DH=DH>>1;
	}
	digitalWrite(LCD_WR,LOW);
	digitalWrite(LCD_WR,HIGH);
	digitalWrite(LCD_CS,HIGH);
}

void main_W_com_data(int com1,int dat1){
	main_Write_COM(com1);
	main_Write_DATA(dat1);
}

void address_set(unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2){
	main_W_com_data(0x0002,x1>>8);     // Column address start2
	main_W_com_data(0x0003,x1);    // Column address start1
	main_W_com_data(0x0004,x2>>8);     // Column address end2
	main_W_com_data(0x0005,x2);    // Column address end1
	main_W_com_data(0x0006,y1>>8);     // Row address start2
	main_W_com_data(0x0007,y1);    // Row address start1
	main_W_com_data(0x0008,y2>>8);     // Row address end2
	main_W_com_data(0x0009,y2);    // Row address end1
	main_Write_COM(0x0022);      
}

void main_init(void){
		digitalWrite(LCD_REST,HIGH);
		delay(5);
		digitalWrite(LCD_REST,LOW);
		delay(10);
		digitalWrite(LCD_REST,HIGH);
		delay(20);
		main_W_com_data(0x00,0x0001);   //Set the OSC bit as ‘1’ to start the internal oscillator
		main_W_com_data(0x01,0x0100);   // set SS and SM bit
		main_W_com_data(0x02,0x0700);   // set 1 line inversion
		main_W_com_data(0x03,0x1030);   //set GRAM Write direction and BGR=1
		main_W_com_data(0x04,0x0000);   // Resize register
		main_W_com_data(0x08,0x0202);   // set the back porch and front porch
		main_W_com_data(0x09,0x0000);   // set non-display area refresh cycle ISC[3:0]
		main_W_com_data(0x0A,0x0000);   // FMARK function
		main_W_com_data(0x0C,0x0000);   // RGB interface setting
		main_W_com_data(0x0D,0x0000);   // Frame marker Position
		main_W_com_data(0x0F,0x0000);   // RGB interface polarity
		delay(30);
		main_W_com_data(0x10, 0x16b0);   // SAP, BT[3:0], AP, DSTB, SLP, STB
		delay(30);
		main_W_com_data(0x11, 0x0007);   //Write final user’s setting values to VC bit
		main_W_com_data(0x12, 0x013a);   // set Internal reference voltage
		main_W_com_data(0x13, 0x1a00);   // VDV[4:0] for VCOM amplitude
		delay(30);
		main_W_com_data(0x29, 0x000c);   // Set VCM[5:0] for VCOMH
		delay(30); // Delay 50ms
		main_W_com_data(0x0030, 0x0000);
		main_W_com_data(0x0031, 0x0505);
		main_W_com_data(0x0032, 0x0304);
		main_W_com_data(0x0035, 0x0006);
		main_W_com_data(0x0036, 0x0707);
		main_W_com_data(0x0037, 0x0105);
		main_W_com_data(0x0038, 0x0002);
		main_W_com_data(0x0039, 0x0707);
		main_W_com_data(0x003C, 0x0704);
		main_W_com_data(0x003D, 0x0807);
		main_W_com_data(0x0050, 0x0000); // Horizontal GRAM Start Address
		main_W_com_data(0x0051, 0x00EF); // Horizontal GRAM End Address
		main_W_com_data(0x0052, 0x0000); // Vertical GRAM Start Address
		main_W_com_data(0x0053, 0x013F); // Vertical GRAM Start Address
		main_W_com_data(0x0060, 0x2700); // Gate Scan Line
		main_W_com_data(0x0061, 0x0001); // NDL,VLE, REV
		main_W_com_data(0x006A, 0x0000); // set scrolling line
		main_W_com_data(0x20, 0x0000);   // GRAM horizontal Address
		main_W_com_data(0x21, 0x0000);   // GRAM Vertical Address
		main_W_com_data(0x0080, 0x0000);
		main_W_com_data(0x0081, 0x0000);
		main_W_com_data(0x0082, 0x0000);
		main_W_com_data(0x0083, 0x0000);
		main_W_com_data(0x0084, 0x0000);
		main_W_com_data(0x0085, 0x0000);
		main_W_com_data(0x90,0x0010);   //Frame Cycle Contral
		main_W_com_data(0x92,0x0000);   //Panel Interface Contral
		main_W_com_data(0x93,0x0003);   //Panel Interface Contral 3. 
		main_W_com_data(0x95,0x0110);   //Frame Cycle Contral
		main_W_com_data(0x97,0x0000);   // 
		main_W_com_data(0x98,0x0000);   //Frame Cycle Contral.     
		main_W_com_data(0x07,0x0173); 
}

void Pant(unsigned int color){
	int i,j;
	address_set(0,0,239,319);
	for(i=0;i<320;i++)
	{
		for (j=0;j<240;j++)
		{
			main_Write_DATA(color);
		}
	}
}

void setup(){
	unsigned char p;
	for(p=0;p<20;p++)
	{
		pinMode(p,OUTPUT);
	}
	main_init();
}

void loop(){
	Pant(0xf800); //Red
	delay(1000);
	Pant(0X07E0); //Green
	delay(1000);
	Pant(0x001f); //Blue
	delay(1000);
}

