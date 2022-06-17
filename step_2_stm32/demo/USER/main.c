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

//extern u8 TIM2CH1_CAPTURE_STA; //输入捕获状态
//extern u16 TIM2CH1_CAPTURE_VAL; //输入捕获值
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
	
	// TIMER_Init(4999,7199); //10Khz 的计数频率，计数到 5000 为 500ms
	
	
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
	// KEY0 长按灯亮
	// KEY1 长按灯亮
	
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
	
	// *****************串口 - USART *****************
	/**
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	My_USART1_Init();
	while(1)
{
	printf("ok");
	delay_ms(1000);
};
**/

// *****************外部中断 *****************
	/**
NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置中断分组
while(1) {
	delay_ms(1000);
 }
**/

// *****************独立看门狗 *****************
// 描述：当无任何操作时，会一直重新装载，这时LED会一直闪动， 当按下key0按键，会进行喂狗，就不会重新装载，灯一直亮着
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

// *****************定时器中断*****************
/**
NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
while(1);

**/

// *****************PWD*****************
	/**
	PWM_Init(899,0);//不分频。PWM 频率=72000/(899+1)=80Khz
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
	

// *****************输入捕获*****************
/**
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	TIMER_Init(899,0); //不分频。PWM 频率=72000/(899+1)=80Khz
	TIM2_Cap_Init(0XFFFF,72-1); //以 1Mhz 的频率计数
	while(1)
	{
		delay_ms(10);
		TIM_SetCompare1(TIM1,TIM_GetCapture1(TIM1)+1);
		if(TIM_GetCapture1(TIM1)==300)TIM_SetCompare1(TIM1,0);
		if(TIM2CH1_CAPTURE_STA&0X80)//成功捕获到了一次高电平
		{
		temp=TIM2CH1_CAPTURE_STA&0X3F;
		temp*=65536; //溢出时间总和
		temp+=TIM2CH1_CAPTURE_VAL; //得到总的高电平时间
		USART_SendData(USART1,temp);
		TIM2CH1_CAPTURE_STA=0; //开启下一次捕获
	}
}
**/

// *****************LCD*****************
/**
	u8 x=0;
	static uint8_t pin_8stat = 1;
	u8 lcd_id[12];			//存放LCD ID字符串	
	delay_init();	    	 //延时函数初始化	  
	uart_init(9600);	 	//串口初始化为9600
	LED_Init();		  		//初始化与LED连接的硬件接口
 	LCD_Init();
	POINT_COLOR=RED; 
	sprintf((char*)lcd_id,"LCD ID:%04X",lcddev.id);//将LCD ID打印到lcd_id数组。				 	
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
 		LCD_ShowString(30,110,200,16,16,lcd_id);		//显示LCD ID	      					 
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
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);// 设置中断优先级分组2
	delay_init();	    	 //延时函数初始化	  
	uart_init(9600);	 	//串口初始化为9600
	LED_Init();				//初始化与LED连接的硬件接口
 	LCD_Init();				//初始化LCD
		 	
	POINT_COLOR=RED;//设置字体为红色 
	LCD_ShowString(60,50,200,16,16,"Mini STM32");	
	LCD_ShowString(60,70,200,16,16,"RTC TEST");	
	LCD_ShowString(60,90,200,16,16,"ATOM@ALIENTEK");
	LCD_ShowString(60,110,200,16,16,"2014/3/9");	
	while(RTC_Init())		//RTC初始化	，一定要初始化成功
	{ 
		LCD_ShowString(60,130,200,16,16,"RTC ERROR!   ");	
		delay_ms(800);
		LCD_ShowString(60,130,200,16,16,"RTC Trying...");	
	}		    						
	//显示时间
	POINT_COLOR=BLUE;//设置字体为蓝色					 
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
	delay_init();	    	 //延时函数初始?
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);// 设置中断优先级分组2  
	uart_init(9600);	 	//串口初始化为9600
	LED_Init();		  		//初始化与LED连接的硬件接口
 	WKUP_Init();			//初始化WK_UP按键，同时检测是否正常开机？
	LCD_Init();			   	//初始化LCD 			 	
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
	delay_init();	    	 //延时函数初始化	  
	uart_init(9600);	 	//串口初始化为9600
	LED_Init();		  		//初始化与LED连接的硬件接口
 	LCD_Init();
 	Adc_Init();		  		//ADC初始化	    
	POINT_COLOR=RED;//设置字体为红色 
	LCD_ShowString(60,50,200,16,16,"Mini STM32");	
	LCD_ShowString(60,70,200,16,16,"ADC TEST");	
	LCD_ShowString(60,90,200,16,16,"ATOM@ALIENTEK");
	LCD_ShowString(60,110,200,16,16,"2014/3/9");	
	//显示提示信息
	POINT_COLOR=BLUE;//设置字体为蓝色
	LCD_ShowString(60,130,200,16,16,"ADC_CH1_VAL:");	      
	LCD_ShowString(60,150,200,16,16,"ADC_CH1_VOL:0.000V");	 

		LCD_ShowString(60,170,200,16,16,"ADC_CH2_VAL:");	      
		LCD_ShowString(60,190,190,16,16,"ADC_CH2_VOL:0.000V");
	while(1)
	{
		adcx=Get_Adc_Average(ADC_Channel_1,10);
		LCD_ShowxNum(156,130,adcx,4,16,0);//显示ADC的值
		temp=(float)adcx*(3.3/4096);
		adcx=temp;
		LCD_ShowxNum(156,150,adcx,1,16,0);//显示电压值
		temp-=adcx;
		temp*=1000;
		LCD_ShowxNum(172,150,temp,3,16,0X80);
		
		adcx2=Get_Adc_Average(ADC_Channel_2,10);
		LCD_ShowxNum(156,170,adcx2,4,16,0);//显示ADC的值
		temp2=(float)adcx2*(3.3/4096);
		adcx2=temp2;
		LCD_ShowxNum(156,190,adcx2,1,16,0);//显示电压值
		temp2-=adcx2;
		temp2*=1000;
		LCD_ShowxNum(172,190,temp2,3,16,0X80);
		
		delay_ms(250);	
	}											
**/

