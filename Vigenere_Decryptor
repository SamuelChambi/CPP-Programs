#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int nro_letra(char letras[], char letra)
{//OBTIENE EL INDICE DE POSICION DE LA LETRA
    for(int i = 0;i<26;i++)
    {
        if(letras[i]==letra)
            return i;
    }
}

bool estaL(char let, char letras[])
{//COMPRUEBA SI UN CARACTER SE ENCUENTRA EN LA LISTA DE LOS CARACTERES CON LOS QUE TRABAJAMOS
    for (int i = 0; i < 26; i++)
    {
        if(letras[i]==let)
            return true;
    }
    return false;
}

int contar_Caracteres(char letras[], string nombre)
{//CUENTA EL #N DE CARACTERES DE UN ARCHIVO DE TEXTO
    ifstream archivo;
    archivo.open(nombre);
    char caracter;
    int count = 0;
    while(!archivo.eof())
    {
        archivo.get(caracter);
        if (estaL(caracter,letras)==true)
        {
            count++;
        }
        else if(caracter == ' ')
        {
            count++;
        }
        else if(caracter == '\n')
        { 
            count++;
        }
        else if(caracter!='\0')
        {
            count++;
        }
        
    }
    archivo.close();
    return count;
}

void leer_Caracteres(char texto[], string nombre)
{//CUENTA EL #N DE CARACTERES DE UN ARCHIVO DE TEXTO
    ifstream archivo;
    archivo.open(nombre);
    char caracter;
    int count = 0;
    while(!archivo.eof())
    {
        archivo.get(caracter);
        if(caracter!='\0')
        {
            texto[count] = caracter;
            count ++;
        }
    }
    archivo.close();
}

int obt_indice(char clave, char des, char letras[])
{//OBTIENE EL INDICE DE LA LETRA DESENCRIPTADA 
    int indice;
    if((nro_letra(letras,des) - nro_letra(letras,clave))>=0)//PREGUNTA SI EL MODULO ES POSITIVO
    {//SI LO ES, CONTINUA CON EL PROCESO MODULAR
        indice = (nro_letra(letras,des) - nro_letra(letras,clave))%26;
    }
    else
    {// SINO, APLICA EL PROCESO DEL RESIDUO 
        indice = 26 - ((nro_letra(letras,des) - nro_letra(letras,clave))*-1);
    }
    return indice;
}

void descifrar_txt(char letras[], string clave, char descifradas[], int nro_Caracteres, char descifrar[])
{//DESCIFRA TODOS LOS CARACTERES CONTENIDOS EN UN VECTOR, SEGUN LA CLAVE
    int x = 0, indice;
    for (int i = 0; i < nro_Caracteres-1; i++)
    {
        if (estaL(descifrar[i],letras)==true)//TRABAJA CON LETRAS
        {
            if(x<clave.length())// PREGUNTA SI LA CLAVE YA FUE RECORRIDA
            {//SINO, CONTINUA EL BUCLE
                indice = obt_indice(clave[x],descifrar[i],letras);
                descifradas[i] = letras[indice];
                x++;
            }
            else
            {// EN CASO CONTRARIO, REINICIA EL RECORRIDO DE LA CLAVE
                x = 0;
                indice = obt_indice(clave[x],descifrar[i],letras);
                descifradas[i] = letras[indice];
                x++;
            }
        }
        else
        {//SI EL CARACTER EVALUADO NO ES UNA LETRA, SIMPLEMENTE SE AGREGA AL VECTOR DESCIFRADAS
            descifradas[i] = descifrar[i];
        }
    }
}

void guardar_dcript(char encriptado[], int nro_Caracteres)
{   //GUARDA LA LISTA DE CARACTERES ENCRIPTADOS DENTRO DE UN ARCHIVO TXT
    ofstream fichero;
    fichero.open("DESENCRIPTADO_VIG.TXT");
    for(int i=0 ; i< nro_Caracteres-1 ; i++)
    {
        fichero << encriptado[i];
    }
    fichero.close();
}

int main()
{
    string clave, nombre;
    char letras[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    cout<<"<--------------------- SISTEMA DE DESCIFRADO VIGNERE --------------------->" << endl 
        <<">>>INGRESE NOMBRE DEL ARCHIVO A DESCIFRAR: "; cin >> nombre;
    cout<<">>>INGRESE CLAVE DE CIFRADO: "; cin >> clave;
    int nro_CaracteresCIF = contar_Caracteres(letras,nombre);//OBTENEMOS EL NRO DE CARACTERES
    char descifradas[nro_CaracteresCIF], descifrar[nro_CaracteresCIF];
    cout<<"<--------------------- LEYENDO ARCHIVO ENCRIPTADO --------------------->" << endl;
    leer_Caracteres(descifrar,nombre);//LLENAMOS UN VECTOR CON TODOS LOS CARACTERES ENCONTRADOS DENTRO DEL TXT CIFRADO
    cout<<"<--------------------- DESENCRIPTANDO ARCHIVO --------------------->" << endl;
    descifrar_txt(letras,clave,descifradas,nro_CaracteresCIF,descifrar);
    cout<<"<--------------------- GENERANDO ARCHIVO DESENCRIPTADO --------------------->" << endl;
    guardar_dcript(descifradas,nro_CaracteresCIF);
    system("DESENCRIPTADO_VIG.txt");
    system("pause");
    return 1;
}
