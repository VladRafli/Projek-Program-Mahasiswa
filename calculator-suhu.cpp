#include <stdio.h>
#include <stdlib.h>

void CelciusToKelvin(){
	
	printf("input celcius: ");
	
	int celcius;
	scanf("%d", &celcius);
	
	printf("%d", celcius + 273);
	
}

int main(){
	printf("CALCULATOR TEMPERATURE\n============================\n1.Celcius to Kelvin\n\nYour choice: ");
	
	int input_menu;
	scanf("%d", &input_menu);
	
	switch(input_menu){
		case 1:
			CelciusToKelvin();
			break;
		default:
			break;
	}
	
	return 0;
}
