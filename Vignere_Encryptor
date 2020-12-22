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

void cifrar(char letras[], char palabra, char clave, char cifrada[],int i)
{//CRIFRA UNA LETRA DE ACUERDO AL INDICE DE LAS OTRAS DOS OBTENIDAS
    int indice;
    indice = (nro_letra(letras,palabra) + nro_letra(letras,clave))%26;
    cifrada[i]=letras[indice];
}

void cifrar_txt(string nombre, char letras[], string clave, char cifradas[])
{//LLENA UN VECTOR CON LAS LETRAS CIFRADAS PARA DESPUES PODER MOSTRARLAS EN UN TXT
    ifstream archivo;
    archivo.open(nombre);
    char aux;
    int x=0, i=0;
    while (!archivo.eof())
    {
        archivo.get(aux);
        if(estaL(aux,letras)==true)//SOLO TRABAJA CON CARACTERES "LETRAS"
        {
            if(x<clave.length())//PREGUNTA SI YA SE RECORRIO TODA LA PALABRA CLAVE
            {//SI NO, SIGUE EL RECORRIDO
                cifrar(letras,aux,clave[x],cifradas,i);//CIFRA LA LETRA Y LA GUARDA EN UN VECTOR
                i++;
                x++;
            }
            else
            {//SI YA LA RECORRIO, REINICIA EL BUCLE EN 0 PARA VOLVER A LEERLA EN EL ORDEN ADECUADO
                x=0;
                cifrar(letras,aux,clave[x],cifradas,i);//CIFRA LA LETRA Y LA GUARDA EN UN VECTOR
                i++;
                x++;
            }
            
        }
        else
        {//SI NO ES UNA LETRA, SIMPLEMENTE LO ALMACENA EN EL VECTOR TAL Y COMO ESTA
            cifradas[i] = aux;
            i++;
        }
    }
    archivo.close();
}

void guardar_cript(char encriptado[], int nro_Caracteres)
{   //GUARDA LA LISTA DE CARACTERES ENCRIPTADOS DENTRO DE UN ARCHIVO TXT
    ofstream fichero;
    fichero.open("ENCRIPTADO_VIG.TXT");
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
    cout<<"<--------------------- SISTEMA DE CIFRADO VIGNERE --------------------->" << endl 
        <<">>>INGRESE NOMBRE DEL ARCHIVO: "; cin >> nombre;
    cout<<">>>INGRESE CLAVE DE CIFRADO: "; cin >> clave;
    int nro_caracteres = contar_Caracteres(letras,nombre);//OBTENEMOS EL N# DE CARACTERES DEL ARCHIVO
    char cifradas[nro_caracteres];//GENERAMOS UN VECTOR QUE CONTENDRA LOS CARACTERES CIFRADOS
    cout<<"<--------------------- LEYENDO ARCHIVO DE TEXTO SELECCIONADO --------------------->" << endl;
    cout<<"<--------------------- ENCRIPTANDO ARCHIVO DE TEXTO SELECCIONADO --------------------->" << endl;
    cifrar_txt(nombre,letras,clave,cifradas);
    cout<<"<--------------------- GENERANDO ARCHIVO ENCRIPTADO --------------------->" << endl;
    guardar_cript(cifradas,nro_caracteres);
    system("ENCRIPTADO_VIG.txt");
    system("pause");
    return 1;
}
