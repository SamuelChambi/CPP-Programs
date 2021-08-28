#include<iostream>
#include<conio.h>
int main(){
	int nAl,nNo,x=0,y=0,z=0,c=0,vNo,cNo;
	float promI, promC, cNotas;
	cout << "INGRESE EL NUMERO DE ALUMNOS: ";cin>> nAl;
	cout << "INGRESE EL NUMERO DE NOTAS POR CADA ALUMNO: "; cin >> nNo;
	for(int i=1;i<=nAl;i++){
		promI=0;
		cNotas = 0;
		for(int j=1;j<=nNo;j++){
			cout << "\nINGRESE NOTA " << j <<" DEL ALUMNO "<<i<<": "; cin >> vNo;
			cNotas += vNo;
		}
		promI = cNotas/nNo;
		cout << "EL PROMEDIO DEL ALUMNO "<< i <<" ES: "<< promI <<"\n";
		cNo += promI;
		if(promI>=6){
			if(promI>=12){
				if(promI>=16){
					x+=1;
				}
				else{
					y+=1;
				}
			}
			else{
				z+=1;
			}
		}
		else{
			c+=1;
		}
	}
	promC = cNo/nAl;
	cout << "\nALUMNOS CON PROMEDIO DE NOTAS ENTRE 0 Y 5: "<<c;
	cout << "\nALUMNOS CON PROMEDIO DE NOTAS ENTRE 5 Y 11: "<<z;
	cout << "\nALUMNOS CON PROMEDIO DE NOTAS ENTRE 12 Y 15: "<<y;
	cout << "\nALUMNOS CON PROMEDIO DE NOTAS MAYOR A 15: "<<x;
	cout << "\n\nEL PROMEDIO DE NOTAS DE LA CLASE ES: " << promC;
	getch();
	return 0;
}
