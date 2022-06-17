#include "stm32f10x.h"
#include "led.h"
#include "key.h"
#include "delay.h"
#include "usart.h"
#include "exti.h"
#include "iwdg.h"
#include "timer.h"
#include "pwm.h"
#include "inacquire.h"
#include "lcd.h"
#include "rtc.h"
#include "wkup.h"
#include "adc.h"
#include "tsensor.h"
#include "dac.h"

//extern u8 TIM2CH1_CAPTURE_STA; //���벶��״̬
//extern u16 TIM2CH1_CAPTURE_VAL; //���벶��ֵ
int main()
{
	//u16 led0pwmval=0;
	//u8 dir=1;
	//u32 temp=0;
	//delay_init();
	//LED_Init();
	//KEY_Init();
	//My_USART1_Init();
	//EXTIX_Init();
	
	// TIMER_Init(4999,7199); //10Khz �ļ���Ƶ�ʣ������� 5000 Ϊ 500ms
	
	
	// *****************LED*****************
	
	/**
		while(1)
	{

		GPIO_ResetBits(GPIOA,GPIO_Pin_8);
		GPIO_SetBits(GPIOD,GPIO_Pin_2);
		delay_ms(1000);
		GPIO_SetBits(GPIOA,GPIO_Pin_8);
		GPIO_ResetBits(GPIOD,GPIO_Pin_2);
		delay_ms(1000);
		

	}
	
	**/
	
	// *****************GPIO*****************
	// KEY0 ��������
	// KEY1 ��������
	
	/**
	while(1)
	{
		KEYS* keyAction = KEY_SCAN();
		
		if(keyAction ->KEY0_P == 0)
		{
			GPIO_ResetBits(GPIOA,GPIO_Pin_8);
		}else {
			GPIO_SetBits(GPIOA,GPIO_Pin_8);
		}
		
		if(keyAction ->KEY1_P == 0)
		{
			GPIO_ResetBits(GPIOD,GPIO_Pin_2);
		}else {
			GPIO_SetBits(GPIOD,GPIO_Pin_2);
		}
	}
	**/
	
	// *****************���� - USART *****************
	/**
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	My_USART1_Init();
	while(1)
{
	printf("ok");
	delay_ms(1000);
};
**/

// *****************�ⲿ�ж� *****************
	/**
NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //�����жϷ���
while(1) {
	delay_ms(1000);
 }
**/

// *****************�������Ź� *****************
// �����������κβ���ʱ����һֱ����װ�أ���ʱLED��һֱ������ ������key0�����������ι�����Ͳ�������װ�أ���һֱ����
/**
	delay_ms(200);
	GPIO_ResetBits(GPIOD,GPIO_Pin_2);
	IWDG_Init(4,625); // 1s
	while(1)
	{
		if(!KEY0)
		{
			IWDG_ReloadCounter();
		}
	}
**/

// *****************��ʱ���ж�*****************
/**
NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
while(1);

**/

// *****************PWD*****************
	/**
	PWM_Init(899,0);//����Ƶ��PWM Ƶ��=72000/(899+1)=80Khz
	while(1)
	{
		delay_ms(10);
		if(dir)led0pwmval++;
		else led0pwmval--;
		if(led0pwmval>300)dir=0;
		if(led0pwmval==0)dir=1;
		TIM_SetCompare1(TIM1,led0pwmval);
	}
	
	**/
	

// *****************���벶��*****************
/**
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	TIMER_Init(899,0); //����Ƶ��PWM Ƶ��=72000/(899+1)=80Khz
	TIM2_Cap_Init(0XFFFF,72-1); //�� 1Mhz ��Ƶ�ʼ���
	while(1)
	{
		delay_ms(10);
		TIM_SetCompare1(TIM1,TIM_GetCapture1(TIM1)+1);
		if(TIM_GetCapture1(TIM1)==300)TIM_SetCompare1(TIM1,0);
		if(TIM2CH1_CAPTURE_STA&0X80)//�ɹ�������һ�θߵ�ƽ
		{
		temp=TIM2CH1_CAPTURE_STA&0X3F;
		temp*=65536; //���ʱ���ܺ�
		temp+=TIM2CH1_CAPTURE_VAL; //�õ��ܵĸߵ�ƽʱ��
		USART_SendData(USART1,temp);
		TIM2CH1_CAPTURE_STA=0; //������һ�β���
	}
}
**/

// *****************LCD*****************
/**
	u8 x=0;
	static uint8_t pin_8stat = 1;
	u8 lcd_id[12];			//���LCD ID�ַ���	
	delay_init();	    	 //��ʱ������ʼ��	  
	uart_init(9600);	 	//���ڳ�ʼ��Ϊ9600
	LED_Init();		  		//��ʼ����LED���ӵ�Ӳ���ӿ�
 	LCD_Init();
	POINT_COLOR=RED; 
	sprintf((char*)lcd_id,"LCD ID:%04X",lcddev.id);//��LCD ID��ӡ��lcd_id���顣				 	
  	while(1) 
	{		 
		switch(x)
		{
			case 0:LCD_Clear(WHITE);break;
			case 1:LCD_Clear(BLACK);break;
			case 2:LCD_Clear(BLUE);break;
			case 3:LCD_Clear(RED);break;
			case 4:LCD_Clear(MAGENTA);break;
			case 5:LCD_Clear(GREEN);break;
			case 6:LCD_Clear(CYAN);break;

			case 7:LCD_Clear(YELLOW);break;
			case 8:LCD_Clear(BRRED);break;
			case 9:LCD_Clear(GRAY);break;
			case 10:LCD_Clear(LGRAY);break;
			case 11:LCD_Clear(BROWN);break;
		}
		POINT_COLOR=RED;	  
		LCD_ShowString(30,40,200,24,24,"Mini STM32 ^_^");	
		LCD_ShowString(30,70,200,16,16,"TFTLCD TEST");
		LCD_ShowString(30,90,200,16,16,"ATOM@ALIENTEK");
 		LCD_ShowString(30,110,200,16,16,lcd_id);		//��ʾLCD ID	      					 
		LCD_ShowString(30,130,200,12,12,"2014/3/7");	          					 
	   x++;
		if(x==12)x=0;
		
		if(pin_8stat)
		{
			GPIO_SetBits(GPIOA,GPIO_Pin_8);
			GPIO_ResetBits(GPIOD,GPIO_Pin_2);
		}else{
			GPIO_ResetBits(GPIOA,GPIO_Pin_8);
			GPIO_SetBits(GPIOD,GPIO_Pin_2);
		}
		pin_8stat = !pin_8stat;	 
		delay_ms(1000);	
	} 
**/

// *****************RTC*****************
/**
	static uint8_t pin_8stat = 1;
	u8 t;	
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);// �����ж����ȼ�����2
	delay_init();	    	 //��ʱ������ʼ��	  
	uart_init(9600);	 	//���ڳ�ʼ��Ϊ9600
	LED_Init();				//��ʼ����LED���ӵ�Ӳ���ӿ�
 	LCD_Init();				//��ʼ��LCD
		 	
	POINT_COLOR=RED;//��������Ϊ��ɫ 
	LCD_ShowString(60,50,200,16,16,"Mini STM32");	
	LCD_ShowString(60,70,200,16,16,"RTC TEST");	
	LCD_ShowString(60,90,200,16,16,"ATOM@ALIENTEK");
	LCD_ShowString(60,110,200,16,16,"2014/3/9");	
	while(RTC_Init())		//RTC��ʼ��	��һ��Ҫ��ʼ���ɹ�
	{ 
		LCD_ShowString(60,130,200,16,16,"RTC ERROR!   ");	
		delay_ms(800);
		LCD_ShowString(60,130,200,16,16,"RTC Trying...");	
	}		    						
	//��ʾʱ��
	POINT_COLOR=BLUE;//��������Ϊ��ɫ					 
	LCD_ShowString(60,130,200,16,16,"    -  -     ");	   
	LCD_ShowString(60,162,200,16,16,"  :  :  ");	 		    
	while(1)
	{								    
		if(t!=calendar.sec)
		{
			t=calendar.sec;
			LCD_ShowNum(60,130,calendar.w_year,4,16);									  
			LCD_ShowNum(100,130,calendar.w_month,2,16);									  
			LCD_ShowNum(124,130,calendar.w_date,2,16);	 
			switch(calendar.week)
			{
				case 0:
					LCD_ShowString(60,148,200,16,16,"Sunday   ");
					break;
				case 1:
					LCD_ShowString(60,148,200,16,16,"Monday   ");
					break;
				case 2:
					LCD_ShowString(60,148,200,16,16,"Tuesday  ");
					break;
				case 3:
					LCD_ShowString(60,148,200,16,16,"Wednesday");
					break;
				case 4:
					LCD_ShowString(60,148,200,16,16,"Thursday ");
					break;
				case 5:
					LCD_ShowString(60,148,200,16,16,"Friday   ");
					break;
				case 6:
					LCD_ShowString(60,148,200,16,16,"Saturday ");
					break;  
			}
			LCD_ShowNum(60,162,calendar.hour,2,16);									  
			LCD_ShowNum(84,162,calendar.min,2,16);									  
			LCD_ShowNum(108,162,calendar.sec,2,16);
			
			if(pin_8stat)
			{
				GPIO_SetBits(GPIOA,GPIO_Pin_8);
				GPIO_ResetBits(GPIOD,GPIO_Pin_2);
			}else{
				GPIO_ResetBits(GPIOA,GPIO_Pin_8);
				GPIO_SetBits(GPIOD,GPIO_Pin_2);
			}
			pin_8stat = !pin_8stat;	 
		}	
		delay_ms(10);								  
	};

**/

// *****************WKUP*****************
/**
	static uint8_t pin_8stat = 1;
	delay_init();	    	 //��ʱ������ʼ?
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);// �����ж����ȼ�����2  
	uart_init(9600);	 	//���ڳ�ʼ��Ϊ9600
	LED_Init();		  		//��ʼ����LED���ӵ�Ӳ���ӿ�
 	WKUP_Init();			//��ʼ��WK_UP������ͬʱ����Ƿ�����������
	LCD_Init();			   	//��ʼ��LCD 			 	
 	POINT_COLOR=RED;
	LCD_ShowString(30,50,200,16,16,"Mini STM32");	
	LCD_ShowString(30,70,200,16,16,"WKUP TEST");	
	LCD_ShowString(30,90,200,16,16,"ATOM@ALIENTEK");
	LCD_ShowString(30,110,200,16,16,"2014/3/8");	 
	while(1)
	{
			if(pin_8stat)
			{
				GPIO_SetBits(GPIOA,GPIO_Pin_8);
				GPIO_ResetBits(GPIOD,GPIO_Pin_2);
			}else{
				GPIO_ResetBits(GPIOA,GPIO_Pin_8);
				GPIO_SetBits(GPIOD,GPIO_Pin_2);
			}
			pin_8stat = !pin_8stat;	 
		delay_ms(250);
	}						
**/

// *****************ADC*****************
/**
	u16 adcx;
	u16 adcx2;
	float temp;
	float temp2;
	delay_init();	    	 //��ʱ������ʼ��	  
	uart_init(9600);	 	//���ڳ�ʼ��Ϊ9600
	LED_Init();		  		//��ʼ����LED���ӵ�Ӳ���ӿ�
 	LCD_Init();
 	Adc_Init();		  		//ADC��ʼ��	    
	POINT_COLOR=RED;//��������Ϊ��ɫ 
	LCD_ShowString(60,50,200,16,16,"Mini STM32");	
	LCD_ShowString(60,70,200,16,16,"ADC TEST");	
	LCD_ShowString(60,90,200,16,16,"ATOM@ALIENTEK");
	LCD_ShowString(60,110,200,16,16,"2014/3/9");	
	//��ʾ��ʾ��Ϣ
	POINT_COLOR=BLUE;//��������Ϊ��ɫ
	LCD_ShowString(60,130,200,16,16,"ADC_CH1_VAL:");	      
	LCD_ShowString(60,150,200,16,16,"ADC_CH1_VOL:0.000V");	 

		LCD_ShowString(60,170,200,16,16,"ADC_CH2_VAL:");	      
		LCD_ShowString(60,190,190,16,16,"ADC_CH2_VOL:0.000V");
	while(1)
	{
		adcx=Get_Adc_Average(ADC_Channel_1,10);
		LCD_ShowxNum(156,130,adcx,4,16,0);//��ʾADC��ֵ
		temp=(float)adcx*(3.3/4096);
		adcx=temp;
		LCD_ShowxNum(156,150,adcx,1,16,0);//��ʾ��ѹֵ
		temp-=adcx;
		temp*=1000;
		LCD_ShowxNum(172,150,temp,3,16,0X80);
		
		adcx2=Get_Adc_Average(ADC_Channel_2,10);
		LCD_ShowxNum(156,170,adcx2,4,16,0);//��ʾADC��ֵ
		temp2=(float)adcx2*(3.3/4096);
		adcx2=temp2;
		LCD_ShowxNum(156,190,adcx2,1,16,0);//��ʾ��ѹֵ
		temp2-=adcx2;
		temp2*=1000;
		LCD_ShowxNum(172,190,temp2,3,16,0X80);
		
		delay_ms(250);	
	}											
**/

// *****************ADC - �¶ȴ�����*****************


	u16 adcx;
	float temp;
	float temperate;	 
	delay_init();	    	 //��ʱ������ʼ��	  
	uart_init(9600);	 	//���ڳ�ʼ��Ϊ9600
	LED_Init();		  		//��ʼ����LED���ӵ�Ӳ���ӿ�
 	LCD_Init();
 	T_Adc_Init();		  		//ADC��ʼ��	    
	POINT_COLOR=RED;//��������Ϊ��ɫ 
	LCD_ShowString(60,50,200,16,16,"Mini STM32");	
	LCD_ShowString(60,70,200,16,16,"Temperature TEST");	
	LCD_ShowString(60,90,200,16,16,"ATOM@ALIENTEK");
	LCD_ShowString(60,110,200,16,16,"2014/3/9");	
	//��ʾ��ʾ��Ϣ											      
	POINT_COLOR=BLUE;//��������Ϊ��ɫ
	LCD_ShowString(60,130,200,16,16,"TEMP_VAL:");	      
	LCD_ShowString(60,150,200,16,16,"TEMP_VOL:0.000V");	      
	LCD_ShowString(60,170,200,16,16,"TEMPERATE:00.00C");	  
	while(1)
	{
		adcx=T_Get_Adc_Average(ADC_CH_TEMP,10);
		LCD_ShowxNum(132,130,adcx,4,16,0);//��ʾADC��ֵ
		temp=(float)adcx*(3.3/4096);
		temperate=temp;//�����¶ȴ������ĵ�ѹֵ
		adcx=temp;
		LCD_ShowxNum(132,150,adcx,1,16,0);     		//��ʾ��ѹֵ��������
		temp-=(u8)temp;				    			//������������		  
		LCD_ShowxNum(148,150,temp*1000,3,16,0X80);	//��ʾ��ѹС������
 		temperate=(1.43-temperate)/0.0043+25;		//�������ǰ�¶�ֵ	 
		LCD_ShowxNum(140,170,(u8)temperate,2,16,0); //��ʾ�¶���������
		temperate-=(u8)temperate;	  
		LCD_ShowxNum(164,170,temperate*100,2,16,0X80);//��ʾ�¶�С������
		delay_ms(250);
	}



/**
	u16 adcx;
	float temp;
 	u8 t=0;	 
	u16 dacval=0;
	u8 key;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);// �����ж����ȼ�����2
	delay_init();	    	 //��ʱ������ʼ��	  
	uart_init(9600);	 	//���ڳ�ʼ��Ϊ9600
	LED_Init();		  		//��ʼ����LED���ӵ�Ӳ���ӿ�
 	LCD_Init();			   	//��ʼ��LCD 		
	KEY_Init();				//������ʼ��		 	
 	Adc_Init();		  		//ADC��ʼ��
	Dac1_Init();		 	//DACͨ��1��ʼ��	
 
	POINT_COLOR=RED;//��������Ϊ��ɫ 
	LCD_ShowString(60,50,200,16,16,"Mini STM32");	
	LCD_ShowString(60,70,200,16,16,"DAC TEST");	
	LCD_ShowString(60,90,200,16,16,"ATOM@ALIENTEK");
	LCD_ShowString(60,110,200,16,16,"2014/3/9");	
	LCD_ShowString(60,130,200,16,16,"WK_UP:+  KEY0:-");	
	//��ʾ��ʾ��Ϣ											      
	POINT_COLOR=BLUE;//��������Ϊ��ɫ
	LCD_ShowString(60,150,200,16,16,"DAC VAL:");	      
	LCD_ShowString(60,170,200,16,16,"DAC VOL:0.000V");	      
	LCD_ShowString(60,190,200,16,16,"ADC VOL:0.000V");	    
	DAC_SetChannel1Data(DAC_Align_12b_R, 0);//????0	   	      
	while(1)
	{
		t++;
		key=KEY_Scan(0);			  
		if(key==WKUP_PRES)
		{		 
			if(dacval<4000)dacval+=200;
			DAC_SetChannel1Data(DAC_Align_12b_R, dacval);//??DAC?
		}else if(key==KEY0_PRES)	
		{
			if(dacval>200)dacval-=200;
			else dacval=0;
			DAC_SetChannel1Data(DAC_Align_12b_R, dacval);//??DAC?
		}	 
		if(t==10||key==KEY0_PRES||key==WKUP_PRES) 	//WKUP/KEY1������,���߶�ʱʱ�䵽��
		{	  
 			adcx=DAC_GetDataOutputValue(DAC_Channel_1);//??????DAC??
			LCD_ShowxNum(124,150,adcx,4,16,0);     	//��ʾDAC�Ĵ���ֵ
			temp=(float)adcx*(3.3/4096);			//�õ�DAC��ѹֵ
			adcx=temp;
 			LCD_ShowxNum(124,170,temp,1,16,0);     	//��ʾ��ѹֵ��������
 			temp-=adcx;
			temp*=1000;
			LCD_ShowxNum(140,170,temp,3,16,0X80); 	//��ʾ��ѹֵ��С������
 			adcx=Get_Adc_Average(ADC_Channel_1,10);		//�õ�ADCת��ֵ	  
			temp=(float)adcx*(3.3/4096);			//�õ�ADC��ѹֵ
			adcx=temp;
 			LCD_ShowxNum(124,190,temp,1,16,0);     	//��ʾ��ѹֵ��������
 			temp-=adcx;
			temp*=1000;
			LCD_ShowxNum(140,190,temp,3,16,0X80); 	//��ʾ��ѹֵ��С������   
			t=0;
		}	    
		delay_ms(10);	
	}	
**/	

}