// *****************ADC - 温度传感器*****************


	u16 adcx;
	float temp;
	float temperate;	 
	delay_init();	    	 //延时函数初始化	  
	uart_init(9600);	 	//串口初始化为9600
	LED_Init();		  		//初始化与LED连接的硬件接口
 	LCD_Init();
 	T_Adc_Init();		  		//ADC初始化	    
	POINT_COLOR=RED;//设置字体为红色 
	LCD_ShowString(60,50,200,16,16,"Mini STM32");	
	LCD_ShowString(60,70,200,16,16,"Temperature TEST");	
	LCD_ShowString(60,90,200,16,16,"ATOM@ALIENTEK");
	LCD_ShowString(60,110,200,16,16,"2014/3/9");	
	//显示提示信息											      
	POINT_COLOR=BLUE;//设置字体为蓝色
	LCD_ShowString(60,130,200,16,16,"TEMP_VAL:");	      
	LCD_ShowString(60,150,200,16,16,"TEMP_VOL:0.000V");	      
	LCD_ShowString(60,170,200,16,16,"TEMPERATE:00.00C");	  
	while(1)
	{
		adcx=T_Get_Adc_Average(ADC_CH_TEMP,10);
		LCD_ShowxNum(132,130,adcx,4,16,0);//显示ADC的值
		temp=(float)adcx*(3.3/4096);
		temperate=temp;//保存温度传感器的电压值
		adcx=temp;
		LCD_ShowxNum(132,150,adcx,1,16,0);     		//显示电压值整数部分
		temp-=(u8)temp;				    			//减掉整数部分		  
		LCD_ShowxNum(148,150,temp*1000,3,16,0X80);	//显示电压小数部分
 		temperate=(1.43-temperate)/0.0043+25;		//计算出当前温度值	 
		LCD_ShowxNum(140,170,(u8)temperate,2,16,0); //显示温度整数部分
		temperate-=(u8)temperate;	  
		LCD_ShowxNum(164,170,temperate*100,2,16,0X80);//显示温度小数部分
		delay_ms(250);
	}



/**
	u16 adcx;
	float temp;
 	u8 t=0;	 
	u16 dacval=0;
	u8 key;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);// 设置中断优先级分组2
	delay_init();	    	 //延时函数初始化	  
	uart_init(9600);	 	//串口初始化为9600
	LED_Init();		  		//初始化与LED连接的硬件接口
 	LCD_Init();			   	//初始化LCD 		
	KEY_Init();				//按键初始化		 	
 	Adc_Init();		  		//ADC初始化
	Dac1_Init();		 	//DAC通道1初始化	
 
	POINT_COLOR=RED;//设置字体为红色 
	LCD_ShowString(60,50,200,16,16,"Mini STM32");	
	LCD_ShowString(60,70,200,16,16,"DAC TEST");	
	LCD_ShowString(60,90,200,16,16,"ATOM@ALIENTEK");
	LCD_ShowString(60,110,200,16,16,"2014/3/9");	
	LCD_ShowString(60,130,200,16,16,"WK_UP:+  KEY0:-");	
	//显示提示信息											      
	POINT_COLOR=BLUE;//设置字体为蓝色
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
		if(t==10||key==KEY0_PRES||key==WKUP_PRES) 	//WKUP/KEY1按下了,或者定时时间到了
		{	  
 			adcx=DAC_GetDataOutputValue(DAC_Channel_1);//??????DAC??
			LCD_ShowxNum(124,150,adcx,4,16,0);     	//显示DAC寄存器值
			temp=(float)adcx*(3.3/4096);			//得到DAC电压值
			adcx=temp;
 			LCD_ShowxNum(124,170,temp,1,16,0);     	//显示电压值整数部分
 			temp-=adcx;
			temp*=1000;
			LCD_ShowxNum(140,170,temp,3,16,0X80); 	//显示电压值的小数部分
 			adcx=Get_Adc_Average(ADC_Channel_1,10);		//得到ADC转换值	  
			temp=(float)adcx*(3.3/4096);			//得到ADC电压值
			adcx=temp;
 			LCD_ShowxNum(124,190,temp,1,16,0);     	//显示电压值整数部分
 			temp-=adcx;
			temp*=1000;
			LCD_ShowxNum(140,190,temp,3,16,0X80); 	//显示电压值的小数部分   
			t=0;
		}	    
		delay_ms(10);	
	}	
**/	

}

